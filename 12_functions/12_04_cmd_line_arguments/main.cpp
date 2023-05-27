#include <iostream>

// filename.exe arg1 arg2 arg3 ...
// In most operating systems the first argument is the file to be executed
// argc: number of arguments; argv: argument values (each one of argv is a pointer to a c_string)
int main(int argc, char* argv[])
{
    std::cout << "There are " << argc << " arguments:\n";
    // Loop through each argument and print its number and value
    for (int count{0}; count < argc; ++count)
    {
        std::cout << count << ' ' << argv[count] << '\n';
    }
}