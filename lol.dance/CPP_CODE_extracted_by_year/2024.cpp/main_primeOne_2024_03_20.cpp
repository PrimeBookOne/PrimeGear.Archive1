
#undef UNICODE

#ifndef _WIN32_WINNT
    #define _WIN32_WINNT 0x0600
#elif _WIN32_WINNT < 0x0600
    #undef _WIN32_WINNT
    #define _WIN32_WINNT 0x0600
#endif
#define MAX_IPV4_ADDRESS_LENGTH 16

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
#include <Ws2tcpip.h>
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
#include <d3d9.h>
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
#include <algorithm>
#include <conio.h>
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

#include <Iptypes.h>
#include <Mstcpip.h>
#include <iphlpapi.h>
#pragma comment(lib, "iphlpapi.lib")









#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <curl/curl.h>
#include <base64_default_rfc4648.hpp>
#include <sstream>
#include <cstdio>
#include <memory>
#include <array>
#include <chrono>
#include <ctime>
#include <iomanip>







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
string globalWolfPackIdString = "";       string globalHostIdString = "";
////////////////// GLOBAL Dancer
string globalRemotePortString="";   string globalRemoteIpString="";
int    globalNewHostPort = 54000;
bool    globalNewHost = false;
int* globalNewPort = new int[ 2 ];
bool* globalGuestNewHost = new bool[ 2 ]; // globalGuestNewHost[0]=false;
bool* globalGuestBecomeHost = new bool[ 2 ]; // globalGuestBecomeHost[0] =false;
////////////////// GLOBAL
string globalRemoteNameString  = "";
__int128 maximum__int128  = 9999999999999999999;
int globalGuestBecomeHostCount=0;

bool guestWaitTime00 = false;
string uniqueIdGlobal ="";
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
//const int PORT = 54000; // Port number for the connection


typedef NTSTATUS(NTAPI* PNT_QUERY_SYSTEM_INFORMATION)(
    SYSTEM_INFORMATION_CLASS SystemInformationClass,
    PVOID SystemInformation,
    ULONG SystemInformationLength,
    PULONG ReturnLength
);




















































































class string128Class
{
private:
    __int128 number;
    std::string result;

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


    std::string getString() const {
        return result;
    }
};



class string128ClassComma

{
private:
    __int128 number;
    std::string result;

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

        int digitCount = 0;

        while (number > 0) {
            int digit = number % 10;
            result.insert(result.begin(), static_cast<char>('0' + digit));
            number /= 10;

            digitCount++;

            // Add a comma every three digits (except at the beginning)
            if (digitCount % 3 == 0 && number > 0) {
                result.insert(result.begin(), ',');
            }
        }

        if (isNegative)
            result.insert(result.begin(), '-');
    }

public:
    string128ClassComma(__int128 num) : number(num) {
        convert();
    }

    std::string getString() const {
        return result;
    }
};



class StringTo128Class {
public:
    // Function to convert a string to __int128
    static __int128 stringToInt128(const std::string& str) {
        if (str.empty())
            throw std::invalid_argument("Empty string");

        int i = 0;
        int sign = 1;

        if (str[i] == '-') {
            sign = -1;
            i++;
        }

        __int128 result = 0;
        for (; i < str.size(); i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                result = result * 10 + (str[i] - '0');
            } else {
                throw std::invalid_argument("Invalid character in the input string");
            }
        }

        return result * sign;
    }
};

























class GitHubFileManager {
private:
    static size_t save_data(char* buffer, size_t size, size_t nmemb, void* userdata);
    static std::string exec(const char* cmd);
    static int curlDebugCallback(CURL* handle, curl_infotype type, char* data, size_t size, void* userptr);
    static void initCurl();
    static void cleanupCurl();
    static void setCurlOptions(CURL* curl, const std::string& apiUrl, struct curl_slist* headers);

public:
    static std::string getCurrentTime();
    static std::string getSHAFromGitHub(const std::string& accessToken, const std::string& owner, const std::string& repo, const std::string& remotePath);
    virtual void updateFileOnGitHub(const std::string& accessToken, const std::string& owner, const std::string& repo, const std::string& remotePath, const std::string& fileContent, const std::string& sha);

    static void listFilesInRootDirectory(const std::string& accessToken, const std::string& owner, const std::string& repo);
};

size_t GitHubFileManager::save_data(char* buffer, size_t size, size_t nmemb, void* userdata) {
    GitHubFileManager* self = static_cast<GitHubFileManager*>(userdata);
    // Process the received data (e.g., write to a file)
    return size * nmemb; // Return the number of bytes processed
}

std::string GitHubFileManager::exec(const char* cmd) {
    std::array<char, 256> buffer; // Increased buffer size
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

std::string GitHubFileManager::getCurrentTime() {
    std::stringstream ss;
    auto now = std::chrono::system_clock::now();
    auto nowTime = std::chrono::system_clock::to_time_t(now);
    ss << std::put_time(std::localtime(&nowTime), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

int GitHubFileManager::curlDebugCallback(CURL* handle, curl_infotype type, char* data, size_t size, void* userptr) {
    std::ostream* outputStream = static_cast<std::ostream*>(userptr);
    outputStream->write(data, size);
    return 0;
}

void GitHubFileManager::initCurl() {
    try {
        curl_global_init(CURL_GLOBAL_DEFAULT);
    } catch (const std::exception& e) {
        std::cerr << "Error initializing libcurl: " << e.what() << std::endl;
        throw;
    }
}

void GitHubFileManager::cleanupCurl() {
    curl_global_cleanup();
}

void GitHubFileManager::setCurlOptions(CURL* curl, const std::string& apiUrl, struct curl_slist* headers) {
    curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlDebugCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &std::cerr); // Directly output to stderr
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
}

std::string GitHubFileManager::getSHAFromGitHub(const std::string& accessToken, const std::string& owner, const std::string& repo, const std::string& remotePath) {
    std::string cmd = "curl -s -H \"Authorization: token " + accessToken + "\" https://api.github.com/repos/" + owner + "/" + repo + "/contents/" + remotePath;
    std::string output = exec(cmd.c_str());
    std::string shaLabel = "\"sha\": \"";
    std::size_t shaPos = output.find(shaLabel);
    if (shaPos != std::string::npos) {
        std::size_t shaStart = shaPos + shaLabel.length();
        std::size_t shaEnd = output.find("\"", shaStart);
        if (shaEnd != std::string::npos) {
            std::string sha = output.substr(shaStart, shaEnd - shaStart);
            return sha;
        }
    }
    return "";
}

void GitHubFileManager::updateFileOnGitHub(const std::string& accessToken, const std::string& owner, const std::string& repo, const std::string& remotePath, const std::string& fileContent, const std::string& sha) {
    CURL* curl = nullptr;
    std::string encodedContent = cppcodec::base64_rfc4648::encode(fileContent);
    initCurl();
    std::string apiUrl = "https://api.github.com/repos/" + owner + "/" + repo + "/contents/" + remotePath;
    curl = curl_easy_init();
    if (!curl) {
        throw std::runtime_error("Failed to initialize CURL.");
    }
    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, ("Authorization: token " + accessToken).c_str());
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "User-Agent: PrimeBookOne");
    setCurlOptions(curl, apiUrl, headers);
    curl_easy_setopt(curl, CURLOPT_CAINFO, "cacert.pem");
    std::string payload = "{\"message\":\"Test\",\"content\":\"" + encodedContent + "\",\"sha\":\"" + sha + "\",\"branch\":\"main\"}";
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, payload.length());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &GitHubFileManager::save_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, this); // Pass 'this' as userdata
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        throw std::runtime_error("HTTP PUT request failed.");
    }
    long httpCode = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    if (httpCode != 200) {
        throw std::runtime_error("HTTP response code is not 200.");
    }
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    cleanupCurl();
}

void GitHubFileManager::listFilesInRootDirectory(const std::string& accessToken, const std::string& owner, const std::string& repo) {
    std::string apiUrl = "https://api.github.com/repos/" + owner + "/" + repo + "/contents";
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlDebugCallback);
       curl_easy_setopt(curl, CURLOPT_WRITEDATA, &std::cerr); // Directly output to stderr
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "PrimeBookOne");
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, ("Authorization: token " + accessToken).c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);
        curl_easy_setopt(curl, CURLOPT_CAINFO, "cacert.pem");
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}



































































































































































class primeTileClass
{
private:  // **************** PRIVATE *******************
  




  string targetTileName = "";
  string arrayNamePrefix = "Tile";
  string stringBean4 = "";
  string stringBean = "";
  string stringBean2 = "";
  string stringBean3 = "";       
  string gridString ="";
  int memError = 0 ;
  int memErrorCount =1;
  __int128 tileCount = 0;
  __int128 powerOf = 0 ;
  __int128 grid = 0 ;
  __int128 singers =0;
  __int128 total = 1;
  __int128 etchWalk =0; 
  __int128 breezeWalk =0;
  __int128 tileWalk =0;
  //__int128 infiniteWalk = 5 ;
  __int128 infiniteWalkAdd =5;
  __int128 infiniteWalkStart = 5 ; 
  __int128 primeRatio = 0 ;
  __int128 previousPrimeRatio = 0 ; 
  __int128 slatePrimeRatio =0;
  __int128 slateRoughCut =0 ;
  __int128 previousPrime = 3;
  __int128 perThreadSlices =0;
  __int128 primeBasePrimer =0;
  std::unordered_map<std::string, byte*> tiles;
  std::unordered_map<std::string, byte*> slate ;
  __int128* threadTotal;
  __int128* threadSlateWalk ;
  __int128* threadBreezeWalk ;
  __int128* threadTileWalk ;
  string primeBookName = "PrimeBookOne.zip";   string primeBookNameImport = "PrimeBookOneImport.tar";
  __int128 readTileCount=0;

  __int128* myTileCount ;
  __int128* myEtchWalk ;

