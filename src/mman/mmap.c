#include "syscall.h"
#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>

static void dummy(void) {}
weak_alias(dummy, __vm_wait);

void *__mmap(void *start, size_t len, int prot, int flags, int fd, off_t off) {
  // TODO (arca): mmap
  return MAP_FAILED;
}

weak_alias(__mmap, mmap);
