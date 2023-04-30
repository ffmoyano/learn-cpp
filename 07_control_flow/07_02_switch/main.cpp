#include <iostream>

void switch_break() {
    std::cout << "BREAK: \n";
    int a = 3;
    switch (a) {
        case 1:
            std::cout << "1\n";
            break;
        case 2:
            std::cout << "2\n";
            break;
        case 3:
            std::cout << "3\n";
            break;
        default:
            std::cout << "other\n";
    }
    std::cout << "Printed after break\n";
}

void switch_return() {
    std::cout << "RETURN: \n";
    int a = 3;
    switch (a) {
        case 1:
            std::cout << "1\n";
            return;
        case 2:
            std::cout << "2\n";
            return;
        case 3:
            std::cout << "3\n";
            return;
        default:
            std::cout << "other\n";
    }
    std::cout << "This doesn't print as return ends the method execution";
}

void switch_fallthrough() {
    std::cout << "FALLTHROUGH: \n";
    int a = 3;
    switch (a) {
        case 1:
            std::cout << "1\n";
        case 2:
            std::cout << "2\n";
        case 3:
            std::cout << "3\n";
            [[fallthrough]];    // By default if neither break nor return is used, the case will fall into the next one.
            // with the [[fallthrough]] attribute we indicate the compiler that this is intended.
        default:
            std::cout << "other\n";
    }
    std::cout << "Printed after default";
}

int main() {
    switch_break();
    switch_return();
    switch_fallthrough();
}