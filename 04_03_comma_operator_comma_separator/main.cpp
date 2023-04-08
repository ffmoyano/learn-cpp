#include <iostream>

void add(int x, int y) {

}

int main() {
    /*
     * COMMA OPERATOR: allows you to evaluate multiple expressions wherever a single expression is allowed.
     * The comma operator evaluates the left operand, then the right operand, and then returns the result of the right operand
     * DON'T USE IT EXCEPT WITHIN FOR LOOPS; it's better to separate it in two statements
     */
    int x{1};
    int y{2};

    std::cout << (++x, ++y) << '\n'; // increment x and y, evaluates to the right operand -> ++y prints 3
    // comma has the lowest precedence of all the operators, even lower than assignment
    // z = (a, b); // evaluate (a, b) first to get result of b, then assign that value to variable z.
    // z = a, b; // evaluates as "(z = a), b", so z gets assigned the value of a, and b is evaluated and discarded.


    /*
     * COMMA SEPARATOR:
     */
    add(x, y); // Comma used to separate arguments in function call
    constexpr int z{3}, w{
            5}; // Comma used to separate multiple variables being defined on the same line (don't do this)
}
