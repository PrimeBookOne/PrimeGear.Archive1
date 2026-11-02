#ifndef IPTYPES_H
#define IPTYPES_H
#include <winsock2.h>
#include <stdint.h>
typedef struct _IP_ADDR_STRING { struct _IP_ADDR_STRING* Next; char IpAddress[16]; char IpMask[16]; DWORD Context; } IP_ADDR_STRING;
typedef struct _IP_ADAPTER_INFO { struct _IP_ADAPTER_INFO* Next; char ComboIndex[256]; char AdapterName[256]; char Description[128]; UINT AddressLength; BYTE Address[8]; DWORD Index; UINT Type; UINT DhcpEnabled; char CurrentIpAddress[16]; IP_ADDR_STRING IpAddressList; IP_ADDR_STRING GatewayList; IP_ADDR_STRING DhcpServer; BOOL HaveWins; IP_ADDR_STRING WinsServer; DWORD LeaseObtained; DWORD LeaseExpires; } IP_ADAPTER_INFO;
#endif
