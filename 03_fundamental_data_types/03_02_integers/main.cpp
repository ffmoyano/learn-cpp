#include <iostream>

/*
 * cpp has both signed and unsigned integers, but using the latter is discouraged
 */

/*
 * 8 bit signed	    -128 to 127
 * 16 bit signed	-32,768 to 32,767
 * 32 bit signed	-2,147,483,648 to 2,147,483,647
 * 64 bit signed	-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
 */
void signed_integers() {
    short a;
    // discouraged as it is redundant
    signed short b;
    // even more discouraged
    signed short int c;
    // returns 1 even if the variable is declared as float,
    // because integer division always return integer and fractions are dropped
    float d = 5 / 4;
    std::cout << d << "\n";
    // although int minimum size is 2 bytes, for most machines is 4 bytes, and a
    // 32 bit signed int ranges from -2,147,483,648 to 2,147,483,647.
    // assigning a value outside of that range results in an undefined behaviour
    int overflow = 5000053532;
    std::cout << overflow << "\n";  // prints an unexpected value
}


/*
 * 1 byte unsigned	0 to 255
 * 2 byte unsigned	0 to 65,535
 * 4 byte unsigned	0 to 4,294,967,295
 * 8 byte unsigned	0 to 18,446,744,073,709,551,615
 */
void unsigned_integers() {
    /*
     * If an unsigned value is out of range,
     * it is divided by one greater than the largest number of the type, and only the remainder kept.
     */

    // unsigned short e {65537}; max value for 2 byte unsigned int is 65535. bracket assignment doesn't allow exceeding max value
    unsigned short e = 65538;
    std::cout << e << "\n";  // returns 2, as it is the remainder of 65538/65536, being 65536 the max value for this type + 1

    /*
     * If we assign an unsigned integer a negative it wraps around the top of the range
     */
    e = -1;
    std::cout << e << "\n"; // returns 65535;
    e = -2;
    std::cout << e << "\n"; // returns 65534

    // the use of unsigned integers is discouraged because of two reasons:
    // 1 - due to the wrap around in negative numbers, a substraction of two unsigned integers can lead to unexpected results:
    unsigned int x{ 3 };
    unsigned int y{ 5 };

    // prints 4294967294, (the max range here would be 4,294,967,295. The result of this substraction is -2, therefore it wraps around)
    std::cout << x - y << '\n';

    // 2 - if one signed and one unsigned integer are used, the signed integer will be converted to unsigned.
    signed int s { -1 };
    unsigned int u { 1 };

    if (s < u) // -1 is implicitly converted to 4294967295, and 4294967295 < 1 is false
        std::cout << "-1 is less than 1\n";
    else
        std::cout << "1 is less than -1\n"; // this statement executes
}

/*
 * These types have its size guaranteed on any architecture
 *
 * std::int8_t	    1 byte signed	-128 to 127	Discouraged because are treated like a signed char on many systems.
 * std::uint8_t	    1 byte unsigned	0 to 255	Discouraged because are treated like an unsigned char on many systems.
 * std::int16_t	    2 byte signed	-32,768 to 32,767
 * std::uint16_t	2 byte unsigned	0 to 65,535
 * std::int32_t	    4 byte signed	-2,147,483,648 to 2,147,483,647
 * std::uint32_t	4 byte unsigned	0 to 4,294,967,295
 * std::int64_t	    8 byte signed	-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
 * std::uint64_t    8 byte unsigned	0 to 18,446,744,073,709,551,615
 */
void fixed_width_integers() {

    // least provide the smallest signed/unsigned integer type with a width of at least # bits
    std::cout << "least 8:  " << sizeof(std::int_least8_t) * 8 << " bits\n";
    std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
    std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
    std::cout << '\n';
    //  fast types (std::int_fast#_t and std::uint_fast#_t) provide the fastest signed/unsigned integer type with a width of at least # bits
    std::cout << "fast 8:  " << sizeof(std::int_fast8_t) * 8 << " bits\n";
    std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
    std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";
    // size_t is 32 bits for 32 bits apps and 64 bits for 64 bits app
    std::cout << "size: " << sizeof(std::size_t) * 8 << " bits\n";
}


/*
 * Best practice
 *
 * Prefer int when the size of the integer doesn’t matter (e.g. the number will always fit within the range of a 2-byte signed integer).
 * Prefer std::int#_t when storing a quantity that needs a guaranteed range.
 * Prefer std::uint#_t when doing bit manipulation or where well-defined wrap-around behavior is required.
 *
 * Avoid the following when possible:
 * Unsigned types for holding quantities
 * The 8-bit fixed-width integer types
 * The fast and least fixed-width types
 * Any compiler-specific fixed-width integers -- for example, Visual Studio defines __int8, __int16, etc…
 */
int main() {
    signed_integers();
    unsigned_integers();
    fixed_width_integers();
}