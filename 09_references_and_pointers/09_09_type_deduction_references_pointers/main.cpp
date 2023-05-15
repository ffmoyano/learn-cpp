#include <iostream>

std::string& getRef(); // some function that returns a reference
const std::string& getConstRef(); // some function that returns a reference to const

std::string* getPtr(); // some function that returns a pointer

int main()
{
    // type deduction drops references, and must be reapplied
    auto ref1{getRef()};  // std::string (reference dropped)
    auto& ref2{getRef()}; // std::string& (reference reapplied)

    // A top-level const is a const qualifier that applies to an object itself.
    const int x = 0;    // this const applies to x, so it is top-level
    int* const ptr = nullptr; // this const applies to ptr, so it is top-level
    // A low-level const is a const qualifier that applies to the object being referenced or pointed to.
    const int& ref{}; // this const applies to the object being referenced, so it is low-level
    const int* ptr2{}; // this const applies to the object being pointed to, so it is low-level


    auto ref3{getConstRef()};        // std::string (top-level const and reference dropped)
    const auto ref4{getConstRef()};  // const std::string (const reapplied, reference dropped)

    auto& ref5{getConstRef()};       // const std::string& (reference reapplied, low-level const not dropped)
    const auto& ref6{getConstRef()}; // const std::string& (reference and const reapplied)

    // type deduction DOES NOT drop pointers
    auto ptr3{ getPtr() };  // std::string*
    auto* ptr4{ getPtr() }; // std::string*
}