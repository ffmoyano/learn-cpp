#include <iostream>
/**
 * UNNAMED NAMESPACE
 * All content declared in an unnamed namespace is treated as if it is part of the parent namespace.
 * So even though function doSomething is defined in the unnamed namespace, the function itself is
 * accessible from the parent namespace (which in this case is the global namespace), which is why we
 * can call doSomething from main without any qualifiers.This might make unnamed namespaces seem useless.
 * ut the other effect of unnamed namespaces is that all identifiers inside an unnamed namespace are treated
 * as if they had internal linkage, which means that the content of an unnamed namespace can’t be seen outside
 * of the file in which the unnamed namespace is defined.For functions, this is effectively the same as defining
 * all functions in the unnamed namespace as static functions.
 */
namespace {// unnamed namespace
    void unnamed() { // can only be accessed in this file
        std::cout << "unnamed\n";
    }
}

inline namespace v1 { // declare an inline namespace named v1
    void doSomething() {
        std::cout << "v1\n";
    }
}

namespace v2 { // declare a normal namespace named v2
    void doSomething() {
        std::cout << "v2\n";
    }
}


int main() {
    unnamed(); // we can call doSomething() without a namespace prefix

    v1::doSomething(); // calls the v1 version of doSomething()
    v2::doSomething(); // calls the v2 version of doSomething()

    doSomething(); // calls the inline version of doSomething() (which is v1)

    return 0;
}