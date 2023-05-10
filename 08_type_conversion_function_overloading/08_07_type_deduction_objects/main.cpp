#include <iostream>

int add(int x, int y) {
    return x + y;
}

// favor type deduction for objects unless commit to a specific type is needed
int main() {

    auto d{5.0}; // 5.0 is a double literal, so d will be type double
    auto i{1 + 2}; // 1 + 2 evaluates to an int, so i will be type int
    auto e{i}; // i is an int, so x will be type int too

    auto sum{add(5, 6)}; // add() returns an int, so sum's type will be deduced to int

    // type deduction does not work without initializer or with empty initalizers
//    auto x; // The compiler is unable to deduce the type of x
//    auto y{ }; // The compiler is unable to deduce the type of y


    const int x { 5 };  // x has type const int
    auto y { x };       // y will be type int (const is dropped)

    const auto z { x }; // z will be type const int (const is reapplied)

    using namespace std::literals; // easiest way to access the s and sv suffixes

    auto s { "Hello, world" }; // s will be type const char*, not std::string
    auto s1 { "goo"s };  // "goo"s is a std::string literal, so s1 will be deduced as a std::string
    auto s2 { "moo"sv }; // "moo"sv is a std::string_view literal, so s2 will be deduced as a std::string_view
}
