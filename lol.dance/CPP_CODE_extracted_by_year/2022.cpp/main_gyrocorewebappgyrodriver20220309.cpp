
void realm_sw_variables()
{
realm_sw_variable();
realm_sw_variables_sort();

realm_sw_variables_bench();



 cout <<" realm_sw_variables Function Has Completed Successfully "<< endl;

}



void realm_sw_variable()
{
using namespace std;
cout << sizeof(__complex__); variable_type_array_bits[variable_type_array_step_count] = sizeof(__complex__);variable_type_array[variable_type_array_step_count] = "__complex__";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(__complex128); variable_type_array_bits[variable_type_array_step_count] = sizeof(__complex128);variable_type_array[variable_type_array_step_count] = "__complex128";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(__float128); variable_type_array_bits[variable_type_array_step_count] = sizeof(__float128);variable_type_array[variable_type_array_step_count] = "__float128";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(__float80); variable_type_array_bits[variable_type_array_step_count] = sizeof(__float80);variable_type_array[variable_type_array_step_count] = "__float80";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(__FUNCTION__); variable_type_array_bits[variable_type_array_step_count] = sizeof(__FUNCTION__);variable_type_array[variable_type_array_step_count] = "__FUNCTION__";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(__int128); variable_type_array_bits[variable_type_array_step_count] = sizeof(__int128);variable_type_array[variable_type_array_step_count] = "__int128";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(__int16); variable_type_array_bits[variable_type_array_step_count] = sizeof(__int16);variable_type_array[variable_type_array_step_count] = "__int16";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(__int32); variable_type_array_bits[variable_type_array_step_count] = sizeof(__int32);variable_type_array[variable_type_array_step_count] = "__int32";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(__int64); variable_type_array_bits[variable_type_array_step_count] = sizeof(__int64);variable_type_array[variable_type_array_step_count] = "__int64";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(__int8); variable_type_array_bits[variable_type_array_step_count] = sizeof(__int8);variable_type_array[variable_type_array_step_count] = "__int8";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(__m128i); variable_type_array_bits[variable_type_array_step_count] = sizeof(__m128i);variable_type_array[variable_type_array_step_count] = "__m128i";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(__m256i); variable_type_array_bits[variable_type_array_step_count] = sizeof(__m256i);variable_type_array[variable_type_array_step_count] = "__m256i";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(__null); variable_type_array_bits[variable_type_array_step_count] = sizeof(__null);variable_type_array[variable_type_array_step_count] = "__null";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(__PRETTY_FUNCTION__); variable_type_array_bits[variable_type_array_step_count] = sizeof(__PRETTY_FUNCTION__);variable_type_array[variable_type_array_step_count] = "__PRETTY_FUNCTION__";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(bool); variable_type_array_bits[variable_type_array_step_count] = sizeof(bool);variable_type_array[variable_type_array_step_count] = "bool";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(char); variable_type_array_bits[variable_type_array_step_count] = sizeof(char);variable_type_array[variable_type_array_step_count] = "char";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(char16_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(char16_t);variable_type_array[variable_type_array_step_count] = "char16_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(char32_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(char32_t);variable_type_array[variable_type_array_step_count] = "char32_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(double); variable_type_array_bits[variable_type_array_step_count] = sizeof(double);variable_type_array[variable_type_array_step_count] = "double";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(double __complex__); variable_type_array_bits[variable_type_array_step_count] = sizeof(double __complex__);variable_type_array[variable_type_array_step_count] = "double __complex__";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(double long __complex__); variable_type_array_bits[variable_type_array_step_count] = sizeof(double long __complex__);variable_type_array[variable_type_array_step_count] = "double long __complex__";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(float); variable_type_array_bits[variable_type_array_step_count] = sizeof(float);variable_type_array[variable_type_array_step_count] = "float";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(int); variable_type_array_bits[variable_type_array_step_count] = sizeof(int);variable_type_array[variable_type_array_step_count] = "int";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(int_fast16_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(int_fast16_t);variable_type_array[variable_type_array_step_count] = "int_fast16_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(int_fast32_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(int_fast32_t);variable_type_array[variable_type_array_step_count] = "int_fast32_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(int_fast64_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(int_fast64_t);variable_type_array[variable_type_array_step_count] = "int_fast64_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(int_fast8_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(int_fast8_t);variable_type_array[variable_type_array_step_count] = "int_fast8_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(int_least16_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(int_least16_t);variable_type_array[variable_type_array_step_count] = "int_least16_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(int_least32_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(int_least32_t);variable_type_array[variable_type_array_step_count] = "int_least32_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(int_least64_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(int_least64_t);variable_type_array[variable_type_array_step_count] = "int_least64_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(int_least8_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(int_least8_t);variable_type_array[variable_type_array_step_count] = "int_least8_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(int16_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(int16_t);variable_type_array[variable_type_array_step_count] = "int16_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(int32_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(int32_t);variable_type_array[variable_type_array_step_count] = "int32_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(int64_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(int64_t);variable_type_array[variable_type_array_step_count] = "int64_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(int8_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(int8_t);variable_type_array[variable_type_array_step_count] = "int8_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(INTMAX_MAX); variable_type_array_bits[variable_type_array_step_count] = sizeof(INTMAX_MAX);variable_type_array[variable_type_array_step_count] = "INTMAX_MAX";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(INTMAX_MIN); variable_type_array_bits[variable_type_array_step_count] = sizeof(INTMAX_MIN);variable_type_array[variable_type_array_step_count] = "INTMAX_MIN";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(intmax_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(intmax_t);variable_type_array[variable_type_array_step_count] = "intmax_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(INTPTR_MAX); variable_type_array_bits[variable_type_array_step_count] = sizeof(INTPTR_MAX);variable_type_array[variable_type_array_step_count] = "INTPTR_MAX";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(INTPTR_MIN); variable_type_array_bits[variable_type_array_step_count] = sizeof(INTPTR_MIN);variable_type_array[variable_type_array_step_count] = "INTPTR_MIN";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(intptr_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(intptr_t);variable_type_array[variable_type_array_step_count] = "intptr_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(long); variable_type_array_bits[variable_type_array_step_count] = sizeof(long);variable_type_array[variable_type_array_step_count] = "long";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(long __complex__); variable_type_array_bits[variable_type_array_step_count] = sizeof(long __complex__);variable_type_array[variable_type_array_step_count] = "long __complex__";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(long double); variable_type_array_bits[variable_type_array_step_count] = sizeof(long double);variable_type_array[variable_type_array_step_count] = "long double";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(long double  __complex__); variable_type_array_bits[variable_type_array_step_count] = sizeof(long double  __complex__);variable_type_array[variable_type_array_step_count] = "long double  __complex__";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(long long); variable_type_array_bits[variable_type_array_step_count] = sizeof(long long);variable_type_array[variable_type_array_step_count] = "long long";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(long long __complex__); variable_type_array_bits[variable_type_array_step_count] = sizeof(long long __complex__);variable_type_array[variable_type_array_step_count] = "long long __complex__";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(long long int); variable_type_array_bits[variable_type_array_step_count] = sizeof(long long int);variable_type_array[variable_type_array_step_count] = "long long int";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(PTRDIFF_MAX); variable_type_array_bits[variable_type_array_step_count] = sizeof(PTRDIFF_MAX);variable_type_array[variable_type_array_step_count] = "PTRDIFF_MAX";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(PTRDIFF_MIN); variable_type_array_bits[variable_type_array_step_count] = sizeof(PTRDIFF_MIN);variable_type_array[variable_type_array_step_count] = "PTRDIFF_MIN";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(short); variable_type_array_bits[variable_type_array_step_count] = sizeof(short);variable_type_array[variable_type_array_step_count] = "short";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(SIG_ATOMIC_MAX); variable_type_array_bits[variable_type_array_step_count] = sizeof(SIG_ATOMIC_MAX);variable_type_array[variable_type_array_step_count] = "SIG_ATOMIC_MAX";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(SIG_ATOMIC_MIN); variable_type_array_bits[variable_type_array_step_count] = sizeof(SIG_ATOMIC_MIN);variable_type_array[variable_type_array_step_count] = "SIG_ATOMIC_MIN";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(signed int); variable_type_array_bits[variable_type_array_step_count] = sizeof(signed int);variable_type_array[variable_type_array_step_count] = "signed int";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(signed long); variable_type_array_bits[variable_type_array_step_count] = sizeof(signed long);variable_type_array[variable_type_array_step_count] = "signed long";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(signed long long); variable_type_array_bits[variable_type_array_step_count] = sizeof(signed long long);variable_type_array[variable_type_array_step_count] = "signed long long";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(signed short); variable_type_array_bits[variable_type_array_step_count] = sizeof(signed short);variable_type_array[variable_type_array_step_count] = "signed short";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(SIZE_MAX); variable_type_array_bits[variable_type_array_step_count] = sizeof(SIZE_MAX);variable_type_array[variable_type_array_step_count] = "SIZE_MAX";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(string); variable_type_array_bits[variable_type_array_step_count] = sizeof(string);variable_type_array[variable_type_array_step_count] = "string";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(uint_fast16_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(uint_fast16_t);variable_type_array[variable_type_array_step_count] = "uint_fast16_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(uint_fast32_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(uint_fast32_t);variable_type_array[variable_type_array_step_count] = "uint_fast32_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(uint_fast64_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(uint_fast64_t);variable_type_array[variable_type_array_step_count] = "uint_fast64_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(uint_fast8_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(uint_fast8_t);variable_type_array[variable_type_array_step_count] = "uint_fast8_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(uint_least16_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(uint_least16_t);variable_type_array[variable_type_array_step_count] = "uint_least16_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(uint_least32_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(uint_least32_t);variable_type_array[variable_type_array_step_count] = "uint_least32_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(uint_least64_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(uint_least64_t);variable_type_array[variable_type_array_step_count] = "uint_least64_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(uint_least8_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(uint_least8_t);variable_type_array[variable_type_array_step_count] = "uint_least8_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(uint16_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(uint16_t);variable_type_array[variable_type_array_step_count] = "uint16_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(uint32_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(uint32_t);variable_type_array[variable_type_array_step_count] = "uint32_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(uint64_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(uint64_t);variable_type_array[variable_type_array_step_count] = "uint64_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(uint8_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(uint8_t);variable_type_array[variable_type_array_step_count] = "uint8_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(UINTMAX_MAX); variable_type_array_bits[variable_type_array_step_count] = sizeof(UINTMAX_MAX);variable_type_array[variable_type_array_step_count] = "UINTMAX_MAX";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(uintmax_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(uintmax_t);variable_type_array[variable_type_array_step_count] = "uintmax_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(UINTPTR_MAX); variable_type_array_bits[variable_type_array_step_count] = sizeof(UINTPTR_MAX);variable_type_array[variable_type_array_step_count] = "UINTPTR_MAX";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(uintptr_t); variable_type_array_bits[variable_type_array_step_count] = sizeof(uintptr_t);variable_type_array[variable_type_array_step_count] = "uintptr_t";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(unsigned __int128); variable_type_array_bits[variable_type_array_step_count] = sizeof(unsigned __int128);variable_type_array[variable_type_array_step_count] = "unsigned __int128";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(unsigned int); variable_type_array_bits[variable_type_array_step_count] = sizeof(unsigned int);variable_type_array[variable_type_array_step_count] = "unsigned int";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(unsigned long); variable_type_array_bits[variable_type_array_step_count] = sizeof(unsigned long);variable_type_array[variable_type_array_step_count] = "unsigned long";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(unsigned long long); variable_type_array_bits[variable_type_array_step_count] = sizeof(unsigned long long);variable_type_array[variable_type_array_step_count] = "unsigned long long";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(unsigned short); variable_type_array_bits[variable_type_array_step_count] = sizeof(unsigned short);variable_type_array[variable_type_array_step_count] = "unsigned short";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(WCHAR_MAX); variable_type_array_bits[variable_type_array_step_count] = sizeof(WCHAR_MAX);variable_type_array[variable_type_array_step_count] = "WCHAR_MAX";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(WCHAR_MIN); variable_type_array_bits[variable_type_array_step_count] = sizeof(WCHAR_MIN);variable_type_array[variable_type_array_step_count] = "WCHAR_MIN";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(WINT_MAX); variable_type_array_bits[variable_type_array_step_count] = sizeof(WINT_MAX);variable_type_array[variable_type_array_step_count] = "WINT_MAX";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
cout << sizeof(WINT_MIN); variable_type_array_bits[variable_type_array_step_count] = sizeof(WINT_MIN);variable_type_array[variable_type_array_step_count] = "WINT_MIN";cout << variable_type_array[variable_type_array_step_count] << endl; variable_type_array_step_count++;
}

void realm_sw_variables_sort()
{
using namespace std;

cout << endl << endl << "Variable Type Array Step Total :  ";
cout << variable_type_array_step_count << endl;


/* create array of bits then by bits */

bit_current_count_continue == (bit_current_count != system_max_bit);
while (bit_current_count_continue == false) {
variable_type_step_check_continue == (variable_type_step_check != variable_type_array_step_count-1);
while (variable_type_step_check_continue == false) {


/*cout << "Current Bit Check: " << variable_type_array_bits[variable_type_step_check] << " "; */
variable_type_array_bits_continue == (bit_current_count == variable_type_array_bits[variable_type_step_check]);
while (variable_type_array_bits_continue == false) {
  if       (variable_type_step_check >= variable_type_array_step_count) {
cout << "Exit All Loops" << endl;
variable_type_step_check_continue = true; bit_current_count_continue = true; variable_type_array_bits_continue = true;
  }
else {




current_total_variables_same_bit = ++bitarrayvariable[variable_type_array_bits[variable_type_step_check]][0];
cout <<  "Now ";
cout << setw(2) << bitarrayvariable[variable_type_array_bits[variable_type_step_check]][0] ;
cout <<  " Different Variables Within :";
cout << setw(4) << right << variable_type_array_bits[variable_type_step_check] ;
cout <<  "-bit class : ";
cout << "Variable # "<< variable_type_step_check;
cout <<  " Variable Name : " << variable_type_array[variable_type_step_check] << endl;
//sort variables by bit type
bitarrayvariable[variable_type_array_bits[variable_type_step_check]][current_total_variables_same_bit] = variable_type_step_check;
// cout << bitarrayvariable[variable_type_array_bits[variable_type_step_check]][current_total_variables_same_bit];


++variable_type_step_check;
        }
++bit_current_count;

}
  //      ++variable_type_step_check;

        variable_type_step_check = 0;
}}
//list variables by bit type


while(bitarrayvariable_continue == false ){
bitarrayvariable_walk++;

if (bitarrayvariable_walk == system_max_bit-1){ bitarrayvariable_continue = true; }
if (bitarrayvariable[bitarrayvariable_walk][0] != 0){
cout << endl << endl;
cout << setw(3) << right<<  bitarrayvariable[bitarrayvariable_walk][0] << "# Available " << bitarrayvariable_walk << " byte Variables" << endl;

  while (bit_display_walk_continue == false) {
    bit_display_walk++;
    cout << "Variable #" << bitarrayvariable[bitarrayvariable_walk][bit_display_walk];
    cout << ": Variable Name: " << variable_type_array[bitarrayvariable[bitarrayvariable_walk][bit_display_walk]] << endl;
    if (bit_display_walk >= bitarrayvariable[bitarrayvariable_walk][0]) {bit_display_walk_continue = true;}
 }
bit_display_walk_continue = false;

}
bit_display_walk =0;
}
}
/* cout << endl << endl; */
void realm_sw_variables_bench()
{

/* realm_sw_variable_worker(); */

cout << "Create Temp or Static Variable of choice at Array Size";

cout << "Transfer Speed of How Many CupArray and Pitcher Sized Variables to Fill the Pitcher Sized Variable\n";

cout << "Cycle Transfer speed between Largest to Smallest Byte\n";
cout << "bitarrayvariable_walk \n";
cout << "bitarrayvariable[bitarrayvariable_walk][0 how many possible variables to cycle through]\n";
cout << "bitarrayvariable_walk=0\n";
cout << "if (bitarrayvariable[bitarrayvariable_walk][0] != 0){\n";

cout << "do {\n";
cout << "bitarrayvariable_walk++\n";


cout << "bitarrayvariable[bitarrayvariable_walk][bit_display_walk]\n";




cout << "realm_sw_variables_bench Program Has Completed Successfully" << endl;
}

















































void realm_conduits()
{
realm_conduit_weaver();
realm_conduit();
realm_conduit_interface_core();
realm_conduit_interface_network();
realm_outer_realm_conduits();
realm_outer_realm_conduit();

 cout <<" realm_conduits Function Has Completed Successfully "<< endl;

}



void realm_conduit_weaver()
{
cout << "How Many Networkable Conduits Available: 5" << endl;
cout <<"How Many Bare Metal Conduit Buses Available:17" <<endl;
cout <<"Other Conduit Options Available:5" <<endl;
cout <<"Create Conduit : Local Bare Metal Self Connect" << endl;
cout<<"Create Conduit : Network Broadcaster Receiver" << endl;


 cout <<" realm_conduit_weaver Function Has Completed Successfully "<< endl;

}



void realm_conduit()
{
cout << "Conduit Designation: 001110001000100001 : " << endl;
cout << "Conduit Type: Network Connection" << endl;
cout << "Conduit Status: Initiation" << endl;
cout << "Realm OS Driver Localization: Wintel Windows 11"<< endl;
cout <<"Realm Throughoutput Compared to CPU Throtle: 1250/3500 50%" << endl;
cout <<"Conduit Status: Listening Receiving Port 80" << endl;

 cout <<" realm_conduit Function Has Completed Successfully "<< endl;

}



void realm_conduit_interface_core()
{







 cout <<" realm_conduit_interface_core Function Has Completed Successfully "<< endl;

}



void realm_conduit_interface_network()
{
cout << "Name of Network Addapter: NetgearNICBravo : OS Host device id: dev1234567890" << endl;
cout << "Opening Network Listening Port: 80" << endl;
cout << "Broadcasting Port:80" << endl;
cout << "Current IP v4 Address is : 10.0.0.42" << endl;
cout << "Current IP v6 Address is : ab:cd:ef:gh:ij:kl:mn:op" << endl;


 cout <<" realm_conduit_interface_network Function Has Completed Successfully "<< endl;

}



void realm_outer_realm_conduits()
{

cout << "Available Outer Realms: 10.0.0.43/44/45/46/47/48/49" << endl;





 cout <<" realm_outer_realm_conduits Function Has Completed Successfully "<< endl;

}



void realm_outer_realm_conduit()
{

cout << "Initiate OuterRealm Connection with -->user Input/realmlist/cpucore/" << endl;





 cout <<" realm_outer_realm_conduit Function Has Completed Successfully "<< endl;

}




void library_letter()
{







 cout <<" library_letter Function Has Completed Successfully "<< endl;

}



void library_time()
{







 cout <<" library_time Function Has Completed Successfully "<< endl;

}



void librarian()
{

library_time();
library_letter();




 cout <<" librarian Function Has Completed Successfully "<< endl;

}



SHARED VARIABLES
