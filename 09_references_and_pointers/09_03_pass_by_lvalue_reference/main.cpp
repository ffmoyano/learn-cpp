#include <iostream>
// BEST PRACTICE Pass fundamental types by value, and class (or struct) types by const reference.
void modifyReference(int &x) // we pass a reference to the object so it is not copied
{
    x++;     // the x variable outside is affected by the changes to its reference
}

void modifyCopy(int y) // the function makes a copy of the objects
{
    y++;    // the y variable outside is not affected because the y here is a different copy
}

void passConstRef(const int &z) {
    std::cout << "z value: " << z << '\n';  // prints 1
}

int main() {
    int x{1};
    int y{1};
    modifyReference(x); // x is now passed by reference into reference parameter y (inexpensive)
    modifyCopy(y);

    std::cout << "x value: " << x << '\n';  // prints 2
    std::cout << "y value: " << y << '\n';  // prints 1

    const int z{5};
    passConstRef(z); // ok: z is a non-modifiable lvalue

}
