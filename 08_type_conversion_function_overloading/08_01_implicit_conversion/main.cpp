/*
 * CONVERSIONS DO NOT CHANGE THE VALUE OR TYPE OF THE OBJECT CONVERTED, THEY CREATE A NEW OBJECT
 */

/*
 * Implicit type conversion (also called automatic type conversion or coercion) is performed automatically by
 * the compiler when one data type is required, but a different data type is supplied.
 */

void implicit_conversion_when_initializing() {
    double d{3}; // int value 3 implicitly converted to type double
    d = 6; // int value 6 implicitly converted to type double
}

float implicit_conversion_when_returning_value() {
    return 3;  // this int is converted to float
}

void implicit_conversion_on_if() {
    if (5) { // int value 5 implicitly converted to type bool

    }
}

void doSomething(long l) {
}

void implicit_conversion_on_argument_passing() {
    doSomething(3);  // int value 3 implicitly converted to type long
}

int main() {

}