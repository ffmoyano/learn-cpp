#include <cmath>
#include <iostream>

int main() {
    /*
     * the result of std::pow is a double, if you want to make potency of integers that result in an integer,
     * implement your own function, but be wary that the result may overflow the integer type.
     */
    double x{ std::pow(3.0, 4.0) };
    std::cout << x << '\n';
}
