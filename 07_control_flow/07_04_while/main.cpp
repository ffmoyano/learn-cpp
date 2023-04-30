#include <iostream>

int main() {
    // don't use unsigned int in loops, as it could lead to unexpected results,
    // when comparing to >= 0, as an unsigned integer never is less than 0.
    int a = 0;
    // infinite loop
    while(true) {
        std::cout << "infinite loop: " << ++a << '\n';
        if(a >= 50) {
            break;
        }
    }

    while(a < 100) {
        std::cout << "normal loop: " << ++a << '\n';
    }

    do {
        std::cout << "do while loop: " << ++a << '\n';
    } while (a < 1);  // do while always occurs at least one time, even it the condition is never fulfilled
}