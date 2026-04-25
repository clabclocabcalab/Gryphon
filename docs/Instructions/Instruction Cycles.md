General:
1. PC(register[1]) to address
2. data to instruction register and increment PC
3. (Instruction specific)
4. reset step counter

Load:
1. register[B] or immediate to address
2. data to register[A]

Move:
1. register[B] or immediate to register[A]

Move Upper:
1. register[B] or immediate to upper 16 bits of register[A] without affecting lower

Store:
1. register[B] or immediate to address, register[A] to data, rw to 1

Branch Zero:
1. register[B] or immediate to PC if register[A] zero else no change

Branch Negative:
1. register[B] or immediate to PC if register[A] negative else no change

Set Carry:
1. register[B] or immediate to carry

Set Interrupt Enabled:
1. register[B] or immediate to interrupt enabled
