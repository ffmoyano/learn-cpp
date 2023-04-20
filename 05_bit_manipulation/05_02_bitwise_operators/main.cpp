#include <bitset>
#include <iostream>

void left_and_right_shift_operators() {

    std::bitset<4> x{ 0b1100 };

    std::cout << x << '\n';
    std::cout << (x >> 1) << '\n'; // shift right by 1, yielding 0110
    std::cout << (x << 1) << '\n'; // shift left by 1, yielding 1000
}

void bitwise_not() {
    // The bitwise NOT operator (~) converts 1 to 0 and viceversa.
    std::cout << ~std::bitset<4>{ 0b0100 } << '\n'; // This prints: 1011
    std::cout << ~std::bitset<8>{ 0b0100 } << '\n'; // This prints: 11111011
}

void bitwise_or() {
    // The bitwise OR operator (|) returns 1 in each bit if any of the operands is 1, or 0 otherwise.
    std::cout << (std::bitset<4>{0b0101} | std::bitset<4>{0b0110}) << '\n'; // this prints 0111

}

void bitwise_and() {
    // The bitwise AND operator (&) returns in each bit 1 if both operands are 1, or 0 otherwise
    std::cout << (std::bitset<4>{ 0b0101 } & std::bitset<4>{ 0b0110 }) << '\n'; // this prints 0100
}

void bitwise_xor() {
    // the bitwise XOR (^), also known as exclusive or, returns 1 if the operands are different (1 and 0) or 0
    // if they are identical (1 and 1 or 0 and 0).
    std::cout << (std::bitset<4>{ 0b0101 } ^ std::bitset<4>{ 0b0110 }) << '\n'; // this prints 0011
}

int main() {
    left_and_right_shift_operators();
    bitwise_not();
    bitwise_or();
    bitwise_and();
    bitwise_xor();
}
