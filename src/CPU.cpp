#include "CPU.h"
#include <iostream>

uint8_t CPU::next(uint32_t* address, uint32_t* data, uint8_t i, uint8_t nmi) {
    uint8_t imIns = BIT_TEST(instruction, 31, 0x1);
    uint8_t opcode = BIT_TEST(instruction, 26, 0xF);
    uint8_t regA = BIT_TEST(instruction, 21, 0x1F);
    uint8_t regB = BIT_TEST(instruction, 16, 0x1F);
    uint8_t regC = BIT_TEST(instruction, 0, 0x1F);
    uint16_t immediate = BIT_TEST(instruction, 5, 0xFFFF);
    uint32_t boi = imIns ? immediate : registers[regB];
    uint16_t control = 0;

    if (step == 0) {
        *address = registers[1];
    }
    else if (step == 1) {
        instruction = *data;
        registers[1]++;
    }
    else if (BIT_TEST(instruction, 30, 1)) {
        registers[regC] = alu.execute(opcode & 0xF, registers[regA], boi, &carry);
    }
    else {
        control = decoder[(opcode << 1) | (step & 1)];
        if (BIT_TEST(control, 1, 1)) *address = boi;
        if (BIT_TEST(control, 2, 1) && regA) registers[regA] = *data;
        if (BIT_TEST(control, 3, 1) && regA) registers[regA] = boi;
        if (BIT_TEST(control, 4, 1) && regA) registers[regA] = (boi << 16) | (registers[regA] & 0xFFFF);
        if (BIT_TEST(control, 5, 1)) *data = registers[regA];
        if (BIT_TEST(control, 6, 1) && registers[regA] == 0) registers[1] = boi;
        if (BIT_TEST(control, 7, 1) && registers[regA] >> 31) registers[1] = boi;
        if (BIT_TEST(control, 8, 1)) carry = boi & 1;
        if (BIT_TEST(control, 9, 1)) intEnable = boi & 1;
    }
    step++;
    if (BIT_TEST(control, 0, 1)) {
        step = 0;
        if (i && intEnable && !interrupt) {
            registers[9] = registers[1];
            registers[1] = registers[8];
            interrupt = 1;
            intEnable = 0;
        }
        if (intEnable && interrupt) interrupt = 0;
    }
    return BIT_TEST(control, 5, 1);
}