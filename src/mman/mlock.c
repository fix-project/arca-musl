#define _GNU_SOURCE
#include "syscall.h"
#include <sys/mman.h>

int mlock(const void *addr, size_t len) {
  return mlock2(addr, len, 0);
}
