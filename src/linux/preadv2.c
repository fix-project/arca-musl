#define _GNU_SOURCE
#include <sys/uio.h>
#include <unistd.h>
#include "syscall.h"

ssize_t preadv2(int fd, const struct iovec *iov, int count, off_t ofs, int flags)
{
  // TODO (arca): preadv2
  return -1;
}
