#ifndef WINBASE_H
#define WINBASE_H
#include <windows.h>
#define INFINITE 0xFFFFFFFF
#define WAIT_OBJECT_0 0
#define WAIT_TIMEOUT 258
typedef struct _OVERLAPPED { void* Internal; void* InternalHigh; uint32_t Offset; uint32_t OffsetHigh; HANDLE hEvent; } OVERLAPPED;
BOOL CloseHandle(HANDLE);
DWORD WaitForSingleObject(HANDLE, DWORD);
HANDLE CreateEventA(void*, int, int, const char*);
BOOL SetEvent(HANDLE);
BOOL ResetEvent(HANDLE);
#endif
