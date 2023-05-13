#include <iostream>


int main() {
    const int x{5}; // x is a non-modifiable (const) lvalue
// int& ref { x }; // error: ref can not bind to non-modifiable lvalue
    const int &ref{x}; // okay: ref is a lvalue reference to a const value

    const int &ref2{5}; // The temporary object holding value 5 has its lifetime extended to match ref
    std::cout << ref << '\n'; // Therefore, we can safely use it here
}