#include "paciente.hpp"

class Medico : public IMedico {
protected:
    std::string classe{};
    std::map<std::string, IPaciente*> pacientes{};
    std::string id{};

public:
    Medico(std::string id, std::string classe) :id{id}, classe{classe} {}

    void addPaciente(IPaciente* paciente) override {
        pacientes[paciente->getId()] = paciente;
    }

    std::string getClasse() override {
        return this->classe;
    }

    std::string getId() override {
        return this->id;
    }

    std::vector<IPaciente*> getPacientes() override {
        std::vector<IPaciente*> pacientes;
        for (auto& paciente : this->pacientes) {
            pacientes.push_back(paciente.second);
        }
        return pacientes;
    }

    void removerPaciente(std::string idPaciente) override {
        this->pacientes.erase(idPaciente);
    }

    std::string toString() {
        std::stringstream ss;
        ss << "Med: " << this->id << " - " << this->classe;
        ss << " Pac[";
        for(auto paciente : this->getPacientes()) {
            ss << paciente->getId() << ",";
        }
        ss << "]";
        return ss.str();
    }

    friend std::ostream& operator<<(std::ostream& os, Medico& medico) {
        os << "Medico: " << medico.id << " - " << medico.classe;
        for (auto &paciente : medico.getPacientes()) {
            os << paciente->getId() << " ";
        }
        return os;
    }
};
