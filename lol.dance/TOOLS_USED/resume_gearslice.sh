#!/bin/bash
# resume_gearslice.sh - GearSlice Analysis: Compare spreadsheets with extracted C++ code

set -euo pipefail

WORKSPACE="${WORKSPACE:-/workspace/app}"
ARCHIVE_DIR="${ARCHIVE_DIR:-${WORKSPACE}/PB1/PrimeBook.CPP/primebookonexlsm.archive}"
EXTRACTED_BASE="${WORKSPACE}/lol.dance/extracted_by_year"
OUTPUT_DIR="${OUTPUT_DIR:-${WORKSPACE}/lol.dance/gearslice_analysis}"

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

log() { echo -e "${GREEN}[INFO]${NC} $*"; }
warn() { echo -e "${YELLOW}[WARN]${NC} $*"; }
err() { echo -e "${RED}[ERROR]${NC} $*"; }

usage() {
    cat << 'USAGE'
resume_gearslice.sh - GearSlice Analysis Engine

USAGE: ./resume_gearslice.sh [OPTIONS]

OPTIONS:
    --year YYYY           Analyze specific year (2022, 2023, 2024, 2025)
    --file STEM           Analyze specific file stem
    --analyze             Run code comparison analysis
    --catalog             Catalog directions, TODOs, milestones
    --evolution           Compare evolution/devolution across versions
    --slice               Slice spreadsheets into code bundles
    --output-dir PATH     Output directory
    --help                Show this help
USAGE
}

mkdir -p "$OUTPUT_DIR"

YEAR=""
FILE_STEM=""
DO_ANALYZE=false
DO_CATALOG=false
DO_EVOLUTION=false
DO_SLICE=false

while [[ $# -gt 0 ]]; do
    case $1 in
        --year) YEAR="$2"; shift ;;
        --file) FILE_STEM="$2"; shift ;;
        --analyze) DO_ANALYZE=true ;;
        --catalog) DO_CATALOG=true ;;
        --evolution) DO_EVOLUTION=true ;;
        --slice) DO_SLICE=true ;;
        --output-dir) OUTPUT_DIR="$2"; shift ;;
        --help) usage; exit 0 ;;
        *) err "Unknown option: $1"; usage; exit 1 ;;
    esac
    shift
done

if [[ -z "$YEAR" && -z "$FILE_STEM" ]]; then
    YEARS=(2022 2023 2024 2025)
else
    YEARS=("$YEAR")
fi

convert_xlsm_to_xlsx() {
    local xlsm_file="$1"
    local target_xlsx="$2"
    local stem=$(basename "$xlsm_file" .xlsm)
    local default_xlsx="/tmp/${stem}.xlsx"
    
    pkill -f libreoffice 2>/dev/null || true
    pkill -f soffice 2>/dev/null || true
    sleep 1
    
    rm -f "$default_xlsx" "$target_xlsx"
    
    libreoffice --headless --calc \
        --convert-to xlsx:"Calc MS Excel 2007 XML" \
        --outdir /tmp \
        "$xlsm_file" 2>&1 | grep -v "^$"
    
    local count=0
    while [ ! -f "$default_xlsx" ] && [ $count -lt 15 ]; do
        sleep 1
        count=$((count + 1))
    done
    
    if [ ! -f "$default_xlsx" ]; then
        err "Conversion failed: $default_xlsx not created"
        return 1
    fi
    
    sleep 3
    
    if [ "$default_xlsx" != "$target_xlsx" ]; then
        mv "$default_xlsx" "$target_xlsx"
    fi
    return 0
}

