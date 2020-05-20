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
