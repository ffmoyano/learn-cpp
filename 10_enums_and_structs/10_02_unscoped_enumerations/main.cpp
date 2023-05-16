#include <cstdint>

// Define a new unscoped enumeration named Color

// unscoped enum put their enumerators in the same scope they are declared, so to avoid name collisions
// wrap enumerators in namespaces instead of defining them in the global namespace
namespace color
{
    // Name your enumerated types starting with a capital letter. Name your enumerators starting with a lower case letter.
    enum Color : std::int8_t    // usually is not necessary to specify the enum underlying type
    {
        red = 4, // avoid explicitly defining integer values of enumerators, they are implicitly assigned integer values
        green,
        blue,// trailing comma optional but recommended
    };// the enum definition must end with a semicolon
}

namespace feeling
{
    enum Feeling
    {
        happy,
        tired,
        blue, // feeling::blue doesn't collide with color::blue
    };
}

int main()
{
    // Define a few variables of enumerated type Color
    color::Color apple{color::red};   // my apple is red
    color::Color shirt{color::green}; // my shirt is green
    color::Color cup{color::blue};    // my cup is blue

    feeling::Feeling me{feeling::happy};

    // Color socks { white }; // error: white is not an enumerator of Color
    // Color hat { 2 };       // error: 2 is not an enumerator of Color

}