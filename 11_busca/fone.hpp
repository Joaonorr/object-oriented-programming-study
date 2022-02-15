#include "libraries.hpp"

class Fone {
private:
    std::string number;
    std::string id;

public:
    Fone(std::string id, std::string number) {
        this->id = id;
        this->number = number;
    }
    
    static bool validate(std::string number) {
        //só pode haver núemros ou () ou .
        for (int i = 0; i < (int) number.size(); i++) {
            if (number[i] != '(' && number[i] != ')' && number[i] != '.' && !isdigit(number[i])) {
                std::cout <<"fail: invalid number" << '\n';
                return false;
            }
        }
        return true;
    }

    bool isValid() {
        return Fone::validate(number);
    }

    std::string getId() {
        return id;
    }

    std::string getNumber() {
        return number;
    }

    void setId(std::string id) {
        this->id = id;
    }

    void setNumber(std::string number) {
        this->number = number;
    }


    friend std::ostream& operator<<(std::ostream& os, Fone& fone) {
        os << fone.getId() << ":" << fone.getNumber();
        return os;
    }
};