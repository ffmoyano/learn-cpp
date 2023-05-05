#include <cassert> // for assert()

int main() {
    // Do not ship assertions into production
    /*
     * An assertion is an expression that will be true unless there is a bug in the program. If the expression evaluates
     * to true, the assertion statement does nothing. If the conditional expression evaluates to false, an error message
     * is displayed and the program is terminated (via std::abort).
     */
    // assert(5==4);
    assert(5==4 && "Impossible");  // assert with fail message

    /*
     * static_assert is run at compile time, therefore what it evaluates must be evaluable at compile time. It doesn't
     * require any include, contrary to normal assert. It causes a compilation error
     */
    // static_assert(5==4);
}