  __int128* findsArray  ;








































































































__int128 listBookZip(){ 
 string userInput="";
  //cout << " 999 " << endl;
    //  realm_os_user_input(userInput);

string listBookZipString = "echo off & cd PrimeBookOne & tar -tf " + primeBookNameImport +" > bookZipList.txt";

system( listBookZipString.c_str() ); 
//cout << listBookZipString << endl;
// count lines of file cout

    ifstream file("PrimeBookOne\\bookZipList.txt");

    if (!file) { cerr << "Error opening file: bookZipList.txt" << endl;  cout << "Error Reading ZipList File" << endl; }

    __int128 lineCount = 0;
    string line;

    while (getline(file, line)) {lineCount++;}   lineCount--;

    string128Class lineCountString( lineCount );
    string stringLineCount = lineCountString.getString();
  //  cout << "Number of Tiles in bookZipList.txt : " <<stringLineCount << endl;
    readTileCount=lineCount;

return lineCount;

}





















































































































void readBookIndex(__int128 readTileCount, __int128* tileStart, __int128* tileFinish, __int128* tileTotals){  
//system("cls"); 
string userInput="";
//  cout << "Begin Book Read of Index *1111111111111111111111111111111111111111111111111111111111111111111111111 " << endl;
 // realm_os_user_input(userInput);

  const int MAX_LINES = 500;
   ifstream file("PrimeBookOne\\PrimeBookOneIndexImport.txt");

    if (!file) {  std::cerr << "Error opening file: file.txt" << std::endl;}

 //   __int128 tileStart[MAX_LINES];
  //  __int128 tileFinish[MAX_LINES];
  //  __int128 tileTotals[MAX_LINES];
    __int128 value1, value2, value3;
 //   __int128  readTileCount = 28;
    string value1S, value2S, value3S;

    __int128 lineCount = 0;



    string stringBean1="", stringBean2="", stringBean3="";

    while (lineCount< readTileCount) {
       file >> value1S >> value2S >> value3S;
  //   cout <<  value1S << " V1  " <<value2S << " V2  " << value3S << " V3 " << endl;
        if (lineCount >= MAX_LINES) { std::cerr << "Exceeded the maximum number of lines allowed (" << MAX_LINES << ")" << std::endl;}
        value1 = StringTo128Class::stringToInt128(value1S);
        value2 = StringTo128Class::stringToInt128(value2S);
        value3 = StringTo128Class::stringToInt128(value3S);
        tileStart[lineCount] = value1;
        tileFinish[lineCount] = value2;
        tileTotals[lineCount] = value3;
        lineCount++;


       }


     //  cout << " print PrimeBookOne Index"<< endl;

    for (__int128 i = 0; i <  readTileCount; i++) {      // Print the read data
      string128Class tileStartString(tileStart[i]);
      string128Class tileFinishString(tileFinish[i]);
      string128Class tileTotalsString(tileTotals[i]);
   //   cout << tileStartString.getString() << " R1 ";
   //   cout << tileFinishString.getString() << " R2 ";
  //    cout << tileTotalsString.getString()  << " R3 ";
  //    cout << endl;


    }



// infiniteWalk = tileFinish[ readTileCount-1 ];

// tileCount = readTileCount;

// total =tileTotals[readTileCount-1];



//string128Class totalString(total);
//string128Class infiniteWalkString(infiniteWalk);
//string128Class tileCountString(tileCount);


//cout << " FFFFFFFFFFFFFFFFFFFFFFFFFinish readbook INDEX" << endl;
//cout << "cout << totalString.getString(); " << totalString.getString() << endl;
//cout << "cout << infiniteWalkString.getString(); " << infiniteWalkString.getString() << endl;
//cout << "cout << tileCountString.getString(); " <<  tileCountString.getString() << endl;
//cout << endl << endl;

//  realm_os_user_input(userInput);



}

































































void extractTile(__int128 tileNumber){      // cout << "Extract Tile " << endl; 
// string userInput="";  
  string128Class tileNumberString(tileNumber);
  string tileString = tileNumberString.getString();

// cout << " 101010 " << endl;      realm_os_user_input(userInput);




  string extractTile = " cd PrimeBookOne & tar -xvf "  +  primeBookNameImport + " PrimeBookOne/Tile0" + tileString +".zip";
  cout  <<extractTile << endl;
  system( extractTile.c_str());







  string unzipTile = " cd PrimeBookOne & cd PrimeBookOne & tar -xvf Tile0" + tileString +".zip";
//   cout << "unzipTile: "<< unzipTile << endl;
  system( unzipTile.c_str());
}

























































































































void extractBookIndex(){ cout << "Extract Book Index " << endl; string userInput="";
//cout << " 11 11 11 " << endl;      

 // realm_os_user_input(userInput);



  //string primeBookIndexString = "tar -xvf PrimeBookOne\\" +  primeBookName + " PrimeBookOne/PrimeBookOneIndexImport.txt";
  // cout << "primeBookIndexString: " << primeBookIndexString << endl;
  //system( primeBookIndexString.c_str());
}






































































































































void cleanupRead(__int128 tileNumber){  

// cout <<"Cleanup" << endl;
  string128Class tileNumberString(tileNumber);
  string tileString = tileNumberString.getString();


  string delZip = "echo off & del PrimeBookOne\\PrimeBookOne\\Tile0" + tileString +".zip";

  // cout << "delZip: " << delZip << endl;
  system( delZip.c_str());

  string delPrime = "echo off & del PrimeBookOne\\PrimeBookOne\\PrimeBookOne\\Tile0" + tileString +".prime";
//  cout << "delPrime: "<< delPrime << endl;

  system( delPrime.c_str());
}





























































































































0



void verifyBook(__int128 singers){ 

  bool infinite = true;
  __int128 singersPlus = singers +1;
  __int128 breezeDigits =0;
  __int128 primeBuild =5;
  __int128 bookWalk=1;

  string128ClassComma totalString( total );
  string128ClassComma singersPlusString(singersPlus);
  
//  cout  << " Total Primes to Test : " << totalString.getString();
 //cout  <<"  singersPlus = " << singersPlusString.getString() << endl<< endl;
// still(singers);
//  breezeDigits = breeze( singers )*2; 
primeBuild +=breeze(singers)*2;
while(bookWalk<total){
 // cout  << " primeBuild Pre : " << int(primeBuild) << "  bookWalk " << int(bookWalk) ;


    if (primeDivise(primeBuild)== true){
     //   cout << " PRIMEBOOK is GOOD!!!!!   ";
     //   cout << int(primeBuild) << " is  PRIME  ";
     //   cout << "  bookWalk " << int(bookWalk) << endl;

    }

    else {
      cout << " PRIMEBOOK is ERRORED!!!!!   ";
      string128ClassComma primeBuildString(primeBuild);
      string128ClassComma bookWalkString(bookWalk);
      cout << primeBuildString.getString() << " is not PRIME!!!!";
      cout << "  bookWalk " << bookWalkString.getString() << endl;
    }
still(singers);
//    breezeDigits = breeze( singers )*2;
//    primeBuild+= breezeDigits;
    //  cout << endl << " breezeDigits " << int(breezeDigits) << endl;

    bookWalk++;
}

cout << endl << endl<< "  ****************************    PrimeBook Verified " << totalString.getString() << " Primes." << endl;

}

































































































0



int testTile(){
  try{
    byte* testGridArray = new  byte[(grid*8)];
    // std::cout << "Created TEST GRID array: " << std::endl;
    delete[] testGridArray;    memError = 0 ;    return memError;
  }
  catch (const std::bad_alloc& e) { // Handle the exception
    std::cerr << "CATCH :: Memory allocation failed :: It's About to Crash!!!" << e.what();
    std::cout << " Total Memory Errors: " << memErrorCount << std::endl;
    memError = 1; memErrorCount++;
  } } // TESTTILE






































































































































void exportTile(string targetTileName){
    byte* fileTile;
  fileTile = tiles[targetTileName];
  string targetTileNamePath = "PrimeBookOne\\Tile0" + stringBean3 + ".prime";
  ofstream copy( targetTileNamePath , std::ios::binary);
  copy.write(reinterpret_cast<const char*>(fileTile), grid);

  copy.close();

  compressTile(targetTileName);

  fstream PrimeOneIndex ;
  PrimeOneIndex.open("PrimeBookOne\\PrimeBookOneIndex.txt",
  fstream::in | fstream::out | fstream::app);

  string128Class infiniteWalkString(infiniteWalkAdd);
  string stringBean2= infiniteWalkString.getString();

  string128Class infiniteWalkStartString(infiniteWalkStart);
  string stringBean3= infiniteWalkStartString.getString();

  string128Class totalString(total);
  string stringBean4 =totalString.getString();
  
  PrimeOneIndex  << stringBean3 << "  " << stringBean2 << " " << stringBean4 <<endl;
  PrimeOneIndex.close();
  infiniteWalkStart=infiniteWalkAdd;
  // cout  << " ETCHED FILE TO WINDOWS OS FS : " << targetTileNamePath << endl << endl;

     }
















































































































     



void compressTile(string targetTileName){

  string addZipString = "echo off & tar  -r -f PrimeBookOne\\PrimeBookOne.tar PrimeBookOne\\"+ targetTileName + ".zip";


  string zipTileString = "echo off & tar -czf PrimeBookOne\\"+ targetTileName + ".zip PrimeBookOne\\"+ targetTileName + ".prime";


  string delTilePrime = "echo off & del PrimeBookOne\\"+ targetTileName + ".prime";


  string delTileZip = "echo off & del PrimeBookOne\\"+ targetTileName + ".zip";

  cout << "\033[1;1H"; cout << endl;
  system( zipTileString.c_str() );



  cout << "\033[1;1H"; cout << endl;
  system( addZipString.c_str() );


  cout << "\033[1;1H"; cout << endl;
  system( delTilePrime.c_str() );



  cout << "\033[1;1H"; cout << endl;
  system( delTileZip.c_str() );
}
















































































































  



void etchTile(byte data) {
    
  byte* targetTile;  
  string128Class tileCountString ( tileCount );
  stringBean3 = tileCountString.getString();
  targetTileName = "Tile0" + stringBean3 ;
//  total++;
 // infiniteWalkAdd += data; 
  // cout << "  etchWalkString: " << stringBean2;
  //  cout << "  tileCountString: " <<  stringBean3;
  //  cout << "  gridString: " << gridString ;
  //  cout << "  targetTileName  " << targetTileName << endl;
  if (etchWalk < grid) {
     targetTile = tiles[ targetTileName ];
     // cout << "    BEGIN ETCH   " ;
     targetTile[etchWalk] = data;
     // cout << "ETCHED GOOD " << endl;
  }
  else { 
    exportTile( targetTileName );
    //    int_fast16_t* newTile = new int_fast16_t[grid];
    //    tiles[targetTileName] = newTile;
    //    targetTile = newTile;
    tileCount++;

    etchWalk = 0;

    string128Class tileCountString ( tileCount );
    string stringBean4 = tileCountString.getString();
    targetTileName = "Tile0" + stringBean4 ;
    byte* newTile = new byte[grid];
    tiles[targetTileName] = newTile;
    // targetTile = newTile;
    targetTile = tiles[ targetTileName ];
    //cout << " targetTileName  ";
 //   cout << targetTileName  << endl;
    targetTile[etchWalk] = data;
  }
    
  etchWalk++;
} // ETCHTILE








































































































void initiateTile(__int128 tileNumber ){  string128Class tileNumberString ( tileNumber ); string stringBean4 = tileNumberString.getString();
  targetTileName = "Tile0" + stringBean4 ;  byte* targetTile;
  byte* newTile = new byte[grid];

  tiles[targetTileName] = newTile;
  targetTile = newTile;
} // INITIATETILE










































































































































void initiateBreeze(){
  byte* threadBreezeWalk = new byte[singers];
}














































































































































void carveSlate(__int128 singers ) {  // cout << "CarveSlate Begin " << endl;
  __int128 singer = 0;
  string stringBean4;
  singers=singers;
  string targetSlateName;
  previousPrimeRatio = primeRatio;
 // primeRatio = (infiniteWalk/total) +1; // cout << "PrimeRatio "<< int(primeRatio)<< endl;
  slateRoughCut = (perThreadSlices ); 
  while (singer < singers ) {
    byte* targetSlate ;
    string128Class singerString ( singer );
    stringBean4 = singerString.getString();
    targetSlateName = "Slate" + stringBean4 ; // cout << "targetSlateName " << targetSlateName << endl;
    byte* cleanSlate = new byte[ slateRoughCut ]; // cout << "roughcut"<<endl;
    slate[targetSlateName] = cleanSlate ; // cout << "cleanslate" << endl;
    targetSlate = cleanSlate ;
    singer++;
  }
  threadTotal = new __int128[ singers ]; 
  threadSlateWalk = new __int128[ singers ];

  singer= 0;
  while (singer < singers) { 
    threadTotal[singer] = 0;
      threadSlateWalk[singer] = 0; singer++;
  }

// cout << "Slate Carved" << endl;
}// CARVESLATE




















































































































void scribeSlate(__int128 singer, byte data){// cout << "singer scribeSlate " << int(singer) << " data " << data << endl;
    byte* targetSlate ;
    __int128 slateWalk =0;
    string128Class singerString ( singer );
    stringBean4 = singerString.getString();
    targetTileName = "Slate" + stringBean4 ; // cout << "Target Slate to Scribe : " << targetTileName;
    targetSlate = slate[targetTileName];  
    slateWalk = threadTotal[singer];  // cout << " SlateWalk " << int(slateWalk)<<endl;
   targetSlate[slateWalk] = data; 
 // slateWalks[singer] ++;

  threadTotal[singer]++;   //cout << " SLATE ETCHED "<< int(singer) << endl;
} //SCRIBESLATE




































































































































void readSlate(){//  cout << "Read Slate" << endl;
  __int128 singer=0;
  __int128 threadScribeTotal = 0;
  __int128 walkData = 0;
  byte data = 0;
  __int128 threadReadWalk = 0;
   byte* targetSlate ;
  string targetSlateName =""; //   while(singer < singers){ 
  string128Class singerString(singer);
  stringBean = singerString.getString();
    threadScribeTotal = threadTotal[singer]; // cout << "ThreadScribe Total Read " << int(threadScribeTotal) << " singers "<< int(singers) << endl;
    targetSlateName = "Slate" + stringBean;      // cout << "TargetSlateName " << targetSlateName << endl; //
    targetSlate = slate[targetSlateName]; 
    threadReadWalk = 0;
     //  cout << "ThreadReadPreWALK " << int(singer) << " threadReadWalk " << int(threadReadWalk) ;
    //  cout <<  int(threadReadWalk) <<   "  threadScribeTotal " << int(threadScribeTotal) << endl;
   while( threadReadWalk < threadScribeTotal ){
    // cout << "threadReadWalk " << int(threadReadWalk) << endl;
     walkData = threadSlateWalk[singer];
     // cout << " walkData = threadSlateWalk[singer] " << int(walkData) << endl;
      data = targetSlate[ threadReadWalk ];
   // cout << "data = targetSlate[ threadReadWalk ]; " << int(data) << endl;
     etchTile(data);
 
     threadReadWalk++;
    }
  singer++;
} // READSLATE





















































































































void scrubSlate(){
  for (auto& pair : slate) {delete[] pair.second;}
  delete[] threadTotal ;    delete[] threadSlateWalk ;  }
__int128 threadReadTotals(__int128 singer){//return threadTotal[singer] ;
 } // BREAKSLATE
 
__int128 primeTotalCurrent(){ return total ; }
//__int128 infiniteWalkCurrent() {return infiniteWalk;}
__int128 threadSlicesCurrent(){ return perThreadSlices;}
__int128 threadSingersCurrent(){ return singers;}




































































































































 
void realm_os_user_input(string&validUserInput)
{    
 //  cout << "\033[25;1H"; 
/* ="cout << " & CHAR(34) & "Function Begin : "  & B2 & CHAR(34)  & " << endl;" */
//cout << "X                                X       |      " ;
  string userRawInput="";
  cin.clear(); 
  getline(cin, userRawInput);
  validUserInput = userRawInput +"\0";

//cout << "\033[1;1H";
}































































void menu_gyrogear( __int128 primeRatio, __int128 totalTiles, __int128 pDlarge, __int128 infiniteWalk, __int128 totalPrimes )
{    
string text_function_name="menu_gyrogear"; string text_post = "";




cout << "\033[1;1H";


cout << endl << endl << endl << endl << endl << endl << endl << endl  << endl;
cout << endl  << endl << endl << endl << endl << endl << endl  << endl;














string128ClassComma sprimeRatioString( primeRatio );
string128ClassComma totalTilesString( totalTiles );
string128ClassComma pDlargeString ( pDlarge );
string128ClassComma infiniteWalkString( infiniteWalk );
string128ClassComma totalPrimesString( totalPrimes );

cout << "X        Prime Ratio = " << sprimeRatioString.getString() << endl ;
cout << "X        Total Tiles = " << totalTilesString.getString() << endl ;
cout << "" << endl ;
cout << "X Largest Difference = " << pDlargeString.getString() << endl ;
cout << "X       infiniteWalk = " << infiniteWalkString.getString()<< endl ;
cout << "X       Total Primes = " << totalPrimesString.getString() << endl ;
cout << "" << endl ;
cout << "" << endl ;
cout << " X    Network Peers  = " << endl ;
cout << "  XXXXXXXX Active ip = " << endl ;





}






























byte breeze(__int128 singer) {
bool forever = true;
while (forever== true){

  if (threadBreezeWalk[singer] == grid){
        threadTileWalk[singer]++;

//cout << "threadTileWalk[singer] " << int(threadTileWalk[singer]) <<"  grid : "<< int(grid)<< endl;
//cout << "singer " << int(singer) << endl;
//cout << " threadBreezeWalk[singer] "<< int(threadBreezeWalk[singer] ) << "  singer =" << int(singer)<<  " start " << endl;
        threadBreezeWalk[singer] = 0;
//cout << " threadBreezeWalk[singer] "<< int(threadBreezeWalk[singer] ) << "  singer =" << int(singer)<<  " finish " << endl;
  }


else{
  string128Class tileWalkString(threadTileWalk[singer]);
  stringBean = tileWalkString.getString();
  string targetTileName = "Tile0" + stringBean;
  byte* targetTile = tiles[targetTileName];
  __int128 myBreezeWalk = threadBreezeWalk[singer];
  byte return16 = targetTile[myBreezeWalk];
  threadBreezeWalk[singer]++;
//if (return16 > 9) {cout << int(threadTileWalk[singer]) << " " <<  int(return16) << " ";}








  return return16;
}
}


}  // BREEZE











































































































void still(__int128 singer){  
//cout << "Begin still for singer : " << int(singer) << endl;
threadTileWalk[singer]=0;  
//cout << "Midway  still for singer : " << int(singer) << endl;
threadBreezeWalk[singer]=0;  



// cout << "Finished still for singer : " << int(singer) << endl;
}







































































































































void testBook(){   string userInput="";

 cout << " Test Read PrimeBook Begin : Singers 00000000000000000000000000000000000000000" << int(singers) << endl;
  cout << " 000 " << endl;      realm_os_user_input(userInput);
__int128 readWalk =0;
 __int128 singersPlus = singers +1 ;
__int128 primeBuild=3;  
  cout << " 111 " << endl;      realm_os_user_input(userInput);
while (readWalk<total){   cout << " 222 " << endl;      realm_os_user_input(userInput);
  primeBuild+= breeze(singersPlus)*2; 

  readWalk++; 

   cout << int(primeBuild)<< endl;

}
  cout << " 333 " << endl;      realm_os_user_input(userInput);

  string128Class primeBuildString( primeBuild );
  string stringBean = primeBuildString.getString();
 // string128Class infiniteWalkString( infiniteWalk );
  //string stringBean2 = infiniteWalkString.getString();
  string128Class totalString( total );
  string stringBean3 = totalString.getString();


//cout << "PrimeBuild Total = " << stringBean << " infiniteWalk : " << stringBean2 << " Total : " << stringBean3 << endl;
}





















































































































__int128 primeBase(__int128 singers,
                  __int128 perThreadSlices,
                   __int128 mrTsaysRead, __int128 primerBase)
{
string gitData="";     __int128 totalTiles = 0; __int128 totalPrimes = 0;
__int128 infiniteWalk = 5;
__int128 etchWalk =0;
__int128 primeRatio =0;
__int128 threadPrimeFinds =0;
__int128 singer =0; 
__int128 pDlarge = 228;
__int128 verifyCount =0;
  byte* targetArray = new byte[ singers  ];
  byte* dancerPrimeFinds = new byte[ singers  ];
__int128 conductorCount =1;
  vector<byte*> dancerPrimeFindsArray (  perThreadSlices );  // 88888 INCORPORATE SIZE@PRIMERATIO TO SAVE SPACE IF NEEDED
  vector<byte*> conductorPrimeFindsArray (  perThreadSlices );  // 88888 INCORPORATE SIZE@PRIMERATIO TO SAVE SPACE IF NEEDED

  conductorPrimeFindsArray[singer] = new byte[ perThreadSlices ];

  bool infinite = true;

  string stringBeanTileCount = "";
  string targetTileName = "";
  vector<std::promise<__int128>> promises(singers);
  vector<std::future<__int128>> futures(singers);

  vector < thread > choir;
        //     menu_gyrogear(primeRatio, tileCount, pDlarge, infiniteWalk, total);

int conductorClockIn = getCurrentTimeInSeconds();
bool iUpdate = true;
int conductorCheckClock =0;
int conductorLastGitUpdate= conductorClockIn ;
int conductorUpdateInterval=600;
int statusUpdates=0;

__int128 intTail=0;
byte primeDifference =0;
  while ( total  <  primeBasePrimer ){ 
  //  cout << int(total)<< "   Total Before primeDivise  " << endl;
if (primeDivise(infiniteWalk)== true){
      primeDifference = (infiniteWalk - previousPrime)/2;  
      previousPrime = infiniteWalk;
      etchTile(primeDifference); 
 //   cout << int(infiniteWalk) << "   infiniteWalk    ";
  //  cout << int(primeDifference) << "   primeDifference" ;
 //   cout << int(total)<< "   Total " << endl;
total++;

    }
   // cout << int(total)<< "   Total After primeDivise  " << endl;
    infiniteWalk+=2;
  //  cout << int(total)<< "   Total After infiniteWalk++  " << endl;
  //  cout << int(infiniteWalk) << "   infiniteWalk    ";
still(0);

}

// string128ClassComma primeBasePrimerString( primeBasePrimer );

// cout << endl << endl << endl << endl <<"  PrimeBasePrimer : " << // primeBasePrimerString.getString() << " Completed" << endl << endl;
threadTileWalk[0]=0;

while ( infinite == true){
  choir.clear();
conductorCheckClock = getCurrentTimeInSeconds();
if (iUpdate == true && (conductorCheckClock - conductorLastGitUpdate ) > conductorUpdateInterval){
totalTiles = tileCount; totalPrimes = total;
conductorLastGitUpdate = getCurrentTimeInSeconds(); 
statusUpdates++;
    choir.push_back(thread([this,
                            gitData, primeRatio,  pDlarge, infiniteWalk,    conductorCount, totalTiles, totalPrimes
                                      ]() {
                            this->conduit_git(gitData, primeRatio,  pDlarge, infiniteWalk,    conductorCount, totalTiles, totalPrimes
                                      );}));
}
  for (singer = 0; singer < singers; singer++) {      //   cout << "create singer "<<int(singer)<< endl;


    dancerPrimeFindsArray[singer] = new byte[ perThreadSlices ];
    //         menu_gyrogear(primeRatio, tileCount, pDlarge, infiniteWalk, total);

    // SEND dancerTotals INT and  dancerPrimeFinds Array to each thread
    choir.push_back(thread([this,
                            singer,
                              infiniteWalk,
                                perThreadSlices,

                                    &primeFindsArray = dancerPrimeFindsArray[singer]
                                      ]() {
                            this->librarianDancer(singer,
                              infiniteWalk,
                                perThreadSlices,

                                   primeFindsArray
                                      );}));
    infiniteWalk+=perThreadSlices*2;
  } // FINISH CREATE ALL THREADS
  
    primeRatio = infiniteWalk/total;

    //         menu_gyrogear(primeRatio, tileCount, pDlarge, infiniteWalk, total);


for (auto& t : choir) {
  t.join();
}


      //       menu_gyrogear(primeRatio, tileCount, pDlarge, infiniteWalk, total);


 cout << "conductorCheckClock " << conductorCheckClock << "  conductorLastGitUpdate " << conductorLastGitUpdate << "  conductorUpdateInterval " << conductorUpdateInterval << "  statusUpdates : " << statusUpdates << endl;







choir.front();

for (singer = 0; singer < singers; singer++) {

   targetArray = dancerPrimeFindsArray[singer];

  for ( etchWalk  = 0; etchWalk < findsArray[singer] ; etchWalk++) {
      etchTile( targetArray[etchWalk]);
      total++;
      //  cout << "Singer " << int(singer) << " at etchWalk ";
      // cout << int(etchWalk) << " found difference ";
      // cout <<  targetArray[etchWalk] << endl;

  }

} // FINISH CONDUCTOR ETCH THREAD DATA

} // WHILE INFINITE = TRUE
}





bool primeDivise(__int128 data){
    
  __int128 primeBuild = 3;
  __int128 intTail =0;
  bool dance = true;

  while (dance == true){ 
    if (data%primeBuild==0){ 
  //    cout << " primeBuild DIVISIBLE by " << int(primeBuild ) << " data " << int(data)  << "" << endl;
      return false;
    }
    
    else  if( primeBuild > (( data /primeBuild) +1) ){
      // cout << " primeBuild " << int(primeBuild ) << " infiniteWalk " << int(data)  << "" << endl;
      return true;
    }  // ******** IF PRIME BY RANGE *******

    else  if( primeBuild > (data/3) ){
 //     cout << " primeBuild inDIVISIBLE by range " << int(primeBuild ) << " data " << int(data)  << "" << endl;
      return true;
    }

    else { 
      primeBuild+= breeze(0)*2;
    }
    
  }  // cout << " ******** WHILE DANCE = TRUE LOOP ******* " << endl;
} // PRIMEDIVISE





















































































































void librarianDancer( __int128 singer,
                      __int128 myInfiniteWalk ,
                      __int128 perThreadSlices,

                           byte* primeFindsArray
                           )



{
__int128 myPrimeFindsLocal=0;
 // cout << "Begin Dancer : " << int(singer)<< "  myWalk = " << int(myInfiniteWalk ) ;
  //cout << "  perThreadSlices = " << int(perThreadSlices) << endl;

  
__int128 countThis=0;
__int128 primeDifference=0;
__int128 primeBuild=0;
__int128 intTail=0;
__int128 myPreviousPrime = 0;
__int128 moonWalker = 0;
__int128 slice=0;
__int128 spaceBuffer =0;
  bool findPrevious=true;
  bool dance=true;
  bool isPrime = false;
  

  

// MOONWALKER FIND PREVIOUS BEGIN ****************************************************
moonWalker =  myInfiniteWalk;
  
while ( findPrevious==true ){ 
  moonWalker+=-2;

        // vvvvvvvvvvvv DIVISE vvvvvvvvvvvv  DIVISE vvvvvvvvvvvv  DIVISE vvvvvvvvvvvv 
        primeBuild = 5;
        intTail =0;
        dance = true;
        while (dance == true){ 
          if (moonWalker%primeBuild==0){ 
            //  cout << " primeBuild DIVISIBLE by " << int(primeBuild );  //  cout << " moonWalker " << int( moonWalker )  << "" << endl;
            isPrime = false;
            still(singer);
            dance = false;
          }
    
          else  if( primeBuild > ((moonWalker/primeBuild) +1) ){
      //       cout << " primeBuild " << int(primeBuild ) << " moonWalker ";
       //     cout << int( moonWalker )  << "singer " << int(singer) << endl;
            isPrime = true; findPrevious=false;
            dance = false;
          }  // ******** IF PRIME BY RANGE *******

          else  if( primeBuild > (moonWalker/3) ){
            //   cout << " primeBuild inDIVISIBLE by range " << int(primeBuild );
            //   cout << " moonWalker " << int( moonWalker )  << " singer" << int(singer) << endl;
            isPrime = true; findPrevious=false;
            dance = false;
          }

          else { 
            primeBuild+= breeze(singer)*2;
          }

          //  cout << " moonwalk " << int(singer);  cout << " " << int(moonWalker)<<endl;
        }  // cout << " ******** WHILE DANCE = TRUE LOOP ******* " << endl;
        // ^^^^^^^^^^^^ DIVISE ^^^^^^^^^^^^  DIVISE ^^^^^^^^^^^^  DIVISE ^^^^^^^^^^^^ 

        
  if ( isPrime== true){
    myPreviousPrime = moonWalker;
    findPrevious=false; } //  IF PRIME
    still(singer);
  } // FINISH findPrevious

//cout << "Singer " << int(singer) << " Moon Walked found previousPrime ="; cout << int(myPreviousPrime) << endl;
// cout << endl << "     ********** BUILD perThreadSlicesTHREADArray ************** "; cout << "\033[1;1H";

while ( slice  <  perThreadSlices ){
        
        // vvvvvvvvvvvv DIVISE vvvvvvvvvvvv  DIVISE vvvvvvvvvvvv  DIVISE vvvvvvvvvvvv 
        primeBuild = 3;
        intTail =0;
        dance = true;

        while (dance == true){ 
          if (myInfiniteWalk%primeBuild==0){ 
            //  cout << " primeBuild DIVISIBLE by " << int(primeBuild ); //  cout << " myInfiniteWalk " << int( myInfiniteWalk )  << "" << endl;
            isPrime = false;
            dance = false;
            still(singer);
          }
    
          else  if( primeBuild > ((myInfiniteWalk/primeBuild) +1) ){
            // cout << " primeBuild " << int(primeBuild ) << " myInfiniteWalk "; // cout << int( myInfiniteWalk )  << "singer " << int(singer) << endl;
            isPrime = true;
            findPrevious=false;
            dance = false;
            still(singer);
          }  // ******** IF PRIME BY RANGE *******

          else  if( primeBuild > (myInfiniteWalk/3) ){
            //  cout << " primeBuild inDIVISIBLE by range " << int(primeBuild ); //  cout << " myInfiniteWalk " << int( myInfiniteWalk )  << " singer" << int(singer) << endl;
            isPrime = true;
            findPrevious=false;
            dance = false;
            still(singer);


          }
           
          else {  primeBuild+= breeze(singer)*2; }

          //  cout << " myInfiniteWalk " << int(singer); //  cout << " " << int(myInfiniteWalk)<<endl;
        } // cout << " ******** WHILE DANCE = TRUE LOOP ******* " << endl;
        // ^^^^^^^^^^^^ DIVISE ^^^^^^^^^^^^  DIVISE ^^^^^^^^^^^^  DIVISE ^^^^^^^^^^^^ 

if ( isPrime== true){
  //  cout << int(slice) << "singer "<< int(singer); //  cout<< "   myInfiniteWalk "<< int( myInfiniteWalk);
  primeDifference = ( myInfiniteWalk - myPreviousPrime)/2;  
  myPreviousPrime =  myInfiniteWalk; 
  primeFindsArray[ myPrimeFindsLocal++ ] = primeDifference; 
//if(countThis++ > 1000 ) {cout << "\033[1;1H";
//while(spaceBuffer<singer){cout<< endl; spaceBuffer++;}
//  string128ClassComma  myInfiniteWalkString (  myInfiniteWalk );      cout << myInfiniteWalkString.getString();; spaceBuffer =0; countThis=0;
//}
}
//  cout << "singer "<< int(singer)<< "  difference "; //  cout << int(primeDifference) << endl;
myInfiniteWalk+=2;
 
slice++;
  
}  // ******** WHILE SLICELOOP *******

//__int128 findRatio =int(int(perThreadSlices/myPrimeFindsLocal)); //cout << "singer SIGN "<< int(singer)<< "  array =  ";
//  cout << int( myPrimeFinds ) << " ratio : " << int(findRatio) ; //  cout << int( myPrimeFindsLocal ) << endl;


findsArray[singer]= myPrimeFindsLocal ;



} // LIBRARIAN DANCER FINISH










































































































































































void theConductor(__int128 singers,
                  __int128 perThreadSlices,
                   __int128 mrTsaysRead, __int128 primerBase)
{
                      __int128 infiniteWalk = 5;    __int128 totalTiles = 0; __int128 totalPrimes = 0;
__int128 etchWalk =0;
__int128 primeRatio =0;
__int128 threadPrimeFinds =0;
__int128 singer =0; 
__int128 pDlarge = 228;
__int128 verifyCount =0;
  byte* targetArray = new byte[ singers  ];
  byte* dancerPrimeFinds = new byte[ singers  ];
string gitData="";
  vector<byte*> dancerPrimeFindsArray (  perThreadSlices );  // 88888 INCORPORATE SIZE@PRIMERATIO TO SAVE SPACE IF NEEDED
  vector<byte*> conductorPrimeFindsArray (  perThreadSlices );  // 88888 INCORPORATE SIZE@PRIMERATIO TO SAVE SPACE IF NEEDED

  conductorPrimeFindsArray[singer] = new byte[ perThreadSlices ];

  bool infinite = true;
int conductorClockIns =0;
  string stringBeanTileCount = "";
  string targetTileName = "";
  
  
  vector<std::promise<__int128>> promises(singers);
  vector<std::future<__int128>> futures(singers);

  vector < thread > choir;
      //       menu_gyrogear(primeRatio, tileCount, pDlarge, infiniteWalk, total);

  __int128 conductorCount =1;
//__int128 infiniteWalk =5;
                   __int128 readTileCount = 900;
__int128 tileLay=1;
__int128 tileWalk=0;
__int128 tileWalkData=0;
  byte data =0;
int conductorClockIn = getCurrentTimeInSeconds();
bool iUpdate = true;
int conductorCheckClock =0;
int conductorLastGitUpdate= conductorClockIn ;
int conductorUpdateInterval=600;
int statusUpdates=0;


  __int128 intTail=0;
byte primeDifference =0;
int primerBenchTime =0;
if (mrTsaysRead == true){ primeBasePrimer = grid;}
readTileCount = listBookZip();
  while ( total  <  primeBasePrimer ){ 
  //  cout << int(total)<< "   Total Before primeDivise  " << endl;
if (primeDivise(infiniteWalk)== true){
      primeDifference = (infiniteWalk - previousPrime)/2;  
      previousPrime = infiniteWalk;
      etchTile(primeDifference); 
 //   cout << int(infiniteWalk) << "   infiniteWalk    ";
  //  cout << int(primeDifference) << "   primeDifference" ;
 //   cout << int(total)<< "   Total " << endl;
total++;

    }
   // cout << int(total)<< "   Total After primeDivise  " << endl;
    infiniteWalk+=2;
  //  cout << int(total)<< "   Total After infiniteWalk++  " << endl;
  //  cout << int(infiniteWalk) << "   infiniteWalk    ";
still(0);

}
infiniteWalk+=2;
// string128ClassComma primeBasePrimerString( primeBasePrimer );
 primerBenchTime =  getCurrentTimeInSeconds() - conductorClockIn;
// cout << endl << endl << endl << endl <<"  PrimeBasePrimer : " << // primeBasePrimerString.getString() << " Completed" << endl << endl;

  
// READ TILE ******************************************************
  while (tileLay < readTileCount){
cout << "\033[2;1H";
    extractTile(tileLay);
   // infiniteWalk+=  readPage2Tile(tileLay );

  byte* targetTile = new byte[ grid ];
  string userInput="";
  string128Class tileNumberString ( tileLay );

 // cout << "Begin read page 2 tile " << endl;  //   realm_os_user_input(userInput);



  stringBean2 = tileNumberString.getString();
  string targetTileName = "Tile0" + stringBean2;
  string targetTileNamePath = "PrimeBookOne\\PrimeBookOne\\PrimeBookOne\\Tile0" +  stringBean2 + ".prime";

  //targetTile = tiles[targetTileName];

  //cout << targetTileNamePath << endl;
  //  for (__int128 zeroTile = 0 ; zeroTile < grid; ) {
  // targetTile[zeroTile] = 0 ;
  //zeroTile++;
  // cout << "zeroTile " <<int(zeroTile)  << endl;
  //}

  ifstream input(targetTileNamePath, std::ios::binary);

  if (!input) { std::cerr << "Error opening file: " << targetTileNamePath << std::endl; }

  input.read(reinterpret_cast<char*>(targetTile), grid );

tileWalk =0;
while (tileWalk < grid){

data =  targetTile[tileWalk];
  // cout << " read tile data = " << int( data ) << "  " << int(tileWalk) << "  TileLay : " << int(tileLay) << endl;
  etchTile( data );

//  if (  data == 0 ) {
  //    cout << " read tile data = " << int( data ) << "  " << int(tileWalk) << "  TileNumber : " << int( tileLay) << endl;
    //  realm_os_user_input(userInput);
  // }
   infiniteWalk+=data*2;
   total++;
   tileWalk++;  
}

//cout << " FINISHED read tile data = " <<targetTileNamePath  << endl <<"  totaltiles=" << int(tileWalk) << "  myInfiniteWalk " << int( infiniteWalk ) << endl;

//delete[] targetTile;

tileLay++;
initiateTile(tileLay); 
}
// READ TILE ******************************************************
cout << "\033[2;1H";  //system("cls");
verifyBook(singers);
 infiniteWalk+=2;
while ( infinite == true){
  choir.clear();
conductorCheckClock = getCurrentTimeInSeconds();
if (iUpdate == true && (conductorCheckClock - conductorLastGitUpdate ) > conductorUpdateInterval){
totalTiles = tileCount; totalPrimes = total;

conductorLastGitUpdate = getCurrentTimeInSeconds(); 
statusUpdates++;
    choir.push_back(thread([this,
                            gitData, primeRatio,  pDlarge, infiniteWalk,    conductorCount, totalTiles, totalPrimes
                                      ]() {
                            this->conduit_git(gitData, primeRatio,  pDlarge, infiniteWalk,    conductorCount, totalTiles, totalPrimes
                                      );}));
}
  for (__int128 singer = 0; singer < singers; singer++) {      //   cout << "create singer "<<int(singer)<< endl;
    dancerPrimeFindsArray[singer] = new byte[ perThreadSlices ];
 //            menu_gyrogear(primeRatio, tileCount, pDlarge, infiniteWalk, total);
    // SEND dancerTotals INT and  dancerPrimeFinds Array to each thread
    choir.push_back(thread([this,
                            singer,
                              infiniteWalk,
                                perThreadSlices,

                                    &primeFindsArray = dancerPrimeFindsArray[singer]
                                      ]() {
                            this->librarianDancer(singer,
                              infiniteWalk,
                                perThreadSlices,

                                   primeFindsArray
                                      );}));
    infiniteWalk+=perThreadSlices*2;
  } // FINISH CREATE ALL THREADS
  
    primeRatio = infiniteWalk/total;

     //        menu_gyrogear(primeRatio, tileCount, pDlarge, infiniteWalk, total);


for (auto& t : choir) {
  t.join();

}


 cout << "conductorCheckClock " << conductorCheckClock << "  conductorLastGitUpdate " << conductorLastGitUpdate << "  conductorUpdateInterval " << conductorUpdateInterval << "  statusUpdates : " << statusUpdates << endl;
       //      menu_gyrogear(primeRatio, tileCount, pDlarge, infiniteWalk, total);
  //for (singer = 0; singer < singers; singer++) {
   // dancerPrimeFinds[singer] = futures[singer].get(); // RECEIVE SINGERS PRIME TOTALS
   // conductorPrimeFindsArray[singer] = dancerPrimeFindsArray[singer];
  //    cout << "Conductor Receive from Singer " << int(singer) << " FOUND  ";
  //  cout << int(  dancerPrimeFinds[singer]) << "  " ;
 //  cout <<  "Conductor READ Array " << int(findsArray[singer]) << endl;
  //} // RECEIVE DATA FROM THREADS


choir.front();

for (singer = 0; singer < singers; singer++) {

   targetArray = dancerPrimeFindsArray[singer];

  for ( etchWalk  = 0; etchWalk < findsArray[singer] ; etchWalk++) {
      etchTile( targetArray[etchWalk]);
      total++;
      //  cout << "Singer " << int(singer) << " at etchWalk ";
      // cout << int(etchWalk) << " found difference ";
      // cout <<  targetArray[etchWalk] << endl;

  }

} // FINISH CONDUCTOR ETCH THREAD DATA

} // WHILE INFINITE = TRUE
}





































































































public: // **************** PUBLIC *******************



primeTileClass(__int128 powerOfIN,
               __int128 perThreadSlicesIN,
               __int128 singersIN, 
               __int128 primeBasePrimerIN  ) : powerOf(powerOfIN),
               perThreadSlices(perThreadSlicesIN),
               singers(singersIN),
               primeBasePrimer(primeBasePrimerIN)

{
//  cout << " Initiate prime tile class " << endl;
    cout << "\033[1;1H"; cout << endl;
 // system("tar -cvjf PrimeBookOne\\PrimeBookOne.zip PrimeBookOne\\PrimeBookOneIndex.txt");

  __int128 singersPlus = 0;


                        // **************** // ****************

                        
                       // infiniteWalk = 5 ;
    //                    powerOf = 24 ; // = powerOf ; 24 = 16meg 25 = 32 26 = 64 27 =128 28 =256meg uncompressed tile file
                        singersPlus = singers + 1 ;
                        grid = pow(2,powerOf);
                        
                         
                        // **************** // ****************
                        
                        
  string128ClassComma stringBeanGrid ( grid );
  gridString = stringBeanGrid.getString(); 

string128ClassComma singersPlusString( singersPlus );
string128ClassComma perThreadSlicesString( perThreadSlices);
string128ClassComma primeBasePrimerString( primeBasePrimer);
// string128ClassComma infiniteWalkString( infiniteWalk );
string128ClassComma powerOfString( powerOf);

 // cout << "  PerThreadSlices Song Count " << perThreadSlicesString.getString()  << endl;
//  cout << "  SingersPlus " << singersPlusString.getString()<< endl;
 // cout << "  Tile Grid Width : " << gridString;
 // cout << " @ 2 to the Power of " << powerOfString.getString() << endl;
 // cout << "  PrimeBasePrimer " << primeBasePrimerString.getString() << endl;
//  cout << "  infiniteWalk Start " << infiniteWalkString.getString() << endl;
  
  
  testTile(); 

  initiateTile(0);
  
  threadTotal      = new __int128[ singersPlus ]; 
  threadTileWalk   = new __int128[ singersPlus ]; 
  threadSlateWalk  = new __int128[ singersPlus ]; 
  threadBreezeWalk = new __int128[ singersPlus ]; 
  myTileCount      = new __int128[ singersPlus ]; 
  myEtchWalk       = new __int128[ singersPlus ]; 
findsArray = new __int128[ singersPlus ]; 
}  // PRIMETILECLASS
























































































void carve (__int128 singers) { carveSlate( singers );}
void scribe(__int128 singer, byte data){scribeSlate( singer, data);}
void scrub () { scrubSlate();}
void read () { readSlate();}
void conductor(__int128 singers, __int128 perThreadSlices,  __int128 mrTsaysRead,__int128 primerBase) { theConductor(singers,  perThreadSlices,  mrTsaysRead, primerBase);}
void buildPrimeBase(__int128 singers, __int128 perThreadSlices,  __int128 mrTsaysRead,__int128 primerBase) { primeBase(singers,  perThreadSlices,  mrTsaysRead, primerBase);}


void cleanUpTiles(){ for (auto& pair : tiles) { delete[] pair.second;} }

void rebuildBookIndex() { rebuildIndex(); }

__int128 requestTotal(){ __int128 returnTotalCurrent = primeTotalCurrent() ; return returnTotalCurrent; }

__int128 requestThreadSlicesCurrent(){__int128 returnThreadSlicesCurrent = threadSlicesCurrent(); return perThreadSlices;}
__int128 requestThreadSingersCurrent(){__int128 returnThreadSingersCurrent = threadSingersCurrent(); return singers;}

int getCurrentTimeInSeconds() {
    auto currentTime = std::chrono::system_clock::now();
    auto secondsSinceEpoch = std::chrono::duration_cast<std::chrono::seconds>(currentTime.time_since_epoch());
    return static_cast<int>(secondsSinceEpoch.count());
}


void conduit_git(string gitData, __int128 primeRatio,  __int128 pDlarge,__int128  infiniteWalk,   __int128 conductorCount, __int128 tileCount, __int128 total){

   std::string accessToken ="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";
    std::string owner = "PrimeBookOne";
    std::string repo = "PrimeBookOne.github.io";
    std::string remoteFilePath = "index.html";
    std::string indexOpener = "indexopener.html";
    std::string indexCloser = "indexcloser.html";

    std::string sha = GitHubFileManager::getSHAFromGitHub(accessToken, owner, repo, remoteFilePath);
    std::string currentTime = GitHubFileManager::getCurrentTime();

    std::string primeBookOneIndexStatus = "";

    std::ifstream inputFile(indexOpener);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open local file for reading.");
    }
    std::string indexOpenerContent((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    std::ifstream inputFile2(indexCloser);
    if (!inputFile2.is_open()) {
        throw std::runtime_error("Failed to open local file for reading.");
    }
    std::string indexCloserContent((std::istreambuf_iterator<char>(inputFile2)), std::istreambuf_iterator<char>());
    inputFile2.close();


string128ClassComma primeRatioString( primeRatio );
string128ClassComma totalTilesString( tileCount );
string128ClassComma pDlargeString ( pDlarge );
string128ClassComma infiniteWalkString( infiniteWalk );
string128ClassComma totalPrimesString( total );








    primeBookOneIndexStatus = indexOpenerContent;
    primeBookOneIndexStatus =  primeBookOneIndexStatus + "<h4>Status Updated: " + currentTime;
    primeBookOneIndexStatus =  primeBookOneIndexStatus +  "      Prime Ratio = " + primeRatioString.getString();
    primeBookOneIndexStatus =  primeBookOneIndexStatus +  "      Total Tiles = " + totalTilesString.getString();

    primeBookOneIndexStatus =  primeBookOneIndexStatus +  "      Largest Difference = " + pDlargeString.getString() ;
    primeBookOneIndexStatus =  primeBookOneIndexStatus +  "      infiniteWalk = " + infiniteWalkString.getString();
    primeBookOneIndexStatus =  primeBookOneIndexStatus +  "      Total Primes = " + totalPrimesString.getString();
    primeBookOneIndexStatus =  primeBookOneIndexStatus +   "</h4>" ;
    primeBookOneIndexStatus =  primeBookOneIndexStatus + indexCloserContent;








//    primeBookOneIndexStatus = indexOpenerContent + "<h1>Status Updated: " + currentTime + "</h1>" + indexCloserContent;

  //  std::cout << "primeBookOneIndexStatus: " << primeBookOneIndexStatus << std::endl;

    GitHubFileManager fileManager;
    fileManager.updateFileOnGitHub(accessToken, owner, repo, remoteFilePath, primeBookOneIndexStatus, sha);


}

















































}; // PRIMETILE CLASS



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

void realm_conduit();

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
string realm_unique_id(string randomString3);
void realm_gl_cores_gpufort(); 
void realm_os_menu();
int realm_sw_array_Flexor();
void realm_gl_cuda_devices(int gpuIndex);
vector<DISPLAY_DEVICE> realm_gl_cores_cuda();
void realm_gl_cuda_devices(int gpuIndex);
void realm_sw_variable_primer(__int128 perThreadSlices, bool mrTsaysRead, __int128 singers, __int128 primerBase, __int128 powerOf);

void realm_sw_divisor_dancer(__int128 singer, __int128 singersDigitSize, primeTileClass PrimeOne );
void menu_gyrogear( __int128 primeRatio, __int128 totalTiles, __int128 pDlarge, __int128 infiniteWalk, __int128 totalPrimes );
void menu_book( __int128 slices , __int128 primer , __int128 singers , __int128 powerOf ) ;
void realm_os_user_input(string&validUserInput);
void menu_librarian();
void librarian_functions( string hostIp, int hostPort, int optionCores, string optionMenue );
void realm_gpu_primer();
string realm_win_archive();
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

void realm_win_host_send_data();
void realm_win_updater( bool isHost, string guestName, string guestIP, string guestPort, string hostIP, string hostPort, string uniqueFileName);
void realm_win_handles_thread();
bool realm_win_port_check( string checkPort );
void realm_os_tcp_host( );
void realm_os_tcp_guest( string remoteHostIPv4 );
void realm_win_ipconfig( );
void realm_win_roll();
string getCurrentTimeInSecondsString();
string realm_unique_time_stamp();

int getCurrentTimeInSecondsInt();
int realm_conduit_win_guest( string uniqueId, int conduit, int myPort, string myIP, int remotePort, string remoteIP, string instruction, string randomString1, string randomString2, string randomString3 );











































































































































































































































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



public:

bool pen16(byte data){ lineCount++;
  //if ( data <= 15){ primeBook << hex << data; }
  //if ( data > 15 && data < 256){ primeBook << endl << hex << data; lineCount++;}
  //if ( data > 255) {primeBook << endl << "0" << hex << data; lineCount++; }
  //   cout << int(lineCount) << "lineCount "<< endl;
  if (lineCount == lineCountMax){
    //   cout << int(lineCountMax) << "lineCountMax "<< endl;
    lineCount=0;
    return true;
  }
  else {
    return false;
   }
} // pen16 function




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
   
} // unCapPen function




