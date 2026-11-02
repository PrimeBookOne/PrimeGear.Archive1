import os
import re
import subprocess
import openpyxl
import time
from pathlib import Path

archive_dir = Path('/workspace/app/PB1/PrimeBook.CPP/primebookonexlsm.archive/2024')
output_base = Path('/workspace/app/lol.dance/extracted_by_year/2024.cpp')

# Cell references for Create_CPP_File macro for 2024
CELL_REFS_2024 = [
    'A37','A38','A39','A40','A41',
    'A175','A176','A177','A178','A179','A180','A181','A182','A183','A184','A185','A186','A187','A188','A189','A190','A191','A192','A193','A194','A195','A196','A197','A198','A199','A200','A201','A202','A203','A204','A205','A206','A207','A208','A209','A210','A211','A212','A213','A214','A215','A216','A217','A218','A219','A220','A221','A222','A223','A224','A225','A226','A227','A228','A229','A230','A231','A232','A233','A234','A235','A236','A237','A238','A239','A240','A241','A242','A243','A244','A245','A246','A247','A248','A249','A250','A251','A252','A253','A254','A255','A256',
    'A42','A43','A44','A45','A46','A47','A48','A49','A50','A51','A52','A53','A54','A55','A56','A57','A58','A59','A60','A61','A62','A63','A64','A65','A66','A67','A68','A69','A70','A71','A72','A73','A74','A75','A76','A77','A78','A79','A80','A81','A82','A83','A84','A85','A86','A87','A88','A89','A90','A91','A92','A93','A94'
]

def kill_libreoffice():
    subprocess.run(['pkill', '-f', 'libreoffice'], capture_output=True)
    subprocess.run(['pkill', '-f', 'soffice'], capture_output=True)
    time.sleep(2)

def convert_xlsm_to_xlsx(xlsm_file, target_xlsx):
    stem = xlsm_file.stem
    default_xlsx = Path(f'/tmp/{stem}.xlsx')
    
    kill_libreoffice()
    
    # Remove any existing files
    default_xlsx.unlink(missing_ok=True)
    target_xlsx.unlink(missing_ok=True)
    
    result = subprocess.run([
        'libreoffice', '--headless', '--calc',
        '--convert-to', 'xlsx',
        '--outdir', '/tmp',
        str(xlsm_file)
    ], capture_output=True, text=True, timeout=120)
    
    # Wait for file to appear
    count = 0
    while not default_xlsx.exists() and count < 15:
        time.sleep(1)
        count += 1
    
    if not default_xlsx.exists():
        print(f"  Conversion failed: {default_xlsx} not created")
        return False
    
    if default_xlsx != target_xlsx:
        default_xlsx.rename(target_xlsx)
    return True

def extract_main_cpp(xlsx_file, output_file):
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
            print(f"  No BUILD sheet found in {xlsx_file.name}")
            return False
        
        with open(output_file, 'w') as f:
            for cell_ref in CELL_REFS_2024:
                val = build_sheet[cell_ref].value
                if val is not None:
                    f.write(str(val))
                    f.write('\n')
        
        size = os.path.getsize(output_file)
        print(f"  OK: {size} bytes")
        return True
        
    except Exception as e:
        print(f"  Error extracting: {e}")
        return False

# Get list of already processed files
processed_files = set()
for f in output_base.glob('main_primeOne_2024_*.cpp'):
    stem = f.name.replace('main_primeOne_', '').replace('.cpp', '')
    processed_files.add(stem)

# Get all 2024 xlsm files
all_files = []
for xlsm_file in archive_dir.glob('primeOne_2024_*.xlsm'):
    stem = xlsm_file.stem.replace('primeOne_', '')
    if stem not in processed_files:
        all_files.append(xlsm_file)

# Sort by date
def extract_date(fname):
    match = re.search(r'(202[2-5])_(\d{1,2})_(\d{1,2})', fname)
    if match:
        y, m, d = match.groups()
        return (int(y), int(m), int(d))
    return (0, 0, 0)

all_files.sort(key=lambda f: extract_date(f.name))

print(f"Found {len(all_files)} unprocessed 2024 files")

for xlsm_file in all_files:
    stem = xlsm_file.stem.replace('primeOne_', '')
    xlsx_file = Path(f'/tmp/{xlsm_file.stem}.xlsx')
    output_file = output_base / f'main_primeOne_{stem}.cpp'
    
    print(f"Processing: {xlsm_file.name}")
    
    if convert_xlsm_to_xlsx(xlsm_file, xlsx_file):
        extract_main_cpp(xlsx_file, output_file)
    else:
        print(f"  Failed to convert: {xlsm_file.name}")

print("\nDone!")