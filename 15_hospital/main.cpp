#include "hospital.hpp"

int main() {
    hospital hospital;

    while(true) {
        std::cout << "$";
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if(command == "addPacs") {
            std::string id;
            while(ss >> id) {
                hospital.addPaciente(std::make_shared<Paciente>(id));
            }
        }
        else if(command == "addMeds") {
            std::string id;
            while(ss >> id) {
                hospital.addMedico(std::make_shared<Medico>(id));
            }
        } 
        else if(command == "show") {
            std::cout << hospital.showALL() << '\n';
        }
        else if(command == "tie") {
            std::string idMedico{};
            std::string idPaciente{};
            ss >> idMedico;
            while(ss >> idPaciente) {
                hospital.vincularPaciente(idMedico, idPaciente);
            }
        }
        else if(command == "untie") {
            std::string idMedico{};
            std::string idPaciente{};
            ss >> idMedico;
            while(ss >> idPaciente) {
                hospital.desvincular(idMedico, idPaciente);
            }
        }
        else if(command == "rmMed") {
            std::string id;
            ss >> id;
            hospital.removerMedico(id);
        }
        else if(command == "rmPac") {
            std::string id;
            ss >> id;
            hospital.removerPaciente(id);
        }
        else if(command == "end") {
            break;
        }
    }
}