/*
 * directives start with a # and end with a newline without semicolon
 * before compilation, the cpp preprocessor replaces the include directive with the included file content
 */
#include "iostream"

// directive define to create macros

// you can define macros with a text but it is DISCOURAGED as that functionality can be done with constants
#define MY_NAME "Fernando"

// you can define macros without text to achieve condicional compilation
#define HUNGRY

int main() {
    std::cout << MY_NAME;  // prints Fernando

#ifdef HUNGRY   // the code inside is compiled because HUNGRY is defined
    std::cout << "Me is hungry";
#endif

#ifdef SATED    // this code is not compiled because SATED is not defined
    std::cout << "Me not hungry";
#endif

#ifndef SATED   // this cocde is compiled because SATED is not defined (ifndef, not ifdef)
    std::cout << "Sated";
#endif

// anything inside an if 0 block will not be compiled
#if 0
    /*
     * we can use if 0 to comment code with multiline comment, as comments are not nestable
     */
#endif
}
