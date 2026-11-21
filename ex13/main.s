	.file	"main.c"
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "Global runs: %lu\12\0"
.LC1:
	.ascii "local_value = %d\12\0"
.LC2:
	.ascii "inferred_value = %d\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	call	device_tick
	movq	.refptr.global_runs(%rip), %rax
	movl	(%rax), %eax
	leaq	.LC0(%rip), %rcx
	movl	%eax, %edx
	call	__mingw_printf
	movl	$304, -4(%rbp)
	movl	-4(%rbp), %eax
	leaq	.LC1(%rip), %rcx
	movl	%eax, %edx
	call	__mingw_printf
	movl	$304, -8(%rbp)
	movl	-8(%rbp), %eax
	leaq	.LC2(%rip), %rcx
	movl	%eax, %edx
	call	__mingw_printf
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (GNU) 16.2.0"
	.def	device_tick;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr.global_runs, "dr"
	.p2align	3, 0
	.globl	.refptr.global_runs
	.linkonce	discard
.refptr.global_runs:
	.quad	global_runs
