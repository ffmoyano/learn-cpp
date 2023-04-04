#include <iostream>

/*
 * char type is an integral type, the underlying value is a 1 byte integer which ranges from 0 to 127
 */
int main() {

    char ch{'a'};
    char chnumber{97};   // 97 is equivalent to 'a'. This way of assigning a char is discouraged

    std::cout << "Input a keyboard character: "; // assume the user enters "abcd" (without quotes)

    char ch2{};
    std::cin >> ch2; // ch = 'a', "bcd" is left queued.
    std::cout << "You entered: " << ch2 << '\n';

    // Note: The following cin doesn't ask the user for input, it grabs queued input!
    std::cin >> ch2; // ch = 'b', "cd" is left queued.
    std::cout << "You entered: " << ch2 << '\n';  // Unique escape characters such as '\n' are best wrapped in single quotes rather than double quotes

    // there also char8_t, char16_t, or char32_t types for 8, 16 and 32 bytes unicode characters,
    // which are only needed if you want to make the program unicode compatible
    // there is also wchar_t type. It is deprecated

}