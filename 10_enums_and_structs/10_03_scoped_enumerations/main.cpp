#include <iostream>
#include <utility>

// we declare scoped enumeration using enum class instead of enum
enum class Color // "enum class" defines this as a scoped enumeration rather than an unscoped enumeration
{   // scoped enum have their own scope so they dont need to be wrapped in a namespace
    red, // red is considered part of Color's scope region
    blue,
};

int main()
{
    Color color{Color::blue};
    // scoped enum are not implicitly converted to int, contrary to unscoped enums
    // std::cout << color << '\n'; // won't work, because there's no implicit conversion to int
    std::cout << static_cast<int>(color) << '\n';   // explicit conversion to int, will print 1
    std::cout << std::to_underlying(color) << '\n'; // convert to underlying type, will print 1 (C++23)
}