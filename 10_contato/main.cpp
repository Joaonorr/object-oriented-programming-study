#include "contact.hpp"

int main() {
    Contact contact;

    while(true) {
        std::cout << "$";
        std::string line{};
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if(command == "init") {
            std::string name;
            ss >> name;
            contact.setName(name);
        }
        else if(command == "add") {
            std::string id;
            std::string number;
            ss >> id >> number;
            Fone fone(id, number);
            contact.addFone(fone);
        }
        else if(command == "rm") {
            int index;
            ss >> index;
            contact.rmFone(index);
        }
        else if(command == "show") {
            std::cout << contact;
        }
        else if(command == "end") {
            break;
        }
    }
}