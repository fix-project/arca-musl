# Arca Syscall Files

### File Control

- [ ] `src/fcntl/open`
- [ ] `src/fcntl/openat`
- [ ] `src/fcntl/open_by_handle_at`
- [ ] `src/fcntl/posix_fadvise`
- [ ] `src/fcntl/posix_fallocate`
- [ ] `src/fcntl/close`
- [ ] `src/fcntl/fcntl`

### Exit

- [x] `src/exit/_Exit`

### Signal

- [ ] `src/signal/block`
- [ ] `src/signal/getitimer`
- [ ] `src/signal/kill`
- [ ] `src/signal/setitimer`
- [ ] `src/signal/sigaction`
- [ ] `src/signal/sigaltstack`
- [ ] `src/signal/sigpending`
- [ ] `src/signal/sigqueue`
- [ ] `src/signal/sigsuspend`
- [ ] `src/signal/sigtimedwait`
- [ ] `src/signal/tkill`

### Linux

- [ ] `src/linux/arch_prctl`
- [ ] `src/linux/cap`
- [ ] `src/linux/chroot`
- [ ] `src/linux/clock_adjtime`
- [ ] `src/linux/copy_file_range`
- [ ] `src/linux/epoll`
- [ ] `src/linux/eventfd`
- [ ] `src/linux/fallocate`
- [ ] `src/linux/fanotify`
- [ ] `src/linux/flock`
- [ ] `src/linux/getdents`
- [ ] `src/linux/getrandom`
- [ ] `src/linux/inotify`
- [ ] `src/linux/ioperm`
- [ ] `src/linux/iopl`
- [ ] `src/linux/klogctl`
- [ ] `src/linux/membarrier`
- [ ] `src/linux/memfd_create`
- [ ] `src/linux/mlock2`
- [ ] `src/linux/mlockall`
- [ ] `src/linux/module`
- [ ] `src/linux/mount`
- [ ] `src/linux/name_to_handle_at`
- [ ] `src/linux/personality`
- [ ] `src/linux/pivot_root`
- [ ] `src/linux/prctl`
- [ ] `src/linux/preadv2`
- [ ] `src/linux/pwritev2`
- [ ] `src/linux/prlimit`
- [ ] `src/linux/process_vm`
- [ ] `src/linux/ptrace`
- [ ] `src/linux/quotactl`
- [ ] `src/linux/readahead`
- [ ] `src/linux/reboot`
- [ ] `src/linux/remap_file_pages`
- [ ] `src/linux/sbrk`
- [ ] `src/linux/sendfile`
- [ ] `src/linux/setfsgid`
- [ ] `src/linux/setfsuid`
- [ ] `src/linux/setgroups`
- [ ] `src/linux/sethostname`
- [ ] `src/linux/setns`
- [ ] `src/linux/signalfd`
- [ ] `src/linux/splice`
- [ ] `src/linux/syncfs`
- [ ] `src/linux/statx`
- [ ] `src/linux/swap`
- [ ] `src/linux/sync_file_range`
- [ ] `src/linux/sysinfo`
- [ ] `src/linux/tee`
- [ ] `src/linux/timerfd`
- [ ] `src/linux/unshare`
- [ ] `src/linux/vhangup`
- [ ] `src/linux/vmsplice`
- [ ] `src/linux/xattr`

### Threads

- [ ] `src/thread/__futex`
- [ ] `src/thread/__set_tid_address`
- [ ] `src/thread/__set_thread_area`
- [ ] `src/thread/__unmapself`
- [ ] `src/thread/pthread_create`
- [ ] `src/thread/pthread_mutex_trylock`
- [ ] `src/thread/pthread_mutexattr_setrobust`

### Scheduler

- [ ] `src/sched/affinity`
- [ ] `src/sched/sched_get_priority`
- [ ] `src/sched/sched_getcpu`
- [ ] `src/sched/sched_getparam`
- [ ] `src/sched/sched_getscheduler`
- [ ] `src/sched/sched_rr_get_interval`
- [ ] `src/sched/sched_setscheduler`
- [ ] `src/sched/sched_setparam`
- [ ] `src/sched/sched_yield`

### Select

- [ ] `src/select/pselect`
- [ ] `src/select/select`

### Memory

- [ ] `src/malloc/__brk`
- [ ] `src/mman/madvise`
- [ ] `src/mman/mincore`
- [ ] `src/mman/mmap`
- [ ] `src/mman/mprotect`
- [ ] `src/mman/mremap`
- [ ] `src/mman/msync`
- [ ] `src/mman/munlock`
- [ ] `src/mman/munlockall`
- [ ] `src/mman/munmap`

### IPC