extract_spreadsheet_cells() {
    local xlsx_file="$1"
    local year="$2"
    local output_json="$3"
    
    python3 -c "
import openpyxl, json, sys, time

xlsx_path = '''$xlsx_file'''
year = '''$year'''
output_path = '''$output_json'''

CELL_REFS = {
    '2022': ['C21','C22','C23','C24','C25','C26','C27','C28','A82','A83','A84','A85','C30','C31','C32'],
    '2023': [f'A{i}' for i in range(37, 171)],
    '2024': ['A37','A38','A39','A40','A41'] + [f'A{i}' for i in range(175, 257)] + [f'A{i}' for i in range(42, 95)],
    '2025': ['A37','A38','A39','A40','A41','A44','A46','A45'] + [f'A{i}' for i in range(175, 257) if i not in [178, 188, 191, 192, 193, 201, 206, 208, 210, 216, 218, 222, 227, 229, 231, 232, 235, 239, 241, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255]] + ['A42','A43'] + [f'A{i}' for i in range(300, 325) if i not in [313, 315, 316, 317, 320, 321, 322, 323]] + [f'A{i}' for i in range(47, 170) if i not in [53, 54, 61, 67, 68, 69, 70, 71, 72, 73, 75, 76, 77, 78, 79, 80, 85, 86, 87, 88, 93, 95, 97, 101, 105, 106, 107, 108, 109, 110, 111, 112, 115, 117, 118, 119, 120, 121, 122, 123, 127, 128, 129, 130, 141, 144, 159, 161, 163, 164, 166, 169]]
}

wb = None
for attempt in range(10):
    try:
        wb = openpyxl.load_workbook(xlsx_path, data_only=True)
        break
    except Exception as e:
        if attempt == 9:
            print('Error loading workbook:', e, file=sys.stderr)
            sys.exit(1)
        time.sleep(0.5)

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
    build_sheet = wb[wb.sheetnames[0]]

cells = CELL_REFS.get(year, [])
cell_data = {}
for cell_ref in cells:
    val = build_sheet[cell_ref].value
    cell_data[cell_ref] = str(val) if val is not None else ''

with open(output_path, 'w') as f:
    json.dump({'year': year, 'sheet_name': build_sheet.title, 'total_cells': len(cells), 'cells': cell_data}, f, indent=2)

non_empty = sum(1 for v in cell_data.values() if v)
print(f'  Extracted {non_empty}/{len(cells)} non-empty cells')
"
}

