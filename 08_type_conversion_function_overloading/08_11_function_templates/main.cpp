#include <iostream>
#include "function_templates.h"

// max templates are included in the header file, Templates that are needed in
// multiple files should be defined in a header file, and then #included wherever needed

float max(float x, float y) {
    std::cout << "Accessing float function" << '\n';
    return (x < y) ? y : x;
}

int main() {
    std::cout << max<int>(1, 2) << '\n'; // instantiates and calls function max<int>(int, int)
    std::cout << max<double>(4.3, 2.4) << '\n';
    // template argument deduction
    std::cout << max<>(2.2f, 4.1f)
              << '\n'; // if we put <> it deducts which template function has to use, and discard non template functions
    std::cout << max(2.2f, 4.1f) << '\n'; // here it uses the float function because it is available

    std::cout << max(2, 4.3) << '\n';

    std::cout << min(2.1, 3) << '\n';

    print<5>();
}