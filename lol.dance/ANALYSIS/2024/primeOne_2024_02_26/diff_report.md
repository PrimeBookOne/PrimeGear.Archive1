# GearSlice Analysis: primeOne_2024_02_26 (2024)

**Source:** Spreadsheet cells -> **Target:** Extracted C++

## Summary
- Spreadsheet cells (tracked): 140
- Non-empty cells: 68
- Extracted C++ lines: 9137
- Incorporated cells: 68
- Unused cells: 0
- Code bundles identified: 11

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

### Bundle 2 (incorporated)
- **Cell A175**: class primeTileClass...
- **Cell A176**: {...
- **Cell A177**: private:  // **************** PRIVATE *******************...

### Bundle 3 (incorporated)
- **Cell A182**: string targetTileName = "";
  string arrayNamePrefix = "Tile";
  string stringBean4 = "";
  string s...
- **Cell A183**: __int128 listBookZip(){ 
 string userInput="";
  //cout << " 999 " << endl;
    //  realm_os_user_in...
- **Cell A184**: void readBookIndex(__int128 readTileCount, __int128* tileStart, __int128* tileFinish, __int128* tile...
- **Cell A186**: void extractTile(__int128 tileNumber){      // cout << "Extract Tile " << endl; 
// string userInput...
- **Cell A188**: void extractBookIndex(){ cout << "Extract Book Index " << endl; string userInput="";
//cout << " 11 ...
- **Cell A190**: void cleanupRead(__int128 tileNumber){  

// cout <<"Cleanup" << endl;
  string128Class tileNumberSt...
- **Cell A192**: //...
- **Cell A194**: void verifyBook(__int128 singers){ 

  bool infinite = true;
  __int128 singersPlus = singers +1;
  ...
- **Cell A196**: //...

### Bundle 4 (incorporated)
- **Cell A199**: int testTile(){
  try{
    byte* testGridArray = new  byte[(grid*8)];
    // std::cout << "Created T...
- **Cell A201**: void exportTile(string targetTileName){
    byte* fileTile;
  fileTile = tiles[targetTileName];
  st...
- **Cell A203**: void compressTile(string targetTileName){

  string addZipString = "echo off & tar  -r -f PrimeBookO...
- **Cell A205**: void etchTile(byte data) {
    
  byte* targetTile;  
  string128Class tileCountString ( tileCount )...
- **Cell A207**: void initiateTile(__int128 tileNumber ){  string128Class tileNumberString ( tileNumber ); string str...
- **Cell A209**: void initiateBreeze(){
  byte* threadBreezeWalk = new byte[singers];
}...
- **Cell A211**: void carveSlate(__int128 singers ) {  // cout << "CarveSlate Begin " << endl;
  __int128 singer = 0;...
- **Cell A213**: void scribeSlate(__int128 singer, byte data){// cout << "singer scribeSlate " << int(singer) << " da...
- **Cell A215**: void readSlate(){//  cout << "Read Slate" << endl;
  __int128 singer=0;
  __int128 threadScribeTotal...
- **Cell A217**: void scrubSlate(){
  for (auto& pair : slate) {delete[] pair.second;}
  delete[] threadTotal ;    de...

### Bundle 5 (incorporated)
- **Cell A221**: void realm_os_user_input(string&validUserInput)
{    
 //  cout << "\033[25;1H"; 
/* ="cout << " & C...
- **Cell A223**: void menu_gyrogear( __int128 primeRatio, __int128 totalTiles, __int128 pDlarge, __int128 infiniteWal...
- **Cell A225**: byte breeze(__int128 singer) {
bool forever = true;
while (forever== true){

  if (threadBreezeWalk[...

### Bundle 6 (incorporated)
- **Cell A228**: void still(__int128 singer){  
//cout << "Begin still for singer : " << int(singer) << endl;
threadT...
- **Cell A230**: void testBook(){   string userInput="";

 cout << " Test Read PrimeBook Begin : Singers 000000000000...
- **Cell A232**: __int128 primeBase(__int128 singers,
                  __int128 perThreadSlices,
                   ...
- **Cell A234**: bool primeDivise(__int128 data){
    
  __int128 primeBuild = 3;
  __int128 intTail =0;
  bool dance...
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

### Bundle 7 (incorporated)
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
- **Cell A44**: class primeScribeClass
{

private:
  fstream primeMileStones;
  fstream primeBook;
  fstream primeCo...
- **Cell A45**: class RandomSeedProvider
{



public:
    RandomSeedProvider() {
        // Seed the random number g...
- **Cell A46**: class conduitClass
{
private:  // **************** PRIVATE *******************


int* hostGuestListA...
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

### Bundle 8 (incorporated)
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

### Bundle 9 (incorporated)
- **Cell A74**: void realm_sw_divisor_dancer(__int128 singer, __int128 singersDigitSize, primeTileClass PrimeOne )
{...

### Bundle 10 (incorporated)
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

### Bundle 11 (incorporated)
- **Cell A92**: string realm_unique_time_stamp()
{
const auto realm_thread_count = thread::hardware_concurrency();

...
- **Cell A94**: void realm_conduits()
{
string text_function_name="realm_conduits"; string text_post = "";







te...

## Structure Map

### Includes (70)
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
- ... and 60 more

### Defines (5)
- #undef UNICODE
- #define _WIN32_WINNT 0x0600
- #undef _WIN32_WINNT
- #define _WIN32_WINNT 0x0600
- #define MAX_IPV4_ADDRESS_LENGTH 16

### Functions (54)
- void convert() {
- void convert() {
- __int128 listBookZip(){
- void readBookIndex(__int128 readTileCount, __int128* tileStart, __int128* tileFinish, __int128* tileTotals){
- void extractTile(__int128 tileNumber){      // cout << "Extract Tile " << endl;
- void extractBookIndex(){ cout << "Extract Book Index " << endl; string userInput="";
- void cleanupRead(__int128 tileNumber){
- void verifyBook(__int128 singers){
- int testTile(){
- void exportTile(string targetTileName){
- ... and 44 more

### Classes (12)
- class string128Class
- class string128ClassComma
- class StringTo128Class {
- class GitHubFileManager {
- struct curl_slist* headers = NULL;
- struct curl_slist* headers = NULL;
- class primeTileClass
- class realm_conduit_win64Class
- class primeScribeClass
- class RandomSeedProvider
- ... and 2 more

### Globals (1295)
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
- ... and 1285 more

### Comments (437)
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
- ... and 427 more

