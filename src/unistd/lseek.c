#include "syscall.h"
#include <unistd.h>

off_t __lseek(int fd, off_t offset, int whence) {
  // TODO (arca): lseek
  return -1;
}

weak_alias(__lseek, lseek);
