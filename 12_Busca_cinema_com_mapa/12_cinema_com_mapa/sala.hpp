#include "client.hpp"

class Sala {
private:
    std::map<int, Client> clients;

public:
    Sala(int size) {
        for(int i = 0; i < size; i++) {
            this->clients.insert(std::make_pair(i, Client("", "")));
        }
    }

    void reservar(std::string id, std::string fone, int pos) {
        for(auto &client : this->clients) {
            if(client.second.getId() == id) {
                std::cout << "fail: cliente ja esta no cinema" << "\n";
                return;
            }
        }
        if(this->clients.at(pos).getId() == "") {
            this->clients.at(pos) = Client(id, fone);
        }
        else {
            std::cout << "fail: cadeira ja esta ocupada" << '\n';
        }
    }

    void cancelar(std::string id) {
        for(auto &client: this->clients) {
            if(client.second.getId() == id) {
                client.second.setId("");
                client.second.setFone("");
                return;
            }
        }
        std::cout << "fail: cliente nao esta no cinema" << '\n';                
    }

    friend std::ostream& operator<<(std::ostream& os, const Sala& sala) {
        os << "[ ";
        for(auto &client: sala.clients) {
            os << client.second << " ";
        }
        os << "]";
        return os;
    }


};