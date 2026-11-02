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

#include <filesystem>


























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

  int pDaSize = 776999999;
    // int pDaSize = 5376999999;
  int songRequest=767;
int_fast16_t* primeDifferencesArray = new int_fast16_t[pDaSize];

int singers = 8;
int songs = singers * songRequest;
 bool* songArray = new bool[songs];
















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


void realm_gl_querry(); 
void realm_gl_webgl(); 
void realm_gl_vulkan(); 
void realm_gl_opengl(); 
void realm_gl_metal(); 
void realm_gl_directx(); 
void realm_gl_cores_zeluda(); 
void realm_gl_cores_cuda(); 
void realm_gl_cores_gpufort(); 
void realm_os_menu();
int realm_sw_array_Flexor();
void realm_librarian_theprimes_read(__int128&iWalk,__int128&tPrimes,__int128&Prime1,__int128&prePrime,int&pDlarge,int &primeDifference,fstream&primemilestones,fstream&primebook,fstream&primebookbin,bool mrTsaysRead,bool readAndConvert,int spots);


void realm_sw_variable_primer();
void realm_librarian_primebook_read(__int128& iWalk,__int128&tPrimes,__int128&foundPrime,int &pDlarge,int &primeDifference,fstream&primemilestones,fstream&primebook,fstream&primebookbin,bool mrTsaysRead,int_fast16_t  primeDifferencesArray[], bool readAndConvert);
void realm_sw_divisor_dance(__int128 iWalk,  int songCount, int singers, int singer, int maxArraySize);
void realm_librarian_prime_book(fstream& primemilestones, fstream& primebook, fstream& primebookbin);
void realm_prime_differences(__int128  foundPrime, __int128 & previousPrime, int  & primeDifference );
void realm_os_user_input(string&validUserInput);
void librarian_menu();
void librarian_functions();
void realm_sw_divisor_danced(int singers);
void realm_librarian_primebook_16pen( int  primeDifference, fstream&primebookbin);
void realm_librarian_primebook_miles (int  primeDifference, int  & pDlarge, __int128 foundPrime, __int128 tPrimes, fstream& primemilestones );



















class primeDifferencesClass
{
string text_function_name="primeDifferencesClass"; string text_post = "";



private:
string workingDirectory_c="";
// int_fast16_t* primeDifferencesArray2 = new int_fast16_t[arrayMax];
int requestTotal_c=0;
fstream primebookbin ;
__int128 tPrimes=3;
int arrayMax_c=0;
int pDlarge=0;
int maxRead=200;


public:









int thankYouCanIHaveAnotherPlease(bool beginAgain){
  if (beginAgain==true){
    primebookbin.close(); requestTotal_c=0;
    primebookbin.open("primebook.bin", std::fstream::in | std::fstream::in);
  }

  if(requestTotal_c<arrayMax_c&&maxRead>requestTotal_c){
    requestTotal_c++;
}      //    primeDifferenceArray[requestTotal_c];
else { //    primebookbin << std::hex << primeBookInputInt; }
  }
}

int LoadMeUp(){
  char primeBookBinInputChar1;   char primeBookBinInputChar2;   char primeBookBinInputChar3;
int differenceInt=0;
__int128 previousPrime=0;  __int128 primeBuild=0;
  bool mrTsaysRead=true;
  while (mrTsaysRead==true){
    primebookbin >> primeBookBinInputChar1 ;
         if (primebookbin.eof()|| int(tPrimes)==arrayMax_c ){ cout << "tPrimes Read: "<< int(tPrimes) << " @ arrayMax: " << arrayMax_c << endl; mrTsaysRead=false; } 
    if (primeBookBinInputChar1=='\n'){
       primebookbin >> primeBookBinInputChar2 ;
         if (primebookbin.eof()|| int(tPrimes)==arrayMax_c ){ cout << "tPrimes Read: "<< int(tPrimes) << " @ arrayMax: " << arrayMax_c << endl; mrTsaysRead=false; } 

       if (primeBookBinInputChar2 =='\n'){
         primebookbin >> primeBookBinInputChar3 ;
         if (primebookbin.eof()|| int(tPrimes)== arrayMax_c ){ cout << "tPrimes Read: "<< int (tPrimes) << " @ arrayMax: " << arrayMax_c << endl; mrTsaysRead=false; } 
         differenceInt=stoul(to_string(primeBookBinInputChar1 + primeBookBinInputChar2 + primeBookBinInputChar3));
       }
     else{
       differenceInt= stoul(to_string(primeBookBinInputChar1 + primeBookBinInputChar2));
     }
}
   else{
     differenceInt=stoul(to_string(primeBookBinInputChar1));
  }
previousPrime=primeBuild;   primeBuild+=differenceInt;
  tPrimes++;
 //  primeDifferencesArray2[totalprimes]=differenceInt;
if (differenceInt > pDlarge) {
     pDlarge=differenceInt;
 //    primemilestones <<   "TotalPrimes: " <<  int(totalprimes) << "," ;
    // primemilestones <<  " CurrentPrime: " << int( primeBuild )<< ",";
   //  primemilestones <<  "  LargestPrimeDifference  Div2: "<<  pDlarge << endl;
}









}







  //    primemilestones<< "Total Primes Loaded: "  << int(totalprimes) <<endl;
// cout << "Total Primes Loaded: " << int(totalprimes) << "  infiniteWalk now at: " << int(infiniteWalk) << endl << "Press Enter to Continue " << endl;
// realm_os_user_input(yescontinue);


}

























};






















