#include "CPU.h"
#include <ncurses.h>

uint8_t CPU::next(uint32_t* address, uint32_t* data, uint8_t i, uint8_t nmi, uint8_t r) {
    uint8_t imIns = BIT_TEST(instruction, 31, 0x1);
    uint8_t opcode = BIT_TEST(instruction, 26, 0xF);
    uint8_t regA = BIT_TEST(instruction, 21, 0x1F);
    uint8_t regB = BIT_TEST(instruction, 16, 0x1F);
    uint8_t regC = BIT_TEST(instruction, 0, 0x1F);
    int16_t immediate = BIT_TEST(instruction, 5, 0xFFFF);
    uint32_t boi = imIns ? immediate : registers[regB];
    uint32_t boo = imIns ? registers[1] + immediate : registers[regB];
    uint16_t control = 0;
    if (r) {
        interrupt = 0x80;
        intEnable = 0;
    }
    else if (nmi && !nmInterrupt) {
        interrupt = 0x82;
        intEnable = 0;
        nmInterrupt = 1;
    }
    else if (i && intEnable) {
        interrupt = 0x81;
        intEnable = 0;
    }
    if (!nmi && nmInterrupt) nmInterrupt = 0;
    if (step == 0) {
        if (interrupt) {
            *address = interrupt & 0xF;
            registers[9] = registers[1];
            intVector = 1;
        }
        else *address = registers[1];
    }
    else if (step == 1) {
        if (interrupt && intVector) {
            registers[1] = *data;
            instruction = 0;
            interrupt = 0;
            intVector = 0;
        }
        else {
            instruction = *data;
            registers[1]++;
        }
    }
    else if (BIT_TEST(instruction, 30, 1)) {
        registers[regA] = alu.execute(opcode & 0xF, registers[regC], boi, &carry);
        control |= 1;
    }
    else {
        control = decoder[(opcode << 1) | (step & 1)];
        if (BIT_TEST(control, 1, 1)) {
            interrupt = 0x83;
            intEnable = 0;
        }
        if (BIT_TEST(control, 2, 1)) *address = boo;
        if (BIT_TEST(control, 3, 1) && regA) registers[regA] = *data;
        if (BIT_TEST(control, 4, 1) && regA) registers[regA] = boi;
        if (BIT_TEST(control, 5, 1) && regA) registers[regA] = (boi << 16) | (registers[regA] & 0xFFFF);
        if (BIT_TEST(control, 6, 1)) *data = registers[regC];
        if ((BIT_TEST(control, 7, 1) && registers[regC] == 0) || 
            (BIT_TEST(control, 8, 1) && registers[regC] >> 31))
            registers[1] = boo;
        if (BIT_TEST(control, 9, 1)) carry = boi & 1;
        if (BIT_TEST(control, 10, 1)) intEnable = boi & 1;
    }
    step++;
    if (BIT_TEST(control, 0, 1)) {
        step = 0;
    }
    return BIT_TEST(control, 6, 1);
}