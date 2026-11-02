#!/bin/bash
# compare_milestones.sh - Compare two milestone tags
# Usage: ./compare_milestones.sh TAG1 TAG2

set -euo pipefail

TAG1="${1:-v2024.09}"
TAG2="${2:-HEAD}"

echo "=== Comparing $TAG1 -> $TAG2 ==="

# Function count comparison
echo "Function count delta:"
git diff --stat "$TAG1" "$TAG2" -- "lol.dance/extracted_by_year/*/*.cpp" | tail -1

# New functions in TAG2
echo ""
echo "New functions in $TAG2:"
git diff "$TAG1" "$TAG2" -- "lol.dance/extracted_by_year/*/*.cpp" | \
    grep "^+" | grep -E "^\+\s*(void|int|bool|char|float|double)\s+\w+\s*\(" | \
    sed 's/^+//' | sort -u | head -30

# Removed functions
echo ""
echo "Removed functions (in $TAG1 only):"
git diff "$TAG1" "$TAG2" -- "lol.dance/extracted_by_year/*/*.cpp" | \
    grep "^-" | grep -E "^\-\s*(void|int|bool|char|float|double)\s+\w+\s*\(" | \
    sed 's/^-//' | sort -u | head -30

# Class changes
echo ""
echo "Class changes:"
git diff "$TAG1" "$TAG2" -- "lol.dance/extracted_by_year/*/*.cpp" | \
    grep -E "^[\+\-].*(class|struct)\s+\w+" | sort -u

# File count
echo ""
echo "File changes:"
git diff --name-only "$TAG1" "$TAG2" -- "lol.dance/extracted_by_year/" | wc -l
