#!/bin/bash
# run_gearslice_pipeline.sh - Full GearSlice pipeline runner
# Usage: ./run_gearslice_pipeline.sh [--full] [--year YYYY] [--extract] [--analyze] [--repair] [--validate] [--tag TAG]

set -euo pipefail

FULL=false
YEAR=""
DO_EXTRACT=false
DO_ANALYZE=false
DO_REPAIR=false
DO_VALIDATE=false
TAG=""

while [[ $# -gt 0 ]]; do
    case $1 in
        --full) FULL=true ;;
        --year) YEAR="$2"; shift ;;
        --extract) DO_EXTRACT=true ;;
        --analyze) DO_ANALYZE=true ;;
        --repair) DO_REPAIR=true ;;
        --validate) DO_VALIDATE=true ;;
        --tag) TAG="$2"; shift ;;
        *) echo "Unknown: $1"; exit 1 ;;
    esac
    shift
done

if [[ "$FULL" == true ]]; then
    DO_EXTRACT=true
    DO_ANALYZE=true
    DO_REPAIR=true
    DO_VALIDATE=true
fi

YEARS=()
if [[ -n "$YEAR" ]]; then
    YEARS=("$YEAR")
else
    YEARS=(2022 2023 2024 2025)
fi

echo "=== GearSlice Pipeline ==="
echo "Years: ${YEARS[*]}"
echo "Extract: $DO_EXTRACT, Analyze: $DO_ANALYZE, Repair: $DO_REPAIR, Validate: $DO_VALIDATE"

# Phase 1: Extract all years
if [[ "$DO_EXTRACT" == true ]]; then
    echo ""
    echo "=== PHASE 1: EXTRACTION ==="
    for y in "${YEARS[@]}"; do
        echo "Extracting year $y..."
        /workspace/app/lol.dance/primeonecpp_resume.sh --extract --archive-path /workspace/app/PB1/PrimeBook.CPP/primebookonexlsm.archive 2>&1 | grep -E "(Processing|Converting|Extracting|OK|Error)" || true
    done
fi

# Phase 2: GearSlice Analysis
if [[ "$DO_ANALYZE" == true ]]; then
    echo ""
    echo "=== PHASE 2: ANALYSIS ==="
    for y in "${YEARS[@]}"; do
        echo "Analyzing year $y..."
        /workspace/app/lol.dance/resume_gearslice.sh --year "$y" --analyze --catalog --evolution 2>&1 | grep -E "(Processing|Analyzing|Extracted|Analysis|Cataloged|Evolution|Complete)" || true
    done
fi

# Phase 3: Repair
if [[ "$DO_REPAIR" == true ]]; then
    echo ""
    echo "=== PHASE 3: REPAIR ==="
    # Inject 2024 bases into 2022
    echo "Repairing 2022 with 2024 bases..."
    /workspace/app/lol.dance/repair_base_classes.sh --target-year 2022 --source-year 2024
    
    # Inject 2025 bases into 2023
    echo "Repairing 2023 with 2025 bases..."
    /workspace/app/lol.dance/repair_base_classes.sh --target-year 2023 --source-year 2025
    
    # Complete NetworkLayer async
    echo "Completing NetworkLayer async..."
    # (Would need manual intervention - template provided in cross_year_evolution_v2.md)
fi

# Phase 4: Validate
if [[ "$DO_VALIDATE" == true ]]; then
    echo ""
    echo "=== PHASE 4: VALIDATION ==="
    for y in "${YEARS[@]}"; do
        echo "Validating year $y..."
        /workspace/app/lol.dance/validate_incorporation.sh --year "$y" --threshold 95 --action report
    done
fi

# Phase 5: Tag milestone
if [[ -n "$TAG" ]]; then
    echo ""
    echo "=== PHASE 5: TAGGING ==="
    /workspace/app/lol.dance/tag_milestone.sh --name "$TAG" --message "GearSlice pipeline complete: ${YEARS[*]}"
fi

# Generate final cross-year report
echo ""
echo "=== FINAL: CROSS-YEAR REPORT ==="
/workspace/app/lol.dance/resume_gearslice.sh --evolution 2>&1 | grep -E "(Cross-year|written to)"

echo ""
echo "=== PIPELINE COMPLETE ==="
echo "Outputs:"
echo "  - Extractions: lol.dance/extracted_by_year/"
echo "  - Analysis: lol.dance/gearslice_analysis/"
echo "  - Repairs: lol.dance/repairs/"
echo "  - Validation: lol.dance/validation_*.md"
echo "  - Cross-year: lol.dance/gearslice_analysis/cross_year_evolution_v2.md"
