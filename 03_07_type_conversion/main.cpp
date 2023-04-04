
#include <iostream>

void implicit_conversion() {
    int i = 5;
    // the value of i es int pero al asignar a d que es double, se crea un nuevo valor double con el valor de i
    double d = i;
}

void explicit_casting() {
    int j = 5;
    // the static_cast operator
    std::cout << static_cast<int>(5.5) * 5;  // 5 * 5 = 25
}

int main() {
    implicit_conversion();
    explicit_casting();
}