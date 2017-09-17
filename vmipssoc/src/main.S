#include "screen.h"
 #include "system.h"
.global clean
.data
array: .word 100,200,300,10,500,600,700,800,900,1000
x: .word 0 
y: .word 0 
 msg0:.asciz "X = " 
 msg1:.asciz ", Y = " 
 msg2:.asciz "\n" 
 msg3:.asciz "Add " 
 msg4:.asciz "\n" 
 msg5:.asciz "Sub " 
 msg6:.asciz "\n" 
 msg7:.asciz "Mul " 
 msg8:.asciz "\n" 
 msg9:.asciz "Div " 
 msg10:.asciz "\n" 
 msg11:.asciz "Mod " 
 msg12:.asciz "\n" 
total: .word 0 
count: .word 0 
number: .word 0 
 msg13:.asciz "Number [" 
 msg14:.asciz "] = " 
 msg15:.asciz "\n" 
 msg16:.asciz "The total is " 
 msg17:.asciz "\n" 
x1: .word 0 
y1: .word 0 
 msg18:.asciz "X = " 
 msg19:.asciz ", Y = " 
 msg20:.asciz "\n" 
 msg21:.asciz "X " 
 msg22:.asciz " is equal to Y " 
 msg23:.asciz " \n" 
 msg24:.asciz "X " 
 msg25:.asciz " is no equal to Y " 
 msg26:.asciz " \n" 
x2: .word 0 
y2: .word 0 
 msg27:.asciz "x = " 
 msg28:.asciz "\n" 
 msg29:.asciz "y = " 
 msg30:.asciz "\n" 
 msg31:.asciz "(x > y: " 
 msg32:.asciz ") " 
 msg33:.asciz "(x < y: " 
 msg34:.asciz " )" 
 msg35:.asciz "(x >= y: " 
 msg36:.asciz ") " 
 msg37:.asciz "(x <= y: " 
 msg38:.asciz " )" 
 msg39:.asciz "(x != y: " 
 msg40:.asciz ") " 
 msg41:.asciz "(x == y: " 
 msg42:.asciz ")\n " 
i: .word 0 
 msg43:.asciz "i = " 
 msg44:.asciz " " 
 msg45:.asciz " End of loop\n" 
a:.word 0 
b:.word 0 
mod: .word 0 
 msg46:.asciz "suma " 
 msg47:.asciz " \n" 
 msg48:.asciz "resta " 
 msg49:.asciz " \n" 
 msg50:.asciz "division " 
 msg51:.asciz " \n" 
 msg52:.asciz "mod " 
 msg53:.asciz " \n" 
 msg54:.asciz "or " 
 msg55:.asciz " \n" 
 msg56:.asciz "and " 
 msg57:.asciz " \n" 
 msg58:.asciz "xor " 
 msg59:.asciz " \n" 
 msg60:.asciz "corrimiento iz " 
 msg61:.asciz " \n" 
 msg62:.asciz "corrimiento de " 
 msg63:.asciz " \n" 

.text
 clean: 
li $a0, BRIGHT_WHITE
 li $a1, BLACK
jal set_color
 jal clear_screen
 jal main
 j .
 
Arimetico: 
addi $sp, $sp, -4
 sw $ra, ($sp)
 
 
li $t0, 50
sw $t0, x
li $t0, 23
sw $t0, y
la $t0, msg0
move $a0, $t0
jal puts
lw $t0, x
move $a0, $t0
jal put_udecimal
la $t0, msg1
move $a0, $t0
jal puts
lw $t0, y
move $a0, $t0
jal put_udecimal
la $t0, msg2
move $a0, $t0
jal puts
la $t0, msg3
move $a0, $t0
jal puts
lw $t0, x
lw $t1, y
add $t0, $t0, $t1
move $a0, $t0
jal put_udecimal
la $t0, msg4
move $a0, $t0
jal puts
la $t0, msg5
move $a0, $t0
jal puts
lw $t0, x
lw $t1, y
sub $t0, $t0, $t1
move $a0, $t0
jal put_udecimal
la $t0, msg6
move $a0, $t0
jal puts
la $t0, msg7
move $a0, $t0
jal puts
lw $t0, x
lw $t1, y
 move $a0, $t0
move $a1, $t1
jal mult 
move $t0, $v0 
move $a0, $t0
jal put_udecimal
la $t0, msg8
move $a0, $t0
jal puts
la $t0, msg9
move $a0, $t0
jal puts
lw $t0, x
lw $t1, y
 move $a0, $t0
