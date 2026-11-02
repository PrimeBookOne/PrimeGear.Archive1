#ifndef IPHLPAPI_H
#define IPHLPAPI_H
#include <winsock2.h>
#include <stdint.h>
typedef struct _IP_ADAPTER_INFO { struct _IP_ADAPTER_INFO* Next; char ComboIndex[256]; char AdapterName[256]; char Description[128]; UINT AddressLength; BYTE Address[8]; DWORD Index; UINT Type; UINT DhcpEnabled; char CurrentIpAddress[16]; char IpAddressList[100]; char GatewayList[100]; char DhcpServer[100]; BOOL HaveWins; char WinsServer[100]; DWORD LeaseObtained; DWORD LeaseExpires; } IP_ADAPTER_INFO;
DWORD GetAdaptersInfo(IP_ADAPTER_INFO*, PULONG);
#endif
