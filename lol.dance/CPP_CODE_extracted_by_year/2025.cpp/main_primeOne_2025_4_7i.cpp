
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
#include <condition_variable>
#include <Iptypes.h>
#include <Mstcpip.h>
#include <iphlpapi.h>
#pragma comment(lib, "iphlpapi.lib")
#include <atomic>



#include <wbemidl.h>
#include <comdef.h>
#include <tuple>
#pragma comment(lib, "wbemuuid.lib")

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
string globalWolfPackIdString = "";       string globalHostIdString = "";  string globalWolfDenIdString = "";   string globalWolfCPUIdString = "";   
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

bool interrupted = false;
std::mutex mtx;
    const int countdown_seconds = 0;

int globalBuild=2502;
double globalMetalUptime=0;
string globalMetalGUID ="";
string globalMetalIdNum ="";

string globalPrimeClientUserName ="";









































































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







































































































































































void unbroken(string words){
bool unBroken = true;  char choice ; while (unBroken){    cout << "\033[2;1H";   cin.clear(); std::cout << words << "        " <<endl;         std::cin >> choice;         if (choice != 'n' ) {  break;  }  }
}
class PaddingAnalyzer {
public:
    static void analyzePadding(__int128 number) {
        // Determine the number of leading zeros
        int leadingZeros = 0;
        while ((number >> (127 - leadingZeros)) & 1) {
            leadingZeros++;
        }

        // Determine the number of trailing zeros
        int trailingZeros = 0;
        while ((number & (1 << trailingZeros)) == 0) {
            trailingZeros++;
        }

        // Print the results
       cout << "Leading zeros: " << leadingZeros << std::endl;
        cout << "Trailing zeros: " << trailingZeros << std::endl;
    }
};


__int128 stringTo__int128(const std::string& binaryString) {
    __int128 value = 0;
    for (char bit : binaryString) {
        value <<= 1;
        value |= (bit - '0');
    }
    return value;
}


__int128 maingo128(__int128 data) {

    std::string hereForward = "";
    std::string thereBackward = "";
    std::string hereForwardInvert = "";
    std::string thereBackwardInvert = "";
int hereForward0=0; int hereForward1=0; int thereForward0=0; int thereForward1=0;       // Print forward and concatenate strings
int hereForwardInvert0=0; int hereForwardInvert1=0; int thereForwardInvert0=0; int thereForwardInvert1=0;
    std::cout << "16-bit value (forward): ";
    for (int i = 127; i >= 0; i--) {
        if ((data >> i) & 1) {
            hereForward += "1";  hereForward1++;
            hereForwardInvert += "0"; hereForwardInvert0++;
        } else {
            hereForward += "0";  hereForward0++;
            hereForwardInvert += "1";  hereForwardInvert1++;
        }
        if( hereForward1 || hereForwardInvert0 || hereForward0 || hereForwardInvert1 >= 2) {
              cout << "hereForward1 : " << hereForward1 << "hereForwardInvert0 : " <<  hereForwardInvert0
              << "hereForward0 : " <<  hereForward0 << "hereForwardInvert1 : " <<  hereForwardInvert1 << endl;
        }    }
    std::cout << "16-bit value (backward): ";    // Print backward and concatenate strings
    for (int i = 0; i < 128; i++) {
        if ((data >> i) & 1) {
            thereBackward += "1";
            thereBackwardInvert += "0";
        } else {
            thereBackward += "0";
            thereBackwardInvert += "1";
        }
    }

    __int128 hereForward128 = (stringTo__int128(hereForward));                   string128ClassComma hereForward128String(hereForward128);
    __int128 thereBackward128 = (stringTo__int128(thereBackward));               string128ClassComma thereBackward128String(thereBackward128);
    __int128 hereForwardInvert128 = (stringTo__int128(hereForwardInvert));       string128ClassComma hereForwardInvert128String(hereForwardInvert128);
    __int128 thereBackwardInvert128 = (stringTo__int128(thereBackwardInvert));   string128ClassComma thereBackwardInvert128String(thereBackwardInvert128);

    std::cout << std::endl;
    std::cout << "hereForward         : " << hereForward << " : " << hereForward128String.getString() << std::endl;
    std::cout << "thereBackward       : " << thereBackward << " : " << thereBackward128String.getString() << std::endl;
    std::cout << "hereForwardInvert   : " << hereForwardInvert << " : " << hereForwardInvert128String.getString() << std::endl;
    std::cout << "thereBackwardInvert : " << thereBackwardInvert << " : " << thereBackwardInvert128String.getString() << std::endl;

    return 0;
}


uint8_t maingo8(uint8_t data) {

    std::string hereForward = "";
    std::string thereBackward = "";
    std::string hereForwardInvert = "";
    std::string thereBackwardInvert = "";

    // Print forward and concatenate strings

    std::cout << "8-bit value (forward): ";
    for (int i = 7; i >= 0; i--) {
        if ((data >> i) & 1) {
            hereForward += "1";
            hereForwardInvert += "0";
        } else {
            hereForward += "0";
            hereForwardInvert += "1";
        }
    }

    // Print backward and concatenate strings
    std::cout << "8-bit value (backward): ";
    for (int i = 0; i < 8; i++) {
        if ((data >> i) & 1) {
            thereBackward += "1";
            thereBackwardInvert += "0";
        } else {
            thereBackward += "0";
            thereBackwardInvert += "1";
        }
    }

    __int128 hereForward128 = (stringTo__int128(hereForward));                   string128ClassComma hereForward128String(hereForward128);
    __int128 thereBackward128 = (stringTo__int128(thereBackward));               string128ClassComma thereBackward128String(thereBackward128);
    __int128 hereForwardInvert128 = (stringTo__int128(hereForwardInvert));       string128ClassComma hereForwardInvert128String(hereForwardInvert128);
    __int128 thereBackwardInvert128 = (stringTo__int128(thereBackwardInvert));   string128ClassComma thereBackwardInvert128String(thereBackwardInvert128);

    std::cout << std::endl;
    std::cout << "hereForward         : " << hereForward << " : " << hereForward128String.getString() << std::endl;
    std::cout << "thereBackward       : " << thereBackward << " : " << thereBackward128String.getString() << std::endl;
    std::cout << "hereForwardInvert   : " << hereForwardInvert << " : " << hereForwardInvert128String.getString() << std::endl;
    std::cout << "thereBackwardInvert : " << thereBackwardInvert << " : " << thereBackwardInvert128String.getString() << std::endl;

    return 0;
}


uint8_t fileRead8(string fileName){

    std::ifstream file(fileName, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    uint8_t data;
    while (file.read(reinterpret_cast<char*>(&data), sizeof(data))) {

        string128ClassComma dataString(data);
        std::cout << "Read: " << std::hex << "  :  "<< dataString.getString() << std::dec << std::endl;
        maingo8(data);
   //     char choice;
    //    std::cout << "Continue? (y/n): ";
    //    std::cin >> choice;

    //    if (choice != 'y' && choice != 'Y') {
    //        break;
      //  }
    }

    file.close();


}


__int128 fileRead128(string fileName){


    std::ifstream file(fileName, std::ios::binary);

    if (!file.is_open()) {

        std::cerr << "Error opening file.\n";
        return 1;
    }

    __int128 data;
    while (file.read(reinterpret_cast<char*>(&data), sizeof(data))) {
        string128ClassComma dataString(data);
        std::cout << "Read: " << std::hex << "  :  "<< dataString.getString() << std::dec << std::endl;
        maingo128(data);



    }

    file.close();


}


class magicVariable
{
    std::string magicVariableName ="";
    __int128 dataWidthData=0;

private:


public:

void create(std::string magicVariableNewName)
{
    magicVariableName= magicVariableNewName;
    std::cout << "magicVariableName    " << magicVariableName<< std::endl;
}


void dataWidth(__int128 dataWidthData)
{
    string128ClassComma dataWidthDataString(dataWidthData);
    std::cout << "DataWidth   " << dataWidthDataString.getString() <<  std::endl;
    // is the number larger than the biggest __int128
    // how many __int128s are necessary to build this number
    // how many additional __int8s are necessary to finish building this number
    // prepare building growing array to handle the whole of the data


}

void dataIngest(__int128 dataIngestion){


}

__int128 dataProvide128(__int128 dataLocation){

}

uint8_t dataProvide8(__int128 dataLocation){

}



};


void mainTest(){

 uint8_t eightBitValue = 0b10101101;
      // uint8_t eightBitValue = 173;
     // largest __int128 = 340282366920938463463374607431768211455;
   //    7 billion 110100001001110111000011000000000;
   //    7 billion 110100001001110111000011000000000;
 //__int128 onetwentyeightBitValue = 0b10110000111100001001000011110010;
     //__int128 sixteenBitValue = 37106; 144021277451
__int128 onetwentyeightBitValue  = 144021277451;
string testfilename="test.txt";
    __int128 myNumber = 0b0000010100001110100101111111111;
  //  PaddingAnalyzer::analyzePadding(myNumber);
// maingo128(onetwentyeightBitValue);

char choice;
bool unBroken = false;
while (unBroken){
       std::cout << "fileRead8(testfilename)? (y/n): ";
       std::cin >> choice;
       if (choice != 'y' && choice != 'Y') {
           break;
       }
       fileRead8(testfilename);
}

unBroken = false;
while (unBroken){
       std::cout << "fileRead128(testfilename)? (y/n): ";
       std::cin >> choice;
       if (choice != 'y' && choice != 'Y') {
           break;
        }
       fileRead128(testfilename);
}

// repeated cell 241
std::string name ="IAMMAGIC";
__int128 width = 777 ;
magicVariable iAmMagic;
unBroken = false;
while (unBroken){

        iAmMagic.create(name);
        iAmMagic.dataWidth(width);

       std::cout << "magicVariable? (y/n): ";
       std::cin >> choice;

       if (choice != 'y' && choice != 'Y') {
           break;
        }

}

}























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













//       =conduitClass!A1

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








































































































class primeTileClass
{
private:  // **************** PRIVATE *******************

string ptv_win_archive()
{
string text_function_name="ptv_win_archive"; string text_post = "";

system("del PrimeOneUpdate\\*.* /Q");


RandomSeedProvider seedProvider;
StringGenerator stringGenerator(seedProvider);
string randomString1 = stringGenerator.generateRandomString(5);

cout << "Win archive running"<< endl;
string uniqueFileName =  "updater_"+ ptv_uniqueId(randomString1) + ".zip";
string command1 = "tar -a -cf PrimeOneUpdate\\" + uniqueFileName + " *.dll *.exe *.bat";
system(command1.c_str());






// system("del PrimeOneUpdate\\PrimeOneUpdate.zip /q");


//system("copy PrimeOneUpdate\\PrimeOneUpdater.zip PrimeOneUpdate\\PrimeOneUpdate.zip");

return uniqueFileName;
}































































































































































































































































































void ptv_win_updater( bool isHost, string guestName, string guestIP, string guestPort, string hostIP, string hostPort, string uniqueFileName)
{
string text_function_name="realm_win_guest"; string text_post = "";
int PORT = 54000 ; bool yesContinue=true; bool socketSearch=true; int PORTgrow = PORT; bool sendForever=true;
int ARRAY_SIZE = 999999999;  // cout << " ARRAY_SIZE " <<  ARRAY_SIZE << endl;
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
std::ofstream copy("PrimeOneUpdate\PrimeOneUpdate.zip", std::ios::binary);

while(printForever==true){
int* received_array = new int[ARRAY_SIZE];
// int received_array[ARRAY_SIZE];
int bytes_received = recv(sock, reinterpret_cast<char*>(received_array), ARRAY_SIZE * sizeof(int), 0);



copy.write(reinterpret_cast<const char*>(received_array), bytes_received);
copy.close();
   closesocket(sock);    WSACleanup();   return;

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


   closesocket(sock);    WSACleanup();   return;
}

// cout << "Waiting for a connection " << endl; // Accept a client socket
sockaddr_in client{};
int clientSize = sizeof(client);

SOCKET clientSocket = accept(sock, reinterpret_cast<sockaddr*>(&client), &clientSize);
if (clientSocket == INVALID_SOCKET){
   cerr << "Can't accept client Invalid Socket! Quitting" << endl;


   closesocket(sock);    WSACleanup();   return;
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

std::vector<char> data;
std::ifstream original("PrimeOneUpdate\PrimeOneUpdater.zip", std::ios::binary);

if (original) {
    // Read the contents of the file into the vector variable
    std::istreambuf_iterator<char> start(original), end;
    data.assign(start, end);
    original.close();
} else {
    std::cerr << "Failed to open 'original.zip' file" << std::endl;
   closesocket(sock);    WSACleanup();   return;
}




while (sendForever) {
    int remainingData = data.size() - dataSend;
    int bytesToSend = std::min(remainingData, static_cast<int>(ARRAY_SIZE * sizeof(char)));
    int bytes_sent = send(clientSocket, reinterpret_cast<char*>(data.data()) + dataSend, bytesToSend, 0);
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

        dataSend += bytes_sent;
    }

    if (dataSend >= data.size()) {
   closesocket(sock);    WSACleanup();   return;



       // break;  // Break out of the loop when all data has been sent
    }
}



cout << "SOCKET FOREVER ==TRUE"<< endl;
}
}



}


























































































































string ptv_unique_time_stamp()
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











































































































































































































































































// PRIVATE VARIABLES       

string targetTileName = "";
string arrayNamePrefix = "Tile";
string stringBean4 = "";
string stringBean = "";
string stringBean2 = "";
string stringBean3 = "";
 
string gridString ="";
string primeBookName = "PrimeBookOne.zip"; 
string primeBookNameImport = "PrimeBookOne.tar";
string userInput;

int memError = 0 ;
int memErrorCount =1;

__int128 tileCount = 0;
__int128 powerOf = 0 ;
__int128 grid = 0 ;
__int128 singers =0;
__int128 total = 1;
__int128 etchWalk =0;
__int128 etchWalkArray =0;
__int128 etchWalkSum =0;
__int128 etchWalkPrint =0; 
__int128 breezeWalk =0;
__int128 tileWalk =0;
__int128 readTileCount=0;
__int128 previousPrimeRatio = 0 ; 
__int128 gearCreatedTiles =0;
__int128 perThreadSlices =0;
__int128 primeBasePrimer =0;
__int128 slatePrimeRatio =0; // remove slate
__int128 slateRoughCut =0 ;// remove slate
__int128 minimumPrimeBookNeeded = 0;
__int128 indexTiles=0;
__int128 primeIndexRoof=0;

std::unordered_map<std::string, byte*> tiles;
std::unordered_map<std::string, byte*> slate ;

bool etchStatus = 0;
bool printBookIndex = false;
bool* tileLoaded;
bool mrTsaysRead = false ;

__int128* processData;
__int128* threadTotal;
__int128* threadSlateWalk ;
__int128* threadBreezeWalk ;
__int128* threadTileWalk ;
__int128* myTileCount ;
__int128* myEtchWalk ;
__int128 singerFinished=0;
__int128* findsArray ;
__int128* indexArray;
__int128* liveIndex;
__int128* primeIndex;
__int128* tileTotalsArray;

byte* etchTileArray;

__int128 guiGrid128[3][31];
string guiGrid[3][31][3];
bool guiUpdate[31];

int guiGridWidth = 96;
int guiGridHeight = 31;

__int128 previousEtchWalkSum =0;
__int128 infiniteCycleStarts =0; 
__int128 infiniteCycleFinishes =0;

byte* etchCacheArray;

__int128* bookIndex ;
__int128* bookIndexTotals;
__int128* bookIndexTotalsDif ;
__int128 indexFileTileCount= 0;

byte** myTiles ;

string* hostGuestListArray00;
string* guestCheck;

int* hostGuestListArrayFreshness00;
int maxHostConduits = 9999;
int maxGuestConduits = 9999;
int dataPort =4321;
int* hostGuestListArrayFreshnessCurrent00;
int totalGuests=0;

__int128 weaverData00;
__int128 globalMyMiles=0;

string* hostGuestPortListArray00;
string* hostGuestIpListArray00;
string* guestPortListArray00;
string globalNewHostIp ="";
string globalNewHostName = "";
string* guestReturnArray;
string* guestReturnIpArray;
string* guestReturnGearArray;

bool globalBecomeHost = false;
bool globalNewHost = false;
bool globalAllTorchesPassed = false;

int hostCount;
int claimedPort00 = globalNewHostPort;
int guestClaimedPort00 = globalNewHostPort;
int myMiles;
int myGuestMiles;
int myHostMiles;
int myGuestTotalMiles;
int myHostTotalMiles;
int maxMiles;
int remainingGuests;
int* guestReturnPortArray;

// conductor private variables

__int128 infiniteWalk = 0;
__int128 previousPrime = 0;
__int128 totalTiles = 0; 
__int128 totalPrimes = 0; 
__int128 primeRatio =0;
__int128 singer =0;
__int128 pDlarge = 0;
__int128 tileLay=0; 
__int128 tileWalkData=0;
__int128 thirdTileCount =0;
__int128 conductorCount =0;
 __int128 printWalk=0;
__int128 sliceWalk=0;
 __int128 conductorEtchWalkPrint=0;
__int128 data =0;
__int128 primeDifference =0;



int conductorClockIns =0;
int conductorClockIn =0;
int conductorCheckClock =0;
int conductorLastGitUpdate = 0;
int createTileRequest = 0;
int conductorUpdateInterval=0;
int statusUpdates=0;
int primerBenchTime =0;


bool iUpdate ;
bool infinite;
bool unBroken ;

char choice ;

byte* targetArray ;
byte* dancerPrimeFinds ;

string uniqueId = "";
string gitData="";


__int128 privateLeapsLap;
__int128 privateLeapsLapDouble;
__int128* privateWolfLeap;

vector<byte>* privateWolfFeast;

string* privateWolfLeapAssingment;

int* privateWolfPrimeQueAssingment;

int privatePrimeQue;
int privateQueCount;

int collectionPlateFirst;  int collectionPlateSecond;

vector<byte> privateGuestWork;

byte* privatePrimeNetCatch;




































































































































__int128 listBookZip(){ 
string userInput;   

// cout << " Begin listBookZip " << endl;   realm_os_user_input(userInput);
 //  realm_os_user_input(userInput);

 string listBookZipString = "echo off & cd PrimeBookOne & tar -tf " + primeBookNameImport +" > bookZipList.txt";
     cout << "\033[2;1H";
 system( listBookZipString.c_str() ); 
 //cout << listBookZipString << endl;
 // count lines of file cout

 ifstream file("PrimeBookOne\\bookZipList.txt");

 if (!file) { cerr << "Error opening file: bookZipList.txt" << endl;  cout << "Error Reading ZipList File" << endl; }

 __int128 lineCount = 0;
 string line;
__int128 tileWalk = 1;
 while (getline(file, line)) {lineCount++;}   lineCount--;

 string128Class lineCountString( lineCount );
 string stringLineCount = lineCountString.getString();
 //  cout << "Number of Tiles in bookZipList.txt : " <<stringLineCount << endl;
file.close();  //  readTileCount=lineCount; 
// cout << " Finish listBookZip " << endl;   realm_os_user_input(userInput);
return lineCount;
}





















































































































__int128* readBookIndex( __int128 readTileCount,  const int MAX_LINES){  
//system("cls"); 
string userInput="";
// cout << "Begin Book Read of Index *1111111111111111111111111111111111111111111111111111111111111111111111111 " << endl;
 // const int MAX_LINES = 500000;
     __int128*   redBookIndex  = new __int128[MAX_LINES];
 //cout << "22222222222222222222222222" << endl;
   ifstream file("PrimeBookOne\\PrimeBookIndex.txt");
//cout << "33333333333333333333333333" << endl;
    if (!file) {  std::cerr << "Error opening file: file.txt" << std::endl;}
// cout << "4444444444444444444444444" << endl;
   // __int128 tileStart[MAX_LINES];
 //   __int128 tileFinish[MAX_LINES];
   // __int128 tileTotals[MAX_LINES];
    __int128 value1;       //, value2, value3;
 //   __int128  readTileCount = 28;
    string value1S;//, value2S, value3S;

    __int128 lineCount = 0;

// cout << "55555555555555555555555555555" << endl;

    string stringBean1=""; //, stringBean2="", stringBean3="";

    while (lineCount< readTileCount) {
       file >> value1S;
//cout << "Linecount: " << int(lineCount)<< value1S << endl;
        if (lineCount >= MAX_LINES) { std::cerr << "Exceeded the maximum number of lines allowed (" << MAX_LINES << ")" << std::endl;}
        value1 = StringTo128Class::stringToInt128(value1S);
   //     value2 = StringTo128Class::stringToInt128(value2S);
     //   value3 = StringTo128Class::stringToInt128(value3S);
        redBookIndex[lineCount] = value1;
// cout << "666666666666666666666" << endl;

        lineCount++;


       }

 //cout << "7777777777777777777777777" << endl;
     //  cout << " print PrimeBookOne Index"<< endl;

 //   for (__int128 i = 0; i <  readTileCount; i++) {      // Print the read data
   //   string128Class tileStartString(tileStart[i]);
   //   string128Class tileFinishString(tileFinish[i]);
   //   string128Class tileTotalsString(tileTotals[i]);
   //   cout << tileStartString.getString() << " R1 ";
   //   cout << tileFinishString.getString() << " R2 ";
  //    cout << tileTotalsString.getString()  << " R3 ";
  //    cout << endl;
// cout << "88888888888888888888888888     Finish Book Index" << endl;
return redBookIndex;




}  // finish read bookIndex
























































































__int128 countTextLines(string fileName){ 


// cout << " Begin listIndexElements " << endl;   realm_os_user_input(userInput);



 // count lines of file cout
string primeBookOneDirectory= "PrimeBookOne\\";
string fileAndDirectory= primeBookOneDirectory + fileName;    // ifstream file("PrimeBookOne\\bookZipList.txt");
 string line;
 __int128 lineCount = 0;
 ifstream file(fileAndDirectory);

 if (!file) { cerr << "Error opening file: "<< fileName << endl;   }
else {

 while (getline(file, line)) {
     lineCount++;
}
 lineCount--;
// string128Class lineCountString( lineCount );  string stringLineCount = lineCountString.getString();      cout << "Number of lines in : " << fileName << " : " <<stringLineCount << endl;
}

file.close();
// cout << " Finish count text file lines " << endl;   realm_os_user_input(userInput);
return lineCount;







}














































































































void extractTile(__int128 tileNumber){      // cout << "Extract Tile " << endl; 
// string userInput="";  
  string128Class tileNumberString(tileNumber);
  string tileString = tileNumberString.getString();
cout << "\033[2;1H";
// cout << " 101010 " << endl;      realm_os_user_input(userInput);




  string extractTile = "echo off & cd PrimeBookOne & tar -xvf "  +  primeBookNameImport + " PrimeBookOne/Tile0" + tileString +".zip";
//  cout  <<extractTile << endl;
  system( extractTile.c_str());
cout << "\033[2;1H";






  string unzipTile = "echo off & cd PrimeBookOne & cd PrimeBookOne & tar -xvf Tile0" + tileString +".zip";
//   cout << "unzipTile: "<< unzipTile << endl;
  system( unzipTile.c_str());
cout << "\033[2;1H";


}






















































































































void fileIndex(__int128 data){
if (data == 0){
  string delIndexTXT = "echo off & del primebookone\\primebookindex.txt"; // DELETE OLD PRIMBOOKINDEX.TXT
  system( delIndexTXT.c_str() );  //  cout << " rebuild PrimeBook Index " << endl;
  fstream createPrimeIndexTXT;   // CREATE NEW PRIMEBOOK INDEX FILE
  createPrimeIndexTXT.open("primebookindex.txt", fstream::in | fstream::out | fstream::app);
  createPrimeIndexTXT.close();

}

else {

  fstream PrimeOneIndex ;  // OPEN INDEX
  PrimeOneIndex.open("PrimeBookOne\\primebookindex.txt", fstream::out  );

    string128Class numObj1(data);   //std::cout << "Number 1: " << numObj1.getString() << std::endl;  //cout << "   infinitePrimeTileWalk = " <<

    PrimeOneIndex  <<  numObj1.getString()  << endl;
  PrimeOneIndex.close();


}

} //Finish FileIndex

































































































































































































































































































__int128 threadRetrieveTile(__int128 singer, __int128 tileNumber, string uniqueId, byte* workingArray) {

__int128 threadRetrieveTileWalk = 0;
__int128 data =0;  
__int128 dataTotal =0;

string delPrimeFile = "";
string delZipFile = "";
string targetTileName = "";
string targetTileNamePath="";

string128Class tileNumberString ( tileNumber );

targetTileName = "Tile0" + tileNumberString.getString() ;

byte* targetRetrieveTile = new byte[grid];

//cout << "  continue    extractTILE? Singer : " << int(singer) <<  endl; realm_os_user_input(userInput);  

extractTile(tileNumber);

targetTileNamePath += "PrimeBookOne/PrimeBookOne/PrimeBookOne/";
targetTileNamePath +=  targetTileName;
targetTileNamePath += ".prime";

 //    cout << "  continue    readTILE? Singer : " << int(singer) << "  Path : " << targetTileNamePath << "    " <<endl; realm_os_user_input(userInput);  
cout << "\033[1;1H";
ifstream input(targetTileNamePath, std::ios::binary);
   if (!input) { std::cerr << "Error opening file: " << targetTileNamePath << std::endl; }

input.read(reinterpret_cast<char*>(workingArray), grid );
// tiles[targetTileName]= targetRetrieveTile;  //*workingArray = targetRetrieveTile;        
//delPrimeFile = "del PrimeBookOne/PrimeBookOne/" +  targetTileName + ".zip";
//delZipFile = "del PrimeBookOne/PrimeBookOne/PrimeBookOne/" +  targetTileName + ".prime";

input.close();

//system(delPrimeFile.c_str());
//system(delZipFile.c_str());

//cout << "  tileTotals start    retrieveTile singer : "<< int(singer)<< endl;

__int128 threadData;
threadRetrieveTileWalk =0;
dataTotal = 0 ;
__int128 threadGridWalk=0;
while(threadGridWalk < grid){

   dataTotal+=workingArray[threadGridWalk];
   threadGridWalk++;
//cout << "singer " <<int(singer) << " tile# " << int(tileNumber) << int(dataTotal) << endl;
}

//cout << "singer " <<int(singer) << " tile# " << int(tileNumber) << int(dataTotal) << endl;
bookIndexTotals[tileNumber]= dataTotal;

//cout << " FINISHED read tile data = " <<targetTileNamePath  << endl <<"  totaltiles=" << int(tileWalk) << endl;
//cout << "  preFinish    retrieveTile singer : "<< int(singer)<< endl;
//workingArray = targetTile;
//cout << "  Finish    retrieveTile singer : "<< int(singer)<< endl;
//delete targetRetrieveTile;
//return workingArray;

}





























































































































































































































































void markIndex(__int128 data){



  fstream PrimeOneIndex ;
  PrimeOneIndex.open("PrimeBookOne\\primebookindex.txt",
  fstream::in | fstream::out | fstream::app);

  string128Class indexDataString(data);
  string stringBean2= indexDataString.getString();

  PrimeOneIndex  << stringBean2 <<endl;
  PrimeOneIndex.close();


} // finish MarkIndex



void markIndexTotals(__int128 data){



  fstream PrimeOneIndex ;
  PrimeOneIndex.open("PrimeBookOne\\primebookindextotals.txt",
  fstream::in | fstream::out | fstream::app);

  string128Class indexDataString(data);
  string stringBean2= indexDataString.getString();

  PrimeOneIndex  << stringBean2 <<endl;
  PrimeOneIndex.close();


} // finish MarkIndex



void markIndexTotalsDif(__int128 data){



  fstream PrimeOneIndex ;
  PrimeOneIndex.open("PrimeBookOne\\primebookindextotalsdif.txt",
  fstream::in | fstream::out | fstream::app);

  string128Class indexDataString(data);
  string stringBean2= indexDataString.getString();

  PrimeOneIndex  << stringBean2 <<endl;
  PrimeOneIndex.close();


} // finish MarkIndex



























































































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






























































































