analyze_code_bundles() {
    local stem="$1"
    local year="$2"
    local cells_json="$3"
    local cpp_file="$4"
    local output_json="$5"
    local output_md="$6"
    
    python3 -c "
import json, re, sys

stem = '''$stem'''
year = '''$year'''
cells_json_path = '''$cells_json'''
cpp_path = '''$cpp_file'''
output_json_path = '''$output_json'''
output_md_path = '''$output_md'''

with open(cells_json_path) as f:
    cells_data = json.load(f)
with open(cpp_path) as f:
    cpp_code = f.read()

cell_values = list(cells_data['cells'].values())
non_empty_cells = [v for v in cell_values if v.strip()]
cpp_lines = cpp_code.strip().split('\n')

incorporated = []
unused_cells = []
bundles = []

for cell_ref, cell_val in cells_data['cells'].items():
    if not cell_val.strip():
        continue
    cell_snippet = cell_val.strip()
    if cell_snippet in cpp_code:
        incorporated.append({'cell': cell_ref, 'snippet': cell_snippet[:200], 'full_length': len(cell_snippet), 'status': 'incorporated'})
    else:
        words = cell_snippet.split()
        if len(words) > 3:
            partial_match = False
            for i in range(len(words) - 2):
                phrase = ' '.join(words[i:i+3])
                if phrase in cpp_code:
                    partial_match = True
                    break
            if partial_match:
                incorporated.append({'cell': cell_ref, 'snippet': cell_snippet[:200], 'full_length': len(cell_snippet), 'status': 'partially_incorporated'})
            else:
                unused_cells.append({'cell': cell_ref, 'snippet': cell_snippet[:200], 'full_length': len(cell_snippet), 'status': 'unused'})
        else:
            unused_cells.append({'cell': cell_ref, 'snippet': cell_snippet[:200], 'full_length': len(cell_snippet), 'status': 'unused'})

current_bundle = []
for item in incorporated + unused_cells:
    if not current_bundle:
        current_bundle.append(item)
    else:
        last_cell = current_bundle[-1]['cell']
        curr_cell = item['cell']
        try:
            last_row = int(re.search(r'(\d+)$', last_cell).group(1))
            curr_row = int(re.search(r'(\d+)$', curr_cell).group(1))
            if curr_row - last_row <= 2:
                current_bundle.append(item)
            else:
                if current_bundle:
                    bundles.append(current_bundle)
                current_bundle = [item]
        except:
            current_bundle.append(item)
if current_bundle:
    bundles.append(current_bundle)

structure = {'includes': [], 'defines': [], 'functions': [], 'classes': [], 'globals': [], 'comments': []}
for line in cpp_lines:
    stripped = line.strip()
    if stripped.startswith('#include'):
        structure['includes'].append(stripped)
    elif stripped.startswith('#define') or stripped.startswith('#undef'):
        structure['defines'].append(stripped)
    elif re.match(r'^\w+\s+\w+\s*\([^)]*\)\s*{', stripped):
        structure['functions'].append(stripped)
    elif stripped.startswith('class ') or stripped.startswith('struct '):
        structure['classes'].append(stripped)
    elif stripped and not stripped.startswith('//') and not stripped.startswith('/*') and ('=' in stripped or stripped.endswith(';')):
        if not any(kw in stripped for kw in ['if', 'for', 'while', 'switch', 'return', 'break', 'continue']):
            structure['globals'].append(stripped)
    elif stripped.startswith('//') or stripped.startswith('/*'):
        structure['comments'].append(stripped)

with open(output_json_path, 'w') as f:
    json.dump({'stem': stem, 'year': year, 'total_cells': len(cell_values), 'non_empty_cells': len(non_empty_cells), 'cpp_lines': len(cpp_lines), 'cpp_size': len(cpp_code), 'incorporated_count': len(incorporated), 'unused_count': len(unused_cells), 'incorporated': incorporated, 'unused': unused_cells, 'bundles': bundles, 'structure': structure}, f, indent=2)

with open(output_md_path, 'w') as f:
    f.write(f'# GearSlice Analysis: {stem} ({year})\n\n')
    f.write(f'**Source:** Spreadsheet cells -> **Target:** Extracted C++\n\n')
    f.write(f'## Summary\n')
    f.write(f'- Spreadsheet cells (tracked): {len(cell_values)}\n')
    f.write(f'- Non-empty cells: {len(non_empty_cells)}\n')
    f.write(f'- Extracted C++ lines: {len(cpp_lines)}\n')
    f.write(f'- Incorporated cells: {len(incorporated)}\n')
    f.write(f'- Unused cells: {len(unused_cells)}\n')
    f.write(f'- Code bundles identified: {len(bundles)}\n\n')
    f.write(f'## Code Bundles\n\n')
    for i, bundle in enumerate(bundles):
        status = bundle[0]['status'] if bundle else 'unknown'
        f.write(f'### Bundle {i+1} ({status})\n')
        for item in bundle:
            f.write(f'- **Cell {item[\"cell\"]}**: {item[\"snippet\"][:100]}...\n')
        f.write(f'\n')
    f.write(f'## Structure Map\n\n')
    for key, items in structure.items():
        if items:
            f.write(f'### {key.capitalize()} ({len(items)})\n')
            for item in items[:10]:
                f.write(f'- {item[:120]}\n')
            if len(items) > 10:
                f.write(f'- ... and {len(items) - 10} more\n')
            f.write(f'\n')

print(f'  Analysis complete: {len(incorporated)} incorporated, {len(unused_cells)} unused, {len(bundles)} bundles')
"
}

