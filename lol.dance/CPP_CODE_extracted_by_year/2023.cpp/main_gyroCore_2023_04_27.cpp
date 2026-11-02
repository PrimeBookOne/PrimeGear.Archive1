#undef UNICODE

/* #include <io.h> */
#include <cstdint>
/* #include <GL/glut.h> */
#include <iomanip>
#include <string>
#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <vector>
#include <sys/types.h>
#include <limits>
#include <fstream>
#include <pthread.h>
/* link with Ws2_32.lib */
#pragma comment (lib, "Ws2_32.lib")

#ifndef __linux__ /*Excludes Anything That Isn't Emscriptem Compatible*/
#ifndef __EMSCRIPTEN__ /*Excludes Anything That Isn't Emscriptem Compatible*/
#include <winsock2.h>  /* UNIX ONLY #include <sys/socket.h> #include <netinet/in.h> #include <arpa/inet.h>*/
#include <winsock.h>  /* #include <netdb.h> */
/* #include "../application/vulkan/vulkan-application.hpp" */
/* #include "../application/vulkan/vulkan-common.hpp" */
#include <quadmath.h>
#include <Ws2tcpip.h>
#include <immintrin.h>
#endif
#endif

#include <stdio.h>
#include <process.h>
#include <wtypes.h>
#include <sys/types.h>
#include <unistd.h>
#include <sstream>
#include <bits/stdc++.h>
#include <sched.h>
#include <unistd.h>
#include <winbase.h>
#include <chrono>
#include <dos.h>
#include <future>
#include <filesystem>

#include <filesystem>
#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <omp.h>
#include <cuda_runtime_api.h>













using namespace std;


int const variable_types_available = 95;
int bit_current_count = 1;
int const system_max_bit = 65;
int variable_type_array_step_total = 0;
int variable_type_step_check = 0;
int variable_type_array_check = 0;
bool bit_current_count_continue;
int variable_bits_comparor = 0;
int not_bit =0;
string variable_type_array[variable_types_available];
int variable_type_array_bits[variable_types_available];
int bit_array[system_max_bit];
int bitarray_walk[system_max_bit];
int vtasc  = 0; /* variable_type_array_step_count */
bool variable_type_step_check_continue;
bool variable_type_array_bits_continue;
int bitarrayvariable[system_max_bit][variable_types_available];
int current_total_variables_same_bit = 0;
bool bitarrayvariable_continue;
int bitarrayvariable_walk  = 0;
bool bit_display_walk_continue ;
int bit_display_walk =0;

////////////////// GLOBAL Dancer
__int128 singers = 5;
__int128 perThreadSlices = 1000000;
__int128* globalUpdatesArrayTotals = new __int128[ singers ];
  mutex globalUpdatesArrayTotalsMutex;
int_fast16_t* globalUpdatesArray = new int_fast16_t[ perThreadSlices*singers ];
  mutex globalUpdatesArrayMutex;
////////////////// GLOBAL















class primeScribeClass
{
public:
bool pen16(int_fast16_t data){
if ( data <= 15){ primeBook << std::hex << data; }
if ( data > 15 && data < 256){ primeBook << endl << std::hex << data; lineCount++;}
if ( data > 255) {primeBook << endl << "0" << std::hex << data; lineCount++; }
     //   cout << int(lineCount) << "lineCount "<< endl;
if (lineCount == lineCountMax){
     //   cout << int(lineCountMax) << "lineCountMax "<< endl;
    lineCount=0;
    return true;
}
else { return false;} }

void unCapPen(__int128 singer_t, __int128 singersDigitSize_t, __int128 lineCountMax_t){
lineCountMax = lineCountMax_t;
singer = singer_t;
singersDigitSize = singersDigitSize_t;
int removed = 0;
__int128 digitDifferences =0;
__int128 singerDigitFind= singer;
string digitDifferencesString="";

primeCobbleStones.open("cobblestones.txt", std::fstream::in | std::fstream::out | std::fstream::app);
primeMileStones.open("primemilestones.txt", std::fstream::in | std::fstream::out | std::fstream::app);

while(singerDigitFind > 9){
  singerDigitFind =singerDigitFind /10;
  singerDigitSize++;
}

digitDifferences= singersDigitSize - singerDigitSize;
if (digitDifferences > 0){
  for (int i =0; i< digitDifferences; i++){ digitDifferencesString=digitDifferencesString+"0";}
}
if(singersDigitSize==0){
  primeBook.open("primebook.bin",
  std::fstream::in | std::fstream::out | std::fstream::app);
}
else{

primeBook.open("myprimes"+digitDifferencesString+to_string(int(singer))+".bin",
 ios::out | ios::trunc );
   }

}

void printMileStone(string printThis){
primeMileStones << printThis << endl;
cout << printThis << endl;
}

void mark(__int128 data){
primeCobbleStones << int(data) << endl;
// cout << int(data) << endl;
}


void capPen(){ primeBook.close(); }

private:
fstream primeMileStones;
fstream primeBook;
fstream primeCobbleStones;
char filename;
__int128 singer =0;
__int128 singers =0;
string filenameString ="";
__int128 singersDigitSize =0;
__int128 singerDigitSize=1;
__int128 penCount =0;
__int128 lineCount=0;
__int128 lineCountMax =0;
};






































































