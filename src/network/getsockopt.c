#include "syscall.h"
#include <errno.h>
#include <sys/socket.h>
#include <sys/time.h>

int getsockopt(int fd, int level, int optname, void *restrict optval,
               socklen_t *restrict optlen) {
  // TODO (arca): getsockopt
  return -1;
}
