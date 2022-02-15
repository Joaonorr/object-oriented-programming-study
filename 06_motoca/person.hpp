#include "libraries.hpp"

class Person {
public:
    int age{0};
    std::string name{""};

    Person(std::string name, int age) {
        this->name = name;
        this->age = age;
    }

    int getAge() {
        return this->age;
    }
    

    std::string getName() {
        return this->name;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << "[" << person.name << ":" << person.age << "]";
        return os;
    }
};
