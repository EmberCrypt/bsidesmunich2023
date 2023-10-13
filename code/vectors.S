	.extern _main

	.align	4
	jr	_start # RESET

	.align	4
	jr	_dummy # SYSERR

	.align	4
	jr	_dummy # HVTRAP

	.align	4
	jr	_dummy # FETRAP

	.align	4
	jr	_dummy_EI # TRAP0

	.align	4
	jr	_dummy_EI # TRAP1

	.align	4
	jr	_dummy # RIE

	.align	4
	jr	_dummy_EI # FPP/FPI

	.align	4
	jr	_dummy # UCPOP

	.align	4
	jr	_dummy # MIP/MDP

	.align	4
	jr	_dummy # PIE

	.align	4
	jr	_dummy # Debug

	.align	4
	jr	_dummy # MAE

	.align	4
	jr	_dummy # (R.F.U)

	.align	4
	jr	_dummy # FENMI

	.align	4
	jr	_dummy # FEINT

	.align	4
	jr	_dummy_EI # INTn(priority0)

	.align	4
	jr	_dummy_EI # INTn(priority1)

	.align	4
	jr	_dummy_EI # INTn(priority2)

	.align	4
	jr	_dummy_EI # INTn(priority3)

	.align	4
	jr	_dummy_EI # INTn(priority4)

	.align	4
	jr	_dummy_EI # INTn(priority5)

	.align	4
	jr	_dummy_EI # INTn(priority6)

	.align	4
	jr	_dummy_EI # INTn(priority7)

	.align	4
	jr	_dummy_EI # INTn(priority8)

	.align	4
	jr	_dummy_EI # INTn(priority9)

	.align	4
	jr	_dummy_EI # INTn(priority10)

	.align	4
	jr	_dummy_EI # INTn(priority11)

	.align	4
	jr	_dummy_EI # INTn(priority12)

	.align	4
	jr	_dummy_EI # INTn(priority13)

	.align	4
	jr	_dummy_EI # INTn(priority14)

	.align	4
	jr	_dummy_EI # INTn(priority15)
	.align	4
.if 1
	.rept	4
	.word	_dummy_EI # INTn
	.endr
.endif
	.align	2
_dummy:
	br	_dummy

_dummy_EI:
	.word	0x014807e0

.equ	GLOBAL_RAM_ADDR,	0xFEE00000
.equ	GLOBAL_RAM_END,		0xFEE08000
.equ	LOCAL_RAM_ADDR,		0xFEDE0000
.equ	LOCAL_RAM_END,		0xFEDFFFFF

.equ	LOCAL_RAM_CPU_ADDR,	0xFEDD8000
.equ	LOCAL_RAM_CPU_END,	0xFEDDFFFF


.equ	STACK_P,		0xFEDEC000

_start:
	mov	r0, r1
	mov	r0, r2
	mov	r0, r3
	mov	r0, r4
	mov	r0, r5
	mov	r0, r6
	mov	r0, r7
	mov	r0, r8
	mov	r0, r9
	mov	r0, r10
	mov	r0, r11
	mov	r0, r12
	mov	r0, r13
	mov	r0, r14
	mov	r0, r15
	mov	r0, r16
	mov	r0, r17
	mov	r0, r18
	mov	r0, r19
	mov	r0, r20
	mov	r0, r21
	mov	r0, r22
	mov	r0, r23
	mov	r0, r24
	mov	r0, r25
	mov	r0, r26
	mov	r0, r27
	mov	r0, r28
	mov	r0, r29
	mov	r0, r30
	mov	r0, r31
	movhi	hi(STACK_P), r0, sp	
	movea	lo(STACK_P), sp, sp
	jarl	_hdwinit, lp 	# not strictly necessary - can skip if too time consuming
	jr	_main
_exit:
	halt


_hdwinit:
	mov	lp, r29			# save return address
	# Clear global RAM
	movhi	hi(GLOBAL_RAM_ADDR), r0, r6
	movea	lo(GLOBAL_RAM_ADDR), r6, r6
	movhi	hi(GLOBAL_RAM_END), r0, r7
	movea	lo(GLOBAL_RAM_END), r6, r7
	jarl	_zeroclr4, lp

	# clear Local RAM
	movhi	hi(LOCAL_RAM_ADDR), r0, r6
	movea	lo(LOCAL_RAM_ADDR), r6, r6
	movhi	hi(LOCAL_RAM_END), r0, r7
	movea	lo(LOCAL_RAM_END), r6, r7
	jarl	_zeroclr4, lp

	# clear Local RAM
	movhi	hi(LOCAL_RAM_CPU_ADDR), r0, r6
	movea	lo(LOCAL_RAM_CPU_ADDR), r6, r6
	movhi	hi(LOCAL_RAM_CPU_END), r0, r7
	movea	lo(LOCAL_RAM_CPU_END), r6, r7
	jarl	_zeroclr4, lp

	mov	r29, lp
	jmp	[lp]


_zeroclr4:
	br	.L.zeroclr4.2
.L.zeroclr4.1:
	st.w	r0, [0, r6]
	add	4, r6
.L.zeroclr4.2:
	cmp	r6, r7
	bh	.L.zeroclr4.1
	jmp	[lp]


