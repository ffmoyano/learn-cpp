#include <iostream>

int main() {
    /**
    * An lvalue (pronounced “ell-value”, short for “left value” or “locator value”, and sometimes written as “l-value”)
    * is an expression that evaluates to an identifiable object or function (or bit-field).
    *
    * An rvalue (pronounced “arr-value”, short for “right value”, and sometimes written as r-value)
    * is an expression that is not an l-value. Commonly seen rvalues include literals
    */
    int myValue{ 5 }; // myValue is an lvalue, 5 is an rvalue expression

    int x{5};    // x is a normal integer variable
    int &ref{x}; // ref is an lvalue reference variable that can now be used as an alias for variable x

    std::cout << x << '\n';  // print the value of x (5)
    std::cout << ref << '\n'; // print the value of x via ref (5)

    ref = 7;    // altering the reference changes the referenced value (x)
    std::cout << x << '\n';

    // int& invalidRef;   // error: references must be initialized

    //    int& invalidRef { y };  // invalid: can't bind to a non-modifiable lvalue
    //    int& invalidRef2 { 0 }; // invalid: can't bind to an r-value
    int a{5};
    int b{6};

    int &ref2{a}; // ref is now an alias for x

    ref = b; // assigns 6 (the value of b) to a (the object being referenced by ref)
    // The above line does NOT change ref into a reference to variable b!

    std::cout << a << '\n'; // user is expecting this to print 5 but prints 6
}