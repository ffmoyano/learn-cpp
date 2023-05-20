#include <iostream>

/*
 * Static memory allocation happens for static and global variables.
 * Memory for these types of variables is allocated once when your program is run and persists throughout the life of your program.
 * Automatic memory allocation happens for function parameters and local variables.
 * Memory for these types of variables is allocated when the relevant block is entered, and freed when the block is exited, as many times as necessary.
 * Dynamic memory allocation is a way for running programs to request memory from the operating system when needed.
 * This memory does not come from the program’s limited stack memory -- instead, it is allocated from a much larger pool of memory managed by the operating system called the heap
 */


int main()
{
    int* ptr{new int}; // dynamically allocate an integer and assign the address to ptr, so we can access it later
    *ptr = 7; // assign value of 7 to allocated memory

    int* ptr1{new int(5)}; // use direct initialization
    int* ptr2{new int{6}}; // use uniform initialization


    // assume ptr has previously been allocated with operator new
    delete ptr; // return the memory pointed to by ptr to the operating system
    ptr = nullptr; // set ptr to be a null pointer. Set deleted pointers to nullptr unless they are going out of scope immediately afterward.


    // When requesting memory from the operating system, in rare circumstances, the operating system may not have any memory to grant the request with.
    // By default, if new fails, a bad_alloc exception is thrown.

    // To avoid this and have new return a null pointer we use ::nothrown
    int* value{new(std::nothrow) int}; // value will be set to a null pointer if the integer allocation fails

    // Deleting a null pointer is okay, and does nothing. There is no need to conditionalize your delete statements.

    std::cout << "Enter a positive integer: ";
    int length{};
    std::cin >> length;
    int* array{new int[length]{}}; // use array new.  Note that length does not need to be constant!

    int* array2{new int[5]{9, 7, 5, 3, 1}}; // initialize a dynamic array since C++11
// To prevent writing the type twice, we can use auto. This is often done for types with long names.
    auto* array3{new int[5]{9, 7, 5, 3, 1}};

}
