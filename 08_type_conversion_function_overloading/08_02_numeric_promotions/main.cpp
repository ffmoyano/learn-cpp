#include <iostream>

// NUMERIC PROMOTIONS CONVERT NARROW DATA TYPES TO WIDER DATA TYPES.

void printDouble(double d)
{
    std::cout << d << '\n';
}

void printInt(int x)
{
    std::cout << x << '\n';
}

int main()
{
    // FLOATING POINT PROMOTIONS
    printDouble(5.0); // no conversion necessary
    printDouble(4.0f); // numeric promotion of float to double

    // INTEGRAL PROMOTIONS
    /*
     * signed char or signed short can be converted to int.unsigned char, char8_t, and unsigned short can be converted
     * to int if int can hold the entire range of the type, or unsigned int otherwise. If char is signed by default, it
     * follows the signed char conversion rules above. If it is unsigned by default, it follows the unsigned char conversion
     * rules above. bool can be converted to int, with false becoming 0 and true becoming 1.
     */
    printInt(2);

    short s{ 3 };
    printInt(s); // numeric promotion of short to int

    printInt('a'); // numeric promotion of char to int
    printInt(true); // numeric promotion of bool to int

}