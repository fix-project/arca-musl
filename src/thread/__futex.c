#include "futex.h"

long __futex(volatile void *addr, int op, long val,
             const struct timespec *timeout) {
  // TODO (arca): futex
  return -1;
}

long __futex_cp(volatile void *addr, int op, long val, long val2,
                volatile void *addr2) {
  // TODO (arca): futex_cp
  return -1;
}
