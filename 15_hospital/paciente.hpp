#include "IMedico.hpp"

class Paciente : public IPaciente {
protected:
    std::string diagnostico{};
    std::map<std::string, IMedico*> medicos{};
    std::string sender{};

public:
    Paciente(std::string sender, std::string diagnostico) : diagnostico{diagnostico}, sender{sender} {}

    void addMedico(IMedico* medico) override {
        medicos[medico->getId()] = medico;
    }

    std::string getDiagnostico() override {
        return this->diagnostico;
    }

    std::string getId() override {
        return this->sender;
    }

    std::vector<IMedico*> getMedicos() override {
        std::vector<IMedico*> medicos;
        for (auto& medico : this->medicos) {
            medicos.push_back(medico.second);
        }
        return medicos;
    }

    void removerMedico(std::string idMedico) override {
        this->medicos.erase(idMedico);
    }

    std::string toString() {
        std::stringstream ss;
        ss << "Pac: " << this->sender << ":" << this->diagnostico;
        ss << " Med[";
        for(auto &medico : this->getMedicos()) {
            ss << medico->getId() << ",";
        }
        ss << "]";
        return ss.str();
    }

    friend std::ostream& operator<<(std::ostream& os,Paciente& paciente) {
        os << "Paciente: " << paciente.sender << " - " << paciente.diagnostico;
        for(auto medico : paciente.getMedicos()) {
            os << medico->getId() << " ";
        }
        return os;
    }
};
