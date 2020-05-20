.data
print_body0: .asciiz "First while a = %d, c = %c\n"
print_body2: .asciiz "Second while a = %d, c = %c\n"
print_body1: .asciiz "case 1 a = %d\n"
print_body3: .asciiz "default a = %d, c = %c\n"
print_body4: .asciiz "out a = %d, c = %c\n"
lol0: .asciiz "a"
a_1: .word 2
c_1: .asciiz "a"
t10: .asciiz " "
t11: .word 0
t12: .word 0
t13: .asciiz " "
t14: .asciiz " "
t4: .word 0
t5: .word 0
t6: .word 0
t7: .word 0
t8: .word 0
t9: .asciiz " "
x_3: .word 0
	.text
	.globl printf

printf:
	subu $sp, $sp, 36
	sw $ra, 32($sp)
	sw $fp, 28($sp)
	sw $s0, 24($sp)
	sw $s1, 20($sp)
	sw $s2, 16($sp)
	sw $s3, 12($sp)
	sw $s4, 8($sp)
	sw $s5, 4($sp)
	sw $s6, 0($sp)
	addu $fp, $sp, 36


	move $s0, $a0 
	move $s1, $a1
	move $s2, $a2
	move $s3, $a3

	li $s4, 0

	subu $sp, $sp, 36	
	move $s6, $sp


printf_loop: 
	lb $s5, 0($s0)
	addu $s0, $s0, 1 

	beq $s5, '%', printf_fmt 
	beq $0, $s5, printf_end 

printf_putc:
	sb $s5, 0($s6)
	sb $0, 1($s6)
	move $a0, $s6 
	li $v0, 4 
	syscall

	b printf_loop 

printf_fmt:
	lb $s5, 0($s0)
	addu $s0, $s0, 1
	beq $s4, 3, printf_invalidtag 
	beq $s5, 'd', printf_int
	beq $s5, 'c', printf_char
    beq $s5, 'f', printf_float 
	beq $s5, '%', printf_perc 

printf_invalidtag:
	sb $0, 2($s6) 
	sb $s5, 1($s6) 
	li $s5, '%'  
	sb $s5, 0($s6) 
	move $a0, $s6 
	li $v0, 4
	syscall
	b printf_loop 

printf_shift_args: 
	move $s1, $s2 
	move $s2, $s3 

	add $s4, $s4, 1 

	b printf_loop 


printf_shift_args_float: 
	mov.s $f0, $f1 
	mov.s $f2, $f3 

	add $s4, $s4, 1 

	b printf_loop 

printf_int: 
	move $a0, $s1 
	li $v0, 1
	syscall
	b printf_shift_args 

printf_float: 
	mov.s $f12, $f0 
	li $v0, 2
	syscall
	b printf_shift_args_float


printf_char:
	sb $s1, 0($s6) 
	sb $0, 1($s6)
	move $a0, $s6 
	li $v0, 4
	syscall
	b printf_shift_args

printf_perc: 
	li $s5, '%'
	sb $s5, 0($s6) 
	sb $0, 1($s6)
	move $a0, $s6
	li $v0, 4
	syscall
	b printf_loop 

printf_end:
	subu $sp, $fp, 36	
	lw $ra, 32($sp) 
	lw $fp, 28($sp)
	lw $s0, 24($sp)
	lw $s1, 20($sp)
	lw $s2, 16($sp)
	lw $s3, 12($sp)
	lw $s4, 8($sp)
	lw $s5, 4($sp)
	lw $s6, 0($sp)
	addu $sp, $sp, 36 
	jr $ra 
.globl main
main:
li $a0 0
sw $a0 a_1
lb $a0 lol0
sb $a0 c_1
l1 : 
lw $a0 a_1
sw $a0 0($sp)
addiu $sp $sp -4
li $a0 9
lw $t0 4($sp)
sub $a0 $t0 $a0
addiu $sp $sp 4
sw $a0 t4
lw $a0 t4
bge $a0 0 l2
la $a0 print_body0
lw $a1 a_1
lb $a2 c_1
jal printf
li $a0 1
sw $a0 0($sp)
addiu $sp $sp -4
lw $a0 a_1
lw $t0 4($sp)
sub $a0 $t0 $a0
addiu $sp $sp 4
sw $a0 t5
lw $a0 t5
bne $a0 0 l4
la $a0 print_body1
lw $a1 a_1
jal printf
li $a0 2
sw $a0 a_1
l6 : 
lw $a0 a_1
sw $a0 0($sp)
addiu $sp $sp -4
li $a0 7
lw $t0 4($sp)
sub $a0 $t0 $a0
addiu $sp $sp 4
sw $a0 t6
lw $a0 t6
bge $a0 0 l7
la $a0 print_body2
lw $a1 a_1
lb $a2 c_1
jal printf
lw $a0 a_1
sw $a0 t8
lw $a0 t8
sw $a0 0($sp)
addiu $sp $sp -4
li $a0 1
lw $t0 4($sp)
add $a0 $t0 $a0
addiu $sp $sp 4
sw $a0 a_1
lb $a0 c_1
sb $a0 t10
lb $a0 t10
sw $a0 0($sp)
addiu $sp $sp -4
li $a0 1
lw $t0 4($sp)
add $a0 $t0 $a0
addiu $sp $sp 4
sb $a0 c_1
b l6
l7 : 
b l3
b l5
l4 : 
l5 : 
la $a0 print_body3
lw $a1 a_1
lb $a2 c_1
jal printf
lw $a0 a_1
sw $a0 t12
lw $a0 a_1
sw $a0 t11
lw $a0 t12
sw $a0 0($sp)
addiu $sp $sp -4
li $a0 1
lw $t0 4($sp)
add $a0 $t0 $a0
addiu $sp $sp 4
sw $a0 a_1
lb $a0 c_1
sb $a0 t14
lb $a0 t14
sw $a0 0($sp)
addiu $sp $sp -4
li $a0 1
lw $t0 4($sp)
add $a0 $t0 $a0
addiu $sp $sp 4
sb $a0 c_1
b l3
l3 : 
b l1
l2 : 
la $a0 print_body4
lw $a1 a_1
lb $a2 c_1
jal printf
l0 : 
li $v0 10
syscall
