#ifndef WS2TCPIP_H
#define WS2TCPIP_H
#include <winsock2.h>
#include <netdb.h>
int getaddrinfo(const char*, const char*, const void*, void**);
void freeaddrinfo(void*);
int getnameinfo(const void*, int, char*, int, char*, int, int);
#endif
