#include <iostream>

// prefer string_view to string when needing read only access to a string
void using_strings()
{
    char text[]{"hello"};  // Literal hello is stored in binary, and a copy is made in text[]. 2 copies
    std::string str{text}; // A new copy is made from text to str. Total 3 copies.
    std::string more{str}; // A new copy is made from str to more. Total 4 copies of the string have been made.
    std::cout << text << ' ' << str << ' ' << more << '\n';
}

void using_string_views()
{
    std::string_view text{"hello"}; // view the text "hello", which is stored in the binary
    std::string_view str{text}; // view of the same "hello"
    std::string_view more{str}; // view of the same "hello". Total only the original copy.

    std::cout << text << ' ' << str << ' ' << more << '\n';

    str.remove_prefix(1);
    std::cout << str << '\n';
    str.remove_suffix(2);
    std::cout << str << '\n';
};

int main()
{
    using_strings();
    using_string_views();
}
