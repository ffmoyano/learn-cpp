// the sizeof operator takes either a type or a variable and returns its size in bytes

#include <iostream>
// types have a minimum size in bytes, but can have larger sizes depending of the machine used
int main() {
    std::cout << "bool:\t\t" << sizeof(bool) << " bytes\n";                 // bool minimum size:           1 byte
    std::cout << "char:\t\t" << sizeof(char) << " bytes\n";                 // char always                  1 byte
    std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes\n";             // wchar_t minimum size:        1 byte
    std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes\n";           // char16_t minimum size:       2 bytes
    std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes\n";           // char32_t minimum size:       4 bytes
    std::cout << "short:\t\t" << sizeof(short) << " bytes\n";               // short minimum size:          2 bytes
    std::cout << "int:\t\t" << sizeof(int) << " bytes\n";                   // int minimum size:            2 bytes
    std::cout << "long:\t\t" << sizeof(long) << " bytes\n";                 // long minimum size:           4 bytes
    std::cout << "long long:\t" << sizeof(long long) << " bytes\n";         // long long minimum size:      8 bytes
    std::cout << "float:\t\t" << sizeof(float) << " bytes\n";               // float minimum size:          4 bytes
    std::cout << "double:\t\t" << sizeof(double) << " bytes\n";             // double minimum size:         8 bytes
    std::cout << "long double:\t" << sizeof(long double) << " bytes\n";     // long double minimum size:    8 bytes


    // sizeof can be used on variables too
    int my_var = 4;
    std:: cout << "\nmy_var:\t\t" << sizeof(my_var) << " bytes\n";
    return 0;
}