class primePillarClass
{
public:
primePillarClass(__int128  window_t,
            __int128  primeFeather_t) :
              window(window_t),
              primeFeather(primeFeather_t)
{
}
void write(__int128 data) { primeTile[total++]=data;
}
int_fast16_t breeze() {
    return primeTile[breezeWalk++]; }
void still(){ breezeWalk=0;}
__int128 primetotals(){return total;}
private:
__int128 window = 0;
__int128 primeFeather=0;
__int128 total =0;
__int128 breezeWalk=0;
  int_fast16_t* primeTile = new int_fast16_t[ primeFeather ];
};



























































































































class LargeIntClass
{
private:
vector<int> digits;
public:
LargeInt(__int128 num) {
  while (num > 0) {
  digits.push_back(num % 10);
  num /= 10;
  }
}
string toString() {
  reverse(digits.begin(), digits.end());
  string str(digits.size(), ' ');
  transform(digits.begin(), digits.end(), str.begin(), [](int digit) {
  return digit + '0';
  });
  return str;
}
};






























































































































void heartbeat();
void gyrocore();
void sw_purchase_verify();
void realm();
void realm_os_initiate();
void realm_os_silent();
void realm_os_responsive();
void realm_os();
void realm_os_interface();
void realm_multi_core();
void realm_post_client(string,string);
void realm_querry_client();
void realm_sw_variables();
void realm_sw_variables_sort();
void realm_sw_variable();

void realm_conduits();
void realm_conduit_weaver();
void realm_conduit();
void realm_conduit_interface_core();
void realm_conduit_interface_network();
void realm_outer_realm_conduits();
void realm_outer_realm_conduit(int,int,int,int);
void library_letter();
void library_time();
void librarian(); 
void library(); 

vector<DISPLAY_DEVICE> realm_gl_winGpus();
void realm_gl_querry(); 
void realm_gl_webgl(); 
void realm_gl_vulkan(); 
void realm_gl_opengl(); 
void realm_gl_metal(); 
void realm_gl_directx(); 
void realm_gl_cores_zeluda(); 

void realm_gl_cores_gpufort(); 
void realm_os_menu();
int realm_sw_array_Flexor();
void realm_gl_cuda_devices(int gpuIndex);
vector<DISPLAY_DEVICE> realm_gl_cores_cuda();
void realm_gl_cuda_devices(int gpuIndex);
void realm_sw_variable_primer(int songRequest,bool mrTsaysRead, int singers);

void realm_sw_divisor_dancer(__int128 infiniteWalk, __int128 songBuffer, __int128 perThreadSlices, __int128 singer, __int128 singers, __int128 singersDigitSize, __int128 primeBookIndex, primePillarClass  primeOne);


void realm_os_user_input(string&validUserInput);
void librarian_menu();
void librarian_functions();





















int main()
{
string text_function_name="main"; string text_post = "";
realm_gl_querry();
//heartbeat();
//gyrocore();
//sw_purchase_verify();
//realm();
librarian();
text_post = "FUNCTION   main   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );
 return (0);
}






























































