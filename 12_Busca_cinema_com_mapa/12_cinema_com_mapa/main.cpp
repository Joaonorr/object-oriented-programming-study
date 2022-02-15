#include "sala.hpp"

int main() {
    Sala sala(1);
    int loop_stop = 0;

    while(true) {
        std::cout << "$";
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if(command == "init") {
            int size{};
            ss >> size;
            sala = Sala(size);
        }
        else if(command == "reservar") {
            std::string id{};
            std::string fone{};
            int pos{};
            ss >> id >> fone >> pos;
            sala.reservar(id, fone, pos);
        }
        else if(command == "cancelar") {
            std::string id{};
            ss >> id;
            sala.cancelar(id);
        }
        else if(command == "show") {
            std::cout << sala << '\n';
        }
        else if(command == "end") {
            break;
        }
        loop_stop++;
        if(loop_stop > 100) {
            std::cout << "fail: loop_stop" << '\n';
            break;
        }
    }
    return 0;
}