// using namespaces allow us to avoid name collision of identifiers among different files of our program
// a namespace can be declared in multiple places and all the identifiers inside will be considered part of the same namespace
#include <iostream>

namespace foo // define a namespace named foo
{
    // This doSomething() belongs to namespace foo
    int doSomething(int x, int y) {
        return x + y;
    }
}

namespace goo // define a namespace named goo
{
    // This doSomething() belongs to namespace goo
    int doSomething(int x, int y) {
        return x - y;
    }


}

/*
 * nested namespace C++17 onwards. Before you would do
 * namespace foo {
 *  namespace goo {
 *  }
 * }
 */
namespace foo::goo {
    int doSomething(int x, int y) {
        return x * y;
    };
}

void print() {
    std::cout << "Hello world!\n";
}

namespace hoo {
    void print() // this print lives in the foo namespace
    {
        std::cout << "Hello";
    }

    // we use :: without namespace in the left to refer to the global namespace. This is useful when calling a function
    // of the global namespace inside a namespace which has a function with a similar name
    void printHelloThere() {
        print(); // calls print() in foo namespace
        ::print(); // calls print() in global namespace
    }
}


int main() {
    // use the scope resolution operator (::) to tell the compiler to which namespace an identifier belongs to
    std::cout << foo::doSomething(4, 2) << '\n';
    std::cout << goo::doSomething(4, 2) << '\n';
    std::cout << foo::goo::doSomething(4, 2) << '\n';

    // namespace alias
    namespace a = foo::goo;
    std::cout << a::doSomething(4, 2) << '\n'; // until the end of the scope, this is the same as using foo::goo
}
