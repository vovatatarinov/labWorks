	.file	"cos.c"
	.text
	.globl	normalize_x
	.type	normalize_x, @function
normalize_x:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movsd	%xmm0, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	movsd	.LC0(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -16(%rbp)
	movsd	-16(%rbp), %xmm0
	cvttsd2siq	%xmm0, %rax
	movq	%rax, -8(%rbp)
	movsd	-16(%rbp), %xmm0
	addsd	%xmm0, %xmm0
	movsd	.LC1(%rip), %xmm1
	mulsd	%xmm1, %xmm0
	movq	-8(%rbp), %rax
	addq	%rax, %rax
	cvtsi2sdq	%rax, %xmm1
	movsd	.LC1(%rip), %xmm2
	mulsd	%xmm2, %xmm1
	subsd	%xmm1, %xmm0
	movsd	%xmm0, -16(%rbp)
	movsd	-16(%rbp), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	normalize_x, .-normalize_x
	.globl	factorial
	.type	factorial, @function
factorial:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	cmpl	$0, -20(%rbp)
	jne	.L4
	movsd	.LC2(%rip), %xmm0
	jmp	.L5
.L4:
	movsd	.LC2(%rip), %xmm0
	movsd	%xmm0, -8(%rbp)
	movl	$1, -12(%rbp)
	jmp	.L6
.L7:
	cvtsi2sd	-12(%rbp), %xmm0
	movsd	-8(%rbp), %xmm1
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	addl	$1, -12(%rbp)
.L6:
	movl	-12(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jle	.L7
	movsd	-8(%rbp), %xmm0
.L5:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	factorial, .-factorial
	.globl	x_n
	.type	x_n, @function
x_n:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -4(%rbp)
	movsd	%xmm0, -16(%rbp)
	cvtsi2sd	-4(%rbp), %xmm0
	movq	.LC3(%rip), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	call	pow@PLT
	movsd	%xmm0, -24(%rbp)
	movl	-4(%rbp), %eax
	addl	%eax, %eax
	cvtsi2sd	%eax, %xmm0
	movq	-16(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -32(%rbp)
	movsd	-32(%rbp), %xmm0
	call	pow@PLT
	movapd	%xmm0, %xmm2
	mulsd	-24(%rbp), %xmm2
	movsd	%xmm2, -24(%rbp)
	movl	-4(%rbp), %eax
	addl	%eax, %eax
	movl	%eax, %edi
	call	factorial
	movsd	-24(%rbp), %xmm2
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	x_n, .-x_n
	.section	.rodata
.LC4:
	.string	"\nInput x: "
.LC5:
	.string	"%lf"
.LC6:
	.string	"\nInput epsilon: "
.LC9:
	.string	"cosinus is %lf\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movq	-24(%rbp), %rax
	movq	%rax, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	call	normalize_x
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -16(%rbp)
	movl	$0, -36(%rbp)
	jmp	.L11
.L12:
	movq	-24(%rbp), %rdx
	movl	-36(%rbp), %eax
	movq	%rdx, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	movl	%eax, %edi
	call	x_n
	movapd	%xmm0, %xmm1
	movsd	-16(%rbp), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -16(%rbp)
	addl	$1, -36(%rbp)
.L11:
	movq	-24(%rbp), %rax
	movl	-36(%rbp), %edx
	addl	$1, %edx
	movq	%rax, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	movl	%edx, %edi
	call	x_n
	movsd	%xmm0, -56(%rbp)
	movq	-24(%rbp), %rdx
	movl	-36(%rbp), %eax
	movq	%rdx, -64(%rbp)
	movsd	-64(%rbp), %xmm0
	movl	%eax, %edi
	call	x_n
	movsd	-56(%rbp), %xmm2
	subsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	movq	.LC8(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	-32(%rbp), %xmm1
	ucomisd	%xmm1, %xmm0
	ja	.L12
	movq	-16(%rbp), %rax
	movq	%rax, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	leaq	.LC9(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L14
	call	__stack_chk_fail@PLT
.L14:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	1413754136
	.long	1075388923
	.align 8
.LC1:
	.long	1413754136
	.long	1074340347
	.align 8
.LC2:
	.long	0
	.long	1072693248
	.align 8
.LC3:
	.long	0
	.long	-1074790400
	.align 16
.LC8:
	.long	4294967295
	.long	2147483647
	.long	0
	.long	0
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
