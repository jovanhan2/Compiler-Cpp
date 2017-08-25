int f (int a ) {
        int res;
        if ( a == 1 ) {
                return 1;
        }
        else {
                res = a + f( a - 1 );
        }

        return res;
}
	.file	1 "test.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	f
	.set	nomips16
	.set	nomicromips
	.ent	f
	.type	f, @function
f:
	.frame	$fp,40,$31		# vars= 8, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-40
	sw	$31,36($sp)
	sw	$fp,32($sp)
	move	$fp,$sp
	sw	$4,40($fp)
	lw	$3,40($fp)
	li	$2,1			# 0x1
	bne	$3,$2,$L2
	nop

	li	$2,1			# 0x1
	b	$L3
	nop

$L2:
	lw	$2,40($fp)
	addiu	$2,$2,-1
	move	$4,$2
	.option	pic0
	jal	f
	nop

	.option	pic2
	move	$3,$2
	lw	$2,40($fp)
	addu	$2,$3,$2
	sw	$2,28($fp)
	lw	$2,28($fp)
$L3:
	move	$sp,$fp
	lw	$31,36($sp)
	lw	$fp,32($sp)
	addiu	$sp,$sp,40
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	f
	.size	f, .-f
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.1) 5.4.0 20160609"
