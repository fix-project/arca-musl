#define _GNU_SOURCE
#include "syscall.h"
#include <fcntl.h>

int fallocate(int fd, int mode, off_t base, off_t len) {
  // TODO (arca): fallocate
  return -1;
}