catalog_todos_milestones() {
    local stem="$1"
    local year="$2"
    local cpp_file="$3"
    local cells_json="$4"
    local output_json="$5"
    local output_md="$6"
    
    python3 -c "
import json, re, sys

stem = '''$stem'''
year = '''$year'''
cpp_path = '''$cpp_file'''
cells_json_path = '''$cells_json'''
output_json_path = '''$output_json'''
output_md_path = '''$output_md'''

with open(cpp_path) as f:
    cpp_code = f.read()
with open(cells_json_path) as f:
    cells_data = json.load(f)

cell_values = ' '.join(v for v in cells_data['cells'].values() if v.strip())
all_text = cpp_code + '\n' + cell_values

todo_pattern = re.compile(r'(?i)(TODO|FIXME|HACK|NOTE|XXX|BUG|OPTIMIZE|REFACTOR|IMPLEMENT|ADD|REMOVE|UPDATE|CHANGE|CREATE|DELETE)\s*[:]\s*(.+?)(?:\n|$)')
milestone_pattern = re.compile(r'(?i)(MILESTONE|VERSION|RELEASE|BUILD|DEPLOY|LAUNCH|COMPLETE|DONE|FINISHED)\s*[:]\s*(.+?)(?:\n|$)')
direction_pattern = re.compile(r'(?i)(DIRECTION|GOAL|TARGET|OBJECTIVE|AIM|PURPOSE|STRATEGY|PLAN|ROADMAP|VISION)\s*[:]\s*(.+?)(?:\n|$)')
comment_pattern = re.compile(r'//\s*(.+?)$|/\*\s*(.+?)\s*\*/', re.MULTILINE | re.DOTALL)

todos = [{'type': 'TODO', 'keyword': m.group(1), 'content': m.group(2).strip()} for m in todo_pattern.finditer(all_text)]
milestones = [{'type': 'MILESTONE', 'keyword': m.group(1), 'content': m.group(2).strip()} for m in milestone_pattern.finditer(all_text)]
directions = [{'type': 'DIRECTION', 'keyword': m.group(1), 'content': m.group(2).strip()} for m in direction_pattern.finditer(all_text)]
comments = []
for m in comment_pattern.finditer(all_text):
    content = m.group(1) or m.group(2)
    if content and content.strip():
        comments.append({'type': 'COMMENT', 'content': content.strip()[:200]})

func_pattern = re.compile(r'^(\w+(?:\s+\w+)*)\s+(\w+)\s*\([^)]*\)\s*{', re.MULTILINE)
functions = [{'return_type': m.group(1).strip(), 'name': m.group(2).strip()} for m in func_pattern.finditer(cpp_code)]

class_pattern = re.compile(r'^(class|struct)\s+(\w+)', re.MULTILINE)
classes = [{'type': m.group(1), 'name': m.group(2)} for m in class_pattern.finditer(cpp_code)]

with open(output_json_path, 'w') as f:
    json.dump({'stem': stem, 'year': year, 'todos': todos, 'milestones': milestones, 'directions': directions, 'comments': comments, 'functions': functions, 'classes': classes, 'total_todos': len(todos), 'total_milestones': len(milestones), 'total_directions': len(directions)}, f, indent=2)

with open(output_md_path, 'w') as f:
    f.write(f'# Catalog: {stem} ({year})\n\n')
    if todos:
        f.write(f'## TODOs ({len(todos)})\n\n')
        for todo in todos:
            f.write(f'- **{todo[\"keyword\"]}**: {todo[\"content\"]}\n')
        f.write(f'\n')
    if milestones:
        f.write(f'## Milestones ({len(milestones)})\n\n')
        for ms in milestones:
            f.write(f'- **{ms[\"keyword\"]}**: {ms[\"content\"]}\n')
        f.write(f'\n')
    if directions:
        f.write(f'## Directions ({len(directions)})\n\n')
        for d in directions:
            f.write(f'- **{d[\"keyword\"]}**: {d[\"content\"]}\n')
        f.write(f'\n')
    if functions:
        f.write(f'## Functions ({len(functions)})\n\n')
        for func in functions[:20]:
            f.write(f'- \`{func[\"return_type\"]} {func[\"name\"]}()\`\n')
        if len(functions) > 20:
            f.write(f'- ... and {len(functions) - 20} more\n')
        f.write(f'\n')
    if classes:
        f.write(f'## Classes/Structs ({len(classes)})\n\n')
        for cls in classes:
            f.write(f'- **{cls[\"type\"]} {cls[\"name\"]}**\n')
        f.write(f'\n')

print(f'  Cataloged: {len(todos)} TODOs, {len(milestones)} milestones, {len(directions)} directions, {len(functions)} functions, {len(classes)} classes')
"
}

