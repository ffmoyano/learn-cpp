
#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
}; // IMPORTANT ;

struct Foo
{
    int a;      // no default initialization value (bad)
    int b{};    // value-initialized by default
    int c{2};   // default value, it will be used if another is not specified in object initialization
}; // IMPORTANT ;


int main()
{
    Employee joe;
    Employee mac{3, 23, 452.00};
    Employee jimmy{2, 28}; // jimmy.wage will be value-initialized to 0.0
    const Employee alphonse{1, 15};

    joe.age = 32;  // use member selection operator (.) to select the age member of variable joe
    joe = {joe.id, 33, 66000.0}; // Joe had a birthday and got a raise
    std::cout << joe.age << '\n'; // print joe's age

    // DESIGNATED INITIALIZERS C++20 - allow you to explicitly define which initialization values map to which members
    Foo f1{.a{1}, .c{3}}; // ok: f1.a = 1, f1.b = 0 (value initialized), f1.c = 3
    // Foo f2{ .b{ 2 }, .a{ 1 } }; // error: initialization order does not match order of declaration in struct
    joe = {.id = joe.id, .age = 34, .wage = 74000.0}; // Joe had a birthday and got a raise
    return 0;
}