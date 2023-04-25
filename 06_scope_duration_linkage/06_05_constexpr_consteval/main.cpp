#include <iostream>

/*
 *  constexpr functions are implicitly inline, which makes them exempt from the one-definition rule.
 *  As a result, constexpr functions are often defined in header files, so they can be #included into any .cpp
 *  file that requires the full definition.
 *
 *  Constexpr functions used in a single source file (.cpp) can be defined in the source file above where they are used.
 *
 *  Constexpr functions used in multiple source files should be defined in a header file so they can be included into each source file.
 */

// A constexpr function is a function whose return value may be computed at compile-time.
// To make a function a constexpr function, we simply use the constexpr keyword in front of the return type.
// to be evaluated at compile time, x and y must be constexpr too
constexpr int greaterCompile(int x, int y) { // now a constexpr function
    return (x > y ? x : y);
}

int greaterRuntime(int x, int y) {
    return (x > y ? x : y);
}

constexpr bool isEvaluatedAtCompileTime() {
    return std::is_constant_evaluated(); // returns true if evaluated at compile time;
}


// consteval: it forces a function to be evaluated at compile time or give error if it cannot. C++20 onwards
consteval bool obligatoryCompileTimeEvaluation() {
    return std::is_constant_evaluated();
}

int main() {
    constexpr int x{ 5 };
    constexpr int y{ 6 }; // if these weren't constexpr, greaterCompile would have to be evaluated at runtime

    // We'll explain why we use variable g here later in the lesson
    constexpr int g { greaterCompile(x, y) }; // will be evaluated at compile-time
    std::cout << g << " is greater!\n";
    std::cout << greaterRuntime(x, y) << " is greater!\n"; // will be evaluated at runtime

    // as this uses constexpr but is not assigned to a constexpr it may or may not evaluated at compile time :S
    std::cout << std::boolalpha << isEvaluatedAtCompileTime() << '\n';
    // as this function is marked with consteval it will be evaluated at compile time always.
    std::cout << std::boolalpha << obligatoryCompileTimeEvaluation() << '\n';

}