__int128 epochMicroSeconds(){

// Return Microseconds Since Epoch
    auto currentTime = std::chrono::system_clock::now();
    auto microSecondsSinceEpoch = std::chrono::duration_cast<std::chrono::microseconds>(currentTime.time_since_epoch());
__int128 timeInMicroSeconds =  static_cast<__int128>(microSecondsSinceEpoch.count());

return timeInMicroSeconds;

}














void archivePrimeBook(__int128 readTileCount, string uniqueId){
string userInput;   

string newPrimeBookName ="";  string newPrimeIndexTotalsName="";
string copyBookString="";  string copyIndexTotalsString ="";
string newPrimeIndexName ="";  string newPrimeIndexTotalsDifName="";
string copyIndexString ="";  string copyIndexTotalsDifString ="";

 string128Class readTileCountString( readTileCount );
// cout << " Begin ArchivePrimeBook " << endl;   realm_os_user_input(userInput); //  realm_os_user_input(userInput);

newPrimeBookName += "primebookone";
newPrimeBookName += readTileCountString.getString();
newPrimeBookName += "_" + uniqueId + ".tar";

copyBookString += "echo off & cd PrimeBookOne & ";
copyBookString += "copy primebookone.tar ";
copyBookString += "archive\\" +uniqueId+"\\";
copyBookString += newPrimeBookName;

newPrimeIndexName += "primebookindex";
newPrimeIndexName += readTileCountString.getString();
newPrimeIndexName += "_" + uniqueId + ".txt";

copyIndexString += "echo off & cd PrimeBookOne & ";
copyIndexString += "copy primebookindex.txt ";
copyIndexString += "archive\\" +uniqueId+"\\";
copyIndexString += newPrimeIndexName;

newPrimeIndexTotalsName += "primebookindextotals";
newPrimeIndexTotalsName += readTileCountString.getString();
newPrimeIndexTotalsName += "_" + uniqueId + ".txt";

copyIndexTotalsString += "echo off & cd PrimeBookOne & ";
copyIndexTotalsString += "copy primebookindextotals.txt ";
copyIndexTotalsString += "archive\\" +uniqueId+"\\";
copyIndexTotalsString += newPrimeIndexTotalsName;

newPrimeIndexTotalsDifName += "primebookindextotalsdif";
newPrimeIndexTotalsDifName += readTileCountString.getString();
newPrimeIndexTotalsDifName += "_" + uniqueId + ".txt";

copyIndexTotalsDifString += "echo off & cd PrimeBookOne & ";
copyIndexTotalsDifString += "copy primebookindextotalsdif.txt ";
copyIndexTotalsDifString += "archive\\" +uniqueId+"\\";
copyIndexTotalsDifString += newPrimeIndexTotalsDifName;

 system( copyBookString.c_str() ); 
 system( copyIndexString.c_str() ); 
 system( copyIndexTotalsString.c_str() ); 
 system( copyIndexTotalsDifString.c_str() ); 

// cout << " FINISH ArchivePrimeBook and Index " << endl;   realm_os_user_input(userInput);






}


































string ptv_uniqueId(string randomString3)
{
const auto realm_thread_count = thread::hardware_concurrency();


    string128Class numObj1( realm_thread_count );

//cout << "Unique Id for Instance of PrimeBookOne Gear# " << uniqueId << endl;
//string userInput;
//realm_os_user_input(userInput);


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




string uniqueId = "pb1_"+ numObj1.getString() + "_" + randomString3+"_" + formattedTime.str() ;










uniqueIdGlobal = uniqueId;
return uniqueId;






}









































































































































































































































































void ptv_COMMANDER(){

  vector<byte*> dancerPrimeFindsArray (  perThreadSlices );  
  vector<byte*> threadWorkingArray (  grid );  
  vector<byte*> conductorPrimeFindsArray (  perThreadSlices );  
  conductorPrimeFindsArray[singer] = new byte[ perThreadSlices ];
string uniqueId = uniqueIdGlobal;
//mrTsaysRead = mrTsaysReadLibrarian;
guiDefaultsSet();
   guiGrid128[0][16] = primeRatio;     guiGrid128[0][16] = primeRatio;   guiGrid[2][8][1] = totalTiles;  guiGrid128[0][19] = pDlarge;    guiGrid128[0][20] = infiniteWalk;   guiGrid128[0][21] =total; guiGrid128[2][18] = singers;
 gui128String(); guiPrime();  system("cls"); gui(); 
   __int128 readTileCount = listBookZip() +1;
  guiGrid128[2][8] = readTileCount;
bool verifyTiles=false;
   bool rebuildIndex = false;
   bool reCreateIndex = false;
//   __int128 indexFileTileCount = countTextLines("primebookindex.txt") + 1;
   __int128* fileBookIndex = new __int128[500000];
string createTileName="";
  //  archivePrimeBook(readTileCount,uniqueId);  
__int128 etchRunner=0;

    string128Class totalString(total); 
//  tileCount = readTileCount;
__int128 createTiles=0;








//tileLay=1;

//        minimumPrimeBookNeeded = findMinimumPrimeBook(readTileCount,bookIndex);
__int128 walkInfiniteTile =0;

     minimumPrimeBookNeeded = readTileCount;

        //     infiniteWalk=bookIndex[readTileCount-1]; // read the largest known prime 
        //   etchIndexInfiniteWalkSum=infiniteWalk;       infiniteWalk+=2;      // Walk 2 into the unknown

         //string128Class infiniteWalkString(infiniteWalk);  string128Class tileCountString(tileCount);

         //string128Class highestPrimeM1(  bookIndex[readTileCount-1]  );











bool verifiedPrimeBook=false;
bool readLastBatch = false;

__int128 assignedBook=0;
__int128 totalCores = singers;
__int128 availableCores = totalCores ; //. totalCores-1



__int128 batchCount =0;
__int128 createTileReadThread =0;


  vector < thread > bookClub;
__int128 threadReadTotal=0;











// ****** BEGIN BATCH READ LOOP *********
__int128 rejoinThreadWalk=0;


  __int128 gridWalk=0;


__int128 batchWalk = 0;
__int128 theBatchWalk = minimumPrimeBookNeeded;
__int128 partialBatchTotal =0;
      byte* threadTile = new byte[ grid ];







while ( readLastBatch == false){

   if (theBatchWalk > availableCores){
      batchWalk = availableCores;

   } else {
     batchWalk = theBatchWalk;
     readLastBatch=true;

   }





    bookClub.clear();
   for (__int128 batchWalker = 0; batchWalker < batchWalk; batchWalker++) {      //   cout << "create singer "<<int(singer)<< endl;




      threadWorkingArray[batchWalker] = new byte[ grid ];




      bookClub.push_back(thread([this,
                            batchWalker,
                              assignedBook,
                                uniqueId,

                                    &workingArray  = threadWorkingArray[batchWalker]
                                      ]() {
                            this->threadRetrieveTile(batchWalker,
                              assignedBook,
                                uniqueId,

                                   workingArray
                                      );}));







     theBatchWalk--; 
      assignedBook++;


   }           // FINISH CREATE ALL THREADS
   






   for (auto& readTileReadThread : bookClub) {



         readTileReadThread.join(); 
   }                                  // Finish Join All Threads

   bookClub.front();

for (__int128 batchWalkerReader = 0; batchWalkerReader < batchWalk; batchWalkerReader++) {

     byte* targetTile;

//      targetTile = threadWorkingArray[batchWalkerReader];

      string128Class tileNumberString ( tileLay );
      string targetTileName = "Tile0" + tileNumberString.getString();
   //  cout << "Begin read batchWalker tile : " << int(batchWalkerReader) << " targetTileName = " << targetTileName << endl;
targetTile=  threadWorkingArray[batchWalkerReader]; //  tiles[targetTileName] = new byte[grid];
//cout << "             create tile " << targetTileName << "   "  << endl;

// tiles[targetTileName] = targetTile;       tileLay++;
etchRunner=0;
while (etchRunner < grid){ data = targetTile[etchRunner++];

// ptv_etchTileARM data => in    


//if(etchWalk%10000==0){
//cout << "EtchTile : " << int(data) << "  EtchWalk : " << int(etchWalk)<< endl;}
//cin >> userInput;

 byte* targetTile;


  string128Class tileCountString ( tileCount );    
  targetTileName = "Tile0" + tileCountString.getString();
     targetTile = tiles[ targetTileName ];
     targetTile[etchWalk] = data;
     etchWalkSum+=data;  // ADD ONTO TILE SUM
  etchWalk++;
  if (etchWalk == grid) {
guiGrid128[2][11] = etchWalkSum;
previousEtchWalkSum =  previousEtchWalkSum;   // PREVIOUS TILESUM
gearCreatedTiles++;  guiGrid128[2][9]=gearCreatedTiles; // primebooksCreated talley

guiGrid128[2][12] = previousEtchWalkSum; // cout << "previousEtchWalkSum : 
bookIndexTotals[tileCount]= etchWalkSum;        
  primeRatio =infiniteWalk/total;
// exportTile( targetTileName );// cout << "export Tile" << endl;

  etchWalkSum=0; // BEGIN NEW TILE SUM
     tileCount++;    
etchWalk = 0;

    string128Class tileCountString ( tileCount );
    targetTileName = "Tile0" + tileCountString.getString() ;
    byte* newTile = new byte[grid]();
    tiles[targetTileName] = newTile;

    targetTile = tiles[ targetTileName ];


    targetTile[0] = 0;
  }








































































































}

   }           // FINISH READ ALL THREADS 

} // WHILE readLastBatch != True    //*******************FINISH  BATCH READ LOOP ********* *********************

        total = (grid*(readTileCount)); 




// ptv_walkIndexARM       

__int128 indexWalk =0;
__int128 previousBookIndex =3; 
while (indexWalk < readTileCount){

bookIndex[indexWalk]= (bookIndexTotals[indexWalk]*2) + previousBookIndex;
   previousBookIndex = bookIndex[indexWalk];
   bookIndexTotalsDif[indexWalk] = (bookIndexTotals[indexWalk]*2) - (bookIndexTotals[indexWalk+1]*2);
      string128Class bookIndexString(bookIndex[indexWalk]);
      string128Class bookIndexTotalsString(bookIndexTotals[indexWalk]*2);
      string128Class bookIndexTotalsDifString(bookIndexTotalsDif[indexWalk]);
      string128Class indexWalkString(indexWalk);
cout << "BookWalk : "<< indexWalkString.getString();
cout << " Index : " << bookIndexString.getString();
cout << " Totals : " << bookIndexTotalsString.getString();
cout << " TotalsDif : " << bookIndexTotalsDifString.getString()<< "        "<<endl;
   indexWalk++;
}
cout <<  int(bookIndex[readTileCount-2] ) << "   " <<   int(bookIndex[readTileCount-1] ) << "   " <<   int(bookIndex[readTileCount] ) << "   " << endl;


















































































cout <<  int(bookIndex[readTileCount-2] ) << "   " <<   int(bookIndex[readTileCount-1] ) << "   " <<   int(bookIndex[readTileCount] ) << "   " << endl;
previousPrime = bookIndex[readTileCount-1];

infiniteWalk = previousPrime+2;  string128Class infiniteWalkString(infiniteWalk);
cout << endl<< "           InfiniteWalk = "<<  infiniteWalkString.getString() << "   TileCount : "<< int(tileCount) << endl;
for (int i = countdown_seconds; i >= 1; --i) {cout << i << " "; this_thread::sleep_for(std::chrono::seconds(1));}



// COMMANDER verifyTile Arm
//gui();
// =ptv_walkTileArm!A1

int gWalk =0;
int moonWalk =1;
int center = 10;
int depth  = 8;


string guiGridString ="";
string title = "";
string indexString="";


__int128 loadedTileDif=0; 
__int128 tileSetup = 0;
__int128 previousPrimeWalk = 0;
__int128  nextPrime =0;
__int128 nextPrimeWalk=0;
__int128 targetTileDif =0;
__int128 previousTile = totalTiles--;
__int128 expectedTileDif =0;
__int128 primeMoonWalk = bookIndex[tileSetup];
__int128 walkTheMoon=0;
__int128 previousPrimeMoonWalk = bookIndex[tileSetup];
__int128 primeGridWalk = 3;
__int128 primetileSetupBase=3;
__int128 primetileSetupBaseNext=3;
__int128 previousPrimeGridWalk = 0;
__int128 expectedPrimetileSetup=0;
__int128 primetileSetup = primetileSetupBase;
__int128 primeMoonWalkNext =0;

byte* targetTile = new byte[grid];
//cout << endl<< "                              Begin VERIFY TILE?"; realm_os_user_input( userInput); 

while(tileSetup<readTileCount){

   string128Class infinitePrimeIndexString(bookIndex[tileSetup-1] );
   string128Class infinitePrimeIndexTotalString(  bookIndexTotals[tileSetup] );

   indexString = "";

   primetileSetupBaseNext =(primetileSetupBase)+ ( bookIndexTotals[tileSetup])*2 ;

   string128Class primetileSetupBaseNextString(primetileSetupBaseNext);

   string128Class tileNumberString ( tileSetup );
   targetTileName = "Tile0" + tileNumberString.getString();
   
   targetTile = tiles[targetTileName] ;


   // NAME TITLE
   string128Class primetileSetupBaseString ( primetileSetupBase );
   title  = "";
   title += "Grid Tile0";
   title += tileNumberString.getString();
   title += " infinitePrimeWalk ' Verify";
   
   guiGrid[1][center][1] = title;

   // INDEX TITLE
   indexString  = "";
   indexString += primetileSetupBaseString.getString(); 
   indexString += "  ";
   indexString += infinitePrimeIndexTotalString.getString();
   indexString += "  ";
   indexString += primetileSetupBaseNextString.getString();

   if(verifyPrime(primetileSetupBaseNext)==true){ indexString += " P "; } else {indexString += " X ";}
   
   guiGrid[1][center+1][1] = indexString;

   walkTheMoon= primetileSetupBaseNext;
   primeMoonWalk= primetileSetupBaseNext;
   moonWalk=1;

   while (moonWalk < (depth+1)){
      targetTileDif = targetTile[grid -moonWalk];

      primeMoonWalkNext = moonWalkPrime(primeMoonWalk);
      expectedTileDif =  (primeMoonWalk -primeMoonWalkNext )/2;

      string128Class targetTileDifString(targetTileDif);
      string128Class expectedTileDifString(expectedTileDif);
      string128Class walkTheMoonString(walkTheMoon);
      string128Class moonWalkString(moonWalk);
      string128Class primeMoonWalkString(primeMoonWalk);

      guiGridString += "-";
      guiGridString += moonWalkString.getString();
      guiGridString += " "  ;
      guiGridString += targetTileDifString.getString();
      guiGridString += " "  ;
      guiGridString += walkTheMoonString.getString();

     if(verifyPrime(walkTheMoon)==true){ guiGridString += " P "  ;} else { guiGridString += " X "  ; } 

      guiGridString += " ' "  ;
      guiGridString += expectedTileDifString.getString();
      
      guiGridString += " "  ;
      guiGridString += primeMoonWalkString.getString();
 
     if(verifyPrime(primeMoonWalk)==true){ guiGridString += " P "  ; } else { guiGridString += " X "  ; }
     
     if (walkTheMoon != primeMoonWalk){  
     // system("cls");
     cout << "     !!!! Prime Math not Matching  ";
     cout << "     !!!!  " << int(walkTheMoon) << " != Not Equal != " << int(primeMoonWalk) << "  !!!!  " ;
cin >> userInput;
       for (int i = countdown_seconds; i >= 1; --i) {cout << i << " ";this_thread::sleep_for(chrono::seconds(1)); }
    
       __int128 mathDifference = walkTheMoon - primeMoonWalk;
       string128Class mathDifferenceString(mathDifference); 
       string mathError = "Prime Math Error Difference of : " + mathDifferenceString.getString();
       // logExit(mathError);    system("start /b PrimeOneReboot.bat");    exit(0);
     }
     
      guiGrid[1][center-moonWalk][1] = guiGridString;
      guiGridString="";
      primeMoonWalk = primeMoonWalkNext;
      walkTheMoon= walkTheMoon-(targetTileDif*2);
      moonWalk++;
   }  // FINISH moonWALK
   gWalk=0;
   while (gWalk < (depth+1)){
      targetTileDif = targetTile[gWalk];
      primetileSetup += targetTileDif*2;
      previousPrimeGridWalk = primeGridWalk;
      primeGridWalk = nextWalkPrime(previousPrimeGridWalk);
      expectedTileDif = (primeGridWalk -previousPrimeGridWalk)/2 ;
   string128Class expectedTileDifString(expectedTileDif);
   string128Class targetTileDifString(targetTileDif);
   string128Class primetileSetupString(primetileSetup);
   string128Class expectedPrimetileSetupString(primeGridWalk);
   string128Class gWalkString(gWalk);

   
      guiGridString += "+";
      guiGridString += gWalkString.getString();

      guiGridString += " "  ;
      guiGridString += targetTileDifString.getString();
      guiGridString += " "  ;
      guiGridString += primetileSetupString.getString();

    if(verifyPrime(primetileSetup)==true){ guiGridString += " P "  ;  } else { guiGridString += " X "  ;}

      guiGridString += " ' "  ;
      guiGridString += expectedTileDifString.getString();
      guiGridString += " "  ;
      guiGridString += expectedPrimetileSetupString.getString();

    if(verifyPrime(expectedPrimetileSetup)==false){ guiGridString += " P "  ; } else { guiGridString += " X "  ; }
    
      guiGrid[1][center+gWalk+2][1] = guiGridString;

      guiGridString="";
      
      gWalk++;
      
      
}  // FINISH gWALK

   primetileSetupBase = bookIndex[tileSetup];
   primeGridWalk = bookIndex[tileSetup];

   primetileSetup = bookIndex[tileSetup];

   primeMoonWalk = bookIndex[tileSetup];

   tileSetup++;
   gui();
  //  for (int i = countdown_seconds; i >= 1; --i) {
  //      std::cout << i << " ";
  //      std::this_thread::sleep_for(std::chrono::seconds(1));

  //  }



} // finish tileSetup

// not a function but a commander insert} // FINISH VERIFY TILE
































































































































archivePrimeBook(readTileCount,uniqueId);


   guiGrid128[2][16] = perThreadSlices;



 //***FINISH  ptv_Commander Function ******
}










__int128 findMinimumPrimeBook( __int128 readTileCount, __int128* bookIndex) {
  //  system("cls");
  //  cout << "BEGIN FIND MINIMUMPRIMEBOOK "<< endl;   realm_os_user_input(userInput);
    __int128 infiniteWalk=bookIndex[readTileCount-1] +2;
    __int128 maxDivisibleNumberMaxNeeded = (infiniteWalk +(singers*perThreadSlices)+2)/3;

string128Class infiniteWalkString(infiniteWalk);
string128Class maxDivisibleNumberMaxNeededString(maxDivisibleNumberMaxNeeded); 

bool search = true;
__int128 findTile=0;
 //  cout << "BEGIN FIND MINIMUMPRIMEBOOK WHILE LOOP"<< endl;   realm_os_user_input(userInput);

while(search==true){
     string128Class bookIndexFindTileString(bookIndex[findTile]);
  //   cout << "Current Tile : "  << int(findTile)<<  "  maxDivisibleNeeded : " << maxDivisibleNumberMaxNeededString.getString() << "  For InfiniteWalk : " << infiniteWalkString.getString() << endl;
   if (maxDivisibleNumberMaxNeeded < bookIndex[findTile] ){
      string128Class tileIndexedString(bookIndex[findTile]);
     //  cout << "\033[6;1H" << "                                                                       Minimum PrimeBooks Needed : " << int(findTile)<< " : " << tileIndexedString.getString() << endl;
      search = false;
   }
  else{ findTile++;
    //  cout << "\033[1;1H" << " Mimimum PrimeBooks Needed : " << int(findTile)<< " :  NOT " << bookIndexFindTileString.getString() << endl;

}


}
   //cout << "MINIMUMPRIMEBOOK FINISHED "<< endl;   realm_os_user_input(userInput);
return findTile;
}


















































































































bool verifyPrimeGear(  __int128 myInfiniteWalk )
{

bool findPrime = true;
  __int128 isPrime = false; __int128 myTileWalk=0;  __int128 myBreezeWalk=0;
__int128 primeBuild =3 ; 
//cout << "                begin VERIFY PRIME : "<< int(infiniteWalk) << endl;  

__int128   primeRange = ( myInfiniteWalk / primeBuild ) +1;
while(findPrime){
//cout << "primebuild = " << int(primeBuild) << "  ";  cin >> userInput; 

if ( myInfiniteWalk % primeBuild == 0 ){
   findPrime = false;
   isPrime = false;

} else {
   primeRange = ( myInfiniteWalk / primeBuild ) +1;
   if ( primeBuild > primeRange ){
      findPrime=false;
      isPrime=true; 
//cout << "                                       ****isPrime=true;******" << endl;





   } else {
//cout << "Querry for next PrimeBuild "<< endl; 
primeBuild+= breeze()*2;
//if(myBreezeWalk<grid){ } else {
//myTileWalk++; myBreezeWalk=0; };
  //       primeBuild += myTiles[myTileWalk][myBreezeWalk]*2;
//myBreezeWalk++;
//cout << "primebuild = " << int(primeBuild) << "  ";  realm_os_user_input( userInput); 
// primeBuild+=2;
  }  // IF PrimeRange

} // IF ELSE % == 0
still(0);
} // FIND PRIME


if (isPrime){
return true;

} else {
return false;
}
} // endl verify Prime function









































































































































































































































































__int128 nextWalkPrime(  __int128 myInfiniteWalk )
{

__int128 myPrimeFindsLocal=0;



__int128 primeDifference=0;
__int128 primeBuild=0;

__int128 myPreviousPrime = 0;



  bool findPrime=true;
  bool dance=true;
  bool isPrime = false;
  bool findPrevious=true;


while ( findPrime==true ){
myInfiniteWalk+=2;

isPrime = slowWalkToSundayDivise(myInfiniteWalk);



if ( isPrime== true){





return myInfiniteWalk;


}


 
//cout << "my InfiniteWalk " << int(myInfiniteWalk)<< endl;
  
} // continue prime number search


} // Close return nextPrime function















































































































































































































































































__int128 moonWalkPrime(   __int128 myInfiniteWalk )
{


__int128 myPrimeFindsLocal=0;

__int128 singer =0;
__int128 countThis=0;
__int128 primeDifference=0;
__int128 primeBuild=0;
__int128 intTail=0;
__int128 myPreviousPrime = 0;
__int128 moonWalker = 0;
__int128 slice=0;
__int128 spaceBuffer =0;
  bool findPrime=true;
  bool dance=true;
  bool isPrime = false;
  bool findPrevious=true;


while ( findPrime==true ){
myInfiniteWalk+=-2;

isPrime = verifyPrime(myInfiniteWalk);



if ( isPrime== true){


//  myPreviousPrime =  myInfiniteWalk; 

            still(singer);
return myInfiniteWalk;


}


 
//cout << "my InfiniteWalk " << int(myInfiniteWalk)<< endl;
  
} // continue prime number search


} // Close return previousPrime function












































































































































































































































































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




































































































































void gui(){
string col1Spacer = "   ";
string col2Spacer = "                          ";
string col3Spacer = "                                      ";

for (int gridRowWalk = 0; gridRowWalk < guiGridHeight; gridRowWalk++) {

  //   if (guiUpdate[gridRowWalk]==true){
       string128Class gridRowWalkString(gridRowWalk+2);
      string coutLocator ="\033["+gridRowWalkString.getString()+";1H";
   //   cout << gridRowWalkString.getString() << " ";


      cout << coutLocator << col1Spacer << col2Spacer << col3Spacer << guiGrid[2][gridRowWalk][1];
      cout << coutLocator << col1Spacer << col2Spacer << guiGrid[1][gridRowWalk][1];
      cout << coutLocator  << col1Spacer << guiGrid[0][gridRowWalk][1];
    //  guiUpdate[gridRowWalk] = false;
   //  }
}

 cout << "\033[0;1H";
}







































































































































































































































































































void exportTile(string targetTileName){
// cout << "Begin exportTile                "<< endl;  realm_os_user_input(userInput);     
   byte* fileTile;    fileTile = tiles[targetTileName];
  string targetTileNamePath = "PrimeBookOne\\" + targetTileName + ".prime";
  ofstream copy( targetTileNamePath , std::ios::binary);
//   cout << "                  Begin Write         copy.write(reinterpret_cast<const char*>(fileTile), grid)       "<< endl;  realm_os_user_input(userInput);     
  copy.write(reinterpret_cast<const char*>(fileTile), grid);
  copy.close();

  compressTile(targetTileName);

  //fstream PrimeOneIndex ;
  //PrimeOneIndex.open("PrimeBookOne\\PrimeBookIndex.txt",
  //fstream::in | fstream::out | fstream::app);

  //string128Class infiniteWalkString(infiniteWalk);
  //string stringBean2= infiniteWalkString.getString();

//mark indexArray





//  PrimeOneIndex  << stringBean2 <<endl;
  //PrimeOneIndex.close();
  //infiniteWalkStart=infiniteWalkAdd;
  // cout  << " ETCHED FILE TO WINDOWS OS FS : " << targetTileNamePath << endl << endl;



















     } //exportTile finish






























































































