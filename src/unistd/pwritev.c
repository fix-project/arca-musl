#define _GNU_SOURCE
#include <sys/uio.h>
#include <unistd.h>
#include "syscall.h"

ssize_t pwritev(int fd, const struct iovec *iov, int count, off_t ofs)
{
  return pwritev2(fd, iov, count, ofs, 0);
}
