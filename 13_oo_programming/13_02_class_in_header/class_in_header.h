class Example {


private:
    int age;
    std::string_view name;

public:
    // in header files use only forward declaration
    void isUnderAge() const;

    Example();

    Example(int age, std::string_view name);
};