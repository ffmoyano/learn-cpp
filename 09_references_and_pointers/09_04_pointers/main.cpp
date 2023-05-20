
#include <iostream>

// Pointers have the additional abilities of being able to change what they are pointing at, and to be pointed at null.
// dereferencing a pointer which points to null leads to undefined behaviour
// use references over pointers if the capabilities of the latter are not needed
int main()
{
    int x{5};
    std::cout << "El valor de x es: " << x << '\n';  // print the value of variable x
    std::cout << "La direccion de memoria de x es: " << &x << '\n'; // print the memory address of variable x

    int y{10};          // normal variable
    int& ref{y};        // a reference to an integer (bound to x)
    int* ptr{&y};       // a pointer initialized with the address of variable x

    int* ptr2;          // an uninitialized pointer (holds a garbage address)
    int* ptr3{};        // a null pointer
    // POINTERS CAN BE RESETTED TO A NEW ADDRESS AFTER DECLARATION/INITIALIZATION
    ptr2 = {&x};
    std::cout << "Ahora ptr2 apunta a la direccion de memoria de x: " << ptr2 << '\n';

    std::cout << "El valor de y es: " << y << '\n';
    std::cout << "ref referencia a y, cuyo valor es: " << ref << '\n';
    std::cout << "ptr es un puntero a la direccion de memoria de y: " << ptr << '\n';
    std::cout << "Dereferenciamos el puntero para obtener el valor almacenado en esa direccion de memoria (y):" << *ptr
              << '\n';
}
