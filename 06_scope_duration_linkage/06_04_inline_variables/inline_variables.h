//
// Created by ffmoy on 17/04/2023.
//

#ifndef LEARNCPP_INLINE_VARIABLES_H
#define LEARNCPP_INLINE_VARIABLES_H

// define your own namespace to hold constants
namespace constants {
    /*
     * The linker will consolidate all inline definitions of a variable into a single variable definition
     * (thus meeting the one definition rule). This allows us to define variables in a header file and have them
     * treated as if there was only one definition in a .cpp file somewhere. Let’s say you have a normal constant
     * that you’re #including into 10 code files. Without inline, you get 10 definitions. With inline, the compiler
     * picks 1 definition to be the canonical definition, so you only get 1 definition. The
     * This means you save 9 constants worth of memory.
     * All definitions of the inline variable must be identical (otherwise, undefined behavior will result).
     * The inline variable definition (not a forward declaration) must be present in any file that uses the variable.
     */
    inline constexpr double pi{3.14159}; // note: now inline constexpr
    inline constexpr double avogadro{6.0221413e23};
    inline constexpr double myGravity{9.2}; // m/s^2 -- gravity is light on this planet
}

#endif //LEARNCPP_INLINE_VARIABLES_H
