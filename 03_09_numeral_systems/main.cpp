#include <iostream>
#include <bitset>

int main() {


    int decimal{12};        // an int is decimal by default
    int octal{014};         // prefix: 0 to make it octal. Octal is not used much
    int hexadecimal{0xC};   // prefix: 0x to make it hexadecimal
    int binary{0b1100};     // prefix: 0b to make it binary (C++ 14 onwards)

    std::cout << "Value 12 in different numerical systems:\n";
    std::cout << std::dec;  // this is the default output, it's not necessary if it has not been changed previously
    std::cout << "Decimal: " << decimal << "\n";
    std::cout << std::oct;  // changes the output to octal type
    std::cout << "Octal: " << octal << "\n";
    std::cout << std::hex;  // changes the output to hexadecimal type
    std::cout << "Hexadecimal: " << hexadecimal << "\n";
    // there is no such thing as std::bin;
    // To output in binary we need to declare a std::bitset<n>, where n is the number of bits stored, which must be known at compile time
    std::bitset<8> bin1{0b0000'1100};
    std::cout << "Binary: " << bin1 << "\n";

    // digit separator: quotation mark(') -> C++ 14 onwards
    int bin{0b1011'0010};       // assign binary 1011 0010 to the variable
    long value{2'132'673'462};  // assign decimal  2132673462 to variable

    // int bin { 0b'1011'0010 };  // error: ' used before first digit of value
    // long value{'2'132'673'462};   // error: ' used before first digit of value
}