void printMileStone( __int128 pDlarge, __int128 infiniteWalk, __int128 total ){

  string stringBean;
  string  stringBean2;
  string  stringBean3;
  string128Class pDlargeString ( pDlarge );  
  stringBean = pDlargeString.getString();

  string128Class infiniteWalkString ( infiniteWalk );  
  stringBean2 = infiniteWalkString.getString();

  string128Class totalString ( total );  
  stringBean3 = totalString.getString();

  string printThis = "";
  printThis = "Prime Difference Largest : ";
  printThis = printThis + stringBean;
  printThis = printThis + " Prime: ";
  printThis = printThis + stringBean2 ;
  printThis = printThis + " Total : ";
  printThis = printThis + stringBean3 ;

  primeMileStones << printThis << endl;
  cout << "\033[1;1H";
  cout << "                   : Totals           ";
  cout << printThis << endl;
  cout.flush();
  
} // printMileStone function





void mark( __int128 data ){
  string128Class dataString( data );   
  string stringBean= dataString.getString();
  cout << "\033[1;1H";
  cout <<  stringBean << endl;
  cout.flush();
  primeCobbleStones << stringBean << endl;
} // mark function



void capPen(){
  primeBook.close(); 
} // capPen function



};














class RandomSeedProvider
{



public:
    RandomSeedProvider() {
        // Seed the random number generator with the current time in the constructor
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
    }

