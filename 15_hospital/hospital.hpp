#include "medico.hpp"

class hospital {
private:
    std::map<std::string, std::shared_ptr<IMedico>> medicos;
    std::map<std::string, std::shared_ptr<IPaciente>> pacientes;

public:
    void addMedico(std::shared_ptr<IMedico> medico) {
        if(medicos.find(medico->getId()) == medicos.end()) {
            medicos[medico->getId()] = medico;
        }
        else {
            std::cout << "fail: medico ja cadastrado" << '\n';
        }
    }

    void addPaciente(std::shared_ptr<IPaciente> paciente) {
        if(pacientes.find(paciente->getId()) == pacientes.end()) {
            pacientes[paciente->getId()] = paciente;
        }
        else {
            std::cout << "fail: paciente ja cadastrado" << '\n';
        }
    }

    void removerMedico(std::string idMedico) {
        if(medicos.find(idMedico) != medicos.end()) {
            medicos.erase(idMedico);
        }
        else {
            std::cout << "fail: medico nao cadastrado" << '\n';
        }
    }

    void removerPaciente(std::string idPaciente) {
        if(pacientes.find(idPaciente) != pacientes.end()) {
            pacientes.erase(idPaciente);
        }
        else {
            std::cout << "fail: paciente nao cadastrado" << '\n';
        }
    }

    std::string showALL() {
        std::stringstream ss;

        for(auto& paciente : this->pacientes) {
            ss << paciente.second->toString() << '\n';
        }
        for(auto& medico : this->medicos) {
            ss << medico.second->toString() << '\n';
        }
        return ss.str();
    }

    void vincularPaciente(std::string idMedico, std::string idPaciente) {
        if( (this->pacientes.find(idPaciente) == this->pacientes.end()) || (this->medicos.find(idMedico) == this->medicos.end()) ) {
            std::cout << "fail: medico ou paciente nao cadastrado" << '\n';
        }
        else {
            auto pacientesMed = this->pacientes[idPaciente].get()->getMedicos();
            if(std::find(pacientesMed.begin(), pacientesMed.end(), this->medicos[idMedico].get()) != pacientesMed.end()) {
                std::cout << "fail: medico ja vinculado ao paciente" << '\n';
            }
            else {
                for(auto medico : this->pacientes[idPaciente].get()->getMedicos()){
                    if(medico->getClasse() == this->medicos[idMedico]->getClasse()){
                        std::cout << "fail: ja existe outro medico com a especialidade";
                        std::cout << this->medicos[idMedico]->getClasse();
                    }
                }
                this->medicos[idMedico]->addPaciente(this->pacientes[idPaciente].get());
                this->pacientes[idPaciente].get()->addMedico(this->medicos[idMedico].get());
            }
        }
    }

    void desvincular(std::string idMedico, std::string idPaciente) {
        if( (this->pacientes.find(idPaciente) == this->pacientes.end()) || (this->medicos.find(idMedico) == this->medicos.end()) ) {
            std::cout << "fail: medico ou paciente nao cadastrado" << '\n';
        }
        else {
            this->medicos[idMedico]->removerPaciente(idPaciente);
            this->pacientes[idPaciente].get()->removerMedico(idMedico);
        }
    }
};
