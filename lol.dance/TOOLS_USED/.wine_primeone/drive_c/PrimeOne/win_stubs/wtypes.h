#ifndef WTYPES_H
#define WTYPES_H
#include <windows.h>
#include <stdint.h>
typedef uint16_t OLECHAR;
typedef OLECHAR* BSTR;
typedef const OLECHAR* LPCOLESTR;
typedef OLECHAR* LPOLESTR;
typedef int32_t HRESULT;
#define S_OK 0
#define S_FALSE 1
#define E_FAIL 0x80004005
#define E_INVALIDARG 0x80070057
#define E_OUTOFMEMORY 0x8007000E
#define E_NOINTERFACE 0x80004002
#define E_POINTER 0x80004003
#define SUCCEEDED(hr) (((HRESULT)(hr)) >= 0)
#define FAILED(hr) (((HRESULT)(hr)) < 0)
typedef struct _GUID { uint32_t Data1; uint16_t Data2; uint16_t Data3; uint8_t Data4[8]; } GUID;
typedef GUID IID;
typedef GUID CLSID;
#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
    const GUID name = { l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } }
#endif