void guiPrime(){
guiGrid[0][0][1] =guiGrid[0][0][0]+"Win64|";
guiGrid[1][0][1] =guiGrid[1][0][0];
guiGrid[2][0][1] =guiGrid[2][0][0] +guiGrid[2][0][2]; // +"1340|"; // BUILD;
//guiGrid[0][1][1] =" ";
//guiGrid[1][1][1] =" ";
guiGrid[2][1][1] = uniqueIdGlobal;
guiGrid[0][2][1] =guiGrid[0][2][0] + "127.0.0.1|";
//guiGrid[1][2][1] =" ";
guiGrid[2][2][1] ="file:///workspace/app/PB1/PrimeBook.CPP/primebookonexlsm.archive/2025/[primeOne_2025_4_7i.xlsm]librarian_functions";
guiGrid[0][3][1] =guiGrid[0][3][0]+guiGrid[0][3][2]; // +"0x2ec|";
//guiGrid[1][3][1] =" ";
guiGrid[2][3][1] =guiGrid[2][3][0] + "1|";
guiGrid[0][4][1]=guiGrid[0][4][0]+"0x344| "; // Thread Handle : 
//guiGrid[1][4][1] =" ";
guiGrid[2][4][1] =guiGrid[2][4][0]+"Identified as INTEL|";
//guiGrid[0][5][1] =" ";
//guiGrid[1][5][1] =" ";
//guiGrid[2][5][1] =" ";
//guiGrid[0][6][1] =" ";
//guiGrid[1][6][1] =" ";
//guiGrid[2][6][1] =" ";
//guiGrid[0][7][1] =" ][ ";
//guiGrid[1][7][1] =" ";
//guiGrid[2][7][1] =" ";
//guiGrid[0][8][1] =" ";
//guiGrid[1][8][1] =guiGrid[1][8][0];
guiGrid[2][8][1] = guiGrid[2][8][0] + guiGrid[2][8][2];
//guiGrid[0][9][1] =" ";
//guiGrid[1][9][1] =guiGrid[1][9][0];
guiGrid[2][9][1] = guiGrid[2][9][0] + guiGrid[2][9][2]; //primebooks created
//guiGrid[0][10][1] =" ";
//guiGrid[1][10][1] =" ";
guiGrid[2][10][1]= guiGrid[2][10][0]+  guiGrid[2][10][2]; // ="PrimeBooks Loaded : ";
//guiGrid[0][11][1] =" ";
//guiGrid[1][11][1] =" ";
guiGrid[2][11][1] = guiGrid[2][11][0]+ guiGrid[2][11][2];//  ="Tile Sum : ";
//guiGrid[0][12][1] =" ";
//guiGrid[1][12][1] =" ";
guiGrid[2][12][1] =guiGrid[2][12][0]+guiGrid[2][12][2];  //0] ="Previous Tile Sum : ";
//guiGrid[0][13][1] =" ";
//guiGrid[1][13][1] =" ";
guiGrid[2][13][1] =guiGrid[2][13][0]+guiGrid[2][13][2] ;//  ="gitInterval :  ";
//guiGrid[0][14][1] =" ";
//guiGrid[1][14][1] =" ";
guiGrid[2][14][1] =guiGrid[2][14][0]+guiGrid[2][14][2]; // ="gitUpdates : ";
//guiGrid[0][15][1] =" ";
//guiGrid[1][15][1] =" ";
guiGrid[2][15][1] =guiGrid[2][15][0]+guiGrid[2][15][2];  //][0] ="git Clocks : ";
guiGrid[0][16][1] =guiGrid[0][16][0] +guiGrid[0][16][2]; //+ "Prime Ratio =  ";
//guiGrid[1][16][1] =" ";
guiGrid[2][16][1] =guiGrid[2][16][0]+guiGrid[2][16][2]; //slices
// guiGrid[0][17][1] =guiGrid[0][17][0]  +guiGrid[0][17][2]; //"Total Tiles = ";
//guiGrid[1][17][1] =" ";
guiGrid[2][17][1] =guiGrid[2][17][0]+ "1,048,576|"; //"Primer =
//guiGrid[0][18][1] =" ";
//guiGrid[1][18][1] =" ";
guiGrid[2][18][1] =guiGrid[2][18][0]+guiGrid[2][18][2]; //Singers
guiGrid[0][19][1] =  guiGrid[0][19][0] + guiGrid[0][19][2]; // "Largest Difference = ";
//guiGrid[1][19][1] =" ";
guiGrid[2][19][1] =guiGrid[2][19][0]+ guiGrid[2][19][2]; //"Power = 20 ";
guiGrid[0][20][1] =guiGrid[0][20][0] + guiGrid[0][20][2]; // "infiniteWalk = ";
//guiGrid[1][20][1] =" ";
guiGrid[2][20][1] =guiGrid[2][20][0] +  guiGrid[2][20][2];   // "Grid = 1][048][576 ";
guiGrid[0][21][1] = guiGrid[0][21][0] + guiGrid[0][21][2] ; // "Total Primes = ";
//guiGrid[1][21][1] =" ";
guiGrid[2][21][1] = guiGrid[2][21][0] + guiGrid[2][21][2]; // infiniteCyclesStarts
//guiGrid[0][22][1] =" ";
guiGrid[1][22][1]  =guiGrid[1][22][0]; // "PRIMEBOOK  ONE ";
guiGrid[2][22][1] = guiGrid[2][22][0] + guiGrid[2][22][2]; // infinitecyclefinishes
//guiGrid[0][23][1] =" ";
guiGrid[1][23][1]  =guiGrid[1][23][0]; // "PRIMEBOOK  ONE ";
guiGrid[2][23][1] = guiGrid[2][23][0] +" Yes|";  // "(c)PU = Yes ";
//guiGrid[0][24][1] =" ";
guiGrid[1][24][1] =guiGrid[1][24][0]; // "PRIMEBOOK  ONE ";
guiGrid[2][24][1] =guiGrid[2][24][0] +"No|";   // "(g)PU = No ";
guiGrid[0][25][1] = guiGrid[0][25][0] + "300|";  // "Network Peers  = 300 ";
guiGrid[1][25][1] =guiGrid[1][25][0]; // "PRIMEBOOK  ONE ";
guiGrid[2][25][1] = guiGrid[2][25][0] + " No|"; // "(t)hermal = No ";
guiGrid[0][26][1] = guiGrid[0][26][0] + "12.34.56.78|"; //  "XXX Active ip = 1  XX ";
guiGrid[1][26][1]  =guiGrid[1][26][0]; // "PRIMEBOOK  ONE ";
guiGrid[2][26][1] =guiGrid[2][26][0] + " 55555|"; // "XX Port = 55555 ";
//guiGrid[0][27][1] =" ";
//guiGrid[1][27][1] =" ";
//guiGrid[2][27][1] =" ";
//guiGrid[0][28][1] =" ";
//guiGrid[1][28][1] =" ";
//guiGrid[2][28][1] =" ";
//guiGrid[0][29][1] =" ";
//guiGrid[1][29][1] =" ";
//guiGrid[2][29][1] =" ";
//guiGrid[0][30][1] =" ";
//guiGrid[1][30][1] =" ";
//guiGrid[2][30][1] =" ";
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


void guiDefaultsSet(){

guiGrid[0][0][0] ="OS : ";
guiGrid[1][0][0] =" ";
guiGrid[2][0][0] ="BUILD # ";

guiGrid[0][1][0] =" ";
guiGrid[1][1][0] =" ";
guiGrid[2][1][0] =" "; // uniqueIdGlobal; 

guiGrid[0][2][0] ="Net :  ";
guiGrid[1][2][0] =" ";
guiGrid[2][2][0] =" ";  //"XLSM.";

guiGrid[0][3][0] ="Windows Handle : ";
guiGrid[1][3][0] =" ";
guiGrid[2][3][0] ="Total DirectX GPUs : ";

guiGrid[0][4][0] ="Thread Handle : ";
guiGrid[1][4][0] =" ";
guiGrid[2][4][0] ="GPU[0] : ";

guiGrid[0][5][0] ="";
guiGrid[1][5][0] =" ";
guiGrid[2][5][0] =" ";

guiGrid[0][6][0] ="";
guiGrid[1][6][0] =" ";
guiGrid[2][6][0] =" ";

guiGrid[0][7][0] ="";
guiGrid[1][7][0] ="";
guiGrid[2][7][0] =" ";

guiGrid[0][8][0] =" ";
guiGrid[1][8][0] ="";
guiGrid[2][8][0] ="PrimeBook Tiles   : ";

guiGrid[0][9][0] =" ";
guiGrid[1][9][0] ="";
guiGrid[2][9][0]="PrimeBooks Created : ";

guiGrid[0][10][0] =" ";
guiGrid[1][10][0] ="";
guiGrid[2][10][0] ="PrimeBooks Loaded  : ";

guiGrid[0][11][0] =" ";
guiGrid[1][11][0] ="";
guiGrid[2][11][0] ="Tile Sum : ";

guiGrid[0][12][0] =" ";
guiGrid[1][12][0] =" ";
guiGrid[2][12][0] ="Previous Tile Sum : ";

guiGrid[0][13][0] =" ";
guiGrid[1][13][0] =" ";
guiGrid[2][13][0] ="gitInterval : ";

guiGrid[0][14][0] =" ";
guiGrid[1][14][0] =" ";
guiGrid[2][14][0] ="gitUpdates : ";

guiGrid[0][15][0] =" ";
guiGrid[1][15][0] =" ";
guiGrid[2][15][0] ="git Clocks : ";

guiGrid[0][16][0] ="Prime Ratio =  ";
guiGrid[1][16][0] =" ";
guiGrid[2][16][0] ="Slices = ";

guiGrid[0][17][0] =" ";
guiGrid[1][17][0] =" ";
guiGrid[2][17][0] ="Primer = ";

guiGrid[0][18][0] =" ";
guiGrid[1][18][0] =" ";
guiGrid[2][18][0] ="Singers = ";

guiGrid[0][19][0] ="Largest Difference = ";
guiGrid[1][19][0] =" ";
guiGrid[2][19][0] ="Grid Power = ";

guiGrid[0][20][0] ="infiniteWalk = ";
guiGrid[1][20][0] =" ";
guiGrid[2][20][0] ="Grid = ";

guiGrid[0][21][0] ="Total Primes = ";
guiGrid[1][21][0] =" ";
guiGrid[2][21][0] ="iCycleStarts   : ";

guiGrid[0][22][0] =" ";
guiGrid[1][22][0] ="  || ||||| ||| ||";
guiGrid[2][22][0] ="iCycleFinishes : ";

guiGrid[0][23][0] =" ";
guiGrid[1][23][0] =" |                |";
guiGrid[2][23][0] ="(c)PU = ";

guiGrid[0][24][0] =" ";
guiGrid[1][24][0] ="|  PRIMEBOOK  ONE";
guiGrid[2][24][0] ="(g)PU = ";

guiGrid[0][25][0] ="Network Peers  = ";
guiGrid[1][25][0] =" |";
guiGrid[2][25][0] ="(t)hermal = ";

guiGrid[0][26][0] ="Net Active IP = ";
guiGrid[1][26][0] ="  || |||||||||||";
guiGrid[2][26][0] ="Net Port = ";

guiGrid[0][27][0] =" ";
guiGrid[1][27][0] =" ";
guiGrid[2][27][0] =" ";

guiGrid[0][28][0] =" ";
guiGrid[1][28][0] =" ";
guiGrid[2][28][0] =" ";

guiGrid[0][29][0] =" ";
guiGrid[1][29][0] =" ";
guiGrid[2][29][0] =" ";

guiGrid[0][30][0] =" ";
guiGrid[1][30][0] =" ";
guiGrid[2][30][0] =" ";



}




























































































































































































void etchTile( byte data) {
//if(etchWalk%10000==0){
//cout << "EtchTile : " << int(data) << "  EtchWalk : " << int(etchWalk)<< endl;}
//cin >> userInput;

 byte* targetTile;


  string128Class tileCountString ( tileCount );    
  targetTileName = "Tile0" + tileCountString.getString();
//byte*     targetTile = tiles[ targetTileName ];

  if (etchWalk < grid) {

     targetTile = tiles[ targetTileName ];
     
     targetTile[etchWalk] = data;
     etchWalkSum+=data;  // ADD ONTO TILE SUM
}  else { 
 exportTile( targetTileName );// cout << "export Tile" << endl;
gearCreatedTiles++;  guiGrid128[2][9]=gearCreatedTiles; // primebooksCreated talley
guiGrid128[2][11] = etchWalkSum;
previousEtchWalkSum =  previousEtchWalkSum;   // PREVIOUS TILESUM
guiGrid128[2][12] = previousEtchWalkSum; // cout << "previousEtchWalkSum : 
bookIndexTotals[tileCount]= etchWalkSum;        
     tileCount++;    etchWalk = 0;

    string128Class tileCountString ( tileCount );

    targetTileName = "Tile0" + tileCountString.getString() ;
    byte* newTile = new byte[grid]();
    tiles[targetTileName] = newTile;

    targetTile = tiles[ targetTileName ];

  etchWalkSum=data; // BEGIN NEW TILE SUM
    targetTile[etchWalk] = data;
  }

  etchWalk++;
} // ETCHTILE






































































































void gui128String(){

//  guiGrid128[0][0] =0;//"OS : ";
//  guiGrid128[1][0] =0;
string128ClassComma buildString(2502); //"BUILD # ";    =BUILD!C17
guiGrid[2][0][2]  = buildString.getString();
//  guiGrid128[0][1]  =0;
//  guiGrid128[1][1] =0;
//  guiGrid128[2][1] =0;//"XLSM.";

//  guiGrid128[0][2]  =0;//"Net :  ";
//  guiGrid128[1][2]  =0;
//  guiGrid128[2][2] =0;

//  guiGrid128[0][3]  =0;//"Windows Handle : ";
//  guiGrid128[1][3] =0;
//  guiGrid128[2][3] =0;//"Total DirectX GPUs : ";

//  guiGrid128[0][4]  =0;//"Thread Handle : ";
//  guiGrid128[1][4] =0;
//  guiGrid128[2][4] =0; // GPU[0] : ";

//  guiGrid128[0][5] =0; // ";
//  guiGrid128[1][5] =0;
//  guiGrid128[2][5] =0;

//  guiGrid128[0][6] =0; // ";
//  guiGrid128[1][6] =0;
//  guiGrid128[2][6] =0;

//  guiGrid128[0][7] =0; // ";
//  guiGrid128[1][7] =0;
//  guiGrid128[2][7] =0;

//  guiGrid128[0][8] =0;
//  guiGrid128[1][8] =0; // ";
   string128ClassComma totalTilesString(   guiGrid128[2][8] );   guiGrid[2][8][2] =totalTilesString.getString();

//  guiGrid128[0][9] =0;
//  guiGrid128[1][9] =0;
string128ClassComma  primeBooksCreatedString(guiGrid128[2][9]);  guiGrid[2][9][2] = primeBooksCreatedString.getString();

//  guiGrid128[0][10] =0;
//  guiGrid128[1][10] =0;
string128ClassComma   minimumPrimeBookNeededString(guiGrid128[2][10]); guiGrid[2][10][2] = minimumPrimeBookNeededString.getString(); // PrimeBooks Loaded : ";

//  guiGrid128[0][11] =0;
//  guiGrid128[1][11] =0;
string128ClassComma   tileSumString( guiGrid128[2][11]);  guiGrid[2][11][2] =  tileSumString.getString(); // Tile Sum : ";

//  guiGrid128[0][12] =0;
//  guiGrid128[1][12] =0;
string128ClassComma  previousTileSumString( guiGrid128[2][12]);   guiGrid[2][12][2] = previousTileSumString.getString();  // Previous Tile Sum : ";

//  guiGrid128[0][13] =0;
//  guiGrid128[1][13] =0;
string128ClassComma conductorUpdateIntervalString(guiGrid128[2][13]); guiGrid[2][13][2]=conductorUpdateIntervalString.getString(); // gitInterval : ";

//  guiGrid128[0][14] =0;
//  guiGrid128[1][14] =0;
string128ClassComma  statusUpdatesString( guiGrid128[2][14]);  guiGrid[2][14][2] = statusUpdatesString.getString(); // gitUpdates : ";

//  guiGrid128[0][15] =0;
//  guiGrid128[1][15] =0;
string128ClassComma gitClocksString( guiGrid128[2][15]);  guiGrid[2][15][2]= gitClocksString.getString(); // gitClocks : ";

string128ClassComma primeRatioString(  guiGrid128[0][16] );   guiGrid[0][16][2]=primeRatioString.getString();  // Prime Ratio =  ";
//  guiGrid128[1][16] =0;
string128ClassComma slicesString(  guiGrid128[2][16]  );   guiGrid[2][16][2]=slicesString.getString();   //  guiGrid128[2][16] =0; // Slices = ";

//string128ClassComma totalTilesString(   guiGrid128[0][16] );   guiGrid[0][17][2] =totalTilesString.getString(); // Total Tiles = ";
//  guiGrid128[1][17] =0;
//  guiGrid128[2][17] =0; // Primer = ";

//  guiGrid128[0][18] =0;
//  guiGrid128[1][18] =0;
  string128ClassComma singersString(guiGrid128[2][18]); guiGrid[2][18][2] =singersString.getString(); // Singers = ";

string128ClassComma pDlargeString(   guiGrid128[0][19] );  guiGrid[0][19][2]=pDlargeString.getString();  // Largest Difference = "; 
//  guiGrid128[1][19] =0;
string128ClassComma powerOfString(     guiGrid128[2][19] );   guiGrid[2][19][2] =powerOfString.getString();  ; // Grid Power = ";  powerOf

string128ClassComma infiniteWalkString(    guiGrid128[0][20] );   guiGrid[0][20][2] =infiniteWalkString.getString(); // infiniteWalk = ";
//  guiGrid128[1][20] =0;
string128ClassComma gridString(    guiGrid128[2][20] );   guiGrid[2][20][2] =gridString.getString();// Grid = ";

string128ClassComma totalPrimesString(   guiGrid128[0][21] );  guiGrid[0][21][2] =totalPrimesString.getString(); // Total Primes = ";
//  guiGrid128[1][21] =0;
string128ClassComma iCycleStartsString(infiniteCycleStarts) ;  guiGrid[2][21][2] =   iCycleStartsString.getString();  // infinitecyclestarts

//  guiGrid128[0][22] =0;
//  guiGrid128[1][22] =0; //   || ||||| ||| ||";
string128ClassComma iCycleFinishesString( infiniteCycleFinishes) ;  guiGrid[2][22][2] =   iCycleFinishesString.getString();   // infinitecyclesfinishes

//  guiGrid128[0][23] =0;
//  guiGrid128[1][23] =0; //  |                |";
//  guiGrid128[2][23] =0; // (c)PU = ";

//  guiGrid128[0][24] =0;
//  guiGrid128[1][24] =0; // |  PRIMEBOOK  ONE";
//  guiGrid128[2][24] =0; // (g)PU = ";

//  guiGrid128[0][25] =0; // Network Peers  = ";
//  guiGrid128[1][25] =0; //  |";
//  guiGrid128[2][25] =0; // (t)hermal = ";

//  guiGrid128[0][26] =0; // Net Active IP = ";
//  guiGrid128[1][26] =0; //   || |||||||||||";
//  guiGrid128[2][26] =0; // Net Port = ";

//  guiGrid128[0][27] =0;
//  guiGrid128[1][27] =0;
//  guiGrid128[2][27] =0;

//  guiGrid128[0][28] =0;
//  guiGrid128[1][28] =0;
//  guiGrid128[2][28] =0;

//  guiGrid128[0][29] =0;
//  guiGrid128[1][29] =0;
//  guiGrid128[2][29] =0;

//  guiGrid128[0][30] =0;
//  guiGrid128[1][30] =0;
//  guiGrid128[2][30] =0;



}


























































































































































































void initiateTile(__int128 tileNumber ){

  string128Class tileNumberString ( tileNumber ); 
  targetTileName = "Tile0" + tileNumberString.getString();  byte* targetTile = new byte[grid];
  byte* newTile = new byte[grid];

  tiles[targetTileName] = newTile;
  targetTile = newTile;



} // INITIATETILE





































































































































bool verifyPrime(  __int128 myInfiniteWalk )
{

bool findPrime = true;
  __int128 isPrime = false; __int128 myTileWalk=0;  __int128 myBreezeWalk=0;
__int128 primeBuild =3 ; 
//cout << "                begin VERIFY PRIME : "<< int(infiniteWalk) << endl;  

__int128   primeRange = 0; //( myInfiniteWalk / primeBuild ) +1;
while(findPrime){
//cout << "primebuild = " << int(primeBuild) << "  ";  cin >> userInput; 

if ( myInfiniteWalk % primeBuild == 0 ){
   findPrime = false;
   isPrime = false;

} else {
   primeRange = ( myInfiniteWalk / primeBuild ) +1;
   if ( primeBuild > primeRange ){
      findPrime=false;
      isPrime=true; 
//cout << "                                       ****isPrime=true;******" << endl;





   } else {
//cout << "Querry for next PrimeBuild "<< endl; 
primeBuild+= breeze()*2;




//cout << "primebuild = " << int(primeBuild) << "  ";  realm_os_user_input( userInput); 
// primeBuild+=2;
  }  // IF PrimeRange

} // IF ELSE % == 0
still(0);
} // FIND PRIME


if (isPrime){
return true;

} else {
return false;
}
} // endl verify Prime function











































































































































































































































































void initiateBreeze(){
  byte* threadBreezeWalk = new byte[singers];
}














































































































































bool slowWalkToSundayDivise(__int128 data){

__int128 d3=data/2 +1;
  __int128 primeBuild = 3;
__int128 quickStep=0;


while(primeBuild < d3){
    if (data%primeBuild==0){ 
  //    cout << " primeBuild DIVISIBLE by " << int(primeBuild ) << " data " << int(data)  << "" << endl;
  return false;
    }

    else  if( primeBuild > (( data /primeBuild) +1) ){
      // cout << " primeBuild " << int(primeBuild ) << " infiniteWalk " << int(data)  << "" << endl;
    return true;
    }  // ******** IF PRIME BY RANGE *******

    else { 

//  primeBuild+= breeze(0)*2; 

   primeBuild+=2;  








//cout << "prime : " << int(primeBuild)<< " dif : "<< int( quickPrime[quickStep])<< "          " ;





    }

}


      return true;








} // PRIMEDIVISE





























































































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


















































































































void logStart(string data){




  fstream primeBookLog ;
  primeBookLog.open("PrimeBookOne\\primebooklog.txt",
  fstream::in | fstream::out | fstream::app);




  primeBookLog  << endl << data << "   ";
  primeBookLog.close();


} // finish primeBookLog


































































































































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


































































































































void logExit(string data){




  fstream primeBookLog ;
  primeBookLog.open("PrimeBookOne\\primebooklog.txt",
  fstream::in | fstream::out | fstream::app);




  primeBookLog  << data<< endl;
  primeBookLog.close();


} // finish primeBookLog


































































































































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





















































































































void etchTileCache( byte data) {
//if(etchWalk%10000==0){
//cout << "EtchTile : " << int(data) << "  EtchWalk : " << int(etchWalk)<< endl;}
//cin >> userInput;

 byte* targetTile;


  string128Class tileCountString ( tileCount );    
  targetTileName = "Tile0" + tileCountString.getString();
//byte*     targetTile = tiles[ targetTileName ];

  if (etchWalkArray < grid) {

     targetTile = tiles[ targetTileName ];
     
     targetTile[etchWalkArray] = data;
     etchWalkSum+=data;  // ADD ONTO TILE SUM
}  else { 
 exportTile( targetTileName );// cout << "export Tile" << endl;
gearCreatedTiles++;  guiGrid128[2][9]=gearCreatedTiles; // primebooksCreated talley
guiGrid128[2][11] = etchWalkSum;
previousEtchWalkSum =  previousEtchWalkSum;   // PREVIOUS TILESUM
guiGrid128[2][12] = previousEtchWalkSum; // cout << "previousEtchWalkSum : 
bookIndexTotals[tileCount]= etchWalkSum;        
     tileCount++;    etchWalkArray = 0;

    string128Class tileCountString ( tileCount );

    targetTileName = "Tile0" + tileCountString.getString() ;
    byte* newTile = new byte[grid]();
    tiles[targetTileName] = newTile;

    targetTile = tiles[ targetTileName ];

  etchWalkSum=data; // BEGIN NEW TILE SUM
    targetTile[etchWalkArray] = data;
  }

  etchWalkArray++;
} // ETCHTILE








































































































void scrubSlate(){
  for (auto& pair : slate) {delete[] pair.second;}
  delete[] threadTotal ;    delete[] threadSlateWalk ;  }
__int128 threadReadTotals(__int128 singer){//return threadTotal[singer] ;
 } // BREAKSLATE
 
__int128 primeTotalCurrent(){ return total ; }
//__int128 infiniteWalkCurrent() {return infiniteWalk;}
__int128 threadSlicesCurrent(){ return perThreadSlices;}
__int128 threadSingersCurrent(){ return singers;}





































































































































vector<byte> ptv_primeBookAuthor(__int128 wolfLeap, int wolfHunger, int privateGuestAssignedQue, int privatePrimeQue){
vector<byte> wolfCatch;
__int128 wolfByte =   pow(2,wolfHunger);
__int128 wolfDomain = wolfLeap+wolfByte;
__int128 totalPrimesFound =0;
__int128  previousPrime = moonWalkPrime(wolfLeap);
char userInput;
system("cls");
cout << "wolfLeap: " <<int(wolfLeap) << endl;
cout << "wolfHunger: " <<int(wolfHunger) << endl;
cout << "wolfByte: " <<int(wolfByte) << endl;
cout << "wolfDomain: " <<int(wolfDomain) << endl;
cout << "previousPrime: " <<int(previousPrime) << endl;
cout << "privateGuestAssignedQue: " <<int(privateGuestAssignedQue) << endl;
cout << "privatePrimeQue: " <<int(privatePrimeQue) << endl;
cout << "NOW COMPUTING PLEASE WAIT "<< endl;
while (wolfLeap < wolfDomain){
if (verifyPrimeGear(wolfLeap)){
  primeDifference = (wolfLeap - previousPrime)/2;
  previousPrime=wolfLeap;
totalPrimesFound++;


wolfCatch.push_back(primeDifference);



}

   wolfLeap += 2;
} // FINISH REQUESTED WOLFDOMAIN Prowel







//cout << "totalPrimesFound: " << int(totalPrimesFound);   cin >> userInput;

return wolfCatch;




} // finish ptv_primeBookAuthor FUNCTION










































string ptv_hostPrimeBookLeap(int wolfHunger, string wolfId){


privateWolfLeap[privateLeapsLap] = infiniteWalk;

//privateWolfFeast[privateLeapsLap]= wolfHunger;

privateWolfLeapAssingment[privateLeapsLap] = wolfId;

string128Class returnInfiniteWalkString(infiniteWalk);


infiniteWalk+=wolfHunger;

privateLeapsLap++;

return returnInfiniteWalkString.getString();


}







































































































































































































































































































void ptv_stagePrimeBook(int privateGuestAssignedQue, string privateGuestAssignedId){





privateWolfLeapAssingment[privateGuestAssignedQue] = privateGuestAssignedId;

if (privateGuestAssignedQue != (privateLeapsLapDouble-1)){
privatePrimeQue++;

} else { 
privatePrimeQue =0;
}


} // Finish stage primebook































































































































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




























void ptv_quiltInit(int quiltQues){
int quiltPrep=0;


    while(quiltPrep < quiltQues){

      privateWolfPrimeQueAssingment[quiltPrep] = -1;
      quiltPrep++;

   }

} // finish Quilt INIT







































































































































byte breeze() {
bool forever = true;
while (forever== true){
//cout << "    BBBBBBBBBBBBBBBBBBBEEEEEEEEEEEEEEEEEEEEEEEEEEEZZZZZZZZZZZZZZZZZZZZZEEEEEEEEEEEEEEEEEEEEEE"<< endl<< endl;
  if (threadBreezeWalk[0] == grid){
        threadTileWalk[0]++;

//cout << "threadTileWalk[singer] " << int(threadTileWalk[singer]) <<"  grid : "<< int(grid)<< endl;
//cout << "singer " << int(singer) << endl;
//cout << " threadBreezeWalk[singer] "<< int(threadBreezeWalk[singer] ) << "  singer =" << int(singer)<<  " start " << endl;
        threadBreezeWalk[0] = 0;
//cout << " threadBreezeWalk[singer] "<< int(threadBreezeWalk[singer] ) << "  singer =" << int(singer)<<  " finish " << endl;
  } else {

  string128Class tileWalkString(threadTileWalk[0]);  // prepare load by name of array
  string myTargetTileName = "Tile0" +  tileWalkString.getString(); // create name of primebook
//cout << "Breeze read : " << targetTileName << endl;
//cin >> userInput;
// check if the requested tile is MEM SSD RING WEB

// if tileLocationXX =  00 mem read from pre-loaded memory

  byte* myTargetTile = tiles[myTargetTileName];
  int myBreezeWalk = threadBreezeWalk[0];
  byte return16 = myTargetTile[myBreezeWalk];
  threadBreezeWalk[0]++; // should delete this targetTile
//if (return16 > 9) {cout << int(threadTileWalk[singer]) << " " <<  int(return16) << " ";}


// else if tileLocationXX = 01 SSD read from disk from primebookcache at primebookreadlocation00


// else if tileLocationXX = 10 RING read ask host for primebook00.zip file unzip it then load it into memory or ssd


// if tileLocationXX = 11 WEB read ask www.primebook.one for the primebook00.zip file then load it into memory or ssd


  return return16;
}
}


}  // BREEZE



































































































void ptv_gearFeast(int privatePrimeQue, byte  privatePrimeByte){



cout << privatePrimeQue << "# byte : " << int(privatePrimeByte); 


// privatePrimeBatch[privatePrimeQue][queEtch[privatePrimeQue]++] = privatePrimeByte ;


//queDelivered[privatePrimeQue]= true;

} // finish gear fest
















































































































































































































































































































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
__int128 primeBuild = 3;  
  cout << " 111 " << endl;      realm_os_user_input(userInput);
while (readWalk<total){   cout << " 222 " << endl;      realm_os_user_input(userInput);
  primeBuild+= breeze()*2; 

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



















































































































void ptv_etchTileConduit( byte data) {


//if(etchWalk%10000==0){
//cout << "EtchTile : " << int(data) << "  EtchWalk : " << int(etchWalk)<< endl;}
//cin >> userInput;

 byte* targetTile;


  string128Class tileCountString ( tileCount );    
  targetTileName = "Tile0" + tileCountString.getString();
     targetTile = tiles[ targetTileName ];
     targetTile[etchWalk] = data;
     etchWalkSum+=data;  // ADD ONTO TILE SUM
  etchWalk++;
  if (etchWalk == grid) {
guiGrid128[2][11] = etchWalkSum;
previousEtchWalkSum =  previousEtchWalkSum;   // PREVIOUS TILESUM
gearCreatedTiles++;  guiGrid128[2][9]=gearCreatedTiles; // primebooksCreated talley

guiGrid128[2][12] = previousEtchWalkSum; // cout << "previousEtchWalkSum : 
bookIndexTotals[tileCount]= etchWalkSum;        
  primeRatio =infiniteWalk/total;
 exportTile( targetTileName );// cout << "export Tile" << endl;

  etchWalkSum=0; // BEGIN NEW TILE SUM
     tileCount++;    
etchWalk = 0;

    string128Class tileCountString ( tileCount );
    targetTileName = "Tile0" + tileCountString.getString() ;
    byte* newTile = new byte[grid]();
    tiles[targetTileName] = newTile;

    targetTile = tiles[ targetTileName ];


    targetTile[0] = 0;
  }


}








































































































bool primeDivise(__int128 data){
__int128 quickStep=0;
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
   //   primeBuild+=       primeBuild+= breeze(0)*2;
      primeBuild+= 2 ;//primeBuild += quickPrime[quickStep]*2;
//quickStep++;
    }
  }  // cout << " ******** WHILE DANCE = TRUE LOOP ******* " << endl;
} // PRIMEDIVISE



















































































































