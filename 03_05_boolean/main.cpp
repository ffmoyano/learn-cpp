#include <iostream>

int main() {
    bool b1 { true };
    bool b2 { false };
    bool b3 { !true };
    bool b4 { !false };
    std::cout << b1 << '\n';        // b is true, which evaluates to 1
    std::cout << !b1 << '\n';       // !b is false, which evaluates to 0

    std::cout << std::boolalpha;    // print booleans as true or false
    std::cout << b1 << '\n';        // now b1 prints true
    std::cout << !b1 << '\n';       // now b1 prints false
}