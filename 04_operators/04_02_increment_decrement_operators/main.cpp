#include <iostream>

int add(int a, int b) {
   return a + b;
}

int main() {
    int x {5};
    // PREFIX increment: the operand is incremented and then expression evaluates to the value of the operand
    int y {++x};    // x is incremented to 6, x is evaluated to the value 6, and 6 is assigned to y
    std::cout << y << '\n';
    // POSTFIX increment: First, a copy of the operand is made. Then the operand (not the copy) is incremented or decremented. Finally, the copy (not the original) is evaluated
    x = 5;
    y = x++;        // x is incremented to 6, copy of original x is evaluated to the value 5, and 5 is assigned to y
    std::cout << y << '\n';
    // as the prefix version doesn't make a copy, try to use it as it is more performant

    /*
     * The C++ standard does not define the order in which function arguments are evaluated.
     * If the left argument is evaluated first, this becomes a call to add(5, 6), which equals 11.
     * If the right argument is evaluated first, this becomes a call to add(6, 6), which equals 12!
     */
    x = 5;
    int value{ add(x, ++x) }; // is this 5 + 6, or 6 + 6?
    // It depends on what order your compiler evaluates the function arguments
    // Don’t use a variable that has a side effect applied to it more than once in a given statement. If you do, the result may be undefined.
}
