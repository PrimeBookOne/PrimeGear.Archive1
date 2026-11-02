#ifndef WINSOCK2_H
#define WINSOCK2_H
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
typedef unsigned int SOCKET;
#define INVALID_SOCKET (-1)
#define SOCKET_ERROR (-1)
#define SD_RECEIVE 0
#define SD_SEND 1
#define SD_BOTH 2
int WSAStartup(unsigned short, void*);
int WSACleanup(void);
SOCKET socket(int, int, int);
int closesocket(SOCKET);
int connect(SOCKET, const struct sockaddr*, int);
int send(SOCKET, const char*, int, int);
int recv(SOCKET, char*, int, int);
int select(int, void*, void*, void*, struct timeval*);
int ioctlsocket(SOCKET, long, unsigned long*);
unsigned long htonl(unsigned long);
unsigned short htons(unsigned short);
unsigned long ntohl(unsigned long);
unsigned short ntohs(unsigned short);
const char* inet_ntoa(struct in_addr);
int inet_pton(int, const char*, void*);
#endif
