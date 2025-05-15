extern __errno_location

section .text

global ft_write ; Make the function accessible to C

ft_write:

	mov rax, 1        ; System call number for write
	syscall           ; Perform the system call

	cmp	rax, -4095
	jae	.error

	ret               ; Return to the caller

.error:

	mov     rbx, rax       ; rbx = error code (negative)
    neg     rbx            ; rbx = positive error number

    ; Get errno pointer
    call    __errno_location wrt ..plt ; 
    mov     [rax], ebx     ; store error code at *errno (32-bit)

    mov     rax, -1        ; return -1
    ret
