#include <iostream>

/*
 * GLOBAL VARIABLES
 * zero value if uninitialized, but still const global variables must be initialized
 * by convention their name is preceded by g_ or g
 * global variables are valid from the point they are declared till the end of the file where they are declared
 * global variables are considered part of the global namespace
 */
int gMyGlobalVariable;

int main() {
    /*
     * LOCAL VARIABLES
     * undefined value if uninitialized
     * block scope, they exist only in the block they are defined
     */
    int myLocalVariable;
    {
        int myNestedVariable;
        myLocalVariable = 2; // variables declared in the outer block can be accessed in the inner block
    } // myNestedVariable is destroyed when this block closes;

    gMyGlobalVariable = 54;
}
