extern malloc
extern __errno_location
extern ft_strlen
extern ft_strcpy
global ft_strdup

; char *strdup(const char *s);
; rdi -> s

ft_strdup:
; pour calculer la taille de la chaine
        call ft_strlen; size of string -> rax
        mov r8,  rdi
        mov rdi, rax
        add rdi, 1

; Allocation de memoire, si erreur, set errno
        call malloc wrt ..plt; allocate memory
        cmp rax, 0
        je .done_errno

; copie la chaine 
        mov rdi , rax
        mov rsi, r8
        call ft_strcpy
        ret
    .done_errno:
        mov rdi, rax
        call __errno_location wrt ..plt
        xor rax, rax
        ret



