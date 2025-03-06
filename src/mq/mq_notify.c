#include <mqueue.h>
#include <pthread.h>
#include <errno.h>
#include <sys/socket.h>
#include <signal.h>
#include <unistd.h>
#include <semaphore.h>
#include "syscall.h"

int mq_notify(mqd_t mqd, const struct sigevent *sev)
{
	// TODO (arca): mq_notify
	return -1;
}
