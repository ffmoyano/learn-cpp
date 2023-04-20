#include <iostream>

// the first word is the return type. Void means no return type.
void no_return_with_parameters(int x, int y) {
    std::cout << x * y << "\n";
}

// the returned result of a function which return something can be used directly in an expression
int use_return_in_expression(int x) {
    return x * 2;
}

/*
* main function returns by defaut a zero int (0), which can be omitted in code.
* This is the exit status of the program (0 is success). main cannot return void
*/
int main() {
    no_return_with_parameters(4, 5);
    std::cout << use_return_in_expression(6) << "\n";
}