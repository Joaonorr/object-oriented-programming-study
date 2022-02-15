#include "pencil.hpp"

int main() {
    Pencil pencil;
    while(true) {
        std::cout << "$";
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if(command == "init") {
            float thickness{};
            ss >> thickness;
            pencil = Pencil(thickness);
        }
        else if(command == "insert") {
            float thickness{};
            std::string hardness;
            int size{};
            ss >> thickness >> hardness >> size;
            Lead *lead = new Lead(thickness, hardness, size);
            pencil.insertGraphite(lead);
        }
        else if(command == "show") {
            std::cout << pencil;
        }
        else if(command == "remove") {
            pencil.remove();
        }
        else if(command == "write") {
            pencil.writePage();
        }
        else if(command == "end") {
            pencil.remove();
            break;
        }
    }
}