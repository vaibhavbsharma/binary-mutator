.data

str:	
	.ascii "Hello world!"
newline:
	.ascii "\n"

.text
#.globl _start
#_start:
.globl main
main:
	mov	0(%rsp), %rax
	cmp	$2, %rax
	sete	str
	shlb	$1, str
	addb	$0x48, str
			
	mov	$1, %rdi
	mov	$str, %rsi
	mov	$12, %rdx
	mov	$1, %rax
	syscall

	mov	$newline, %rsi
	mov	$1, %rdx
	mov	$1, %rax
	syscall

	mov	$0, %rdi
	mov	$60, %rax
	syscall

	hlt
