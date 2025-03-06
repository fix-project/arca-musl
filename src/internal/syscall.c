__asm__(".globl syscall\n\t"
        "syscall:\n\t"
        "mov %r10, %rcx\n\t"
        "syscall\n\t"
        "ret\n\t");
