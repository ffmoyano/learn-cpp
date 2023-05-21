#include <iostream>
#include <array>
// RECOMMENDED OVER NORMAL ARRAY
// contrary to normal array, std::array doesn't decay to a pointer when passed in a function.
// therefore, make sure to always pass a reference to avoid making a copy. (normal array can also be passed by reference)
void printLength(const std::array<int, 5>& myArray)
{
    std::cout << "length: " << myArray.size() << '\n';
}

// using templates, apart from using any type, we can use any array size
template<typename T, std::size_t size>
// parameterize the element type and size
void printArray(const std::array<T, size>& myArray)
{
    for (auto element: myArray)
        std::cout << element << ' ';
    std::cout << '\n';
}


int main()
{
    std::array<int, 5> myArray = {9, 7, 5, 3, 1}; // initializer list
    std::array<int, 5> myArray2{9, 7, 5, 3, 1}; // list initialization

    // since C++17 types can be deducted -> USE THIS
    std::array myArray3{9, 7, 5, 3, 1}; // The type is deduced to std::array<int, 5>
    std::array myArray4{9.7, 7.31}; // The type is deduced to std::array<double, 2>

    // Since C++20, it is possible to specify the element type but omit the array length with std::to_array.
    // This is expensive since copies all elements from a C-style array to a std::array, so avoid it if you can

    auto myArray5{std::to_array<int, 5>({9, 7, 5, 3, 1})}; // Specify type and size
    auto myArray6{std::to_array<int>({9, 7, 5, 3, 1})}; // Specify type only, deduce size
    auto myArray7{std::to_array({9, 7, 5, 3, 1})}; // Deduce type and size

    std::array<int, 5> myArray8;
    myArray8 = {0, 1, 2, 3, 4}; // okay
    myArray8 = {9, 8, 7}; // okay, elements 3 and 4 are set to zero!
    // myArray8 = { 0, 1, 2, 3, 4, 5 }; // not allowed, too many elements in initializer list!

    printLength(myArray8);

    // std::array supports a second form of array element access (the at() function) that does (runtime) bounds checking:
    std::array myArray9 { 9, 7, 5, 3, 1 };
    myArray.at(1) = 6; // array element 1 is valid, sets array element 1 to value 6
    myArray.at(9) = 10; // array element 9 is invalid, will throw a runtime error

    // sorting array
    std::sort(myArray.begin(), myArray.end()); // sort the array forwards
    std::sort(myArray.rbegin(), myArray.rend()); // sort the array backwards

    for (int element: myArray)
    {
        std::cout << element << '\n';
    }



    // initializing array of structs

    struct House
    {
        int number{};
        int stories{};
        int roomsPerStory{};
    };


    std::array<House, 3> houses{ // initializer for houses
            { // extra set of braces to initialize the C-style array member inside the std::array struct
                    {13, 4, 30}, // initializer for array element 0
                    {14, 3, 10}, // initializer for array element 1
                    {15, 3, 40}, // initializer for array element 2
            }
    };

    for (const auto& house: houses)
    {
        std::cout << "House number " << house.number
                  << " has " << (house.stories * house.roomsPerStory)
                  << " rooms\n";
    }

}
