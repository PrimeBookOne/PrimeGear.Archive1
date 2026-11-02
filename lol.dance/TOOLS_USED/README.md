# PrimeOne CPP Extraction Environment

This folder contains the complete environment rebuild script and extracted outputs for the PrimeOne Excel macro project.

## Directory Structure

```
lol.dance/
├── primeonecpp_resume.sh      # Main resume/rebuild script
├── extracted_by_year/         # Extracted main.cpp files by year
│   ├── 2022.cpp/
│   ├── 2023.cpp/
│   ├── 2024.cpp/
│   └── 2025.cpp/
├── reference_output_2025/     # Reference output from GUI_primeOne_2025_6_29.xlsm
│   ├── PrimeOne/main.cpp      # 257KB - Main C++ output
│   └── JS.bench/              # JavaScript/CSS/HTML output files
├── extract_macros.py          # Original extraction script
├── extract_yearly_main.py     # Yearly extraction v1
├── extract_yearly_main_v2.py  # Yearly extraction v2
├── process_all_years.py       # File analysis script
└── batch_convert.sh           # Batch conversion script
```

## Quick Start

```bash
# Full environment setup + extraction
./primeonecpp_resume.sh --full

# Or step by step:
./primeonecpp_resume.sh --install   # Install dependencies only
./primeonecpp_resume.sh --extract   # Run extraction (deps required)
./primeonecpp_resume.sh --test      # Test single file
```

## What This Does

1. **Converts** `.xlsm` files to `.xlsx` using LibreOffice headless (evaluates all formulas)
2. **Extracts** computed cell values from the BUILD sheet using openpyxl
3. **Replicates** the VBA `Create_CPP_File` macro logic in Python
4. **Generates** `main.cpp` files for each year's key snapshots

## Year-Specific Cell References

Each year has a different macro pattern:

| Year | Cell Range | Notes |
|------|------------|-------|
| 2022 | C21-C32, A82-A85 | GyroCore files, outputs to `.txt` |
| 2023 | A37-A170 | Sequential range, primeOne files |
| 2024 | A37-A256, A42-A94 | Extended with primetileclass + conduitClass |
| 2025 | Custom list (80+ cells) | Most complex, includes primeTileClass + conduitClass |

## Archive Source

Files are read from: `/workspace/app/PB1/PrimeBook.CPP/primebookonexlsm.archive/`

- 2022: 19 GyroCore files
- 2023: 450 primeOne/gyroCore files  
- 2024: 384 primeOne files
- 2025: 665 primeOne files

## Key Files Selected Per Year

One file per month (last revision) + first + last = ~8-14 key files per year.

## Dependencies

- `libreoffice` (headless conversion)
- `python3` + `openpyxl` + `oletools` + `olefile`
- `python3-uno` (LibreOffice Python bridge)

## Notes

- The 2022 GyroCore files use a different output path (`PrimeGyroGear/main.cpp`) and fewer cells
- The 2023-2025 primeOne files use `PrimeOne/main.cpp` with expanding cell ranges
- JavaScript/CSS/HTML outputs (JS.bench) are only in some years
- SERVICE and GUI variant files are excluded (different macro structure)

## Testing

The reference output in `reference_output_2025/` was generated from `GUI_primeOne_2025_6_29.xlsm` and matches the VBA macro output exactly.

