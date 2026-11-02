#!/bin/bash
# primeonecpp_resume.sh - Rebuild environment for PrimeOne CPP extraction
# Usage: ./primeonecpp_resume.sh [--full] [--extract] [--test] [--archive-path PATH]
#   --full          : Full environment setup (install deps, build)
#   --extract       : Run extraction only (requires archive)
#   --test          : Test single file conversion
#   --archive-path  : Path to primebookonexlsm.archive directory (default: auto-detect)
#   --install       : Install dependencies only

set -euo pipefail

# Default paths
WORKSPACE="${WORKSPACE:-/workspace/app}"
DEFAULT_ARCHIVE="${WORKSPACE}/PB1/PrimeBook.CPP/primebookonexlsm.archive"
ARCHIVE_DIR="${ARCHIVE_DIR:-$DEFAULT_ARCHIVE}"
OUTPUT_BASE="${WORKSPACE}/lol.dance/extracted_by_year"
SCRIPTS_DIR="${WORKSPACE}/lol.dance"

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

usage() {
    cat << 'USAGE'
primeonecpp_resume.sh - PrimeOne CPP Extraction Environment

USAGE:
    ./primeonecpp_resume.sh [OPTIONS]

OPTIONS:
    --full              Full environment setup + extraction
    --extract           Run extraction only (requires archive files)
    --test              Test single file conversion
    --install           Install dependencies only
    --archive-path PATH Path to primebookonexlsm.archive directory
    --help              Show this help

EXAMPLES:
    # Fresh environment (installs deps, needs archive files)
    ./primeonecpp_resume.sh --full

    # Extract with custom archive location
    ./primeonecpp_resume.sh --extract --archive-path /path/to/archive

    # Test only (uses built-in test file)
    ./primeonecpp_resume.sh --test

ARCHIVE FILES:
    The script requires original .xlsm files from the PrimeBook.CPP archive.
    These are NOT in git (too large). Place them at:
    $DEFAULT_ARCHIVE/
    
    Or specify with --archive-path

FILES PRODUCED:
    lol.dance/extracted_by_year/
    ├── 2022.cpp/   (5 GyroCore files)
    ├── 2023.cpp/   (7 primeOne files)
    ├── 2024.cpp/   (9 primeOne files)
    └── 2025.cpp/   (6 primeOne files)

USAGE
}

# Parse arguments
ACTION=""
while [[ $# -gt 0 ]]; do
    case $1 in
        --full) ACTION="full" ;;
        --extract) ACTION="extract" ;;
        --test) ACTION="test" ;;
        --install) ACTION="install" ;;
        --archive-path) ARCHIVE_DIR="$2"; shift ;;
        --help) usage; exit 0 ;;
        *) err "Unknown option: $1"; usage; exit 1 ;;
    esac
    shift
done

if [[ -z "$ACTION" ]]; then
    usage
    exit 1
fi

check_archive() {
    if [[ ! -d "$ARCHIVE_DIR" ]]; then
        err "Archive directory not found: $ARCHIVE_DIR"
        err "Expected structure: $ARCHIVE_DIR/primeOne_YYYY_*.xlsm or GyroCore_YYYY_*.xlsm"
        err "Use --archive-path to specify correct location"
        return 1
    fi
    
    local count=$(find "$ARCHIVE_DIR" -name "*.xlsm" | wc -l)
    if [[ $count -eq 0 ]]; then
        err "No .xlsm files found in $ARCHIVE_DIR"
        return 1
    fi
    
    log "Found $count .xlsm files in $ARCHIVE_DIR"
    return 0
}

install_dependencies() {
    log "Installing system dependencies..."
    apt-get update && apt-get install -y \
        libreoffice \
        python3 \
        python3-pip \
        python3-venv \
        python3-uno \
        2>&1 | tail -20
    
    log "Installing Python packages..."
    python3 -m pip install --break-system-packages \
        openpyxl \
        oletools \
        olefile \
        2>&1 | tail -10
    
    log "Dependencies installed successfully"
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
    if [ "$year" = "2022" ]; then
        # Find all .xlsm files in 2022 subdirectory
        while IFS= read -r file; do
            files+=("$file")
        done < <(find "$ARCHIVE_DIR/2022" -maxdepth 1 -name "*.xlsm" | sort)
    elif [ "$year" = "2023" ]; then
        # Find all .xlsm files in 2023 subdirectory
        while IFS= read -r file; do
            files+=("$file")
        done < <(find "$ARCHIVE_DIR/2023" -maxdepth 1 -name "*.xlsm" | sort)
    elif [ "$year" = "2024" ]; then
        # Find all .xlsm files in 2024 subdirectory
        while IFS= read -r file; do
            files+=("$file")
        done < <(find "$ARCHIVE_DIR/2024" -maxdepth 1 -name "primeOne_2024_*.xlsm" | sort)
    elif [ "$year" = "2025" ]; then
        # Find all .xlsm files in 2025 subdirectory
        while IFS= read -r file; do
            files+=("$file")
        done < <(find "$ARCHIVE_DIR/2025" -maxdepth 1 -name "primeOne_2025_*.xlsm" | sort)
    fi
    
    log "  Found ${#files[@]} files to process"
    
    local file_count=0
    for xlsm_file in "${files[@]}"; do
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

run_full_extraction() {
    log "Starting full extraction for all years..."
    if ! check_archive; then
        exit 1
    fi
    for year in 2022 2023 2024 2025; do
        extract_year "$year"
    done
    log "Extraction complete!"
    ls -la "$OUTPUT_BASE"/*/
}

test_single() {
    log "Testing single file conversion..."
    local test_file="$ARCHIVE_DIR/primeOne_2024_02_26.xlsm"
    if [ ! -f "$test_file" ]; then
        # Try to find any 2024 file
        test_file=$(find "$ARCHIVE_DIR" -name "primeOne_2024_*.xlsm" | head -1)
        if [ -z "$test_file" ]; then
            err "No test file found in $ARCHIVE_DIR"
            exit 1
        fi
    fi
    local xlsx_file="/tmp/test_primeOne_2024_02_26.xlsx"
    local output_file="/tmp/test_main.cpp"
    
    if convert_xlsm_to_xlsx "$test_file" "$xlsx_file"; then
        extract_main_cpp "$xlsx_file" "2024" "$output_file"
        head -50 "$output_file"
    fi
}

main() {
    case "$ACTION" in
        full)
            install_dependencies
            run_full_extraction
            ;;
        extract)
            run_full_extraction
            ;;
        test)
            if ! check_archive; then
                err "Test requires archive files"
                exit 1
            fi
            test_single
            ;;
        install)
            install_dependencies
            ;;
        *)
            usage
            exit 1
            ;;
    esac
}

main "$@"
