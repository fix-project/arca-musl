#define _GNU_SOURCE
#include "syscall.h"
#include <fcntl.h>

int open_by_handle_at(int mount_fd, struct file_handle *handle, int flags) {
  // TODO (arca): OPEN_BY_HANDLE_AT
  return -1;
}
