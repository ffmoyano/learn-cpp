// instead of using forward declaration for multiple functions we can declare them in a header file (but we should not define their implementation)
#include "headers.h"
// difference from using <headername> and "headername" is that the one with angled brackets is not created by our source code but is external
#include <iostream>

// all user created headers should always have the .h extension.
// When using header files from the standard library prioritize the ones without the .h if they exist.

// always explicitly include all headers needed for a class to work, do not rely on a header including other headers
// (this could lead to duplicated declaration which is avoided with header guards, explained on the header file)

/*
 * order of includes of headers should be:
 * 1 - pair h file
 * 2 - other headers from project
 * 3 - third party headers
 * 4 - standard library headers
 * In each tier, they should appear alphabetically ordered
 */


int main() {
    std::cout << "Using headers\n";
    hello();  // this function is declared in the headers.h file and defined in this file in the function below
}

void hello() {
    std::cout << "Hello, world!";
}