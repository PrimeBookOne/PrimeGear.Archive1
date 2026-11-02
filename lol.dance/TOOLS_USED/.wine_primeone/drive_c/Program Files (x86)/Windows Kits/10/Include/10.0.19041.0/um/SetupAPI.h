#ifndef SETUPAPI_H
#define SETUPAPI_H
#include <windows.h>
#include <stdint.h>
typedef void* HDEVINFO;
typedef struct _SP_DEVINFO_DATA { DWORD cbSize; } SP_DEVINFO_DATA;
BOOL SetupDiGetClassDevsExA(LPCGUID, LPCSTR, HWND, DWORD, HDEVINFO, LPCSTR, PVOID);
BOOL SetupDiEnumDeviceInfo(HDEVINFO, DWORD, PSP_DEVINFO_DATA);
BOOL SetupDiGetDeviceRegistryPropertyA(HDEVINFO, PSP_DEVINFO_DATA, DWORD, PDWORD, PBYTE, DWORD, PDWORD);
BOOL SetupDiDestroyDeviceInfoList(HDEVINFO);
#endif
