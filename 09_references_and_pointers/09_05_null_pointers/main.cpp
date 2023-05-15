
#include <iostream>

void someFunction(auto x)
{

}

int main()
{
    int* ptr{}; // ptr is a null pointer, and is not holding an address
    int* ptr2{nullptr}; // can use nullptr to initialize a pointer to bea null pointer
    int value{5};
    int* ptr3{&value}; // ptr2 is a valid pointer
    ptr3 = nullptr; // Can assign nullptr to make the pointer a null pointer

    someFunction(nullptr); // we can also pass nullptr to a function that has a pointer parameter

    if (ptr == nullptr) // explicit test for equivalence
    {
        std::cout << "ptr is null\n";
    }
    else
    {
        std::cout << "ptr is non-null\n";
    }

    int* nullPtr{};

    std::cout << "nullPtr is " << (nullPtr ? "non-null\n" : "null\n"); // implicit conversion to Boolean

}
