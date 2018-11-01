	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_cread
	.align	4, 0x90
_cread:                                 ## @cread
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	xorl	%eax, %eax //well, I suppose this is you clearing your register (set equal to 0)?
	testq	%rdi, %rdi //this is you testing x
	je	LBB0_2 // if x==0?
## BB#1:
	movq	(%rdi), %rax //right, now this is probably your v = *xp
LBB0_2:
	popq	%rbp
	retq //the expected return instruction
	.cfi_endproc


.subsections_via_symbols
