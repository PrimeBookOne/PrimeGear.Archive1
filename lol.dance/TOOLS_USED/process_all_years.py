import os
import subprocess
import openpyxl
import re
from pathlib import Path

archive_dir = Path('/workspace/app/PB1/PrimeBook.CPP/primebookonexlsm.archive')
output_base = Path('/workspace/app/extracted_by_year')

# Create output directories
for year in ['2022', '2023', '2024', '2025']:
    (output_base / f'{year}.cpp').mkdir(parents=True, exist_ok=True)

# Find all xlsm files grouped by year
files_by_year = {'2022': [], '2023': [], '2024': [], '2025': []}

for f in archive_dir.glob('*.xlsm'):
    fname = f.name
    # Determine year from filename
    year_match = re.search(r'(202[2-5])', fname)
    if year_match:
        year = year_match.group(1)
        files_by_year[year].append(f)

for year, files in files_by_year.items():
    print(f"{year}: {len(files)} files")

# Sort files by date in filename for each year
def extract_date(fname):
    # Try to extract date from filename like primeOne_2023_06_10.xlsm or GyroCore_2022_05_01e.xlsm
    match = re.search(r'(202[2-5])_(\d{1,2})_(\d{1,2})', fname)
    if match:
        y, m, d = match.groups()
        return (int(y), int(m), int(d))
    return (0, 0, 0)

for year in files_by_year:
    files_by_year[year].sort(key=lambda f: extract_date(f.name))

print("\nLatest file per year:")
for year, files in files_by_year.items():
    if files:
        print(f"  {year}: {files[-1].name}")

