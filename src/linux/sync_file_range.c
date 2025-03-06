#define _GNU_SOURCE
#include "syscall.h"
#include <errno.h>
#include <fcntl.h>

int sync_file_range(int fd, off_t pos, off_t len, unsigned flags) {
  // TODO (arca): sync_file_range
  return -1;
}
