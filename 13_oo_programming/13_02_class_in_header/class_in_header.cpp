#include <iostream>
#include "class_in_header.h"

Example::Example() : age{14}, name{"unknown"} {}

Example::Example(int age, std::string_view name) : age{age}, name{name} {}

void Example::isUnderAge() const {
    if (age < 18) {
        std::cout << name << " is underage\n";
    } else {
        std::cout << name << " is not underage\n";
    }
}

int main() {
    auto timmy = Example(); // this uses default 14 value for age
    timmy.isUnderAge();
    auto jimmy = Example(23, "jimmy");
    jimmy.isUnderAge();
}