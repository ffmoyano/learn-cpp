#include <iostream>

// In for-each loops element declarations, if your elements are non-fundamental types, use references or const references for performance reasons.


int sumArray(const int array[]) // array is a pointer
{
    int sum{ 0 };

//    for (auto number : array) // compile error, the size of array isn't known
//    {
//        sum += number;
//    }

    return sum;
}


int main()
{
    constexpr int fibonacci[]{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    for (auto number : fibonacci) // type is auto, so number has its type deduced from the fibonacci array
    {
        std::cout << number << ' ';
    }

    std::cout << '\n';


    std::string array[]{ "peter", "likes", "frozen", "yogurt" };
    for (auto element : array) // element will be a copy of the current array element
    {
        std::cout << element << ' ';
    }

    std::string array2[]{ "peter", "likes", "frozen", "yogurt" };
    for (const auto& element: array2) // The ampersand makes element a reference to the actual array element, preventing a copy from being made
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    constexpr std::string_view names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily" }; // Names of the students
    constexpr int scores[]{ 84, 92, 76, 81, 56 };
    int maxScore{ 0 };

    // since c++ foreach loops can used an init-statement
    for (int i{ 0 }; auto score : scores) // i is the index of the current element
    {
        if (score > maxScore)
        {
            std::cout << names[i] << " beat the previous best score of " << maxScore << " by " << (score - maxScore) << " points!\n";
            maxScore = score;
        }

        ++i;
    }

}