    int getRandomNumber(int max) {
        std::lock_guard<std::mutex> lock(mutex);  // Lock to ensure thread safety
        return std::rand() % max;
    }

private:
    std::mutex mutex;  // Mutex for thread safety
};

class StringGenerator {
public:
    StringGenerator(RandomSeedProvider& seedProvider) : seedProvider(seedProvider) {}

    std::string generateRandomString(int length) {
        std::string randomString;
        for (int i = 0; i < length; ++i) {
            randomString += charset[seedProvider.getRandomNumber(charsetSize)];
        }

     //   std::cout << "Random String " << randomString << std::endl;

        return randomString;
    }

private:
    static const char charset[];
    static const int charsetSize = 11; // Adjusted size
    RandomSeedProvider& seedProvider;
};









































































































class conduitClass
{
private:  // **************** PRIVATE *******************


int* hostGuestListArrayFreshness00;
string* hostGuestListArray00;
int maxHostConduits = 9999;
int maxGuestConduits = 9999;
string* guestCheck;
int dataPort =4321;
int* hostGuestListArrayFreshnessCurrent00;
int totalGuests=0;
__int128 weaverData00;

string* hostGuestPortListArray00; string* hostGuestIpListArray00;

string* guestPortListArray00;

 __int128 globalMyMiles=0;
bool globalAllTorchesPassed = false;

