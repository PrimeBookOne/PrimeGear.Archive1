#!/bin/bash
# tag_milestone.sh - Tag a milestone in git
# Usage: ./tag_milestone.sh --name TAG_NAME [--message "MSG"] [--year YYYY]

set -euo pipefail

TAG_NAME=""
MESSAGE=""
YEAR=""

while [[ $# -gt 0 ]]; do
    case $1 in
        --name) TAG_NAME="$2"; shift ;;
        --message) MESSAGE="$2"; shift ;;
        --year) YEAR="$2"; shift ;;
        *) echo "Unknown: $1"; exit 1 ;;
    esac
    shift
done

[[ -z "$TAG_NAME" ]] && { echo "Usage: --name TAG_NAME"; exit 1; }

# Build message
if [[ -z "$MESSAGE" ]]; then
    if [[ -n "$YEAR" ]]; then
        MESSAGE="Milestone $TAG_NAME for year $YEAR - $(date)"
    else
        MESSAGE="Milestone $TAG_NAME - $(date)"
    fi
fi

# Create annotated tag
git tag -a "$TAG_NAME" -m "$MESSAGE"

# Push tag
git push origin "$TAG_NAME"

echo "Tagged: $TAG_NAME"
echo "Message: $MESSAGE"

# Also update gearslice catalog with milestone
if [[ -n "$YEAR" ]]; then
    CATALOG="/workspace/app/lol.dance/gearslice_analysis/$YEAR/catalog_summary.json"
    if [[ -f "$CATALOG" ]]; then
        python3 -c "
import json
with open('$CATALOG') as f: d=json.load(f)
d['milestones'].append('$TAG_NAME')
with open('$CATALOG', 'w') as f: json.dump(d, f, indent=2)
print('Updated catalog summary')
"
    fi
fi
