#include <iostream>

int main() {
// the ?: operator has a very low precedence. If doing anything other than assigning the result to a variable,
// the whole ?: operator also needs to be wrapped in parentheses.
    int x{4};
    int y{5};
    std::cout << ((x > y) ? x : y) << '\n';
    // if we don't parenthesize it:
    // this evaluates to (std::cout << (x > y)) ? x : y << '\n'; which returns true if x > y or false otherwise
    std::cout << (x > y) ? x : y << '\n';
}
