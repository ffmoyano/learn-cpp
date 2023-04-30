#include <iostream>

int main() {
    int a = 7;
    if (a > 5) {
        std::cout << "greater than 5\n";
    } else {
        std::cout << "less or equal than 5\n";
    }

    if (a > 6)
        std::cout << "When the if or else statement contains inside only one statement, brackets can be ommited, but it is not recommended.\n";
}