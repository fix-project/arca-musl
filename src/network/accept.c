#include "syscall.h"
#include <sys/socket.h>

int accept(int fd, struct sockaddr *restrict addr, socklen_t *restrict len) {
  return accept4(fd, addr, len, 0);
}
