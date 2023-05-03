#include <iostream>

void cleanup() {
    std::cout << "Bye!\n";
}

int main() {

    // std::atexit runs the specified method (which must not have parameters) when std::exit is called
    // multiple std::atexit can be registered, and they will be run in reverse order of declaration
    std::atexit(cleanup);

    // exits the program, this is called implicitly at the end of the main method
    // explicit use is DISCOURAGED because does not clean up any local variables
    // (either in the current function, or in functions up the call stack. Exceptions are preferred
    std::exit(0);  // thanks to std::atexit, cleanup() is called here
}