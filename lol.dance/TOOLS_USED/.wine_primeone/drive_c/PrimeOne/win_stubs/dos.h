#ifndef DOS_H
#define DOS_H
#include <stdint.h>
#define _O_RDONLY 0x0000
#define _O_WRONLY 0x0001
#define _O_RDWR 0x0002
#define _O_APPEND 0x0008
#define _O_CREAT 0x0100
#define _O_TRUNC 0x0200
#define _O_EXCL 0x0400
#define _O_TEXT 0x4000
#define _O_BINARY 0x8000
int _open(const char*, int, ...);
int _close(int);
int _read(int, void*, unsigned int);
int _write(int, const void*, unsigned int);
long _lseek(int, long, int);
int _chmod(const char*, int);
int _unlink(const char*);
int _access(const char*, int);
int _mkdir(const char*);
int _rmdir(const char*);
struct find_t { char reserved[21]; char attrib; unsigned short wr_time; unsigned short wr_date; long size; char name[13]; };
int _dos_findfirst(const char*, int, struct find_t*);
int _dos_findnext(struct find_t*);
#endif
