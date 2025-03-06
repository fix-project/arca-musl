#define _BSD_SOURCE
#include "syscall.h"
#include <dirent.h>
#include <limits.h>

int getdents(int fd, struct dirent *buf, size_t len) {
  // TODO (arca): getdents
  return -1;
}
