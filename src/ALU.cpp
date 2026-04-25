#include "ALU.h"

uint32_t ALU::execute(uint8_t opcode, uint32_t a, uint32_t b, uint8_t* carry) {
    uint32_t output = 0;

    switch (opcode) {
        case 0x0: // add
            *carry = _addcarry_u32(*carry, a, b, &output);
            break;
        case 0x1: // subtract
            *carry = _subborrow_u32(*carry, a, b, &output);
            break;
        case 0x2: // multiply
            output = (unsigned long)a * (unsigned long)b;
            break;
        case 0x3: // multiply high unsigned
            output = ((unsigned long)a * (unsigned long)b) >> 32;
            break;
        case 0x4: // multiply high signed
            output = ((long)((int)a) * (long)((int)b)) >> 32;
            break;
        case 0x5: // logical shift right
            output = a >> b;
            break;
        case 0x6: // logical shift left
            output = a << b;
            break;
        case 0x7: // arithmetic shift right
            output = ((int)a >> b);
            break;
        case 0x8: // and
            output = a & b;
            break;
        case 0x9: // or
            output = a | b;
            break;
        case 0xA: // xor
            output = a ^ b;
            break;
        case 0xB: // not
            output = ~a;
            break;
        default:
            break;
    }

    return output;
}