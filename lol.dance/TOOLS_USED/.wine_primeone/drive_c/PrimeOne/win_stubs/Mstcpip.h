#ifndef MSTCPIP_H
#define MSTCPIP_H
#include <winsock2.h>
#define SIO_KEEPALIVE_VALS _WSAIOW(IOC_VENDOR, 4)
struct tcp_keepalive { uint32_t onoff; uint32_t keepalivetime; uint32_t keepaliveinterval; };
#endif
