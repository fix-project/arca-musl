#include "ksigaction.h"
#include "libc.h"
#include "lock.h"
#include "pthread_impl.h"
#include "syscall.h"
#include <errno.h>
#include <signal.h>
#include <string.h>

static int unmask_done;
static unsigned long handler_set[_NSIG / (8 * sizeof(long))];

void __get_handler_set(sigset_t *set) {
  memcpy(set, handler_set, sizeof handler_set);
}

int __sigaction(int sig, const struct sigaction *restrict sa,
                struct sigaction *restrict old) {
  // TODO (arca): __sigaction
  return -1;
}

weak_alias(__sigaction, sigaction);
