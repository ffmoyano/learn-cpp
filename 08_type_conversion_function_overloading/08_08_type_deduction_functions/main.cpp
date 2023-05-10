#include <iostream>

auto sum(int x, int y) {
    return x + y; // returns an int, so the type deducted for the function is int
}

auto add(int x, int y) -> int { // this does not perform type deduction, but allows the use of trailing type (explained later)
    return (x + y);
}

// we cannot use type deduction in forward declaration
auto deduct(int x, int y);  // error: use of 'auto deduct(int, int)' before deduction of 'auto'

// you cannot have multiple return types in a type deducted function
auto someFcn(bool b)
{
//    if (b)
//        return 5; // return type int
//    else
//        return 6.7; // return type double ERROR
}

// favor explicit return for functions
int main() {
  //  deduct(5,4);
}

auto deduct(int x, int y) {
    return x - y;
}