analyze_evolution() {
    local year="$1"
    local year_dir="${OUTPUT_DIR}/${year}"
    
    python3 -c "
import json, os, sys

year = '''$year'''
year_dir = '''$year_dir'''

files = [f for f in os.listdir(year_dir) if os.path.isdir(os.path.join(year_dir, f))]

if not files:
    print(f'  No analysis files for {year}')
    sys.exit(0)

all_todos = []
all_milestones = []
all_directions = []
all_functions = []
all_classes = []
total_incorporated = 0
total_unused = 0

for stem in files:
    bundle_path = os.path.join(year_dir, stem, 'code_bundles.json')
    catalog_path = os.path.join(year_dir, stem, 'todo_catalog.json')
    if os.path.exists(bundle_path):
        with open(bundle_path) as f:
            data = json.load(f)
            total_incorporated += data.get('incorporated_count', 0)
            total_unused += data.get('unused_count', 0)
    if os.path.exists(catalog_path):
        with open(catalog_path) as f:
            data = json.load(f)
            all_todos.extend(data.get('todos', []))
            all_milestones.extend(data.get('milestones', []))
            all_directions.extend(data.get('directions', []))
            all_functions.extend(data.get('functions', []))
            all_classes.extend(data.get('classes', []))

seen_funcs = set()
unique_funcs = []
for f in all_functions:
    key = f['return_type'] + ' ' + f['name']
    if key not in seen_funcs:
        seen_funcs.add(key)
        unique_funcs.append(f)

seen_classes = set()
unique_classes = []
for c in all_classes:
    key = c['type'] + ' ' + c['name']
    if key not in seen_classes:
        seen_classes.add(key)
        unique_classes.append(c)

report_path = os.path.join(year_dir, 'evolution_report.md')
with open(report_path, 'w') as f:
    f.write(f'# Evolution Report: {year}\n\n')
    f.write(f'## Files Analyzed: {len(files)}\n\n')
    f.write(f'## Code Incorporation\n')
    f.write(f'- Incorporated cells: {total_incorporated}\n')
    f.write(f'- Unused cells: {total_unused}\n')
    if (total_incorporated + total_unused) > 0:
        rate = total_incorporated / (total_incorporated + total_unused) * 100
        f.write(f'- Incorporation rate: {rate:.1f}%\n')
    f.write(f'\n')
    f.write(f'## TODOs ({len(all_todos)})\n\n')
    for todo in all_todos[:30]:
        f.write(f'- **{todo[\"keyword\"]}**: {todo[\"content\"]}\n')
    if len(all_todos) > 30:
        f.write(f'- ... and {len(all_todos) - 30} more\n')
    f.write(f'\n')
    f.write(f'## Milestones ({len(all_milestones)})\n\n')
    for ms in all_milestones[:20]:
        f.write(f'- **{ms[\"keyword\"]}**: {ms[\"content\"]}\n')
    f.write(f'\n')
    f.write(f'## Directions ({len(all_directions)})\n\n')
    for d in all_directions[:20]:
        f.write(f'- **{d[\"keyword\"]}**: {d[\"content\"]}\n')
    f.write(f'\n')
    f.write(f'## Unique Functions ({len(unique_funcs)})\n\n')
    for func in unique_funcs[:30]:
        f.write(f'- \`{func[\"return_type\"]} {func[\"name\"]}()\`\n')
    if len(unique_funcs) > 30:
        f.write(f'- ... and {len(unique_funcs) - 30} more\n')
    f.write(f'\n')
    f.write(f'## Unique Classes/Structs ({len(unique_classes)})\n\n')
    for cls in unique_classes[:20]:
        f.write(f'- **{cls[\"type\"]} {cls[\"name\"]}**\n')
    f.write(f'\n')

summary_path = os.path.join(year_dir, 'catalog_summary.json')
with open(summary_path, 'w') as f:
    json.dump({'year': year, 'files_analyzed': len(files), 'incorporated_cells': total_incorporated, 'unused_cells': total_unused, 'todos': len(all_todos), 'milestones': len(all_milestones), 'directions': len(all_directions), 'unique_functions': len(unique_funcs), 'unique_classes': len(unique_classes)}, f, indent=2)

print(f'  Evolution report for {year}: {len(files)} files, {total_incorporated} incorporated, {len(unique_funcs)} unique functions')
"
}

