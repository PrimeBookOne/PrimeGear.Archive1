# GearSlice Analysis: primeOne_2025_1_1 (2025)

**Source:** Spreadsheet cells -> **Target:** Extracted C++

## Summary
- Spreadsheet cells (tracked): 148
- Non-empty cells: 119
- Extracted C++ lines: 23765
- Incorporated cells: 119
- Unused cells: 0
- Code bundles identified: 18

## Code Bundles

### Bundle 1 (incorporated)
- **Cell A37**: #undef UNICODE

#ifndef _WIN32_WINNT
    #define _WIN32_WINNT 0x0600
#elif _WIN32_WINNT < 0x0600
   ...
- **Cell A38**: int const variable_types_available = 95;
int bit_current_count = 1;
int const system_max_bit = 65;
i...
- **Cell A39**: class string128Class
{
private:
    __int128 number;
    std::string result;

    void convert() {
 ...
- **Cell A40**: class GitHubFileManager {
private:
    static size_t save_data(char* buffer, size_t size, size_t nme...
- **Cell A41**: void unbroken(string words){
bool unBroken = true;  char choice ; while (unBroken){    cout << "\033...

### Bundle 2 (incorporated)
- **Cell A44**: class primeScribeClass
{

private:
  fstream primeMileStones;
  fstream primeBook;
  fstream primeCo...
- **Cell A46**: class conduitClass
{
private:  // **************** PRIVATE *******************


int* hostGuestListA...
- **Cell A45**: class RandomSeedProvider
{



public:
    RandomSeedProvider() {
        // Seed the random number g...

### Bundle 3 (incorporated)
- **Cell A175**: class primeTileClass...
- **Cell A176**: {...
- **Cell A177**: private:  // **************** PRIVATE *******************...

### Bundle 4 (incorporated)
- **Cell A182**: string targetTileName = "";
  string arrayNamePrefix = "Tile";
  string stringBean4 = "";
  string s...
- **Cell A183**: __int128 listBookZip(){ 
string userInput;   

// cout << " Begin listBookZip " << endl;   realm_os_...
- **Cell A184**: __int128* readBookIndex( __int128 readTileCount,  const int MAX_LINES){  
//system("cls"); 
string u...
- **Cell A185**: __int128 countTextLines(string fileName){ 


// cout << " Begin listIndexElements " << endl;   realm...
- **Cell A186**: void extractTile(__int128 tileNumber){      // cout << "Extract Tile " << endl; 
// string userInput...
- **Cell A187**: void fileIndex(__int128 data){
if (data == 0){
  string delIndexTXT = "echo off & del primebookone\\...
- **Cell A189**: void markIndex(__int128 data){



  fstream PrimeOneIndex ;
  PrimeOneIndex.open("PrimeBookOne\\prim...
- **Cell A190**: void cleanupRead(__int128 tileNumber){  

// cout <<"Cleanup" << endl;
  string128Class tileNumberSt...

### Bundle 5 (incorporated)
- **Cell A194**: bool verifyBook(__int128 singers,__int128 maxBookDepth, __int128* bookIndex, bool rebuildIndex){ 

 ...
- **Cell A195**: __int128 findMinimumPrimeBook( __int128 readTileCount, __int128* bookIndex) {
  //  system("cls");
 ...
- **Cell A196**: //...
- **Cell A197**: __int128 nextWalkPrime(  __int128 myInfiniteWalk )
{

__int128 myPrimeFindsLocal=0;



__int128 prim...
- **Cell A198**: __int128 moonWalkPrime(   __int128 myInfiniteWalk )
{


__int128 myPrimeFindsLocal=0;

__int128 sing...
- **Cell A199**: int testTile(){
  try{
    byte* testGridArray = new  byte[(grid*8)];
    // std::cout << "Created T...
- **Cell A200**: void gui(){
string col1Spacer = "   ";
string col2Spacer = "                          ";
string col3...
- **Cell A202**: void guiPrime(){

guiGrid[0][0][1] =guiGrid[0][0][0]+"Win64|";
guiGrid[1][0][1] =guiGrid[1][0][0];
g...
- **Cell A203**: void compressTile(string targetTileName){

  string addZipString = "echo off & tar  -r -f PrimeBookO...
- **Cell A204**: void guiDefaultsSet(){

guiGrid[0][0][0] ="OS : ";
guiGrid[1][0][0] =" ";
guiGrid[2][0][0] ="BUILD #...
- **Cell A205**: void etchTile(byte data) {
if(etchWalk%10000==0){
cout << "EtchTile : " << int(data) << "  EtchWalk ...
- **Cell A207**: void initiateTile(__int128 tileNumber ){

  string128Class tileNumberString ( tileNumber ); 
  targe...
- **Cell A209**: void initiateBreeze(){
  byte* threadBreezeWalk = new byte[singers];
}...
- **Cell A211**: void carveSlate(__int128 singers ) {  // cout << "CarveSlate Begin " << endl;
  __int128 singer = 0;...
- **Cell A212**: void logStart(string data){




  fstream primeBookLog ;
  primeBookLog.open("PrimeBookOne\\primeboo...
- **Cell A213**: void scribeSlate(__int128 singer, byte data){// cout << "singer scribeSlate " << int(singer) << " da...
- **Cell A214**: void logExit(string data){




  fstream primeBookLog ;
  primeBookLog.open("PrimeBookOne\\primebook...
- **Cell A215**: void readSlate(){//  cout << "Read Slate" << endl;
  __int128 singer=0;
  __int128 threadScribeTotal...
- **Cell A217**: void scrubSlate(){
  for (auto& pair : slate) {delete[] pair.second;}
  delete[] threadTotal ;    de...

### Bundle 6 (incorporated)
- **Cell A221**: void realm_os_user_input(string&validUserInput)
{    
 //  cout << "\033[25;1H"; 
/* ="cout << " & C...
- **Cell A223**: void menu_gyrogear( __int128 primeRatio, __int128 totalTiles, __int128 pDlarge, __int128 infiniteWal...
- **Cell A225**: byte breeze(__int128 singer) {
bool forever = true;
while (forever== true){
//cout << "    BBBBBBBBB...

### Bundle 7 (incorporated)
- **Cell A228**: void still(__int128 singer){  
//cout << "Begin still for singer : " << int(singer) << endl;
threadT...
- **Cell A230**: void testBook(){   string userInput="";

 cout << " Test Read PrimeBook Begin : Singers 000000000000...

### Bundle 8 (incorporated)
- **Cell A234**: bool primeDivise(__int128 data){
__int128 quickStep=0;
  __int128 primeBuild = 3;
  __int128 intTail...
- **Cell A236**: void librarianDancer( __int128 singer,
                      __int128 myInfiniteWalk ,
             ...
- **Cell A237**: void theConductor(__int128 singers,
                  __int128 perThreadSlices,
                   _...
- **Cell A238**: public: // **************** PUBLIC *******************...
- **Cell A240**: primeTileClass(__int128 powerOfIN,
               __int128 perThreadSlicesIN,
               __int12...
- **Cell A242**: void carve (__int128 singers) { carveSlate( singers );}
void scribe(__int128 singer, byte data){scri...

### Bundle 9 (incorporated)
- **Cell A256**: }; // PRIMETILE CLASS...
- **Cell A42**: void heartbeat();
void gyrocore();
void sw_purchase_verify();
void realm();
void realm_os_initiate()...
- **Cell A43**: class realm_conduit_win64Class
{


private: 
string text_function_name=""; string text_post = "";
st...

### Bundle 10 (incorporated)
- **Cell A47**: const char StringGenerator::charset[] = "jasonisaacbrodsky03091976";...
- **Cell A48**: int main(int argc, char* argv[])
{
string text_function_name="main"; string text_post = "";
// realm...
- **Cell A49**: void heartbeat()
{
string text_function_name="heartbeat"; string text_post = "";


text_post = " 432...
- **Cell A50**: void gyrocore()
{
string text_function_name="gyrocore"; string text_post = "";






text_post = "FU...
- **Cell A51**: void sw_purchase_verify()
{
string text_function_name="sw_purchase_verify"; string text_post = "";

...
- **Cell A52**: void realm()
{
string text_function_name="realm"; string text_post = "";
realm_os_initiate();
realm_...

### Bundle 11 (incorporated)
- **Cell A55**: void realm_os_initiate()
{
string text_function_name="realm_os_initiate"; string text_post = "";
rea...
- **Cell A56**: void realm_os_silent()
{
string text_function_name="realm_os_silent"; string text_post = "";






t...
- **Cell A57**: void realm_os_responsive()
{
string text_function_name="realm_os_responsive"; string text_post = "";...
- **Cell A58**: void realm_os()
{
string text_function_name="realm_os"; string text_post = "";
text_post = "FUNCTION...
- **Cell A59**: void realm_multi_core()
{
string text_function_name="realm_multi_core"; string text_post = "";


con...
- **Cell A60**: void realm_gpu_primer()
{










































































...
- **Cell A62**: void realm_os_interface()
{
string text_function_name="realm_os_interface"; string text_post = "";
r...
- **Cell A63**: void realm_post_client(string input_text_function_name, string input_text)
{
int stringLength = 35 -...
- **Cell A64**: void realm_querry_client()
{
string text_function_name="realm_querry_client"; string text_post = "";...
- **Cell A65**: void realm_os_menu()
{
string text_function_name="realm_os_menu"; string text_post = "";











...
- **Cell A66**: void realm_os_user_input(string&validUserInput)
{    
 //  cout << "\033[25;1H"; 
/* ="cout << " & C...

### Bundle 12 (incorporated)
- **Cell A74**: void realm_sw_divisor_dancer(__int128 singer, __int128 singersDigitSize, primeTileClass PrimeOne )
{...

### Bundle 13 (incorporated)
- **Cell A81**: void realm_sw_variable_primer(__int128 perThreadSlices, bool mrTsaysRead, __int128 singers, __int128...
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

### Bundle 14 (incorporated)
- **Cell A92**: string realm_unique_time_stamp()
{
const auto realm_thread_count = thread::hardware_concurrency();

...
- **Cell A94**: void realm_conduits()
{
string text_function_name="realm_conduits"; string text_post = "";







te...
- **Cell A96**: void realm_conduit()
{
string text_function_name="realm_conduit"; string text_post = "";
      //sys...
- **Cell A98**: void realm_conduit_adapter()
{
string text_function_name="realm_conduit_adapter"; string text_post =...
- **Cell A99**: void realm_conduits_ring(int ring)
{
string text_function_name="realm_conduits_ring"; string text_po...
- **Cell A100**: void realm_conduit_tree(int a,int b, int c, int d)
{
string text_function_name="realm_conduit_tree";...
- **Cell A102**: int realm_conduit_win_guest( string uniqueId, int conduit, int myPort, string myIP, int remotePort, ...
- **Cell A103**: int getCurrentTimeInSecondsInt()
{


    auto currentTime = std::chrono::system_clock::now();
    au...
- **Cell A104**: string getCurrentTimeInSecondsString()
{


    auto currentTime = std::chrono::system_clock::now();
...

### Bundle 15 (incorporated)
- **Cell A113**: void librarian_functions( string hostIp, int hostPort, int optionCores, string optionMenue, string o...
- **Cell A114**: void menu_librarian()
{    
string text_function_name="menu_librarian"; string text_post = "";





...
- **Cell A116**: void library()
{
string text_function_name="library"; string text_post = "";
text_post = " ENTER TEX...

### Bundle 16 (incorporated)
- **Cell A124**: void library_letter()
{
string text_function_name="library_letter"; string text_post = "";






// ...
- **Cell A125**: void library_time()
{
string text_function_name="library_time"; string text_post = "";





/*
// te...
- **Cell A126**: void librarian()
{
string text_function_name="librarian"; string text_post = "";






//librarian_f...

### Bundle 17 (incorporated)
- **Cell A131**: void realm_gl_querry()
{

// realm_gl_cuda_querry();
// realm_gl_webgl();
// realm_gl_opengl();
// r...
- **Cell A132**: void realm_gl_webgl()
{
string text_function_name="realm_gl_webgl"; string text_post = "";






tex...
- **Cell A133**: void realm_gl_vulkan()
{
string text_function_name="realm_gl_vulkan"; string text_post = "";






t...
- **Cell A134**: void realm_gl_opengl()
{
string text_function_name="realm_gl_opengl"; string text_post = "";






t...
- **Cell A135**: void realm_gl_metal()
{
string text_function_name="realm_gl_metal"; string text_post = "";






tex...
- **Cell A136**: void realm_gl_directx()
{
string text_function_name="realm_gl_directx"; string text_post = "";





...
- **Cell A137**: void realm_gl_cores_zeluda()
{
string text_function_name="realm_gl_cores_zeluda"; string text_post =...
- **Cell A138**: vector<DISPLAY_DEVICE> realm_gl_cores_cuda()
{






    vector<DISPLAY_DEVICE> gpus;
    DISPLAY_DE...
- **Cell A139**: void realm_gl_cores_gpufort()
{
string text_function_name="realm_gl_cores_gpufort"; string text_post...
- **Cell A140**: vector<DISPLAY_DEVICE> realm_gl_winGpus()



{

    vector<DISPLAY_DEVICE> gpus;
    DISPLAY_DEVICE ...
- **Cell A142**: void realm_gl_cuda_devices(int gpuIndex)
{
string text_function_name="realm_gl_cuda_devices"; string...
- **Cell A143**: void realm_gl_cuda_querry()
{
string text_function_name="realm_gl_cuda_querry"; string text_post = "...
- **Cell A145**: void realm_os_windows()
{
string text_function_name="realm_os_windows"; string text_post = "";

// c...
- **Cell A146**: void realm_win_handles_process()
{
string text_function_name="realm_win_handles_process"; string tex...
- **Cell A147**: void realm_win_handles_file()
{
string text_function_name="realm_win_handles_file"; string text_post...
- **Cell A148**: void realm_win_handles_file2()
{
string text_function_name="realm_win_handles_file2"; string text_po...
- **Cell A149**: void realm_win_handles_sockets()
{
string text_function_name="realm_win_handles_sockets"; string tex...
- **Cell A150**: void realm_win_handles_events()
{
string text_function_name="realm_win_handles_events"; string text_...
- **Cell A151**: void realm_win_handles_mutex()
{
string text_function_name="realm_win_handles_mutex"; string text_po...
- **Cell A152**: void realm_win_save_state()
{
string text_function_name="realm_win_save_state"; string text_post = "...
- **Cell A153**: void menu_book( __int128 slices , __int128 primer , __int128 singers , __int128 powerOf ) 
{    
str...
- **Cell A154**: void realm_win_host_send_data()
{
string text_function_name="realm_win_host_send_data"; string text_...
- **Cell A155**: void realm_win_updater( bool isHost, string guestName, string guestIP, string guestPort, string host...
- **Cell A156**: void realm_win_handles_thread()
{
string text_function_name="realm_win_handles_thread"; string text_...
- **Cell A157**: bool realm_win_port_check( string checkPort )
{
string text_function_name="realm_win_port_check"; st...
- **Cell A158**: void realm_os_tcp_host( )
{
string text_function_name="realm_os_tcp_host"; string text_post = "";
bo...
- **Cell A160**: void realm_win_ipconfig( )
{
string text_function_name="realm_win_ipconfig"; string text_post = "";
...
- **Cell A162**: string realm_win_archive()
{
string text_function_name="realm_win_archive"; string text_post = "";

...

### Bundle 18 (incorporated)
- **Cell A167**: bool countdown(int seconds) 
{



















}...
- **Cell A168**: void wait_for_input() 
{








}...

## Structure Map

### Includes (72)
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
- ... and 62 more

### Defines (5)
- #undef UNICODE
- #define _WIN32_WINNT 0x0600
- #undef _WIN32_WINNT
- #define _WIN32_WINNT 0x0600
- #define MAX_IPV4_ADDRESS_LENGTH 16

### Functions (94)
- void convert() {
- void convert() {
- void unbroken(string words){
- __int128 stringTo__int128(const std::string& binaryString) {
- __int128 maingo128(__int128 data) {
- uint8_t maingo8(uint8_t data) {
- uint8_t fileRead8(string fileName){
- __int128 fileRead128(string fileName){
- void dataIngest(__int128 dataIngestion){
- __int128 dataProvide128(__int128 dataLocation){
- ... and 84 more

### Classes (14)
- class string128Class
- class string128ClassComma
- class StringTo128Class {
- class GitHubFileManager {
- struct curl_slist* headers = NULL;
- struct curl_slist* headers = NULL;
- class PaddingAnalyzer {
- class magicVariable
- class primeScribeClass
- class conduitClass
- ... and 4 more

### Globals (2631)
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
- ... and 2621 more

### Comments (927)
- /* #include <io.h> */
- /* #include <GL/glut.h> */
- /* link with Ws2_32.lib */
- /* #include "../application/vulkan/vulkan-application.hpp" */
- /* #include "../application/vulkan/vulkan-common.hpp" */
- ////////////////// GLOBAL Dancer
- ////////////////// GLOBAL
- //const int PORT = 54000; // Port number for the connection
- // Add a comma every three digits (except at the beginning)
- // Function to convert a string to __int128
- ... and 917 more

