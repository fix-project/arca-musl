extern long syscall(long n, ...);

// Arca System Calls
#define __SYS_NOP 			0x00
#define __SYS_MOV 			0x01
#define __SYS_DUP 			0x02
#define __SYS_NULL			0x03
#define __SYS_RESIZE		0x04

#define __SYS_EXIT 			0x10
#define __SYS_EQ 			0x11
#define __SYS_FIND 			0x12
#define __SYS_LEN 			0x13
#define __SYS_READ 			0x14
#define __SYS_TYPE 			0x15

#define __SYS_CREATE_ATOM 	0x20
#define __SYS_CREATE_BLOB 	0x30
#define __SYS_CREATE_TREE 	0x40

#define __SYS_CONTINUATION	0x50
#define __SYS_APPLY			0x51
#define __SYS_TRACE			0x52
#define __SYS_UNAPPLY		0x53
#define __SYS_EXPLODE		0x54
#define __SYS_IMPLODE		0x55
#define __SYS_FORCE			0x56
#define __SYS_PROMPT		0x57
#define __SYS_PERFORM       0x58
#define __SYS_TAILCALL	 	0x59

#define __SYS_SHOW			0xf0
#define __SYS_LOG			0xf1

// Arca Error Codes
#define __ERR_OK			-0x00
#define __ERR_BAD_SYSCALL	-0x01
#define __ERR_BAD_INDEX		-0x02
#define __ERR_BAD_TYPE		-0x03
#define __ERR_BAD_ARGUMENT	-0x04
#define __ERR_OUT_OF_MEMORY	-0x05
#define __ERR_INTERRUPTED	-0x06
#define __ERR_CONTINUED		-0x07

// Arca Types
#define __TYPE_NULL         0x00
#define __TYPE_ERROR        0x01
#define __TYPE_ATOM         0x02
#define __TYPE_BLOB         0x03
#define __TYPE_TREE         0x04
#define __TYPE_PAGE         0x05
#define __TYPE_PAGETABLE    0x06
#define __TYPE_LAMBDA       0x07
#define __TYPE_THUNK        0x08


#define VDSO_USEFUL
#define VDSO_CGT_SYM "__vdso_clock_gettime"
#define VDSO_CGT_VER "LINUX_2.6"
#define VDSO_GETCPU_SYM "__vdso_getcpu"
#define VDSO_GETCPU_VER "LINUX_2.6"

#define IPC_64 0
