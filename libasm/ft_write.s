section .text
    global ft_write
    extern __errno_location


; ssize_t write(int fd, const void buf[.count], size_t count);
; rdi fd
; rsi buf
; rdx count

_errno:
    mov rdi, rax
    call __errno_location wrt ..plt
    mov rax, -1
    ret

ft_write:
        mov rax, 1
        syscall
        cmp rax, -1
        je _errno
    .done:
        ret