 string globalNewHostIp =  "";

string globalNewHostName = "";
bool globalBecomeHost = false;
bool globalNewHost = false;
    int hostCount;
int claimedPort00 = globalNewHostPort;
int guestClaimedPort00 = globalNewHostPort;
int myMiles; int maxMiles;
int remainingGuests;
string* guestReturnArray;

int* guestReturnPortArray;

string* guestReturnIpArray;

string* guestReturnGearArray;
































 void conduit_win_hosts( __int128 weaverDataHost, string uniqueId, string randomString1, string randomString2, string randomString3, bool firstPassTorch, bool passTorch, int weavePort )
{
 int conduits = 1;

string instruction; int assignedPort = weavePort; string assignedIP; int remotePort; string remoteIP;
int hostConduits = conduits;
int guestConduits = conduits;
int conduitCount =0;










vector< thread > choir;


  choir.clear();

//cout << "  for (conduit = 0; conduit < hostConduits; conduit++) {" << endl;
  for ( int conduit  = 0; conduit < conduits; conduit++) {
// cout << "create conduit "<<int(conduit)<< " of total created: " << ++conduitCount << endl;









 choir.push_back(thread([this,
uniqueId, conduit, assignedPort,  assignedIP,  remotePort,  remoteIP, instruction, randomString1,
randomString2, randomString3, firstPassTorch, passTorch



                                      ]() {
                            this->conduit_win_host(
uniqueId, conduit, assignedPort,  assignedIP,  remotePort,  remoteIP, instruction, randomString1,
randomString2, randomString3, firstPassTorch, passTorch


                                      );}));
  }



//cout << " created threads = " << int(conduits) << endl;
  for (auto& t : choir) {
   t.join();
 }

  choir.front();

} //END FUNCTION












void conduit_win_guests( __int128 weaverDataGear, string uniqueId, string randomString1, string randomString2, string randomString3, bool& weaveHost, int&weavePort, int& returnData, int&weavePortHost, int&weaveNewPort )
{
bool infinite = true;
int conduits = 1;
string instruction; int assignedPort; string assignedIP; int remotePort; string remoteIP;
int hostConduits = conduits;
int guestConduits = conduits;
string userInput ="";


int gatherData =0;


    const int numThreads = 1000;
    int dataReturnArray[numThreads];

vector< thread > choir;
    std::vector<std::promise<int>> promises;



  choir.clear();
 promises.clear();
//cout << "  for (conduit = 0; conduit < hostConduits; conduit++) {" << endl;
  for ( int conduit  = 0; conduit < conduits; conduit++) {
 //cout << "create conduit "<<int(conduit)<< endl;
remotePort = weavePort;
//remoteIP = guestReturnIpArray[0];
//instruction = guestReturnGearArray[0];
            promises.emplace_back();
    choir.push_back(thread([conduit](string  uniqueId, int conduit, int assignedPort,  
                                        string assignedIP,  int remotePort,  string remoteIP, string  instruction, string  randomString1, string randomString2, string randomString3,  promise<int>& p) {
                                            p.set_value(realm_conduit_win_guest( uniqueId, conduit, assignedPort,  
                                            assignedIP,  remotePort,  remoteIP, instruction, randomString1, randomString2, randomString3 ));
                                        }, uniqueId, conduit, assignedPort,  
                                        assignedIP,  remotePort,  remoteIP, instruction, randomString1, randomString2, randomString3, ref(promises[conduit])));

//if ( guestWaitTime00 == true){
//std::this_thread::sleep_for(std::chrono::seconds(3));
//}
  } //create conduit loop
//cout << " created threads = " << int(conduits) << endl;

  for (int i = 0; i < hostConduits; ++i) {
gatherData = promises[0].get_future().get();
   choir[i].join(); }  
if(gatherData == 1){ 
//cout << "Returned to Become Host" << endl;  
//realm_os_user_input(userInput); 
weavePortHost = globalNewPort[0];   weaveHost = true;
}
if(gatherData == 2){ 
weavePort=globalNewPort[0];
// weaveip=
}
  choir.front(); promises.front();
 } // END FUNCTION






void conduit_win_host( string uniqueId, int conduit, int myPort, string myIP, int remotePort, string remoteIP, string instruction, string randomString1, string randomString2, string randomString4, bool firstPassTorch, bool passTorch )
{
bool searchComplete = false;    int guestCurrentTime =0; int guestFreshness=0; int currentTime =0; int freshness =0; int staleTime=0;
 string guestName = "";  bool updateGear = false;  bool updateBook =false ; 
bool isHost = true; bool infiniteWalkGuest = false; string guestIp = "127.000.000.001" ; string guestPort = "55555"; string hostIp= "127.000.000.001"; string hostPort = "55555"; string uniqueFileName ="";
 string text_post = ""; int tileCount =0;   string primaryWolfPackId = realm_unique_id(randomString4);
  string userInput; int remotePortInt=0;
bool yesContinue=true; string guestIPstring="";
 bool socketSearch=true;
  int PORTgrow = myPort;
   bool sendForever=true;
    int ARRAY_SIZE = 99999;  // cout << " ARRAY_SIZE " <<  ARRAY_SIZE << endl;
bool receiveForever=true;
 int dataSend=0;
  bool socketForever=true;
   bool printForever=true;
    string delString;
int MAX_BUFFER_SIZE = 99999;
int totalSends=0;
 int allData=0;                    string    remotePortString = "";
  int* array = new int[ARRAY_SIZE];
//  cout << "H Initialize Winsock" << endl;
bool foundGuest = false;   int guestCheck =0; 
WSADATA wsData;
WORD ver = MAKEWORD(2, 2);
int wsOk = WSAStartup(ver, &wsData);

if (wsOk != 0){
  cerr << "H Can't initialize Winsock! Quitting" << endl;
  return;
}

//cout << "H Create socket" << endl;
SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

if (sock == INVALID_SOCKET) {
   cerr << "H Can't create socket! Quitting" << endl;
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
//         cout << "H  Port Attempt: " << ntohs(hint.sin_port) << endl;
     int bindResult = bind(sock, reinterpret_cast<sockaddr*>(&hint), sizeof(hint));

     if (bindResult != SOCKET_ERROR){
   //          cout << "H  HOST Created at IP :  " << ipAddress ;
    //         cout << " Port: " << PORTgrow << endl;
     }
     if (bindResult == SOCKET_ERROR){
//        PORTgrow+=3;
     }



    else {socketSearch=false;};

   }  // WHILE socketSearch==true  // cout << "Socket Connected Successfully" << endl;

// claimedPort00=PORTgrow;

//cout << "H HOST uniqueId: " << uniqueId<<":"<< conduit << "IP Address 127.0.0.1:" << claimedPort00<< endl;






































bool hostStayOpen = true;

/*H*/  while (hostStayOpen){  


/*H*/  // while (PORTgrow == PORT){  // Listen for incoming connections

/*H*/      if (listen(sock, SOMAXCONN) == SOCKET_ERROR){
/*H*/         //**  cerr << "H Can't listen on socket! Quitting" << endl;
/*H*/         closesocket(sock);
/*H*/         WSACleanup();
/*H*/         return;
/*H*/      }  // SOCKET ERROR
    string128Class claimedPort00String( myPort ); string portString = claimedPort00String.getString() ; 
//cout << "H Awaiting Gear Connection : Host uniqueId: " << uniqueId<< "IP Address 127.0.0.1:" << portString << endl << endl;

/*H*/      sockaddr_in client{};
/*H*/      int clientSize = sizeof(client);

/*H*/      fd_set readSet;
/*H*/      FD_ZERO(&readSet);
/*H*/      FD_SET(sock, &readSet);

/*H*/      timeval timeout;
/*H*/      timeout.tv_sec = 25;  // 5 seconds timeout
/*H*/      timeout.tv_usec = 0;

/*H*/      int result = select(0, &readSet, nullptr, nullptr, &timeout);

/*H*/      if (result == SOCKET_ERROR) {
/*H*/          cerr << "Error in select function!" << endl;
/*H*/          closesocket(sock);
/*H*/          WSACleanup();
/*H*/         delete[] array;


/*H*/          return;
/*H*/      }
/*H*/      else if (result == 0) {
/*H*/          // Timeout occurred
/*H*/          cerr << "Timeout waiting for client connection!" << endl;                     if ( myMiles > maxMiles) {remainingGuests = -1;};
/*H*/          closesocket(sock);
/*H*/          WSACleanup();
/*H*/         delete[] array;

/*H*/          return;
/*H*/      }

/*H*/      SOCKET clientSocket = accept(sock, reinterpret_cast<sockaddr*>(&client), &clientSize);

/*H*/      if (clientSocket == INVALID_SOCKET){
/*H*/         //**  cerr << "H Can't accept client Invalid Socket! Quitting" << endl;
/*H*/         closesocket(sock);
/*H*/         WSACleanup();
/*H*/         delete[] array;

/*H*/         return;
/*H*/      } // INVALID SOCKET




/*H*/      char computerName[MAX_COMPUTERNAME_LENGTH + 1];
/*H*/      DWORD computerNameSize = sizeof(computerName);

/*H*/      char service[NI_MAXSERV];   // Service (i.e., port) the client is connected on
/*H*/      char host[NI_MAXHOST];      // Client's remote name

/*H*/      ZeroMemory(host, NI_MAXHOST);
/*H*/      ZeroMemory(service, NI_MAXSERV);


/*H*/      if (GetComputerName(computerName, &computerNameSize)){
/*H*/     //     cout << "H  HOST name: " << computerName << endl;
/*H*/      }

/*H*/      else{
/*H*/         //** cerr << "H Failed to retrieve computer name!" << endl;    //    return 1;
/*H*/      }

/*H*/      //  Get information about the client
/*H*/      if (getnameinfo(reinterpret_cast<sockaddr*>(&client), clientSize, host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0){
/*H*/          sockaddr_in clientAddr;
/*H*/          int clientAddrLen = sizeof(clientAddr);
/*H*/          getpeername(clientSocket, (sockaddr*)&clientAddr, &clientAddrLen);

/*H*/          // Manually convert IP address to string
/*H*/          char guestIP[INET_ADDRSTRLEN];
/*H*/          inet_ntop(AF_INET, &clientAddr.sin_addr, guestIP, INET_ADDRSTRLEN);

/*H*/          std::cout << "Guest IP: " << guestIP << ":" << service;
guestIPstring = guestIP;
/*H*/          cout << "   Peer Name: " << host;
/*H*/          cout << "  " << computerName << endl;

/*H*/      }
















/*H*/      else{ }
/*H*/      //**   cout << "H Connected on port NTOS " << ntohs(client.sin_port) << " to " << host << endl; }
// cout << " additionalDataBuffer begin" << endl;

// guest receive


char additionalDataBuffer[MAX_BUFFER_SIZE];

int additionalDataSize = recv(clientSocket, additionalDataBuffer, MAX_BUFFER_SIZE, 0);

string guestDataAll = "";
string guestDataShrinking = "";

string guestData2 = "";
string guestData3 = "";
string guestData4 = "";
string guestData5 = "";
string guestData6 = "";
string guestData7 = "";
string guestData8 = "";
string guestData9 = "";
string guestData10 = "";


if (additionalDataSize > 0) {

string additionalDataReceived(additionalDataBuffer, additionalDataSize);

guestDataAll = additionalDataReceived;

guestData2 = guestDataAll.substr(0,10);  // gearBuildString 10 digits
guestDataShrinking = additionalDataReceived.erase(0, 10);

guestData3 = guestDataShrinking.substr(0,50);  // myUniqueLoginKeyString 50 digits
guestDataShrinking = additionalDataReceived.erase(0, 50);

guestData4 = guestDataShrinking.substr(0,15);  // hostIp00String 15 digits
guestDataShrinking = additionalDataReceived.erase(0, 15);

guestData5 = guestDataShrinking.substr(0,5);  // claimedPort00String //5digits
guestDataShrinking = additionalDataReceived.erase(0, 5);

guestData6 = guestDataShrinking.substr(0,33);  // UniqueId   // 10 digits 
guestDataShrinking = additionalDataReceived.erase(0, 33);

guestData7 = guestDataShrinking.substr(0,20);  // tileCountString = "01234567890123456789";   // 20 digits 
guestDataShrinking = additionalDataReceived.erase(0, 20);

guestData8 = guestDataShrinking.substr(0,33);  // wolfPackIdString = uniqueId;   // 10 digits 
guestDataShrinking = additionalDataReceived.erase(0, 33);

guestData9 = guestDataShrinking.substr(0,10);  // wolfHungerString = "1234512345";   // 10 digits 
guestDataShrinking = additionalDataReceived.erase(0, 10);

guestData10 = guestDataShrinking;   // myPreferredUserHandleString ="jasonisaachuffbrodsky";  // no digit limit but string variable roof 


__int128 guestData2Int ;
guestData2Int = StringTo128Class::stringToInt128( guestData2 );
/*
//cout << "guestData  All: " << guestDataAll << endl << endl;
cout << "guestData2 gearBuildString              : " << guestData2 << "   gearBuildString " << endl;
cout << "guestData3 myUniqueLoginKeyString       : " << guestData3 << "   myUniqueLoginKeyString " << endl;
cout << "guestData4 hostIp00String               : " << guestData4 << "   hostIp00String " << endl;
cout << "guestData5 claimedPort00String          : " << guestData5 << "   claimedPort00String " << endl;
cout << "guestData6 UniqueId                     : " << guestData6 << "   UniqueId   " << endl;
cout << "guestData7 tileCountString              : " << guestData7 << "   tileCountString " << endl;
cout << "guestData8 wolfPackIdString             : " << guestData8 << "   wolfPackIdString " << endl;
cout << "guestData9 wolfHungerString             : " << guestData9 << "   wolfHungerString " << endl;
cout << "guestData10 myPreferredUserHandleString : " << guestData10 << "   myPreferredUserHandleString " << endl;
*/



//cout <<  "H from Gear "<< additionalDataBuffer << " 127.0.0.1:" << service << " x64 "<< computerName<<endl;







} else {
cout << "H Data Receive Error from Guest Gear"<< endl;
}





/*H*/    //      realm_os_user_input(userInput);


 bool updateGear = false;
bool updateBook = false;
bool infiniteWalkGuest = false;


    __int128 guestBuild = StringTo128Class::stringToInt128( guestData2 );
    __int128 guestTileCount = StringTo128Class::stringToInt128( guestData7 );
    __int128 guestHostclaimedPort00 = StringTo128Class::stringToInt128( guestData5 );
        string guestHostIp00String = guestData4;
__int128 gearBuild  = 1018;

if ( guestBuild  < gearBuild) {

updateGear = true;

}


if (guestTileCount< tileCount){

updateBook = true;

}


if ( updateGear == false && updateBook == false){

infiniteWalkGuest = true;

}






























//system ("cls");

// parse guest

foundGuest = false; 
guestCheck =0;
searchComplete = false;
//cout << "Hp Check for "<< guestData << " in GuestList with total guests: " << totalGuests<<endl;

while (searchComplete == false ){        //  cout << "Hp hostGuestListArray00[guestCheck]: "<<hostGuestListArray00[guestCheck] << endl;
   if ( guestData6 == hostGuestListArray00[guestCheck]){
       guestCurrentTime = getCurrentTimeInSeconds();
       guestFreshness = guestCurrentTime - hostGuestListArrayFreshness00[guestCheck] ;
       hostGuestListArrayFreshness00[guestCheck] = guestCurrentTime;
       searchComplete = true;
       guestPortListArray00[guestCheck] = service;
        hostGuestPortListArray00[totalGuests] = guestIPstring;

//      cout << "Hp Return Guest: " << guestData << " Freshness: " << guestFreshness << endl;
    } else {
        guestCheck++;
}
    if ( guestCheck >= totalGuests ) {
       hostGuestListArray00[totalGuests] = guestData6 ;   // name of guest peer
    //   hostGuestPortListArray00[totalGuests] = guestData2;  //guest peer stated Port
        hostGuestPortListArray00[totalGuests] = service;  // actual peer port as received
        hostGuestIpListArray00[totalGuests] = guestIPstring;
       hostGuestListArrayFreshness00[totalGuests] = getCurrentTimeInSeconds();

       searchComplete = true;
       totalGuests++;
   //    cout << "Hp New gear: "<< hostGuestListArray00[totalGuests]<< endl;

}
} //while foundGuest or searchComplete = false


 cout << "\033[3;1H" <<"H: " << myPort << " G Total: "<< (totalGuests) << "   " << endl;
//cout << endl << "Hp "<< uniqueIdGlobal << " Host:  127.0.0.1:"<< myPort << "   List All Guests total: "<< (totalGuests+2) << endl;
//cout << "Freshness : Roof : userUniqueID : Handle : totalFinds  : Gear PP/M : Rhombus Reliability : infiniteWalk : pieSlice" << endl;

currentTime =getCurrentTimeInSeconds();
guestCheck =0;
while (guestCheck < totalGuests ){ 
 //  cout << hostGuestListArray00[guestCheck];
freshness = ( currentTime - hostGuestListArrayFreshness00[guestCheck] ) ;
hostGuestListArrayFreshnessCurrent00[guestCheck] = freshness;
//cout << "     " << freshness<< "     jasonisaachuffbrodsky";

//cout << "   127.0.0.1:"<<hostGuestPortListArray00[guestCheck];
//cout << "   127.0.0.1:"<< guestPortListArray00[guestCheck] << endl;





guestCheck++;
}




























// remove stale gears
staleTime = 125;
guestCheck=0;
while (guestCheck < totalGuests ){ 

if ( hostGuestListArrayFreshnessCurrent00[guestCheck] > staleTime){
    cout << "Stale Gear " << hostGuestListArrayFreshness00[guestCheck] << " removed from list"<< endl;
    hostGuestListArray00[guestCheck] = hostGuestListArray00[totalGuests-1];
    hostGuestIpListArray00[guestCheck] = hostGuestIpListArray00[totalGuests-1];
    hostGuestPortListArray00[guestCheck] = hostGuestPortListArray00[totalGuests-1];
    hostGuestListArrayFreshness00[guestCheck] =  hostGuestListArrayFreshness00[totalGuests-1] ;
hostGuestListArrayFreshnessCurrent00[guestCheck] = hostGuestListArrayFreshnessCurrent00[totalGuests-1]; 
    totalGuests--;

} else {
   guestCheck++;
}


}

























// host send



 


int totalInstructionLines = 6 + (3*totalGuests);
string hostFileName = "pb1_" + randomString2+realm_unique_time_stamp() +".txt";


// hostCREATEinstructions




    // Open the file for writing
    ofstream outputFile(hostFileName );
    if (outputFile.is_open()) {



        outputFile << "0" << endl;
        outputFile << "total instruction lines" << endl;
        outputFile << totalInstructionLines << endl;
        outputFile << " " << endl;
        outputFile << uniqueId << endl;
        outputFile << " " << endl;

        outputFile << "1" << endl;
        outputFile << primaryWolfPackId << endl;
        outputFile << totalGuests << endl;



        guestCheck =0;
        while (guestCheck < totalGuests ){ 
           outputFile << hostGuestListArray00[guestCheck] << endl;
           outputFile << hostGuestIpListArray00[guestCheck] << endl;
           outputFile << hostGuestPortListArray00[guestCheck] << endl;
           guestCheck++;
}
guestCheck=0;
if (updateGear){
        outputFile << "2" << endl;
// reconnect at specified ip and port as guestUpdater            
           outputFile << "127.0.0.1" << endl;
        outputFile << "hostGearUpdaterPort" << endl;
}



if (updateBook){
        outputFile << "3" << endl;
// reconnect at specified ip and port as tileUpdater
           outputFile << "127.0.0.1" << endl;
        outputFile << "hostTileUpdaterPort" << endl;
}

if ( infiniteWalkGuest ){
        outputFile << "4" << endl;
// inFiniteWalk this pieSlice
           outputFile << "124163033469" << endl;
        outputFile << "1048576" << endl;
}


        outputFile << "5" << endl;
// return foundPrimes to assigned primeFindsUpdaterPort
           outputFile << "124163033469" << endl;
        outputFile << "1048576" << endl;



if(firstPassTorch) {
     remoteIP = guestIPstring;

//int to string service
//int to string
globalNewHostPort = StringTo128Class::stringToInt128( service ); 
     globalRemotePortString = service;
     globalRemoteIpString = guestIPstring;
     globalRemoteNameString  =  host;
     passTorch = false;
     firstPassTorch = false;
 //    verifyTorchPass = true;


        outputFile << "6" << endl; // become host
           outputFile << globalRemoteIpString.c_str() << endl;
              outputFile <<  globalRemotePortString.c_str() << endl;
        outputFile << " " << endl;
           outputFile << globalRemoteNameString.c_str() << endl;
        outputFile << " " << endl;
}


if (passTorch){  // next run connect to new host


        outputFile << "7" << endl; // become host
           outputFile << globalRemoteIpString.c_str() << endl;
              outputFile <<  globalRemotePortString.c_str() << endl;
        outputFile << " " << endl;
           outputFile << globalRemoteNameString.c_str() << endl;
        outputFile << " " << endl;
}







        outputFile << endl << endl;

        // Close the file
        outputFile.close();
     //  cout << "H File " << hostFileName << " created and filled with content." << endl;
































    } else {
        cerr << "Create Instructions Unable to open the file for writing." << endl;
    }



// cout << "H to Send " << uniqueId<<":"<< conduit << " 127.0.0.1:" << claimedPort00 << " x64 " << host << endl;
// cout <<  "H  to Gear "<< additionalDataBuffer << " 127.0.0.1:" << service << " x64 "<< computerName<<endl;
/*H*/      vector<char> data;
/*H*/      ifstream original(hostFileName, ios::binary);
/*H*/      if (original) {
/*H*/         // Read the contents of the file into the vector variable
/*H*/         istreambuf_iterator<char> start(original), end;
/*H*/         data.assign(start, end);
/*H*/         original.close();
/*H*/         delString = "echo off & del " + hostFileName;
/*H*/         system(delString.c_str());

/*H*/      } else {
/*H*/         //** cerr << "H Failed to open 'original.zip' file" << endl;
/*H*/         closesocket(sock);
/*H*/         WSACleanup();
/*H*/         return;
/*H*/      }

/*H*/      while (sendForever) {

/*H*/         int remainingData = data.size() - dataSend;
/*H*/         int bytesToSend = min(remainingData, static_cast<int>(ARRAY_SIZE * sizeof(char)));
/*H*/         int bytes_sent = send(clientSocket, reinterpret_cast<char*>(data.data()) + dataSend, bytesToSend, 0);

/*H*/         if (bytes_sent == SOCKET_ERROR) {
/*H*/            cerr << "send() failed error: " << WSAGetLastError();
/*H*/            break;

/*H*/         } else if (bytes_sent <= 0) {
/*H*/               cerr << "H Failed to send data" << endl;
/*H*/            break;

/*H*/         } else {
/*H*/        //    cout << "H totalDataSends: " << totalSends++ << endl;
/*H*/            //  cout.flush();
/*H*/            dataSend += bytes_sent;
/*H*/         }



/*H*/         if (dataSend >= data.size()) {
/*H*/           closesocket(sock);
/*H*/           WSACleanup();
/*H*/          delete[] array;
/*H*/           return;

/*H*/             break;  // Break out of the loop when all data has been sent
/*H*/         }  // datasend SIZE
/*H*/      }     //   WHILE (sendForever)























/*H*/  // }        // WHILE (PORTgrow == PORT)
//cout << "H -----------------------------------------------" << endl;
} // WHILE hostStayOpen
}           // WHILE SOCKETFOREVER == TRUE
delete[] array;
delete[] array;





if (updateGear == true){
string updaterFileName = realm_win_archive();
realm_win_updater(  isHost,  guestName, guestIp,  guestPort,  hostIp,  hostPort,  uniqueFileName );

}


if ( updateBook == true && updateGear == false ) {


}


if ( infiniteWalkGuest == true) {


}


























} // END HOST FUNCTION


































































void conduit_weaver( string uniqueIdGlobal, bool createHostCommand,__int128 weaverBeginData, string hostIp, int hostPort)
{
__int128 weaverHostData; int weaveNewPort =0;
    RandomSeedProvider seedProvider;
    StringGenerator stringGenerator(seedProvider);
    bool passTorch = false;  string userInput ="";
   std::string randomString1 ;
    std::string randomString2 ;
    std::string randomString3 ;
randomString3 = stringGenerator.generateRandomString(11);
string uniqueId = realm_unique_id(randomString3);
bool weaveHost =createHostCommand;
int weavePort = globalNewHostPort;                
bool weaveNewHost=false;
bool firstPassTorch = false;
int conduits = 1; 
bool infinite = true; 
int choirSize=0;                    globalNewPort[0] =hostPort;
string instruction; int assignedPort = globalNewHostPort ; string assignedIP; string remotePort; string remoteIP;
int hostConduits = conduits;
int guestConduits = conduits;
int conduitCount =0;
__int128 weaverDataHost = 0;
__int128 weaverDataGear = 0;
bool weaveForever=true;
int returnData=1;
int myConnectAttempts =0 ;
globalGuestNewHost[0] = false;   globalGuestBecomeHost[0] = false;
int weavePortHost = globalNewHostPort ; if ( hostPort != 0){    weavePortHost = hostPort ;   }
while (weaveForever){

   randomString1 = stringGenerator.generateRandomString(15);
   randomString2 = stringGenerator.generateRandomString(15);
   randomString3 = stringGenerator.generateRandomString(15);

if (remainingGuests == -1){ 
    weaveHost = false;
    weavePort = globalNewHostPort;
    myMiles=0;
    // system("cls");
    passTorch = false;
    firstPassTorch = false;
    // cout << "Remaining Guests = -1 : globalNewHostPort:" <<  globalNewHostPort<< endl;  realm_os_user_input( userInput ); 
    weaveNewPort= globalNewHostPort;  
    //weaveHost = globalNewHostPort;  weavePortHost= globalNewHostPort;
  };
   if ( weaveHost ){

      for ( int conduit  = 0; conduit < conduits; conduit++) {

         if ( myMiles == maxMiles ){ firstPassTorch = true; passTorch = true;}
         if ( myMiles  > maxMiles ){ firstPassTorch = false; passTorch = true ;  }
//system("cls");
// cout << "\033[1;1H"<< "H:  "<< weavePortHost  << " Miles: " << myMiles << " Hosted: "<< hostCount++ << endl;  realm_os_user_input(userInput);
cout << "\033[1;1H" <<"H " << uniqueId << endl;
            conduit_win_hosts( weaverHostData, uniqueId, randomString1,
                               randomString2, randomString3, firstPassTorch, passTorch, weavePortHost );



myConnectAttempts =0 ;
            myMiles++;
            firstPassTorch = false;

  } // CREATE HOST CONDUITS

} else { 
  totalGuests=0;
 remainingGuests = 0;     
// system("cls");
// cout << "\033[1;1H"<< "G: "<< uniqueId << " "  << weavePort << " " << weavePortHost << " " << weaveNewPort  << " " <<  myConnectAttempts << "     " <<endl; realm_os_user_input(userInput);
//cout << uniqueId << endl;
   conduit_win_guests(weaverDataGear, uniqueId, randomString1, 
                      randomString2, randomString3, weaveHost, weavePort, returnData, weavePortHost, weaveNewPort );
            myMiles=0; myConnectAttempts++;
}
} // WEAVE FOREVER
} //END FUNCTION


















public: // **************** PUBLIC *******************


conduitClass(int dataPortIN) : dataPort(dataPortIN)

{
hostGuestListArrayFreshnessCurrent00  = new int[ maxGuestConduits ]; 
hostGuestListArrayFreshness00  = new int[ maxGuestConduits ]; 
//cout<<"conduitCLass Begin " << dataPort<< endl;
hostGuestListArray00      = new string[ maxGuestConduits ]; 
//vector<string*> hostsGuestArrays (  maxGuestConduits  );  
string* hostGuestList ; hostGuestList = new string[maxGuestConduits];
string* guestCheck ; guestCheck = new string[maxGuestConduits];
totalGuests  =0;
 hostGuestPortListArray00  = new string[ maxGuestConduits ];       hostGuestIpListArray00  = new string[ maxGuestConduits ]; 
weaverData00 = 0;
 guestPortListArray00  = new string[ maxGuestConduits ]; 
 myMiles =0;
 maxMiles =200;
remainingGuests=0;
string* guestReturnArray = new string[ 1 ]; 
hostCount=0;
int* guestReturnPortArray = new int[ 1 ];
guestReturnPortArray[0] = globalNewHostPort;
string* guestReturnIpArray = new string[ 1 ]; 

string* guestReturnGearArray = new string[ 1 ]; 

}


string getCurrentTimeInSecondsString() {
    auto currentTime = std::chrono::system_clock::now();
    auto secondsSinceEpoch = std::chrono::duration_cast<std::chrono::seconds>(currentTime.time_since_epoch());
    int returnInt =  static_cast<int>(secondsSinceEpoch.count());
    string128Class timeInSeconds( returnInt );
 return timeInSeconds.getString();


}


int getCurrentTimeInSeconds() {
    auto currentTime = std::chrono::system_clock::now();
    auto secondsSinceEpoch = std::chrono::duration_cast<std::chrono::seconds>(currentTime.time_since_epoch());
    return static_cast<int>(secondsSinceEpoch.count());
}

void weaverBegin( string uniqueIdGlobal, bool createHost,__int128 weaverBeginData, string hostIp, int hostPort ){

         conduit_weaver(uniqueIdGlobal, createHost, weaverBeginData, hostIp, hostPort );

}

























};































