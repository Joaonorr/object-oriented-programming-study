#include "trampoline.hpp"

int main() {
    Trampoline trampoline;
    while(true) {
        std::cout << "$";
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if(command == "arrive") {
            std::string name{};
            int age{};
            ss >> name >> age;
            Kid kid{name, age};
            trampoline.arrive(kid);
        }
        else if(command == "enter") {
            trampoline.enter();
        }
        else if(command == "show") {
            std::cout << trampoline << '\n';
        }
        else if(command == "leave") {
            trampoline.leave();
        }
        else if(command == "remove") {
            std::string name{};
            ss >> name;
            trampoline.remove(name);
        }
        else if(command == "end") {
            break;
        }

        
    }
}