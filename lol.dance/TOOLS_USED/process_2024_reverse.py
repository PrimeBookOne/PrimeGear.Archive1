#!/usr/bin/env python3
"""
Process missing 2024 files in reverse chronological order.
"""

import os
import subprocess
import sys
import glob

WORKSPACE = "/workspace/app"
ARCHIVE_DIR = "/workspace/app/PB1/PrimeBook.CPP/primebookonexlsm.archive"
OUTPUT_BASE = "/workspace/app/lol.dance/extracted_by_year"
SCRIPTS_DIR = "/workspace/app/lol.dance"

# Cell references for 2024 from the original script
CELL_REFS_2024 = [
    'A37','A38','A39','A40','A41',
    'A175','A176','A177','A178','A179','A180','A181','A182','A183','A184','A185','A186','A187','A188','A189','A190','A191','A192','A193','A194','A195','A196','A197','A198','A199','A200','A201','A202','A203','A204','A205','A206','A207','A208','A209','A210','A211','A212','A213','A214','A215','A216','A217','A218','A219','A220','A221','A222','A223','A224','A225','A226','A227','A228','A229','A230','A231','A232','A233','A234','A235','A236','A237','A238','A239','A240','A241','A242','A243','A244','A245','A246','A247','A248','A249','A250','A251','A252','A253','A254','A255','A256',
    'A42','A43','A44','A45','A46','A47','A48','A49','A50','A51','A52','A53','A54','A55','A56','A57','A58','A59','A60','A61','A62','A63','A64','A65','A66','A67','A68','A69','A70','A71','A72','A73','A74','A75','A76','A77','A78','A79','A80','A81','A82','A83','A84','A85','A86','A87','A88','A89','A90','A91','A92','A93','A94'
]

def log(msg):
    print(f"[INFO] {msg}")

def warn(msg):
    print(f"[WARN] {msg}")

def err(msg):
    print(f"[ERROR] {msg}")

def kill_libreoffice():
    subprocess.run(["pkill", "-f", "libreoffice"], capture_output=True)
    subprocess.run(["pkill", "-f", "soffice"], capture_output=True)
    import time
    time.sleep(2)

def convert_xlsm_to_xlsx(xlsm_file, target_xlsx):
    stem = os.path.basename(xlsm_file).replace('.xlsm', '')
    default_xlsx = f"/tmp/{stem}.xlsx"
    
    kill_libreoffice()
    
    # Remove any existing files
    for f in [default_xlsx, target_xlsx]:
        if os.path.exists(f):
            os.remove(f)
    
    result = subprocess.run([
        "libreoffice", "--headless", "--calc",
        "--convert-to", "xlsx:\"Calc MS Excel 2007 XML\"",
        "--outdir", "/tmp",
        xlsm_file
    ], capture_output=True, text=True)
    
    # Wait for file to appear
    import time
    count = 0
    while not os.path.exists(default_xlsx) and count < 15:
        time.sleep(1)
        count += 1
    
    if not os.path.exists(default_xlsx):
        err(f"Conversion failed: {default_xlsx} not created")
        return False
    
    if default_xlsx != target_xlsx:
        os.rename(default_xlsx, target_xlsx)
    return True

def extract_main_cpp(xlsx_file, year, output_file):
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
        
        cells = CELL_REFS_2024
        if not cells:
            print(f"  No cell refs for year {year}", file=sys.stderr)
            return False
        
        with open(output_file, 'w') as f:
            for cell_ref in cells:
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

def process_file(stem):
    xlsm_file = f"{ARCHIVE_DIR}/2024/primeOne_2024_{stem}.xlsm"
    xlsx_file = f"/tmp/primeOne_2024_{stem}.xlsx"
    output_dir = f"{OUTPUT_BASE}/2024.cpp"
    output_file = f"{output_dir}/main_primeOne_2024_{stem}.cpp"
    
    if not os.path.exists(xlsm_file):
        warn(f"File not found: {xlsm_file}")
        return False
    
    log(f"Converting: {xlsm_file}")
    if not convert_xlsm_to_xlsx(xlsm_file, xlsx_file):
        err(f"Failed to convert: {xlsm_file}")
        return False
    
    log(f"Extracting: {output_file}")
    if not extract_main_cpp(xlsx_file, "2024", output_file):
        warn(f"Extraction failed for {xlsm_file}")
        return False
    
    return True

def get_missing_files():
    # Get all archive files
    archive_files = glob.glob(f'{ARCHIVE_DIR}/2024/primeOne_2024_*.xlsm')
    archive_stems = [f.split('primeOne_2024_')[1].split('.xlsm')[0] for f in archive_files]
    
    # Get extracted files
    extracted_files = glob.glob(f'{OUTPUT_BASE}/2024.cpp/main_primeOne_2024_*.cpp')
    extracted_stems = [f.split('main_primeOne_2024_')[1].split('.cpp')[0] for f in extracted_files]
    extracted_set = set(extracted_stems)
    
    # Find missing
    missing = [f for f in archive_stems if f not in extracted_set]
    
    # Sort by date (reverse order - latest first)
    def date_key(s):
        if s == '11_10gbacktrack to11_6d':
            return (11, 10, 'gbacktrack to11_6d')
        parts = s.split('_')
        month = int(parts[0])
        day_suffix = parts[1] if len(parts) > 1 else ''
        day = int(''.join(c for c in day_suffix if c.isdigit()))
        suffix = ''.join(c for c in day_suffix if not c.isdigit())
        return (month, day, suffix)
    
    missing_sorted = sorted(missing, key=date_key, reverse=True)
    return missing_sorted

def main():
    os.makedirs(f"{OUTPUT_BASE}/2024.cpp", exist_ok=True)
    
    missing_files = get_missing_files()
    log(f"Found {len(missing_files)} missing files to process")
    
    success_count = 0
    fail_count = 0
    
    for i, stem in enumerate(missing_files, 1):
        log(f"[{i}/{len(missing_files)}] Processing: {stem}")
        if process_file(stem):
            success_count += 1
        else:
            fail_count += 1
    
    log(f"Complete! Success: {success_count}, Failed: {fail_count}")

if __name__ == "__main__":
    main()