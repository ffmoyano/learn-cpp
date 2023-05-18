#include <iostream>


int main()
{
    int array[3][5]
            {
                    {1,  2}, // row 0 = 1, 2, 0, 0, 0
                    {6,  7,  8}, // row 1 = 6, 7, 8, 0, 0
                    {11, 12, 13, 14} // row 2 = 11, 12, 13, 14, 0
            };

    int array2[][5] // only the leftmost length is allowed to be left empty
            {
                    { 1, 2, 3, 4, 5 },
                    { 6, 7, 8, 9, 10 },
                    { 11, 12, 13, 14, 15 }
            };

    // int array3[][]{{},{}}; // this is now allowed

    for (int row{ 0 }; row < 3; ++row) // step through the rows in the array
    {
        for (int col{ 0 }; col < 5; ++col) // step through each element in the row
        {
            std::cout << array[row][col] << '\t';
        }
        std:: cout << '\n';
    }
}
