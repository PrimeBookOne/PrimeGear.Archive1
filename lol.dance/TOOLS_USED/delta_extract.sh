#!/bin/bash
# delta_extract.sh - Extract changes between milestones
# Usage: ./delta_extract.sh --from TAG1 --to TAG2 [--output-dir PATH]

set -euo pipefail

FROM_TAG=""
TO_TAG="HEAD"
OUTPUT_DIR="/workspace/app/lol.dance/deltas"

while [[ $# -gt 0 ]]; do
    case $1 in
        --from) FROM_TAG="$2"; shift ;;
        --to) TO_TAG="$2"; shift ;;
        --output-dir) OUTPUT_DIR="$2"; shift ;;
        *) echo "Unknown: $1"; exit 1 ;;
    esac
    shift
done

[[ -z "$FROM_TAG" ]] && { echo "Usage: --from TAG"; exit 1; }

mkdir -p "$OUTPUT_DIR"

DELTA_FILE="$OUTPUT_DIR/delta_${FROM_TAG}_to_${TO_TAG}.patch"
SUMMARY_FILE="$OUTPUT_DIR/delta_${FROM_TAG}_to_${TO_TAG}_summary.md"

echo "=== Generating delta: $FROM_TAG -> $TO_TAG ==="

# Generate patch
git diff "$FROM_TAG" "$TO_TAG" -- "lol.dance/extracted_by_year/" > "$DELTA_FILE"

# Generate summary
cat > "$SUMMARY_FILE" << SUMMARY_EOF
# Delta Summary: $FROM_TAG -> $TO_TAG
**Generated**: $(date)

## Statistics
- Files changed: $(git diff --name-only "$FROM_TAG" "$TO_TAG" -- "lol.dance/extracted_by_year/" | wc -l)
- Lines added: $(git diff --numstat "$FROM_TAG" "$TO_TAG" -- "lol.dance/extracted_by_year/" | awk '{sum+=$1} END {print sum}')
- Lines removed: $(git diff --numstat "$FROM_TAG" "$TO_TAG" -- "lol.dance/extracted_by_year/" | awk '{sum+=$2} END {print sum}')

## New Functions
$(git diff "$FROM_TAG" "$TO_TAG" -- "lol.dance/extracted_by_year/*/*.cpp" | grep "^+" | grep -E "^\+\s*(void|int|bool|char|float|double)\s+\w+\s*\(" | sed 's/^+//' | sort -u | head -50 | sed 's/^/- /')

## Removed Functions
$(git diff "$FROM_TAG" "$TO_TAG" -- "lol.dance/extracted_by_year/*/*.cpp" | grep "^-" | grep -E "^\-\s*(void|int|bool|char|float|double)\s+\w+\s*\(" | sed 's/^-//' | sort -u | head -50 | sed 's/^/- /')

## Class Changes
$(git diff "$FROM_TAG" "$TO_TAG" -- "lol.dance/extracted_by_year/*/*.cpp" | grep -E "^[\+\-].*(class|struct)\s+\w+" | sort -u | sed 's/^/- /')

## Modified Files
$(git diff --name-only "$FROM_TAG" "$TO_TAG" -- "lol.dance/extracted_by_year/" | sed 's/^/- /')
SUMMARY_EOF

echo "Delta patch: $DELTA_FILE"
echo "Summary: $SUMMARY_FILE"
