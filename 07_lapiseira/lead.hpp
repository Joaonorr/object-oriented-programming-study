#include "libraries.hpp"

class Lead {
public:
    // grossura
    float thinckness{0.0};
    //dureza
    std::string hardness{""};
    //tamanho
    int size{0};
    
    Lead(float thinckness, std::string hardness, int size) {
        this->thinckness = thinckness;
        this->hardness = hardness;
        this->size = size;
    }

    int usagePerSheet() {
        if(this->hardness == "HB") {
            return 1;
        }
        else if(this->hardness == "2B") {
            return 2;
        }
        else if(this->hardness == "4B") {
            return 4;
        }
        else {
            return 6;
        }
    }

    std::string getHardness() {
        return this->hardness;
    }

    int getSize() {
        return this->size;
    }

    float getThickness() {
        return this->thinckness;
    }

    void setSize(int size) {
        this->size = size;
    }

    friend std::ostream& operator<<(std::ostream& os, const Lead& L) {
        os << "[" << L.thinckness << ":" << L.hardness << ":" << L.size << "]";
        return os;
    }
};
