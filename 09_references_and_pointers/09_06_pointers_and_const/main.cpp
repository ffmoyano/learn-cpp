#include <iostream>

int main()
{
// A pointer to a const value (sometimes called a pointer to const for short) is a (non-const) pointer that points to a constant value.
    const int x{5}; // x is now const
    // int* ptr { &x };   // compile error: cannot convert from const int* to int*
    const int* ptr{&x}; // okay: ptr is pointing to a "const int"
    // *ptr = 6; // not allowed: we can't change a const value
    const int y{6};
    ptr = &y; // okay: ptr now points at const int y

    // CONST POINTER -> Cannot be reset
    int z{ 5 };
    int* const ptr2 { &z }; // const after the asterisk means this is a const pointer
    // because the value being pointed to is non-const, it is possible to change the value being pointed to via dereferencing the const pointer:
    *ptr2 = 8; // now z is 8
    std::cout << z << '\n';


    // CONST POINTER TO CONST VALUE
    int value { 5 };
    const int* const ptr3 { &value }; // a const pointer to a const value
}
