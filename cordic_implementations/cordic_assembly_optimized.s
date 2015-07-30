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
	.file	"cordic_assembly_optimized.c"
	.section	.rodata
	.align	2
	.type	local_elem_angle.1122, %object
	.size	local_elem_angle.1122, 56
local_elem_angle.1122:
	.word	2949120
	.word	1740967
	.word	919789
	.word	466945
	.word	234379
	.word	117304
	.word	58666
	.word	29335
	.word	14668
	.word	7334
	.word	3667
	.word	1833
	.word	917
	.word	458
	.text
	.align	2
	.global	cordic_assembly_optimized
	.type	cordic_assembly_optimized, %function
cordic_assembly_optimized:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 40
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #44
	@ Store pointers for x, y, z and mode
	str	r0, [fp, #-32]
	str	r1, [fp, #-36]
	str	r2, [fp, #-40]
	str	r3, [fp, #-44]
	ldr	r3, [fp, #-32]
	ldr	r3, [r3, #0]
	str	r3, [fp, #-12]
	ldr	r3, [fp, #-36]
	ldr	r3, [r3, #0]
	str	r3, [fp, #-24]
	ldr	r3, [fp, #-40]
	ldr	r3, [r3, #0]
	str	r3, [fp, #-28]
	@ Check mode
	ldr	r3, [fp, #-44]
	cmp	r3, #0
	bne	.L2
	@ Set z_local
	sub	r3, fp, #28
	str	r3, [fp, #-20]
	b	.L3
@ Set y_local
.L2:
	sub	r3, fp, #24
	str	r3, [fp, #-20]

@ x_local = x_local << 16;
@ y_local = y_local << 16;
@ z_local = z_local << 16;
.L3:
	ldr	r3, [fp, #-12]
	mov	r3, r3, asl #16
	str	r3, [fp, #-12]
	ldr	r3, [fp, #-24]
	mov	r3, r3, asl #16
	str	r3, [fp, #-24]
	ldr	r3, [fp, #-28]
	mov	r3, r3, asl #16
	str	r3, [fp, #-28]
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L4
.L9:
	ldr	r3, [fp, #-12]
	str	r3, [fp, #-16]
	ldr	r3, [fp, #-20]
	ldr	r3, [r3, #0]
	cmp	r3, #0
	bge	.L5
	ldr	r3, [fp, #-44]
	cmp	r3, #0
	beq	.L6
.L5:
	ldr	r3, [fp, #-20]
	ldr	r3, [r3, #0]
	cmp	r3, #0
	blt	.L7
	ldr	r3, [fp, #-44]
	cmp	r3, #0
	beq	.L7
@ Rotation mode with negative value
.L6:	
	ldr	r4, [fp, #-12]
	ldr	r5, [fp, #-24]
	ldr	r6, [fp, #-28]
	ldr 	r7, [fp, #-16]
	ldr	r8, [fp, #-8]
	ldr	r2, [fp, #-24]
	mov 	r2, r2, asr r8
	add 	r4, r4, r2
	mov	r7, r7, asr r8
	rsb	r5, r7, r5		
	ldr	r3, .L11
	ldr	r2, [r3, r8, asl #2]
	add	r6, r2, r6
	str	r4, [fp, #-12]
	str	r5, [fp, #-24]
	str	r6, [fp, #-28]
	b	.L8
@ Rotation mode with positive value OR Vectoring mode
.L7:

	ldr	r4, [fp, #-12]
	ldr	r5, [fp, #-24]
	ldr	r6, [fp, #-28]
	ldr 	r7, [fp, #-16]
	ldr	r8, [fp, #-8]
	ldr 	r2, [fp, #-24]
	mov	r2, r2, asr r8
	rsb	r4, r2, r4
	mov	r7, r7, asr r8
	add	r5, r7, r5
	ldr	r1, [fp, #-28]
	ldr	r2, [fp, #-8]
	ldr	r3, .L11
	ldr	r3, [r3, r8, asl #2]
	rsb	r6, r3, r6
	str	r4, [fp, #-12]
	str	r5, [fp, #-24]
	str	r6, [fp, #-28]
@ Increment loop counter
.L8:
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]

@ Forloop : for (int i = 0; i < 14; i++)
.L4:
	ldr	r3, [fp, #-8]
	cmp	r3, #13
	ble	.L9
	ldr	r2, [fp, #-32]
	ldr	r3, [fp, #-12]
	str	r3, [r2, #0]
	ldr	r2, [fp, #-24]
	ldr	r3, [fp, #-36]
	str	r2, [r3, #0]
	ldr	r2, [fp, #-28]
	ldr	r3, [fp, #-40]
	str	r2, [r3, #0]
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
.L12:
	.align	2
.L11:
	.word	local_elem_angle.1122
	.size	cordic_assembly_optimized, .-cordic_assembly_optimized
	.ident	"GCC: (Sourcery G++ Lite 2008q3-72) 4.3.2"
	.section	.note.GNU-stack,"",%progbits
