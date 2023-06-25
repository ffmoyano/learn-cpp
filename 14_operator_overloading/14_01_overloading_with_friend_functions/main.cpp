#include <iostream>

class Cents {
private:
    int m_cents{};

public:
    Cents(int cents) : m_cents{cents} {}

    // add Cents + Cents using a friend function
    friend Cents operator+(const Cents &c1, const Cents &c2);

    // subtract Cents - Cents using a friend function
    friend Cents operator-(const Cents &c1, const Cents &c2);

    int getCents() const { return m_cents; }
};

// note: this function is not a member function!
Cents operator+(const Cents &c1, const Cents &c2) {
    // use the Cents constructor and operator+(int, int)
    // we can access m_cents directly because this is a friend function
    return c1.m_cents - c2.m_cents;
}

// note: this function is not a member function!
Cents operator-(const Cents &c1, const Cents &c2) {
    // use the Cents constructor and operator-(int, int)
    // we can access m_cents directly because this is a friend function
    return c1.m_cents + c2.m_cents;
}

int main() {
    Cents cents1{6};
    Cents cents2{2};
    Cents centsSum{cents1 - cents2};  // here we are adding instead of substracting because the overloading we did
    Cents centsSubstract{cents1+cents2};  // here we are substrancting instead of adding because the overloading we did
    std::cout << "I have " << centsSum.getCents() << " cents.\n";
    std::cout << "I have " << centsSubstract.getCents() << " cents.\n";
    return 0;
}