#include <iostream>

// variable definition: allocates in memory a variable of the specified type
void variable_definition() {
    int x;
    // multiple variable definition of the same type in one line (DISCOURAGED)
    int y, z;
    // you can not specify more than one type in a one line multiple variable definition, even if it is the same type
    // int a, int b -> this is incorrect
    // int c, string d -> this is also incorrect
}

// variable assignment: gives a value to an already defined variable
void variable_assignment(int x) {
    x = 5;
}

// variable initialization: combines definition and assignment in one statement
void variable_initialization() {

    // variable initialization: combines definition and assignment in one statement
    int a;          // no initializer (default initialization) this leaves the variable with an undetermined value
    int b = 5;      // initializer after equals sign (copy initialization)
    int c(6);       // initializer in parentheses (direct initialization)

    // List initialization methods (C++ 11 and onwards)
    int d{7};    // initializer in braces (direct list initialization) -> PREFERRED WAY
    int e = {8};  // initializer in braces after equals sign (copy list initialization)
    int f{};       // initializer in empty braces (value initialization) -> initializes variable to its zero type value

    /*
     *list initialization doesn't allow narrowing conversions (i.e: double to int),
     * whereas copy and direct initialization allows them
     */
    int g = 9.5;        // allowed, being and int g takes the value 9
    // int h { 10.5 };  // not allowed

    // multiple variable initialization (ALSO DISCOURAGED)
    int h = 5, i = 6;          // copy initialization
    int j(7), k(8);        // direct initialization
    int l{9}, m{10};     // direct brace initialization (preferred)
    int n = {9}, o = {10}; // copy brace initialization
    int p{}, q{};            // value initialization

    int r, s = 5;              // this is bad, as only s is initialized, whereas r is left uninitialized
}

// attribute maybe_unused avoids warning or even error on some compilers when te variable is not used
void unused_variable() {
    [[maybe_unused]] int t{5};
}

int main() {

}