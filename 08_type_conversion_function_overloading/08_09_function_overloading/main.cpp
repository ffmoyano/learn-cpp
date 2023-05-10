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

int main()
{
    std::cout << add(1, 2); // calls add(int, int)
    std::cout << '\n';
    std::cout << add(1.2, 3.4); // calls add(double, double)

}