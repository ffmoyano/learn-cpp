#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

struct Paw
{
    int claws{};
};

struct Animal
{
    std::string name{};
    Paw paw{};
};

int main()
{
    Employee joe{ 1, 34, 65000.0 };

    ++joe.age;
    joe.wage = 68000.0;

    Employee* ptr{ &joe };
    // std::cout << ptr.id << '\n'; // Compile error: can't use operator. with pointers
    std::cout << (*ptr).id << '\n'; // Not great but works: First dereference ptr, then use member selection
    std::cout << ptr->id << '\n'; // Better: use -> to select member from pointer to object



    Animal puma{ "Puma", { 5 } };

    Animal* ptr2{ &puma };

    // ptr is a pointer, use ->
    // paw is not a pointer, use .

    std::cout << (ptr2->paw).claws << '\n';
}