#!/bin/bash
# repair_base_classes.sh - Inject missing base classes into target year
# Usage: ./repair_base_classes.sh --target-year YYYY --source-year YYYY [--output-dir PATH]

set -euo pipefail

TARGET_YEAR=""
SOURCE_YEAR=""
OUTPUT_DIR="/workspace/app/lol.dance/repairs"

while [[ $# -gt 0 ]]; do
    case $1 in
        --target-year) TARGET_YEAR="$2"; shift ;;
        --source-year) SOURCE_YEAR="$2"; shift ;;
        --output-dir) OUTPUT_DIR="$2"; shift ;;
        *) echo "Unknown: $1"; exit 1 ;;
    esac
    shift
done

[[ -z "$TARGET_YEAR" || -z "$SOURCE_YEAR" ]] && { echo "Usage: --target-year YYYY --source-year YYYY"; exit 1; }

mkdir -p "$OUTPUT_DIR"

echo "=== Repairing base classes: $SOURCE_YEAR -> $TARGET_YEAR ==="

# Extract classes from source year
SOURCE_CLASSES=$(find /workspace/app/lol.dance/gearslice_analysis/$SOURCE_YEAR -name "todo_catalog.json" -exec grep -l "class" {} \; | head -20)

# Generate repair header
REPAIR_HEADER="$OUTPUT_DIR/repair_${SOURCE_YEAR}_to_${TARGET_YEAR}_bases.hpp"
cat > "$REPAIR_HEADER" << HEADER_EOF
// AUTO-GENERATED: Base class repairs from $SOURCE_YEAR for $TARGET_YEAR
// Generated: $(date)
// DO NOT EDIT MANUALLY - Regenerate with repair_base_classes.sh

#ifndef REPAIR_BASES_${SOURCE_YEAR}_TO_${TARGET_YEAR}_HPP
#define REPAIR_BASES_${SOURCE_YEAR}_TO_${TARGET_YEAR}_HPP

#include <string>
#include <vector>
#include <map>
#include <functional>
#include <memory>

HEADER_EOF

# Extract class definitions from source year catalogs
python3 << PYEOF
import json
import os

source_year = "$SOURCE_YEAR"
output_file = "$REPAIR_HEADER"

classes_found = {}
for root, dirs, files in os.walk(f"/workspace/app/lol.dance/gearslice_analysis/{source_year}"):
    for f in files:
        if f == "todo_catalog.json":
            path = os.path.join(root, f)
            with open(path) as fp:
                data = json.load(fp)
                for cls in data.get("classes", []):
                    key = f"{cls['type']} {cls['name']}"
                    if key not in classes_found:
                        classes_found[key] = cls

with open(output_file, "a") as f:
    f.write(f"// Found {len(classes_found)} classes in {source_year}\n\n")
    
    for key, cls in classes_found.items():
        f.write(f"// === {cls['type']} {cls['name']} ===\n")
        f.write(f"class {cls['name']} {{\n")
        f.write(f"public:\n")
        f.write(f"    // TODO: Add members from {source_year} spreadsheet cells\n")
        f.write(f"    virtual ~{cls['name']}() = default;\n")
        f.write(f"}};\n\n")
    
    f.write("#endif\n")

print(f"Generated {len(classes_found)} base class stubs")
PYEOF

echo "Generated: $REPAIR_HEADER"

# Now inject into target year extracted files
TARGET_DIR="/workspace/app/lol.dance/extracted_by_year/${TARGET_YEAR}.cpp"
if [[ -d "$TARGET_DIR" ]]; then
    for cpp_file in "$TARGET_DIR"/main_*.cpp; do
        [[ -f "$cpp_file" ]] || continue
        STEM=$(basename "$cpp_file" .cpp | sed 's/^main_//')
        
        # Check if file already includes repair header
        if ! grep -q "REPAIR_BASES_${SOURCE_YEAR}_TO_${TARGET_YEAR}" "$cpp_file"; then
            # Inject after includes
            sed -i "/^#include/a #include \"../../../repairs/repair_${SOURCE_YEAR}_to_${TARGET_YEAR}_bases.hpp\"" "$cpp_file"
            echo "  Injected into: $STEM"
        fi
    done
fi

echo "Repair complete. Review $REPAIR_HEADER and injected files."
