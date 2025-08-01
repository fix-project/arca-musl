#ifndef _ARCA_ASM_H
#define _ARCA_ASM_H

// general runtime calls
#define __NR_nop 0
#define __NR_clone 1
#define __NR_drop 2
#define __NR_exit 3
#define __NR_type 4
#define __NR_get_argument 5

// constructors
#define __NR_create_null 6
#define __NR_create_word 7
#define __NR_create_atom 8
#define __NR_create_error 9
#define __NR_create_blob 10
#define __NR_create_tree 11
#define __NR_create_page 12
#define __NR_create_table 13
#define __NR_create_function 14

// consumers
#define __NR_read 15
#define __NR_write 16
#define __NR_equals 17
#define __NR_length 18
#define __NR_take 19
#define __NR_put 20
#define __NR_get 21
#define __NR_set 22
#define __NR_apply 23
#define __NR_map 24

// address space
#define __NR_mmap 25
#define __NR_mprotect 26

// control flow
#define __NR_call_with_current_continuation 27

// debug
#define __NR_debug_log 28
#define __NR_debug_log_int 29
#define __NR_debug_show 30
#define __NR_error_reset 31
#define __NR_error_append 32
#define __NR_error_append_int 33
#define __NR_error_return 34

#define __ERR_bad_syscall 0
#define __ERR_bad_index 1
#define __ERR_bad_type 2
#define __ERR_bad_argument 3
#define __ERR_out_of_memory 4
#define __ERR_interrupted 5

#define __TYPE_null 0
#define __TYPE_word 1
#define __TYPE_atom 2
#define __TYPE_exception 3
#define __TYPE_blob 4
#define __TYPE_tuple 5
#define __TYPE_page 6
#define __TYPE_table 7
#define __TYPE_function 8

#define __MODE_none 0
#define __MODE_read_only 1
#define __MODE_read_write 2

#endif
