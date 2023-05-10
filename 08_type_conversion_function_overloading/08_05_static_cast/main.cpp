#include <iostream>

int main() {

    int x { 10 };
    int y { 4 };

    // c-style cast DISCOURAGED, prefer static cast
    double d { double(x) / y }; // convert x to a double so we get floating point division
    std::cout << d << '\n'; // prints 2.5


    // static cast x to a double so we get floating point division
    double e { static_cast<double>(x) / y };
    std::cout << e; // prints 2.5

    int i { 48 };

// explicit conversion from int to char, so that a char is assigned to variable ch
    char ch { static_cast<char>(i) };

}