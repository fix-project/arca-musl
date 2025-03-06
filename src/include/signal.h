#ifndef SIGNAL_H
#define SIGNAL_H

#include "../../include/signal.h"

hidden int __sigaction(int, const struct sigaction *, struct sigaction *);

hidden void __block_all_sigs(void *);
hidden void __block_app_sigs(void *);
hidden void __restore_sigs(void *);
hidden void __get_handler_set(sigset_t *);

hidden int __sigproc_mask(int, const sigset_t *, sigset_t *);
hidden int __sigqueueinfo(pid_t, int, const siginfo_t *);
hidden int __tkill(pid_t, int);

#endif
