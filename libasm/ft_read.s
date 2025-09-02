section .text
    global ft_read
    extern __errno_location

; ssize_t read(int fd, void buf[.count], size_t count);
; rdi -> fd
; rsi -> buf
; rdx -> count

_errno:
    mov rdi, rax
    call __errno_location  wrt ..plt
    mov rax, -1
    ret

ft_read:
        mov rax, 0
        syscall
        cmp rax, -1
        je _errno
    .done:
        ret