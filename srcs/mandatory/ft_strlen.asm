section .text

global ft_strlen ; Make the function accessible to C

ft_strlen:
    mov rax, -1

_loop:
	inc rax						; increment rax to 0
	cmp byte[rdi + rax], 0		; compare the current src char to 0
	jne _loop					; start the loop again if not the end

_return:
    ret                 ; Return the length in RAX