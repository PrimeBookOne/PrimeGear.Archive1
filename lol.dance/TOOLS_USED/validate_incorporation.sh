#!/bin/bash
# validate_incorporation.sh - Validate incorporation rates
# Usage: ./validate_incorporation.sh --year YYYY [--threshold 95] [--action report|fix]

set -euo pipefail

YEAR=""
THRESHOLD=95
ACTION="report"

while [[ $# -gt 0 ]]; do
    case $1 in
        --year) YEAR="$2"; shift ;;
        --threshold) THRESHOLD="$2"; shift ;;
        --action) ACTION="$2"; shift ;;
        *) echo "Unknown: $1"; exit 1 ;;
    esac
    shift
done

[[ -z "$YEAR" ]] && { echo "Usage: --year YYYY"; exit 1; }

ANALYSIS_DIR="/workspace/app/lol.dance/gearslice_analysis/$YEAR"
REPORT_FILE="/workspace/app/lol.dance/validation_${YEAR}.md"

echo "=== Validating incorporation for $YEAR (threshold: ${THRESHOLD}%) ==="

python3 << PYEOF
import json
import os
import sys

year = "$YEAR"
analysis_dir = "$ANALYSIS_DIR"
threshold = $THRESHOLD
action = "$ACTION"
report_file = "$REPORT_FILE"

files = [f for f in os.listdir(analysis_dir) if os.path.isdir(os.path.join(analysis_dir, f)) and f not in ['evolution_report.md', 'catalog_summary.json']]

results = []
for stem in files:
    bundle_path = os.path.join(analysis_dir, stem, "code_bundles.json")
    if os.path.exists(bundle_path):
        with open(bundle_path) as f:
            data = json.load(f)
        incorp = data.get("incorporated_count", 0)
        unused = data.get("unused_count", 0)
        total = incorp + unused
        rate = (incorp / total * 100) if total > 0 else 100
        results.append({
            "stem": stem,
            "incorporated": incorp,
            "unused": unused,
            "rate": rate,
            "pass": rate >= threshold
        })

passed = sum(1 for r in results if r["pass"])
failed = len(results) - passed

with open(report_file, "w") as f:
    f.write(f"# Incorporation Validation: {year}\n\n")
    f.write(f"**Threshold**: {threshold}%\n")
    f.write(f"**Files**: {len(results)}\n")
    f.write(f"**Passed**: {passed}\n")
    f.write(f"**Failed**: {failed}\n\n")
    
    f.write(f"## Results\n\n")
    f.write(f"| File | Incorporated | Unused | Rate | Status |\n")
    f.write(f"|------|-------------|--------|------|--------|\n")
    
    for r in sorted(results, key=lambda x: x["rate"]):
        status = "✅ PASS" if r["pass"] else "❌ FAIL"
        f.write(f"| {r['stem']} | {r['incorporated']} | {r['unused']} | {r['rate']:.1f}% | {status} |\n")
    
    if failed > 0 and action == "fix":
        f.write(f"\n## Failed Files - Repair Actions\n\n")
        for r in results:
            if not r["pass"]:
                f.write(f"### {r['stem']}\n")
                f.write(f"- Rate: {r['rate']:.1f}% (threshold: {threshold}%)\n")
                f.write(f"- Unused cells: {r['unused']}\n")
                f.write(f"- Action: Review spreadsheet cells for unused code\n\n")

print(f"Validation complete: {passed}/{len(results)} passed")
if failed > 0:
    print(f"FAILED files: {failed}")
    for r in results:
        if not r["pass"]:
            print(f"  {r['stem']}: {r['rate']:.1f}%")
    sys.exit(1)
PYEOF

echo "Report: $REPORT_FILE"
