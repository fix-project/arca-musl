#define _GNU_SOURCE
#include <sys/uio.h>
#include "syscall.h"

ssize_t process_vm_writev(pid_t pid, const struct iovec *lvec, unsigned long liovcnt, const struct iovec *rvec, unsigned long riovcnt, unsigned long flags)
{
  // TODO (arca): process_vm_writev
  return -1;
}

ssize_t process_vm_readv(pid_t pid, const struct iovec *lvec, unsigned long liovcnt, const struct iovec *rvec, unsigned long riovcnt, unsigned long flags)
{
  // TODO (arca): process_vm_readv
  return -1;
}
