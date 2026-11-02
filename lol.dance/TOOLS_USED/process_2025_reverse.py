#!/usr/bin/env python3
"""
Process 2025 PrimeOne files in reverse order (newest first)
Skipping already extracted files
"""

import os
import sys
import subprocess
import shutil

ARCHIVE_DIR = "/workspace/app/PB1/PrimeBook.CPP/primebookonexlsm.archive/2025"
OUTPUT_DIR = "/workspace/app/lol.dance/extracted_by_year/2025.cpp"

# Already extracted files (from the output directory)
EXTRACTED = {
    "primeOne_2025_1_1",
    "primeOne_2025_1_31i",
    "primeOne_2025_2_28",
    "primeOne_2025_3_31c",
    "primeOne_2025_4_30o",
    "primeOne_2025_5_31b",
}

CELL_REFS_2025 = [
    'A37','A38','A39','A40','A41','A44','A46','A45',
    'A175','A176','A177','A179','A180','A181','A182','A183','A184','A185','A186','A187','A188','A189','A190','A191','A192','A193','A194','A195','A196','A197','A198','A199','A200','A201','A202','A203','A204','A205','A206','A207','A208','A209','A210','A211','A212','A213','A214','A215','A216','A217','A218','A219','A220','A221','A223','A224','A225','A226','A228','A230','A233','A234','A236','A237','A238','A240','A242','A256',
    'A42','A43',
    'A300','A301','A302','A303','A304','A305','A306','A307','A308','A309','A310','A311','A312','A314','A318','A319','A324',
    'A47','A48','A49','A50','A51','A52','A55','A56','A57','A58','A59','A60','A62','A63','A64','A65','A66','A74','A81','A82','A83','A84','A89','A90','A91','A92','A94','A96','A98','A99','A100','A102','A103','A104','A113','A114','A116','A124','A125','A126','A131','A132','A133','A134','A135','A136','A137','A138','A139','A140','A142','A143','A145','A146','A147','A148','A149','A150','A151','A152','A153','A154','A155','A156','A157','A158','A159','A160','A161','A162','A163','A164','A165','A167','A168'
]

def kill_libreoffice():
    subprocess.run(["pkill", "-f", "libreoffice"], capture_output=True)
    subprocess.run(["pkill", "-f", "soffice"], capture_output=True)
    import time
    time.sleep(3)

# Kill once at startup
kill_libreoffice()

def convert_xlsm_to_xlsx(xlsm_file, target_xlsx):
    stem = os.path.basename(xlsm_file).replace('.xlsm', '')
    default_xlsx = f"/tmp/{stem}.xlsx"
    
    for f in [default_xlsx, target_xlsx]:
        if os.path.exists(f):
            os.remove(f)
    
    # Try up to 3 times
    for attempt in range(3):
        print(f"  Converting (attempt {attempt+1}/3)...")
        result = subprocess.run([
            "libreoffice", "--headless", "--calc",
            "--convert-to", "xlsx:Calc MS Excel 2007 XML",
            "--outdir", "/tmp",
            xlsm_file
        ], capture_output=True, text=True, timeout=240)
        
        if result.stdout:
            print(f"  LO stdout: {result.stdout[:300]}")
        if result.stderr:
            print(f"  LO stderr: {result.stderr[:300]}")
        
        for _ in range(25):
            if os.path.exists(default_xlsx):
                break
            import time
            time.sleep(1)
        
        if os.path.exists(default_xlsx):
            if default_xlsx != target_xlsx:
                shutil.move(default_xlsx, target_xlsx)
            return True, "OK"
        
        print(f"  Attempt {attempt+1} failed, retrying...")
        kill_libreoffice()
    
    return False, f"Conversion failed after 3 attempts: {default_xlsx} not created"

def extract_main_cpp(xlsx_file, output_file):
    import openpyxl
    
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
        return False, "No BUILD sheet found"
    
    with open(output_file, 'w') as f:
        for cell_ref in CELL_REFS_2025:
            val = build_sheet[cell_ref].value
            if val is not None:
                f.write(str(val))
                f.write('\n')
    
    size = os.path.getsize(output_file)
    return True, f"OK: {size} bytes"

def main():
    # Get all primeOne_2025_*.xlsm files
    files = []
    for f in os.listdir(ARCHIVE_DIR):
        if f.startswith("primeOne_2025_") and f.endswith(".xlsm"):
            stem = f[:-5]  # remove .xlsm
            if stem not in EXTRACTED:
                files.append((f, stem))
    
    # Sort in reverse order (newest first)
    # The filename format is primeOne_2025_M_DD or primeOne_2025_M_DDx
    # We'll sort by the full filename in reverse
    files.sort(key=lambda x: x[0], reverse=True)
    
    print(f"Found {len(files)} files to process (skipping {len(EXTRACTED)} already done)")
    
    os.makedirs(OUTPUT_DIR, exist_ok=True)
    
    for i, (filename, stem) in enumerate(files):
        xlsm_path = os.path.join(ARCHIVE_DIR, filename)
        xlsx_path = f"/tmp/{stem}.xlsx"
        output_path = os.path.join(OUTPUT_DIR, f"main_{stem}.cpp")
        
        print(f"\n[{i+1}/{len(files)}] Processing: {filename}")
        
        # Convert
        ok, msg = convert_xlsm_to_xlsx(xlsm_path, xlsx_path)
        if not ok:
            print(f"  FAILED convert: {msg}")
            continue
        
        # Extract
        ok, msg = extract_main_cpp(xlsx_path, output_path)
        if not ok:
            print(f"  FAILED extract: {msg}")
            continue
        
        print(f"  SUCCESS: {msg}")
        
        # Cleanup temp xlsx
        if os.path.exists(xlsx_path):
            os.remove(xlsx_path)
    
    print("\nDone!")

if __name__ == "__main__":
    main()