const char StringGenerator::charset[] = "jasonisaacbrodsky03091976";









































































int main(int argc, char* argv[])
{
string text_function_name="main"; string text_post = "";
// realm_gl_querry();
//heartbeat();
//gyrocore();
//sw_purchase_verify();
//realm();




string userInput= "";
    string hostIp="null";
    int hostPort = 0;

    bool optionO = false;
    int optionCores = 0;
    string optionMenueInput ="null";

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-o") {
            optionO = true;
        } else if (arg == "-c" && i + 1 < argc) {
            std::istringstream stream(argv[i + 1]);
            stream >> optionCores ;
            if (stream.fail()) {
                std::cerr << "Invalid argument for -a. Expected integer." << std::endl;
                return 1;
            }
            ++i; // Skip the next argument since it's already processed
        } else if (arg == "-m" && i + 1 < argc) {
            optionMenueInput = argv[i + 1];
            ++i; // Skip the next argument since it's already processed

        } else if (arg == "-ip" && i + 1 < argc) {
            hostIp = argv[i + 1];
            ++i; // Skip the next argument since it's already processed


        } else if (arg == "-p" && i + 1 < argc) {
            std::istringstream stream(argv[i + 1]);
            stream >> hostPort ;  globalNewHostPort = hostPort;
            if (stream.fail()) {
                std::cerr << "Invalid argument for -p. Expected integer." << std::endl;
                return 1;
            }
            ++i; // Skip the next argument since it's already processed


        } else {
            std::cerr << "Invalid argument: " << arg << std::endl;
        }
    }

    // Print the results