move $a1, $t1
jal divide 
move $t0, $t1 
move $a0, $t0
jal put_udecimal
la $t0, msg10
move $a0, $t0
jal puts
la $t0, msg11
move $a0, $t0
jal puts
lw $t0, x
lw $t1, y
 move $a0, $t0
move $a1, $t1
jal divide 
move $t0, $a0 
move $a0, $t0
jal put_udecimal
la $t0, msg12
move $a0, $t0
jal puts
lw $ra, ($sp)
 addi $sp, $sp, 4
jr $ra
WhileTest: 
addi $sp, $sp, -4
 sw $ra, ($sp)
 
 
 
li $t0, 0
sw $t0, total
li $t0, 0
sw $t0, count
while0:
	lw $t0, count
slti $t0, $t0, 3
	 beqz $t0, .endWhile0 
li $t1, 12

lw $t2, number
add $t1, $t1, $t2
sw $t1, number
la $t1, msg13
move $a0, $t1
jal puts
lw $t1, count
move $a0, $t1
jal put_udecimal
la $t1, msg14
move $a0, $t1
jal puts
lw $t1, number
move $a0, $t1
jal put_udecimal
la $t1, msg15
move $a0, $t1
jal puts
lw $t1, count
addi $t1, $t1, 1
sw $t1, count
lw $t1, total
lw $t2, number
add $t1, $t1, $t2
sw $t1, total
	 j while0 
.endWhile0: 
la $t0, msg16
move $a0, $t0
jal puts
lw $t0, total
move $a0, $t0
jal put_udecimal
la $t0, msg17
move $a0, $t0
jal puts
lw $ra, ($sp)
 addi $sp, $sp, 4
jr $ra
IfTest: 
addi $sp, $sp, -4
 sw $ra, ($sp)
 
 
li $t1, 32
addi $t0, $t1, 100
sw $t0, x1
li $t1, 43
addi $t0, $t1, 100
sw $t0, y1
la $t0, msg18
move $a0, $t0
jal puts
lw $t0, x1
move $a0, $t0
jal put_udecimal
la $t0, msg19
move $a0, $t0
jal puts
lw $t0, y1
move $a0, $t0
jal put_udecimal
la $t0, msg20
move $a0, $t0
jal puts
if0: 
	lw $t0, x1
lw $t1, y1
beq $t0, $t1, igualEQ0 
li $t0,0 
j finEQ0 
igualEQ0: 
li $t0,1 
finEQ0: 
	 beqz $t0, .else0 
la $t1, msg21
move $a0, $t1
jal puts
lw $t1, x1
move $a0, $t1
jal put_udecimal
la $t1, msg22
move $a0, $t1
jal puts
lw $t1, y1
move $a0, $t1
jal put_udecimal
la $t1, msg23
move $a0, $t1
jal puts
	 j .endif0 
.else0:
la $t0, msg24
move $a0, $t0
jal puts
lw $t0, x1
move $a0, $t0
jal put_udecimal
la $t0, msg25
move $a0, $t0
jal puts
lw $t0, y1
move $a0, $t0
jal put_udecimal
la $t0, msg26
move $a0, $t0
jal puts
	 j .endif0 
.endif0: 
lw $ra, ($sp)
 addi $sp, $sp, 4
jr $ra
Relacionales: 
addi $sp, $sp, -4
 sw $ra, ($sp)
 
 
li $t0, 100
li $t1, 22
 move $a0, $t0
move $a1, $t1
jal divide 
move $t0, $t1 
sw $t0, x2
li $t0, 100
li $t1, 52
 move $a0, $t0
