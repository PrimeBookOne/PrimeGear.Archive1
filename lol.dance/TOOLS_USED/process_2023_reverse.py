#!/usr/bin/env python3
"""Process 2023 .xlsm files in reverse order to avoid conflicts with other processes."""

import os
import sys
import subprocess
import tempfile
import shutil
from pathlib import Path

ARCHIVE_DIR = "/workspace/app/PB1/PrimeBook.CPP/primebookonexlsm.archive/2023"
OUTPUT_DIR = "/workspace/app/lol.dance/extracted_by_year/2023.cpp"

CELL_REFS_2023 = [f'A{i}' for i in range(37, 171)]

def kill_libreoffice():
    subprocess.run(["pkill", "-f", "libreoffice"], capture_output=True)
    subprocess.run(["pkill", "-f", "soffice"], capture_output=True)
    import time
    time.sleep(2)

def convert_xlsm_to_xlsx(xlsm_file, target_xlsx):
    stem = Path(xlsm_file).stem
    default_xlsx = f"/tmp/{stem}.xlsx"
    
    kill_libreoffice()
    
    for f in [default_xlsx, target_xlsx]:
        if os.path.exists(f):
            os.remove(f)
    
    result = subprocess.run([
        "libreoffice", "--headless", "--calc",
        "--convert-to", "xlsx:Calc MS Excel 2007 XML",
        "--outdir", "/tmp",
        xlsm_file
    ], capture_output=True, text=True, timeout=120)
    
    # Wait for file to appear
    import time
    count = 0
    while not os.path.exists(default_xlsx) and count < 15:
        time.sleep(1)
        count += 1
    
    if not os.path.exists(default_xlsx):
        print(f"  Conversion failed: {default_xlsx} not created")
        return False
    
    if default_xlsx != target_xlsx:
        shutil.move(default_xlsx, target_xlsx)
    return True

def extract_main_cpp(xlsx_file, output_file):
    import openpyxl
    
    try:
        wb = openpyxl.load_workbook(xlsx_file, data_only=True)
        
        build_sheet = None
        for name in wb.sheetnames:
            if 'BUILD' in name.upper():
                build_sheet = wb[name]
                break
        if not build_sheet:
            for name in wb.sheetnames:
                if name == 'Sheet5' or '5' in name:
                    build_sheet = wb[name]
                    break
        
        if not build_sheet:
            print("  No BUILD sheet found", file=sys.stderr)
            return False
        
        with open(output_file, 'w') as f:
            for cell_ref in CELL_REFS_2023:
                val = build_sheet[cell_ref].value
                if val is not None:
                    f.write(str(val))
                    f.write('\n')
        
        size = os.path.getsize(output_file)
        print(f"  OK: {size} bytes")
        return True
        
    except Exception as e:
        print(f"  Error extracting: {e}", file=sys.stderr)
        return False

def main():
    # Get all .xlsm files in the archive
    xlsm_files = sorted(Path(ARCHIVE_DIR).glob("*.xlsm"))
    
    # Get already processed files
    processed = set()
    for f in Path(OUTPUT_DIR).glob("main_*.cpp"):
        stem = f.stem.replace("main_", "") + ".xlsm"
        processed.add(stem)
    
    # Filter to unprocessed files
    unprocessed = [f for f in xlsm_files if f.name not in processed]
    
    print(f"Total .xlsm files in archive: {len(xlsm_files)}")
    print(f"Already processed: {len(processed)}")
    print(f"Remaining to process: {len(unprocessed)}")
    
    # Process in REVERSE order (newest first)
    unprocessed.reverse()
    
    for i, xlsm_file in enumerate(unprocessed):
        print(f"\n[{i+1}/{len(unprocessed)}] Processing: {xlsm_file.name}")
        
        stem = xlsm_file.stem
        xlsx_file = f"/tmp/{stem}.xlsx"
        output_file = Path(OUTPUT_DIR) / f"main_{stem}.cpp"
        
        if convert_xlsm_to_xlsx(str(xlsm_file), xlsx_file):
            extract_main_cpp(xlsx_file, str(output_file))
        else:
            print(f"  Failed to convert: {xlsm_file.name}")

if __name__ == "__main__":
    main()