#include "agenda.hpp"

int main() {
    Agenda agenda;

    while(true) {
        std::cout << "$";
        std::string line{};
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string command{};
        ss >> command;

        

        if(command == "add") {
            for(char &caracter: line) {
                if(caracter == ':') {
                    caracter = ' ';
                }
            }
            std::stringstream ss2(line);
            std::string buffer{};
            ss2 >> buffer;
            std::string name{};
            ss2 >> name;
            std::list<Fone> fones;
            std::string id;
            std::string number;
            while(ss2 >> id >> number) {
                fones.push_back(Fone(id, number));
            };   

            agenda.addContact(name, fones);
        }
        else if(command == "rmFone") {
            std::string name{};
            std::string aux{};            
            ss >> name >> aux;
            int pos = std::stoi(aux);
            Contact *contact = agenda.findContact(name);
            if(contact != nullptr) {
                contact->rmFone(pos);
            }
        }
        else if(command == "rm") {
            std::string name{};
            ss >> name;
            agenda.rmContact(name);
        }
        else if(command == "search") {
            std::string regularExpression{};
            ss >> regularExpression;
            for(auto contacts : agenda.search(regularExpression)) {
                std::cout << contacts << '\n';
            }


        }
        else if(command == "show") {
            std::cout << agenda;
        }
        else if(command == "end") {
            break;
        }
            
        
    }
}