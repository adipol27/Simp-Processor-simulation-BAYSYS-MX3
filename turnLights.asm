add $s0, $zero, $imm, 75	# $s0 holds the IOreg value on the next LED change.
add $s1, $zero, $zero		# $s1 holds the pressing count of the BTNC.
add $s2, $zero, $zero		# $s2 = 0 for left movement and 1 for right movement.
add $a0, $zero, $imm, 1		# $a0 holds the bin value 00000001.
add $a1, $zero, $imm, 128	# $a1 holds the bin value 10000000.
add $v0, $zero, $imm, 1		# $v0 holds the LEDs state.
reserved $v0, $imm, $a0, 1		# turn on the first LED.
beq $imm, $zero, $zero, LEFTANYWAY

MOVELEFT:
sll $v0, $v0, $imm, 1
reserved $v0, $imm, $a0, 1
reserved $s1, $imm, $zero, 2	# save button pressings
bne $imm, $v0, $a1, WAIT5SEC

RIGHTANYWAY:
reserved $t0, $zero, $zero		# $t0 holds IORegister[0] value
bgt $imm, $s0, $t0, RIGHTANYWAY
add $s0, $s0, $imm, 80
add $s2, $zero, $imm, 1
beq $imm, $zero, $zero, MOVERIGHT

MOVERIGHT:
sra $v0, $v0, $imm, 1
reserved $v0, $imm, $a0, 1
reserved $s1, $imm, $zero, 2	# save button pressings
bne $imm, $v0, $a0, WAIT5SEC

LEFTANYWAY:
reserved $t0, $zero, $zero		# $t0 holds IORegister[0] value
bgt $imm, $s0, $t0, LEFTANYWAY
add $s0, $s0, $imm, 80
add $s2, $zero, $zero
beq $imm, $zero, $zero, MOVELEFT

WAIT5SEC:
reserved $t0, $zero, $zero		# $t0 holds IORegister[0] value
bgt $imm, $s0, $t0, WAIT5SEC
add $s0, $s0, $imm, 80
add $t1, $s1, $zero
reserved $s1, $imm, $zero, 2		# load again IORegister[2] to $s1
sub $t1, $s1, $t1
and $t1, $t1, $imm, 1
beq $imm, $t1, $zero, LASTLABEL
beq $imm, $s2, $zero, CHANGETORIGHT
add $s2, $zero, $zero
beq $imm, $s2, $zero, MOVELEFT

CHANGETORIGHT:
add $s2, $zero, $imm, 1
beq $imm, $zero, $zero, MOVERIGHT

LASTLABEL:
beq $imm, $s2, $zero, MOVELEFT
beq $imm, $zero, $zero, MOVERIGHT
