#ifndef WINDOWS_H
#define WINDOWS_H
#include <stdint.h>
#include <stddef.h>
typedef void* HANDLE;
typedef void* HWND;
typedef uint32_t DWORD;
typedef int32_t LONG;
typedef uintptr_t WPARAM;
typedef intptr_t LPARAM;
typedef intptr_t LRESULT;
typedef uint16_t WORD;
typedef const char* LPCSTR;
typedef const wchar_t* LPCWSTR;
typedef char* LPSTR;
typedef wchar_t* LPWSTR;
#define WINAPI __stdcall
#define CALLBACK __stdcall
#define IN
#define OUT
#define OPTIONAL
#define MAX_PATH 260
#define TRUE 1
#define FALSE 0
#define NULL 0
#endif
