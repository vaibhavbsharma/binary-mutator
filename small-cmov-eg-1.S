.data

onearg_str:     
        .ascii "argument"
multiarg_str:   
        .ascii "argments"
output_buf:
        .ascii "XXXXXXXX"
newline:
        .ascii "\n"

.text

exit:   mov     $60, %rax
        syscall
        ret

write:  mov     $1, %rax
        syscall
        ret


#.globl _start
#_start:
#       mov     0(%rsp), %rdi
#       mov     4(%rsp), %rsi
#       jmp     main

.globl main
main:
        mov     %rdi, %rax
        mov     multiarg_str, %rcx
        cmp     $2, %rax
        cmove   onearg_str, %ecx
        mov     %rcx, output_buf

        mov     $1, %rdi
        mov     $output_buf, %rsi
        mov     $8, %rdx
        call    write

        mov     $newline, %rsi
        mov     $1, %rdx
        call    write

        mov     $0, %rdi
        call    exit

        hlt