void librarianDancer( __int128 singer,
                      __int128 myInfiniteWalk ,
                      __int128 perThreadSlices,  const int myMinimumTileCount,
                      byte* primeFindsArray )
{
        // cout << "  perThreadSlices = " << int(perThreadSlices) << endl;
        // cout << "Begin Dancer : " << int(singer)<< "  myWalk = " << int(myInfiniteWalk ) ;

// ProcessLogDeclare


__int128 process00[10];
__int128 process01[10];
__int128 process02[10];
__int128 process03[10];
__int128 process04[10];















// ProcessLogZero

process00[0]=0;  process00[1]=0;  process00[2]=0;  process00[3]=0;  process00[4]=0;  process00[5]=0;  process00[6]=0;  
process01[0]=0;  process01[1]=0;  process01[2]=0;  process01[3]=0;  process01[4]=0;  process01[5]=0;  process01[6]=0;  
process02[0]=0;  process02[1]=0;  process02[2]=0;  process02[3]=0;  process02[4]=0;  process02[5]=0;  process02[6]=0;  
process03[0]=0;  process03[1]=0;  process03[2]=0;  process03[3]=0;  process03[4]=0;  process03[5]=0;  process03[6]=0;  
process04[0]=0;  process04[1]=0;  process04[2]=0;  process04[3]=0;  process04[4]=0;  process04[5]=0;  process04[6]=0;  















string processName="";
__int128 myPrimeFindsLocalStep=0;
__int128 countThis=0;
__int128 primeDifference=0;
__int128 primeBuild = 0;
__int128 myPreviousPrime = 0;
__int128 moonWalker = 0;
__int128 slice=0;  int return16b=0;
__int128 spaceBuffer =0;
__int128 myPrimeFindsLocal=0;
__int128 d3=0; int dice=0;
__int128 startTime=0;
  int myBreezeWalk = 0;
  int itWorks=0;
  int jump = 6; 
  int myThreadBreezeWalk=0;
  int gridInt = grid;
  int gridWalker=0;  
  int myThreadTileWalk=0;
  int myTilePlacement =0;
  int minimumTileWalk=0;
  int TIlePlacement =0;
  byte return16 =0;
  bool foreverRead = true;
  bool findPrevious=true;
  bool dance=true;
  bool isPrime = false;

string128Class tileWalkString(myThreadTileWalk);  // prepare load by name of array
string targetTileName = "Tile0" +  tileWalkString.getString(); // create name of primebook

byte* targetTile = new byte[grid];

    const int arrayGrid = static_cast<int>(std::pow(2, 20)); // Convert to int for array size
    byte** myTiles = new uint8_t*[myMinimumTileCount]; // Allocate rows       // Dynamically allocate a 2D array
    for (int i = 0; i < myMinimumTileCount; ++i) {   myTiles[i] = new uint8_t[arrayGrid];} // Allocate columns for each row

byte* myTargetTile = new byte[gridInt];

while (minimumTileWalk<myMinimumTileCount){
   string128Class minimumTileWalkString(minimumTileWalk);  // prepare load by name of array
   string targetTileName = "Tile0" +  minimumTileWalkString.getString(); // create name of primebook
   byte*  myTargetTile= new byte[grid];   myTargetTile = tiles[targetTileName];
   while (gridWalker < gridInt){ myTiles[minimumTileWalk][gridWalker]=myTargetTile[gridWalker];  gridWalker++;} gridWalker=0; // cout << "   " << int(myTargetTile[gridWalker])<< "   " << int( myTiles[minimumTileWalk][gridWalker]) << "        ";
      minimumTileWalk++;}
      
// MOONWALKER FIND PREVIOUS BEGIN ****************************************************
moonWalker =  myInfiniteWalk;
while ( findPrevious==true ){ 
   moonWalker+=-2;
   d3 = moonWalker/3 +1;
   // vvvvvvvvvvvv DIVISE vvvvvvvvvvvv  DIVISE vvvvvvvvvvvv  DIVISE vvvvvvvvvvvv 
   primeBuild = 3;
   dance = true;
   
   while (dance == true){ 
     if (moonWalker%primeBuild==0){ 
         // cout << " primeBuild DIVISIBLE by " << int(primeBuild );  //  cout << " moonWalker " << int( moonWalker )  << "" << endl;
         isPrime = false;
         dance = false;
     }
     else  if( primeBuild > d3 ){
            //   cout << " primeBuild inDIVISIBLE by range " << int(primeBuild );
            //   cout << " moonWalker " << int( moonWalker )  << " singer" << int(singer) << endl;
        isPrime = true;
        findPrevious=false;
        dance = false;
     } else { 
             // Librarian Reader Segment Start
        if (myThreadBreezeWalk == gridInt){
                 // threadTileWalk[singer]++;
                 //cout << "threadTileWalk[singer] " << int(threadTileWalk[singer]) <<"  grid : "<< int(grid)<< endl;
                 //cout << "singer " << int(singer) << endl;
                 //cout << " threadBreezeWalk[singer] "<< int(threadBreezeWalk[singer] ) << "  singer =" << int(singer)<<  " start " << endl;
                 // cout << " threadBreezeWalk[singer] "<< int(threadBreezeWalk[singer] ) << "  singer =" << int(singer)<<  " finish " << endl;
                 //cout << "TargetTile Previous : "<< targetTileName;
           myThreadBreezeWalk = 0;
           myThreadTileWalk++;
           string128Class tileWalkString(myThreadTileWalk);              // prepare load by name of array
           string targetTileName = "Tile0" +  tileWalkString.getString();             // create name of primebook
           targetTile = tiles[targetTileName];
                 //cout << "   TargetTile Next : "<< targetTileName<< endl;
                 //cout << "Breeze read : " << targetTileName << endl;
                 //cin >> userInput;
                 // check if the requested tile is MEM SSD RING WEB
                 // if tileLocationXX =  00 mem read from pre-loaded memory
        }
        return16 = targetTile[myThreadBreezeWalk++];
             // Librarian Reader Segment FINISH
        primeBuild += return16*2;
    }
          //  cout << " moonwalk " << int(singer);  cout << " " << int(moonWalker)<<endl;
  } // cout << " ******** WHILE DANCE = TRUE LOOP ******* " << endl;
       // ^^^^^^^^^^^^ DIVISE ^^^^^^^^^^^^  DIVISE ^^^^^^^^^^^^  DIVISE ^^^^^^^^^^^^ 
        
  if ( isPrime== true){
          myPreviousPrime = moonWalker;
          findPrevious=false;
  } //  IF PRIME

}    // FINISH MoonWalk findPrevious
     // cout << "Singer " << int(singer) << " Moon Walked found previousPrime =";
     // cout << int(myPreviousPrime) << endl;
     // cout << endl << "     ********** BUILD perThreadSlicesTHREADArray ************** ";  v
     
// ******************* BEGIN DANCE ************************     
while ( slice  <  perThreadSlices ){
        // vvvvvvvvvvvv DIVISE vvvvvvvvvvvv  DIVISE vvvvvvvvvvvv  DIVISE vvvvvvvvvvvv 
   myTilePlacement=0;
   myThreadTileWalk=0;
//targetTileName = "Tile00";
//myTargetTile = tiles[targetTileName];
    primeBuild = 3 ;   dance = true;
   d3=(myInfiniteWalk/3) +1;
   while (dance == true){ 
      // *** *** PROCESSstart    :  Divisible00
     // process00[0] = epochMicroSeconds();  // Process Start
      if (myInfiniteWalk%primeBuild==0){ 
         //cout << " primeBuild DIVISIBLE by " << int(primeBuild ); //  cout << " myInfiniteWalk " << int( myInfiniteWalk )  << "" << endl;
         isPrime = false;
         dance = false;
         // *** *** PROCESSfinish   :  Divisible00
     //    process00[1] = epochMicroSeconds() - process00[0] ; if ( process00[1]  > process00[2] ){ process00[2]  = process00[1]  ;} ; if ( process00[1]  < process00[3]  ){ process00[3]   = process00[1]   ;}; process00[4]   =  (process00[1]   + process00[4]   ) /2;  ; process00[5]  =   process00[5]   + process00[1] ; process00[6]++;
      }
      else  if( primeBuild > d3 ){
         //cout << " primeBuild " << int(primeBuild ) << " myInfiniteWalk "; // cout << int( myInfiniteWalk )  << "singer " << int(singer) << endl;
         isPrime = true;
         dance = false;
      }  else { // ******** IF PRIME BY RANGE *******                // Librarian Reader Segment Start
         // *** *** PROCESSstart    :  Reader04
     //    process04[0] = epochMicroSeconds();  // Process Start
         if (myThreadBreezeWalk == grid){
            // *** *** PROCESSstart    :  grid02
     //       process02[0] = epochMicroSeconds();  // Process Start

            myThreadBreezeWalk = 0;
            myThreadTileWalk++;
  //          myTilePlacement++;
   //         string128Class tileWalkString(myThreadTileWalk);              // prepare load by name of array
  //          targetTileName = "Tile0" +  tileWalkString.getString();             // create name of primebook
   //          myTargetTile = tiles[targetTileName];

            // *** *** PROCESSfinish   :  grid02
     //       process02[1] = epochMicroSeconds() - process02[0] ; if ( process02[1]  > process02[2] ){ process02[2]  = process02[1]  ;} ; if ( process02[1]  < process02[3]  ){ process02[3]   = process02[1]   ;}; process02[4]   =  (process02[1]   + process02[4]   ) /2;  ; process02[5]  =   process02[5]   + process02[1] ; process02[6]++;
         }
         // *** *** PROCESSstart   :  d3
     //    process03[0] = epochMicroSeconds();  // Process Start03
         return16=myTiles[myThreadTileWalk][myThreadBreezeWalk]*2;
     //    return16 = myTargetTile[myThreadBreezeWalk]*2; 
    //     if (return16b != return16){cout << "     "<<int(return16) <<"        NoDice        "<<int(return16b) <<"     "<< int(dice)<< "       ";  
   //         cout << int(myThreadBreezeWalk) << "  tilePl: "<< int(myTilePlacement) << "  tileWl: " << int(myThreadTileWalk) <<   " It Works: "<< int(itWorks)<< endl;;            string ok; cin >> ok;}
   //      else {itWorks++; }
         
         primeBuild += return16;
         myThreadBreezeWalk++;//         threadBreezeWalk[singer]++; dice++;    // Librarian Reader Segment FINISH
         // *** *** PROCESSfinish   :  d3
     //    process03[1] = epochMicroSeconds() - process03[0] ; if ( process03[1]  > process03[2] ){ process03[2]  = process03[1]  ;} ; if ( process03[1]  < process03[3]  ){ process03[3]   = process03[1]   ;}; process03[4]   =  (process03[1]   + process03[4]   ) /2;  ; process03[5]  =   process03[5]   + process03[1] ; process03[6]++;
         // *** *** PROCESSfinish   :  Reader04
     //    process04[1] = epochMicroSeconds() - process04[0] ; if ( process04[1]  > process04[2] ){ process04[2]  = process04[1]  ;} ; if ( process04[1]  < process04[3]  ){ process04[3]   = process04[1]   ;}; process04[4]   =  (process04[1]   + process04[4]   ) /2;  ; process04[5]  =   process04[5]   + process04[1] ; process04[6]++;
      }            //  cout << " myInfiniteWalk " << int(singer);            //  cout << " " << int(myInfiniteWalk)<<endl;
   }  //cout << " ******** WHILE DANCE = TRUE LOOP ******* " << endl;
      // ^^^^^^^^^^^^ DIVISE ^^^^^^^^^^^^  DIVISE ^^^^^^^^^^^^  DIVISE ^^^^^^^^^^^^ 
   if ( isPrime== true){            // cout << int(slice) << " : singer "<< int(singer);  cout<< "   myInfiniteWalk "<< int( myInfiniteWalk)<< endl;
      // *** *** PROCESSstart    :  IsPrime01
     // process01[0] = epochMicroSeconds();  // Process Start
      primeDifference = ( myInfiniteWalk - myPreviousPrime)/2;  
      myPreviousPrime =  myInfiniteWalk; 
      primeFindsArray[ myPrimeFindsLocal ] = primeDifference; 
      myPrimeFindsLocal++;
      isPrime = false;

      // *** *** PROCESSfinish   :  IsPrime01
     // process01[1] = epochMicroSeconds() - process01[0] ; if ( process01[1]  > process01[2] ){ process01[2]  = process01[1]  ;} ; if ( process01[1]  < process01[3]  ){ process01[3]   = process01[1]   ;}; process01[4]   =  (process01[1]   + process01[4]   ) /2;  ; process01[5]  =   process01[5]   + process01[1] ; process01[6]++;

//      if(myPrimeFindsLocalStep==100 ) {
 //        string128ClassComma  myPrimeFindsLocalString (  myPrimeFindsLocal );  







// =ptv_processLogPrintArm!A1



          
//             myPrimeFindsLocalStep=0;
//          } else { myPrimeFindsLocalStep++;}
} // IS PRIME
 // cout << "singer "<< int(singer)<< "  difference "; //  cout << int(primeDifference) << endl;
myInfiniteWalk+=2;
slice++;
myThreadTileWalk=0;  //myTilePlacement=0;
//targetTileName = "Tile00";

}  // ******** WHILE SLICELOOP *******
   //int128 findRatio =int(int(perThreadSlices/myPrimeFindsLocal));
   //cout << "singer SIGN "<< int(singer)<< "  array =  ";
   // cout << "singer SIGN "<< int(singer)<< "  array =    "<<   int( myPrimeFindsLocal ) << endl;  

findsArray[singer]= myPrimeFindsLocal ;

singerFinished++;




} // LIBRARIAN DANCER FINISH


































































































void theConductor(__int128 singers, bool singleCore, string computeMethod,
                  __int128 perThreadSlices,
                   __int128 mrTsaysReadLibrarian, __int128 primerBase, bool gitState, string uniqueIdGloba)
{
__int128 infiniteWalk = 3;      __int128  etchIndexInfiniteWalkSum =5; 
__int128 totalTiles = 0;   int createTileRequest = 1;
__int128 totalPrimes = 0;  __int128 printWalk=0;
__int128 etchWalk =0; __int128 sliceWalk=0;
__int128 primeRatio =0;
__int128 primeBookLoadMinimum=0;
__int128 threadPrimeFinds =0;
__int128 singer =0;
__int128 pDlarge = 228;
__int128 verifyCount =0;
__int128 tileLay=0;         
__int128 tileWalk=0;  __int128 conductorEtchWalkPrint=0;
__int128 tileWalkData=0;
__int128 thirdTileCount =0;
__int128 conductorCount =1;
__int128 intTail=0;
__int128 singerPrint =0;
  int conductorClockIns =0;
  int conductorClockIn = getCurrentTimeInSeconds();
  int conductorCheckClock =0;
  int conductorLastGitUpdate= conductorClockIn ;
  int conductorUpdateInterval=6000;
  int statusUpdates=0;
  int primerBenchTime =0;
__int128 etchIndexTalleySum=0;  __int128 etchIndexTalley=0;
  bool iUpdate = true;
  bool infinite = true;
  bool unBroken = true;
  string uniqueId = uniqueIdGlobal;
  char choice ;
mrTsaysRead = mrTsaysReadLibrarian;
  __int128 data =0;
  __int128 primeDifference =0;
  byte* targetArray = new byte[ singers  ];
  byte* dancerPrimeFinds = new byte[ singers  ];

  string gitData="";
  string stringBeanTileCount = "";
  string targetTileName = "";
  string userInput="";
  vector<byte*> dancerPrimeFindsArray (  perThreadSlices );  // 88888 INCORPORATE SIZE@PRIMERATIO TO SAVE SPACE IF NEEDED
  vector<byte*> threadWorkingArray (  grid );  // 88888 INCORPORATE SIZE@PRIMERATIO TO SAVE SPACE IF NEEDED
  vector<byte*> conductorPrimeFindsArray (  perThreadSlices );  // 88888 INCORPORATE SIZE@PRIMERATIO TO SAVE SPACE IF NEEDED
 // vector<std::promise<__int128>> promises(singers);
 // vector<std::future<__int128>> futures(singers);
  vector < thread > gitChoir;

  conductorPrimeFindsArray[singer] = new byte[ perThreadSlices ];
__int128 primeBuild =3 ; __int128 primeRange =0;
 bool findPrime = false ; bool isPrime = false;

//=testTimeArm!A1
// ****StartFresh***
if (mrTsaysRead == false){


// ptv_primeBookAuthor    PRIMEBOOK COMMANDER AUTHOR ARM

system("cls");
cout << "How Many Tiles to Create?                         "<< endl;  cin >> createTileRequest;

cout << "   Prime Book To Be Recreated and Build TILES : "<< int(createTileRequest)<<endl;  


__int128 readTileCount = listBookZip() +1;
__int128 myInfiniteWalk = 0 ;
__int128 nextPrime=0;

archivePrimeBook(readTileCount,uniqueId);
cout << "   Prime Book Archived  : ";



system("echo off &&  copy primeBookOne\\PrimeBookOneEmpty.tar primeBookOne\\PrimeBookOne.tar /Y");
    cout << "   Prime Book Recreation inPROGRESS Single Thread : Now Building Grid@ "<< endl ;
    cout << "tiles[primebuild]  TILES : "<< int(createTileRequest) << "     "<< endl;  



previousPrime = 3;
 printWalk=0;
infiniteWalk = previousPrime;



while ( gearCreatedTiles  <  createTileRequest ){
  //   cout << int(total)<< "   Total Before primeDivise  " << endl;

   infiniteWalk+=2;




if (verifyPrime(infiniteWalk)){

  primeDifference = (infiniteWalk - previousPrime)/2;
  previousPrime=infiniteWalk;
total++; data= primeDifference;

// ptv_etchTileARM data => in    


//if(etchWalk%10000==0){
//cout << "EtchTile : " << int(data) << "  EtchWalk : " << int(etchWalk)<< endl;}
//cin >> userInput;

 byte* targetTile;


  string128Class tileCountString ( tileCount );    
  targetTileName = "Tile0" + tileCountString.getString();
     targetTile = tiles[ targetTileName ];
     targetTile[etchWalk] = data;
     etchWalkSum+=data;  // ADD ONTO TILE SUM
  etchWalk++;
  if (etchWalk == grid) {
guiGrid128[2][11] = etchWalkSum;
previousEtchWalkSum =  previousEtchWalkSum;   // PREVIOUS TILESUM
gearCreatedTiles++;  guiGrid128[2][9]=gearCreatedTiles; // primebooksCreated talley

guiGrid128[2][12] = previousEtchWalkSum; // cout << "previousEtchWalkSum : 
bookIndexTotals[tileCount]= etchWalkSum;        
  primeRatio =infiniteWalk/total;
 exportTile( targetTileName );// cout << "export Tile" << endl;

  etchWalkSum=0; // BEGIN NEW TILE SUM
     tileCount++;    
etchWalk = 0;

    string128Class tileCountString ( tileCount );
    targetTileName = "Tile0" + tileCountString.getString() ;
    byte* newTile = new byte[grid]();
    tiles[targetTileName] = newTile;

    targetTile = tiles[ targetTileName ];


    targetTile[0] = 0;
  }








































































































//   etchTile(primeDifference);
if (printWalk > 10000){ printWalk=0;
       cout << int(infiniteWalk) << "   infiniteWalk    ";         cout << int(primeDifference) << "   primeDifference " ;            cout << int(total)<< "   Total " << int(primeRatio) << " Prime Ratio " <<endl;  
}
printWalk++;



}
   isPrime = false;

} // FINISH REQUESTED TILE CREATION
primeRatio =infiniteWalk/total;

cout << endl << "Prime Books at Grid Created Tiles : "<< int(gearCreatedTiles)<<endl;
cout << endl << "Ready to Reboot?";

string exitString= "Authored Tiles = " + int(gearCreatedTiles);

logExit(exitString);
system("start /b PrimeOneReboot.bat");
exit(0); // reboot


// finish primebook author commander arm



















}
//if (mrTsaysRead == true){
// *****MrTSaysRead ptv_primeBookCommander ******foo***


// ******MrTSaysRead******foo***
guiDefaultsSet();

   guiGrid128[0][16] = primeRatio;     guiGrid128[0][16] = primeRatio;   guiGrid[2][8][1] = totalTiles;  guiGrid128[0][19] = pDlarge;    guiGrid128[0][20] = infiniteWalk;   guiGrid128[0][21] =total; guiGrid128[2][18] = singers;
 gui128String(); guiPrime();  system("cls"); gui(); 
   __int128 readTileCount = listBookZip() +1;
  guiGrid128[2][8] = readTileCount;
bool verifyTiles=false;
   bool rebuildIndex = false;
   bool reCreateIndex = false;
//   __int128 indexFileTileCount = countTextLines("primebookindex.txt") + 1;
   __int128* fileBookIndex = new __int128[500000];
string createTileName="";
  //  archivePrimeBook(readTileCount,uniqueId);  
__int128 etchRunner=0;

    string128Class totalString(total); 
//  tileCount = readTileCount;
__int128 createTiles=0;














//tileLay=1;

//        minimumPrimeBookNeeded = findMinimumPrimeBook(readTileCount,bookIndex);
__int128 walkInfiniteTile =0;

     minimumPrimeBookNeeded = readTileCount;

        //     infiniteWalk=bookIndex[readTileCount-1]; // read the largest known prime 
        //   etchIndexInfiniteWalkSum=infiniteWalk;       infiniteWalk+=2;      // Walk 2 into the unknown

         //string128Class infiniteWalkString(infiniteWalk);  string128Class tileCountString(tileCount);

         //string128Class highestPrimeM1(  bookIndex[readTileCount-1]  );











bool verifiedPrimeBook=false;
bool readLastBatch = false;

__int128 assignedBook=0;
__int128 totalCores = singers;
__int128 availableCores = totalCores ; //. totalCores-1



__int128 batchCount =0;
__int128 createTileReadThread =0;


  vector < thread > bookClub;
__int128 threadReadTotal=0;











// ****** BEGIN BATCH READ LOOP *********
__int128 rejoinThreadWalk=0;


  __int128 gridWalk=0;


__int128 batchWalk = 0;
__int128 theBatchWalk = minimumPrimeBookNeeded;
__int128 partialBatchTotal =0;
      byte* threadTile = new byte[ grid ];







while ( readLastBatch == false){

   if (theBatchWalk > availableCores){
      batchWalk = availableCores;

   } else {
     batchWalk = theBatchWalk;
     readLastBatch=true;

   }





    bookClub.clear();
   for (__int128 batchWalker = 0; batchWalker < batchWalk; batchWalker++) {      //   cout << "create singer "<<int(singer)<< endl;




      threadWorkingArray[batchWalker] = new byte[ grid ];




      bookClub.push_back(thread([this,
                            batchWalker,
                              assignedBook,
                                uniqueId,

                                    &workingArray  = threadWorkingArray[batchWalker]
                                      ]() {
                            this->threadRetrieveTile(batchWalker,
                              assignedBook,
                                uniqueId,

                                   workingArray
                                      );}));







     theBatchWalk--; 
      assignedBook++;


   }           // FINISH CREATE ALL THREADS
   






   for (auto& readTileReadThread : bookClub) {



         readTileReadThread.join(); 
   }                                  // Finish Join All Threads

   bookClub.front();

for (__int128 batchWalkerReader = 0; batchWalkerReader < batchWalk; batchWalkerReader++) {

     byte* targetTile;

//      targetTile = threadWorkingArray[batchWalkerReader];

      string128Class tileNumberString ( tileLay );
      string targetTileName = "Tile0" + tileNumberString.getString();
   //  cout << "Begin read batchWalker tile : " << int(batchWalkerReader) << " targetTileName = " << targetTileName << endl;
targetTile=  threadWorkingArray[batchWalkerReader]; //  tiles[targetTileName] = new byte[grid];
//cout << "             create tile " << targetTileName << "   "  << endl;

// tiles[targetTileName] = targetTile;       tileLay++;
etchRunner=0;
while (etchRunner < grid){ data = targetTile[etchRunner++];

// ptv_etchTileARM data => in    


//if(etchWalk%10000==0){
//cout << "EtchTile : " << int(data) << "  EtchWalk : " << int(etchWalk)<< endl;}
//cin >> userInput;

 byte* targetTile;


  string128Class tileCountString ( tileCount );    
  targetTileName = "Tile0" + tileCountString.getString();
     targetTile = tiles[ targetTileName ];
     targetTile[etchWalk] = data;
     etchWalkSum+=data;  // ADD ONTO TILE SUM
  etchWalk++;
  if (etchWalk == grid) {
guiGrid128[2][11] = etchWalkSum;
previousEtchWalkSum =  previousEtchWalkSum;   // PREVIOUS TILESUM
gearCreatedTiles++;  guiGrid128[2][9]=gearCreatedTiles; // primebooksCreated talley

guiGrid128[2][12] = previousEtchWalkSum; // cout << "previousEtchWalkSum : 
bookIndexTotals[tileCount]= etchWalkSum;        
  primeRatio =infiniteWalk/total;
// exportTile( targetTileName );// cout << "export Tile" << endl;

  etchWalkSum=0; // BEGIN NEW TILE SUM
     tileCount++;    
etchWalk = 0;

    string128Class tileCountString ( tileCount );
    targetTileName = "Tile0" + tileCountString.getString() ;
    byte* newTile = new byte[grid]();
    tiles[targetTileName] = newTile;

    targetTile = tiles[ targetTileName ];


    targetTile[0] = 0;
  }








































































































}

   }           // FINISH READ ALL THREADS 

} // WHILE readLastBatch != True    //*******************FINISH  BATCH READ LOOP ********* *********************



















        total = (grid*(readTileCount)); 

 //***FINISH  mrTsaysRead  LOOP ******

//cout << " Finished Build MyTIles"; cin >> userInput;












//}


// ptv_walkIndexARM       

__int128 indexWalk =0;
__int128 previousBookIndex =3; 
while (indexWalk < readTileCount){

bookIndex[indexWalk]= (bookIndexTotals[indexWalk]*2) + previousBookIndex;
   previousBookIndex = bookIndex[indexWalk];
   bookIndexTotalsDif[indexWalk] = (bookIndexTotals[indexWalk]*2) - (bookIndexTotals[indexWalk+1]*2);
      string128Class bookIndexString(bookIndex[indexWalk]);
      string128Class bookIndexTotalsString(bookIndexTotals[indexWalk]*2);
      string128Class bookIndexTotalsDifString(bookIndexTotalsDif[indexWalk]);
      string128Class indexWalkString(indexWalk);
cout << "BookWalk : "<< indexWalkString.getString();
cout << " Index : " << bookIndexString.getString();
cout << " Totals : " << bookIndexTotalsString.getString();
cout << " TotalsDif : " << bookIndexTotalsDifString.getString()<< "        "<<endl;
   indexWalk++;
}
cout <<  int(bookIndex[readTileCount-2] ) << "   " <<   int(bookIndex[readTileCount-1] ) << "   " <<   int(bookIndex[readTileCount] ) << "   " << endl;































































































cout <<  int(bookIndex[readTileCount-2] ) << "   " <<   int(bookIndex[readTileCount-1] ) << "   " <<   int(bookIndex[readTileCount] ) << "   " << endl;
infiniteWalk = bookIndex[readTileCount-1];
string128Class infiniteWalkString(infiniteWalk);
previousPrime =infiniteWalk;
cout << endl<< "           InfiniteWalk = "<<  infiniteWalkString.getString() << "   TileCount : "<< int(tileCount) << endl;
for (int i = countdown_seconds; i >= 1; --i) {cout << i << " "; this_thread::sleep_for(std::chrono::seconds(1));}



// COMMANDER verifyTile Arm
//gui();
// =ptv_walkTileArm!A1

int gWalk =0;
int moonWalk =1;
int center = 10;
int depth  = 8;


string guiGridString ="";
string title = "";
string indexString="";


__int128 loadedTileDif=0; 
__int128 tileSetup = 0;
__int128 previousPrimeWalk = 0;
__int128  nextPrime =0;
__int128 nextPrimeWalk=0;
__int128 targetTileDif =0;
__int128 previousTile = totalTiles--;
__int128 expectedTileDif =0;
__int128 primeMoonWalk = bookIndex[tileSetup];
__int128 walkTheMoon=0;
__int128 previousPrimeMoonWalk = bookIndex[tileSetup];
__int128 primeGridWalk = 3;
__int128 primetileSetupBase=3;
__int128 primetileSetupBaseNext=3;
__int128 previousPrimeGridWalk = 0;
__int128 expectedPrimetileSetup=0;
__int128 primetileSetup = primetileSetupBase;
__int128 primeMoonWalkNext =0;

byte* targetTile = new byte[grid];
//cout << endl<< "                              Begin VERIFY TILE?"; realm_os_user_input( userInput); 

while(tileSetup<readTileCount){

   string128Class infinitePrimeIndexString(bookIndex[tileSetup-1] );
   string128Class infinitePrimeIndexTotalString(  bookIndexTotals[tileSetup] );

   indexString = "";

   primetileSetupBaseNext =(primetileSetupBase)+ ( bookIndexTotals[tileSetup])*2 ;

   string128Class primetileSetupBaseNextString(primetileSetupBaseNext);

   string128Class tileNumberString ( tileSetup );
   targetTileName = "Tile0" + tileNumberString.getString();
   
   targetTile = tiles[targetTileName] ;


   // NAME TITLE
   string128Class primetileSetupBaseString ( primetileSetupBase );
   title  = "";
   title += "Grid Tile0";
   title += tileNumberString.getString();
   title += " infinitePrimeWalk ' Verify";
   
   guiGrid[1][center][1] = title;

   // INDEX TITLE
   indexString  = "";
   indexString += primetileSetupBaseString.getString(); 
   indexString += "  ";
   indexString += infinitePrimeIndexTotalString.getString();
   indexString += "  ";
   indexString += primetileSetupBaseNextString.getString();

   if(verifyPrime(primetileSetupBaseNext)==true){ indexString += " P "; } else {indexString += " X ";}
   
   guiGrid[1][center+1][1] = indexString;

   walkTheMoon= primetileSetupBaseNext;
   primeMoonWalk= primetileSetupBaseNext;
   moonWalk=1;

   while (moonWalk < (depth+1)){
      targetTileDif = targetTile[grid -moonWalk];

      primeMoonWalkNext = moonWalkPrime(primeMoonWalk);
      expectedTileDif =  (primeMoonWalk -primeMoonWalkNext )/2;

      string128Class targetTileDifString(targetTileDif);
      string128Class expectedTileDifString(expectedTileDif);
      string128Class walkTheMoonString(walkTheMoon);
      string128Class moonWalkString(moonWalk);
      string128Class primeMoonWalkString(primeMoonWalk);

      guiGridString += "-";
      guiGridString += moonWalkString.getString();
      guiGridString += " "  ;
      guiGridString += targetTileDifString.getString();
      guiGridString += " "  ;
      guiGridString += walkTheMoonString.getString();

     if(verifyPrime(walkTheMoon)==true){ guiGridString += " P "  ;} else { guiGridString += " X "  ; } 

      guiGridString += " ' "  ;
      guiGridString += expectedTileDifString.getString();
      
      guiGridString += " "  ;
      guiGridString += primeMoonWalkString.getString();
 
     if(verifyPrime(primeMoonWalk)==true){ guiGridString += " P "  ; } else { guiGridString += " X "  ; }
     
     if (walkTheMoon != primeMoonWalk){  
     // system("cls");
     cout << "     !!!! Prime Math not Matching  ";
     cout << "     !!!!  " << int(walkTheMoon) << " != Not Equal != " << int(primeMoonWalk) << "  !!!!  " ;
cin >> userInput;
       for (int i = countdown_seconds; i >= 1; --i) {cout << i << " ";this_thread::sleep_for(chrono::seconds(1)); }
    
       __int128 mathDifference = walkTheMoon - primeMoonWalk;
       string128Class mathDifferenceString(mathDifference); 
       string mathError = "Prime Math Error Difference of : " + mathDifferenceString.getString();
       // logExit(mathError);    system("start /b PrimeOneReboot.bat");    exit(0);
     }
     
      guiGrid[1][center-moonWalk][1] = guiGridString;
      guiGridString="";
      primeMoonWalk = primeMoonWalkNext;
      walkTheMoon= walkTheMoon-(targetTileDif*2);
      moonWalk++;
   }  // FINISH moonWALK
   gWalk=0;
   while (gWalk < (depth+1)){
      targetTileDif = targetTile[gWalk];
      primetileSetup += targetTileDif*2;
      previousPrimeGridWalk = primeGridWalk;
      primeGridWalk = nextWalkPrime(previousPrimeGridWalk);
      expectedTileDif = (primeGridWalk -previousPrimeGridWalk)/2 ;
   string128Class expectedTileDifString(expectedTileDif);
   string128Class targetTileDifString(targetTileDif);
   string128Class primetileSetupString(primetileSetup);
   string128Class expectedPrimetileSetupString(primeGridWalk);
   string128Class gWalkString(gWalk);

   
      guiGridString += "+";
      guiGridString += gWalkString.getString();

      guiGridString += " "  ;
      guiGridString += targetTileDifString.getString();
      guiGridString += " "  ;
      guiGridString += primetileSetupString.getString();

    if(verifyPrime(primetileSetup)==true){ guiGridString += " P "  ;  } else { guiGridString += " X "  ;}

      guiGridString += " ' "  ;
      guiGridString += expectedTileDifString.getString();
      guiGridString += " "  ;
      guiGridString += expectedPrimetileSetupString.getString();

    if(verifyPrime(expectedPrimetileSetup)==false){ guiGridString += " P "  ; } else { guiGridString += " X "  ; }
    
      guiGrid[1][center+gWalk+2][1] = guiGridString;

      guiGridString="";
      
      gWalk++;
      
      
}  // FINISH gWALK

   primetileSetupBase = bookIndex[tileSetup];
   primeGridWalk = bookIndex[tileSetup];

   primetileSetup = bookIndex[tileSetup];

   primeMoonWalk = bookIndex[tileSetup];

   tileSetup++;
   gui();
  //  for (int i = countdown_seconds; i >= 1; --i) {
  //      std::cout << i << " ";
  //      std::this_thread::sleep_for(std::chrono::seconds(1));

  //  }



} // finish tileSetup

// not a function but a commander insert} // FINISH VERIFY TILE
































































































































archivePrimeBook(readTileCount,uniqueId);






   guiGrid128[2][16] = perThreadSlices;

// XXX BEGIN Infinite Count  XXX
while ( infinite == true){
   guiGrid128[2][21] = ++infiniteCycleStarts;
   guiGrid128[0][16] = primeRatio;     guiGrid128[0][16] = primeRatio;   guiGrid[2][8][1] = totalTiles;  guiGrid128[0][19] = pDlarge;    guiGrid128[0][20] = infiniteWalk;   guiGrid128[0][21] =total; guiGrid128[2][18] = singers;
   gui128String(); guiPrime();  system("cls"); gui(); 




// ptv_gitUpdateArm                   

   conductorCheckClock = getCurrentTimeInSeconds();
if (gitState==true){
// **** BEGIN iUPDATE ****
   if (iUpdate == true && (conductorCheckClock - conductorLastGitUpdate ) > conductorUpdateInterval){
      totalTiles = tileCount; totalPrimes = total;
      conductorLastGitUpdate = getCurrentTimeInSeconds();
      statusUpdates++;      //  unbroken("Continue to Create Threads? (press any key then enter to continue");

      gitChoir.push_back(thread([this,
                            gitData, primeRatio,  pDlarge, infiniteWalk,    conductorCount, totalTiles, totalPrimes
                                      ]() {
                            this->conduit_git(gitData, primeRatio,  pDlarge, infiniteWalk,    conductorCount, totalTiles, totalPrimes
                                      );}));
   }  // FINISHSH  if (iUpdate == true && 
// ****FINISH iUPDATE **
}


































































































/*
if(createHostCommand==true && createGuests==true){

}

if(createHostCommand==true){  cout << "Host";
} else { cout << "Guest";}
//cin >> userInput;
*/








//                         =ptv_primeBookAuthorGear!A1










 guiGrid128[2][22] = ++infiniteCycleFinishes;
} // WHILE INFINITE = TRUE
// XXXXX FINISH Infinite Count  XXX

}  //FINISH theCONDUCTOR FUNCTION
























































































































































