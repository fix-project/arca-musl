#define _GNU_SOURCE
#include "pthread_impl.h"
#include "syscall.h"
#include <sched.h>
#include <string.h>

int sched_setaffinity(pid_t tid, size_t size, const cpu_set_t *set) {
  // TODO (arca): sched_setaffinity
  return -1;
}

int pthread_setaffinity_np(pthread_t td, size_t size, const cpu_set_t *set) {
  return -sched_setaffinity(td->tid, size, set);
}

int sched_getaffinity(pid_t tid, size_t size, cpu_set_t *set) {
  // TODO (arca): sched_getaffinity
  return -1;
}

int pthread_getaffinity_np(pthread_t td, size_t size, cpu_set_t *set) {
  return -sched_getaffinity(td->tid, size, set);
}
