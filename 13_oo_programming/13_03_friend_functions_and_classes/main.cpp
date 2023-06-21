#include <iostream>
class Storage; // forward declaration


// A friend function is a function that can access the private members of a class as though it was a member of that class.
class Value {
private:
    int m_value{};

public:
    Value(int value)
            : m_value{value} {
    }

    friend bool isEqual(const Value &value1,
                        const Value &value2);  // we declare the isEqual() function to be a friend of the Value class
};

bool isEqual(const Value &value1,
             const Value &value2) {  // isEqual is a friend of Value, so it can access private member m_value
    return (value1.m_value == value2.m_value);
}




// It is also possible to make an entire class a friend of another class. This gives all the members of the friend class access to the private members of the other class.
class Storage {
private:
    int m_nValue{};
    double m_dValue{};
public:
    Storage(int nValue, double dValue)
            : m_nValue{nValue}, m_dValue{dValue} {
    }

    // Make the Display class a friend of Storage
    friend class Display;

    // Make the Display::displayItem member function a friend of the Storage class instead of all class
    // For this to work Display should be fully implemented before Storage

    // friend void Display::displayItem(const Storage& storage);
};


class Display {
private:
    bool m_displayIntFirst;

public:
    Display(bool displayIntFirst)
            : m_displayIntFirst{displayIntFirst} {
    }

    void displayItem(const Storage &storage) {  // display has access to the private members m_nValue and m_dValue
        if (m_displayIntFirst)
            std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
        else // display double first
            std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
    }
};


int main() {
    Value v1{5};
    Value v2{6};
    std::cout << std::boolalpha << isEqual(v1, v2);


    Storage storage{5, 6.7};
    Display display{false};

    display.displayItem(storage);
}

