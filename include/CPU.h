#pragma once

#include <cstdint>
#include "ALU.h"

#define BIT_TEST(value, index, mask) ((value >> index) & mask)

class CPU {
    public:
        uint8_t next(uint32_t* address, uint32_t* data, uint8_t i, uint8_t nmi, uint8_t r); // returns r/w
    private:
        ALU alu;
        uint32_t instruction = 0;
        uint32_t registers[32];

        uint8_t step = 0;

        uint32_t aluOut = 0;
        uint8_t carry = 0;
        uint8_t intEnable = 0;
        uint8_t interrupt = 0;
        uint8_t nmInterrupt = 0;
        uint8_t reset = 1;
        uint8_t intVector = 0;

        static inline uint16_t decoder[] = { 
            0b1, 0b1, 0b11, 0b1, 0b100, 0b1001, 0b10001, 0b1, 0b100001, 0b1, 0b1000101, 0b1, 
            0b10000001, 0b1, 0b100000001, 0b1, 0b1000000001, 0b1, 0b10000000001, 0b1, 0b1, 0b1, 
            0b1, 0b1, 0b1, 0b1, 0b1, 0b1, 0b1, 0b1, 0b1, 0b1
        };
};