void heartbeat()
{
string text_function_name="heartbeat"; string text_post = "";


text_post = " 432 "; realm_post_client(text_function_name, text_post );



text_post = "FUNCTION   heartbeat   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void gyrocore()
{
string text_function_name="gyrocore"; string text_post = "";






text_post = "FUNCTION   gyrocore   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void sw_purchase_verify()
{
string text_function_name="sw_purchase_verify"; string text_post = "";






text_post = "FUNCTION   sw_purchase_verify   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void realm()
{
string text_function_name="realm"; string text_post = "";
realm_os_initiate();
realm_os_silent();
realm_os_responsive();



text_post = "FUNCTION   realm   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void realm_os_initiate()
{
string text_function_name="realm_os_initiate"; string text_post = "";
realm_os();





text_post = "FUNCTION   realm_os_initiate   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void realm_os_silent()
{
string text_function_name="realm_os_silent"; string text_post = "";






text_post = "FUNCTION   realm_os_silent   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void realm_os_responsive()
{
string text_function_name="realm_os_responsive"; string text_post = "";






text_post = "FUNCTION   realm_os_responsive   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void realm_os()
{
string text_function_name="realm_os"; string text_post = "";
text_post = "FUNCTION   realm_os   HAS BEGUN SUCESSFULLY!"; realm_post_client(text_function_name, text_post );
realm_sw_variables();
realm_conduits();
realm_multi_core();
realm_os_interface();

text_post = "FUNCTION   realm_os   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void realm_multi_core()
{
string text_function_name="realm_multi_core"; string text_post = "";


const auto realm_thread_count = std::thread::hardware_concurrency();
text_post = "Realm OS CPU Thread Count "; realm_post_client(text_function_name, text_post );
text_post = to_string(realm_thread_count);realm_post_client(text_function_name, text_post );

text_post = "FUNCTION   realm_multi_core   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}




int realm_sw_array_Flexor(__int128& arraySizeMax, int singers)
{
string text_function_name="realm_sw_array_Flexor"; string text_post = "";
text_post = " ENTER TEXT HERE "; realm_post_client(text_function_name, text_post );
// int_fast16_t* primeDifferencesArray = new int_fast16_t[5376999999];
//int_fast16_t* primeDifferencesArray = new int_fast16_t[76999999];
// bool* songArray = new bool[songRequest];
int singerWalk=0;
int boolTestSizeChunks =1000000;
string string128="";
// cout << "FLEXFunction " << endl;
int intTestSizeChunks =1000000;
__int128 intTestSizeGrow =intTestSizeChunks;
bool testMemory=true;
singerWalk=0;


while (testMemory==true){
  try{
    int_fast16_t* singerWalk0 = new int_fast16_t[ intTestSizeGrow ];
    intTestSizeGrow += intTestSizeChunks;
    delete[] singerWalk0;
















 //   cout << " " << int(intTestSizeGrow) << "    " << endl;
  }
  catch(...){
   //  cout << "too large of an Array" << int(intTestSizeGrow) << endl;
    testMemory=false;
   arraySizeMax=(intTestSizeGrow - intTestSizeChunks)/singers;
  }





































































}







text_post = "FUNCTION   realm_sw_variable_primer   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );
}




















void realm_os_interface()
{
string text_function_name="realm_os_interface"; string text_post = "";
realm_querry_client();

text_post = "Realm OS is now ready for instructions"; realm_post_client(text_function_name, text_post );






realm_os_menu();


text_post = "FUNCTION   realm_os_interface   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );


}















void realm_post_client(string input_text_function_name, string input_text)
{


cout  << "LOG: " << input_text_function_name  << setw(42-input_text_function_name.length()) <<  "POST: "<< input_text << endl;






}



void realm_querry_client()
{
string text_function_name="realm_querry_client"; string text_post = "";
string Compiler="EMSCRIPTEN";
#ifndef __EMSCRIPTEN__ 
/* bool isConsole = isatty(fileno(stdin)); */
Compiler="Console";
#endif
/*
text_post = "Realm OS is Compiled by: "+Compiler; realm_post_client(text_function_name, text_post );
*/


realm_gl_querry();


text_post = "FUNCTION   realm_querry_client   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post);
}














void realm_os_menu()
{
string text_function_name="realm_os_menu"; string text_post = "";












text_post = "FUNCTION   realm_os_menu   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );


}















void realm_os_user_input(string&validUserInput)
{    

/* ="cout << " & CHAR(34) & "Function Begin : "  & B2 & CHAR(34)  & " << endl;" */

  string userRawInput="";
  cin.clear();
  getline(cin, userRawInput);
  validUserInput = userRawInput +"\0";
}


































































void realm_sw_divisor_dancer(__int128 infiniteWalk, __int128 songBuffer, __int128 perThreadSlices, __int128 singer, __int128 singers, __int128 singersDigitSize, __int128 primeBookIndex, primePillarClass  primeOne)
{

__int128 primeDifference=0;
__int128 primeBuild=0;
__int128 intTail=0;
__int128 previousPrime = 0;
__int128 moonWalker = 0;
  bool findPrevious=true;
  bool dance=true;
__int128 slice=0;
__int128 primesFindTotals=0;
__int128 dancePlacement = singer*perThreadSlices;
char wait;

infiniteWalk= infiniteWalk + (singer * perThreadSlices * 2);
// cout << "singer "<< int(singer)<< "  infiniteWalk "<< int(infiniteWalk) << endl;
moonWalker = infiniteWalk;
  while ( findPrevious==true ){
      primeBuild = 3;
    while (dance==true){
      moonWalker+=-2;
      intTail=moonWalker%primeBuild;
      if (intTail==0){ dance =false; }
      else if(primeBuild> ((infiniteWalk/primeBuild) +1) ){
        dance =false;
        previousPrime = moonWalker;
        findPrevious=false; } //  IF PRIME
  primeBuild+=primeOne.breeze()*2;
    } // ******** WHILE DANCE = TRUE LOOP *******
    dance=true;   primeOne.still();
  } // FINISH findPrevious
//cout << endl << "     ********************** BUILD perThreadSlicesTHREADArray **************************** ";
//cout << endl ;

while ( slice  <  perThreadSlices ){
primeBuild=3;
dance=true;
while (dance==true){
intTail=infiniteWalk%primeBuild;
if (intTail==0){dance =false;}
else  if(primeBuild> ((infiniteWalk/primeBuild) +1) ){
dance =false;
primeDifference = (infiniteWalk - previousPrime)/2;

globalUpdatesArrayMutex.lock();
globalUpdatesArray[dancePlacement + primesFindTotals ] = primeDifference;
globalUpdatesArrayMutex.unlock();
primesFindTotals++;
previousPrime=infiniteWalk;
// cout << "singer "<< int(singer)<< "  difference "<< int(primeDifference) << endl;

}  // ******** IF PRIME BY RANGE *******
else{primeBuild+= primeOne.breeze()*2;}
}  // ******** WHILE DANCE = TRUE LOOP *******
primeOne.still();
infiniteWalk+=2;
slice++;
} // slices
// cout << "                  ********************** threadFinished **************************** ";

// myPrimeChapter.capPen();
globalUpdatesArrayTotals[singer]=primesFindTotals;
}



























































































































































































































































void realm_sw_variable_primer(int songRequest,bool mrTsaysRead, int singers)
{
string text_function_name="realm_sw_variable_primer"; string text_post = "";
text_post = " ENTER TEXT HERE "; realm_post_client(text_function_name, text_post );


__int128 infiniteWalk = 5;
__int128 songBuffer = 0; // future use 767676767
__int128 singer =0;
__int128 singersDigitSize=1;
__int128 primeBookIndex = 0; // future use 1000000
__int128 window = 3;
__int128 pDaSize = 7676767676;
primePillarClass primeOne(window,pDaSize);
__int128 infiniteWalkStart =0;
__int128 previousPrime=3;
__int128 cycle=0;
__int128 feather = 0;
__int128 total = 0;
__int128 totalPrimes=0;
__int128 primeBuild=0;
__int128 dance=0;
__int128 intTail=0;
__int128 pDlarge=0;
__int128 totalSkip =0;
__int128 singersDigitFind= singers;
__int128 totalScan=0;
__int128 scanBegin=0;
__int128 scanWalk=0;
__int128 printInt=0;
__int128 lineCountMax=500000;
__int128 lineTotalCount=0;

int removed =0;
bool infinite = true;
int_fast16_t primeDifference;
string pDlargeString ="";
  removed = remove("cobblestones.txt");
  removed = remove("primemilestones.txt");
  removed = remove("primebook.bin");
system("cleanupallbin.bat");


while(singersDigitFind > 9){
  singersDigitFind =singersDigitFind /10;
  singersDigitSize++;
}  //cout << endl << "     **********************  singersDigitSize  **************************** "; //cout << endl << "     **********************  " << int(singers) << "  **************************** "; //cout << endl << "     **********************  " << int(singersDigitSize) << "  **************************** ";

primeScribeClass primeBook;
primeBook.unCapPen(singersDigitSize, 0, lineCountMax);


while ( total  <  perThreadSlices ){

primeBuild=3;
dance=true;

while (dance==true){
intTail=infiniteWalk%primeBuild;
if (intTail==0){dance =false;}
else  if(primeBuild> ((infiniteWalk/primeBuild) +1) ){
dance =false;
total++;
totalSkip++;
primeDifference = (infiniteWalk - previousPrime)/2;
previousPrime=infiniteWalk;


primeOne.write(primeDifference);
if (primeBook.pen16(primeDifference)==true){primeBook.mark(infiniteWalk); };
   if (pDlarge<primeDifference){
      pDlarge= primeDifference ;
      pDlargeString=  "PrimeDifferenceLargest  " + to_string(int(pDlarge)) + " Prime: " + to_string(int( infiniteWalk ))+ " Total : " +to_string(int( total));
      primeBook.printMileStone(pDlargeString);
    }

//cout << endl << "    hello" << primeMiles.check(primeDifference);




}  // ******** IF PRIME BY RANGE *******
else{primeBuild+= primeOne.breeze()*2;}
}  // ******** WHILE DANCE = TRUE LOOP *******
primeOne.still();
infiniteWalk+=2;
} // slices

// primeBook.capPen();
cout << "----> Dance Request Size Now Engaged at : " << int(total) << endl<< endl<< endl<< endl;
vector< thread > choir;

while ( infinite == true){  // =============================================v  //cout  << "***** infinite main = true # " ;
choir.clear();
infiniteWalkStart=infiniteWalk;

for (singer = 0; singer < singers; singer++) {
  choir.push_back(thread(realm_sw_divisor_dancer,    infiniteWalk,
                          songBuffer,                perThreadSlices,
                          singer,                    singers,
                          singersDigitSize,          primeBookIndex,
                          primeOne)
                  );}

for (auto& t : choir) { t.join(); }

choir.front();

singer=0;
globalUpdatesArrayMutex.lock();
while(singer < singers){
totalScan=globalUpdatesArrayTotals[singer]+1;
//  cout << "    singer " << int(singer)<< " totalScan " << int(totalScan);
scanBegin = (singer * perThreadSlices );
scanWalk=1;

while(scanWalk < totalScan){
    infiniteWalk+=primeDifference*2;
    primeDifference = globalUpdatesArray[scanBegin+scanWalk];
    primeOne.write(primeDifference);
if (primeBook.pen16(primeDifference)){primeBook.mark(infiniteWalk); };
    if (pDlarge<primeDifference){
      pDlarge= primeDifference ;
      pDlargeString=  "PrimeDifferenceLargest  " + to_string(int(pDlarge)) + " Prime: " + to_string(int( infiniteWalk ))+ " Total : " +to_string(int( total));
      primeBook.printMileStone(pDlargeString);
    }
    total++;

    scanWalk++;
}
singer++;
}
globalUpdatesArrayMutex.unlock();


// //////  check system and gpu temp compare and contrast to previous inquiries in array

/*
cout <<"Step:" <<  int(singers * perThreadSlices *2);

printInt=((singers * perThreadSlices *2)-((infiniteWalk - (infiniteWalkStart + (singers * perThreadSlices *2)))));

cout <<"  Step Difference ";

cout << int(printInt/singers);
cout <<"  Built:";
cout<<  int(infiniteWalk);
printInt=(infiniteWalk - (infiniteWalkStart + (singers * perThreadSlices *2)));
cout <<"  Difference:";
cout<< int(printInt/singers) ;

 infiniteWalk=infiniteWalkStart + (singers * perThreadSlices *2);
cout <<"  Equated:" <<  int(infiniteWalk) << endl;

cout << " primeOne.primetotals ";
 cout<< int(primeOne.primetotals());
cout << " count totals ";
 cout<< int(total);
cout << " iWalk/Total Ratio : ";
cout <<int( infiniteWalk/total);
cout << endl;
*/
} // WHILE INFINITE == TRUE  ===============================================^
}






















































































































































void realm_sw_variables()
{
string text_function_name="realm_sw_variables"; string text_post = "";


realm_sw_variable();
realm_sw_variables_sort();






text_post = "FUNCTION   realm_sw_variables   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );
}

void realm_sw_variable()
{

string text_function_name="realm_sw_variable"; string text_post = ""; string tb1 = "";


#ifndef __linux__ 
variable_type_array_bits[vtasc] = sizeof(__complex128);variable_type_array[vtasc] = "__complex128";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(__int16);variable_type_array[vtasc] = "__int16";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(__int32);variable_type_array[vtasc] = "__int32";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(__int64);variable_type_array[vtasc] = "__int64";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(__float128);variable_type_array[vtasc] = "__float128";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(__float80);variable_type_array[vtasc] = "__float80";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(__m128i);variable_type_array[vtasc] = "__m128i";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(__m256i);variable_type_array[vtasc] = "__m256i";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;




#ifndef __EMSCRIPTEN__ 
variable_type_array_bits[vtasc] = sizeof(__complex128);variable_type_array[vtasc] = "__complex128";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(__int16);variable_type_array[vtasc] = "__int16";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(__int32);variable_type_array[vtasc] = "__int32";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(__int64);variable_type_array[vtasc] = "__int64";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(__float80);variable_type_array[vtasc] = "__float80";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(__int8);variable_type_array[vtasc] = "__int8";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(__m128i);variable_type_array[vtasc] = "__m128i";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(__int128);variable_type_array[vtasc] = "__int128";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(__m256i);variable_type_array[vtasc] = "__m256i";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;






#endif 
#endif 


#ifndef WINNT



variable_type_array_bits[vtasc] = sizeof(__int16_t);variable_type_array[vtasc] = "__int16_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(__int32_t);variable_type_array[vtasc] = "__int32_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(__int64_t);variable_type_array[vtasc] = "__int64_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(__m256i);variable_type_array[vtasc] = "__m256i";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;

#endif 




variable_type_array_bits[vtasc] = sizeof(__null);variable_type_array[vtasc] = "__null";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(__PRETTY_FUNCTION__);variable_type_array[vtasc] = "__PRETTY_FUNCTION__";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(bool);variable_type_array[vtasc] = "bool";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(char);variable_type_array[vtasc] = "char";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(char16_t);variable_type_array[vtasc] = "char16_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(char32_t);variable_type_array[vtasc] = "char32_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(double);variable_type_array[vtasc] = "double";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(double __complex__);variable_type_array[vtasc] = "double __complex__";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(double long __complex__);variable_type_array[vtasc] = "double long __complex__";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(float);variable_type_array[vtasc] = "float";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(int);variable_type_array[vtasc] = "int";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(int_fast16_t);variable_type_array[vtasc] = "int_fast16_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(int_fast32_t);variable_type_array[vtasc] = "int_fast32_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(int_fast64_t);variable_type_array[vtasc] = "int_fast64_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(int_fast8_t);variable_type_array[vtasc] = "int_fast8_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(int_least16_t);variable_type_array[vtasc] = "int_least16_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(int_least32_t);variable_type_array[vtasc] = "int_least32_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(int_least64_t);variable_type_array[vtasc] = "int_least64_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(int_least8_t);variable_type_array[vtasc] = "int_least8_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(int16_t);variable_type_array[vtasc] = "int16_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(int32_t);variable_type_array[vtasc] = "int32_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(int64_t);variable_type_array[vtasc] = "int64_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(int8_t);variable_type_array[vtasc] = "int8_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(INTMAX_MAX);variable_type_array[vtasc] = "INTMAX_MAX";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(INTMAX_MIN);variable_type_array[vtasc] = "INTMAX_MIN";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(intmax_t);variable_type_array[vtasc] = "intmax_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(INTPTR_MAX);variable_type_array[vtasc] = "INTPTR_MAX";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(INTPTR_MIN);variable_type_array[vtasc] = "INTPTR_MIN";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(intptr_t);variable_type_array[vtasc] = "intptr_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(long);variable_type_array[vtasc] = "long";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(long __complex__);variable_type_array[vtasc] = "long __complex__";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(long double);variable_type_array[vtasc] = "long double";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(long double  __complex__);variable_type_array[vtasc] = "long double  __complex__";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(long long);variable_type_array[vtasc] = "long long";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(long long __complex__);variable_type_array[vtasc] = "long long __complex__";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(long long int);variable_type_array[vtasc] = "long long int";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(PTRDIFF_MAX);variable_type_array[vtasc] = "PTRDIFF_MAX";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(PTRDIFF_MIN);variable_type_array[vtasc] = "PTRDIFF_MIN";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(short);variable_type_array[vtasc] = "short";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(SIG_ATOMIC_MAX);variable_type_array[vtasc] = "SIG_ATOMIC_MAX";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(SIG_ATOMIC_MIN);variable_type_array[vtasc] = "SIG_ATOMIC_MIN";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(signed int);variable_type_array[vtasc] = "signed int";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(signed long);variable_type_array[vtasc] = "signed long";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(signed long long);variable_type_array[vtasc] = "signed long long";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(signed short);variable_type_array[vtasc] = "signed short";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(SIZE_MAX);variable_type_array[vtasc] = "SIZE_MAX";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(size_t);variable_type_array[vtasc] = "size_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(string);variable_type_array[vtasc] = "string";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(uint_fast16_t);variable_type_array[vtasc] = "uint_fast16_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(uint_fast32_t);variable_type_array[vtasc] = "uint_fast32_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(uint_fast64_t);variable_type_array[vtasc] = "uint_fast64_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(uint_fast8_t);variable_type_array[vtasc] = "uint_fast8_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(uint_least16_t);variable_type_array[vtasc] = "uint_least16_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(uint_least32_t);variable_type_array[vtasc] = "uint_least32_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(uint_least64_t);variable_type_array[vtasc] = "uint_least64_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(uint_least8_t);variable_type_array[vtasc] = "uint_least8_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(uint16_t);variable_type_array[vtasc] = "uint16_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(uint32_t);variable_type_array[vtasc] = "uint32_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(uint64_t);variable_type_array[vtasc] = "uint64_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(uint8_t);variable_type_array[vtasc] = "uint8_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(UINTMAX_MAX);variable_type_array[vtasc] = "UINTMAX_MAX";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(uintmax_t);variable_type_array[vtasc] = "uintmax_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(UINTPTR_MAX);variable_type_array[vtasc] = "UINTPTR_MAX";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(uintptr_t);variable_type_array[vtasc] = "uintptr_t";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(unsigned __int128);variable_type_array[vtasc] = "unsigned __int128";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(unsigned int);variable_type_array[vtasc] = "unsigned int";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(unsigned long);variable_type_array[vtasc] = "unsigned long";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(unsigned long long);variable_type_array[vtasc] = "unsigned long long";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(unsigned short);variable_type_array[vtasc] = "unsigned short";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(WCHAR_MAX);variable_type_array[vtasc] = "WCHAR_MAX";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(WCHAR_MIN);variable_type_array[vtasc] = "WCHAR_MIN";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(WINT_MAX);variable_type_array[vtasc] = "WINT_MAX";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


variable_type_array_bits[vtasc] = sizeof(WINT_MIN);variable_type_array[vtasc] = "WINT_MIN";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;





















text_post = "Completed new variables"; realm_post_client(text_function_name, text_post );



}


void realm_sw_variables_sort()
{
string text_function_name="realm_sw_variables_sort"; string text_post = ""; string text_build_1 = "";

text_build_1 =  "Variable Type Array Step Total :  " + 
to_string(vtasc);
text_post = text_build_1; realm_post_client(text_function_name, text_post );

/* create array of bits then by bits */

bit_current_count_continue == (bit_current_count != system_max_bit);
while (bit_current_count_continue == false) {
variable_type_step_check_continue == (variable_type_step_check != vtasc-1);
while (variable_type_step_check_continue == false) {



variable_type_array_bits_continue == (bit_current_count == variable_type_array_bits[variable_type_step_check]);
while (variable_type_array_bits_continue == false) {
  if       (variable_type_step_check >= vtasc) {
text_post = "Exit All Loops"; realm_post_client(text_function_name, text_post );
variable_type_step_check_continue = true; bit_current_count_continue = true; variable_type_array_bits_continue = true;
  }
else {


current_total_variables_same_bit = ++bitarrayvariable[variable_type_array_bits[variable_type_step_check]][0];
text_build_1 =  "Now " +
to_string(bitarrayvariable[variable_type_array_bits[variable_type_step_check]][0]) +
" : " +
to_string(variable_type_array_bits[variable_type_step_check]) +
"-bit class : Variable # " +
to_string(variable_type_step_check) +
" Name : " +
variable_type_array[variable_type_step_check];
text_post = text_build_1; realm_post_client(text_function_name, text_post );
//sort variables by bit type
bitarrayvariable[variable_type_array_bits[variable_type_step_check]][current_total_variables_same_bit] = variable_type_step_check;



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
text_build_1 =  to_string(bitarrayvariable[bitarrayvariable_walk][0]) +  "# Available " + to_string(bitarrayvariable_walk) + " bit Variables";
text_post = text_build_1; realm_post_client(text_function_name, text_post );

  while (bit_display_walk_continue == false) {
    bit_display_walk++;
text_build_1 =  "Variable #" + to_string(bitarrayvariable[bitarrayvariable_walk][bit_display_walk]) + ": Variable Name: " +  variable_type_array[bitarrayvariable[bitarrayvariable_walk][bit_display_walk]];
text_post = text_build_1; realm_post_client(text_function_name, text_post );
    if (bit_display_walk >= bitarrayvariable[bitarrayvariable_walk][0]) {bit_display_walk_continue = true;}
 }
bit_display_walk_continue = false;

}
bit_display_walk =0;
}
}

void realm_conduits()
{
string text_function_name="realm_conduits"; string text_post = "";
realm_conduit_weaver();
realm_conduit();
realm_conduit_interface_core();

realm_outer_realm_conduits();


text_post = "FUNCTION   realm_conduits   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void realm_conduit_weaver()
{
string text_function_name="realm_conduit_weaver"; string text_post = "";






realm_conduit_interface_network();





text_post = "FUNCTION   realm_conduit_weaver   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}













void realm_conduit()
{
string text_function_name="realm_conduit"; string text_post = "";







text_post = "FUNCTION   realm_conduit   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}


void realm_conduit_interface_core()
{
string text_function_name="realm_conduit_interface_core"; string text_post = "";






text_post = "FUNCTION   realm_conduit_interface_core   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void realm_conduit_interface_network()
{
string text_function_name="realm_conduit_interface_network"; string text_post = "";







































text_post = "FUNCTION   realm_conduit_interface_network   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}





























void realm_outer_realm_conduits()
{
string text_function_name="realm_outer_realm_conduits"; string text_post = "";






text_post = "FUNCTION   realm_outer_realm_conduits   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void realm_outer_realm_conduit(int a,int b, int c, int d)
{
string text_function_name="realm_outer_realm_conduit"; string text_post = "";






text_post = "FUNCTION   realm_outer_realm_conduit   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void librarian_functions()
{    

  bool mrTsaysRead=false;
  bool questionDemonstrate=true;

  int songCount=767676;
  int singers =20;

  string userInput;

  while( questionDemonstrate==true){
 
    librarian_menu();

    realm_os_user_input(userInput);
    cout << endl;

    if (userInput=="1"){
       realm_sw_variable_primer(songCount, mrTsaysRead, singers);
    }

    else if (userInput=="2"){
      mrTsaysRead=true;
    }

    else if (userInput=="3"){  
      cout << endl << "Enter the Number of Songs(Cycles) per Dance(primeCheck): " ;
      realm_os_user_input(userInput);
      songCount=stoi(userInput);
    }



    else if (userInput=="4"){  
      cout << endl << "Enter the Number of Concurrent Prime Dance Threads: " ;
      realm_os_user_input(userInput);
      singers=stoi(userInput);
    }





    else if (userInput=="exit") {
      questionDemonstrate=false;
    }

    else {
      cout << endl << " INVALID ENTRY " << endl<< endl;
    }

  }
}





















void librarian_menu()
{    
string text_function_name="librarian_menu"; string text_post = "";






text_post = " (1)  BEGIN Prime Count  "; realm_post_client(text_function_name, text_post );
text_post = " (2)  LOAD PrimeBook.bin : Create MILESTONES of Total Current & Previous Primes "; realm_post_client(text_function_name, text_post );
text_post = " (3)  COUNT per thread cycle to evaluate : Default at 767676"; realm_post_client(text_function_name, text_post );
text_post = " (4)  THREADS to concurrently run "; realm_post_client(text_function_name, text_post );
text_post = "  Please enter a Librarian Task (type exit to exit):  "; realm_post_client(text_function_name, text_post );



























































}

void library()
{
string text_function_name="library"; string text_post = "";
text_post = " ENTER TEXT HERE "; realm_post_client(text_function_name, text_post );





text_post = "FUNCTION   library   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void library_letter()
{
string text_function_name="library_letter"; string text_post = "";



librarian_functions();


text_post = "FUNCTION   library_letter   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void library_time()
{
string text_function_name="library_time"; string text_post = "";






text_post = "FUNCTION   library_time   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void librarian()
{
string text_function_name="librarian"; string text_post = "";


library();
library_time();
library_letter();

text_post = "FUNCTION   librarian   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}




void realm_gl_querry()
{


// realm_gl_webgl();
// realm_gl_opengl();
// realm_gl_vulkan();
// realm_gl_metal();
// realm_gl_directx();

// realm_gl_cores_zeluda();

// realm_gl_cores_gpufort();


std::vector<DISPLAY_DEVICE> gpus = realm_gl_winGpus();

    if (gpus.empty())
    {
        std::cout << "No GPUs found." << std::endl;
    }
    else
    {
        std::cout << "Available GPUs:" << std::endl;
        for (const DISPLAY_DEVICE& gpu : gpus)
        {
            std::cout << "  " << gpu.DeviceString << std::endl;
        }
    }







{
    std::vector<DISPLAY_DEVICE> gpus2 =  realm_gl_cores_cuda();

    if (gpus2.empty())
    {
        std::cout << "No GPUs found." << std::endl;
    }
    else
    {
        std::cout << "Available GPUs:" << std::endl;
        for (size_t i = 0; i < gpus2.size(); ++i)
        {
            std::cout << "  " << gpus2[i].DeviceString << std::endl;
            realm_gl_cuda_devices(i);
        }
    }


}

}























































































void realm_gl_webgl()
{
string text_function_name="realm_gl_webgl"; string text_post = "";






text_post = "FUNCTION   realm_gl_webgl   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void realm_gl_vulkan()
{
string text_function_name="realm_gl_vulkan"; string text_post = "";






text_post = "FUNCTION   realm_gl_vulkan   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void realm_gl_opengl()
{
string text_function_name="realm_gl_opengl"; string text_post = "";






text_post = "FUNCTION   realm_gl_opengl   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void realm_gl_metal()
{
string text_function_name="realm_gl_metal"; string text_post = "";






text_post = "FUNCTION   realm_gl_metal   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void realm_gl_directx()
{
string text_function_name="realm_gl_directx"; string text_post = "";






text_post = "FUNCTION   realm_gl_directx   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void realm_gl_cores_zeluda()
{
string text_function_name="realm_gl_cores_zeluda"; string text_post = "";






text_post = "FUNCTION   realm_gl_cores_zeluda   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}




vector<DISPLAY_DEVICE> realm_gl_cores_cuda()
{






    std::vector<DISPLAY_DEVICE> gpus;
    DISPLAY_DEVICE displayDevice = { 0 };
    displayDevice.cb = sizeof(DISPLAY_DEVICE);

    for (DWORD i = 0; EnumDisplayDevices(nullptr, i, &displayDevice, 0); ++i)
    {
        if (!(displayDevice.StateFlags & DISPLAY_DEVICE_MIRRORING_DRIVER))
        {
            DISPLAY_DEVICE gpu = { 0 };
            gpu.cb = sizeof(DISPLAY_DEVICE);

            if (EnumDisplayDevices(displayDevice.DeviceName, 0, &gpu, 0))
            {
                if ((gpu.StateFlags & DISPLAY_DEVICE_ACTIVE) && (gpu.StateFlags & DISPLAY_DEVICE_ATTACHED_TO_DESKTOP))
                {
                    gpus.push_back(gpu);
                }
            }
        }
    }

    return gpus;
}

















































































































void realm_gl_cores_gpufort()
{
string text_function_name="realm_gl_cores_gpufort"; string text_post = "";






text_post = "FUNCTION   realm_gl_cores_gpufort   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}




vector<DISPLAY_DEVICE> realm_gl_winGpus()



{

    std::vector<DISPLAY_DEVICE> gpus;
    DISPLAY_DEVICE displayDevice = { 0 };
    displayDevice.cb = sizeof(DISPLAY_DEVICE);

    for (DWORD i = 0; EnumDisplayDevices(nullptr, i, &displayDevice, 0); ++i)
    {
        if (!(displayDevice.StateFlags & DISPLAY_DEVICE_MIRRORING_DRIVER))
        {
            DISPLAY_DEVICE gpu = { 0 };
            gpu.cb = sizeof(DISPLAY_DEVICE);

            if (EnumDisplayDevices(displayDevice.DeviceName, 0, &gpu, 0))
            {
                if ((gpu.StateFlags & DISPLAY_DEVICE_ACTIVE) && (gpu.StateFlags & DISPLAY_DEVICE_ATTACHED_TO_DESKTOP))
                {
                    gpus.push_back(gpu);
                }
            }
        }
    }







    return gpus;
}














































































































void realm_gl_cuda_devices(int gpuIndex)
{




    cudaDeviceProp deviceProp;
    cudaError_t error = cudaGetDeviceProperties(&deviceProp, gpuIndex);
    if (error != cudaSuccess)
    {
        std::cerr << "Error querying CUDA device properties: " << cudaGetErrorString(error) << std::endl;
        return;
    }

    std::cout << "  CUDA Devices for GPU " << gpuIndex << ":" << std::endl;
    std::cout << "    Device name: " << deviceProp.name << std::endl;
    std::cout << "    Compute capability: " << deviceProp.major << "." << deviceProp.minor << std::endl;
    std::cout << "    Total global memory: " << (deviceProp.totalGlobalMem / 1024.0 / 1024.0) << " MB" << std::endl;
}




























































































































;
