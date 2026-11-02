#ifndef WINSOCK2_H
#define WINSOCK2_H
#include <stdint.h>
typedef unsigned int SOCKET;
#define INVALID_SOCKET ((SOCKET)(~0))
#define SOCKET_ERROR (-1)
#define SD_RECEIVE 0
#define SD_SEND 1
#define SD_BOTH 2
#define AF_INET 2
#define AF_INET6 23
#define SOCK_STREAM 1
#define SOCK_DGRAM 2
#define IPPROTO_TCP 6
#define IPPROTO_UDP 17
#define SOMAXCONN 0x7fffffff
#define MSG_PEEK 0x2
#define MSG_OOB 0x1
#define FD_READ 0x01
#define FD_WRITE 0x02
#define FD_OOB 0x04
#define FD_ACCEPT 0x08
#define FD_CONNECT 0x10
#define FD_CLOSE 0x20
typedef struct sockaddr { uint16_t sa_family; char sa_data[14]; } SOCKADDR;
typedef struct sockaddr_in { uint16_t sin_family; uint16_t sin_port; uint32_t sin_addr; char sin_zero[8]; } SOCKADDR_IN;
typedef struct in_addr { uint32_t s_addr; } IN_ADDR;
typedef struct fd_set { uint32_t fd_count; SOCKET fd_array[64]; } fd_set;
typedef struct timeval { long tv_sec; long tv_usec; } timeval;
int WSAStartup(uint16_t, void*);
int WSACleanup(void);
SOCKET socket(int, int, int);
int closesocket(SOCKET);
int connect(SOCKET, const SOCKADDR*, int);
int bind(SOCKET, const SOCKADDR*, int);
int listen(SOCKET, int);
SOCKET accept(SOCKET, SOCKADDR*, int*);
int send(SOCKET, const char*, int, int);
int recv(SOCKET, char*, int, int);
int sendto(SOCKET, const char*, int, int, const SOCKADDR*, int);
int recvfrom(SOCKET, char*, int, int, SOCKADDR*, int*);
int select(int, fd_set*, fd_set*, fd_set*, timeval*);
int ioctlsocket(SOCKET, long, uint32_t*);
uint32_t htonl(uint32_t);
uint16_t htons(uint16_t);
uint32_t ntohl(uint32_t);
uint16_t ntohs(uint16_t);
const char* inet_ntoa(IN_ADDR);
int inet_pton(int, const char*, void*);
const char* inet_ntop(int, const void*, char*, size_t);
int getsockname(SOCKET, SOCKADDR*, int*);
int getpeername(SOCKET, SOCKADDR*, int*);
int getsockopt(SOCKET, int, int, char*, int*);
int setsockopt(SOCKET, int, int, const char*, int);
int shutdown(SOCKET, int);
int gethostname(char*, int);
struct hostent* gethostbyname(const char*);
int WSAGetLastError(void);
void WSASetLastError(int);
#define WSAEINTR 10004
#define WSAEBADF 10009
#define WSAEACCES 10013
#define WSAEFAULT 10014
#define WSAEINVAL 10022
#define WSAEMFILE 10024
#define WSAEWOULDBLOCK 10035
#define WSAEINPROGRESS 10036
#define WSAEALREADY 10037
#define WSAENOTSOCK 10038
#define WSAEDESTADDRREQ 10039
#define WSAEMSGSIZE 10040
#define WSAEPROTOTYPE 10041
#define WSAENOPROTOOPT 10042
#define WSAEPROTONOSUPPORT 10043
#define WSAESOCKTNOSUPPORT 10044
#define WSAEOPNOTSUPP 10045
#define WSAEPFNOSUPPORT 10046
#define WSAEAFNOSUPPORT 10047
#define WSAEADDRINUSE 10048
#define WSAEADDRNOTAVAIL 10049
#define WSAENETDOWN 10050
#define WSAENETUNREACH 10051
#define WSAENETRESET 10052
#define WSAECONNABORTED 10053
#define WSAECONNRESET 10054
#define WSAENOBUFS 10055
#define WSAEISCONN 10056
#define WSAENOTCONN 10057
#define WSAESHUTDOWN 10058
#define WSAETOOMANYREFS 10059
#define WSAETIMEDOUT 10060
#define WSAECONNREFUSED 10061
#define WSAELOOP 10062
#define WSAENAMETOOLONG 10063
#define WSAEHOSTDOWN 10064
#define WSAEHOSTUNREACH 10065
#define WSAENOTEMPTY 10066
#define WSAEPROCLIM 10067
#define WSAEUSERS 10068
#define WSAEDQUOT 10069
#define WSAESTALE 10070
#define WSAEREMOTE 10071
#endif
