#include "main.h"

// if the type is going to be used only in a file, define it in said file, otherwise define it in headers
// name it starting with a capital letter and without suffixes
struct Fraction
{
    int numerator {};
    int denominator {};
};  // don't forget semicolon or it will give error

// Now we can make use of our Fraction type
int main()
{
    Fraction f{ 3, 4 }; // this actually instantiates a Fraction object named f
    Fraction2 f2{2, 5};
}