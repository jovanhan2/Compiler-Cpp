========================================
 Cleaning the temporaries and outputs
rm src/*.o
rm bin/*
rm src/*.tab.cpp
rm src/*.yy.cpp
rm working/*
 Force building compiler (just in case)
g++  -std=c++11 -W -Wall -g -Wno-unused-parameter -I include  -c -o src/print_assembly.o src/print_assembly.cpp
bison -v -d src/parser.y -o src/parser.tab.cpp
g++  -std=c++11 -W -Wall -g -Wno-unused-parameter -I include  -c -o src/parser.tab.o src/parser.tab.cpp
bison -v -d src/parser.y -o src/parser.tab.cpp
flex -o src/lexer.yy.cpp  src/lexer.flex
g++  -std=c++11 -W -Wall -g -Wno-unused-parameter -I include  -c -o src/lexer.yy.o src/lexer.yy.cpp
mkdir -p bin
g++ -std=c++11 -W -Wall -g -Wno-unused-parameter -I include -o bin/c_compiler src/print_assembly.o src/parser.tab.o src/lexer.yy.o
============================================================================================

Input file : INPUTS/99test.c
Testing 99test.c, [1th test]

===========================INPUT 99test.c===========================
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

===========================OUTPUT 99test.c===========================
.globl f
.ent f
.type f, @function
f: 

addiu $sp, $sp, -100 #Allocate 25 bytes
sw $31,96($sp)
sw $fp, 92($sp) #Old frame pointer 2 blocks down 
move $fp, $sp
#Storing params $7-$4
sw $4, 100($fp)

#Declarations (saved to stack)

# (Dec) varID :res type :int
lw $8, 88($fp)
#In loop, type : ifelse
#In primitive: a
lw $24, 100($fp)
#In num: 1
li $25, 1
bne $24, $25, __Equal__1
nop

#Return statement
#In num: 1
li $26, 1
li $2, 1
b __Return__2
b __ElseJump__3
__Equal__1:

#Normal statment
#id : res opCode : =

lw $9, 88($fp)

#Operator
#In primitive: a
lw $10, 100($fp)
#Function Call

#Operator
#In primitive: a
lw $10, 100($fp)
#In num: 1
li $11, 1
subu $11, $10, $11
move $4, $11
jal f
nop
addu $2, $10, $2
sw $2, 88($fp)
__ElseJump__3: 

#Return statement
#In primitive: res
lw $3, 88($fp)
move $2, $3
__Return__2:

#End function
move $sp, $fp
lw $31,96($sp)
lw $fp, 92($sp) #Load old frame pointer 2 blocks down
addiu $sp, $sp, 100  #Release 25 bytes from stack
j $31 #Return
nop #Delay slot 
.end f
#End function f


============================================================================================

Input file : INPUTS/mytest.s
Testing mytest.s, [2th test]

===========================INPUT mytest.s===========================

===========================OUTPUT mytest.s===========================
============================================================================================

Input file : INPUTS/test.s
Testing test.s, [3th test]

===========================INPUT test.s===========================
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

===========================OUTPUT test.s===========================
