section .text

global ft_strlen ; Make the function accessible to C

ft_strlen:
    mov rax, -1

_loop:
	inc rax						; RAX++
	cmp byte[rdi + rax], 0		; compare the current byte of the string (character) to null terminator (0) 
	jne _loop					; Jump to _loop if not equal

_return:
    ret                 ; Return the length in RAX