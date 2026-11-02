#!/bin/bash
set -e

archive_dir="/workspace/app/PB1/PrimeBook.CPP/primebookonexlsm.archive"
output_base="/workspace/app/extracted_by_year"

# Kill any existing LibreOffice
pkill -f libreoffice 2>/dev/null; pkill -f soffice 2>/dev/null; sleep 2

# Function to convert and extract
process_file() {
    local xlsm_file="$1"
    local year="$2"
    local output_dir="$3"
    
    local stem=$(basename "$xlsm_file" .xlsm)
    local xlsx_file="/tmp/${stem}.xlsx"
    local output_file="${output_dir}/main_${stem}.cpp"
    
    echo "Processing: $xlsm_file"
    
    # Convert
    libreoffice --headless --calc --convert-to xlsx:"Calc MS Excel 2007 XML" --outdir /tmp "$xlsm_file" 2>&1 | grep -v "^$"
    
    # Wait for file
    local count=0
    while [ ! -f "$xlsx_file" ] && [ $count -lt 10 ]; do
        sleep 1
        count=$((count + 1))
    done
    
    if [ ! -f "$xlsx_file" ]; then
        echo "  FAILED: xlsx not created"
        return 1
    fi
    
    # Extract using Python
    python3 << PYEOF
import openpyxl
import sys

xlsx_path = "$xlsx_file"
year = "$year"
output_path = "$output_file"

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

wb = openpyxl.load_workbook(xlsx_path, data_only=True)
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
    print(f"  No BUILD sheet found")
    sys.exit(1)

cells = CELL_REFS.get(year, [])
with open(output_path, 'w') as f:
    for cell_ref in cells:
        val = build_sheet[cell_ref].value
        if val is not None:
            f.write(str(val))
            f.write('\n')

size = os.path.getsize(output_path)
print(f"  OK: {size} bytes")
PYEOF
}

# Select key files per year (first, monthly, last)
# 2022
for f in "$archive_dir"/GyroCore_2022_05_01e.xlsm \
         "$archive_dir"/GyroCore_2022_05_02b.xlsm \
         "$archive_dir"/GyroCore_2022_06_28.xlsm \
         "$archive_dir"/GyroCore_2022_07_01.xlsm \
         "$archive_dir"/gyroCore_2022_12_30c.xlsm; do
    [ -f "$f" ] && process_file "$f" "2022" "$output_base/2022.cpp"
done

# 2023 - primeOne files from June onwards
for f in "$archive_dir"/primeOne_2023_06_10.xlsm \
         "$archive_dir"/primeOne_2023_07_22f.xlsm \
         "$archive_dir"/primeOne_2023_08_31g.xlsm \
         "$archive_dir"/primeOne_2023_09_23b.xlsm \
         "$archive_dir"/primeOne_2023_10_31b.xlsm \
         "$archive_dir"/primeOne_2023_11_25b.xlsm \
         "$archive_dir"/primeOne_2023_12_28.xlsm; do
    [ -f "$f" ] && process_file "$f" "2023" "$output_base/2023.cpp"
done

# 2024
for f in "$archive_dir"/primeOne_2024_02_26.xlsm \
         "$archive_dir"/primeOne_2024_03_25b.xlsm \
         "$archive_dir"/primeOne_2024_04_15.xlsm \
         "$archive_dir"/primeOne_2024_05_17.xlsm \
         "$archive_dir"/primeOne_2024_06_28.xlsm \
         "$archive_dir"/primeOne_2024_09_30b.xlsm \
         "$archive_dir"/primeOne_2024_10_31e.xlsm \
         "$archive_dir"/primeOne_2024_11_29c.xlsm \
         "$archive_dir"/primeOne_2024_12_30d.xlsm; do
    [ -f "$f" ] && process_file "$f" "2024" "$output_base/2024.cpp"
done

# 2025
for f in "$archive_dir"/primeOne_2025_1_1.xlsm \
         "$archive_dir"/primeOne_2025_1_31i.xlsm \
         "$archive_dir"/primeOne_2025_2_28.xlsm \
         "$archive_dir"/primeOne_2025_3_31c.xlsm \
         "$archive_dir"/primeOne_2025_4_30o.xlsm \
         "$archive_dir"/primeOne_2025_5_31b.xlsm \
         "$archive_dir"/primeOne_2025_6_29.xlsm \
         "$archive_dir"/primeOne_2025_6_30.xlsm 2>/dev/null; do
    [ -f "$f" ] && process_file "$f" "2025" "$output_base/2025.cpp"
done

echo "All done!"
