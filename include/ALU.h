#pragma once

#include <cstdint>
#include <x86intrin.h>

class ALU {
    public:
        uint32_t execute(uint8_t opcode, uint32_t a, uint32_t b, uint8_t* carry);
};