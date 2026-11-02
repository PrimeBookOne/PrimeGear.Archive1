#!/bin/bash
# Process 2023 files in batches

ARCHIVE_DIR="PB1/PrimeBook.CPP/primebookonexlsm.archive"
OUTPUT_BASE="lol.dance/extracted_by_year"
BATCH_SIZE=25

# Get remaining files
find "$ARCHIVE_DIR/2023" -maxdepth 1 -name "*.xlsm" -exec basename {} .xlsm \; | sort > /tmp/all_2023_basenames.txt
ls "$OUTPUT_BASE/2023.cpp"/*.cpp 2>/dev/null | sed 's|.*/main_||; s|\.cpp$||' | sort > /tmp/processed_2023.txt
comm -23 /tmp/all_2023_basenames.txt /tmp/processed_2023.txt > /tmp/remaining_2023.txt

TOTAL=$(wc -l < /tmp/remaining_2023.txt)
echo "Total remaining: $TOTAL"

BATCH=1
while IFS= read -r stem; do
    echo "Batch $BATCH: Processing $stem"
    
    xlsm_file="$ARCHIVE_DIR/2023/$stem.xlsm"
    xlsx_file="/tmp/$stem.xlsx"
    output_file="$OUTPUT_BASE/2023.cpp/main_$stem.cpp"
    
    # Convert
    pkill -f libreoffice 2>/dev/null || true
    pkill -f soffice 2>/dev/null || true
    sleep 1
    rm -f "$xlsx_file"
    
    libreoffice --headless --calc \
        --convert-to xlsx:"Calc MS Excel 2007 XML" \
        --outdir /tmp \
        "$xlsm_file" 2>&1 | grep -v "^$"
    
    # Wait for file
    count=0
    while [ ! -f "$xlsx_file" ] && [ $count -lt 15 ]; do
        sleep 1
        count=$((count + 1))
    done
    
    if [ ! -f "$xlsx_file" ]; then
        echo "  ERROR: Conversion failed for $stem"
        continue
    fi
    
    # Extract
    python3 << PYEOF
import openpyxl
import sys

xlsx_path = "$xlsx_file"
output_path = "$output_file"

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
        print(f"  No BUILD sheet found for $stem")
        sys.exit(1)
    
    cells = [f'A{i}' for i in range(37, 171)]
    
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
    print(f"  Error extracting: {e}")
    sys.exit(1)
PYEOF
    
    # Push every batch
    if [ $((BATCH % 5)) -eq 0 ]; then
        echo "Pushing to GitHub..."
        git add "$OUTPUT_BASE/2023.cpp/"
        git commit -m "feat: extract 2023 batch $BATCH ($stem)" 2>/dev/null || true
        git push origin HEAD 2>/dev/null || true
    fi
    
    BATCH=$((BATCH + 1))
done < /tmp/remaining_2023.txt

# Final push
echo "Final push..."
git add "$OUTPUT_BASE/2023.cpp/"
git commit -m "feat: extract 2023 final batch" 2>/dev/null || true
git push origin HEAD 2>/dev/null || true

echo "Done!"