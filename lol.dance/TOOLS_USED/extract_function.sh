#!/bin/bash
# extract_function.sh - Extract specific function across years

set -euo pipefail

FUNCTION=""
YEARS="2022 2023 2024 2025"
OUTPUT_DIR="/workspace/app/lol.dance/extractions"

while [[ $# -gt 0 ]]; do
    case $1 in
        --function) FUNCTION="$2"; shift ;;
        --years) YEARS="$2"; shift ;;
        --output-dir) OUTPUT_DIR="$2"; shift ;;
        *) echo "Unknown: $1"; exit 1 ;;
    esac
    shift
done

[[ -z "$FUNCTION" ]] && { echo "Usage: --function NAME"; exit 1; }

mkdir -p "$OUTPUT_DIR"

echo "=== Extracting function: $FUNCTION ==="
for YEAR in $YEARS; do
    echo "--- Year: $YEAR ---"
    FOUND=false
    for catalog in /workspace/app/lol.dance/gearslice_analysis/$YEAR/*/todo_catalog.json; do
        [[ -f "$catalog" ]] || continue
        if grep -q "\"name\": \"$FUNCTION\"" "$catalog" 2>/dev/null; then
            STEM=$(basename $(dirname "$catalog"))
            CPP_FILE="/workspace/app/lol.dance/extracted_by_year/${YEAR}.cpp/main_${STEM}.cpp"
            [[ -f "$CPP_FILE" ]] || continue
            echo "  Found in: $STEM"
            python3 -c "
import re
func_name = '$FUNCTION'
cpp_file = '$CPP_FILE'
output_file = '$OUTPUT_DIR/${YEAR}_${STEM}_${FUNCTION}.cpp'

with open(cpp_file) as f:
    content = f.read()

escaped = re.escape(func_name)
# Match from return type through opening brace
pattern = r'^(\s*(?:inline\s+)?(?:static\s+)?(?:\w+(?:\s+\w+)*)\s+' + escaped + r'\s*\([^)]*\)\s*\{)'
matches = list(re.finditer(pattern, content, re.MULTILINE))

if matches:
    for i, match in enumerate(matches):
        start = match.start(1)
        brace_count = 0
        func_lines = []
        found_brace = False
        for j, char in enumerate(content[start:], start):
            if char == '{':
                brace_count += 1
                found_brace = True
            elif char == '}':
                if found_brace:
                    brace_count -= 1
            func_lines.append(char)
            if found_brace and brace_count == 0:
                break
        func_text = ''.join(func_lines)
        suffix = '_' + str(i+1) if len(matches) > 1 else ''
        out_path = output_file.replace('.cpp', suffix + '.cpp')
        with open(out_path, 'w') as f:
            f.write(func_text)
        print('    -> ' + out_path)
else:
    print('    Function body not found')
"
            FOUND=true
        fi
    done
    [[ "$FOUND" == false ]] && echo "  Not found in $YEAR"
done
echo "Done. Output: $OUTPUT_DIR"
