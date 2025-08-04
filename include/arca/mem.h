#ifndef _ARCA_MEM
#define _ARCA_MEM
#include <sys/mman.h>

void *__sys_brk(void *p);
void *__sys_mmap(void *addr, size_t len, int prot, int flags, int filedes,
                 off_t off);
void *__sys_mmap2(void *addr, size_t len, int prot, int flags, int filedes,
                  unsigned long off);
int __sys_mprotect(void *addr, size_t len, int prot);
int __sys_munmap(void *addr, size_t len);

#endif