public: // **************** PUBLIC *******************



primeTileClass(__int128 powerOfIN,
               __int128 perThreadSlicesIN,
               __int128 singersIN, 
               __int128 primeBasePrimerIN ,
               __int128* primeIndexIN,
               __int128 indexTilesIN,
               __int128 primeIndexRoofIN
) : powerOf(powerOfIN),
               perThreadSlices(perThreadSlicesIN),
               singers(singersIN),
               primeBasePrimer(primeBasePrimerIN),
               primeIndex(primeIndexIN),
               indexTiles(indexTilesIN),
               primeIndexRoof(primeIndexRoofIN)
{
// cout << " Initiate prime tile class " << endl; //    cout << " 111111 " << endl;
    cout << "\033[1;1H"; 
 // system("tar -cvjf PrimeBookOne\\PrimeBookOne.zip PrimeBookOne\\PrimeBookOneIndex.txt");

  __int128 singersPlus = 0;


                        // **************** // ****************

                        
                       // infiniteWalk = 5 ;
    //                    powerOf = 24 ; // = powerOf ; 24 = 16meg 25 = 32 26 = 64 27 =128 28 =256meg uncompressed tile file
                        singersPlus = singers ;
                        grid = pow(2,powerOf);


                        // **************** // ****************
                        
                        
  string128ClassComma stringBeanGrid ( grid );
  gridString = stringBeanGrid.getString(); 

string128ClassComma singersPlusString( singersPlus );
string128ClassComma perThreadSlicesString( perThreadSlices);
string128ClassComma primeBasePrimerString( primeBasePrimer);
// string128ClassComma infiniteWalkString( infiniteWalk );
string128ClassComma powerOfString( powerOf);
string userInput=""; 
 // cout << "  PerThreadSlices Song Count " << perThreadSlicesString.getString()  << endl;
//  cout << "  SingersPlus " << singersPlusString.getString()<< endl;
 // cout << "  Tile Grid Width : " << gridString;
 // cout << " @ 2 to the Power of " << powerOfString.getString() << endl;
 // cout << "  PrimeBasePrimer " << primeBasePrimerString.getString() << endl;
//  cout << "  infiniteWalk Start " << infiniteWalkString.getString() << endl;
singerFinished=0;
 // cout << " 55555 " << endl;
  testTile(); 
//cout << " 66666 " << endl;
  initiateTile(0);
  tileLoaded      = new bool[ 76767676 ]; 
  threadTotal      = new __int128[ singersPlus ]; 
  threadTileWalk   = new __int128[ singersPlus ]; 
  threadSlateWalk  = new __int128[ singersPlus ]; 
  threadBreezeWalk = new __int128[ singersPlus ]; 
  myTileCount      = new __int128[ singersPlus ]; 
  myEtchWalk       = new __int128[ singersPlus ]; 
findsArray = new __int128[ singersPlus ]; 
__int128 tileLay =0; //cout << " 8888888 " << endl;
liveIndex = new __int128[ 76767676 ]; 
   // string128Class  indexRoofString(  primeIndex[indexTiles-1]  );  cout << " bbbbbbbb " << endl; cout << "  PrimeBook Index Initiate Roof "<< " : "  <<  indexRoofString.getString()  << " Tiles : " << int(indexTiles) << endl;   
tileTotalsArray = new __int128[singers];
  while ( tileLay < indexTiles){  //cout << " 999999 " << endl;
//    string128Class  indexRoofString2(  primeIndex[tileLay]  );  cout << "  PrimeBook Index Initiate Base "<< " : "  <<  indexRoofString2.getString()  << " Tiles : " << int(indexTiles) << endl;  
//cout << " aaaaaaaa " << endl;
 //    string128Class numObj1(  primeIndex[tileLay]  );
  //   cout << int(tileLay) << " : TileClass : "  <<  numObj1.getString()  << endl; 
     tileLay++;
  }  
 //   string128Class  indexRoofString2(  primeIndex[tileLay]  );  // cout << "  PrimeBook Ini "<< endl;  // realm_os_user_input(userInput);

indexArray = primeIndex;
guiGrid128[2][8] = 0;
guiGrid128[2][9] = previousEtchWalkSum;

guiGrid128[2][10] = 0;
guiGrid128[2][11] = 0;
guiGrid128[2][13] = 0;
guiGrid128[2][14] = 0;
guiGrid128[2][15] = 0;
guiGrid128[2][20] =grid;  guiGrid128[2][19] =powerOf; 

    const int arrayGrid = static_cast<int>(std::pow(2, 20)); // Convert to int for array size
    byte** myTiles = new uint8_t*[800]; // Allocate rows       // Dynamically allocate a 2D array
    for (int i = 0; i < 800; ++i) {   myTiles[i] = new uint8_t[arrayGrid];} // Allocate columns for each row

bookIndex = new __int128[ 50000 ];  
bookIndexTotals = new __int128[ 50000 ]; 
bookIndexTotalsDif = new __int128[ 50000 ]; 
indexFileTileCount= 50000;
processData = new __int128[10];


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
 byte* etchTileArray = new byte[grid];


// conductor primeTileClassInit

 infiniteWalk = 3; 
 pDlarge = 228;
 conductorCount =1;
   conductorLastGitUpdate= conductorClockIn ;
   createTileRequest = 1;
   conductorUpdateInterval=6000;
  targetArray = new byte[ singers  ];
  dancerPrimeFinds = new byte[ singers  ];
uniqueId = uniqueIdGlobal;

privateLeapsLap =singers; 
privateLeapsLapDouble =privateLeapsLap*2; 
privateWolfLeap = new __int128[privateLeapsLapDouble];
privateQueCount=0;
privateWolfFeast = new vector<byte>[privateLeapsLapDouble];
 collectionPlateFirst=0;   collectionPlateSecond=0;
privateWolfLeapAssingment = new string[privateLeapsLapDouble];
privateWolfPrimeQueAssingment = new int[privateLeapsLapDouble];

privatePrimeQue =0;  byte* privatePrimeNetCatch =new byte[privateLeapsLapDouble];
ptv_quiltInit(privateLeapsLapDouble);
}  // PRIMETILECLASS










































































































































































void carve (__int128 singers) { carveSlate( singers );}
void scribe(__int128 singer, byte data){scribeSlate( singer, data);}
void scrub () { scrubSlate();}
void read () { readSlate();}
void conductor(__int128 singers,  bool singleCore, string computeMethod, __int128 perThreadSlices,  __int128 mrTsaysRead,__int128 primerBase, bool gitState,string uniqueIdGlobal ) { theConductor(singers,   singleCore,  computeMethod, perThreadSlices,  mrTsaysRead, primerBase, gitState,uniqueIdGlobal); }
//void buildPrimeBase(__int128 singers, __int128 perThreadSlices,  __int128 mrTsaysRead,__int128 primerBase) { primeBase(singers,  perThreadSlices,  mrTsaysRead, primerBase);}
string hostPrimeBookLeap(int wolfHunger, string wolfId){ return ptv_hostPrimeBookLeap(wolfHunger, wolfId);}
vector<byte> primeBookAuthor(__int128 wolfLeap, int wolfHunger, int privateGuestAssignedQue, int privatePrimeQue) { return ptv_primeBookAuthor(wolfLeap, wolfHunger, privateGuestAssignedQue, privatePrimeQue);}
void cleanUpTiles(){ for (auto& pair : tiles) { delete[] pair.second;} }
__int128 getInfiniteWalk(){return infiniteWalk;}
//__int128* rebuildBookIndex(__int128 bookIndexSize) { return rebuildIndex(); }
void quiltInfiniteWalk(__int128 quiltWeave){ infiniteWalk=quiltWeave;}
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

string getCurrentTimeInSecondsString() {
    auto currentTime = std::chrono::system_clock::now();
    auto secondsSinceEpoch = std::chrono::duration_cast<std::chrono::seconds>(currentTime.time_since_epoch());
    int returnInt =  static_cast<int>(secondsSinceEpoch.count());
    string128Class timeInSeconds( returnInt );
 return timeInSeconds.getString();
}

void COMMANDER(){ptv_COMMANDER();}

int getPrimeQue(){ privateQueCount++;
if (privatePrimeQue<((singers-1)*4)){return privatePrimeQue++;}
else{ privatePrimeQue=0; return privatePrimeQue++;}
}
__int128 getTotalCount(){return total;}
__int128 getTileCount(){ return tileCount;}
void gearFeast(int privatePrimeQue, byte  privatePrimeByte) {ptv_gearFeast( privatePrimeQue, privatePrimeByte);}
void etchFeast(byte data) { etchTile(data);total++;}
int getPrivateQueCount(){return privateQueCount;}

int remainingEtchWalk() {int remaining = (grid - etchWalk); return remaining;}



























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
string realm_wolfpack_id(string randomString3);
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
 void realm_sw_variable_primer (__int128 perThreadSlices, bool mrTsaysRead, __int128 singers,      __int128 primerBase, __int128 powerOf, bool gitState, string uniqueIdGlobal, bool createHost,    __int128 weaverBeginData, string hostIp, int hostPort,  bool singleCore, string computeMethod);
double realm_metalUpTime();
void realm_sw_divisor_dancer(__int128 singer, __int128 singersDigitSize, primeTileClass PrimeOne );
void menu_gyrogear( __int128 primeRatio, __int128 totalTiles, __int128 pDlarge, __int128 infiniteWalk, __int128 totalPrimes );
void menu_book( __int128 slices , __int128 primer , __int128 singers , __int128 powerOf ) ;
void realm_os_user_input(string&validUserInput);
void menu_librarian();
void librarian_functions( string hostIp, int hostPort, int optionCores, string optionMenue, string optionFlag, string optionCompute,  bool singleCore, string computeMethod, bool createHost );
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
string realm_metalGUID();
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
string realm_metalIdNum();
int getCurrentTimeInSecondsInt();
tuple<int,string,string,__int128,int,int> realm_conduit_win_guest(string returnGuestStatusIn, string uniqueId, int conduit, int myPort, string myIP, int remotePort, string remoteIP, string instruction, string randomString1, string randomString2, string randomString3, vector<byte> primeCatch, int returnPrimeQue );

bool countdown(int seconds) ;
void wait_for_input() ;








































































































































































































































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

double metalUpTime =0;
string metalGUID = "";
string metalIdNum = "";

string privateGuestStatus="";

string privatePrimeClientUserName;

string tempDir="";

__int128 privateInfiniteWalk;

__int128 privateWolfLeap;
int privateWolfHunger;
int privateWolfPrimeQue;

bool privateGuestAssigned;
int privateGuestAssignment;
int privateGuestHunger;
__int128 sortCatch;
string privateHostStatus;
int privateGuestAssignedQue;
__int128 privateGuestAssignedWork;
int privateGuestAssignedHunger;
string privateGuestAssignedId;


__int128 privatePrimeCatchSize;
int privatePrimeQue;
vector<vector<byte>> vectorCaches;
int vectorArrays;
int vectorIndex;
int* vectorCollection;
__int128 hostCollectedArrays;
__int128 privateTileCount;
__int128 privateTotalCount;
bool assignmentCollected;
bool* assignmentsCollected;    bool* currentQueueComplete;
__int128 private1stCollects;  

int privateQueCountConduit;
bool privateReAssign;




    std::vector<std::chrono::steady_clock::time_point> queueStartTimes{vectorArrays}; // Track when each queue was assigned work
    int currentQueue = 0;
    bool firstCycleComplete = false;

    std::chrono::milliseconds averageCompletionTime{15000}; // Example: 5 seconds per work unit
    int privateReassignedQue = -1;    __int128 privateReassignedWork = 0;


__int128* privateWorkAssignment;
int* privateWorkAssignmentHunger;
//    std::chrono::milliseconds::rep elapsedAverage = 0;
int      privateNextBatch;
int collectNextQue;
bool collect;
int privateReAssigns;
int privateRemainingEtchWalk;
int missedCollection;
bool nothingEtched;
int quarterVectorArrays;
string* guestConduitNames;
bool* guestConduitVerify;





















































































































































































































 void conduit_win_hosts( __int128 weaverDataHost, string uniqueId, string randomString1, string randomString2, string randomString3, bool firstPassTorch, bool passTorch, int weavePort )
{
 int conduits = 1;
 int conduit = 0;
string instruction; int assignedPort = weavePort; string assignedIP; int remotePort; string remoteIP;
int hostConduits = conduits;
int guestConduits = conduits;
int conduitCount =0;










//vector< thread > choir;


//  choir.clear();

//cout << "  for (conduit = 0; conduit < hostConduits; conduit++) {" << endl;
//  for ( int conduit  = 0; conduit < conduits; conduit++) {
// cout << "create conduit "<<int(conduit)<< " of total created: " << ++conduitCount << endl;

conduit_win_host(
uniqueId, conduit, assignedPort,  assignedIP,  remotePort,  remoteIP, instruction, randomString1,
randomString2, randomString3, firstPassTorch, passTorch);




/*
 choir.push_back(thread([this,
uniqueId, conduit, assignedPort,  assignedIP,  remotePort,  remoteIP, instruction, randomString1,
randomString2, randomString3, firstPassTorch, passTorch



                                      ]() {
                            this->conduit_win_host(
uniqueId, conduit, assignedPort,  assignedIP,  remotePort,  remoteIP, instruction, randomString1,
randomString2, randomString3, firstPassTorch, passTorch


                                      );}));
//  }



//cout << " created threads = " << int(conduits) << endl;
  for (auto& t : choir) {
   t.join();
 }

  choir.front();
*/
} //END FUNCTION












void conduit_win_guests( __int128 weaverDataGear, string uniqueId, string randomString1, string randomString2, string randomString3, bool& weaveHost, int&weavePort, int& returnData, int&weavePortHost, int&weaveNewPort, vector<byte> primeCatch )
{
bool infinite = true;
int conduits = 1;
string instruction; int assignedPort; string assignedIP; int remotePort; string remoteIP;
int hostConduits = conduits;
int guestConduits = conduits;
string userInput ="";
string returnGuestStatus="";
__int128 wolfLeap =0;  __int128 returnWork=0; int returnPrimeQue =0;
int gatherData =0;  int gatherTupleData =0;
string returnDataString ="";
int wolfHunger = 0; int returnHunger=0;
    const int numThreads = 1000;
    int dataReturnArray[numThreads];

vector< thread > choir;
vector<promise<tuple<int, string,string,__int128,int,int>>> promises(conduits);
vector<future<tuple<int, string,string,__int128,int,int>>> futures;


 // choir.clear();
 //promises.clear();
//cout << "  for (conduit = 0; conduit < hostConduits; conduit++) {" << endl;





// conduit_guestChoirArm       
// Create promises and futures **before** launching threads
for (int conduit = 0; conduit < conduits; conduit++) {

remotePort = weavePort;

    promises[conduit] = promise<tuple<int, string,string,__int128,int,int>>(); // Initialize promise
    futures.push_back(promises[conduit].get_future()); // Get future **before thread**
    
    choir.push_back(thread([conduit](string privateGuestStatus, string uniqueId, int conduit, int assignedPort,  
                                     string assignedIP, int remotePort, string remoteIP, string instruction,  
                                     string randomString1, string randomString2, string randomString3, vector<byte> primeCatch, int privateWolfPrimeQue,
                                     promise<tuple<int, string,string,__int128,int,int>>& p) {
        p.set_value(realm_conduit_win_guest(privateGuestStatus, uniqueId, conduit, assignedPort,  
                                            assignedIP, remotePort, remoteIP, instruction,  
                                            randomString1, randomString2, randomString3, primeCatch, privateWolfPrimeQue));  
    }, privateGuestStatus, uniqueId, conduit, assignedPort, assignedIP, remotePort,  
       remoteIP, instruction, randomString1, randomString2, randomString3, primeCatch, privateWolfPrimeQue, ref(promises[conduit])));
}





































































































































































































































































































































for (int i = 0; i < conduits; ++i) {
    auto [gatherTupleData, returnDataString, returnGuestStatus, returnWork, returnHunger, returnPrimeQue] = futures[i].get(); // Retrieve and unpack tuple
//    cout << "Conduit " << i << " - Int Result: " << gatherTupleData 
//         << ", String Result: " << returnDataString << endl;
gatherData = gatherTupleData;
privateGuestStatus = returnGuestStatus;
privateWolfLeap= returnWork;
privateWolfHunger = returnHunger;
privateWolfPrimeQue = returnPrimeQue;  privateGuestAssignedQue = returnPrimeQue;
    choir[i].join();}
if(gatherData == 1){ 
//cout << "Returned to Become Host" << endl;  cin >> userInput;
//realm_os_user_input(userInput); 
weavePortHost = globalNewPort[0];   weaveHost = true;

}

if(gatherData == 2){ 
//cout << "Returned to Connect to New Host: " << int(weavePort) << endl;  cin >> userInput;

weavePort=globalNewPort[0];
// weaveip=
}
 // choir.front(); promises.front();






 } // END FUNCTION

































































































































































































































