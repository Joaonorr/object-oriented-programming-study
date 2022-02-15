#include "lead.hpp"

class Pencil {
public:
    Lead *lead{nullptr};
    float thickness{0.0};

    Pencil(float thickness = 0.0) {
        this->thickness = thickness;
        this->lead = nullptr;
    }

    bool hasGraphite() {
        if(this->lead == nullptr) {
            return false;
        }
        return true;
    }

    bool compare(Lead *lead) {
        if(this->thickness == lead->getThickness()) {
            return true;
        }
        std::cout << "fail: calibre incompatível" << '\n';
        return false;
    }

    void insertGraphite(Lead *lead) {
        if(!hasGraphite() && compare(lead)) {
            this->lead = lead;
        }
        else if(hasGraphite()) {
            std::cout << "fail: ja existe grafite" << "\n";
            delete lead;
        }
    }

    void remove() {
        if(hasGraphite()) {
            delete this->lead;
            this->lead = nullptr;
        }
    }
    
    void writePage() {
        if(!hasGraphite() || this->lead->getSize() <= 10) {
            std::cout << "warning: grafite com tamanho insuficiente para escrever" << "\n";
        }
        else if(this->lead->getSize() > 10) {
            this->lead->setSize(this->lead->getSize() - this->lead->usagePerSheet());
        }
        if(this->lead->getSize() < 10) {
            std::cout << "fail: folha incompleta" << "\n";
            this->lead->setSize(10);
        }
    }

    float getThickness() {
        return this->thickness;
    }

    friend std::ostream& operator<<(std::ostream& os, const Pencil& P) {
        os << "calibre: " << P.thickness << ", grafite: ";
        if(P.lead != nullptr) {
            os << *P.lead << "\n";
        }
        else {
            os << "null" << "\n";
        }
        return os;
    }
};
