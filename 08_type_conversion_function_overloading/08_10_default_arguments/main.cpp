#include <iostream>

void print(int x=3, int y=4) // 4 is the default argument
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

//void print(int x=10, int y); // not allowed -> default arguments must be the rightmost arguments

int main()
{
    print(1, 2); // y will use user-supplied argument 2
    print(3); // y will use default argument 4
    print();

}
