#ifndef WS2TCPIP_H
#define WS2TCPIP_H
#include <winsock2.h>
#include <stdint.h>
typedef struct addrinfo { int ai_flags; int ai_family; int ai_socktype; int ai_protocol; size_t ai_addrlen; char* ai_canonname; struct sockaddr* ai_addr; struct addrinfo* ai_next; } ADDRINFOA;
int getaddrinfo(const char*, const char*, const ADDRINFOA*, ADDRINFOA**);
void freeaddrinfo(ADDRINFOA*);
int getnameinfo(const struct sockaddr*, int, char*, int, char*, int, int);
#define AI_PASSIVE 0x1
#define AI_CANONNAME 0x2
#define AI_NUMERICHOST 0x4
#define NI_MAXHOST 1025
#define NI_MAXSERV 32
#define NI_NUMERICHOST 1
#define NI_NUMERICSERV 2
#endif
