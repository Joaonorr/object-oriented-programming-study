#include "libraries.hpp"

class Client {
private:
    std::string fone;
    std::string id;

public:
    Client(std::string id, std::string fone) : fone(fone), id(id) {}

    std::string getFone() {
        return this->fone;
    }

    std::string getId() {
        return this->id;
    }

    void setFone(std::string fone) {
        this->fone = fone;
    }

    void setId(std::string id) {
        this->id = id;
    }

    friend std::ostream& operator<<(std::ostream& os, const Client& client) {
        if(client.id == "" && client.fone == "") {
            os << "-";
        }
        else {
            os << client.id << ":" << client.fone;
        }
        return os;
    }

};