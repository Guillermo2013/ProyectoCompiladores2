#include "screen.h"
 #include "system.h"
.global clean
.data
array: .word 32,12,3,58,75,218,12,4,2,1
 msg0:.asciz "array[" 
 msg1:.asciz "]== " 
 msg2:.asciz " \n" 

.text
 clean: 
li $a0, BRIGHT_WHITE
 li $a1, BLACK
jal set_color
 jal clear_screen
 jal main
 j .
 
autosuma: 
addi $sp, $sp, -24
sw $ra, ($sp)
 li $t0, 0
sw $t0, 4($sp)

 li $t0, 0
sw $t0, 8($sp)

 li $t0, 1
sw $t0, 12($sp)

 li $t0, 0
sw $t0, 16($sp)

 li $t0, 10
sw $t0, 20($sp)

while1:
	lw $t0, 12($sp)
lw $t1, 20($sp)
beq $t0, $t1, igualLTE0 
sub $t0, $t1, $t0
slt $t0, $zero, $t0 
bne $t0, $zero, igualLTE0 
li $t0, 0 
j finLTE0 
igualLTE0: 
li $t0, 1 
finLTE0: 
	 beqz $t0, .endWhile1 
li $t1, 0
sw $t1, 16($sp)
while0:
	lw $t1, 16($sp)
lw $t2, 20($sp)
addi $t2, $t2, -1
slt $t1, $t1, $t2
	 beqz $t1, .endWhile0 
if0: 
	la $t2, array
lw $t3, 16($sp)
sll $t3, $t3, 2
add $t2, $t3, $t2
lw $t2, ($t2)
la $t3, array
lw $t4, 16($sp)
addi $t4, $t4, 1
sll $t4, $t4, 2
add $t3, $t4, $t3
lw $t3, ($t3)
slt $t2, $t3, $t2
	 beqz $t2, .else0 
la $t3, array
lw $t4, 16($sp)
sll $t4, $t4, 2
add $t3, $t4, $t3
lw $t3, ($t3)
sw $t3, 4($sp)
la $t3, array
lw $t4, 16($sp)
addi $t4, $t4, 1
sll $t4, $t4, 2
add $t3, $t4, $t3
lw $t3, ($t3)
lw $t5, 16($sp)
la $t4, array
sll $t5, $t5, 2
add $t4, $t4, $t5
sw $t3, ($t4) 
 lw $t3, 4($sp)
lw $t5, 16($sp)
addi $t5, $t5, 1
la $t4, array
sll $t5, $t5, 2
add $t4, $t4, $t5
sw $t3, ($t4) 
 	 j .endif0 
.else0:
	 j .endif0 
.endif0: 
lw $t2, 16($sp)
addi $t3, $t2, 1 
sw $t3, 16($sp)
	 j while0 
.endWhile0: 
lw $t1, 12($sp)
addi $t2, $t1, 1 
sw $t2, 12($sp)
	 j while1 
.endWhile1: 
li $t0, 0
sw $t0, 16($sp)
while2:
	lw $t0, 16($sp)
lw $t1, 20($sp)
slt $t0, $t0, $t1
	 beqz $t0, .endWhile2 
la $t1, msg0
move $a0, $t1
jal puts
lw $t1, 16($sp)
move $a0, $t1
jal put_udecimal
la $t1, msg1
move $a0, $t1
jal puts
la $t1, array
lw $t2, 16($sp)
sll $t2, $t2, 2
add $t1, $t2, $t1
lw $t1, ($t1)
move $a0, $t1
jal put_udecimal
la $t1, msg2
move $a0, $t1
jal puts
lw $t1, 16($sp)
addi $t2, $t1, 1 
sw $t2, 16($sp)
	 j while2 
.endWhile2: 
.epilogo0:
 lw $ra, ($sp)
 addi $sp, $sp,24
jr $ra
main: 
addi $sp, $sp, -4
sw $ra, ($sp)
 jal autosuma 
.epilogo1:
 lw $ra, ($sp)
 addi $sp, $sp,4
jr $ra


j .
