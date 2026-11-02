#ifndef WINTERNL_H
#define WINTERNL_H
#include <windows.h>
typedef struct _PEB { BYTE Reserved1[2]; BYTE BeingDebugged; BYTE Reserved2[1]; void* Reserved3[2]; void* Ldr; void* ProcessParameters; } PEB;
typedef struct _TEB { void* Reserved1[12]; PEB* ProcessEnvironmentBlock; } TEB;
#endif
