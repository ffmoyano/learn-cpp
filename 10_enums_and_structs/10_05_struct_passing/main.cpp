#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

struct Company {
    int employeeQuantity{};
    Employee CEO {};    // composition, object as member
};

void printEmployee(const Employee& employee) // note pass by reference here
{
    std::cout << "ID:   " << employee.id << '\n';
    std::cout << "Age:  " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

struct Point3d
{
    double x{0.0};
    double y{0.0};
    double z{0.0};
};

Point3d getZeroPoint()
{
    return Point3d { 0.0, 0.0, 0.0 };
}

int main()
{
    Employee joe{14, 32, 24.15};
    // Print Joe's information
    printEmployee(joe);

    Point3d zero{getZeroPoint()};

    Company myCompany{ 7, { 1, 32, 55000.0 } }; // Nested initialization list to initialize Employee
}