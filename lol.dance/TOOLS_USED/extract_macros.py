import openpyxl
import os

# Load the computed xlsx file
wb = openpyxl.load_workbook('/tmp/GUI_primeOne_2025_6_29.xlsx', data_only=True)
ws = wb['BUILD']

# Output directory
output_dir = '/workspace/app/PB1/PrimeBook.CPP/PrimeOne'
js_bench_dir = '/workspace/app/PB1/PrimeBook.CPP/JS.bench'
js_bench_html_dir = os.path.join(js_bench_dir, 'html')

os.makedirs(output_dir, exist_ok=True)
os.makedirs(js_bench_dir, exist_ok=True)
os.makedirs(js_bench_html_dir, exist_ok=True)

# Create_CPP_File cells
cpp_cells = [
    'A37','A38','A39','A40','A41','A44','A46','A45',
    'A175','A176','A177','A179','A180','A181','A182','A183','A184','A185','A186','A187','A188','A189','A190','A191','A192','A193','A194','A195','A196','A197','A198','A199','A200','A201','A202','A203','A204','A205','A206','A207','A208','A209','A210','A211','A212','A213','A214','A215','A216','A217','A218','A219','A220','A221','A223','A224','A225','A226','A228','A230','A233','A234','A236','A237','A238','A240','A242','A256',
    'A42','A43',
    'A300','A301','A302','A303','A304','A305','A306','A307','A308','A309','A310','A311','A312','A314','A318','A319','A324',
    'A47','A48','A49','A50','A51','A52','A55','A56','A57','A58','A59','A60','A62','A63','A64','A65','A66','A74','A81','A82','A83','A84','A89','A90','A91','A92','A94','A96','A98','A99','A100','A102','A103','A104','A113','A114','A116','A124','A125','A126','A131','A132','A133','A134','A135','A136','A137','A138','A139','A140','A142','A143','A145','A146','A147','A148','A149','A150','A151','A152','A153','A154','A155','A156','A157','A158','A159','A160','A161','A162','A163','A164','A165','A167','A168'
]

print("Generating main.cpp...")
with open(os.path.join(output_dir, 'main.cpp'), 'w') as f:
    for cell in cpp_cells:
        val = ws[cell].value
        if val is not None:
            f.write(str(val))
            f.write('\n')

print("Generating gyrocore.cpp...")
js_cpp_cells = ['C21','C22','C23','C24','C25','C26','C27','C28','A82','A83','A84','A85','C30','C31','C32']
with open(os.path.join(js_bench_dir, 'gyrocore.cpp'), 'w') as f:
    for cell in js_cpp_cells:
        val = ws[cell].value
        if val is not None:
            f.write(str(val))
            f.write('\n')

print("Generating manifest.json...")
with open(os.path.join(js_bench_dir, 'manifest.json'), 'w') as f:
    val = ws['G6'].value
    if val is not None:
        f.write(str(val))

print("Generating gyrocorex.js...")
with open(os.path.join(js_bench_dir, 'gyrocorex.js'), 'w') as f:
    val = ws['G12'].value
    if val is not None:
        f.write(str(val))

print("Generating gyrocorec.js...")
with open(os.path.join(js_bench_dir, 'gyrocorec.js'), 'w') as f:
    val = ws['G13'].value
    if val is not None:
        f.write(str(val))

print("Generating gyrocore_interface.html...")
with open(os.path.join(js_bench_html_dir, 'gyrocore_interface.html'), 'w') as f:
    val = ws['G8'].value
    if val is not None:
        f.write(str(val))

print("Generating gyrocore_interface.css...")
with open(os.path.join(js_bench_html_dir, 'gyrocore_interface.css'), 'w') as f:
    val = ws['G9'].value
    if val is not None:
        f.write(str(val))

print("Done!")
