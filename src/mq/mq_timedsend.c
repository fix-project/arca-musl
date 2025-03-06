#include "syscall.h"
#include <errno.h>
#include <mqueue.h>

#define IS32BIT(x) !((x) + 0x80000000ULL >> 32)
#define CLAMP(x) (int)(IS32BIT(x) ? (x) : 0x7fffffffU + ((0ULL + (x)) >> 63))

int mq_timedsend(mqd_t mqd, const char *msg, size_t len, unsigned prio,
                 const struct timespec *at) {
  // TODO (arca): mq_timedsend
  return -1;
}
