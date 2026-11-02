#ifndef WBEMIDL_H
#define WBEMIDL_H
#include <windows.h>
typedef void* IWbemLocator;
typedef void* IWbemServices;
typedef void* IEnumWbemClassObject;
typedef void* IWbemClassObject;
#define WBEM_INFINITE 0xFFFFFFFF
HRESULT CoCreateInstance(void*, void*, DWORD, void*, void**);
HRESULT CoInitializeEx(void*, DWORD);
void CoUninitialize(void);
#endif