- [ ] `src/ipc/msgctl`
- [ ] `src/ipc/msgget`
- [ ] `src/ipc/msgrcv`
- [ ] `src/ipc/msgsnd`
- [ ] `src/ipc/semctl`
- [ ] `src/ipc/semget`
- [ ] `src/ipc/semop`
- [ ] `src/ipc/semtimedop`
- [ ] `src/ipc/shmat`
- [ ] `src/ipc/shmctl`
- [ ] `src/ipc/shmdt`
- [ ] `src/ipc/shmget`

### Unistd

- [ ] `src/unistd/access`
- [ ] `src/unistd/acct`
- [ ] `src/unistd/chdir`
- [ ] `src/unistd/chown`
- [ ] `src/unistd/dup3`
- [ ] `src/unistd/fcaccessat`
- [ ] `src/unistd/fchdir`
- [ ] `src/unistd/fchown`
- [ ] `src/unistd/fchownat`
- [ ] `src/unistd/fdatasync`
- [ ] `src/unistd/fsync`
- [ ] `src/unistd/ftruncate`
- [ ] `src/unistd/getcwd`
- [ ] `src/unistd/getegid`
- [ ] `src/unistd/geteuid`
- [ ] `src/unistd/getgid`
- [ ] `src/unistd/getgroups`
- [ ] `src/unistd/getpgid`
- [ ] `src/unistd/getpid`
- [ ] `src/unistd/getppid`
- [ ] `src/unistd/getsid`
- [ ] `src/unistd/getuid`
- [ ] `src/unistd/lchown`
- [ ] `src/unistd/link`
- [ ] `src/unistd/linkat`
- [ ] `src/unistd/lseek`
- [ ] `src/unistd/pause`
- [ ] `src/unistd/pipe2`
- [ ] `src/unistd/pread`
- [ ] `src/unistd/pwrite`
- [ ] `src/unistd/read`
- [ ] `src/unistd/readlink`
- [ ] `src/unistd/readlinkat`
- [ ] `src/unistd/readv`
- [ ] `src/unistd/rename`
- [ ] `src/unistd/renameat`
- [ ] `src/unistd/rmdir`
- [ ] `src/unistd/setpgid`
- [ ] `src/unistd/setsid`
- [ ] `src/unistd/setxid`
- [ ] `src/unistd/symlink`
- [ ] `src/unistd/symlinkat`
- [ ] `src/unistd/sync`
- [ ] `src/unistd/truncate`
- [ ] `src/unistd/unlink`
- [ ] `src/unistd/unlinkat`
- [ ] `src/unistd/waitid`
- [ ] `src/unistd/write`
- [ ] `src/unistd/writev`

### Miscellaneous

- [ ] `src/misc/getpriority`
- [ ] `src/misc/getresgid`
- [ ] `src/misc/getresuid`
- [ ] `src/misc/getrusage`
- [ ] `src/misc/ioctl`
- [ ] `src/misc/setdomainname`
- [ ] `src/misc/setpriority`
- [ ] `src/misc/uname`

### Process

- [ ] `src/process/execve`
- [ ] `src/process/fexecve`
- [ ] `src/process/_Fork`
- [ ] `src/process/vfork`

### Stat

- [ ] `src/stat/chmod`
- [ ] `src/stat/fchmod`
- [ ] `src/stat/fchmodat`
- [ ] `src/stat/fstatat`
- [ ] `src/stat/mkdir`
- [ ] `src/stat/mkdirat`
- [ ] `src/stat/mknod`
- [ ] `src/stat/mknodat`
- [ ] `src/stat/statvfs`
- [ ] `src/stat/umask`
- [ ] `src/stat/utimensat`

### Message Queue

- [ ] `src/mq/mq_notify`
- [ ] `src/mq/mq_open`
- [ ] `src/mq/mq_setattr`
- [ ] `src/mq/mq_timedreceive`
- [ ] `src/mq/mq_timedsend`
- [ ] `src/mq/mq_unlink`

### Network

- [ ] `src/network/accept`
- [ ] `src/network/bind`
- [ ] `src/network/connect`
- [ ] `src/network/getpeername`
- [ ] `src/network/getsockname`
- [ ] `src/network/getsockopt`
- [ ] `src/network/listen`
- [ ] `src/network/recvfrom`
- [ ] `src/network/recvmmsg`
- [ ] `src/network/recvmsg`
- [ ] `src/network/sendmsg`
- [ ] `src/network/sendto`
- [ ] `src/network/setsockopt`
- [ ] `src/network/shutdown`
- [ ] `src/network/socket`
- [ ] `src/network/socketpair`

### Time

- [ ] `src/time/clock_getres`
- [ ] `src/time/clock_gettime`
- [ ] `src/time/clock_nanosleep`
- [ ] `src/time/clock_settime`
- [ ] `src/time/timer_create`
- [ ] `src/time/timer_delete`
- [ ] `src/time/timer_getoverrun`
- [ ] `src/time/timer_gettime`
- [ ] `src/time/timer_settime`
- [ ] `src/time/times`
