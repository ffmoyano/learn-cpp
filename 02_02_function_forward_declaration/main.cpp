#include <iostream>

/*
 * in c++ you cannot the vertical declaration order of functions matters, therefore you cannot call a function
 * which hasn't been declared yet
 */

/*
 * we can use forward declaration which is declaring the function without define its implementation
 * Most often, forward declarations are used to tell the compiler about the existence of some function
 * that has been defined in a different code file. It can also be used to declare functions in an order
 * that maximizes understanding of the code.
 */
void forwarded_function();

void predefined_function() {

}

int main() {

// this function would give an error because the function has not been declared yet
// called_before_declared();

// this is ok, because the function has been already declared even if its implementation has not been defined
    forwarded_function();

// this is ok because the function has been defined before
    predefined_function();

}


void called_before_declared() {}

void forwarded_function() {

}