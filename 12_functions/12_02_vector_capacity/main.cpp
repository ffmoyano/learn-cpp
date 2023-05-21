#include <iostream>
#include <vector>

void printStack(const std::vector<int>& stack)
{
    for (auto element : stack)
        std::cout << element << ' ';
    std::cout << "(cap " << stack.capacity() << " length " << stack.size() << ")\n";
}


// length: the number of items a vector has
// capacity: the maximum number a vector can carry before needing to reallocate to hold more items
int main()
{
    std::vector<int> vector{};
    vector = {0, 1, 2, 3, 4 };      // length = 5, capacity 5
    printStack(vector);

    vector = {9, 8, 7 };            // length = 3, capacity still 5
    printStack(vector);

    vector = {0, 0, 0, 0, 0, 0};    // vector length = 6, vector reallocates to have greater capacity
    printStack(vector);

    vector.push_back(5); // push_back() pushes an element on the stack
    printStack(vector);
    vector.pop_back();    // removes an element of the stack
    printStack(vector);
    // as reallocating a vector is expensive, we can put a larger capacity if we predict it is going to grow multiple times
    vector.reserve(20); // Set the capacity to (at least) 20
    printStack(vector);
}
