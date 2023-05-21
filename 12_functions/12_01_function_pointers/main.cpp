#include <utility>
#include <iostream>

// function prototypes
int foo()
{

};

double goo()
{

};

int hoo(int x)
{

};

int greater(int x, int y)
{
    return x > y ? x : y;
}


void printGreater(int (*greater)(int, int), int x, int y)
{
    std::cout << "Hello, checking which one is greater:\n";
    std::cout << greater(x, y) << '\n';

}

int main()
{
    // function pointer initializers
    int (* fcnPtr1)(){&foo};    // okay
    // int (*fcnPtr2)(){ &goo };    // wrong -- return types don't match!
    double (* fcnPtr4)(){&goo}; // okay
    // fcnPtr1 = &hoo;              // wrong -- fcnPtr1 has no parameters, but hoo() does
    int (* fcnPtr3)(int){&hoo}; // okay

    (*fcnPtr3)(5); // call function hoo(5) through fcnPtr3.
    fcnPtr3(5);  // call function hoo(5) through fcnPtr3. -> prefer this

    // passing function pointer as argument to another function
    printGreater(greater, 5 ,6);
}
