/*
 * float	    minimum 4 bytes, usually 4 bytes
 * double	    minimum 8 bytes, usually 8 bytes
 * long double	minimum 8 bytes, usually 8, 12, or 16 bytes
 */

#include <iostream>
#include <iomanip>

/* Size         Range                               Precision
 * 4 bytes	    ±1.18 x 10-38 to ±3.4 x 1038	    6-9 significant digits, typically 7
 * 8 bytes	    ±2.23 x 10-308 to ±1.80 x 10308	    15-18 significant digits, typically 16
 * 16 bytes	    ±3.36 x 10-4932 to ±1.18 x 104932	33-36 significant digits
 */
int main() {
    // When using floating point literals, always include at least one decimal place (even if the decimal is 0)
    float a { 5.0f };   // f tells the compiler that this is a float
    double b { 5.0 };   // if f is not added as suffix the value is double by default -> PREFERRED DUE TO GREATER PRECISION

    /*
     * std::cout has a default precision of 6 -- that is, it assumes all floating point variables
     * are only significant to 6 digits (the minimum precision of a float), and hence it will truncate anything after that.
     */
    std::cout << 9.87654321f << '\n';       // prints 9.87654
    std::cout << 987.654321f << '\n';       // prints 987.654
    std::cout << 987654.321f << '\n';       // prints 987654
    std::cout << 9876543.21f << '\n';       // prints 9.87654e+006
    std::cout << 0.0000987654321f << '\n';  // prints 9.87654e-005

    // we can modify the precision of the std::count with the following statement
    std::cout << std::setprecision(16);
    std::cout << 3.33333333333333333333333333333333333333f <<'\n'; // f suffix means float, prints 3.333333253860474 -> the cout precision is 16, but the float precision is 6-9, so is more error-prone
    std::cout << 3.33333333333333333333333333333333333333 << '\n'; // no suffix means double, prints 3.333333333333333 -> PREFERRED due to larger precision

    // NAN AND INF
    double zero {0.0};
    double posinf { 5.0 / zero };   // positive infinity
    std::cout << posinf << '\n';

    double neginf { -5.0 / zero };  // negative infinity
    std::cout << neginf << '\n';

    double nan { zero / zero };     // not a number (mathematically invalid)
    std::cout << nan << '\n';
}