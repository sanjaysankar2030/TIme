	.file	"main.c"
	.text
	.section	.rodata
.LC1:
	.string	"test chunk"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -52(%rbp)
	movq	%rsi, -64(%rbp)
	movl	$0, %eax
	call	initVM@PLT
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	initPile@PLT
	movq	.LC0(%rip), %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	addConst@PLT
	movl	%eax, -4(%rbp)
	leaq	-48(%rbp), %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	writePile@PLT
	movl	-4(%rbp), %eax
	movzbl	%al, %ecx
	leaq	-48(%rbp), %rax
	movl	$1, %edx
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	writePile@PLT
	leaq	-48(%rbp), %rax
	movl	$1, %edx
	movl	$1, %esi
	movq	%rax, %rdi
	call	writePile@PLT
	leaq	-48(%rbp), %rax
	leaq	.LC1(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	disassemblePile@PLT
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	interpret@PLT
	movl	$0, %eax
	call	freeVM@PLT
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	freepile@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	858993459
	.long	1072902963
	.ident	"GCC: (Debian 12.2.0-14+deb12u1) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
