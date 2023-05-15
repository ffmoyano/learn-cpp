#include <iostream>
// like when passing a value, when returning by value a copy of the return value is passed back to the caller
// to avoid making a copy we can return by reference or address (prefer return by reference except if you need to return nullptr)

// Never return a local variable by reference.
const std::string& getProgramName() // returns a const reference
{
    const std::string programName{"Calculator"}; // local variable, destroyed when function ends

    return programName;
}

const std::string& getProgramNameStatic()
{
    static const std::string s_programName{"Calculator"}; // has static duration, destroyed at end of program

    return s_programName;
}

// Avoid returning references to non-const local static variables.
const int& getNextId()
{
    static int s_x{0}; // note: variable is non-const
    ++s_x; // generate the next id
    return s_x; // and return a reference to it
}


int main()
{
    std::cout << "This program is named " << getProgramNameStatic() << '\n';    // ok
    //  std::cout << "This program is named " << getProgramName() << '\n';          // undefined behaviour, as programName is no longer alive

    const int& id1{getNextId()}; // id1 is a reference
    const int& id2{getNextId()}; // id2 is a reference
    const int id3{
            getNextId()}; // id3 is a normal variable and receives a copy of the value returned by reference from getNextId()

    std::cout << id1 << id2 << id3 << '\n'; // both print 3, as the variable s has been incremented one time each call

}
