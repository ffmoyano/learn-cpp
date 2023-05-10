#include <iostream>

// type alias -> name it with PascalCase and no suffixes
using Distance = double; // define Distance as an alias for type double
// typeDef -> older, prefer type alias
typedef double Kilometers;


void printDistance(Distance distance) {
    std::cout << distance << '\n';
}

void printKilometers(Kilometers kilometers) {
    std:: cout << kilometers << '\n';
}

int main() {

    Distance kilometersToDestination{4.5};
    printDistance(kilometersToDestination);

    Kilometers unitsToDestination{5.5};
    printKilometers(unitsToDestination);

}

// One of the primary uses for type aliases is to hide platform specific details. On some platforms, an int is 2 bytes,
// and on others, it is 4 bytes. Thus, using int to store more than 2 bytes of information can be potentially dangerous
// when writing platform independent code.
// In order to make sure each aliased type resolves to a type of the right size, type aliases of this kind are typically
// used in conjunction with preprocessor directives:


//#ifdef INT_2_BYTES
//    using int8_t = char;
//using int16_t = int;
//using int32_t = long;
//#else
//    using int8_t = char;
//    using int16_t = short;
//    using int32_t = int;
//#endif
