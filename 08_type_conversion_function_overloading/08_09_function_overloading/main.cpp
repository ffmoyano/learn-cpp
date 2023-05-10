#include <iostream>

int add(int x, int y)
{
    return x + y;
}

double add(double x, double y)
{
    return x + y;
}

// A function’s return type is not considered when differentiating overloaded functions. This function is not admitted
// because the compiler thinks is the same than the previously declared function
//int add(double x, double y)  {
//
//}

void print(int)
{
}

void print(double)
{
}

int main()
{
    std::cout << add(1, 2); // calls add(int, int)
    std::cout << '\n';
    std::cout << add(1.2, 3.4); // calls add(double, double)

    // Matches made by applying numeric promotions take precedence over any matches made by applying numeric conversions.
    print('a'); // promoted to match print(int)
    print(true); // promoted to match print(int)
    print(4.5f); // promoted to match print(double)

    // print(5L); // 5L is type long -> no match from a given step is considered to be better than any other match from the same step.

}