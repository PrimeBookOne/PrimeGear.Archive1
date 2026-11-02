
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
#include <Windows.h>
#include <winternl.h>
#include <winsock2.h> 
#include <ws2tcpip.h>
#include <comdef.h>
#include <Wbemidl.h>
#include <TlHelp32.h>
#pragma comment(lib, "wbemuuid.lib")
#pragma comment(lib, "ws2_32.lib")
#include <ws2tcpip.h>
#include <Iptypes.h>
#include <Mstcpip.h>
#include <iphlpapi.h>
#pragma comment(lib, "iphlpapi.lib")



#ifndef _WIN32_WINNT
    #define _WIN32_WINNT 0x0600
#elif _WIN32_WINNT < 0x0600
    #undef _WIN32_WINNT
    #define _WIN32_WINNT 0x0600
#endif



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
__int128 gSingers = 16;
__int128 perThreadSlices = 7000000;
__int128* globalUpdatesArrayTotals = new __int128[ gSingers ];
  mutex globalUpdatesArrayTotalsMutex;
int_fast16_t* globalUpdatesArray = new int_fast16_t[ perThreadSlices* gSingers ];
  mutex globalUpdatesArrayMutex;
////////////////// GLOBAL

__int128 maximum__int128  = 9999999999999999999;




typedef struct _SYSTEM_HANDLE
{
    ULONG ProcessId;
    BYTE ObjectTypeNumber;
    BYTE Flags;
    USHORT Handle;
    PVOID Object;
    ACCESS_MASK GrantedAccess;
} SYSTEM_HANDLE, *PSYSTEM_HANDLE;

const int ARRAY_SIZE = 1024 * 1024 / sizeof(int); // array size in bytes

const int BUFFER_SIZE = 1024 * 1024; // 1MB
const int PORT = 54000; // Port number for the connection


typedef NTSTATUS(NTAPI* PNT_QUERY_SYSTEM_INFORMATION)(
    SYSTEM_INFORMATION_CLASS SystemInformationClass,
    PVOID SystemInformation,
    ULONG SystemInformationLength,
    PULONG ReturnLength
);




















































































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
void realm_conduit(char conduitType);

void realm_conduit_adapter();
void realm_conduits_ring(int ring);
void realm_conduit_tree(int a,int b, int c, int d);
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
void realm_gpu_primer();

void realm_conduit_tree(int a,int b, int c, int d);
void realm_gl_cuda_querry();
void realm_win_handles_process();
void realm_win_handles_file();
void realm_win_handles_file2();
void realm_win_handles_sockets();
void realm_win_handles_events();
void realm_win_handles_mutex();
void realm_win_save_state();
void realm_os_windows();
void realm_win_host();
void realm_win_host_send_data();
void realm_win_updater( string remoteHostIPv4 );
void realm_win_handles_thread();
bool realm_win_port_check( string checkPort );
void realm_os_tcp_host( );
void realm_os_tcp_guest( string remoteHostIPv4 );


class realm_conduit_win64Class
{


private: 
string text_function_name=""; string text_post = "";
string querryNet;
public:

void NET(){
system("ipconfig /all");




}
void WALL(){
text_post = "  WALL()  "; realm_post_client(text_function_name, text_post );

}
void DOOR(){
text_post = "  DOOR()  "; realm_post_client(text_function_name, text_post );

}

void IP(int newIP){
text_post = "  IP(newIP) "; realm_post_client(text_function_name, text_post );

}

void PORTS(){
text_post = "  PORTS()  "; realm_post_client(text_function_name, text_post );

}

void DHCP(){
text_post = "  DHCP()  "; realm_post_client(text_function_name, text_post );

}

void IPCONFIG(){
text_post = "  IPCONFIG()  "; realm_post_client(text_function_name, text_post );

}






};
























