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


