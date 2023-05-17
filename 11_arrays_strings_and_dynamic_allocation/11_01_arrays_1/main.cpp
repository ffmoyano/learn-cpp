
#include <string>

int main()
{
    double batteryLifeInHours[3]{}; // allocate 3 doubles
    batteryLifeInHours[0] = 2.0;
    batteryLifeInHours[1] = 3.0;
    batteryLifeInHours[2] = 4.3;

    batteryLifeInHours[1 + 2] = 7.0; // ok

    constexpr int daysPerWeek{ 7 };
    constexpr int numberOfLessonsPerDay[daysPerWeek]{}; // Ok

    // using a macro
    #define DAYS_PER_WEEK 7
    int numberOfLessonsPerDay2[DAYS_PER_WEEK]{}; // Works, but don't do this (use a constexpr symbolic constant instead)


    int array[5]{};          // Initialize all elements to 0
    double array2[5] {};      // Initialize all elements to 0.0
    std::string array3[5] {}; // Initialize all elements to an empty string

    int array4[5];         // uninitialized (since int doesn't self-initialize)
    double array5[5];      // uninitialized (since double doesn't self-initialize)
    std::string array6[5]; // Initialize all elements to an empty string

    int array7[5]{ 0, 1, 2, 3, 4 }; // explicitly define the length of the array
    int array8[]{ 0, 1, 2, 3, 4 }; // let the initializer list set length of the array


}