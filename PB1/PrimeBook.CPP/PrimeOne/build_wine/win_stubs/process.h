#ifndef PROCESS_H
#define PROCESS_H
#include <stdint.h>
typedef uintptr_t _beginthreadex_proc_type;
uintptr_t _beginthreadex(void*, unsigned, _beginthreadex_proc_type, void*, unsigned, unsigned*);
void _endthreadex(unsigned);
#define _beginthread(func, stack, arg) _beginthreadex(NULL, stack, func, arg, 0, NULL)
#endif
