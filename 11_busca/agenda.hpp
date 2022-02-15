#include "contact.hpp"

static bool ordena_por_nome(Contact a, Contact b) {
    return a.getName() < b.getName();
}

class Agenda {
private:
    std::list<Contact> contacts{};
    
    int findPosByName(std::string name) {
        int pos = 0;
        if(!contacts.empty()) {
            for(auto it : contacts) {
                if(it.getName() == name) {
                    return pos;
                }
                pos++;
            }
        }
        return -1;
    }

public:    
    Agenda(){};

    void addContact(std::string name, std::list<Fone> fones) {
        //std::transform(name.begin(), name.end(), name.begin(), ::tolower);
        if(findPosByName(name) == -1) {
            this->contacts.push_back(Contact(name, fones));
        }
        else if(true){
            std::list<Contact>::iterator it = contacts.begin();
            std::advance(it, findPosByName(name));
            for(auto fone : fones) {
                it->addFone(fone);
            }
        }
        else {
            std::cout << "fail: contact already exists!" << "\n";
        }
        //ordenar lista
        if(!this->contacts.empty()) {
            contacts.sort(ordena_por_nome);
        }
    }

    Contact *findContact(std::string name) {
        int pos = findPosByName(name);
        if(pos != -1) {
            std::list<Contact>::iterator it = contacts.begin();
            std::advance(it, pos);
            return &(*it);
        }
        std::cout << "fail: contact not found" << '\n';
        return nullptr;
    }

    void rmContact(std::string name) {
        int pos = findPosByName(name);
        if(pos != -1) {
            std::list<Contact>::iterator it = contacts.begin();
            std::advance(it, pos);
            contacts.erase(it);
        }
        //std::cout << "fail: contact not found" << '\n';
    }


    std::list<Contact> getContacts() {
        return contacts;
    }

    std::list<Contact> search(std::string re) {
        std::list<Contact> retorno;
        std::list<Contact>::iterator it = contacts.begin();
        for(; it != contacts.end(); it++) {
            if(it->getName().find(re) != std::string::npos) {
                retorno.push_back(*it);
            }
            else {
                for(auto fone : it->getFones()) {
                    if( (fone.getId().find(re)!= std::string::npos) || (fone.getNumber().find(re) != std::string::npos)) {
                        retorno.push_back(*it);
                    }
                }
            }
        }
        return retorno;
        
    }

    friend std::ostream& operator<<(std::ostream& os, Agenda& agenda) {
        for(auto it : agenda.contacts) {
            os << "- " << it << '\n';
        }
        return os;
    }
    

};