#include "syscall.h"
#include <stdlib.h>

_Noreturn void _Exit(int ec) {
  syscall_resize(1);
  syscall_create_blob(1, (uint8_t *)&ec, sizeof(ec));
  syscall_exit(0);

  __builtin_unreachable();
}
