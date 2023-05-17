
#include <utility>

template<typename T=int, typename U=int> // default T and U to type int
struct Pair
{
    T first{};
    U second{};
};

// class template argument deduction (CTAD) C++17 onwards
int main()
{

    std::pair myPair{1, 2.1};
    // CTAD only works if there is no argument list present
    // std::pair<> p1 { 1, 2 };    // error: too few template arguments, both arguments not deduced
    // std::pair<int> p2 { 3, 4 }; // error: too few template arguments, second argument not deduced

    Pair pair; // uses default Pair<int, int>

}