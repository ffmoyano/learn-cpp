#include <iostream>

// normally make variables private and methods public
// use structs to contain only data and classes to contain data and logic (functions)

class DateClass {// members are private by default (contrary to structs)

// private:
    int month{}; // private by default, can only be accessed by other members
    int day{}; // private by default, can only be accessed by other members
    int year{}; // private by default, can only be accessed by other members
    char* dateFormat;

    constexpr static double const pi {3.14};  // static int private members can only be accessed by public static member functions

public:

    static int common; // static member variables are shared by all objects of this class, they must be initialized out of class

    static double getPi(){  // this class is called by the class itself, not an instance, and can be used to work with static members
        return pi;
    };

    DateClass() {
        dateFormat = new char[8];
    };

    // normal constructor with assignments
    DateClass(int month, int day) {
        this->month = month;
        this->day = day;
        this->year = 2000;
    }

    // constructor with initializer list
    DateClass(int day, int month, int year) : day{day}, month{month}, year{year} {}

    // constructor chaining (delegating constructors)
    DateClass(std::string_view date) : DateClass{} { // DateClass{} calls DateClass() constructor
        // DateClass(); don't do this, this instantiates a new DateClass object and discards as it is not stored in variable
    }

    // destructor, generally is left implicitly declared, but can be used to release memory reserved with new keyword
    ~DateClass(){
        if(dateFormat != nullptr) {
            delete[] dateFormat;
        }
    }

    void print() const { // Make any member function that does not modify the state of the class object const
        std::cout << month << '/' << day << '/' << year;
    }

    void copyFrom(const DateClass &d) {
        // Note that we can access the private members of d directly because this method is another member of the class
        this->month = d.month;
        this->day = d.day;
        this->year = d.year;
    }
};

int DateClass::common { 5 };

int main() {
    DateClass date{10, 14, 2020};

    DateClass copy{};
    copy.copyFrom(date); // okay, because copyFrom() is public
    copy.print();

    std::cout << "\ncommon is: " << DateClass::common << '\n';  // using a static member variable

    return 0;
}