move $a1, $t1
jal divide 
move $t0, $t1 
sw $t0, y2
la $t0, msg27
move $a0, $t0
jal puts
lw $t0, x2
move $a0, $t0
jal put_udecimal
la $t0, msg28
move $a0, $t0
jal puts
la $t0, msg29
move $a0, $t0
jal puts
lw $t0, y2
move $a0, $t0
jal put_udecimal
la $t0, msg30
move $a0, $t0
jal puts
la $t0, msg31
move $a0, $t0
jal puts
lw $t0, x2
lw $t1, y2
slt $t0, $t1, $t0
move $a0, $t0
jal put_udecimal
la $t0, msg32
move $a0, $t0
jal puts
la $t0, msg33
move $a0, $t0
jal puts
lw $t0, x2
lw $t1, y2
slt $t0, $t0, $t1
move $a0, $t0
jal put_udecimal
la $t0, msg34
move $a0, $t0
jal puts
la $t0, msg35
move $a0, $t0
jal puts
lw $t0, x2
lw $t1, y2
beq $t0, $t1, igualGTE0 
sub $t0, $t0, $t1
slt $t0, $zero, $t0 
bne $t0, $zero , igualGTE0 
li $t0, 0 
j finGTE0 
igualGTE0: 
li $t0, 1 
finGTE0: 
move $a0, $t0
jal put_udecimal
la $t0, msg36
move $a0, $t0
jal puts
la $t0, msg37
move $a0, $t0
jal puts
lw $t0, x2
lw $t1, y2
beq $t0, $t1, igualLTE0 
sub $t0, $t1, $t0
slt $t0, $zero, $t0 
bne $t0, $zero, igualLTE0 
li $t0, 0 
j finLTE0 
igualLTE0: 
li $t0, 1 
finLTE0: 
move $a0, $t0
jal put_udecimal
la $t0, msg38
move $a0, $t0
jal puts
la $t0, msg39
move $a0, $t0
jal puts
lw $t0, x2
lw $t1, y2
xor $t0, $t1, $t0
slt $t0, $zero, $t0 
move $a0, $t0
jal put_udecimal
la $t0, msg40
move $a0, $t0
jal puts
la $t0, msg41
move $a0, $t0
jal puts
lw $t0, x2
lw $t1, y2
beq $t0, $t1, igualEQ1 
li $t0,0 
j finEQ1 
igualEQ1: 
li $t0,1 
finEQ1: 
move $a0, $t0
jal put_udecimal
la $t0, msg42
move $a0, $t0
jal puts
lw $ra, ($sp)
 addi $sp, $sp, 4
jr $ra
ForTest: 
addi $sp, $sp, -4
 sw $ra, ($sp)
 
li $t0, 0
sw $t0, i
for0: 
lw $t0, i
li $t1, 10
beq $t0, $t1, igualLTE1 
sub $t0, $t1, $t0
slt $t0, $zero, $t0 
bne $t0, $zero, igualLTE1 
li $t0, 0 
j finLTE1 
igualLTE1: 
li $t0, 1 
finLTE1: 
	 beqz $t0, .endFor0 
la $t2, msg43
move $a0, $t2
jal puts
lw $t2, i
move $a0, $t2
jal put_udecimal
la $t2, msg44
move $a0, $t2
jal puts
lw $t1, i
addi $t2, $t1, 1 
sw $t2, i
	 j for0 
.endFor0: 
la $t2, msg45
move $a0, $t2
jal puts
lw $ra, ($sp)
 addi $sp, $sp, 4
jr $ra


gcd: 
sw $a0, a 
sw $a1, b 
addi $sp, $sp, -4
 sw $ra, ($sp)
 
if1: 
	lw $t3, b
li $t4, 0
beq $t3, $t4, igualEQ2 
li $t3,0 
j finEQ2 
igualEQ2: 
li $t3,1 
finEQ2: 
	 beqz $t3, .else1 
lw $t4, a
 move $v0 ,$t4
jr $ra 
	 j .endif1 
.else1:
lw $t3, a
lw $t4, b
 move $a0, $t3
move $a1, $t4
jal divide 
move $t3, $a0 
sw $t3, mod
 lw $t3, b
move $a0, $t3 
lw $t3, mod
move $a1, $t3 
jal gcd 
move $t3, $v0
 move $v0 ,$t3
jr $ra 
	 j .endif1 
.endif1: 
lw $ra, ($sp)
 addi $sp, $sp, 4
jr $ra
autosuma: 
addi $sp, $sp, -4
 sw $ra, ($sp)
li $t3, 10

li $t6, 0
sll $t6, $t6, 2
la $t4, array
add $t4, $t4, $t6
lw $t5, ($t4)
add $t3, $t3, $t5
sw $t3, ($t4) 
 la $t3, msg46
move $a0, $t3
jal puts
la $t3, array
li $t4, 0
sll $t4, $t4, 2
add $t3, $t4, $t3
lw $t3, ($t3)
move $a0, $t3
jal put_udecimal
la $t3, msg47
move $a0, $t3
jal puts
li $t3, 10
li $t6, 1
sll $t6, $t6, 2
la $t4, array
add $t4, $t4, $t6
lw $t5, ($t4)
sub $t3, $t5, $t3
sw $t3, ($t4) 
 la $t3, msg48
