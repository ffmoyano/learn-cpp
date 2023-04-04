
// we could also use a constant-like macro with a fixed value, but it is discouraged because it can cause name conflicts with variables in code and is harder to debug
#define CONSTANT_MACRO 50

#include <iostream>

// when we pass by value we don't need to put const because the variable is going to be destroyed at the end of the function and it only adds clutter
// as they are going to be destroyed, declaring return type as const is also useless
const int stupid_const_by_value(const int value) {
    return value;
}


void constant_expression() {
    // if an expression can be evaluated at compile-time (all of its values are known at compile time) then it is a constant expression
    // this actually is processed at compile time like int x { 7 }
    int x{3 + 4};

    int y;
    std::cout << "Insert a value:\n";
    std::cin >> x;
    // this expression can't be known at compile time, therefore it will be evaluated at run time every time the program is run
    int z{x * 2};
    std::cout << z << '\n';
}

// A const variable is a compile-time constant if its initializer is a constant expression.
void compile_time_constant_vs_runtime_constant() {
    const int z{3};     // 3 is a constant expression, so z is compile-time const
    const int a{1 + 2}; // 1 + 2 is a constant expression, so a is compile-time const
    const int b{z * 2}; // z * 2 is a constant expression, so b is compile-time const
    std::cout << "Enter a number: ";
    int y{};
    std::cin >> y;
    const int h{y}; // is a runtime expression, as y cannot be known at compile time

    /*
     * constexpr keyword:
     * forces check if constant is at compile time, runtime constants give an error
     */
     constexpr int ca{5};        // OK
    // constexpr int ce {y};    // ERROR, as y is not known at compile time, this is a runtime constant, not accepted with the constexpr keyword
}

int main() {
    const double gravity{9.8};   // preferred way
    const int age{40};           // also valid but the other way is preferred

    // const int power;              error: a constant must be initialized as it's value cannot be assigned later
    const int power{age};         // consts can be initialized with other variables

    stupid_const_by_value(6);
    constant_expression();


}