global ft_strcpy

; char *strcpy(char* dst, const char *src);
; rdi -> dst
; rsi -> src

ft_strcpy:
    xor rcx, rcx
    .loop:
        cmp byte [rsi + rcx], 0
        jz .done
        mov al,  [rsi + rcx]
        mov [rdi + rcx], al
        inc rcx
        jmp .loop
    .done:
        mov rax, rdi
        ret
