#include "ALU.h"

uint32_t ALU::execute(uint8_t opcode, uint32_t a, uint32_t b, uint8_t carryIn, uint8_t* carryOut) {
    uint32_t output = 0;

    switch (opcode) {
        default:
            break;
        case 0x4: // and
            output = a & b;
            break;
        case 0x5: // or
            output = a | b;
            break;
        case 0x6: // xor
            output = a ^ b;
            break;
        case 0x7: // not
            output = ~a;
            break;
        case 0x8: // add
            *carryOut = _addcarry_u32(carryIn, a, b, &output);
            break;
        case 0x9: // subtract
            *carryOut = _subborrow_u32(carryIn, a, b, &output);
            break;
        case 0xA: // multiply
            output = (unsigned long)a * (unsigned long)b;
            break;
        case 0xB: // multiply high unsigned
            output = ((unsigned long)a * (unsigned long)b) >> 32;
            break;
        case 0xC: // multiply high signed
            output = ((long)((int)a) * (long)((int)b)) >> 32;
            break;
        case 0xD: // logical shift right
            output = a >> b;
            break;
        case 0xE: // logical shift left
            output = a << b;
            break;
        case 0xF: // arithmetic shift right
            output = ((int)a >> b);
            break;
    }

    return output;
}