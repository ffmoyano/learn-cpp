#include <iostream>

int main()
{
/*
 * The usual arithmetic conversion rules are pretty simple. The compiler has a prioritized list of types that looks something like this:
 * long double (highest)
 * double
 * float
 * unsigned long long
 * long long
 * unsigned long
 * long
 * unsigned int
 * int (lowest)
 * There are only two rules:
 *
 * If the type of at least one of the operands is on the priority list, the operand with lower priority is converted to the type of the operand with higher priority.
 * Otherwise (the type of neither operand is on the list), both operands are numerically promoted
 */

    int i{ 2 };
    double d{ 3.5 };
    std::cout << typeid(i + d).name() << ' ' << i + d << '\n'; // this shows that the type of i + d is double

}