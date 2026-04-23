#include <iostream>
#include "ALU.h"

using namespace std;

int main() {
    ALU alu;
    uint8_t carry = 0;
    uint32_t a = 15;
    uint32_t b = -1;

    cout << (int)alu.execute(0xA, a, b, carry, &carry) << endl;

    return 0;
}