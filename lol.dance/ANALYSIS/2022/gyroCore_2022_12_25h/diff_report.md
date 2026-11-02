# GearSlice Analysis: gyroCore_2022_12_25h (2022)

**Source:** Spreadsheet cells -> **Target:** Extracted C++

## Summary
- Spreadsheet cells (tracked): 15
- Non-empty cells: 15
- Extracted C++ lines: 1467
- Incorporated cells: 15
- Unused cells: 0
- Code bundles identified: 2

## Code Bundles

### Bundle 1 (incorporated)
- **Cell C21**: #undef UNICODE

/* #include <io.h> */
#include <cstdint>
/* #include <GL/glut.h> */
#include <iomani...
- **Cell C22**: using namespace std;...
- **Cell C23**: int const variable_types_available = 95;
int bit_current_count = 1;
int const system_max_bit = 65;
i...
- **Cell C24**: void heartbeat();
void gyrocore();
void sw_purchase_verify();
void realm();
void realm_os_initiate()...
- **Cell C25**: int main()
{
string text_function_name="main"; string text_post = "";

heartbeat();
gyrocore();
sw_p...
- **Cell C26**: void heartbeat()
{
string text_function_name="heartbeat"; string text_post = "";


text_post = "432 ...
- **Cell C27**: void realm_os_initiate()
{
string text_function_name="realm_os_initiate"; string text_post = "";
rea...
- **Cell C28**: void realm_os_interface()
{
string text_function_name="realm_os_interface"; string text_post = "";
r...

### Bundle 2 (incorporated)
- **Cell A82**: void realm_sw_variables()
{
string text_function_name="realm_sw_variables"; string text_post = "";

...
- **Cell A83**: void realm_sw_variable()
{

string text_function_name="realm_sw_variable"; string text_post = ""; st...
- **Cell A84**: void realm_sw_variables_sort()
{
string text_function_name="realm_sw_variables_sort"; string text_po...
- **Cell A85**: void realm_sw_variables_bench()
{

/* realm_sw_variable_worker(); */
string text_function_name="real...
- **Cell C30**: void realm_conduits()
{
string text_function_name="realm_conduits"; string text_post = "";
realm_con...
- **Cell C31**: void library()
{
string text_function_name="library"; string text_post = "";
text_post = " ENTER TEX...
- **Cell C32**: void realm_gl_querry()
{
string text_function_name="realm_gl_querry"; string text_post = "";
realm_g...

## Structure Map

### Includes (28)
- #include <cstdint>
- #include <iomanip>
- #include <string>
- #include <iostream>
- #include <thread>
- #include <stdio.h>
- #include <stdlib.h>
- #include <unistd.h>
- #include <errno.h>
- #include <vector>
- ... and 18 more

### Defines (1)
- #undef UNICODE

### Globals (405)
- using namespace std;
- int const variable_types_available = 95;
- int bit_current_count = 1;
- int const system_max_bit = 65;
- int variable_type_array_step_total = 0;
- int variable_type_step_check = 0;
- int variable_type_array_check = 0;
- int variable_bits_comparor = 0;
- int not_bit =0;
- string variable_type_array[variable_types_available];
- ... and 395 more

### Comments (17)
- /* #include <io.h> */
- /* #include <GL/glut.h> */
- /* link with Ws2_32.lib */
- /* #include "../application/vulkan/vulkan-application.hpp" */
- /* #include "../application/vulkan/vulkan-common.hpp" */
- /* bool isConsole = isatty(fileno(stdin)); */
- /*
- /* create array of bits then by bits */
- //sort variables by bit type
- //      ++variable_type_step_check;
- ... and 7 more

