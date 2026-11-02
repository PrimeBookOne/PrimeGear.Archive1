#ifndef TLHELP32_H
#define TLHELP32_H
#include <windows.h>
#include <stdint.h>
typedef struct tagPROCESSENTRY32 { DWORD dwSize; DWORD cntUsage; DWORD th32ProcessID; uintptr_t th32DefaultHeapID; DWORD th32ModuleID; DWORD cntThreads; DWORD th32ParentProcessID; LONG pcPriClassBase; DWORD dwFlags; char szExeFile[MAX_PATH]; } PROCESSENTRY32;
HANDLE CreateToolhelp32Snapshot(DWORD, DWORD);
BOOL Process32First(HANDLE, PROCESSENTRY32*);
BOOL Process32Next(HANDLE, PROCESSENTRY32*);
#endif
