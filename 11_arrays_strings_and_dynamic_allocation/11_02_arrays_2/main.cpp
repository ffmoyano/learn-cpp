#include <iostream>

// when passing an array to a function no copy is made, the actual array is passed and therefore changes made to
// the array inside the function are reflected in the object outside as if a reference was passed.
// this is because making a copy could be very expensive
void passArray(int prime[5]) // prime is the actual array
{
    prime[0] = 11; // so changing it here will change the original argument!
    prime[1] = 7;
    prime[2] = 5;
    prime[3] = 3;
    prime[4] = 2;

    // std::cout << std::size(prime) << '\n'; // Error, std::size doesn't work in arrays passed to function, as the info of size is not passed
}

void passArrayByReference(int (& prime)[8])
{ // the syntax must be this one, ampersand and name inside parenthesis
    std::cout << "The size of the passed array by reference is: " << std::size(prime)
              << '\n'; // passing by reference we can use std:: size
}

int main()
{
    int prime[5]{2, 3, 5, 7, 11};
    std::cout << "before passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3] << " "
              << prime[4] << '\n';
    passArray(prime);
    std::cout << "after passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3] << " "
              << prime[4] << '\n';

    // use std::size to know the size of an array
    int array[]{1, 1, 2, 3, 5, 8, 13, 21};
    std::cout << "The array has: " << std::size(array) << " elements\n";

    passArrayByReference(array);

    int what[2]{};
    what[25] = 5;  // undefined behaviour, 5 is inserted in the place that would occupy that slot of the array even if it is out of bounds
}