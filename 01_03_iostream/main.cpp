// #include imports a library
#include <iostream>

int main() {
    int x; // uninitialized variable

    // we can't know what it will print, because
    std::cout << x << '\n';
}