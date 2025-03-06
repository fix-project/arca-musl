#include "libc.h"
#include <features.h>

#define START "_start"

#include "crt_arch.h"

int main();
weak void _init();
weak void _fini();
int __libc_start_main(int (*)(), void (*)(), void (*)(), void (*)());

void _start_c() { __libc_start_main(main, _init, _fini, 0); }