move $a0, $t3
jal puts
la $t3, array
li $t4, 1
sll $t4, $t4, 2
add $t3, $t4, $t3
lw $t3, ($t3)
move $a0, $t3
jal put_udecimal
la $t3, msg49
move $a0, $t3
jal puts
li $t3, 10
li $t6, 2
sll $t6, $t6, 2
la $t4, array
add $t4, $t4, $t6
lw $t5, ($t4)
move $a0, $t5
move $a1, $t3
move $s0, $t4
jal divide
sw $t1, ($s0) 
 la $t3, msg50
move $a0, $t3
jal puts
la $t3, array
li $t4, 2
sll $t4, $t4, 2
add $t3, $t4, $t3
lw $t3, ($t3)
move $a0, $t3
jal put_udecimal
la $t3, msg51
move $a0, $t3
jal puts
li $t3, 10
li $t6, 4
sll $t6, $t6, 2
la $t4, array
add $t4, $t4, $t6
lw $t5, ($t4)
move $a0, $t5
move $a1, $t3
move $s0, $t4
jal divide
sw $a0, ($s0) 
 la $t3, msg52
move $a0, $t3
jal puts
la $t3, array
li $t4, 4
sll $t4, $t4, 2
add $t3, $t4, $t3
lw $t3, ($t3)
move $a0, $t3
jal put_udecimal
la $t3, msg53
move $a0, $t3
jal puts
li $t3, 10
li $t6, 5
sll $t6, $t6, 2
la $t4, array
add $t4, $t4, $t6
lw $t5, ($t4)
or $t3, $t3, $t5
sw $t3, ($t4) 
 la $t3, msg54
move $a0, $t3
jal puts
la $t3, array
li $t4, 5
sll $t4, $t4, 2
add $t3, $t4, $t3
lw $t3, ($t3)
move $a0, $t3
jal put_udecimal
la $t3, msg55
move $a0, $t3
jal puts
li $t3, 10
li $t6, 6
sll $t6, $t6, 2
la $t4, array
add $t4, $t4, $t6
lw $t5, ($t4)
and $t3, $t3, $t5
sw $t3, ($t4) 
 la $t3, msg56
move $a0, $t3
jal puts
la $t3, array
li $t4, 6
sll $t4, $t4, 2
add $t3, $t4, $t3
lw $t3, ($t3)
move $a0, $t3
jal put_udecimal
la $t3, msg57
move $a0, $t3
jal puts
li $t3, 10
li $t6, 7
sll $t6, $t6, 2
la $t4, array
add $t4, $t4, $t6
lw $t5, ($t4)
xor $t3, $t3, $t5
sw $t3, ($t4) 
 la $t3, msg58
move $a0, $t3
jal puts
la $t3, array
li $t4, 7
sll $t4, $t4, 2
add $t3, $t4, $t3
lw $t3, ($t3)
move $a0, $t3
jal put_udecimal
la $t3, msg59
move $a0, $t3
jal puts
li $t3, 1
li $t6, 8
sll $t6, $t6, 2
la $t4, array
add $t4, $t4, $t6
lw $t5, ($t4)
sll $t3, $t5, $t3
sw $t3, ($t4) 
 la $t3, msg60
move $a0, $t3
jal puts
la $t3, array
li $t4, 8
sll $t4, $t4, 2
add $t3, $t4, $t3
lw $t3, ($t3)
move $a0, $t3
jal put_udecimal
la $t3, msg61
move $a0, $t3
jal puts
li $t3, 1
li $t6, 9
sll $t6, $t6, 2
la $t4, array
add $t4, $t4, $t6
lw $t5, ($t4)
srl $t3, $t5, $t3
sw $t3, ($t4) 
 la $t3, msg62
move $a0, $t3
jal puts
la $t3, array
li $t4, 9
sll $t4, $t4, 2
add $t3, $t4, $t3
lw $t3, ($t3)
move $a0, $t3
jal put_udecimal
la $t3, msg63
move $a0, $t3
jal puts
lw $ra, ($sp)
 addi $sp, $sp, 4
jr $ra
main: 
addi $sp, $sp, -4
 sw $ra, ($sp)
 jal Arimetico 
 jal WhileTest 
 jal ForTest 
 jal autosuma 
 jal IfTest 
 jal Relacionales 
lw $ra, ($sp)
 addi $sp, $sp, 4
jr $ra


j .
