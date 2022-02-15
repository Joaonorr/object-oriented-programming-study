#include "libraries.hpp"

class IMedico;

class IPaciente {
public:
    virtual ~IPaciente() {}	
    virtual void addMedico(IMedico* medico) = 0;
    virtual std::string getDiagnostico() = 0;
    virtual std::string getId() = 0;
    virtual std::vector<IMedico*> getMedicos() = 0;
    virtual void removerMedico(std::string idMedico) = 0;
    virtual std::string toString() = 0;
};
