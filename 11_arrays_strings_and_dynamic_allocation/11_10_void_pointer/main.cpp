#include <iostream>

// The void pointer, also known as the generic pointer, is a special type of pointer that can be pointed at objects
// of any data type! A void pointer is declared like a normal pointer, using the void keyword as the pointer’s type
int main()
{
    int nValue;
    float fValue;

    struct Something
    {
        int n;
        float f;
    };

    Something sValue;

    void* ptr;
    ptr = &nValue; // valid
    ptr = &fValue; // valid
    ptr = &sValue; // valid

// However, because the void pointer does not know what type of object it is pointing to, dereferencing a void pointer is illegal.
// Instead, the void pointer must first be cast to another pointer type before the dereference can be performed.

    int value{5};
    void* voidPtr{&value};

    // std::cout << *voidPtr << '\n'; // illegal: dereference of void pointer

    int* intPtr{static_cast<int*>(voidPtr)}; // however, if we cast our void pointer to an int pointer...

    std::cout << *intPtr << '\n'; // then we can dereference the result
}
