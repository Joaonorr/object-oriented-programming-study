#include "Ipaciente.hpp"

class IMedico {
public:
    virtual ~IMedico() {}
    virtual void addPaciente(IPaciente* paciente) = 0;
    //virtual void atendimento(IPaciente* paciente) = 0;
    virtual std::string getClasse() = 0;
    virtual std::string getId() = 0;
    virtual std::vector<IPaciente*> getPacientes() = 0;
    virtual void removerPaciente(std::string idPaciente) = 0;
    virtual std::string toString() = 0;
};
