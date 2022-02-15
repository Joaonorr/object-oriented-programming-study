#include "libraries.hpp"

class Kid {
private:
    int age{};
    std::string name{};

public:
    Kid(std::string name, int age) {
        this->age = age;
        this->name = name;
    }

    int getAge() {
        return age;
    }

    std::string getName() {
        return name;
    }   

    void setAge(int age) {
        this->age = age;
    }

    void setName(std::string name) {
        this->name = name;
    }

    friend std::ostream& operator<<(std::ostream& os, const Kid& kid) {
        os << kid.name << ":" << kid.age;
        return os;
    }

};
