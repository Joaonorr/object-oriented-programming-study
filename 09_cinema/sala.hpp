#include "client.hpp"

class Sala {
private:
    std::list<Client> cadeiras;

public:
    Sala(int size) {
        cadeiras.assign(size, Client("", ""));
    }

    void cancelar(std::string id) {
        std::list<Client>::iterator it;
        for(it = cadeiras.begin(); it != cadeiras.end(); it++) {
            if(it->getId() == id) {
                it->setId("");
                it->setFone("");
                break;
            }
        }
        if(it == cadeiras.end()) {
            std::cout << "fail: cliente nao esta no cinema" << "\n";
        }
    }

    bool verificar(std::string id) {
        for(auto& Client : cadeiras) {
            if(Client.getId() == id) {
                return true;
            }
        }
        return false;
    }

    void reservar(std::string id, std::string fone, int pos) {
        std::list<Client>::iterator it = cadeiras.begin();
        std::advance(it, pos);
        if(!verificar(id)) {
            if(it->getId() == "") {
                cadeiras.insert(it, Client(id, fone));
            }
            else {
                std::cout << "fail: cadeira já está ocupada" << "\n";
            }
        }
        else {
            std::cout << "fail: client já está no cinema" << "\n";
        }
    }

    std::list<Client> getCadeiras() {
        return cadeiras;
    }

    friend std::ostream& operator<<(std::ostream& os, const Sala& sala) {
        os << "[ ";
        for(auto& Client : sala.cadeiras) {
            os << Client << " ";
        }
        os << ']' << "\n";
        return os;
    }
};