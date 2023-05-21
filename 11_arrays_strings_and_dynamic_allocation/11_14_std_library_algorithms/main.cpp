#include <iostream>
#include <array>


bool greater(int a, int b)
{
    // Order @a before @b if @a is greater than @b.
    return (a > b);
}

// Our function will return true if the element matches
bool containsNut(std::string_view str)
{
    // std::string_view::find returns std::string_view::npos if it doesn't find
    // the substring. Otherwise it returns the index where the substring occurs
    // in str.
    return (str.find("nut") != std::string_view::npos);
}

void doubleNumber(int& i)
{
    i *= 2;
}


int main()
{
    std::array<std::string_view, 5> arr{"apple", "banana", "walnut", "lemon", "peanut"};

    // Scan our array to see if any elements contain the "nut" substring
    auto found{std::find_if(arr.begin(), arr.end(), containsNut)};

    if (found == arr.end())
    {
        std::cout << "No nuts\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }
    // count_if
    auto nuts{std::count_if(arr.begin(), arr.end(), containsNut)};
    std::cout << "Counted " << nuts << " nut(s)\n";


    std::array array{ 13, 90, 99, 5, 40, 80 };

    // Using function greater to custom sort array
    std::sort(array.begin(), array.end(), greater);

    for (int i : array)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    std::array arr2{ 1, 2, 3, 4 };

    // std::for_each takes a list as input and applies a custom function to every element.
    std::for_each(arr2.begin(), arr2.end(), doubleNumber);

    for (int i : arr2)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';
}