void conduit_win_host( string uniqueId, int conduit, int myPort, string myIP, int remotePort, string remoteIP, string instruction, string randomString1, string randomString2, string randomString4, bool firstPassTorch, bool passTorch )
{
bool searchComplete = false;    int guestCurrentTime =0; int guestFreshness=0; int currentTime =0; int freshness =0; int staleTime=0;
 string guestName = "";  bool updateGear = false;  bool updateBook =false ; 
bool isHost = true; bool infiniteWalkGuest = false; string guestIp = "127.000.000.001" ; string guestPort = "55555"; string hostIp= "127.000.000.001"; string hostPort = "55555"; string uniqueFileName ="";
 string text_post = ""; int tileCount =0;   string guestStatus="";
  string userInput; int remotePortInt=0;
bool yesContinue=true; string guestIPstring="";
 bool socketSearch=true;
  int PORTgrow = myPort;
   bool sendForever=true;
    int ARRAY_SIZE = 99999;  // cout << " ARRAY_SIZE " <<  ARRAY_SIZE << endl;
bool receiveForever=true;
 int dataSend=0;   string assignedWolfLeapString="";  string assignedWolfHungerString ="";  string guestHungerString="";
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
 string tempDir =  "PrimeBookOne\\archive\\"+uniqueId+"\\";
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
/*H*/      timeout.tv_sec = 18;  // 5 seconds timeout
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

/*H*/       //   std::cout << "Guest IP: " << guestIP << ":" << service;
guestIPstring = guestIP;
/*H*/       //   cout << "   Peer Name: " << host;
/*H*/      //    cout << "  " << computerName << endl;

/*H*/      }
















/*H*/      else{ }
/*H*/      //**   cout << "H Connected on port NTOS " << ntohs(client.sin_port) << " to " << host << endl; }
// cout << " additionalDataBuffer begin" << endl;

// guest receive



char additionalDataBuffer[MAX_BUFFER_SIZE];

int additionalDataSize = recv(clientSocket, additionalDataBuffer, MAX_BUFFER_SIZE, 0);

string guestDataAll = "";
string guestDataShrinking = "";

string guestData2 = ""; string guestData3 = ""; string guestData4 = "";
string guestData5 = "";  string guestData6 = "";string guestData7 = "";
string guestData8 = "";   string guestData9 = "";  string guestData10 = "";
string guestData11 = "";   string guestData12 = "";  string guestData13 = "";
string guestData14 = "";   string guestData15 = "";  string guestData16 = "";





string collectedGuestData[50];
int collectGuestDataWalk=0;
string collectGuestDataSizeString="";
int collectGuestDataSizeInt=0;

if (additionalDataSize > 0) {
string additionalDataReceived(additionalDataBuffer, additionalDataSize);
guestDataAll = additionalDataReceived;
//cout <<"guestDataAll"<< guestDataAll<<endl;
  string guestDatasString =  guestDataAll.substr(0,4);
//cout <<"guestDatasString "<< guestDatasString<< endl;
  guestDataShrinking = additionalDataReceived.erase(0, 4);
//cout <<"guestDataShrinking "<< guestDataShrinking<< endl;


__int128 guestDatasInt = StringTo128Class::stringToInt128( guestDatasString );
//cout << "total Guest Datas: "<< int(guestDatasInt); 
while(collectGuestDataWalk < guestDatasInt){
collectGuestDataSizeString = guestDataShrinking.substr(0,4);  // gearBuildString 10 digits
guestDataShrinking = additionalDataReceived.erase(0, 4);
collectGuestDataSizeInt = StringTo128Class::stringToInt128( collectGuestDataSizeString );
//cout << "collectGuestDataSizeString: "<<collectGuestDataSizeString;    //  cin >> userInput;
collectedGuestData[collectGuestDataWalk] = guestDataShrinking.substr(0,collectGuestDataSizeInt);
guestDataShrinking = additionalDataReceived.erase(0, collectGuestDataSizeInt);



//cout << "  " << collectedGuestData[collectGuestDataWalk] << endl;
collectGuestDataWalk++;

}
///*H*/         realm_os_user_input(userInput);

guestData2 = collectedGuestData[0];   // guest gear version
guestData3 = collectedGuestData[1]  ; // myUniqueLoginKeyString 50 digits
guestData4 = collectedGuestData[2];  // hostIp00String 15 digits
guestData5 = collectedGuestData[3];   // claimedPort00String //5digits
guestData6 = collectedGuestData[4];  // UniqueId   // 10 digits 
guestData7 = collectedGuestData[5] ;  // tileCountString = "01234567890123456789";   // 20 digits 
guestData8 = collectedGuestData[6] ;  // wolfPackIdString = uniqueId;   // 10 digits 
guestData9 = collectedGuestData[7];  // wolfHungerString = "1234512345";   // 10 digits 
guestData10 = collectedGuestData[8] ;   // myPreferredUserHandleString ="jasonisaachuffbrodsky";  // no digit limit but string variable roof 
guestData11 = collectedGuestData[9] ;   //guestData[9] = globalmetalUpTimeString.getString();
guestData12 = collectedGuestData[10] ;   //guestData[10] = globalMetalGUID;
guestData13 = collectedGuestData[11] ;   //guestData[11] = globalMetalIdNum;
guestData14 = collectedGuestData[12] ;   //guestData[12] = GuestStatus
__int128 guestData2Int = StringTo128Class::stringToInt128( guestData2 );
guestData15 = collectedGuestData[13] ;   //guestData[12] = workQue
















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
cin >> userInput;
*/
//cout <<  "H from Gear "<< additionalDataBuffer << " 127.0.0.1:" << service << " x64 "<< computerName<<endl;

//cin >> userInput;
} else {
cout << "H Data Receive Error from Guest Gear"<< endl;
}
 bool updateGear = false; bool updateBook = false;   bool infiniteWalkGuest = false;
    __int128 guestPrimeQue = StringTo128Class::stringToInt128(guestData15);
    __int128 guestBuild = StringTo128Class::stringToInt128( guestData2 );
string wolfUniqueId = guestData6;// = collectedGuestData[4];  // UniqueId   // 10 digits 
    __int128 guestTileCount = StringTo128Class::stringToInt128( guestData7 );
    __int128 guestHostclaimedPort00 = StringTo128Class::stringToInt128( guestData5 );
string wolfHungerString = guestData9; // = collectedGuestData[7];  //
    __int128 wolfHunger = pow(2, StringTo128Class::stringToInt128( wolfHungerString ));
      string guestHostIp00String = guestData4;

   __int128 gearBuild  = 2502;

    __int128 guestUpTimeDouble = StringTo128Class::stringToInt128( guestData11 );

    string guestMetalGUID = guestData12;
    string guestMetalIdNum = guestData13;
    guestStatus = guestData14;
// cout <<    "        privateGuestStatus "<< privateGuestStatus<< endl ; cin >>userInput;
if(  globalMetalGUID ==  guestMetalGUID && globalMetalIdNum == guestMetalIdNum){
    //cout << "SAME METAL GOOD!"; cin >> userInput;
}


if ( guestBuild  < gearBuild) {  updateGear = true;  }

if (guestTileCount< tileCount){  updateBook = true;  }

if ( updateGear == false && updateBook == false){ infiniteWalkGuest = true; }


















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



// hostCOUT ARM
 cout << "\033[2;1H";
 cout << "H HOST PrimeClient : " <<privatePrimeClientUserName <<  endl;
cout << "H Metal HW Id: " << metalIdNum << "       " << endl;
cout << "H CPU Name: " << computerName << "       " << endl;
cout << "H IP: 127.0.0.1:"<< myPort << " Guests: " <<totalGuests << "       " << endl;
cout << "H Build  : "<< int(globalBuild)  << " Total Tiles : " << int(privateTileCount) << "       " << endl;
cout  << "H MyMiles = " << int(myMiles) <<  " MaxMiles = "<< int(maxMiles)<< endl;
cout << "H Hosted: " << int(hostCount) << " Total Collected: "<< int( hostCollectedArrays)  <<  "      " << endl;
cout << "H 1st: "<< int(private1stCollects) << "  ReAssigns: " << privateReAssigns << "                                              " << endl;
cout <<"H TotalPrimeCount: "<< int(privateTotalCount)<< " EtchWalk Remaining: " << int(privateRemainingEtchWalk) << "                    "<<endl;

cout <<"                                                                                                                                                       "<<endl;
cout << "  WolfDenId  : " << globalWolfDenIdString  << "       " << endl;
cout << "  WolfPackId : " << globalWolfPackIdString  << "       " << endl;
cout << "  WolfPackHunger : " << "12345"  << "       " << endl;
cout << "  WolfDenHunger : " << "12345678"  << "       " << endl;

//cout << "Metal GUID: " << metalGUID << "       " << endl;













































































































currentTime =getCurrentTimeInSeconds();
guestCheck =0;
while (guestCheck != totalGuests ){ 
   //cout << hostGuestListArray00[guestCheck];
freshness = ( currentTime - hostGuestListArrayFreshness00[guestCheck] ) ;
hostGuestListArrayFreshnessCurrent00[guestCheck] = freshness;
//cout << "     " << freshness<< endl<<"     jasonisaachuffbrodsky";

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

// hostSEND ARM    

 


int totalInstructionLines = 9 + (3*totalGuests);
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
        outputFile << globalWolfPackIdString << endl;
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


//int to string service  //int to string
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


if (guestStatus=="FirstRun"){  // Send WolfPackID and WolfDenID


        outputFile << "8" << endl; // Send FirstRun Settings
           outputFile << globalWolfPackIdString.c_str() << endl;
              outputFile <<  globalWolfDenIdString.c_str() << endl;

}


if (guestStatus=="PrimeBookReady"){  // Send infiniteLeap and wolfHunger
int sendQue = guestPrimeQue;
if (guestPrimeQue == -1){ sendQue = privateWolfPrimeQue; nothingEtched=true;}
string128Class leapString(privateInfiniteWalk);
string128Class guestPrimeQueString(sendQue);
 privateInfiniteWalk+=wolfHunger;

string assignedWolfLeapString =leapString.getString();
string assignedWolfPrimeQueString =guestPrimeQueString.getString();
      outputFile << "9" << endl; // Send FirstRun Settings
         outputFile << assignedWolfLeapString.c_str() << endl;
            outputFile <<  wolfHungerString.c_str() << endl;
        outputFile << " " << endl;
           outputFile << assignedWolfPrimeQueString.c_str() << endl;
        outputFile << " " << endl;



//cout << "Send InfiniteLeap: "  << assignedWolfLeapString.c_str() <<"  to guest: " << wolfUniqueId <<" at GuestHunger: " << wolfHungerString.c_str() ;
//cin >> userInput;
privateHostStatus = "WorkAssigned";
privateGuestAssignedQue = sendQue;
privateGuestAssignedWork = privateInfiniteWalk;
privateGuestAssignedHunger = wolfHunger;
privateGuestAssignedId ="wolfUniqueId";
assignmentCollected=true; 
guestConduitNames[sendQue] = wolfUniqueId;
} else { assignmentCollected=false;

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
sendForever = false;


/*H*/         }  // datasend SIZE



/*H*/      }     //   WHILE (sendForever)





// HOST FOLLOWUP ARM    







if ( updateBook == true && updateGear == false ) {


}


if ( guestStatus == "PrimeCatchReady") {  // RECEIVE PRIMECATCH TO HOST
if (wolfUniqueId == guestConduitNames[guestPrimeQue]) {  guestConduitVerify[guestPrimeQue] = true;} else { guestConduitVerify[guestPrimeQue] = false;} 
   char primeCatchDataBuffer[MAX_BUFFER_SIZE];
   uint32_t vectorSize = 0;
   
   recv(clientSocket, reinterpret_cast<char*>(&vectorSize), sizeof(vectorSize), 0);
   
   std::vector<byte> primeCatchReceive(vectorSize);
   
   recv(clientSocket, reinterpret_cast<char*>(primeCatchReceive.data()), vectorSize, 0);
if (guestConduitVerify[guestPrimeQue] == true){ 
   for (uint8_t byte : primeCatchReceive) { 
      vectorCaches[guestPrimeQue].emplace_back(static_cast<int>(byte));
   }
   currentQueueComplete[guestPrimeQue]=true; 
   hostCollectedArrays++; 
}
   privateHostStatus = "WorkCollected";     //  cout << "HOST RECEIVED VECTOR"; cin >> userInput;
}


























































































































































































































































































/*H*/           closesocket(sock);
/*H*/           WSACleanup();
/*H*/          delete[] array;
/*H*/           return;
/*H*/             break;  // Break out of the loop when all data has been sent












/*H*/  // }        // WHILE (PORTgrow == PORT)
//cout << "H -----------------------------------------------" << endl;
} // WHILE hostStayOpen
}           // WHILE SOCKETFOREVER == TRUE
delete[] array;
delete[] array;





} // END HOST FUNCTION


































































void conduit_weaver( string uniqueIdGlobal, bool createHostCommand,__int128 weaverBeginData, string hostIp, int hostPort)
{
__int128 weaverHostData; int weaveNewPort =0;
    RandomSeedProvider seedProvider;
    StringGenerator stringGenerator(seedProvider);
    bool passTorch = false;  string userInput ="";   bool reAssignmentBool=false; int queToll=0;      std::chrono::milliseconds::rep elapsedAverage = 0;
   std::string randomString1 ;      std::string randomString2 ;      std::string randomString3 ;   std::string randomString4 ;  std::string randomString5 ;
randomString3 = stringGenerator.generateRandomString(11);
randomString4 = stringGenerator.generateRandomString(14);  randomString5 = stringGenerator.generateRandomString(14);
string uniqueId = realm_unique_id(randomString3);
vector<byte> primeCatch;  __int128 feast=0;   int vectorWalk=0; int vectorData=0;
// create TEMP dir
tempDir="md PrimeBookOne\\archive\\"+uniqueId;
system(tempDir.c_str());
__int128 wolfLeap =0; int wolfHunger=0;



// PrimeBook Variable Primer ARM






// SET PRIMEBOOK VARIABLES
  const auto realm_thread_count = thread::hardware_concurrency();
  __int128 powerOf     = 20 ;                       // = powerOf ; 24 = 16meg 25 = 32 26 = 64 27 =128 28 =256meg uncompressed tile file
  __int128 songPowerOf = 18;                        // 2^23 = 8,388,608 = 8 GB
  __int128 songCount   = pow( 2, songPowerOf );
  __int128 singers     = realm_thread_count   ;     // Check for Concurrancy Minus One
 
  __int128 primerBase      = 0;
  __int128* primeIndex      = 0;
  __int128 indexTiles      = 0;
  __int128 primeIndexRoof  = 0;

// Initiate PRIMEBOOK
primeTileClass PrimeOne(powerOf, 12345, singers, primerBase,
                        primeIndex, indexTiles, primeIndexRoof);

PrimeOne.carve(singers);





// PrimeOne.conductor(  singers,  singleCore,  computeMethod, perThreadSlices,   mrTsaysRead,primerBase,gitState, uniqueIdGlobal,  createHost,  weaverBeginData, hostIp, hostPort);



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
*/





































































































































































































































































system("cls");
if(createHostCommand){
PrimeOne.COMMANDER();     privateGuestStatus = "PrimeBookReady";  system("cls");
   string primaryWolfPackId = realm_wolfpack_id(randomString4);  globalWolfPackIdString = primaryWolfPackId;
   string primaryWolfDenId = realm_wolfpack_id(randomString5);  globalWolfDenIdString = primaryWolfDenId;
}
string tempDir="md PrimeBookOne\\archive\\"+uniqueId;
system(tempDir.c_str());
bool weaveHost =createHostCommand;  int weavePort = globalNewHostPort;   bool weaveNewHost=false;  bool firstPassTorch = false;
int conduits = 1;   bool infinite = true;   int choirSize=0;     globalNewPort[0] =hostPort;
string instruction; int assignedPort = globalNewHostPort ; string assignedIP; string remotePort; string remoteIP;
int hostConduits = conduits;
int guestConduits = conduits;
int conduitCount =0;  __int128 weaverDataHost = 0;  __int128 weaverDataGear = 0;
bool weaveForever=true;  int returnData=1;  int myConnectAttempts =0 ;
globalGuestNewHost[0] = false;   globalGuestBecomeHost[0] = false;
int weavePortHost = globalNewHostPort ; if ( hostPort != 0){    weavePortHost = hostPort ;   }
   if ( weaveHost ){

// conduit_init_gearsArm      
tempDir="PrimeBookOne\\archive\\"+uniqueId+"\\";
string targetNamePath= tempDir+"\\initGuests.bat";
string deleteAnyPreviousInitGearFile = "@echo off & del " + targetNamePath;
system(deleteAnyPreviousInitGearFile.c_str());
//createGuests=false;
// create file in temp dir
  fstream bootGuestGears ;
  bootGuestGears.open(targetNamePath,
  fstream::in | fstream::out | fstream::app);
// querry how many cores available and use all minus one
const auto realm_thread_count = thread::hardware_concurrency();
int guestGears = realm_thread_count -1;




bootGuestGears << "@echo off" << endl;
bootGuestGears << "setlocal enabledelayedexpansion" << endl;

bootGuestGears << "set \"iterations=" << guestGears << "\"" << endl;
bootGuestGears << "set \"delay_seconds=1\"" << endl;

bootGuestGears << "for /l %%i in (1, 1, %iterations%) do (" << endl;
bootGuestGears << "    start \"\"  cmd /c ";
bootGuestGears << "primeone.exe ";
bootGuestGears << "-m 9 ";
bootGuestGears << "-p 54767 ";
bootGuestGears << "-ip 127.0.0.1";
bootGuestGears << " -c 1 ";
bootGuestGears << " -w g";
bootGuestGears << endl;


bootGuestGears << "    timeout /nobreak /t %delay_seconds% >nul" << endl;
bootGuestGears << ")" << endl;

bootGuestGears << "endlocal" << endl;
bootGuestGears << endl;



  bootGuestGears.close();


system(targetNamePath.c_str());

// run file 

//cout <<"GearGuestFileBuilt:                                          ";
//cin >> userInput;











































}

//                  =realm_metalARM!A1

while (weaveForever){   // system("cls"); cout << "WeaveForever"; cin >> userInput;
privateTileCount=PrimeOne.getTileCount();
privateTotalCount=PrimeOne.getTotalCount();
   randomString1 = stringGenerator.generateRandomString(15);     randomString2 = stringGenerator.generateRandomString(15);     randomString3 = stringGenerator.generateRandomString(15);
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
   if ( weaveHost ){//  system("cls"); cout << "Weave Host"; cin >> userInput;
//  ifHostPreStartStatusARM         
if (privateHostStatus == "ReadyForAssignment"&&assignmentCollected){
    
if (reAssignmentBool==false) {
   privateInfiniteWalk = PrimeOne.getInfiniteWalk();     
   privateWorkAssignment[currentQueue] = privateInfiniteWalk;
   privateWorkAssignmentHunger[currentQueue] = 0;   // SETUP for differing Hungers
   assignmentsCollected[currentQueue] = true;
   currentQueueComplete[currentQueue] = false;
   queueStartTimes[currentQueue] = std::chrono::steady_clock::now();
   privateWolfPrimeQue = currentQueue;
if (nothingEtched){
   currentQueue++; if(currentQueue>=vectorArrays){currentQueue=0;} }
   privateHostStatus ="AssignmentCollected";       
} 
if (reAssignmentBool) {reAssignmentBool=false;}
   privateHostStatus ="AssignmentCollected";       
} // finish  if privateHostStatus == "ReadyForAssignment"&&assignmentCollected){

privateRemainingEtchWalk = PrimeOne.remainingEtchWalk();


      for ( int conduit  = 0; conduit < conduits; conduit++) {
         if ( myMiles == maxMiles ){ firstPassTorch = true; passTorch = true;}
         if ( myMiles  > maxMiles ){ firstPassTorch = false; passTorch = true ;  }
//cout << "\033[1;1H" <<"H " << uniqueId << endl;    // cout << "\033[1;1H"<< "H:  "<< weavePortHost  << " Miles: " << myMiles << " Hosted: "<< hostCount++ << endl;  realm_os_user_input(userInput);
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
                      randomString2, randomString3, weaveHost, weavePort, returnData, weavePortHost, weaveNewPort, primeCatch);
            myMiles=0; myConnectAttempts++;
}




// ifHOSTFinishStatusARM                   

if (privateHostStatus == "WorkAssigned"){
//   PrimeOne.quiltInfiniteWalk(privateInfiniteWalk); // send updated infiniteWalk to PrimeBook
 //  PrimeOne.workAssignment(privateGuestAssignedQue, privateGuestAssignedWork, privateGuestAssignedHunger, privateGuestAssignedId);
privateHostStatus ="ReadyForAssignment";

}



if (privateHostStatus == "WorkCollected"){


   collect = true;
   nothingEtched = true;
   auto now = std::chrono::steady_clock::now();

   while (collect){
      if ( currentQueueComplete[collectNextQue]==true){
            
         for (byte b : vectorCaches[collectNextQue]) {   PrimeOne.etchFeast(static_cast<int>(b));  }
         
         auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - queueStartTimes[collectNextQue]).count();
         elapsedAverage += elapsed; elapsedAverage= elapsedAverage/2;

         currentQueueComplete[collectNextQue] = false;
         assignmentsCollected[collectNextQue] = false;
         vectorCaches[collectNextQue].clear();

         private1stCollects++; 
         collectNextQue++; if (collectNextQue>=vectorArrays){collectNextQue=0;}

      } else {
         collect = false;
         auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - queueStartTimes[collectNextQue]).count();
 
         if((elapsed>(elapsedAverage*3))){
            privateInfiniteWalk = privateWorkAssignment[collectNextQue];
            privateGuestHunger = privateWorkAssignmentHunger[collectNextQue];
            privateWolfPrimeQue = collectNextQue;
            currentQueueComplete[collectNextQue] = false;
            assignmentsCollected[collectNextQue] = true;
            privateReAssigns++;
            missedCollection=0;
            reAssignmentBool=true;
            queueStartTimes[collectNextQue] = now;
         }  
          
      }

} // finish collect



privateHostStatus ="ReadyForAssignment";

}// finish workCollected


































































































































































































































































// ifGUESTFinishStatusARM                    

if (privateGuestStatus == "FirstRun"){




}



if (privateGuestStatus == "ReadyToBegin"){

PrimeOne.COMMANDER();

privateGuestStatus = "PrimeBookReady";



}

if (privateGuestStatus == "PrimeBookCompute"){
//system("cls");
//cout << "PRIMEBOOK COMPUTE"; cin >> userInput;
primeCatch = PrimeOne.primeBookAuthor(privateWolfLeap,privateWolfHunger, privatePrimeQue,privateGuestAssignedQue);

privateGuestStatus = "PrimeCatchReady";



}


if (privateGuestStatus == "PrimeBookReceived"){


privateGuestStatus = "PrimeBookReady";
}






























































































































































































































































































} // WEAVE FOREVER
} //END FUNCTION



















































































































































































































void conduitCache(byte data){




vectorCaches[privatePrimeQue].emplace_back(data);


}



































void conduitVectorsInit(string segment){

int firstQuarter =vectorArrays/4;

if (segment=="first"){

   int walk=0;
   while (walk < firstQuarter){
      vectorCaches[walk].clear();
      vectorCollection[walk] =0;
      walk++;
   }

}


if (segment=="second"){
   int firstHalf =vectorArrays/2;
   int walk=firstQuarter;
   while (walk < firstHalf){
      vectorCaches[walk].clear();
      vectorCollection[walk] =0;
      walk++;
   }

}


if (segment=="third"){
   int firstHalf =vectorArrays/2;
   int walk = firstHalf;
   int thirdQuarter = firstHalf + firstQuarter;
   while (walk < firstQuarter){
      vectorCaches[walk].clear();
      vectorCollection[walk] =0;
      walk++;
   }

}

if (segment=="fourth"){
   int firstHalf =vectorArrays/2;
   int thirdQuarter = firstHalf + firstQuarter;
   int walk = thirdQuarter;
   while (walk < vectorArrays){
      vectorCaches[walk].clear();
      vectorCollection[walk] =0;
      walk++;
   }

}




} // finish conduitVectorINIT



































































































































































































































































bool conduitVectorsReady(string segment){


int ready=0;
int firstQuarter =vectorArrays/4;


//----------------------
if (segment=="first"){
   int walk=0; 
   while (walk < firstQuarter){
      if (vectorCollection[walk] !=0){ready++;}
   walk++;
   }

}


//----------------------
if (segment=="second"){
   int firstHalf = vectorArrays/2;
   int walk=firstQuarter; 
   while (walk < firstQuarter){
      if (vectorCollection[walk] !=0){ready++;}
   walk++;
   }

}



//----------------------
if (segment=="third"){

   int firstHalf = vectorArrays/2;
   int thirdQuarter = firstQuarter + firstHalf;
   int walk=firstHalf; 
   while (walk < thirdQuarter){
      if (vectorCollection[walk] !=0){ready++;}
   walk++;
   }

}



//----------------------
if (segment=="fourth"){

   int firstHalf = vectorArrays/2;
   int thirdQuarter = firstQuarter + firstHalf;
   int walk=thirdQuarter; 
   while (walk < vectorArrays){
      if (vectorCollection[walk] !=0){ready++;}
   walk++;
   }

}


//+++++++++++++++
if (ready == firstQuarter){
return true;}
else { return false;}


}
// finish function






















































































































































































































































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
 myMiles =0;   maxMiles =3500;  remainingGuests=0;
 privatePrimeCatchSize=0; sortCatch=0;  assignmentCollected=true; 

string* guestReturnArray = new string[ 1 ]; 
hostCount=0;privatePrimeQue=-1;
int* guestReturnPortArray = new int[ 1 ];  privateRemainingEtchWalk=0;
guestReturnPortArray[0] = globalNewHostPort;  missedCollection=0;
string* guestReturnIpArray = new string[ 1 ]; privateReAssigns=0;
string* guestReturnGearArray = new string[ 1 ];        privateNextBatch=0;   nothingEtched=true;



//   realm_metalARM          

double metalUpTime = 0;// realm_metalUpTime();
 metalGUID = realm_metalGUID();
 metalIdNum = realm_metalIdNum();
//globalMetalUpTime = metalUpTime;
 globalMetalGUID =metalGUID;
 globalMetalIdNum =metalIdNum;
//cout << "Uptime: " << metalUpTime << endl;
//cout << "metalGUID: " << metalGUID << endl;
//cout << "metalIdNum: " << metalIdNum << endl;

//cin >> userInput;





































































































vectorArrays =( (thread::hardware_concurrency())-1)*4; vectorIndex=0;   collect = true;   quarterVectorArrays =vectorArrays/4;
privateHostStatus ="ReadyForAssignment"; privateGuestAssignedQue =0; privateGuestAssignedWork =0; privateGuestAssignedHunger =0; privateGuestAssignedId ="";
privateGuestStatus="FirstRun";  privateWolfPrimeQue = -1;  privateInfiniteWalk=0;  privateReAssign=false;
privatePrimeClientUserName = "jasonisaachuffbrodsky";  private1stCollects=0;  guestConduitNames = new string[vectorArrays];  guestConduitVerify = new bool[vectorArrays];
globalPrimeClientUserName = privatePrimeClientUserName;  hostCollectedArrays=0;  privateQueCountConduit=0;
privateGuestAssigned = false;   privateGuestAssignment =0;   privateGuestHunger=0;  privateTileCount=0; collectNextQue = 0;
vectorCaches.resize(vectorArrays);  vectorCollection = new int[vectorArrays]; conduitVectorsInit("first");  conduitVectorsInit("second"); conduitVectorsInit("third");  conduitVectorsInit("fourth"); privateTotalCount=0;  assignmentsCollected = new bool[vectorArrays];   privateWorkAssignment = new __int128[vectorArrays];   privateWorkAssignmentHunger= new int[vectorArrays];   currentQueueComplete = new bool[vectorArrays]; 
} // END ConduitClassFunction
string getCurrentTimeInSecondsString() {
    auto currentTime = std::chrono::system_clock::now();
    auto secondsSinceEpoch = std::chrono::duration_cast<std::chrono::seconds>(currentTime.time_since_epoch());
    int returnInt =  static_cast<int>(secondsSinceEpoch.count());
    string128Class timeInSeconds( returnInt );
 return timeInSeconds.getString();  }

int getCurrentTimeInSeconds() {
    auto currentTime = std::chrono::system_clock::now();
    auto secondsSinceEpoch = std::chrono::duration_cast<std::chrono::seconds>(currentTime.time_since_epoch());
    return static_cast<int>(secondsSinceEpoch.count());
}

