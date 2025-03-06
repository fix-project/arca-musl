#include "syscall.h"
#include <fcntl.h>
#include <mqueue.h>

int mq_close(mqd_t mqd) { return close(mqd); }
