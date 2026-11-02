#!/bin/bash
# extract_class.sh - Extract class definition across years
# Usage: ./extract_class.sh --class NAME [--year YYYY] [--output-dir PATH]

set -euo pipefail

CLASS=""
YEAR=""
OUTPUT_DIR="/workspace/app/lol.dance/extractions"

while [[ $# -gt 0 ]]; do
    case $1 in
        --class) CLASS="$2"; shift ;;
        --year) YEAR="$2"; shift ;;
        --output-dir) OUTPUT_DIR="$2"; shift ;;
        *) echo "Unknown: $1"; exit 1 ;;
    esac
    shift
done

[[ -z "$CLASS" ]] && { echo "Usage: --class NAME"; exit 1; }
[[ -z "$YEAR" ]] && YEARS="2022 2023 2024 2025" || YEARS="$YEAR"

mkdir -p "$OUTPUT_DIR"

echo "=== Extracting class: $CLASS ==="
for Y in $YEARS; do
    echo "--- Year: $Y ---"
    
    for catalog in /workspace/app/lol.dance/gearslice_analysis/$Y/*/todo_catalog.json; do
        [[ -f "$catalog" ]] || continue
        if grep -q "\"name\": \"$CLASS\"" "$catalog" 2>/dev/null; then
            STEM=$(basename $(dirname "$catalog"))
            CPP_FILE="/workspace/app/lol.dance/extracted_by_year/${Y}.cpp/main_${STEM}.cpp"
            if [[ -f "$CPP_FILE" ]]; then
                echo "  Found in: $STEM"
                # Extract class with methods
                awk -v cn="$CLASS" '
                    $0 ~ "class " cn || $0 ~ "struct " cn { in_class=1; brace=0; print; next }
                    in_class {
                        brace += gsub(/{/,"{")
                        brace -= gsub(/}/,"}")
                        print
                        if (brace == 0 && /^}/) { in_class=0; exit }
                    }
                ' "$CPP_FILE" > "$OUTPUT_DIR/${Y}_${STEM}_${CLASS}.hpp"
                echo "    -> $OUTPUT_DIR/${Y}_${STEM}_${CLASS}.hpp"
            fi
        fi
    done
done

echo "Done. Output: $OUTPUT_DIR"
