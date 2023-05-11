#ifndef LEARNCPP_FUNCTION_TEMPLATES_H
#define LEARNCPP_FUNCTION_TEMPLATES_H

template<typename T>
T max(T x, T y) {
    std::cout << "Accessing template function" << '\n';
    return (x < y) ? y : x;
}

template<typename T, typename U>
// We're using two template type parameters named T and U
auto max(T x, U y) // x can resolve to type T, and y can resolve to type U
{
    return (x < y) ? y : x; // as it returns auto the function can decide which to return
}

// abbreviated function template using auto for parameters -> C++ 20 onwards
auto min(auto x, auto y) {
    return (x > y) ? y : x;
}

// A non-type template parameter is a template parameter with a fixed type that serves as a placeholder for a constexpr value passed in as a template argument.
template <auto N> // deduce non-type template parameter from template argument
void print()
{
    std::cout << N << '\n';
}
// Non-type template parameters are used primarily when we need to pass constexpr values to functions (or class types)
// so they can be used in contexts that require a constant expression.

#endif //LEARNCPP_FUNCTION_TEMPLATES_H
