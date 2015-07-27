	.arch armv4t
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 18, 4
	.file	"generate_assembly.c"
	.global	ANGLE_LIMIT
	.section	.rodata
	.align	2
	.type	ANGLE_LIMIT, %object
	.size	ANGLE_LIMIT, 4
ANGLE_LIMIT:
	.word	90
	.global	HALFPI1
	.align	2
	.type	HALFPI1, %object
	.size	HALFPI1, 4
HALFPI1:
	.word	25735
	.global	LOOKUP1
	.align	2
	.type	LOOKUP1, %object
	.size	LOOKUP1, 56
LOOKUP1:
	.word	12867
	.word	7595
	.word	4013
	.word	2036
	.word	1022
	.word	511
	.word	255
	.word	127
	.word	63
	.word	31
	.word	15
	.word	7
	.word	3
	.word	1
	.global	HALFPI2
	.align	2
	.type	HALFPI2, %object
	.size	HALFPI2, 4
HALFPI2:
	.word	51471
	.global	LOOKUP2
	.align	2
	.type	LOOKUP2, %object
	.size	LOOKUP2, 56
LOOKUP2:
	.word	25735
	.word	15192
	.word	8026
	.word	4074
	.word	2044
	.word	1023
	.word	511
	.word	255
	.word	127
	.word	63
	.word	31
	.word	15
	.word	7
	.word	3
	.global	SCALE_FACTOR
	.align	2
	.type	SCALE_FACTOR, %object
	.size	SCALE_FACTOR, 4
SCALE_FACTOR:
	.word	1058763998
	.text
	.align	2
	.global	int_cordic
	.type	int_cordic, %function
int_cordic:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 32
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #36
	str	r0, [fp, #-24]
	str	r1, [fp, #-28]
	str	r2, [fp, #-32]
	str	r3, [fp, #-36]
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L2
.L7:
	ldr	r3, [fp, #-32]
	ldr	r3, [r3, #0]
	cmp	r3, #0
	blt	.L3
	mov	r3, #1
	str	r3, [fp, #-16]
	b	.L4
.L3:
	mov	r3, #0
	str	r3, [fp, #-16]
.L4:
	ldr	r3, [fp, #-16]
	cmp	r3, #0
	beq	.L5
	ldr	r3, [fp, #-24]
	ldr	r1, [r3, #0]
	ldr	r3, [fp, #-28]
	ldr	r2, [r3, #0]
	ldr	r3, [fp, #-8]
	mov	r3, r2, asr r3
	rsb	r3, r3, r1
	str	r3, [fp, #-12]
	ldr	r3, [fp, #-28]
	ldr	r1, [r3, #0]
	ldr	r3, [fp, #-24]
	ldr	r2, [r3, #0]
	ldr	r3, [fp, #-8]
	mov	r3, r2, asr r3
	add	r2, r1, r3
	ldr	r3, [fp, #-28]
	str	r2, [r3, #0]
	ldr	r2, [fp, #-24]
	ldr	r3, [fp, #-12]
	str	r3, [r2, #0]
	ldr	r3, [fp, #-32]
	ldr	r1, [r3, #0]
	ldr	r3, [fp, #-8]
	mov	r2, r3, asl #2
	ldr	r3, [fp, #-36]
	add	r3, r3, r2
	ldr	r3, [r3, #0]
	rsb	r2, r3, r1
	ldr	r3, [fp, #-32]
	str	r2, [r3, #0]
	b	.L6
.L5:
	ldr	r3, [fp, #-24]
	ldr	r1, [r3, #0]
	ldr	r3, [fp, #-28]
	ldr	r2, [r3, #0]
	ldr	r3, [fp, #-8]
	mov	r3, r2, asr r3
	add	r3, r1, r3
	str	r3, [fp, #-12]
	ldr	r3, [fp, #-28]
	ldr	r1, [r3, #0]
	ldr	r3, [fp, #-24]
	ldr	r2, [r3, #0]
	ldr	r3, [fp, #-8]
	mov	r3, r2, asr r3
	rsb	r2, r3, r1
	ldr	r3, [fp, #-28]
	str	r2, [r3, #0]
	ldr	r2, [fp, #-24]
	ldr	r3, [fp, #-12]
	str	r3, [r2, #0]
	ldr	r3, [fp, #-32]
	ldr	r1, [r3, #0]
	ldr	r3, [fp, #-8]
	mov	r2, r3, asl #2
	ldr	r3, [fp, #-36]
	add	r3, r3, r2
	ldr	r3, [r3, #0]
	add	r2, r1, r3
	ldr	r3, [fp, #-32]
	str	r2, [r3, #0]
.L6:
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L2:
	ldr	r3, [fp, #-8]
	cmp	r3, #13
	ble	.L7
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
	.size	int_cordic, .-int_cordic
	.section	.rodata
	.align	2
.LC0:
	.ascii	"value: %d\000"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #24
	str	r0, [fp, #-24]
	str	r1, [fp, #-28]
	mov	r3, #600
	str	r3, [fp, #-8]
	mov	r3, #600
	str	r3, [fp, #-12]
	mov	r3, #712
	str	r3, [fp, #-16]
	sub	r3, fp, #8
	sub	r2, fp, #12
	sub	ip, fp, #16
	mov	r0, r3
	mov	r1, r2
	mov	r2, ip
	ldr	r3, .L11
	bl	int_cordic
	ldr	r3, [fp, #-16]
	ldr	r0, .L11+4
	mov	r1, r3
	bl	printf
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	ldmfd	sp!, {fp, lr}
	bx	lr
.L12:
	.align	2
.L11:
	.word	LOOKUP2
	.word	.LC0
	.size	main, .-main
	.ident	"GCC: (Sourcery G++ Lite 2008q3-72) 4.3.2"
	.section	.note.GNU-stack,"",%progbits
