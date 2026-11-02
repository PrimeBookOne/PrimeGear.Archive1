#!/bin/bash
# Process missing 2024 files in reverse chronological order

set -euo pipefail

WORKSPACE="/workspace/app"
ARCHIVE_DIR="${WORKSPACE}/PB1/PrimeBook.CPP/primebookonexlsm.archive"
OUTPUT_BASE="${WORKSPACE}/lol.dance/extracted_by_year"
SCRIPTS_DIR="${WORKSPACE}/lol.dance"

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

log() { echo -e "${GREEN}[INFO]${NC} $*"; }
warn() { echo -e "${YELLOW}[WARN]${NC} $*"; }
err() { echo -e "${RED}[ERROR]${NC} $*"; }

kill_libreoffice() {
    pkill -f libreoffice 2>/dev/null || true
    pkill -f soffice 2>/dev/null || true
    sleep 2
}

convert_xlsm_to_xlsx() {
    local xlsm_file="$1"
    local target_xlsx="$2"
    local stem=$(basename "$xlsm_file" .xlsm)
    local default_xlsx="/tmp/${stem}.xlsx"
    
    kill_libreoffice
    
    rm -f "$default_xlsx" "$target_xlsx"
    
    libreoffice --headless --calc \
        --convert-to xlsx:"Calc MS Excel 2007 XML" \
        --outdir /tmp \
        "$xlsm_file" 2>&1 | grep -v "^$"
    
    local count=0
    while [ ! -f "$default_xlsx" ] && [ $count -lt 15 ]; do
        sleep 1
        count=$((count + 1))
    done
    
    if [ ! -f "$default_xlsx" ]; then
        err "Conversion failed: $default_xlsx not created"
        return 1
    fi
    
    if [ "$default_xlsx" != "$target_xlsx" ]; then
        mv "$default_xlsx" "$target_xlsx"
    fi
    return 0
}

extract_main_cpp() {
    local xlsx_file="$1"
    local year="$2"
    local output_file="$3"
    
    python3 << PYEOF
import openpyxl
import sys

xlsx_path = "$xlsx_file"
year = "$year"
output_path = "$output_file"

CELL_REFS = {
    '2024': [
        'A37','A38','A39','A40','A41',
        'A175','A176','A177','A178','A179','A180','A181','A182','A183','A184','A185','A186','A187','A188','A189','A190','A191','A192','A193','A194','A195','A196','A197','A198','A199','A200','A201','A202','A203','A204','A205','A206','A207','A208','A209','A210','A211','A212','A213','A214','A215','A216','A217','A218','A219','A220','A221','A222','A223','A224','A225','A226','A227','A228','A229','A230','A231','A232','A233','A234','A235','A236','A237','A238','A239','A240','A241','A242','A243','A244','A245','A246','A247','A248','A249','A250','A251','A252','A253','A254','A255','A256',
        'A42','A43','A44','A45','A46','A47','A48','A49','A50','A51','A52','A53','A54','A55','A56','A57','A58','A59','A60','A61','A62','A63','A64','A65','A66','A67','A68','A69','A70','A71','A72','A73','A74','A75','A76','A77','A78','A79','A80','A81','A82','A83','A84','A85','A86','A87','A88','A89','A90','A91','A92','A93','A94'
    ]
}

try:
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
        print("  No BUILD sheet found", file=sys.stderr)
        sys.exit(1)
    
    cells = CELL_REFS.get(year, [])
    if not cells:
        print(f"  No cell refs for year {year}", file=sys.stderr)
        sys.exit(1)
    
    with open(output_path, 'w') as f:
        for cell_ref in cells:
            val = build_sheet[cell_ref].value
            if val is not None:
                f.write(str(val))
                f.write('\n')
    
    import os
    size = os.path.getsize(output_path)
    print(f"  OK: {size} bytes")
    
except Exception as e:
    print(f"  Error extracting: {e}", file=sys.stderr)
    sys.exit(1)
PYEOF
}

# Get missing files in reverse order
get_missing_files() {
    # Get all archive files
    local archive_stems=()
    while IFS= read -r file; do
        local stem=$(basename "$file" .xlsm)
        stem=${stem#primeOne_2024_}
        archive_stems+=("$stem")
    done < <(find "$ARCHIVE_DIR/2024" -maxdepth 1 -name "primeOne_2024_*.xlsm" | sort)
    
    # Get extracted files
    local extracted_stems=()
    while IFS= read -r file; do
        local stem=$(basename "$file" .cpp)
        stem=${stem#main_primeOne_2024_}
        extracted_stems+=("$stem")
    done < <(find "$OUTPUT_BASE/2024.cpp" -maxdepth 1 -name "main_primeOne_2024_*.cpp" 2>/dev/null | sort)
    
    # Create associative array of extracted files
    declare -A extracted_set
    for stem in "${extracted_stems[@]}"; do
        extracted_set[$stem]=1
    done
    
    # Find missing
    local missing=()
    for stem in "${archive_stems[@]}"; do
        if [[ -z ${extracted_set[$stem]+_} ]]; then
            missing+=("$stem")
        fi
    done
    
    # Sort missing in reverse chronological order
    # We'll use a simple approach: sort by month/day numerically, then reverse
    printf '%s\n' "${missing[@]}" | python3 -c "
import sys

def date_key(s):
    if s == '11_10gbacktrack to11_6d':
        return (11, 10, 'gbacktrack to11_6d')
    parts = s.split('_')
    month = int(parts[0])
    day_suffix = parts[1] if len(parts) > 1 else ''
    day = int(''.join(c for c in day_suffix if c.isdigit()))
    suffix = ''.join(c for c in day_suffix if not c.isdigit())
    return (month, day, suffix)

lines = [line.strip() for line in sys.stdin if line.strip()]
lines.sort(key=date_key, reverse=True)
for line in lines:
    print(line)
"
}

main() {
    mkdir -p "$OUTPUT_BASE/2024.cpp"
    
    log "Finding missing 2024 files..."
    mapfile -t missing_files < <(get_missing_files)
    
    log "Found ${#missing_files[@]} missing files to process"
    
    local success_count=0
    local fail_count=0
    local i=0
    
    for stem in "${missing_files[@]}"; do
        i=$((i + 1))
        log "[$i/${#missing_files[@]}] Processing: $stem"
        
        local xlsm_file="${ARCHIVE_DIR}/2024/primeOne_2024_${stem}.xlsm"
        local xlsx_file="/tmp/primeOne_2024_${stem}.xlsx"
        local output_file="${OUTPUT_BASE}/2024.cpp/main_primeOne_2024_${stem}.cpp"
        
        if [ ! -f "$xlsm_file" ]; then
            warn "File not found: $xlsm_file"
            fail_count=$((fail_count + 1))
            continue
        fi
        
        if convert_xlsm_to_xlsx "$xlsm_file" "$xlsx_file"; then
            if extract_main_cpp "$xlsx_file" "2024" "$output_file"; then
                success_count=$((success_count + 1))
            else
                warn "Extraction failed for $xlsm_file"
                fail_count=$((fail_count + 1))
            fi
        else
            err "Failed to convert: $xlsm_file"
            fail_count=$((fail_count + 1))
        fi
    done
    
    log "Complete! Success: $success_count, Failed: $fail_count"
}

main "$@"