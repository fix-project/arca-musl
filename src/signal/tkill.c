#include "pthread_impl.h"
#include "syscall.h"
#include <signal.h>
#include <stdint.h>

int __tkill(pid_t tid, int sig) {
  // TODO (arca): tkill
  return -1;
}
