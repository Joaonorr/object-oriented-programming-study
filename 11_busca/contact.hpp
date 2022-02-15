#include "fone.hpp"

class Contact {
private:
    //std::string prefix;
    std::list<Fone> fones;
    std::string name;

public:
    Contact(std::string name = "", std::list<Fone> fones = std::list<Fone>()) {
        this->name = name;
        this->fones = fones;
    }

    void addFone(Fone fone) {
        if(Fone::validate(fone.getNumber())) {
            fones.push_back(fone);
        }
    }

    void rmFone(int index) {
        std::list<Fone>::iterator it = fones.begin();
        std::advance(it, index);
        fones.erase(it);
    }

    std::list<Fone> getFones() {
        return fones;
    }

    std::string getName() {
        return name;
    }

    void setFones(std::list<Fone> fones) {
        this->fones = fones;
    }

    void setName(std::string name) {
        this->name = name;
    }

    friend std::ostream& operator<<(std::ostream& os, Contact& contact) {
        int cont{0};
        os << contact.getName();
        os << " ";
        if(!contact.getFones().empty()) {
            for (auto it : contact.getFones()) {
                os << " ";
                os << "[" << cont << ":";
                os << it;
                os << "]";
                cont++;
            }

        }
        return os;

    }
};