cross_year_evolution() {
    python3 -c "
import json, os, sys

output_dir = '''$OUTPUT_DIR'''
output_md = '''$OUTPUT_DIR/cross_year_evolution.md'''

years = ['2022', '2023', '2024', '2025']
year_data = {}
for year in years:
    summary_path = os.path.join(output_dir, year, 'catalog_summary.json')
    if os.path.exists(summary_path):
        with open(summary_path) as f:
            year_data[year] = json.load(f)

with open(output_md, 'w') as f:
    f.write(f'# Cross-Year Evolution/Devolution Crests\n\n')
    f.write(f'## Summary Table\n\n')
    f.write(f'| Year | Files | Incorporated | Unused | Rate | TODOs | Milestones | Directions | Functions | Classes |\n')
    f.write(f'|------|-------|--------------|--------|------|-------|------------|------------|-----------|--------|\n')
    for year in years:
        if year in year_data:
            d = year_data[year]
            total = d.get('incorporated_cells', 0) + d.get('unused_cells', 0)
            rate = d.get('incorporated_cells', 0) / total * 100 if total > 0 else 0
            f.write(f'| {year} | {d.get(\"files_analyzed\", 0)} | {d.get(\"incorporated_cells\", 0)} | {d.get(\"unused_cells\", 0)} | {rate:.1f}% | {d.get(\"todos\", 0)} | {d.get(\"milestones\", 0)} | {d.get(\"directions\", 0)} | {d.get(\"unique_functions\", 0)} | {d.get(\"unique_classes\", 0)} |\n')
        else:
            f.write(f'| {year} | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A |\n')
    
    f.write(f'\n## Evolution Analysis\n\n')
    f.write(f'### Code Growth/Contraction\n\n')
    for year in years:
        if year in year_data:
            d = year_data[year]
            f.write(f'**{year}**: {d.get(\"files_analyzed\", 0)} files, {d.get(\"unique_functions\", 0)} unique functions, {d.get(\"unique_classes\", 0)} classes\n')
    
    f.write(f'\n### Crest Points (Major Milestones)\n\n')
    for year in years:
        milestone_path = os.path.join(output_dir, year, 'evolution_report.md')
        if os.path.exists(milestone_path):
            f.write(f'#### {year} Crests\n')
            with open(milestone_path) as mf:
                content = mf.read()
                if '## Milestones' in content:
                    ms_section = content.split('## Milestones')[1].split('##')[0]
                    f.write(f'{ms_section[:1000]}\n')
                else:
                    f.write(f'  (No milestones cataloged)\n')
            f.write(f'\n')
    
    f.write(f'### Devolution Indicators\n\n')
    f.write(f'- Files with high unused cell counts may indicate abandoned experiments\n')
    f.write(f'- Decreasing incorporation rates suggest code divergence from spreadsheets\n')
    f.write(f'- TODO accumulation without resolution indicates stalled development\n')
    f.write(f'\n')

print(f'  Cross-year evolution report written to {output_md}')
"
}

