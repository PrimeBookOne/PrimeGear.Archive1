import os
import re
import subprocess
import openpyxl
import time
from pathlib import Path

archive_dir = Path('/workspace/app/PB1/PrimeBook.CPP/primebookonexlsm.archive')
output_base = Path('/workspace/app/extracted_by_year')

# Create output directories
for year in ['2022', '2023', '2024', '2025']:
    (output_base / f'{year}.cpp').mkdir(parents=True, exist_ok=True)

# Find all xlsm files grouped by year
files_by_year = {'2022': [], '2023': [], '2024': [], '2025': []}

for f in archive_dir.glob('*.xlsm'):
    fname = f.name
    year_match = re.search(r'(202[2-5])', fname)
    if year_match:
        year = year_match.group(1)
        # Only process primeOne and GyroCore files (not SERVICE, GUI, etc.)
        if 'primeOne' in fname or 'GyroCore' in fname or 'gyroCore' in fname:
            files_by_year[year].append(f)

def extract_date(fname):
    match = re.search(r'(202[2-5])_(\d{1,2})_(\d{1,2})', fname)
    if match:
        y, m, d = match.groups()
        return (int(y), int(m), int(d))
    return (0, 0, 0)

for year in files_by_year:
    files_by_year[year].sort(key=lambda f: extract_date(f.name))

print("Files per year (primeOne/GyroCore only):")
for year, files in files_by_year.items():
    print(f"  {year}: {len(files)} files")

# Select key files per year - one per month plus first/last
def select_key_files(files):
    if not files:
        return []
    by_month = {}
    for f in files:
        date = extract_date(f.name)
        key = (date[0], date[1])
        if key not in by_month:
            by_month[key] = []
        by_month[key].append(f)
    
    selected = []
    selected.append(files[0])
    for month_key in sorted(by_month.keys()):
        selected.append(by_month[month_key][-1])
    selected.append(files[-1])
    
    seen = set()
    unique = []
    for f in selected:
        if f not in seen:
            seen.add(f)
            unique.append(f)
    return unique

# Cell references for Create_CPP_File macro by year
CELL_REFS = {
    '2022': ['C21','C22','C23','C24','C25','C26','C27','C28','A82','A83','A84','A85','C30','C31','C32'],
    '2023': [f'A{i}' for i in range(37, 171)],
    '2024': [
        'A37','A38','A39','A40','A41',
        'A175','A176','A177','A178','A179','A180','A181','A182','A183','A184','A185','A186','A187','A188','A189','A190','A191','A192','A193','A194','A195','A196','A197','A198','A199','A200','A201','A202','A203','A204','A205','A206','A207','A208','A209','A210','A211','A212','A213','A214','A215','A216','A217','A218','A219','A220','A221','A222','A223','A224','A225','A226','A227','A228','A229','A230','A231','A232','A233','A234','A235','A236','A237','A238','A239','A240','A241','A242','A243','A244','A245','A246','A247','A248','A249','A250','A251','A252','A253','A254','A255','A256',
        'A42','A43','A44','A45','A46','A47','A48','A49','A50','A51','A52','A53','A54','A55','A56','A57','A58','A59','A60','A61','A62','A63','A64','A65','A66','A67','A68','A69','A70','A71','A72','A73','A74','A75','A76','A77','A78','A79','A80','A81','A82','A83','A84','A85','A86','A87','A88','A89','A90','A91','A92','A93','A94'
    ],
    '2025': [
        'A37','A38','A39','A40','A41','A44','A46','A45',
        'A175','A176','A177','A179','A180','A181','A182','A183','A184','A185','A186','A187','A188','A189','A190','A191','A192','A193','A194','A195','A196','A197','A198','A199','A200','A201','A202','A203','A204','A205','A206','A207','A208','A209','A210','A211','A212','A213','A214','A215','A216','A217','A218','A219','A220','A221','A223','A224','A225','A226','A228','A230','A233','A234','A236','A237','A238','A240','A242','A256',
        'A42','A43',
        'A300','A301','A302','A303','A304','A305','A306','A307','A308','A309','A310','A311','A312','A314','A318','A319','A324',
        'A47','A48','A49','A50','A51','A52','A55','A56','A57','A58','A59','A60','A62','A63','A64','A65','A66','A74','A81','A82','A83','A84','A89','A90','A91','A92','A94','A96','A98','A99','A100','A102','A103','A104','A113','A114','A116','A124','A125','A126','A131','A132','A133','A134','A135','A136','A137','A138','A139','A140','A142','A143','A145','A146','A147','A148','A149','A150','A151','A152','A153','A154','A155','A156','A157','A158','A159','A160','A161','A162','A163','A164','A165','A167','A168'
    ]
}

def convert_to_xlsx(xlsm_path, xlsx_path):
    """Convert xlsm to xlsx using LibreOffice headless"""
    try:
        result = subprocess.run([
            'libreoffice', '--headless', '--calc', 
            '--convert-to', 'xlsx:"Calc MS Excel 2007 XML"',
            '--outdir', str(xlsx_path.parent),
            str(xlsm_path)
        ], capture_output=True, text=True, timeout=120)
        # Wait a bit for file to be written
        time.sleep(1)
        return xlsx_path.exists()
    except Exception as e:
        print(f"  Error converting {xlsm_path.name}: {e}")
        return False

def extract_main_cpp(xlsx_path, year, output_path):
    """Extract main.cpp from xlsx using year-specific cell references"""
    try:
        wb = openpyxl.load_workbook(xlsx_path, data_only=True)
        
        # Find BUILD sheet
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
            print(f"  No BUILD sheet found in {xlsx_path.name}")
            return False
        
        cells = CELL_REFS.get(year, [])
        if not cells:
            print(f"  No cell refs for year {year}")
            return False
        
        with open(output_path, 'w') as f:
            for cell_ref in cells:
                val = build_sheet[cell_ref].value
                if val is not None:
                    f.write(str(val))
                    f.write('\n')
        
        return True
    except Exception as e:
        print(f"  Error extracting {xlsx_path.name}: {e}")
        return False

# Process selected files for each year
for year in ['2022', '2023', '2024', '2025']:
    files = files_by_year[year]
    if not files:
        continue
    
    key_files = select_key_files(files)
    print(f"\nProcessing {year}: {len(key_files)} key files")
    
    for xlsm_file in key_files:
        date_str = xlsm_file.stem.replace('primeOne_', '').replace('GyroCore_', '').replace('gyroCore_', '')
        output_file = output_base / f'{year}.cpp' / f'main_{date_str}.cpp'
        xlsx_file = Path('/tmp') / f'{xlsm_file.stem}.xlsx'
        
        print(f"  {xlsm_file.name} -> {output_file.name}")
        
        # Convert
        if convert_to_xlsx(xlsm_file, xlsx_file):
            # Extract
            if extract_main_cpp(xlsx_file, year, output_file):
                size = output_file.stat().st_size
                print(f"    OK: {size} bytes")
            else:
                print(f"    FAILED: extraction")
        else:
            print(f"    FAILED: conversion (file not created)")

print("\nDone!")

