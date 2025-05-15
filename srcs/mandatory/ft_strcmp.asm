section .text

global ft_strcmp

ft_strcmp:

    mov rax, 0              ; Initialize RAX to 0 (to store the result)

_loop: 
    mov al, byte [rdi]      ; Load the byte from the first string into AL
    mov bl, byte [rsi]      ; Load the byte from the second string into BL
    cmp al, bl              ; Compare the two bytes
    jne _return             ; If not equal, jump to return
    test al, al             ; Check if we reached the null terminator
    je _return              ; If null, strings are equal, jump to return
    inc rdi                 ; Increment the pointer to the first string
    inc rsi                 ; Increment the pointer to the second string
    jmp _loop               ; Repeat the loop

_return:
    sub rax, rbx            ; Calculate the difference between the two characters
    ret                     ; Return the result