for year in "${YEARS[@]}"; do
    archive_year_dir="${ARCHIVE_DIR}/${year}"
    extracted_year_dir="${EXTRACTED_BASE}/${year}.cpp"
    analysis_year_dir="${OUTPUT_DIR}/${year}"
    
    if [[ ! -d "$archive_year_dir" ]]; then
        warn "Archive directory not found: $archive_year_dir"
        continue
    fi
    
    mkdir -p "$analysis_year_dir"
    
    if [[ -n "$FILE_STEM" ]]; then
        xlsm_files=("${archive_year_dir}/${FILE_STEM}.xlsm")
    else
        if [[ "$year" == "2022" ]]; then
            mapfile -t xlsm_files < <(find "$archive_year_dir" -maxdepth 1 -name "*.xlsm" | sort)
        elif [[ "$year" == "2023" ]]; then
            mapfile -t xlsm_files < <(find "$archive_year_dir" -maxdepth 1 -name "*.xlsm" | sort)
        elif [[ "$year" == "2024" ]]; then
            mapfile -t xlsm_files < <(find "$archive_year_dir" -maxdepth 1 -name "primeOne_2024_*.xlsm" | sort)
        elif [[ "$year" == "2025" ]]; then
            mapfile -t xlsm_files < <(find "$archive_year_dir" -maxdepth 1 -name "*.xlsm" | sort)
        fi
    fi
    
    log "Processing year $year: ${#xlsm_files[@]} files"
    
    for xlsm_file in "${xlsm_files[@]}"; do
        [[ ! -f "$xlsm_file" ]] && continue
        
        stem=$(basename "$xlsm_file" .xlsm)
        cpp_file="${extracted_year_dir}/main_${stem}.cpp"
        analysis_file_dir="${analysis_year_dir}/${stem}"
        
        if [[ ! -f "$cpp_file" ]]; then
            warn "No extracted C++ for $stem, skipping"
            continue
        fi
        
        mkdir -p "$analysis_file_dir"
        
        log "  Analyzing $stem..."
        
        xlsx_file="/tmp/${stem}.xlsx"
        cells_json="${analysis_file_dir}/spreadsheet_cells.json"
        
        if [[ "$DO_SLICE" == true || "$DO_ANALYZE" == true || "$DO_CATALOG" == true ]]; then
            if [[ ! -f "$xlsx_file" ]]; then
                convert_xlsm_to_xlsx "$xlsm_file" "$xlsx_file"
            fi
            extract_spreadsheet_cells "$xlsx_file" "$year" "$cells_json"
        fi
        
        if [[ "$DO_ANALYZE" == true || "$DO_SLICE" == true ]]; then
            bundles_json="${analysis_file_dir}/code_bundles.json"
            diff_md="${analysis_file_dir}/diff_report.md"
            analyze_code_bundles "$stem" "$year" "$cells_json" "$cpp_file" "$bundles_json" "$diff_md"
        fi
        
        if [[ "$DO_CATALOG" == true ]]; then
            catalog_json="${analysis_file_dir}/todo_catalog.json"
            catalog_md="${analysis_file_dir}/catalog_report.md"
            catalog_todos_milestones "$stem" "$year" "$cpp_file" "$cells_json" "$catalog_json" "$catalog_md"
        fi
    done
    
    if [[ "$DO_EVOLUTION" == true || "$DO_CATALOG" == true || "$DO_ANALYZE" == true ]]; then
        analyze_evolution "$year"
    fi
done

if [[ "$DO_EVOLUTION" == true ]]; then
    log "Generating cross-year evolution report..."
    cross_year_evolution
fi

log "GearSlice analysis complete! Output: $OUTPUT_DIR"