class primeScribeClass
{
public:
bool pen16(int_fast16_t data){
if ( data <= 15){ primeBook << hex << data; }
if ( data > 15 && data < 256){ primeBook << endl << hex << data; lineCount++;}
if ( data > 255) {primeBook << endl << "0" << hex << data; lineCount++; }
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

primeCobbleStones.open("cobblestones.txt", fstream::in | fstream::out | fstream::app);
primeMileStones.open("primemilestones.txt", fstream::in | fstream::out | fstream::app);

while(singerDigitFind > 9){
  singerDigitFind =singerDigitFind /10;
  singerDigitSize++;
}

digitDifferences= singersDigitSize - singerDigitSize;
if (digitDifferences > 0){
  for (int i =0; i< digitDifferences; i++){ digitDifferencesString=digitDifferencesString+"0";}
}
if(singersDigitSize==0){
  primeBook.open("primeBook.bin",
  fstream::in | fstream::out | fstream::app);
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

void read(){   // READ primeBook

globalUpdatesArrayMutex.lock();



  char primeBookInputChar1;   char primeBookInputChar2;   char primeBookInputChar3;
int differenceInt=0;
__int128 previousPrime=0;  __int128 primeBuild=0;
  bool mrTsaysRead=true;
  while (mrTsaysRead==true){
    primeBook >> primeBookInputChar1 ;
         if (primeBook.eof() ){ cout << "totalPrimes Read: "<< int(totalPrimes)<< endl; mrTsaysRead=false; } 
    if (primeBookInputChar1=='\n'){
       primeBook >> primeBookInputChar2 ;
         if (primeBook.eof() ){ cout << "totalPrimes Read: "<< int(totalPrimes)<< endl; mrTsaysRead=false; } 

       if (primeBookInputChar2 =='\n'){
         primeBook >> primeBookInputChar3 ;
         if (primeBook.eof()){ cout << "totalPrimes Read: "<< int (totalPrimes)<< endl; mrTsaysRead=false; } 
         differenceInt=stoul(to_string(primeBookInputChar1 + primeBookInputChar2 + primeBookInputChar3));
       }
     else{
       differenceInt= stoul(to_string(primeBookInputChar1 + primeBookInputChar2));
     }
}
   else{
     differenceInt=stoul(to_string(primeBookInputChar1));
  }
previousPrime=primeBuild;  
 primeBuild+=differenceInt;




  totalPrimes++;

globalUpdatesArray[totalPrimes] = differenceInt;






if (differenceInt > pDlarge) {
     pDlarge=differenceInt;
 //    primemilestones <<   "totalPrimes: " <<  int(totalPrimes) << "," ;
    // primemilestones <<  " CurrentPrime: " << int( primeBuild )<< ",";
   //  primemilestones <<  "  LargestPrimeDifference  Div2: "<<  pDlarge << endl;
}



globalUpdatesArrayMutex.unlock();


}


}

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
__int128 pDlarge =3;
__int128 totalPrimes =3;
};







class string128Class
{
private:
    __int128 number;
    string result;

    void convert() {
        if (number == 0) {
            result = "0";
            return;
        }

        bool isNegative = false;

        if (number < 0) {
            isNegative = true;
            number = -number;
        }

        while (number > 0) {
            int digit = number % 10;
            result.insert(result.begin(), static_cast<char>('0' + digit));
            number /= 10;
        }

        if (isNegative)
            result.insert(result.begin(), '-');
    }

public:
    string128Class(__int128 num) : number(num) {
        convert();
    }

    string getString() {
        return result;
    }
};










































































































int main()
{
string text_function_name="main"; string text_post = "";
// realm_gl_querry();
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


const auto realm_thread_count = thread::hardware_concurrency();
text_post = "Realm OS CPU Thread Count "; realm_post_client(text_function_name, text_post );
text_post = to_string(realm_thread_count);realm_post_client(text_function_name, text_post );

text_post = "FUNCTION   realm_multi_core   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}




void realm_gpu_primer()
{

































































































































































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
int stringLength = 35 - input_text_function_name.size();

cout <<  setw(stringLength) << "  " << input_text_function_name  << " :  " << input_text << endl;






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
singers=gSingers;

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

cout << "CHECK FOR GYROGEARUPDATE APP" << endl;
cout << "IF GYROGEARUPDATE APP RUNNING COPY ARRAY IN MEMORY TO GYROGEARUPDATE" << endl;
cout << "CLOSE DELETE GYROGEAR COPY GYROGEARUPDATE TO GYROGEAREXE LOAD AND PASS GYROGEARUPDATE ARRAY TO GYROGEAR" << endl;
cout << "CLOSE DELETE GYROGEAR UPDATE" << endl;

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







text_post = "FUNCTION   realm_conduits   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}





























































void realm_conduit_weaver()
{
string text_function_name="realm_conduit_weaver"; string text_post = "";
char defaultConduit; int ring; int one; int two; int three; int four;
realm_conduit(defaultConduit);

realm_conduit_tree(one, two, three, four);
realm_conduits_ring(ring);

realm_conduit(ring);





// text_post = "FUNCTION   realm_conduit_weaver   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}













void realm_conduit(char conduitType)
{
string text_function_name="realm_conduit"; string text_post = "";

text_post = "   Win64 Conduits Initiated  = 1"; realm_post_client(text_function_name, text_post );





text_post = "FUNCTION   realm_conduit   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}





// create link between two threads within same OS























































void realm_conduit_adapter()
{
string text_function_name="realm_conduit_adapter"; string text_post = "";
realm_conduit_win64Class adapter0;








text_post = " QUERRY NETWORK"; realm_post_client(text_function_name, text_post );
adapter0.NET();


text_post = " QUERRY FIREWALL"; realm_post_client(text_function_name, text_post );
adapter0.WALL();


text_post = " OPEN FIREWALL CONDUIT"; realm_post_client(text_function_name, text_post );
adapter0.DOOR();

int newIP;
text_post = " SET NETWORK ADDRESS "; realm_post_client(text_function_name, text_post );
adapter0.IP(newIP); // newdns // new lots 


text_post = " OPEN CONDUIT NETWORK PORTS "; realm_post_client(text_function_name, text_post );
adapter0.PORTS();


text_post = " RENEW IP DHCP "; realm_post_client(text_function_name, text_post );
adapter0.DHCP();


text_post = " SEND IPCONFIG COMMAND "; realm_post_client(text_function_name, text_post );
adapter0.IPCONFIG();











text_post = "FUNCTION      HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}






















void realm_conduits_ring(int ring)
{
string text_function_name="realm_conduits_ring"; string text_post = "";

text_post = "  CONNECTED TO GYRO IPV4:     IPV6:   "; realm_post_client(text_function_name, text_post );

text_post = "ASSIGN ADAPTER CONDUITS"; realm_post_client(text_function_name, text_post );

text_post = " ASSIGN RING OF CONDUITS"; realm_post_client(text_function_name, text_post );

text_post = "FUNCTION      HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );
}






























































void realm_conduit_tree(int a,int b, int c, int d)
{
string text_function_name="realm_conduit_tree"; string text_post = "";
text_post = " PRIME ONE INTERNET CONNECTION  UNDER CONSTRUCTION  "; realm_post_client(text_function_name, text_post );
text_post = "  PRIME ONE LOCAL CONNECTION   "; realm_post_client(text_function_name, text_post );
text_post = " ENTER GYRO IPV4 ADDRESS "; realm_post_client(text_function_name, text_post );

text_post = " ASSIGN RING OF CONDUITS"; realm_post_client(text_function_name, text_post );

text_post = "FUNCTION   realm_conduit_tree   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}































































void librarian_functions()
{    
string text_function_name="librarian_functions"; string text_post = "";



  bool mrTsaysRead=false;  bool runForever=true;
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
     // Display Current Network Information
    }


    else if (userInput=="4"){  
    // User Input IP Address of LAN
    system(" ipconfig /all | findstr /r /c:\"IPv4\"");
    system(" ipconfig /all | findstr /r /c:\"IPv6\"");
    }

    else if (userInput=="5"){  
    // Change existing Network Configurations
    }

    else if (userInput=="6"){  
    // Change existing Network Configurations
    }

    else if (userInput=="7"){  
    // Sign Into Live Work Schedule
    }
    else if (userInput=="8"){  
    // Windows OS Handles
    realm_os_windows();
    }

    else if (userInput=="9"){  
    // Windows NETWORK HOST
    realm_win_host();
    }

    else if (userInput=="10"){  
    // Windows NETWORK UPDATER




realm_win_updater( userInput );


}
    else if (userInput=="11"){  
// Windows CHECK PORT

text_post = "  Please Enter Port to Check (enter for default) :  "; realm_post_client(text_function_name, text_post );
//  realm_os_user_input( userInput );
userInput = "";


if( realm_win_port_check( userInput ) ){

cout << "Port is in use " << endl;
}
else{
cout << "Port is available" << endl;
}



}

    else if (userInput=="12"){  
    // Windows TCP HOST
    realm_os_tcp_host();
    }


    else if (userInput=="13"){  
    // Windows TCP Guest
    realm_os_tcp_guest( userInput );
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
cout<< "                                      ";
system(" ipconfig | findstr /r /c:\"IPv4\"");
cout<< "                                      ";
system(" ipconfig | findstr /r /c:\"IPv6\"");
cout<< "                                      ";
system(" ipconfig /all | findstr /r /c:\"IPv4\"");
cout<< "                                      ";
system(" ipconfig /all | findstr /r /c:\"IPv6\"");














cout << "\033[10;1H";
text_post = "  Current Windows Memory Shared Location: "; realm_post_client(text_function_name, text_post );
text_post = "  (1)  LOAD PrimeBook.bin OLD : Create MILESTONES COBBLESTONES "; realm_post_client(text_function_name, text_post );
text_post = "  (2)  LOAD PrimeBook.bin NEW : Create MILESTONES COBBLESTONES "; realm_post_client(text_function_name, text_post );
text_post = "  (3)  NETWORK Information "; realm_post_client(text_function_name, text_post );
text_post = "  (4)  NETWORK Join "; realm_post_client(text_function_name, text_post );
text_post = "  (5)  NETWORK CONDUITS SETUP"; realm_post_client(text_function_name, text_post );
text_post = "  (6)  NETWORK PRIMEBOOK BALANCE "; realm_post_client(text_function_name, text_post );
text_post = "  (7)  NETWORK BEGIN WORK"; realm_post_client(text_function_name, text_post );
text_post = "  (8)  WINDOWS HANDLES Information"; realm_post_client(text_function_name, text_post );
text_post = "  (9)  NETWORK      "; realm_post_client(text_function_name, text_post );
text_post = " (10)  NETWORK UPDATER 127.0.0.1"; realm_post_client(text_function_name, text_post );
text_post = " (11)  Port Check "; realm_post_client(text_function_name, text_post );
text_post = " (12)           "; realm_post_client(text_function_name, text_post );
text_post = " (13)         "; realm_post_client(text_function_name, text_post );

text_post = "  Please enter a Librarian Task (type exit to exit):  "; realm_post_client(text_function_name, text_post );

cout.flush();





























}

void library()
{
string text_function_name="library"; string text_post = "";
text_post = " ENTER TEXT HERE "; realm_post_client(text_function_name, text_post );




/*
text_post = "FUNCTION   library   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );
*/
}



void library_letter()
{
string text_function_name="library_letter"; string text_post = "";






// text_post = "FUNCTION   library_letter   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void library_time()
{
string text_function_name="library_time"; string text_post = "";





/*
// text_post = "FUNCTION   library_time   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );
*/
}



void librarian()
{
string text_function_name="librarian"; string text_post = "";






librarian_functions();






text_post = "FUNCTION      HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}
























































void realm_gl_querry()
{

realm_gl_cuda_querry();
// realm_gl_webgl();
// realm_gl_opengl();
// realm_gl_vulkan();
// realm_gl_metal();
// realm_gl_directx();

// realm_gl_cores_zeluda();

// realm_gl_cores_gpufort();







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






    vector<DISPLAY_DEVICE> gpus;
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

    vector<DISPLAY_DEVICE> gpus;
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
string text_function_name="realm_gl_cuda_devices"; string text_post = "";



    cudaDeviceProp deviceProp;
    cudaError_t error = cudaGetDeviceProperties(&deviceProp, gpuIndex);
    if (error != cudaSuccess)   {
     text_post= "Error querying CUDA device properties: ";
     realm_post_client(text_function_name, text_post );
        cerr << "              realm_gl_cuda_devices :   "  << cudaGetErrorString(error) << endl;
        return;
    }
   text_post= "CUDA Devices for GPU " + to_string(gpuIndex) + ":" ;
string propName=deviceProp.name;
     realm_post_client(text_function_name, text_post );
   text_post= "Device name: " + propName; 

     realm_post_client(text_function_name, text_post );
   text_post= "Compute capability: " + to_string(deviceProp.major) +  "." + to_string(deviceProp.minor);


     realm_post_client(text_function_name, text_post );
   text_post= "Total global memory: " + to_string((deviceProp.totalGlobalMem / 1024.0 / 1024.0)) + " MB" ;

     realm_post_client(text_function_name, text_post );
}



















































































































;

void realm_gl_cuda_querry()
{
string text_function_name="realm_gl_cuda_querry"; string text_post = "";

string countString;
int count=0;

vector<DISPLAY_DEVICE> gpus = realm_gl_winGpus();

   if (gpus.empty())
    {
text_post = "No GPUs found.";
     realm_post_client(text_function_name, text_post );
    }
    else
    {
text_post = "Available GPUs:";
     realm_post_client(text_function_name, text_post );

        for (const DISPLAY_DEVICE& gpu : gpus)
        {

       text_post = "GPU # " + to_string(int(count)) + " : " + gpu.DeviceString + "  |  ";
     realm_post_client(text_function_name, text_post );
          count++;
        }
    }

cout  << " - - - - - - - - - - - - - - " << endl;
system("nvidia-smi base-clocks");
cout  << " - - - - - - - - - - - - - - " << endl;
system("wmic /namespace:\\root\wmi PATH MSAcpi_ThermalZoneTemperature get CurrentTemperature");
cout  << " - - - - - - - - - - - - - - " << endl;


{
    vector<DISPLAY_DEVICE> gpus2 =  realm_gl_cores_cuda();
    if (gpus2.empty())
    {
text_post = "No GPUs found.";
     realm_post_client(text_function_name, text_post );
    }
    else
    {
text_post = "Available GPUs: ";
     realm_post_client(text_function_name, text_post );
        for (size_t i = 0; i < gpus2.size(); ++i)
        {
text_post =  gpus2[i].DeviceString;
     realm_post_client(text_function_name, text_post );
            realm_gl_cuda_devices(i);
        }
    }
}



    // Get number of available CUDA devices
    int deviceCount;
    cudaGetDeviceCount(&deviceCount);
    text_post = "Number of CUDA devices: " + to_string(deviceCount);
     realm_post_client(text_function_name, text_post );
    // Query each device for its maximum number of threads per block
    for (int i = 0; i < deviceCount; ++i) {
        cudaDeviceProp prop;
        cudaGetDeviceProperties(&prop, i);
text_post ="Device " + to_string(i) + " - " + prop.name;
     realm_post_client(text_function_name, text_post );
text_post= "Compute capability: " + to_string(prop.major) + "." + to_string(prop.minor) ;
     realm_post_client(text_function_name, text_post );
text_post = "Clock rate: " + to_string(prop.clockRate) + " kHz" ;
     realm_post_client(text_function_name, text_post );
text_post =(prop.deviceOverlap ? "Enabled" : "Disabled"); text_post = "Device copy overlap: " + text_post ;
     realm_post_client(text_function_name, text_post );
text_post = (prop.kernelExecTimeoutEnabled ? "Enabled" : "Disabled") ; text_post = "Kernel execution timeout: " + text_post ;
     realm_post_client(text_function_name, text_post );
text_post = "Memory clock rate: " + to_string(prop.memoryClockRate) + " kHz" ;
     realm_post_client(text_function_name, text_post );
text_post = "Memory bus width: " + to_string(prop.memoryBusWidth) + " bits" ;
     realm_post_client(text_function_name, text_post );
text_post = "Total global memory: " + to_string(prop.totalGlobalMem / (1024.0 * 1024.0)) + " MB" ;
     realm_post_client(text_function_name, text_post );
text_post = "Total constant memory: " + to_string(prop.totalConstMem) + " bytes" ;
     realm_post_client(text_function_name, text_post );
text_post = "Multiprocessor count: " + to_string(prop.multiProcessorCount) ;
     realm_post_client(text_function_name, text_post );
text_post = "Number of FP32 Cores: " + to_string(prop.multiProcessorCount * 128) ;
     realm_post_client(text_function_name, text_post );
text_post = "Threads per Multiprocessor: " + to_string(prop.maxThreadsPerMultiProcessor) ;
     realm_post_client(text_function_name, text_post );
text_post = "Maximum Threads per Block: " +to_string( prop.maxThreadsPerBlock) ;
     realm_post_client(text_function_name, text_post );
text_post = "Maximum Threads per SM: Total Parallel Threads: " + to_string(prop.maxThreadsPerMultiProcessor * prop.multiProcessorCount) ;
     realm_post_client(text_function_name, text_post );
text_post = "Max threads dimensions: (" + to_string(prop.maxThreadsDim[0]) + ", " + to_string(prop.maxThreadsDim[1]) + ", " + to_string(prop.maxThreadsDim[2]) + ")" ;
     realm_post_client(text_function_name, text_post );
                  
                  
__int128 threadsPerBlock=  prop.maxThreadsPerBlock;
__int128 x = prop.maxGridSize[0];
__int128 y = prop.maxGridSize[1];
__int128 z = prop.maxGridSize[2];
__int128 totalBlocks = x * y * z;
__int128 totalThreads = totalBlocks * threadsPerBlock;
string128Class convertTotalBlocks(totalBlocks);
string totalBlocksString = convertTotalBlocks.getString();
string128Class convertTotalThreads(totalThreads);
string totalThreadsString = convertTotalThreads.getString();


text_post = "Max grid size: (" + to_string(int(x)) + ", " + to_string(int(y)) + ", " + to_string(int(z)) + ")"  ;
     realm_post_client(text_function_name, text_post );

text_post = "Total Available Blocks = " +totalBlocksString;
     realm_post_client(text_function_name, text_post );
text_post = "Total Available Threads = " + totalThreadsString ;
     realm_post_client(text_function_name, text_post );



    }

}




















;

void realm_win_host()
{
string text_function_name="realm_win_host"; string text_post = "";
bool yesContinue=true;



if (yesContinue){ //void ListProcessHandles()


if (yesContinue){ // int main()

    WSADATA wsa_data;
    int error = WSAStartup(MAKEWORD(2, 2), &wsa_data);
    if (error != 0)
    {
        std::cerr << "WSAStartup() failed: " << error << std::endl;
      //  return -1;
    }

    // Create the socket
    SOCKET listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listen_socket == INVALID_SOCKET)
    {
        std::cerr << "socket() failed: " << WSAGetLastError() << std::endl;
        WSACleanup();
       // return -1;
    }

    // Bind the socket to a port
    sockaddr_in address = {};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(8080);
    error = bind(listen_socket, (SOCKADDR*)&address, sizeof(address));
    if (error == SOCKET_ERROR)
    {
        std::cerr << "bind() failed: " << WSAGetLastError() << std::endl;
        closesocket(listen_socket);
        WSACleanup();
     //   return -1;
    }

    // Listen for incoming connections
    error = listen(listen_socket, SOMAXCONN);
    if (error == SOCKET_ERROR)
    {
        std::cerr << "listen() failed: " << WSAGetLastError() << std::endl;
        closesocket(listen_socket);
        WSACleanup();
   //     return -1;
    }

    std::cout << "waiting for guest connection..." << std::endl;

    // Accept the guest connection
    SOCKET guest_socket = accept(listen_socket, NULL, NULL);
    if (guest_socket == INVALID_SOCKET)
    {
        std::cerr << "accept() failed: " << WSAGetLastError() << std::endl;
        closesocket(listen_socket);

}


}


}


}


















































































































































































































































void realm_os_windows()
{
string text_function_name="realm_os_windows"; string text_post = "";

cout << "windows handles" << endl;
 realm_win_handles_process();
 realm_win_handles_thread();
 realm_win_handles_file();
 realm_win_handles_file2();
 realm_win_handles_sockets();
 realm_win_handles_events();
 realm_win_handles_mutex();
 realm_win_save_state();

}

void realm_win_handles_process()
{
string text_function_name="realm_win_handles_process"; string text_post = "";
bool yesContinue=true;



if (yesContinue){ //void ListProcessHandles()

    DWORD processId = GetCurrentProcessId();
    HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);

    if (processHandle != NULL)
    {
        std::cout << "Process Handle: " << processHandle << std::endl;
        CloseHandle(processHandle);
    }
}

























}















































































































































































































































































void realm_win_handles_file()
{
string text_function_name="realm_win_handles_file"; string text_post = "";

bool yesContinue=false;







if (yesContinue){ // void ListFileHandles()
/*
    HRESULT hres;

    // Step 1: Initialize COM
//    hres = CoInitializeEx(0, COINIT_MULTITHREADED);
    if (FAILED(hres))
    {
        std::cout << "Failed to initialize COM." << std::endl;
        return;
    }

    // Step 2: Initialize WMI
    hres = CoInitializeSecurity(
        NULL,
        -1,
        NULL,
        NULL,
        RPC_C_AUTHN_LEVEL_DEFAULT,
        RPC_C_IMP_LEVEL_IMPERSONATE,
        NULL,
        EOAC_NONE,
        NULL);

    if (FAILED(hres))
    {
        CoUninitialize();
        std::cout << "Failed to initialize WMI security." << std::endl;
        return;
    }

    // Step 3: Obtain the initial locator to WMI
    IWbemLocator* pLoc = NULL;
    hres = CoCreateInstance(
        CLSID_WbemLocator,
        0,
        CLSCTX_INPROC_SERVER,
        IID_IWbemLocator,
        (LPVOID*)&pLoc);

    if (FAILED(hres))
    {
        CoUninitialize();
        std::cout << "Failed to create WbemLocator instance." << std::endl;
        return;
    }

    // Step 4: Connect to WMI through the IWbemLocator::ConnectServer method
    IWbemServices* pSvc = NULL;
    hres = pLoc->ConnectServer(
        _bstr_t(L"ROOT\\CIMV2"),
        NULL,
        NULL,
        0,
        NULL,
        0,
        0,
        &pSvc);

    if (FAILED(hres))
    {
        pLoc->Release();
        CoUninitialize();
        std::cout << "Failed to connect to WMI." << std::endl;
        return;
    }

    // Step 5: Set the security levels on the proxy
    hres = CoSetProxyBlanket(
        pSvc,
        RPC_C_AUTHN_WINNT,
        RPC_C_AUTHZ_NONE,
        NULL,
        RPC_C_AUTHN_LEVEL_CALL,
        RPC_C_IMP_LEVEL_IMPERSONATE,
        NULL,
        EOAC_NONE);

    if (FAILED(hres))
    {
        pSvc->Release();
        pLoc->Release();
        CoUninitialize();
        std::cout << "Failed to set proxy blanket." << std::endl;
        return;
    }

    // Step 6: Use the IWbemServices pointer to make requests of WMI
    IEnumWbemClassObject* pEnumerator = NULL;
    hres = pSvc->ExecQuery(
        bstr_t("WQL"),
        bstr_t("SELECT * FROM Win32_Process"),
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
        NULL,
        &pEnumerator);

    if (FAILED(hres))
    {
        pSvc->Release();
        pLoc->Release();
        CoUninitialize();
        std::cout << "Failed to execute WMI query." << std::endl;
        return;
    }

    // Step 7: Retrieve the data from the query result
  //  IWb



*/
}
}






























































































































































































void realm_win_handles_file2()
{
string text_function_name="realm_win_handles_file2"; string text_post = "";






//BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)

    // Process or store the window handle as needed
  //  std::cout << "Window Handle: " << hwnd << std::endl;






 //   if (!EnumWindows(EnumWindowsProc, 0))

     //   std::cout << "Failed to enumerate window handles." << std::endl;

}



































































































































































































































































































void realm_win_handles_sockets()
{
string text_function_name="realm_win_handles_sockets"; string text_post = "";

bool yesContinue=false;






if (yesContinue){ // void ListSocketHandles()
/*
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cout << "Failed to initialize Winsock." << std::endl;
        return;
    }

    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET)
    {
        std::cout << "Failed to create socket." << std::endl;
        WSACleanup();
        return;
    }

    // Use the socket handle 's' to perform operations as needed

    // Example: Enumerate socket handles
    WSANETWORKEVENTS networkEvents;
    if (WSAEnumNetworkEvents(s, NULL, &networkEvents) != SOCKET_ERROR)
    {
      //  for (int i = 0; i < networkEvents.iTotalHandles; ++i)
        {
     //       SOCKET socketHandle = networkEvents.hEventObject[i];
    //        std::cout << "Socket Handle: " << socketHandle << std::endl;
        }
    }

    // Clean up
    closesocket(s);
    WSACleanup();

*/
}
}











































































































































































































































































void realm_win_handles_events()
{
string text_function_name="realm_win_handles_events"; string text_post = "";

bool yesContinue=false;





















































































}
































































































































































































































void realm_win_handles_mutex()
{
string text_function_name="realm_win_handles_mutex"; string text_post = "";

bool yesContinue=false;




















































































}

































































































































































































































void realm_win_save_state()
{
string text_function_name="realm_win_save_state"; string text_post = "";

bool yesContinue=false;
string fileName="winSave.Mem";



// Function to save memory state to a file
if (yesContinue){ // void SaveMemoryState(const std::string& fileName)

    HANDLE processHandle = GetCurrentProcess();

    // Get the minimum and maximum address range of the process memory
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    LPVOID minAddress = systemInfo.lpMinimumApplicationAddress;
    LPVOID maxAddress = systemInfo.lpMaximumApplicationAddress;

    // Calculate the size of the memory region to be saved
    SIZE_T memorySize = static_cast<SIZE_T>(reinterpret_cast<BYTE*>(maxAddress) - reinterpret_cast<BYTE*>(minAddress));

    // Create a file for writing memory state
    std::ofstream outFile(fileName, std::ios::binary);
    if (!outFile)
    {
        std::cerr << "Failed to create the output file." << std::endl;
        return;
    }

    // Read the memory state of the process and write it to the file
    if (!WriteProcessMemory(processHandle, minAddress, minAddress, memorySize, nullptr))
    {
        std::cerr << "Failed to save the memory state." << std::endl;
        outFile.close();
        return;
    }

    outFile.write(reinterpret_cast<const char*>(minAddress), memorySize);
    outFile.close();

    std::cout << "Memory state saved to file: " << fileName << std::endl;
}

}













































































































































































































































































void realm_win_host_send_data()
{
string text_function_name="realm_win_host_send_data"; string text_post = "";
bool yesContinue=true;












if (yesContinue){ //void send_data(SOCKET socket)
/*
    int* array = new int[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
        array[i] = i;

    while (true)
    {
        // Send the data
        int bytes_sent = send(socket, (char*)array, ARRAY_SIZE * sizeof(int), 0);
        if (bytes_sent == SOCKET_ERROR)
        {
            std::cerr << "send() failed: " << WSAGetLastError() << std::endl;
            break;
        }
        else if (bytes_sent != ARRAY_SIZE * sizeof(int))
        {
            std::cerr << "sent " << bytes_sent << " bytes instead of " << ARRAY_SIZE * sizeof(int) << " bytes" << std::endl;
            break;
        }

        // Wait for the response
        int response;
        int bytes_recv = recv(socket, (char*)&response, sizeof(response), 0);
        if (bytes_recv == SOCKET_ERROR)
        {
            std::cerr << "recv() failed: " << WSAGetLastError() << std::endl;
            break;
        }
        else if (bytes_recv == 0)
        {
            std::cout << "guest disconnected" << std::endl;
            break;
        }

        std::cout << "received response: " << response << std::endl;
    }

    delete[] array;



*/



}

}


























































































































































































































































void realm_win_updater( string remoteHostIPv4 )
{
string text_function_name="realm_win_guest"; string text_post = "";
bool yesContinue=true; bool socketSearch=true; int PORTgrow = PORT; bool sendForever=true;
int ARRAY_SIZE = 1500;  // cout << " ARRAY_SIZE " <<  ARRAY_SIZE << endl;
bool receiveForever=true; int dataSend=0;  bool socketForever=true;  bool printForever=true;


int totalSends=0; int allData=0;
int* array = new int[ARRAY_SIZE];
// cout << "Initialize Winsock" << endl;
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);
    int wsOk = WSAStartup(ver, &wsData);
    if (wsOk != 0){
        cerr << "Can't initialize Winsock! Quitting" << endl;
        return;
    }

// cout << "Create socket" << endl;
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        cerr << "Can't create socket! Quitting" << endl;
        WSACleanup();
        return;
    }
    sockaddr_in hint{};
    hint.sin_family = AF_INET;
    hint.sin_addr.s_addr = inet_addr("127.0.0.1");
    string ipAddress = inet_ntoa(hint.sin_addr);
while (socketForever==true){
while (socketSearch==true){
    hint.sin_port = htons(PORTgrow);
cout << "\033[2;1H";


    cout << "  Port: " << ntohs(hint.sin_port) << endl;
    int bindResult = bind(sock, reinterpret_cast<sockaddr*>(&hint), sizeof(hint));
    if (bindResult != SOCKET_ERROR){
       cout << "  HOST ip :  " << ipAddress << endl;
    }

    if (bindResult == SOCKET_ERROR){
        int errorCode = WSAGetLastError();
            cout << "  HOST remote ip : " << ipAddress<< endl;  cout << "  HOST name : " <<  endl;
            cout << "  GUEST local ip : " << ipAddress<< endl;    cout << "  GUEST name : "<< endl;
            cerr << "  not Host Error code: " << errorCode << endl;
            int connectResult = connect(sock, reinterpret_cast<sockaddr*>(&hint), sizeof(hint));
            if (connectResult == SOCKET_ERROR) {
              std::cerr << "  due to HOST port Unavailable Error code: " << WSAGetLastError() << std::endl;
          //    closesocket(sock);
       //       WSACleanup();
        //      return;
}
cout << "I am GUEST CONNECTED TO HOST" << endl;
std::ofstream copy("copy.zip", std::ios::binary);

while(printForever==true){
// ***** SEND ZIP FILE HERE ASSISTANCE as either a Vector Array or Integer Array
int received_array[ARRAY_SIZE];
int bytes_received = recv(sock, reinterpret_cast<char*>(received_array), ARRAY_SIZE * sizeof(int), 0);



copy.write(reinterpret_cast<const char*>(received_array), bytes_received);
copy.close();


if (bytes_received == SOCKET_ERROR) {
    std::cerr << "recv() failed: " << WSAGetLastError() << std::endl;
    break;
} else if (bytes_received == 0) {
    std::cout << "Guest disconnected" << std::endl;
    break;
}








cout << "\033[1;1H";
cout << "GUEST totalDataReceives : "<<allData++;
cout.flush();
}
}


   else {socketSearch=false;};
} // (socketSearch==true)
// cout << "Socket Connected Successfully" << endl;

while (PORTgrow == PORT){

// Listen for incoming connections
if (listen(sock, SOMAXCONN) == SOCKET_ERROR){
   cerr << "Can't listen on socket! Quitting" << endl;
   closesocket(sock);
   WSACleanup();
   return;
}

// cout << "Waiting for a connection " << endl; // Accept a client socket
sockaddr_in client{};
int clientSize = sizeof(client);

SOCKET clientSocket = accept(sock, reinterpret_cast<sockaddr*>(&client), &clientSize);
if (clientSocket == INVALID_SOCKET){
   cerr << "Can't accept client Invalid Socket! Quitting" << endl;
   closesocket(sock);
   WSACleanup();
   return;
}

char computerName[MAX_COMPUTERNAME_LENGTH + 1];
DWORD computerNameSize = sizeof(computerName);

char service[NI_MAXSERV];   // Service (i.e., port) the client is connected on
char host[NI_MAXHOST];      // Client's remote name

ZeroMemory(host, NI_MAXHOST);
ZeroMemory(service, NI_MAXSERV);
if (GetComputerName(computerName, &computerNameSize)){
   cout << "  HOST name: " << computerName << endl;

}
else{
   cerr << "Failed to retrieve computer name!" << endl;    //    return 1;
}

// Get information about the client
if (getnameinfo(reinterpret_cast<sockaddr*>(&client), clientSize, host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0){
cout << "  GUEST name : " << host <<endl ;
cout << "  GUEST ip : ??? " << endl ;
cout << "  GUEST port : "  << service << endl ;
cout << "I am HOST CONNECTED TO GUEST" << endl;
}
else{    cout << "Connected on port NTOS " << ntohs(client.sin_port) << " to " << host << endl; }
std::ifstream original("original.zip", std::ios::binary);
std::vector<char> data((std::istreambuf_iterator<char>(original)), std::istreambuf_iterator<char>());
std::vector<int> intData(data.begin(), data.end());

std::cout << "Array size: " << intData.size() << " elements" << std::endl;







while (sendForever ) {
    int remainingData = intData.size() - dataSend;
    int bytesToSend = std::min(remainingData, ARRAY_SIZE);
    int bytes_sent = send(clientSocket, reinterpret_cast<char*>(intData.data()) + dataSend, bytesToSend * sizeof(int), 0);
    if (bytes_sent == SOCKET_ERROR) {
        std::cerr << "send() failed error: " << WSAGetLastError();
        break;
    } else if (bytes_sent <= 0) {
        std::cerr << "Failed to send data" << std::endl;
        break;
    } else {
        cout << "\033[1;1H";
        cout << "HOST totalDataSends: " << totalSends++;
        cout.flush();

        dataSend += bytes_sent / sizeof(int);
    }

    if (dataSend >= intData.size()) {
        break;  // Break out of the loop when all data has been sent
    }
}
}


cout << "SOCKET FOREVER ==TRUE"<< endl;
}

}






































































































































void realm_win_handles_thread()
{
string text_function_name="realm_win_handles_thread"; string text_post = "";
bool yesContinue=true;


if (yesContinue){ // void ListThreadHandles()

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    if (snapshot != INVALID_HANDLE_VALUE)
    {
        THREADENTRY32 threadEntry;
        threadEntry.dwSize = sizeof(threadEntry);
        if (Thread32First(snapshot, &threadEntry))
        {
            do
            {
                if (threadEntry.th32OwnerProcessID == GetCurrentProcessId())
                {
                    HANDLE threadHandle = OpenThread(THREAD_ALL_ACCESS, FALSE, threadEntry.th32ThreadID);
                    std::cout << "Thread Handle: " << threadHandle << std::endl;
                    CloseHandle(threadHandle);
                }
            } while (Thread32Next(snapshot, &threadEntry));
        }

        CloseHandle(snapshot);
    }
}

}




























































































































































































































































































bool realm_win_port_check( string checkPort )
{
string text_function_name="realm_win_port_check"; string text_post = "";
bool yesContinue=true;

int port =54000;






    std::string command = "powershell.exe Test-NetConnection -ComputerName 127.0.0.1 -Port " + std::to_string(port);

    // Execute the PowerShell command and capture the output
    FILE* pipe = _popen(command.c_str(), "r");
    if (!pipe)
    {
        std::cerr << "Failed to execute command: " << command << std::endl;
        return false;
    }

    const int maxBufferSize = 128;
    char buffer[maxBufferSize];
    std::string result;

    while (!feof(pipe))
    {
        if (fgets(buffer, maxBufferSize, pipe) != nullptr)
        {
            result += buffer;
        }
    }

    // Close the pipe
    _pclose(pipe);

    // Check if the port is available
    return (result.find("True") != std::string::npos);
}



















































































































































































































































































void realm_os_tcp_host( )
{
string text_function_name="realm_os_tcp_host"; string text_post = "";
bool yesContinue=true;















    // Initialize Winsock
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);

    int wsOk = WSAStartup(ver, &wsData);
    if (wsOk != 0)
    {
        std::cerr << "Can't initialize Winsock! Quitting" << std::endl;
        return;
    }

    // Create socket
    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == INVALID_SOCKET)
    {
        std::cerr << "Can't create socket! Quitting" << std::endl;
                WSACleanup();
        return;
    }

}



















































































































































































































































































void realm_os_tcp_guest( string remoteHostIPv4 )
{
string text_function_name="realm_os_tcp_guest"; string text_post = "";
bool yesContinue=true;











    // Initialize Winsock
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);

    int wsOk = WSAStartup(ver, &wsData);
    if (wsOk != 0)
    {
        std::cerr << "Can't initialize Winsock! Quitting" << std::endl;
        return;
    }

    // Create socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET)
    {
        std::cerr << "Can't create socket! Quitting" << std::endl;
        WSACleanup();
        return;
    }

    // Connect to the server
    sockaddr_in hint{};
    hint.sin_family = AF_INET;
    hint.sin_port = htons(PORT);
    hint.sin_addr.s_addr = inet_addr(remoteHostIPv4.c_str());

    int connectResult = connect(sock, reinterpret_cast<sockaddr*>(&hint), sizeof(hint));
    if (connectResult == SOCKET_ERROR)
    {
        std::cerr << "Can't connect to the server! Error code: " << WSAGetLastError() << std::endl;
        closesocket(sock);
        WSACleanup();
        return;
    }

    // Prepare the array
    std::vector<int> dataArray = { 1, 2, 3, 4, 5 }; // Modify this array according to your needs

    // Send the array size
    int arraySize = static_cast<int>(dataArray.size());
    int sendResult = send(sock, reinterpret_cast<char*>(&arraySize), sizeof(arraySize), 0);
    if (sendResult == SOCKET_ERROR)
    {
        std::cerr << "Failed to send array size! Error code: " << WSAGetLastError() << std::endl;
        closesocket(sock);
        WSACleanup();
        return;
    }

    // Send the array elements
    sendResult = send(sock, reinterpret_cast<char*>(dataArray.data()), sizeof(int) * arraySize, 0);
    if (sendResult == SOCKET_ERROR)
    {
        std::cerr << "Failed to send array data! Error code: " << WSAGetLastError() << std::endl;
        closesocket(sock);
        WSACleanup();
        return;
    }

    std::cout << "Array fully sent." << std::endl;

    // Clean up
    closesocket(sock);
    WSACleanup();
}










































































































































































































































