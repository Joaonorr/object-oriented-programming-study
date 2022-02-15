#include "motorcycle.hpp"
#include <memory>


int main() {
    std::shared_ptr<Motorcycle> motorcycle{new Motorcycle()};

    while(true) {
        std::cout << "$";
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if(command == "init") {
            int power{0};
            ss >> power;
            motorcycle->power = power;
        }

        else if(command == "show") {
            std::cout << *motorcycle;
        }

        else if(command == "enter") {
            std::string name;
            int age{0};
            ss >> name >> age;
            Person person{name, age};
            motorcycle->enter(person);
        }

        else if(command == "leave") {
            motorcycle->leave();
        }

        else if(command == "buy") {
            int time{0};
            ss >> time;
            motorcycle->buyTime(time);
        }

        else if(command == "honk") {
            motorcycle->honk();
        }

        else if(command == "drive") {
            int time{0};
            ss >> time;
            motorcycle->drive(time);
        }
        
        else if(command == "end") {
            motorcycle->leave();
            break;
        }

        
    }
    return 0;
}