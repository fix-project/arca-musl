#include "syscall.h"
#include <errno.h>
#include <mqueue.h>

#define IS32BIT(x) !((x) + 0x80000000ULL >> 32)
#define CLAMP(x) (int)(IS32BIT(x) ? (x) : 0x7fffffffU + ((0ULL + (x)) >> 63))

ssize_t mq_timedreceive(mqd_t mqd, char *restrict msg, size_t len,
                        unsigned *restrict prio,
                        const struct timespec *restrict at) {
  // TODO (arca): mq_timedreceive
  return -1;
}
