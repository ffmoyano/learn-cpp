#include <iostream>
#include <cstring>

// DO NOT USE C STYLE STRINGS, USE STD::STRING AND STD::STRING_VIEW
int main()
{
    // A C-style string is simply an array of characters that uses a null terminator. A null terminator is a special
    // character (‘\0’, ascii code 0) used to indicate the end of the string.

    // To define a C-style string, simply declare a char array and initialize it with a string literal
    char myString[]{"string"};  // length 7, string (6) + 1 terminator character
    int length = std::size(myString);
    std::cout << "myString has " << length << " characters\n";
    for (int character{0}; character < length; ++character)
    {
        std::cout << static_cast<int>(myString[character])
                  << '\n'; // convert the char value to int, so we can see the last 0 (terminator)
    }

    // strcpy() allows you to copy a string to another string. More commonly, this is used to assign a value to a string
    char source[]{"Copy this!"};
    char dest[50];
    std::strcpy(dest, source);
    std::cout << dest << '\n'; // prints "Copy this!"

}