void weaverBegin( string uniqueIdGlobal, bool createHost,__int128 weaverBeginData, string hostIp, int hostPort ){

         conduit_weaver(uniqueIdGlobal, createHost, weaverBeginData, hostIp, hostPort );

}

vectorToByteArray(const vector<byte>& vec, byte* byteArray, size_t size){
if (size >= vec.size()) { memcpy(byteArray, vec.data(), vec.size());  }}




































































































































































































































































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
//=main_test!A1
bool createHost=true;
string networkAssignment ="default";
 bool singleCore=false; string computeMethod="null";
    string hostIp="null";
    int hostPort = 0;
 string optionComputeInput="default";
    bool optionO = false;
    int optionCores = 0;
    string optionMenueInput ="null";
    string optionFlagInput ="null";
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

        } else if (arg == "-f" && i + 1 < argc) {
            optionFlagInput = argv[i + 1];
            ++i; // Skip the next argument since it's already processed





        } else if (arg == "-x" && i + 1 < argc) {
            optionComputeInput = argv[i + 1];
            ++i; // Skip the next argument since it's already processed

        } else if (arg == "-w" && i + 1 < argc) {
            networkAssignment = argv[i + 1];
            ++i; // Skip the next argument since it's already processed




        } else {
            std::cerr << "Invalid argument: " << arg << std::endl;
        }
    }



if (networkAssignment=="g"){ networkAssignment="g"; createHost=false;
} else{ networkAssignment="h"; createHost=true;} 

// cout << "networkAssignment   " << networkAssignment; cin>> userInput;
// optionMenueInput="0";
    // Print the results
//    std::cout << "Option -o: " << std::boolalpha << optionO << std::endl;
//    std::cout << "Option -c: " << optionCores << std::endl;
//    std::cout << "Option -m: " << optionMenueInput << std::endl;
system("cls");
    std::cout << "Run Commands: " << endl;
if( hostIp == "null" &&  hostPort != 0 && networkAssignment == "g" ){cout << "Guest connect to Host Port: " <<  hostPort << endl;}
if( hostIp != "null" &&  hostPort != 0 && networkAssignment == "g" ){cout << "Guest connect to Host IP & Port: " << hostIp << ":" <<  hostPort << endl;}


if( hostPort != 0 &&  hostIp != "null" && networkAssignment == "h" ){  cout << "Host Assigned IP & Port: " << hostIp << ":" <<  hostPort << endl;  }
if( hostPort != 0 &&  hostIp == "null" && networkAssignment == "h" ){  cout << "Host Assigned Port: " <<  hostPort << endl;  }
if( optionCores ==1){singleCore=true;}
if( optionCores != 0 ){cout << "CPU Core Assignment: " << optionCores;
if( singleCore==true ){cout << "  SINGLE Core ";}
cout << endl;}
if( optionMenueInput != "null"){  cout << "Menue Assignment: " << optionMenueInput << endl; }

if( optionFlagInput != "null"){  cout << "Flag Assignment: " << optionFlagInput << endl; }
optionComputeInput = "Gear"; // blindPrime 
if( optionComputeInput != "default"){  cout << "Compute Assignment: " << optionComputeInput << endl; }
else{  cout << "Compute Assignment: " << optionComputeInput << endl;
computeMethod=optionComputeInput;
}
bool interrupted = false;
    std::mutex mtx;
    std::cout << "Press ENTER to interrupt default SET to Load-N-Go!!!" << std::endl;

    auto future = std::async(std::launch::async, [&mtx, &interrupted]() {
        std::cin.get();
        std::lock_guard<std::mutex> lock(mtx);
        interrupted = true;
    });

    for (int i = countdown_seconds; i >= 1; --i) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            if (interrupted) {
         optionMenueInput ="null";       break;
            }
        }
        std::cout << i << " ";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << std::endl;

    int GO = interrupted ? 0 : 1;
    std::cout << "GO = " << GO << std::endl;
// mainTest();

//realm_sw_variables();

librarian_functions( hostIp, hostPort, optionCores, optionMenueInput, optionFlagInput, optionComputeInput,  singleCore, computeMethod, createHost );
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
























































































































































































































































 void realm_sw_variable_primer (__int128 perThreadSlices, bool mrTsaysRead, __int128 singers,      __int128 primerBase, __int128 powerOf, bool gitState, string uniqueIdGlobal, bool createHost,    __int128 weaverBeginData, string hostIp, int hostPort,  bool singleCore, string computeMethod)



