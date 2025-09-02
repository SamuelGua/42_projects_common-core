global ft_strcmp

; ft_strcmp(char *s1, char *s2)
; rdi -> s1
; rsi -> s2

ft_strcmp:
    xor rcx, rcx
    .loop:
        mov al, [rdi + rcx]
        mov bl, [rsi + rcx]
        cmp al, bl
        jnz .done
        inc rcx
        jmp .loop
    .done:
        sub al, bl
        movsx rax, al
        ret
    