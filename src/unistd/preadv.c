#define _GNU_SOURCE
#include "syscall.h"
#include <sys/uio.h>
#include <unistd.h>

ssize_t preadv(int fd, const struct iovec *iov, int count, off_t ofs) {
  return preadv2(fd, iov, count, ofs, 0);
}
