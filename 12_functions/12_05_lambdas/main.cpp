#include <iostream>
#include <functional>

void myInvoke(const std::function<void()>& fn)
{
    fn();
}

// lambdas (anonymous functions)
int main(int argc, char* argv[])
{
    // lambda function with no return type, empty capture clause and no parameters
    []
    {
        std::cout << "Hello, world!\n";
    }();  // semicolon is obligatory


    // when storing the function in a variable use the auto type (or prior to c++20, std::function)
    auto isEven{  // setting a lambda function as a variable value;
            [](int i)
            {
                return ((i % 2) == 0);
            }
    };

    std::cout << std::boolalpha << isEven(2) << '\n';  // calling the lambda function stored in variable

    // with parameters
    auto multiplied{
            [](int a)
            {
                return a * 2;
            }
    };

    std::cout << multiplied(3) << '\n';

    // The capture clause is used to (indirectly) give a lambda access to variables available in the surrounding scope
    // that it normally would not have access to.
    std::string_view search{"weeeee"};
    [search]  // a copy of search is made to be accessed inside the lambda
    {
        std::cout << search
                  << '\n';  // search cannot be used inside lambda if not specificly captured in capture clause
        // search = "SDFdasf";  INVALID, by default the copy made is a const
    }();

    // using the keyword mutable the copy can be changed its value
    [search] mutable  {
        search = "asdfagasdf";
    }
    ();

    std::cout << search << '\n';    // this prints weeee as the previous change is being made to a copy inside a lambda
    // variables can be captured by reference too, avoiding a copy being made
    [&search] mutable
    {
        search = "sdggsdsdgsdg";    // being a reference, changes affect the outer variable
    }();

    std::cout << search << '\n';    // sdggsdsdgsdg

    // DEFAULT CAPTURES [=] and [&]
    [=]
    {    // [=] means capturing all variables mentioned inside the lambda by value
        std::cout << search << '\n';
        std::cout << multiplied << '\n';
    }();

    [&]
    {    // [&] means capturing all variables mentioned inside the lambda by reference
        std::cout << search << '\n';
        std::cout << multiplied << '\n';
    }();

    int i{ 0 };

    auto count{[i]() mutable
               {
                   std::cout << ++i << '\n';
               }};

    // each time we pass the lambda count to the function myInvoke, a copy of count is made
    myInvoke(count); // 1
    myInvoke(count); // 1
    myInvoke(count); // 1

    // std::ref(count) ensures count is treated like a reference
    // thus, anything that tries to copy count will actually copy the reference
    // ensuring that only one count exists
    myInvoke(std::ref(count)); // 1
    myInvoke(std::ref(count)); // 2
    myInvoke(std::ref(count)); // 3
}