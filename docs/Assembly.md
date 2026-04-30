NOP: No operation
BRK: Trigger software interrupt
LOD rA (rB/im): Load value at address from im offset or rB into rA
MOV rA (rB/im): Move im or rB to rA
MVU rA (rB/im): Move im or rB to upper half of rA
STR (rB/im) rC: Store rC to address from im offset or rB
BRZ (rB/im) rC: Branch if rC zero to address from im offset or rB
BRN (rB/im) rC: Branch if rC negative to address from im offset or rB
SEC (rB/im): Set carry to (rB/im)
SIE (rB/im): Set interrupt enabled to (rB/im)
ADD rA (rB/im) rC: Add (rB/im) to rC and put result in rA
SUB rA (rB/im) rC: Subtract (rB/im) from rC and put result in rA
MUL rA (rB/im) rC: Multiply (rB/im) with rC and put low 32 bits of result in rA
MHU rA (rB/im) rC: Multiply (rB/im) with rC unsigned and put high 32 bits of result in rA
MHS rA (rB/im) rC: Multiply (rB/im) with rC signed and put high 32 bits of result in rA
LSR rA (rB/im) rC: Logical shift rA right by (rB/im) and put result in rC
LSL rA (rB/im) rC: Logical shift rA left by (rB/im) and put result in rC
ASR rA (rB/im) rC: Arithmetic shift rA right by (rB/im) and put result in rC
AND rA (rB/im) rC: And (rB/im) with rC and put result in rA
ORR rA (rB/im) rC: Or (rB/im) with rC and put result in rA
XOR rA (rB/im) rC: Exclusive or (rB/im) with rC and put result in rA
NOT rA rC: Invert bits of rC and put result in rA