//    std::cout << "Option -o: " << std::boolalpha << optionO << std::endl;
//    std::cout << "Option -c: " << optionCores << std::endl;
//    std::cout << "Option -m: " << optionMenueInput << std::endl;

    std::cout << "Run Commands: " << endl;
if( hostIp != "null" &&  hostPort != 0 ){
cout << "HostIP Remote Address: " << hostIp << endl;
cout << "HostPort Remote Address: " << hostPort << endl;
}
if( hostPort != 0 &&  hostIp == "null" ){
cout << "Host @ Assigned Port: " << hostPort << endl;
}
if( optionCores != 0 ){
cout << "CPU Core Assignment: " << optionCores << endl;
}
if( optionMenueInput != "null"){
cout << "Menue Assignment: " << optionMenueInput << endl;
}

//realm_os_user_input(userInput);
librarian_functions( hostIp, hostPort, optionCores, optionMenueInput );
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
 //  cout << "\033[25;1H"; 
/* ="cout << " & CHAR(34) & "Function Begin : "  & B2 & CHAR(34)  & " << endl;" */
//cout << "X                                X       |      " ;
  string userRawInput="";
  cin.clear(); 
  getline(cin, userRawInput);
  validUserInput = userRawInput +"\0";

//cout << "\033[1;1H";
}
































