int main()
{
string text_function_name="main"; string text_post = "";

heartbeat();
gyrocore();
sw_purchase_verify();
realm();
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




int realm_sw_array_Flexor(__int128& arraySizeMax)
{
string text_function_name="realm_sw_array_Flexor"; string text_post = "";
text_post = " ENTER TEXT HERE "; realm_post_client(text_function_name, text_post );
// int_fast16_t* primeDifferencesArray = new int_fast16_t[5376999999];
//int_fast16_t* primeDifferencesArray = new int_fast16_t[76999999];
// bool* songArray = new bool[songRequest];

int boolTestSizeChunks =1000000;
string string128="";
cout << "FLEXFunction " << endl;
int intTestSizeChunks =1000000;
__int128 intTestSizeGrow =intTestSizeChunks;
bool testMemory=true;



while (testMemory==true){
  try{
    int_fast16_t* primeDifferencesArray2 = new int_fast16_t[ intTestSizeGrow ];
    intTestSizeGrow += intTestSizeChunks;
    delete[] primeDifferencesArray2;
















    cout << " " << int(intTestSizeGrow) << "    " << endl;
  }
  catch(...){
    cout << "too large of an Array" << int(intTestSizeGrow) << endl;
    testMemory=false;
   arraySizeMax=intTestSizeGrow - intTestSizeChunks;
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


































































void realm_prime_differences(__int128  foundPrime, __int128 & previousPrime, int  & primeDifference )
{
//="string text_function_name="& CHAR(34)&B2&CHAR(34)&"; string text_post = "& CHAR(34)& CHAR(34)&";"

    __int128 primeDifference128=0;




      primeDifference128=(foundPrime- previousPrime )/2;
      primeDifference = int (primeDifference128);














































//="text_post = " & CHAR(34)&"FUNCTION   "&B2 & "   HAS COMPLETED SUCESSFULLY!"&CHAR(34)&";"&" "&"realm_post_client(text_function_name, text_post );"



}



















































































void realm_sw_divisor_dance(__int128 iWalk,  int songCount, int singers, int singer, int maxArraySize)
{
string text_function_name="realm_sw_divisor_dance"; string text_post = "";

 __int128 guestDancer=0;
 __int128 primeBuild=1;
 __int128 primewalk=0;
 __int128 intDancer=0;
 __int128 intTail=1;
 __int128 primeRange=0;
 __int128 tPrimes=3;
 __int128 previousPrime=0;
 
fstream myPrimes;
fstream primebookbin;
fstream fin;
ifstream finfin;

bool dance=true;
bool checkFin=false;
bool singForever=true;
bool mrTsaysRead=true;

int songWalk=0;
int myFinish=0;
int myStart = 0;
int differenceInt=0;

maxArraySize=307070687;

__int128 recommendedThreadArrayMax =( maxArraySize/singers) ;
int_fast16_t* primeDifferencesArray = new int_fast16_t[ recommendedThreadArrayMax ];

char primeBookBinInputChar1;
char primeBookBinInputChar2;
char primeBookBinInputChar3;

myStart = singer*songCount;
myFinish=  myStart + songCount;


while (singForever==true){
  guestDancer=iWalk+(myStart*2);

  primebookbin.open("primebook.bin", std::fstream::in | std::fstream::in);
  if (singers==1){singForever=false;}
  //cout << "song count " << songWalk  << " of " << songCount << endl;
  myPrimes.open(to_string(singer)+"myPrimes.tru", std::fstream::in | std::fstream::out | std::fstream::app);
  songWalk=myStart;

  while ( songWalk < myFinish){
    while (dance==true){
        //BUILD PRIME FUNCTION
        if(primewalk==tPrimes-1){
            primeBookBinInputChar1='0';    primeBookBinInputChar2='0';    primeBookBinInputChar3='0';

            primebookbin >> primeBookBinInputChar1 ;

            if (primebookbin.eof()|| int(tPrimes)==maxArraySize ){ /* cout << "tPrimes Read: "<< int(tPrimes) << " @ arrayMax: " << maxArraySize << endl; */ mrTsaysRead=false; }

            if (primeBookBinInputChar1=='\n'){
              primebookbin >> primeBookBinInputChar2 ;
              if (primebookbin.eof()|| int(tPrimes)==maxArraySize ){ /* cout << "tPrimes Read: "<< int(tPrimes) << " @ arrayMax: " << maxArraySize << endl; */ mrTsaysRead=false; }

              primebookbin >> primeBookBinInputChar3 ;
              if (primebookbin.eof()|| int(tPrimes)==maxArraySize ){ /* cout << "tPrimes Read: "<< int(tPrimes) << " @ arrayMax: " << maxArraySize << endl; */ mrTsaysRead=false; }

              else{ differenceInt= stoul(to_string(primeBookBinInputChar1 + primeBookBinInputChar2));}
            }
            else{ differenceInt =stoul(to_string(primeBookBinInputChar1)); }
            previousPrime=primeBuild;
            tPrimes++;
            primeDifferencesArray[tPrimes]= differenceInt ;
            primeBuild+=differenceInt;
            cout << singer << " differenceInt " << int(differenceInt) << endl;
        }
        else {primeBuild+=primeDifferencesArray[primewalk]; }


// PRIME CALCULATE FUNCTION
    cout << singer << " primeBuild " << int(primeBuild) << " total primes " << int(tPrimes);
    cout << singer << " checking guestDancer" << int(guestDancer);
    intTail=__int128(guestDancer)%primeBuild;
    cout << " (primeDifferencesArray[primewalk]*2)" << int((primeDifferencesArray[ primewalk ]*2)) ;
    intDancer=__int128(guestDancer)/primeBuild;
    primeRange=intDancer+1;
    cout << " primewalk " << int( primewalk ) ;
    cout << "  intTail " << int( intTail) << endl;
    //cout << "  primeRange ----" << int(primeRange) << "----"<< endl;

// PRIME TEST FUNCTION
    if (intTail==0){
      dance=false;
      myPrimes << "0";
      //    cout << "                              dance found tail 0  " << int(guestDancer) << endl;
    }

    else if(guestDancer==primeBuild+2){
      dance=false;
      songArray[songWalk]=true;
      myPrimes << "1";
      //   cout << "                             " << singer << " dance found prime growth" << int(guestDancer) << endl;
    }

    else if(primeBuild> primeRange ){
      dance=false;
      songArray[songWalk]=true;
      myPrimes << "1";
      //   cout << "                             " << singer << " dance found prime by range " << int(primeRange) <<  "     "<< int(guestDancer) << endl;
    }

    else{

    }
    primewalk++;
  }



  primewalk=0; primeBuild=1;
  guestDancer+=2;
  songWalk++;
  dance=true;
} // finish song Walk


songWalk=0;
myPrimes.close();







if (singForever == true){ cout << "sing forever " << singer << endl;
  fin.open(to_string(singer)+".fin", std::fstream::in | std::fstream::out | std::fstream::app); fin << endl << endl;
  fin.close();
  checkFin=true;
}




while(checkFin==true){       finfin.close();
   finfin.open(to_string(singer)+".fin");
   if(finfin) {
    //  cout<<"Singer # " << singer << " is Finished " << endl;  finfin.close();
   this_thread::sleep_for(chrono::milliseconds(760) );
   cout << "Singer " << singer << " wakes from catnap " << singer << endl;
   }
   else {
     //   cout<<"Singer " << singer << " it is time to dance " << endl; checkFin=false;
   }
}


iWalk+=songs*2;


}  // while singforever


} // finish dance function



void realm_sw_divisor_danced(int singers)
{
string text_function_name="realm_sw_divisor_danced"; string text_post = "";
fstream finito;
int finished=0; int singer =0;
while (finished < singers){

   finito.open(to_string(singer)+".fin");
   if(finito) {
     //  cout<<"Singer Finished " << singer << endl;  finito.close(); finished++;  cout<<"Finished Singers = " << finished++ <<endl; singer++;
   } else {
      // cout<<"The Dance Continues with Singer " << singer << endl;  finished=0;
     this_thread::sleep_for(chrono::milliseconds(1600) );
   //   cout << "slept " << singer << " are we there yet " << endl;
     singer =0;
   } 




}


































































}

























































void realm_sw_variable_primer(int songRequest,bool mrTsaysRead, bool readAndConvert)
{
string text_function_name="realm_sw_variable_primer"; string text_post = "";
text_post = " ENTER TEXT HERE "; realm_post_client(text_function_name, text_post );
// int_fast16_t* primeDifferencesArray = new int_fast16_t[5376999999];
//int_fast16_t* primeDifferencesArray = new int_fast16_t[76999999];
// bool* songArray = new bool[songRequest];
__int128 tPrimes=3;
__int128 foundPrime=3;
__int128 previousPrime=3;
__int128 primeDifference128=0;
__int128 iWalk=3; 
primeDifferencesArray[0]=1;
int removed = 0;
int singer = 0;   int singers = 8;    int songs = singers * songRequest;
// primeDifferencesClass primeDifferencesClass("c:",4000);  primeDifferencesClass.arrayFlexor();
bool infinite = true;
int songWalk=0;
int  primeDifference=0;
int  pDlarge=0;
vector<thread> choir;
int songCount=1;
fstream primebookbin;  fstream primemilestones;  fstream primebook;  fstream thePrimes;
__int128 maxArraySize=0;
realm_sw_array_Flexor(maxArraySize);
realm_librarian_prime_book(primemilestones,  primebook, primebookbin);
if (mrTsaysRead==true){
     realm_librarian_primebook_read(iWalk, tPrimes,  foundPrime, pDlarge, primeDifference, primemilestones,  primebook, primebookbin, mrTsaysRead, primeDifferencesArray, readAndConvert );}

while(songWalk<songRequest){
   songArray[songWalk] =false;
   songWalk++;}
songWalk=0;
foundPrime= iWalk ;  previousPrime= iWalk - primeDifferencesArray[tPrimes-1];
if (tPrimes < songRequest ){ cout << "Prefilling Differences Array to Request Size" << endl;}

songs=songRequest*singers;
while (tPrimes < (songRequest/3) ){
   iWalk=iWalk+2;
   realm_sw_divisor_dance(iWalk,  songCount, 1, singer, maxArraySize);
   if (songArray[songWalk] ==true){
      songArray[songWalk] =false;
      tPrimes++;
      foundPrime= iWalk ; 


 realm_prime_differences( foundPrime, previousPrime, primeDifference);

      primeDifferencesArray[tPrimes]= primeDifference; 

realm_librarian_primebook_16pen( primeDifference , primebookbin);

realm_librarian_primebook_miles(primeDifference, pDlarge, foundPrime, tPrimes, primemilestones);
//      realm_prime_differences( totalprimes,  primeDifferenceLargest, primeDifference, foundPrime,  primemilestones,  primebook, primebookbin);
      previousPrime=foundPrime;
   }
}
 primebookbin.close(); 
 songWalk=0; songCount=songRequest; songs = singers*songRequest; iWalk+=2;
cout << "----> Dance Request Size Now Engaged at : " << songRequest<< endl;
removed = remove(char(singer)+"myPrimes.tru");
 // *************************** DANCE TROUP BEGIN *************************************

  for (singer = 0; singer < singers; singer++) {
     choir.push_back(thread(realm_sw_divisor_dance, iWalk,  songRequest, singers, singer, maxArraySize)); 
} 

while ( infinite ==true){
   realm_sw_divisor_danced(singers);     //now rest until all#.fin files are created

cout << "                      Here is the check song walk" << songWalk << " songs " << songs << "  tPrimes " << int(tPrimes) << endl;

     realm_librarian_theprimes_read(iWalk, tPrimes,  foundPrime, previousPrime, pDlarge, primeDifference, primemilestones,  primebook, primebookbin, mrTsaysRead, readAndConvert,singers );
























 iWalk+=(songs*2);
singer =0;
while (singer < singers){
removed = remove(char(singer)+"myPrimes.tru");
  singer++;
}
singer =0;

while (singer < singers){
removed = remove(char(singer)+".fin"); 
 cout << "removed " << singer << endl;
  singer++;
}
singer =0;
}










text_post = "FUNCTION   realm_sw_variable_primer   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );
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


void realm_librarian_prime_book(fstream& primemilestones, fstream& primebook, fstream& primebookbin)
{
string text_function_name="realm_librarian_prime_book"; string text_post = "";

char filename1[]="primebook.txt"; char filename2[]="primemilestones.txt"; char filename3[]="primebook.bin"; 



primemilestones.open(filename2, std::fstream::in | std::fstream::out | std::fstream::app);


cout<<"LOADED EXISTING PRIMEMILESTONES"<< endl;


primebook.open(filename1, std::fstream::in | std::fstream::out | std::fstream::app);


 cout<<"LOADED EXISTING PRIMEBOOK"<< endl;



primebookbin.open(filename3, std::fstream::in | std::fstream::out | std::fstream::app);


 cout<<"LOADED EXISTING PRIMEBOOK"<< endl;
































text_post = "FUNCTION   realm_librarian_prime_book   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );



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




void realm_librarian_primebook_16pen( int  primeDifference, fstream&primebookbin)
{
//="string text_function_name="& CHAR(34)&B2&CHAR(34)&"; string text_post = "& CHAR(34)& CHAR(34)&";"


      if ( primeDifference <= 15){
        primebookbin << std::hex << primeDifference;
      }

    if ( primeDifference > 15 && primeDifference < 256){
      primebookbin << endl << std::hex << primeDifference;
    }

    if ( primeDifference > 255 ){
      primebookbin << endl << endl << std::hex   << primeDifference;
    }













//="text_post = " & CHAR(34)&"FUNCTION   "&B2 & "   HAS COMPLETED SUCESSFULLY!"&CHAR(34)&";"&" "&"realm_post_client(text_function_name, text_post );"



}














































































































void librarian_functions()
{    



     string userInput;
     bool questionDemonstrate=true;
     int songCount=1;
     bool mrTsaysRead=false;
     bool readAndConvert=false;





















     while( questionDemonstrate==true){
librarian_menu();







          realm_os_user_input(userInput);
          cout << endl;

          if (userInput=="1"){realm_sw_variable_primer(songCount, mrTsaysRead, readAndConvert);}

          else if (userInput=="2"){mrTsaysRead=true;}

          else if (userInput=="3"){  
          cout << endl << "Enter the Number of Songs(Cycles) per Dance(primeCheck): " ;
          realm_os_user_input(userInput);
          songCount=stoi(userInput);


                }

       else if ( userInput=="4"){readAndConvert=true;}

          else if (userInput=="exit") { questionDemonstrate=false;}

          else { cout << endl << " INVALID ENTRY " << endl<< endl; }

     }











}

void librarian_menu()
{    
string text_function_name="librarian_menu"; string text_post = "";






text_post = " (1) Append and Build PrimeBook & MileStones  "; realm_post_client(text_function_name, text_post );
text_post = " (2)    Load Local PrimeBook.bin (2 byte) into Differences Array  "; realm_post_client(text_function_name, text_post );
text_post = " (3)    Set How Many Songs(Cycles) Per Dance(PrimeCheck) Default=1 "; realm_post_client(text_function_name, text_post );
text_post = " (4)    Convert PrimeBook.txt (256 byte) to PrimeBook.bin (16 byte) "; realm_post_client(text_function_name, text_post );
text_post = "  Please enter a Librarian Task (type exit to exit):  "; realm_post_client(text_function_name, text_post );



























































}

void library()
{
string text_function_name="library"; string text_post = "";
text_post = " ENTER TEXT HERE "; realm_post_client(text_function_name, text_post );





text_post = "FUNCTION   library   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}




void realm_librarian_primebook_read(__int128& iWalk,__int128&tPrimes,__int128&foundPrime,int &pDlarge,int &primeDifference,fstream&primemilestones,fstream&primebook,fstream&primebookbin,bool mrTsaysRead,int_fast16_t  primeDifferencesArray[], bool readAndConvert)
{
//="string text_function_name="& CHAR(34)&B2&CHAR(34)&"; string text_post = "& CHAR(34)& CHAR(34)&";"


string primeBookInputString="";


int primeBookInputInt = 0;


while (mrTsaysRead==true){

  primebook >> primeBookInputString ;

if (primebook.eof()){
cout << "end of file reached" << endl;

    mrTsaysRead=false;
}
  else{    primeBookInputInt=stoi(primeBookInputString);

realm_librarian_primebook_16pen(int ( primeBookInputInt ), primebookbin);











  tPrimes++;
  primeDifferencesArray[tPrimes]=primeBookInputInt;

  iWalk+=primeBookInputInt*2;

realm_librarian_primebook_miles( primeBookInputInt , pDlarge, foundPrime, tPrimes, primemilestones);






}
}




      primemilestones<< "Total Primes Loaded: "  << int(tPrimes) <<endl;
cout << "Total Primes Loaded: " << int(tPrimes) << "  iWalk now at: " << int(iWalk) << endl << "Press Enter to Continue " << endl;



//="text_post = " & CHAR(34)&"FUNCTION   "&B2 & "   HAS COMPLETED SUCESSFULLY!"&CHAR(34)&";"&" "&"realm_post_client(text_function_name, text_post );"



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




void realm_librarian_theprimes_read(__int128&iWalk,__int128&tPrimes,__int128&Prime1,__int128&prePrime,int&pDlarge,int &primeDifference,fstream&primemilestones,fstream&primebook,fstream&primebookbin,bool mrTsaysRead,bool readAndConvert,int spots)
{
//="string text_function_name="& CHAR(34)&B2&CHAR(34)&"; string text_post = "& CHAR(34)& CHAR(34)&";"
__int128 iPrime=0;   
fstream thePrimes;

string primeListInputString="";
int primeListInputInt = 0;

int readWalk=0;
int spot=0;
for (spot = 0; spot < spots ; spot++) {
thePrimes.open("myprimes"+to_string(spot)+".tru", std::fstream::in | std::fstream::out | std::fstream::app);
  while (readWalk<songRequest &&mrTsaysRead==true){
      thePrimes >> primeListInputString ;
      // cout << primeListInputString << "     ";

      if (primebook.eof()){
         cout << "end of file reached" << endl;
          mrTsaysRead=false;
       }

    else{   
      if (primeListInputString=="0"){
        Prime1=false;}
      else{
        Prime1=true;}
    }

    if (Prime1==true){
      iPrime=iWalk+(readWalk*2)+(spot*songRequest);
      tPrimes++;


 realm_prime_differences( Prime1, prePrime, primeDifference);

      primeDifferencesArray[tPrimes]=int(primeDifference);

realm_librarian_primebook_16pen(int (primeDifference), primebookbin);














  }








   //   primeDifferencesArray[totalprimes]= primeDifference;

       cout << int(primeDifferencesArray[tPrimes]) << "      ";
      cout << int(iWalk) << "   " << int(tPrimes) << endl;

     prePrime=Prime1;
  }
thePrimes.close();
  primemilestones<< "Total Primes Loaded: "  << int(tPrimes) <<endl;
  cout << "Spot " << spot << " Total Primes Loaded: " << int(tPrimes) << "  iWalk now at: " << int(iWalk) << endl;
}   






//="text_post = " & CHAR(34)&"FUNCTION   "&B2 & "   HAS COMPLETED SUCESSFULLY!"&CHAR(34)&";"&" "&"realm_post_client(text_function_name, text_post );"



}





























































void realm_librarian_primebook_miles (int  primeDifference, int  & pDlarge, __int128 foundPrime, __int128 tPrimes, fstream& primemilestones )
{
//="string text_function_name="& CHAR(34)&B2&CHAR(34)&"; string text_post = "& CHAR(34)& CHAR(34)&";"







if (primeDifference>pDlarge){
     pDlarge=primeDifference;
     primemilestones <<   "Total Primes: " <<  int(tPrimes) << "," ;
     primemilestones <<  " CurrentPrime: " << int(foundPrime)<< ",";
     primemilestones <<  "  LargestPrimeDifference  Div2: "<<  primeDifference << endl;
}













//="text_post = " & CHAR(34)&"FUNCTION   "&B2 & "   HAS COMPLETED SUCESSFULLY!"&CHAR(34)&";"&" "&"realm_post_client(text_function_name, text_post );"



}














































































































void realm_gl_querry()
{
string text_function_name="realm_gl_querry"; string text_post = "";
realm_gl_webgl();
realm_gl_vulkan();
realm_gl_opengl();

realm_gl_metal();
realm_gl_directx();

realm_gl_cores_zeluda();
realm_gl_cores_cuda();
realm_gl_cores_gpufort();
text_post = "FUNCTION   realm_gl_querry   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );
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



void realm_gl_cores_cuda()
{
string text_function_name="realm_gl_cores_cuda"; string text_post = "";






text_post = "FUNCTION   realm_gl_cores_cuda   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



void realm_gl_cores_gpufort()
{
string text_function_name="realm_gl_cores_gpufort"; string text_post = "";






text_post = "FUNCTION   realm_gl_cores_gpufort   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}



