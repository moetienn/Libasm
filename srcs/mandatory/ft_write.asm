section .text
    global ft_write ; Make the function accessible to C

ft_write:

    mov rax, 1        ; System call number for write
    syscall           ; Perform the system call
    ret               ; Return to the caller