void realm_sw_divisor_dancer(__int128 singer, __int128 singersDigitSize, primeTileClass PrimeOne )
{

cout << "Singer"<< endl;
//PrimeOne.engageLibrarianDancer(singer);





























































}
























































































































































































































































void realm_sw_variable_primer(__int128 perThreadSlices, bool mrTsaysRead, __int128 singers, __int128 primerBase, __int128 powerOf)
{
string text_function_name="realm_sw_variable_primer"; string text_post = "";
//="text_post = " &CHAR(34)&  " ENTER TEXT HERE "&CHAR(34)&";"&" "&"realm_post_client(text_function_name, text_post );"



string stringBean="", stringBean2="";
__int128 zeroData =0; __int128 totalTiles=0;

__int128 songBuffer = 0; // future use 767676767
__int128 singer =0;
__int128 singersDigitSize=1;
__int128 primeBookIndex = 0; // future use 1000000
__int128 window = 3;
__int128 pDaSize = 7676767676;
// primePillarClass primeOne(window,pDaSize);
__int128 infiniteWalkStart =0;
__int128 previousPrime=3;
__int128 cycle=0;
__int128 feather = 0;
__int128 total = 0;
__int128 totalPrimes=0;
__int128 primeBuild=0;  __int128 primeBuild1=0;
__int128 dance=0;
__int128 intTail=0;
__int128 pDlarge=0;
__int128 totalSkip =0;
__int128 singersDigitFind= singers;
__int128 totalScan=0;
__int128 scanBegin=0;
__int128 scanWalk=0;
__int128 printInt=0;
__int128 lineCountMax=50000;
__int128 lineTotalCount=0;
string beans = "";   string userInput ="";
int removed =0;
bool infinite = true;
byte primeDifference;
string pDlargeString ="";
removed = remove("cobblestones.txt");
removed = remove("primemilestones.txt");
removed = remove("primebook.bin");

primeTileClass PrimeOne(powerOf, perThreadSlices, singers, primerBase);
while(singersDigitFind > 9){
  singersDigitFind = singersDigitFind /10;
  singersDigitSize++;
} 
PrimeOne.carve(singers);







if ( mrTsaysRead == true){
PrimeOne.conductor(  singers,  perThreadSlices,   mrTsaysRead,primerBase);

 // cout << "PrimeBook Load Finished : Press Enter to Continue. " ;

 // cout << "PrimeBook Now Verify : Press Enter to Continue. " ;
//  realm_os_user_input(userInput);
//  PrimeOne.verifyPrimeBook(singers);

 }

if ( mrTsaysRead == false) {  
  //cout << " Mr T Says Start From Beginning" << endl;
PrimeOne.buildPrimeBase(  singers,  perThreadSlices,   mrTsaysRead,primerBase);

//  PrimeOne.verifyPrimeBook(singers);
}




//__int128 totalPrimeNow = PrimeOne.requestTotal();
//__int128 infiniteWalkNow = PrimeOne.requestInfiniteWalk();






  //string128ClassComma PrimeOneTotalString(total);
 //stringBean = PrimeOneTotalString.getString() ;
 //cout << endl << "----------> Dance Primed to : " << stringBean << " Total Primes" << endl<< endl<< endl<< endl;





PrimeOne.conductor(  singers,  perThreadSlices,   mrTsaysRead,primerBase);



















































  //  check system and gpu temp compare and contrast to previous inquiries in array


/*
  if (_kbhit()) {  // Check if a key has been pressed
    char key = _getch(); // Read the pressed key
    std::cout << endl << "Key pressed: " << key << " : ";  // Process the key press

    if (key == 'q'|| key == 'Q'|| key == 'x'|| key == 'X' ) {  // Exit the loop if 'q' is pressed
      break;
    }


    if (key == ' '|| key == '.') {  // Load Menu if ' ' is pressed
      librarian_functions();
      return;
    }

    if (key == 's' || key == 'S') { // Save Array in Memory if 's' is pressed
     ; //  primeOne.arrayToFile(infiniteWalk, pDlarge)
    }
  }



// cout << "CHECK FOR GYROGEARUPDATE APP" << endl;
// cout << "IF GYROGEARUPDATE APP RUNNING COPY ARRAY IN MEMORY TO GYROGEARUPDATE" << endl;
// cout << "CLOSE DELETE GYROGEAR COPY GYROGEARUPDATE TO GYROGEAREXE LOAD AND PASS GYROGEARUPDATE ARRAY TO GYROGEAR" << endl;
// cout << "CLOSE DELETE GYROGEAR UPDATE" << endl;
*/
// } // WHILE INFINITE == TRUE  ===============================================^
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


variable_type_array_bits[vtasc] = sizeof(byte);variable_type_array[vtasc] = "byte";tb1 = variable_type_array[vtasc]  + " Is " + to_string(variable_type_array_bits[vtasc]) + " bit"; realm_post_client(text_function_name, tb1 ); vtasc++;


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


string realm_unique_time_stamp()
{
const auto realm_thread_count = thread::hardware_concurrency();









 // Get the current time point
    auto now = std::chrono::system_clock::now();

    // Extract individual components of time
    auto time = std::chrono::system_clock::to_time_t(now);
    std::tm tm_time = *std::localtime(&time);

    // Format the string as "MODYYRHRMNSEC"
    std::ostringstream formattedTime;
    formattedTime << std::put_time(&tm_time, "%b%d%Y%H%M%S");

 //   std::string result = formattedTime.str();

  //  std::cout << "Formatted Time: " << result << std::endl;




string timeStamp =  formattedTime.str() ;











return timeStamp;






}








































































































































































































































































void realm_conduits()
{
string text_function_name="realm_conduits"; string text_post = "";







text_post = "FUNCTION   realm_conduits   HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}





























































