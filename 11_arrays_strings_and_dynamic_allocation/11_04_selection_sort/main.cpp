#include <iostream>

void manualSorting() {
    int array[]{ 30, 50, 20, 10, 40 };
    constexpr int length = std::size(array);
    for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
    {
        int smallestIndex{ startIndex };
        for (int currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex)
        {
            if (array[currentIndex] < array[smallestIndex])
            {
                smallestIndex = currentIndex;
            }
        }
        std::swap(array[startIndex], array[smallestIndex]);
    }
    for (int index{ 0 }; index < length; ++index)
    {
        std::cout << array[index] << ' ';
    }
    std::cout << '\n';
}

void usingStdSort() {
    int array[]{ 30, 50, 20, 10, 40 };

    std::sort(std::begin(array), std::end(array));

    for (int i{ 0 }; i < std::size(array); ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    manualSorting();
    usingStdSort();
}
