#!/bin/bash
# Extract only 2025 files

set -euo pipefail

WORKSPACE="${WORKSPACE:-/workspace/app}"
ARCHIVE_DIR="${ARCHIVE_DIR:-${WORKSPACE}/PB1/PrimeBook.CPP/primebookonexlsm.archive}"
OUTPUT_BASE="${WORKSPACE}/lol.dance/extracted_by_year"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

log() { echo -e "${GREEN}[INFO]${NC} $*"; }
warn() { echo -e "${YELLOW}[WARN]${NC} $*"; }
err() { echo -e "${RED}[ERROR]${NC} $*"; }

# Git commit and push after every 5 conversions
GIT_COMMIT_COUNT=0
GIT_BATCH_SIZE=5

git_commit_and_push() {
    local year="$1"
    local output_dir="${OUTPUT_BASE}/${year}.cpp"
    
    # Check if there are any new/untracked files to commit
    local new_files=$(git status --porcelain "$output_dir" 2>/dev/null | grep "^??" | wc -l)
    local modified_files=$(git status --porcelain "$output_dir" 2>/dev/null | grep "^ M" | wc -l)
    
    if [ "$new_files" -gt 0 ] || [ "$modified_files" -gt 0 ]; then
        log "  [GIT] Committing $new_files new + $modified_files modified files for $year..."
        git add "$output_dir"
        git commit -m "Extract $year: batch of ${GIT_BATCH_SIZE} files (auto-commit)" 2>&1 | tail -3
        git push origin HEAD 2>&1 | tail -3
        log "  [GIT] Push complete for $year"
    fi
}

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
    
    # Remove any existing files
    rm -f "$default_xlsx" "$target_xlsx"
    
    libreoffice --headless --calc \
        --convert-to xlsx:"Calc MS Excel 2007 XML" \
        --outdir /tmp \
        "$xlsm_file" 2>&1 | grep -v "^$"
    
    # Wait for file to appear (LibreOffice uses original filename)
    local count=0
    while [ ! -f "$default_xlsx" ] && [ $count -lt 15 ]; do
        sleep 1
        count=$((count + 1))
    done
    
    if [ ! -f "$default_xlsx" ]; then
        err "Conversion failed: $default_xlsx not created"
        return 1
    fi
    
    # Move to target location if different
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

extract_year() {
    local year="$1"
    local output_dir="${OUTPUT_BASE}/${year}.cpp"
    mkdir -p "$output_dir"
    
    log "Processing year $year..."
    
    local files=()
    # Find all .xlsm files in 2025 subdirectory matching primeOne_2025_*
    while IFS= read -r file; do
        files+=("$file")
    done < <(find "$ARCHIVE_DIR/2025" -maxdepth 1 -name "primeOne_2025_*.xlsm" | sort)
    
    log "  Found ${#files[@]} files to process"
    
    # Check which files are already processed
    local already_processed=0
    local to_process=()
    for xlsm_file in "${files[@]}"; do
        local stem=$(basename "$xlsm_file" .xlsm)
        local output_file="${output_dir}/main_${stem}.cpp"
        if [ -f "$output_file" ] && [ -s "$output_file" ]; then
            already_processed=$((already_processed + 1))
        else
            to_process+=("$xlsm_file")
        fi
    done
    
    log "  Already processed: $already_processed"
    log "  Remaining to process: ${#to_process[@]}"
    
    local file_count=0
    for xlsm_file in "${to_process[@]}"; do
        if [ ! -f "$xlsm_file" ]; then
            warn "File not found: $xlsm_file"
            continue
        fi
        
        local stem=$(basename "$xlsm_file" .xlsm)
        local xlsx_file="/tmp/${stem}.xlsx"
        local output_file="${output_dir}/main_${stem}.cpp"
        
        log "  Converting: $xlsm_file"
        if convert_xlsm_to_xlsx "$xlsm_file" "$xlsx_file"; then
            log "  Extracting: $output_file"
            extract_main_cpp "$xlsx_file" "$year" "$output_file" || warn "  Extraction failed for $xlsm_file"
        else
            err "  Failed to convert: $xlsm_file"
        fi
        
        file_count=$((file_count + 1))
        GIT_COMMIT_COUNT=$((GIT_COMMIT_COUNT + 1))
        
        # Commit and push every 5 files
        if [ $((GIT_COMMIT_COUNT % GIT_BATCH_SIZE)) -eq 0 ]; then
            git_commit_and_push "$year"
        fi
    done
    
    # Final commit for any remaining files
    if [ $((GIT_COMMIT_COUNT % GIT_BATCH_SIZE)) -ne 0 ]; then
        git_commit_and_push "$year"
    fi
}

# Check archive
if [[ ! -d "$ARCHIVE_DIR" ]]; then
    err "Archive directory not found: $ARCHIVE_DIR"
    exit 1
fi

count=$(find "$ARCHIVE_DIR" -name "*.xlsm" | wc -l)
log "Found $count .xlsm files in $ARCHIVE_DIR"

extract_year "2025"
log "Extraction complete for 2025!"
ls -la "$OUTPUT_BASE"/2025.cpp/