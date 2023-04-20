#include <iostream>

void whitespaces() {
    std::cout << "Enter your full name: ";
    // we write Fernando Fernandez
    // problem is whitespace breaks the cin and therefore two cin are needed to process the input
    std::string name{};
    std::cin >> name;   // this inserts Fernando in name

    std::cout << "Enter your age: ";
    std::string age{};
    // this inserts Fernandez in age, as its been buffered as a second answer, and so no input is needed again
    std::cin >> age;
    // Your name is Fernando and your age is Fernandez :/
    std::cout << "Your name is " << name << " and your age is " << age << '\n';
}

void get_line() {
    std::cout << "Pick 1 or 2: ";
    int choice{};
    // we enter 1 or 2 and push enter. The cin understands the enter as a newline
    std::cin >> choice;

    std::cout << "Now enter your name: ";
    std::string name{};
    // std::getLine accepts an input without whitespaces breaking the input. However, as we have \n buffered,
    // the std::getLine understands that as a new line and doesn't ask for input, assigning to name an empty string
    std::getline(std::cin, name);

    std::cout << "Hello, " << name << ", you picked " << choice << '\n';
}

void std_ws() {
    std::cout << "Pick 1 or 2: ";
    int choice{};
    // we enter 1 or 2 and push enter. The cin understands the enter as a newline
    std::cin >> choice;

    std::cout << "Now enter your name: ";
    std::string name{};
    // this time we use the std::ws input manipulator to tell the std::cin to ignore leading whitespaces
    // this removes the buffered empty string and allows the user to enter input again for the second prompt
    std::getline(std::cin >> std::ws, name);

    std::cout << "Hello, " << name << ", you picked " << choice << '\n';
}

void string_length() {
    std::string hi{"Hi!"};
    // we can use string.length() to get the length of a string, however it is returned as an unsigned integer
    // and we should cast it to a signed integer to avoid compiler warnings about signed/unsigned conversions
    int length{static_cast<int>(hi.length())};
    // std::ssize returns the length of a string as a signed integer (C++ 20 onwards)
    long hisize = std::ssize(hi);
}

/*
 * Double-quoted string literals (like “Hello, world!”) are C-style strings by default (and thus, have a strange type).
 * We can create string literals with type std::string by using a s suffix after the double-quoted string literal.
 */
void string_literals() {
    using namespace std::literals; // easiest way to access the s and sv suffixes

    std::cout << "foo\n";   // no suffix is a C-style string literal
    std::cout << "goo\n"s;  // s suffix is a std::string literal
    std::cout << "moo\n"sv; // sv suffix is a std::string_view literal
}

// here str is initialized through my_string without making a copy.
std::string string_views(std::string_view str) {
    std::cout << str << "\n";
    // we can initialize strings from string views and vice-versa
    std::string other_string {str};
    // we return a string because returning string_view is discouraged
    return other_string;
}

int main() {
    whitespaces();
    get_line();
    std_ws();
    string_length();
    string_literals();
    // string_view provides a read only access to a string without making a copy. More efficient
    // also, we cannot make constexpr from a string but we can make it from a string_view
    constexpr std::string_view my_string{"i'm a string view"};
    string_views(my_string);;
}
