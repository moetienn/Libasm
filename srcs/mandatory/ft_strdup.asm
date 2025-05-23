section .text

global  ft_strdup

extern  malloc

ft_strdup:
	mov		rax, -1
	mov 	rbx, rdi            ; Save original src pointer in rbx
	xor 	rcx, rcx            ; rcx = 0 (counter)

.strlen_loop:
	inc 	rax
	cmp		byte[rbx + rax], 0
	jne 	.strlen_loop

	inc		rax 
	mov 	rdi, rax
	call	malloc wrt ..plt
	test	rax, rax
	je		.return_null

	mov		rsi, rbx
	mov		rdi, rax
	xor		rcx, rcx

.copy_loop
	mov		bl, byte[rsi + rcx]
	mov 	byte[rdi + rcx], bl
	inc		rcx
	cmp		bl, 0
	jne		.copy_loop

	mov		rax, rdi
	ret

.return_null
	xor		rax, rax
	ret
	
