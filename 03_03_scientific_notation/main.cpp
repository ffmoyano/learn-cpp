#include <iostream>

/*
 * Your exponent starts at zero.
 * Slide the decimal so there is only one non-zero digit to the left of the decimal.
 * Each place you slide the decimal to the left increases the exponent by 1.
 * Each place you slide the decimal to the right decreases the exponent by 1.
 * Trim off any leading zeros (on the left end of the significand)
 * Trim off any trailing zeros (on the right end of the significand) only if the original number had no decimal point. We’re assuming they’re not significant unless otherwise specified.
 */
int main() {
    int a = 4.203e4;        // 42030 -> 4 decimals to left -> e4, no leading zeros to trim, with the last trailing zero trimmed because the original number had no decimal point
    double b = 7.8900e-3;   // 0.0078900 -> 3 decimals to right -> e-3, trailing zeros not trimmed as the number had decimal points
    double c = 6.00410e2;   // 00600.410 -> 2 decimals to left -> leading zeros trimmed, trailing zeros not trimmed as the number had decimal points
    std::cout << "a is " << a << "\nb is " << b << "\nc is " << c << "\n";
}