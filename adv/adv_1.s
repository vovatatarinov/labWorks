	.file	"adv_1.c"
	.text
	.section	.rodata
.LC0:
	.string	"\nInput x: "
.LC1:
	.string	"%f"
.LC2:
	.string	"\nInput N: "
.LC3:
	.string	"%d"
	.align 8
.LC6:
	.string	"\ne^x from 0 to N: %.20f\ne^x by lib: %.20f\ne^x from N to 0: %.20f\n"
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
	subq	$80, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-56(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-52(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	pxor	%xmm0, %xmm0
	movss	%xmm0, -48(%rbp)
	movl	$0, -44(%rbp)
	jmp	.L2
.L5:
	movss	.LC5(%rip), %xmm0
	movss	%xmm0, -40(%rbp)
	movl	$1, -36(%rbp)
	jmp	.L3
.L4:
	cvtsi2ss	-36(%rbp), %xmm0
	movss	-40(%rbp), %xmm1
	mulss	%xmm1, %xmm0
	movss	%xmm0, -40(%rbp)
	addl	$1, -36(%rbp)
.L3:
	movl	-36(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jle	.L4
	cvtsi2sd	-44(%rbp), %xmm1
	movss	-56(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	call	pow@PLT
	movapd	%xmm0, %xmm1
	cvtss2sd	-40(%rbp), %xmm0
	divsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm3
	movss	%xmm3, -12(%rbp)
	movss	-48(%rbp), %xmm0
	addss	-12(%rbp), %xmm0
	movss	%xmm0, -48(%rbp)
	addl	$1, -44(%rbp)
.L2:
	movl	-52(%rbp), %eax
	cmpl	%eax, -44(%rbp)
	jle	.L5
	movss	-48(%rbp), %xmm0
	movss	%xmm0, -20(%rbp)
	pxor	%xmm0, %xmm0
	movss	%xmm0, -48(%rbp)
	movl	-52(%rbp), %eax
	movl	%eax, -32(%rbp)
	jmp	.L6
.L9:
	movss	.LC5(%rip), %xmm0
	movss	%xmm0, -28(%rbp)
	movl	$1, -24(%rbp)
	jmp	.L7
.L8:
	cvtsi2ss	-24(%rbp), %xmm0
	movss	-28(%rbp), %xmm1
	mulss	%xmm1, %xmm0
	movss	%xmm0, -28(%rbp)
	addl	$1, -24(%rbp)
.L7:
	movl	-24(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jle	.L8
	cvtsi2sd	-32(%rbp), %xmm1
	movss	-56(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	call	pow@PLT
	movapd	%xmm0, %xmm1
	cvtss2sd	-28(%rbp), %xmm0
	divsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm4
	movss	%xmm4, -16(%rbp)
	movss	-48(%rbp), %xmm0
	addss	-16(%rbp), %xmm0
	movss	%xmm0, -48(%rbp)
	subl	$1, -32(%rbp)
.L6:
	cmpl	$0, -32(%rbp)
	jns	.L9
	cvtss2sd	-48(%rbp), %xmm5
	movsd	%xmm5, -72(%rbp)
	movss	-56(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	call	exp@PLT
	movapd	%xmm0, %xmm1
	cvtss2sd	-20(%rbp), %xmm0
	movsd	-72(%rbp), %xmm2
	leaq	.LC6(%rip), %rdi
	movl	$3, %eax
	call	printf@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L11
	call	__stack_chk_fail@PLT
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC5:
	.long	1065353216
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
