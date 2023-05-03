#include <iostream>

int main() {
    for (int i{0}; i <= 10; ++i) { // init-statement; condition; end-expression
        std::cout << i << '\n';
    }
    int j = 10;
    for (; j <= 20; ++j) {  // for without init statement
        std::cout << j << '\n';
    }

    for (; j <= 30;) { // for with only condition
        std::cout << j << '\n';
        ++j;
    }

    for (;; j++) {  // for with only end-expression
        std::cout << j << '\n';
        if (j >= 40) {
            break;
        }
    }

    for (int k{0}, l{10}; (k <= 10) || (l >= 0); ++k, --l) {  // we can use more than one variable in each section of the for loop
        std::cout << "K: " << k << " L: " << l << '\n';
    }

    for (;;) {  // infinite loop -> while (true) is preferred
        break;
    }

}