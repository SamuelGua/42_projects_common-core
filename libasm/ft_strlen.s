global ft_strlen

; ft_strlen(const char*)
; rdi -> str
ft_strlen:
        xor rcx, rcx
    .loop:
        cmp byte [rdi + rcx],0;
        je .done
        inc rcx
        jmp .loop
    .done:
        mov rax, rcx
        ret
