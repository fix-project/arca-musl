#define _GNU_SOURCE
#include "syscall.h"
#include <sys/uio.h>
#include <unistd.h>

ssize_t pwritev2(int fd, const struct iovec *iov, int count, off_t ofs,
                 int flags) {
  // TODO (arca): pwritev2
  return -1;
}