{

string text_function_name="realm_sw_variable_primer"; string text_post = "";
//="text_post = " &CHAR(34)&  " ENTER TEXT HERE "&CHAR(34)&";"&" "&"realm_post_client(text_function_name, text_post );"
 __int128 tileLay =0; __int128 readTileCount = 76767676;  __int128 indexTiles= 0 ;  __int128 primeIndexRoof= 0;
   __int128* primeIndex = new __int128[ readTileCount +2 ];  string stringBean="", stringBean2="";
__int128 zeroData =0; __int128 totalTiles=0;
__int128 songBuffer = 0; // future use 767676767
__int128 singersDigitSize=1;  __int128 singer =0;
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
primeTileClass PrimeOne(powerOf, 12345, singers, primerBase, primeIndex, indexTiles, primeIndexRoof);

while(singersDigitFind > 9){
  singersDigitFind = singersDigitFind /10;
  singersDigitSize++;
} 
PrimeOne.carve(singers);





//if ( mrTsaysRead == true){
// primeIndex = PrimeOne.rebuildBookIndex();

//PrimeOne.conductor(  singers,  singleCore,  computeMethod, perThreadSlices,   mrTsaysRead,primerBase,gitState, uniqueIdGlobal,  createHost,  weaverBeginData, hostIp, hostPort);

 // cout << "PrimeBook Load Finished : Press Enter to Continue. " ;

 // cout << "PrimeBook Now Verify : Press Enter to Continue. " ;
//  realm_os_user_input(userInput);
//  PrimeOne.verifyPrimeBook(singers);

// }

//if ( mrTsaysRead == false) {  
  //cout << " Mr T Says Start From Beginning" << endl;
//PrimeOne.buildPrimeBase(  singers,  perThreadSlices,   mrTsaysRead,primerBase);

//  PrimeOne.verifyPrimeBook(singers);
//}




//__int128 totalPrimeNow = PrimeOne.requestTotal();
//__int128 infiniteWalkNow = PrimeOne.requestInfiniteWalk();






  //string128ClassComma PrimeOneTotalString(total);
 //stringBean = PrimeOneTotalString.getString() ;
 //cout << endl << "----------> Dance Primed to : " << stringBean << " Total Primes" << endl<< endl<< endl<< endl;





//PrimeOne.conductor(  singers,  singleCore,  computeMethod, perThreadSlices,   mrTsaysRead,primerBase,gitState, uniqueIdGlobal,  createHost,  weaverBeginData, hostIp, hostPort);



















































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


cin >> text_post;



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


double realm_metalUptime(){





    // Get system uptime in milliseconds
    DWORD uptime = GetTickCount(); 
    
    // Convert milliseconds to seconds
    double uptime_seconds = uptime / 1000.0;

    //std::cout << "System Uptime: " << uptime_seconds << " seconds" << std::endl;
    
    return uptime_seconds;
}





































































































string realm_metalGUID(){

















    std::string command = "powershell.exe gwmi win32_networkadapter -Property guid";

    // Execute the PowerShell command and capture the output
    FILE* pipe = _popen(command.c_str(), "r");
    if (!pipe)
    {
        std::cerr << "Failed to execute command: " << command << std::endl;

    }
//    std::cout << command.c_str()<<std::endl;

    const int maxBufferSize = 128;
    char buffer[maxBufferSize];
    std::string result;
    std::string bufferString;
    std::string bufferStringShort;
    std::string guidKey="GuidKey";
    while (!feof(pipe))
    {
        if (fgets(buffer, maxBufferSize, pipe) != nullptr)
        {
            result += buffer;
            bufferString = buffer;
           bufferStringShort= bufferString.substr( 0, 4 );
//std::cout << bufferStringShort<< std::endl;
// std::cout << buffer;
        if (bufferString.substr( 0, 4 )=="GUID"){

        if (bufferString.substr( 0, 20 )=="GUID             : {"){
       //  std::cout << bufferString;
           bufferStringShort= bufferString.substr( 0, 56 );
         //  GUID             : {9BA5A73A-7FA8-41CA-A502-C8DAD3839573
        // std::cout << bufferStringShort << std::endl;

           bufferStringShort= bufferStringShort.substr( 20, 36 );
         //  GUID             : {9BA5A73A-7FA8-41CA-A502-C8DAD3839573
         //std::cout << bufferStringShort << std::endl;
         guidKey+="-"+bufferStringShort;
         }
        }
        }
    }
// std::cout << result.c_str();
    // Close the pipe
    _pclose(pipe);

   // std::cout << guidKey << std::endl;

    // Check if the port is available
    return guidKey;
}
















































string realm_metalIdNum(){
















    std::string command = "powershell.exe get-wmiobject Win32_ComputerSystemProduct";

    // Execute the PowerShell command and capture the output
    FILE* pipe = _popen(command.c_str(), "r");
    if (!pipe)
    {
        std::cerr << "Failed to execute command: " << command << std::endl;

    }
 //   std::cout << command.c_str()<<std::endl;

    const int maxBufferSize = 128;
    char buffer[maxBufferSize];
    std::string result;


    std::string bufferString;
    std::string bufferStringShort;
    std::string metalKey="MetalKey";

    std::string metalIdNum="";
    std::string metalName="";
    std::string metalVendor="";




    while (!feof(pipe))
    {
        if (fgets(buffer, maxBufferSize, pipe) != nullptr)
        {
            result += buffer;
            bufferString = buffer;
               if (bufferString.substr( 0, 4 )=="Iden"){
               //std::cout << bufferString;
               metalIdNum=bufferString.substr( 20, 14 );
              // std::cout << metalIdNum << std::endl;

               }
               if (bufferString.substr( 0, 4 )=="Name"){
              // std::cout << bufferString;
               metalName=bufferString.substr( 20, 14 );
            //   std::cout << metalName << std::endl;
               }
               if (bufferString.substr( 0, 4 )=="Vend"){
              // std::cout << bufferString;
               metalVendor=bufferString.substr( 20, 14 );
              // std::cout << metalVendor << std::endl;


               }




        }
    }
 //std::cout << result.c_str();
    // Close the pipe
    _pclose(pipe);


int metalIdNumSize =metalIdNum.size();
metalIdNumSize--;
metalIdNum = metalIdNum.substr(0,metalIdNumSize);

int metalNameSize =metalName.size();
metalNameSize--;
metalName = metalName.substr(0,metalNameSize);

int metalVendorSize =metalVendor.size();
metalVendorSize--;
metalVendor = metalVendor.substr(0,metalVendorSize);




metalKey=  metalIdNum +" * "+ metalName +" * "+ metalVendor;

std::cout << metalKey.c_str();


    // Check if the port is available
    return metalKey;
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





























































void realm_conduit()
{
string text_function_name="realm_conduit"; string text_post = "";
      //system("cls");





bool openPortFound = false;
string defaultPortString = "55555";










//realm_conduit_win(defaultPortString);
//}

//else {
text_post = "       PORT 55555 BUSY!!!!! "; realm_post_client(text_function_name, text_post );
// increase Port Number by ++ or +=3 or +=5

//}

//}





























text_post = "FUNCTION   realm_conduit   HAS COMPLETED SUCESSFULLY!    ----    PRESS KEY TO CONTINUE "; realm_post_client(text_function_name, text_post );

  string userInput;
    realm_os_user_input(userInput);

}








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






























































tuple<int,string,string,__int128,int,int> realm_conduit_win_guest(string returnGuestStatusIn, string uniqueId, int conduit, int myPort, string myIP, int remotePort, string remoteIP, string instruction, string randomString1, string randomString2, string randomString3, vector<byte> primeCatch, int returnPrimeQue )
{
string returnGuestStatus= returnGuestStatusIn;
int returnData = 1;      __int128 claimed128Port00  =0;
string text_function_name="realm_win_guest";   string newPort = "";
 string text_post = "";    int guestAssignedPrimeQue =0;
  string userInput;  string assignedWolfPrimeQueString="";
bool yesContinue=true;
 bool socketSearch=true;
  int PORTgrow =  remotePort;
   bool sendForever=true;
    int ARRAY_SIZE = 99999;  // cout << " ARRAY_SIZE " <<  ARRAY_SIZE << endl;
bool receiveForever=true;
 int dataSend=0;     __int128 guestAssignedWolfLeap =0; int guestAssignedWolfHunger =0;
  bool socketForever=true;
   bool printForever=true;
    string delString;   int wolfHunger = 16 ;    string wolfHungerString = "16"; //  2pow(16)
string remoteHostId ="";    string assignedWolfLeapString ="";  string assignedWolfHungerString ="";
int totalSends=0;   int allData=0;
__int128 returnWork=0;  int returnHunger=0;
  int* array = new int[ARRAY_SIZE];
/* GS */   int totalGuestDatas=0;
/* GS */   __int128 guestDataSize;
/* GS */   string guestDataSizeString="";
/* GS */   string guestData[50];   __int128 guestDataSizeStringSize=0;
/* GS */   string additionalData="";   __int128 totalGuestDataStringSize;
/* GS */   string totalGuestDatasString ="";  int guestAddWalk=0;
//    cout << "Initialize Winsock" << endl;
 string tempDir =  "PrimeBookOne\\archive\\"+uniqueId+"\\";
WSADATA wsData;
WORD ver = MAKEWORD(2, 2);
int wsOk = WSAStartup(ver, &wsData);
if (wsOk != 0){    cerr << "Can't initialize Winsock! Quitting" << endl;    return make_tuple(9,"9",returnGuestStatus,0,returnHunger, returnPrimeQue);}
SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);   // cout << "Create socket" << endl;
if (sock == INVALID_SOCKET) {
   cerr << "Can't create socket! Quitting" << endl;
   WSACleanup();
   return make_tuple(8,"8",returnGuestStatus,0,returnHunger, returnPrimeQue);
}
sockaddr_in hint{};
hint.sin_family = AF_INET;
hint.sin_addr.s_addr = inet_addr("127.0.0.1");
string ipAddress = inet_ntoa(hint.sin_addr);
while (socketForever==true){
     hint.sin_port = htons( PORTgrow );
//     cout << endl << "  G  HOST remote ip : " << ipAddress;
//   cout << endl << "  G  GUEST local ip : " << ipAddress;
//    cout << endl << "  G  GUEST local PORTgrow : " << int(PORTgrow) << " " ;
/*G*/        int connectResult = connect(sock, reinterpret_cast<sockaddr*>(&hint), sizeof(hint));
/*G*/         if (connectResult == SOCKET_ERROR) {
/*G*/             std::cerr << "G  due to HOST port " << PORTgrow << " Unavailable Error code: " << WSAGetLastError() << std::endl;
/*G*/             //  closesocket(sock);     WSACleanup();
/*G*/         //    cout << "I am GUEST CONNECTED TO HOST now Awaiting Continue" << endl;
/*G*/          }




string gearBuildString  = "0000002487"; // 10 digits
guestData[0] = gearBuildString;

string myUniqueLoginKeyString = "09876543210987654321098765432109876543210987654321"; // 50 digits
guestData[1] = myUniqueLoginKeyString;

string hostIp00String   = "127.000.000.001"; // 15 digits 
guestData[2] = hostIp00String;

string128Class claimedPort00Int128( remotePort );
string claimedPort00String = claimedPort00Int128.getString();   // 5 digits 

guestData[3] = claimedPort00String;

guestData[4] = uniqueId;

string tileCountString = "01234567890123456789";   // 20 digits 
guestData[5] =tileCountString;

 string wolfPackIdString = uniqueId;   // 33 digits 
guestData[6] = wolfPackIdString;

//string wolfHungerString = "1234512345";   // 10 digits 
guestData[7] = wolfHungerString;

string myPreferredUserHandleString ="jasonisaachuffbrodsky";  // no digit limit but string variable roof 
guestData[8] = myPreferredUserHandleString;

string128Class globalMetalUpTimeString( 0 );
guestData[9] = globalMetalUpTimeString.getString();

guestData[10] = globalMetalGUID;
guestData[11] = globalMetalIdNum;
guestData[12] = returnGuestStatus;
string128Class returnPrimeQueString(returnPrimeQue);
guestData[13] = returnPrimeQueString.getString();

totalGuestDatas=14;
string128Class guestDatasString(totalGuestDatas);
totalGuestDatasString = guestDatasString.getString();

totalGuestDataStringSize =totalGuestDatasString.length();
if (totalGuestDataStringSize==1){totalGuestDatasString= "000"+ totalGuestDatasString;};
if (totalGuestDataStringSize==2){totalGuestDatasString= "00"+ totalGuestDatasString;};
if (totalGuestDataStringSize==3){totalGuestDatasString= "0"+ totalGuestDatasString;};

additionalData = totalGuestDatasString;
while(guestAddWalk < totalGuestDatas){
   guestDataSize= guestData[guestAddWalk].size();
string128Class dataSizeString(guestDataSize);
   guestDataSizeString =dataSizeString.getString();
guestDataSizeStringSize = guestDataSizeString.size();  
   if (guestDataSizeStringSize==1){guestDataSizeString= "000"+ guestDataSizeString;};
   if (guestDataSizeStringSize==2){guestDataSizeString= "00"+ guestDataSizeString;};
   if (guestDataSizeStringSize==3){guestDataSizeString= "0"+ guestDataSizeString;};

additionalData+=   guestDataSizeString + guestData[guestAddWalk] ;
//cout << int(guestAddWalk)<< endl << guestDataSizeString << endl << guestData[guestAddWalk] << endl;

guestAddWalk++;
}
//cout << "G uniqueId send Rebuild:" << endl << additionalData<< endl;

// additionalData = gearBuildString + myUniqueLoginKeyString + 
//           hostIp00String  + claimedPort00String  +  uniqueId + tileCountString +
//           globalWolfPackIdString +wolfHungerString + myPreferredUserHandleString;
//cout << "G uniqueId send: og" << endl<< additionalData<< endl;
// Send the additional data to the host
//cin >> userInput;
send(sock, additionalData.c_str(), additionalData.size(), 0);
// Print the additional data sent


// std::cout << "   G Sent: "<< additionalData << "  To Host:" << std::endl;













































































































































































































































//guest send

/*Guest RECEIVE ARM*/           string128Class PORTgrowString( PORTgrow );   
string guestFileName = tempDir + "pb1_" + randomString1 + getCurrentTimeInSecondsString() + PORTgrowString.getString()  + ".txt";


/*G*/     //    cout << "G " << uniqueId <<":"<< conduit << " Guest File Name: " << guestFileName << endl;
/*G*/         std::ofstream copy( guestFileName , std::ios::binary);
/*G*/         while(printForever==true){
/*G*/             int* received_array = new int[ARRAY_SIZE];

/*G*/             int bytes_received = recv(sock, reinterpret_cast<char*>(received_array), ARRAY_SIZE * sizeof(int), 0);
/*G*/             copy.write(reinterpret_cast<const char*>(received_array), bytes_received);
/*G*/             copy.close();

/*G*/             delete[] received_array;
/*G*/             delete[] array;




// guestENACT  ARM     

// cout << "G Enact fileName : "<< guestFileName << "   <---"<<endl;
// ********* QUERRY LINE NUMBERS ***********
    ifstream file( guestFileName );

    if (!file) { cerr << "G Error opening Instructions file:    " << guestFileName << endl;  cout << "Error Reading ZipList File" << endl; }

    __int128 lineCount = 0;
    string line;

    while (getline(file, line)) {lineCount++;}   lineCount--;

    string128Class lineCountString( lineCount -1 );
    string stringLineCount = lineCountString.getString();
//  cout << "G Number of Instructions in pb1send.txt : " <<stringLineCount << endl;
        file.close();
// ******************************************
  const int MAX_LINES = 500;
string  instructionArray[MAX_LINES];
// ********* READ TXT DATA INTO ARRAY ***********
// cout <<"G Filename to Read Into Array : " << guestFileName << endl;
int walk =0;
   ifstream file2( guestFileName );
    if (!file2) {  std::cerr << "G Error opening file: " << guestFileName << std::endl;}
    if (file2.is_open()) {
        while (getline(file2, instructionArray[walk] )) {

  //        cout <<"G Instructed : "<< walk << " " << instructionArray[walk] << endl ;
walk++;
        }
        file2.close();

}
// cout << endl << endl << "PB1 TXT FINISHED" << endl << endl;
//system("cls");
 cout << "\033[0;1H" ;
// ******************************************
//system("cls");
string arrayInstruction; string arrayData;
// ********* ENACT COMMANDS ***********
int instruction =0;
while(instruction< lineCount ){

//cout <<"G Enact: " << instruction << " : " << instructionArray[instruction] << " "<< instructionArray[instruction + 1] << " " <<  instructionArray[instruction + 2] << endl;






// guestINSTRUCT ARM     
//cout << endl << "G Instruction " << instructionArray[instruction] << " with data " <<  instructionArray[instruction+2] << " : " << instructionArray[instruction]<< endl;
if (instructionArray[instruction] == "0"){        // total Instructions Line
//cout << "\033[2;1H" << endl <<" Enact Total Instructions : "<< instructionArray[instruction+2];
 remoteHostId = instructionArray[instruction+4];
// cout <<  "H: "<< remoteHostId << "     " << endl ; // "\033[3;1H"
}

if (instructionArray[instruction] == "1"){

//cout << "W# "<< instructionArray[instruction+2] << "     " <<endl; // << "\033[4;1H" 
//cout <<  endl << "W: "<< instructionArray[instruction+1] << "     " <<endl ; // "\033[5;1H"


}

if (instructionArray[instruction] == "2"){ // Run Updater

 cout << "                                                                    Update Gear Reconnect to Update IP : "<< instructionArray[instruction+1] << endl;
 cout << "                                                                    Update Gear Reconnect to Update Port : "<< instructionArray[instruction+2] << endl;
//  realm_win_updater(ip)
}

if (instructionArray[instruction]== "3"){
//cout << " Update Prime Book Reconnect to add more page tiles at Port" << endl;

}



if (instructionArray[instruction] == "4"){
//cout << " Begin InfiniteWalk at  XXX with total piesclice = xxx" << endl;

}




if (instructionArray[instruction] == "5"){
//cout << "  return foundPrimes to assigned primeFindsUpdaterPort" << endl;

}

if (instructionArray[instruction] == "6"){

 //  cout << "\033[5;1H" << instructionArray[instruction+1] ;
   newPort =  instructionArray[instruction+2];
//   cout <<"port:"<< instructionArray[instruction+2]<< endl;     
   claimed128Port00  =    StringTo128Class::stringToInt128( newPort );
//    cout <<  "\033[1;1H" << " I AM THE CHOSEN ONE" << endl; // initiate Host at Stated Port 
//cout << "Guest Become Host Count : "<< globalGuestBecomeHostCount++ << endl;    //realm_os_user_input(userInput);
system("cls");
      globalNewPort[0] =  int(claimed128Port00);
      globalGuestBecomeHost[0] =true;
      closesocket(sock);     WSACleanup();  return make_tuple(1,"1",returnGuestStatus,returnWork,returnHunger,returnPrimeQue);

}

if (instructionArray[instruction] == "7"){
//cout << "\033[;1H" << "                                       "<< newPort ;
//   cout << "\033[5;1H" << instructionArray[instruction+1] ;
   newPort =  instructionArray[instruction+2];
  // cout <<"port:"<< instructionArray[instruction+2]<< endl;     
   claimed128Port00  =    StringTo128Class::stringToInt128( newPort );
//cout << "\033[;1H";
//      cout <<  "\033[1;1H" <<" I SEEK THE CHOSEN ONE" << endl;  // connect guest to stated ip and port
//cout << "AAAAaAAAA"<<endl;    realm_os_user_input(userInput);
system("cls");
      globalNewPort[0] =  int(claimed128Port00);
      globalGuestBecomeHost[0] = false;  
      closesocket(sock);     WSACleanup();  return make_tuple(2,"2",returnGuestStatus,returnWork,returnHunger, returnPrimeQue);







}


if (instructionArray[instruction]== "8"){
globalWolfPackIdString = instructionArray[instruction+1];
globalWolfDenIdString = instructionArray[instruction+2];
returnGuestStatus ="ReadyToBegin";
}

if (instructionArray[instruction]== "9"){

//system("cls");

assignedWolfLeapString =  instructionArray[instruction+1];
assignedWolfHungerString =  instructionArray[instruction+2];
assignedWolfPrimeQueString =  instructionArray[instruction+4];
//cout << "GUEST RECEIVES INFINITEWALK:" << assignedWolfLeapString << " AssignedWolfHunger: "<< assignedWolfHungerString;
//cin >> userInput;
 guestAssignedWolfLeap       =    StringTo128Class::stringToInt128( assignedWolfLeapString );
 guestAssignedWolfHunger  =    StringTo128Class::stringToInt128( assignedWolfHungerString );
 guestAssignedPrimeQue      =    StringTo128Class::stringToInt128( assignedWolfPrimeQueString );




returnHunger = guestAssignedWolfHunger;
returnGuestStatus="PrimeBookCompute";
returnWork = guestAssignedWolfLeap;
returnPrimeQue = guestAssignedPrimeQue;

}






















































































instruction+=3;

}





  string delFile = "echo off & del " + guestFileName  ;
  system( delFile.c_str() );

































































































































































































































































// GUEST FOLLOWUP ARM       
if (1 == 0){  //   RECEIVE PRIMBEBOOKONE UPDATER



}


if ( 1 == 0 && 2 == 3 ) {   // RECEIVE A PRIMEBOOK


}


if ( returnGuestStatus == "PrimeCatchReady") {  // SEND PRIMECATCH TO HOST

//   send(sock, primeCatch, primeCatch.size(), 0);

    uint32_t vectorSize = primeCatch.size();
    send(sock, reinterpret_cast<const char*>(&vectorSize), sizeof(vectorSize), 0);

    // Send the vector data
    send(sock, reinterpret_cast<const char*>(primeCatch.data()), vectorSize, 0);

returnGuestStatus="PrimeBookReceived";




//system ("cls");
//cout << "GUEST SENT VECTOR"; cin >> userInput;
}











//  guestCOUT ARM             
system("cls");
cout << "\033[1;1H";
/*G*/        cout << "G " << uniqueId << endl;
/*G*/        cout << "G GUEST PrimeClient : " <<globalPrimeClientUserName <<  "      "<<endl;
cout << "G Metal HW Id: " << globalMetalIdNum << endl;
cout << "G CPU Name: " << "computerName" << "       " << endl;
/*G*/        cout << "G IP: " << ipAddress << ":" << PORTgrow << " Fellow Guests: "<< endl;
/*G*/        cout << "G Build : "<< gearBuildString  << " Total Tiles : " << tileCountString ;
/*G*/        cout << "G MyMiles : "<< "123" << "MissedAttempts : " << "123" << endl;
cout << "G Hosted: " <<" int(hostCount)" << "       " << endl;
/*G*/        cout << "G Host Name: " << endl;
/*G*/        cout << "G Host00 ID  :" << hostIp00String << ":" << claimedPort00String << endl;
cout << "              GuestStatus  : " << returnGuestStatus  << endl;
cout << "              GuestWolfQue  : " << int(returnPrimeQue)  << endl;
cout << "  WolfDenId  : " << globalWolfDenIdString  << endl;
cout << "  WolfPackId : " << globalWolfPackIdString  << endl;
cout << "  WolfHunger : " << wolfHungerString  << endl;
cout <<"                                                                                                                                                       "<<endl;
cout <<"                                                                                                                                                       "<<endl;
/*G*/       // cout << "G UniqueLoginKeyString : "<< myUniqueLoginKeyString << endl;
//cout << "Metal GUID: " << globalMetalGUID << endl;

















































































































/*G*/             closesocket(sock);
/*G*/             WSACleanup();
/*G*/             return make_tuple(0,"0",returnGuestStatus,returnWork,returnHunger, returnPrimeQue);

/*G*/             if (bytes_received == SOCKET_ERROR) {
/*G*/                 std::cerr << "G recv() failed: " << WSAGetLastError() << std::endl;
/*G*/                delete[] received_array;
/*G*/                delete[] array;

/*G*/                break;

/*G*/             } else if (bytes_received == 0) {
/*G*/                 std::cout << "G Guest disconnected" << std::endl;
/*G*/                delete[] received_array;
/*G*/                delete[] array;

/*G*/                break;
/*G*/             }

/*G*/             //cout << "GUEST totalDataReceives : "<<allData++;
/*G*/            // cout.flush();

/*G*/             closesocket(sock);
/*G*/             WSACleanup();
/*G*/         //   return 6;


/*G*/            } // WHILE (printForever==true)





















































































}           // WHILE SOCKETFOREVER == TRUE
delete[] array;
return make_tuple(returnData,"finish function", returnGuestStatus,returnWork,returnHunger, returnPrimeQue);
} // END FUNCTION


int getCurrentTimeInSecondsInt()
{


    auto currentTime = std::chrono::system_clock::now();
    auto secondsSinceEpoch = std::chrono::duration_cast<std::chrono::seconds>(currentTime.time_since_epoch());
    int returnInt =  static_cast<int>(secondsSinceEpoch.count());

 return returnInt;


}















































































































































































































































































































string getCurrentTimeInSecondsString()
{


    auto currentTime = std::chrono::system_clock::now();
    auto secondsSinceEpoch = std::chrono::duration_cast<std::chrono::seconds>(currentTime.time_since_epoch());
    int returnInt =  static_cast<int>(secondsSinceEpoch.count());
    string128Class timeInSeconds( returnInt );
 return timeInSeconds.getString();


}















































































































































































































































































































void librarian_functions( string hostIp, int hostPort, int optionCores, string optionMenue, string optionFlag, string optionCompute,  bool singleCore, string computeMethod, bool createHost )

{    

  string text_function_name="librarian_functions"; string text_post = "";
   bool commandLineMode = true;
   bool gitState=true;
   string userInput;   string setPrimeMath ="";
   if ( optionMenue != "null" ){        commandLineMode = true;        userInput = optionMenue;}
   if ( optionFlag != "null" ){        if(optionFlag=="git_off"){           gitState=false; }    }
   if ( optionCompute != "default" ){        if(optionFlag=="quickPrime"){           setPrimeMath="quickPrime"; }    
    if(optionFlag=="noPrime"){           setPrimeMath="noPrime"; }    
    } else { setPrimeMath = "quickPrime";}





  
  bool runForever=true;
  bool mrTsaysRead=false;
  bool questionDemonstrate=true;
  bool reload = false;
  

  int menueChoice = 0;
  int dataPort =1234;
  const auto realm_thread_count = thread::hardware_concurrency();
  __int128  powerOf = 20 ;                                  // = powerOf ; 24 = 16meg 25 = 32 26 = 64 27 =128 28 =256meg uncompressed tile file
  __int128 songPowerOf = 18;                               // 2^23 = 8,388,608 = 8 GB
  __int128 songCount   = pow( 2, songPowerOf );
  __int128 singers     =  realm_thread_count   ;            // Check for Concurrancy Minus One

  __int128 primerBase  =  pow(2,powerOf);;                  //                  __int128 primerBase  = (singers * songCount)/3;
  __int128 tileLay =0;
  __int128 readTileCount = 76767676;
  __int128 indexTiles= 0 ;
  __int128 primeIndexRoof= 0;
  __int128* primeIndex = new __int128[ readTileCount +2 ];


  while( questionDemonstrate==true){
    reload = false;
    if ( menueChoice  < 0 ) { menueChoice = 0 ; }

    if ( menueChoice == 0 ) {
      menu_librarian() ;
      menu_book ( songCount , primerBase , singers , powerOf ) ;
    }
    if ( menueChoice == 1 ) {  }
    if ( menueChoice == 2 ) {  }

if (optionMenue == "null"){  realm_os_user_input(userInput); }

//   ) 10 (
    if (userInput=="10" && menueChoice == 0  && reload == false ){  
       system("cls");
   }




















//PRIMEBOOK NETWORK GUEST ) 9 (
    if (userInput=="9" && menueChoice == 0  && reload == false ){  
      mrTsaysRead=true;   menueChoice =1;  system("cls");

      conduitClass winTelConduits( 5678 );
      createHost = false;__int128 weaverBeginData =0;
      globalRemotePortString = hostPort;
      globalRemoteIpString = hostIp;
      winTelConduits.weaverBegin(  uniqueIdGlobal,  createHost,  weaverBeginData, hostIp, hostPort);
      reload = true;
    }



//PRIMEBOOK NETWORK HOST   ) 8 (
    if (userInput=="8" && menueChoice == 0  && reload == false ){  
      mrTsaysRead=true;   menueChoice =1;  system("cls");

      conduitClass winTelConduits(5678);
      createHost = true;__int128 weaverBeginData =0;
      globalRemotePortString = hostPort;
      winTelConduits.weaverBegin(  uniqueIdGlobal,  createHost,  weaverBeginData, hostIp, hostPort);
      reload = true;
    }

//PRIMEBOOK      ) 00 (
    if (userInput=="00" && menueChoice == 0  && reload == false ){  
      mrTsaysRead=true;
      menueChoice =1;
      reload = true;

    }

//PRIMEBOOK ) 01 (
    if (userInput=="01" && menueChoice == 0  && reload == false ){  
      mrTsaysRead=true;
      menueChoice =1;
      reload = true;  __int128 weaverBeginData =0;

    }

//PRIMEBOOK load n go LOCAL ONLY  ) 0 (
    if (userInput=="0" && menueChoice == 0  && reload == false ){  
      mrTsaysRead=true;            menueChoice =1;     
      reload = true; 



//     realm_sw_variable_primer(songCount, mrTsaysRead, singers, primerBase, powerOf,gitState, uniqueIdGlobal,  createHost,  weaverBeginData, hostIp, hostPort,  singleCore,  computeMethod);
    }
//PRIMEBOOK Begin Anew  ) 1 (
    if (userInput=="1" && menueChoice == 0  && reload == false ){  
      mrTsaysRead=false;       
      menueChoice =1;       
      reload = true; __int128 weaverBeginData =0;
//    realm_sw_variable_primer(songCount, mrTsaysRead, singers, primerBase, powerOf,gitState, uniqueIdGlobal,  createHost,  weaverBeginData, hostIp, hostPort,  singleCore,  computeMethod);
      // primeTileClass PrimeOne(powerOf, 12345, singers, primerBase, primeIndex, indexTiles, primeIndexRoof);
      // realm_sw_variable_primer(songCount, mrTsaysRead, singers, primerBase, powerOf,gitState);
    }


//PRIMEBOOK ONE Connect  ) 2 (
    else if (userInput=="2" && menueChoice == 0  && reload == false ){ 
      reload = true;
    }




//PRIMEBOOK  Archive  ) 3 (
    else if (userInput=="3" && menueChoice == 0  && reload == false ){   
      // realm_win_archive(); 
      reload = true;
    }




// PRIMEBOOK  NETWORK Updater Send Receive LAN 127.0.0.1  ) 4 (
    else if (userInput=="4" && menueChoice == 0  && reload == false ){  
      //   realm_win_archive(); 
      userInput = "";
      //  realm_win_updater( userInput );
      reload = true;
    }




//ROLL PrimeOneOS Update Install & Load  ) 5 (
    else if (userInput=="5" && menueChoice == 0  && reload == false ){    
      realm_win_roll();
      reload = true;
    }


    else if (userInput=="6" && menueChoice == 0  && reload == false ){
      menueChoice =1; 
      reload = true;
    }



    else if (userInput=="7"  && menueChoice == 0  && reload == false ){ 
      mrTsaysRead=true;
      menueChoice =1;
      system("cls");
      //    realm_conduit_hosts();
//      conduitClass winTelConduits( 5678 );
      reload = true;
    }













//PRIMEBOOK Start ) 2 (
    else if (userInput=="2" && menueChoice ==1  && reload == false){ 
      mrTsaysRead=false;
      menueChoice =2; 
      //   realm_sw_variable_primer(songCount, mrTsaysRead, singers);
     reload = true; 
    }
    



//PRIMEBOOK  on Network ) 3 (
    else if (userInput=="3" && menueChoice ==1  && reload == false){   
      realm_win_ipconfig();
      reload = true;
    }
    



// ARCHIVE Create PrimeOneUpdater.zip  ) 4 (
    else if (userInput=="4" && menueChoice ==1  && reload == false){  
      //   realm_win_archive();
      //  realm_os_user_input(userInput);    cout << endl;
      reload = true;
    }





//  NETWORK PrimeOneUpdater.zip Send Receive LAN 127.0.0.1 ) 5 (
    else if (userInput=="5" && menueChoice ==1  && reload == false){  
      system("cls");
      //   realm_win_updater( userInput );
      reload = true;
    }





//ROLL PrimeOneOS Update Install & Load 
    else if (userInput=="6" && menueChoice ==1  && reload == false){  
      realm_win_roll();
      reload = true;
    }




// PRIMEBOOK  Transfer
    else if (userInput=="7" && menueChoice ==1  && reload == false){      
      reload = true; 
    }




// MENUE BACKWARD
    else if (userInput==".."|| userInput=="back") { 
      menueChoice--;
      reload = true; 
    }



// EXIT
    if (userInput=="exit") { 
      questionDemonstrate=false;
      exit(0);
    }

    else if (  reload == true) { system("cls"); }

    else {
      cout << endl << " INVALID ENTRY " << endl<< endl;
      system("cls");
     }  //  1
// 2

  } //3
} //4
//5  FINISH LIBRARIAN FUNCTIONS Function




























void menu_librarian()
{    
string text_function_name="menu_librarian"; string text_post = "";






































system("cls");
cout.flush();

 
cout  << " " << " " << " " << " " << " " << "X" << "X" << "X" << " " << "O" << "P" << "E" << "R" << "A" << "T" << "I" << "N" << "G" << " " << "S" << "Y" << "S" << "T" << "E" << "M" << " " << "X" << "X" << "X" << " " << " " << " " << " " << " " << " " << " " << "X" << "X" << "X" << " " << "N" << "E" << "T" << "W" << "O" << "R" << "K" << " " << " " << "A" << "D" << "D" << "R" << "E" << "S" << "S" << "E" << "S" << " " << "X" << "X" << "X" << " " << " " << " " << " " << " " <<  "X" << "X" << "X" << " " << "P" << "R" << "O" << "C" << "E" << "S" << "S" << "I" << "N" << "G" << " " << "U" << "N" << "I" << "T" << "S" << " " << "X" << "X" << "X" << " " << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " <<  " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "1" << "2" << "7" << "." << "0" << "." << "0" << "." << "1" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " <<  " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " <<  " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " <<  " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " <<  " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " <<  " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " <<  " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " <<  " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "Build count: " << "2502" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" <<  "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "file:///workspace/app/PB1/PrimeBook.CPP/primebookonexlsm.archive/2025/[primeOne_2025_4_7i.xlsm]librarian_functions" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" <<  "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << "X" << "X" << "X" << "X" << "X" << " " << "M" << "E" << "N" << "U" << "E" << " " << "O" << "P" << "T" << "I" << "O" << "N" << "S" << " " << "X" << "X" << "X" << "X" << "X" << "X" << " " << " " << " " <<  " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << " " << " " <<  " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << " " << "(" << "0" << ")" << " " << "P" << "r" << "i" << "m" << "e" << "B" << "o" << "o" << "k" << " " << "L" << "o" << "a" << "d" << " " << "&" << " " << "G" << "o" << "!" << " " << " " << "X" << " " << " " <<  " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << " " << "(" << "1" << ")" << " " << "P" << "r" << "i" << "m" << "e" << "B" << "o" << "o" << "k" << " " << "S" << "t" << "a" << "r" << "t" << " " << "A" << " " << "N" << "e" << "w" << " " << "X" << " " << " " <<  " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << " " << " " << "X" << "X" << "X" << "X" << " " << "P" << "R" << "I" << "M" << "E" << "B" << "O" << "O" << "K" << " " << "O" << "N" << "E" << " " << "S" << "T" << "A" << "T" << "U" << "S" << " " << "X" << "X" << "X" << "X" << " " << " " << " " << " " << "X" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << " " << " " <<  " " << " " << "X" << "X" << "X" << " " << "P" << "A" << "R" << "A" << "M" << "E" << "T" << "E" << "R" << "S" << "E" << "R" << "S" << " " << "X" << "X" << "X" << " " << " " << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << " " << "X" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << " " << " " << " " << "X" << " " << "(" << "l" << ")" << " " << "P" << "r" << "i" << "m" << "e" << "B" << "o" << "o" << "k" << " " << "O" << "n" << "e" << " " << "L" << "i" << "b" << "r" << "a" << "r" << "y" << " " << "X" << " " << " " <<  " " << "X" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << " " << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << "X" << " " << " " << " " << " " << " " << " " << " " << " " << "P" << "r" << "i" << "m" << "e" << " " << "R" << "a" << "t" << "i" << "o" << " " << "=" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << " " << " " << "X" << " " << "(" << "a" << ")" << " " << "P" << "r" << "i" << "m" << "e" << "B" << "o" << "o" << "k" << " " << "O" << "n" << "e" << " " << "A" << "r" << "c" << "h" << "i" << "v" << "e" << " " << "X" << " " << " " <<  "X" << " " << " " << " " << " " << " " << "(" << "c" << ")" << "u" << "t" << " " << "=" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << "X" << " " << " " << " " << " " << " " << " " << " " << " " << "T" << "o" << "t" << "a" << "l" << " " << "T" << "i" << "l" << "e" << "s" << " " << "=" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << " " << " " << "X" << " " << "(" << "r" << ")" << " " << "P" << "r" << "i" << "m" << "e" << "B" << "o" << "o" << "k" << " " << "O" << "n" << "e" << " " << "R" << "e" << "b" << "i" << "n" << "d" << " " << " " << "X" << " " << " " <<  "X" << " " << " " << "(" << "p" << ")" << "r" << "i" << "m" << "e" << "r" << " " << "=" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << "X" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << " " << " " << "X" << " " << "(" << "u" << ")" << " " << "P" << "r" << "i" << "m" << "e" << "B" << "o" << "o" << "k" << " " << "O" << "n" << "e" << " " << "U" << "p" << "d" << "a" << "t" << "e" << " " << " " << "X" << " " << " " <<  "X" << " " << "(" << "s" << ")" << "i" << "n" << "g" << "e" << "r" << "s" << " " << "=" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << "X" << " " << "L" << "a" << "r" << "g" << "e" << "s" << "t" << " " << "D" << "i" << "f" << "f" << "e" << "r" << "e" << "n" << "c" << "e" << " " << "=" << " " << "2" << "2" << "8" << " " << " " << " " << " " << " " << " " << " " << "X" << " " << " " << " " << "X" << "X" << "X" << "X" << "X" << "X" << " " << "(" << " " << ")" << " " << "P" << "a" << "u" << "s" << "e" << " " << " " << " " << " " << "X" << "X" << "X" << "X" << "X" << "X" << "X" << " " << " " << " " <<  "X" << " " << " " << " " << " " << " " << "P" << "o" << "w" << "e" << "r" << " " << "=" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << "X" << " " << " " << " " << " " << " " << " " << " " << "i" << "n" << "f" << "i" << "n" << "i" << "t" << "e" << "W" << "a" << "l" << "k" << " " << "=" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " <<  "X" << " " << "G" << "r" << "i" << "d " << " " << "=" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << "X" << " " << " " << " " << " " << " " << " " << " " << "T" << "o" << "t" << "a" << "l" << " " << "P" << "r" << "i" << "m" << "e" << "s" << " " << "=" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << " " << " " << " " << "." << "." << ":" << ":" << ":" << ":" << "T" << "Y" << "P" << "E" << " " << "A" << " " << "C" << "O" << "M" << "M" << "A" << "N" << "D" << ":" << ":" << ":" << ":" << "." << "." << " " << " " << " " << " " <<  "X" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << "X" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << " " << " " << " " << " " << " " << " " << " " << " " << "|" << "|" << " " << "|" << "|" << "|" << "|" << "|" << " " << "|" << "|" << "|" << " " << "|" << "|" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " <<  "X" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << "X" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << " " << " " << " " << " " << " " << " " << " " << "|" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "|" << " " << " " << " " << " " << " " << " " << " " << " " <<  "X" << " " << " " << " " << " " << " " << "(" << "c" << ")" << "P" << "U" << " " << "=" << " " << "Y" << "e" << "s" << " " << " " << " " << " " << " " << " " << " " << "X" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << "X" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "X" << " " << " " << " " << " " << " " << " " << "|" << " " << " " << "P" << "R" << "I" << "M" << "E" << "B" << "O" << "O" << "K" << " " << " " << "O" << "N" << "E" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " <<  "X" << " " << " " << " " << " " << " " << "(" << "g" << ")" << "P" << "U" << " " << "=" << " " << "N" << "o" << " " << " " << " " << " " << " " << " " << " " << " " << "X" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << " " << "X" << " " << " " << " " << " " << "N" << "e" << "t" << "w" << "o" << "r" << "k" << " " << "P" << "e" << "e" << "r" << "s" << " " << " " << "=" << " " << "3" << "0" << "0" << " " << " " << " " << " " << " " << " " << "X" << " " << " " << " " << " " << " " << " " << " " << " " << "|" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " <<  " " << "X" << "(" << "t" << ")" << "h" << "e" << "r" << "m" << "a" << "l" << " " << "=" << " " << "N" << "o" << " " << " " << " " << " " << " " << " " << " " << "X" << " " << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;

cout  << " " << " " << "X" << "X" << "X" << "X" << "X" << "X" << "X" << "X" << " " << "A" << "c" << "t" << "i" << "v" << "e" << " " << "i" << "p" << " " << "=" << " " << "1" << " " << " " << "X" << "X" << "X" << "X" << "X" << "X" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "|" << "|" << " " << "|" << "|" << "|" << "|" << "|" << "|" << "|" << "|" << "|" << "|" << "|" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " <<  " " << " " << "X" << "X" << "X" << "X" << " " << "P" << "o" << "r" << "t" << " " << "=" << " " << "5" << "5" << "5" << "5" << "5" << " " << " " << "X" << "X" << " " << " " << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << ""  << endl;



   cout << "\033[3;1H"; 





/*
    if( realm_win_port_check( "555555" ) ){
      cout << "Port 555555 is in use. . ." << endl;
    }

    else{
      cout << "Port is available. . ." << endl;
    } */
cout << "\033[4;1H";
// realm_gl_querry();

cout << "\033[4;1H";
realm_win_ipconfig();

cout << "\033[4;1H";
 // realm_win_handles_sockets();

// realm_os_windows();
cout << "\033[4;1H";
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






//librarian_functions();






text_post = "FUNCTION      HAS COMPLETED SUCESSFULLY!"; realm_post_client(text_function_name, text_post );

}
























































void realm_gl_querry()
{

// realm_gl_cuda_querry();
// realm_gl_webgl();
// realm_gl_opengl();
// realm_gl_vulkan();
// realm_gl_metal();
// realm_gl_directx();

// realm_gl_cores_zeluda();

// realm_gl_cores_gpufort();



    string* GPUvenderNames = new string[60];
     GPUvenderNames[0] = "AMD";
     GPUvenderNames[1] = "NVIDIA";
     GPUvenderNames[2] = "INTEL";
     GPUvenderNames[3] = "NAVI";
     GPUvenderNames[4] = "ASUS";
     GPUvenderNames[5] = "MSI";
     GPUvenderNames[6] = "GIGABYTE";
     GPUvenderNames[7] = "ZOTAC";
     GPUvenderNames[8] = "PNY";
     int next =0;
    string* GPUvenders = new string[200];

    IDirect3D9* d3d = Direct3DCreate9(D3D_SDK_VERSION);

    if (d3d) {
        std::vector<std::string> vendorNames;
        int adapterCount = d3d->GetAdapterCount();

        for (int i = 0; i < adapterCount; ++i) {
            D3DADAPTER_IDENTIFIER9 adapterIdentifier;
            if (SUCCEEDED(d3d->GetAdapterIdentifier(i, 0, &adapterIdentifier))) {
                vendorNames.push_back(adapterIdentifier.Description);
            }
        }

        for (const std::string& vendorName : vendorNames) {
                GPUvenders[next++] = vendorName;
        }

        d3d->Release();
    }




cout << "                                                                    Total DirectX GPUs  : " << next << endl;{}
  for (int venderWalk = 0; venderWalk < next; ++venderWalk){
    for (int venderNameWalk = 0; venderNameWalk < 9; ++venderNameWalk) {

      std::transform(GPUvenders[venderWalk].begin(), GPUvenders[venderWalk].end(), GPUvenders[venderWalk].begin(), ::toupper);
      std::transform(GPUvenderNames[venderNameWalk].begin(), GPUvenderNames[venderNameWalk].end(), GPUvenderNames[venderNameWalk].begin(), ::toupper);

      if (GPUvenders[venderWalk].find(GPUvenderNames[venderNameWalk]) != std::string::npos) {


cout << "                                                                    GPU[" << venderWalk << "] Identified as " << GPUvenderNames[venderNameWalk] << std::endl;
      } else {
       // std::cout << "String vendor not found" << std::endl;
      }
    }
  }
cout << "\033[3;1H";


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
void realm_os_windows()
{
string text_function_name="realm_os_windows"; string text_post = "";

// cout << "windows handles" << endl;
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
        std::cout << "Windows Handle : " << processHandle << " . . . . " <<endl;
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
  //  std::cout << "Windows File Handle : " << hwnd << ". . . . . " <<endl;






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
    //        std::cout << "Win Socket Handle : " << socketHandle <<" . . . . . " < endl;
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












































































































































































































































































void menu_book( __int128 slices , __int128 primer , __int128 singers , __int128 powerOf ) 
{    
string text_function_name="menu_book"; string text_post = "";
cout << "\033[1;1H";

cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
cout << endl << endl << endl << endl   << endl << endl << endl;






__int128 grid = pow( 2, powerOf );

string128ClassComma slicesString( slices );
string128ClassComma primerString(primer);
string128ClassComma singersString(singers);
string128ClassComma powerOfString(powerOf);
string128ClassComma gridString(grid);





cout << "X        Prime Ratio =           X  X (3) PrimeBook One Archive X  X    Slices = " << slicesString.getString() << endl ;
cout << "X        Total Tiles =           X  X (4) PrimeBook One Updater X  X    Primer = " << primerString.getString() << endl ;
cout << "X                                X  X (5) PrimeBook One Update  X  X   Singers = " <<singersString.getString() << endl ;
cout << "X Largest Difference =           X   XXXXXX (6) Settings XXXXXXX   X     Power = " <<powerOfString.getString() << endl ;
cout << "X       infiniteWalk =           X                                 X Grid = " <<gridString.getString() << endl ;

















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


























































































































































































































































void realm_win_updater( bool isHost, string guestName, string guestIP, string guestPort, string hostIP, string hostPort, string uniqueFileName)
{
string text_function_name="realm_win_guest"; string text_post = "";
int PORT = 54000 ; bool yesContinue=true; bool socketSearch=true; int PORTgrow = PORT; bool sendForever=true;
int ARRAY_SIZE = 999999999;  // cout << " ARRAY_SIZE " <<  ARRAY_SIZE << endl;
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
std::ofstream copy("PrimeOneUpdate\PrimeOneUpdate.zip", std::ios::binary);

while(printForever==true){
int* received_array = new int[ARRAY_SIZE];
// int received_array[ARRAY_SIZE];
int bytes_received = recv(sock, reinterpret_cast<char*>(received_array), ARRAY_SIZE * sizeof(int), 0);



copy.write(reinterpret_cast<const char*>(received_array), bytes_received);
copy.close();
   closesocket(sock);    WSACleanup();   return;

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


   closesocket(sock);    WSACleanup();   return;
}

// cout << "Waiting for a connection " << endl; // Accept a client socket
sockaddr_in client{};
int clientSize = sizeof(client);

SOCKET clientSocket = accept(sock, reinterpret_cast<sockaddr*>(&client), &clientSize);
if (clientSocket == INVALID_SOCKET){
   cerr << "Can't accept client Invalid Socket! Quitting" << endl;


   closesocket(sock);    WSACleanup();   return;
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

std::vector<char> data;
std::ifstream original("PrimeOneUpdate\PrimeOneUpdater.zip", std::ios::binary);

if (original) {
    // Read the contents of the file into the vector variable
    std::istreambuf_iterator<char> start(original), end;
    data.assign(start, end);
    original.close();
} else {
    std::cerr << "Failed to open 'original.zip' file" << std::endl;
   closesocket(sock);    WSACleanup();   return;
}




while (sendForever) {
    int remainingData = data.size() - dataSend;
    int bytesToSend = std::min(remainingData, static_cast<int>(ARRAY_SIZE * sizeof(char)));
    int bytes_sent = send(clientSocket, reinterpret_cast<char*>(data.data()) + dataSend, bytesToSend, 0);
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

        dataSend += bytes_sent;
    }

    if (dataSend >= data.size()) {
   closesocket(sock);    WSACleanup();   return;



       // break;  // Break out of the loop when all data has been sent
    }
}



cout << "SOCKET FOREVER ==TRUE"<< endl;
}
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
                    std::cout << " Thread Handle : " << threadHandle << " . . . . . . "<< endl;
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

int PORT =54000;









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











































































































































































































































void realm_win_ipconfig( )
{
string text_function_name="realm_win_ipconfig"; string text_post = "";



system(" ipconfig | findstr /r /c:\"IPv4\"");
system(" ipconfig | findstr /r /c:\"IPv6\"");
//  system(" ipconfig /all | findstr /r /c:\"IPv4\"");
// system(" ipconfig /all | findstr /r /c:\"IPv6\"");

}















































































































































































































































































































void realm_win_roll()
{
string text_function_name="realm_win_roll"; string text_post = "";


system("start PrimeOneUpdate.bat");

exit(0);








































}










































































































































































































































































string realm_win_archive()
{
string text_function_name="realm_win_archive"; string text_post = "";

system("del PrimeOneUpdate\\*.* /Q");


RandomSeedProvider seedProvider;
StringGenerator stringGenerator(seedProvider);
string randomString1 = stringGenerator.generateRandomString(5);


string uniqueFileName =  "updater_"+ realm_unique_id(randomString1) + ".zip";
string command1 = "tar -a -cf PrimeOneUpdate\\" + uniqueFileName + " *.dll *.exe *.bat";
system(command1.c_str());






// system("del PrimeOneUpdate\\PrimeOneUpdate.zip /q");


//system("copy PrimeOneUpdate\\PrimeOneUpdater.zip PrimeOneUpdate\\PrimeOneUpdate.zip");

return uniqueFileName;
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




























string realm_unique_id(string randomString3)
{
const auto realm_thread_count = thread::hardware_concurrency();


    string128Class numObj1( realm_thread_count );

//cout << "Unique Id for Instance of PrimeBookOne Gear# " << uniqueId << endl;
//string userInput;
//realm_os_user_input(userInput);


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




string uniqueId = "pb1_"+ numObj1.getString() + "_" + randomString3+"_" + formattedTime.str() ;










uniqueIdGlobal = uniqueId;
return uniqueId;






}









































































































































































































































































string realm_wolfpack_id(string randomString3)
{










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




string wolfId = "pb1_" + randomString3+"_" + formattedTime.str() ;











return wolfId;






}








































































































































































































































































bool countdown(int seconds) 
{



















}




















































void wait_for_input() 
{








}































































