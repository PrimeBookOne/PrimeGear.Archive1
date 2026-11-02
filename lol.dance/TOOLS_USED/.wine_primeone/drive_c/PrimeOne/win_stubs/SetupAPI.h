#ifndef SETUPAPI_H
#define SETUPAPI_H
#include <windows.h>
typedef void* HDEVINFO;
typedef struct _SP_DEVINFO_DATA { DWORD cbSize; } SP_DEVINFO_DATA;
BOOL SetupDiGetClassDevsExA(void*, void*, HWND, DWORD, HDEVINFO, void*, void*);
BOOL SetupDiEnumDeviceInfo(HDEVINFO, DWORD, void*);
BOOL SetupDiGetDeviceRegistryPropertyA(HDEVINFO, void*, DWORD, DWORD*, void*, DWORD, DWORD*);
BOOL SetupDiDestroyDeviceInfoList(HDEVINFO);
#endif
