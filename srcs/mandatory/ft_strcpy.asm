section .text

global  ft_strcpy

ft_strcpy:
    mov rax, rdi         ; Save the original destination pointer

_loop:
    mov al, byte [rsi]   ; Load byte from source
    mov byte [rdi], al   ; Store byte to destination
    inc rsi
    inc rdi
    test al, al          ; Check for null terminator
    jne _loop

    ret                  ; Return pointer in RAX