section .text

global ft_read
extern __errno_location

ft_read:
    mov     rax, 0          ; syscall number for read
    syscall                 ; perform the syscall

    cmp     rax, 0
    jge     .done           ; if rax >= 0, no error

    ; error handling
    neg     rax             ; make error code positive
    mov     rdi, rax
    call    __errno_location wrt ..plt
    mov     [rax], edi      ; set errno
    mov     rax, -1         ; return -1
.done:
    ret