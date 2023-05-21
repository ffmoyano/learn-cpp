#include <iostream>
#include <vector>

// like std::array, std::vector doesn't decay to a pointer when passed to a function
void printLength(const std::vector<int>& v) // use reference to avoid making a copy
{
    std::cout << "The length is: " << v.size() << '\n';
}

// std::vector has dynamic size, prefer it to dynamic arrays
int main()
{
// no need to specify length at the declaration
    std::vector<int> v;
    std::vector<int> v2 = { 9, 7, 5, 3, 1 }; // use initializer list to initialize vector (before C++11)
    std::vector<int> v3 { 9, 7, 5, 3, 1 }; // use uniform initialization to initialize vector

// as with std::array, the type can be omitted since C++17
    std::vector v4 { 9, 7, 5, 3, 1 }; // deduced to std::vector<int>

    // Just like std::array, accessing array elements can be done via the [] operator (which does no bounds checking) or the at() function (which does bounds checking):

    v[6] = 2; // no bounds checking
    v.at(7) = 3; // does bounds checking

    v = { 0, 1, 2, 3, 4 }; // okay, vector length is now 5
    v = { 9, 8, 7 }; // okay, vector length is now 3

    std::vector v5{ 0, 1, 2 };
    v2.resize(5); // set size to 5. Extra elements are initialized to their default value (0 for integers)

    // Using direct initialization, we can create a vector with 5 elements,
    // each element has value 0. If we use brace initialization, the vector would
    // have 1 element with value 5.
    std::vector<int> v6(5);
}
