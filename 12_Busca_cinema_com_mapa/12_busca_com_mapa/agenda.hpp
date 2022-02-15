#include "contact.hpp"


class Agenda {
private:
    std::map<std::string, Contact> contacts;

public:    
    Agenda(){};

    void addContact(std::string name, std::list<Fone> fones) {
        if(!contacts.count(name)) {
            contacts[name] = Contact(fones);
        }
        else {
            for(auto fone : fones) {
                contacts[name].addFone(fone);
            }
        }

    }

    Contact *findContact(std::string name) {
        if(contacts.count(name)) {
            return &contacts[name];
        }
        return nullptr;
    }

    void rmContact(std::string name) {
        if(contacts.count(name)) {
            contacts.erase(name);
        }
        std::cout << "fail: contact not found" << '\n';
    }


    std::map<std::string, Contact> getContacts() {
        return contacts;
    }

    std::list<Contact> search(std::string re) {
        std::list<Contact> retorno;
        std::map<std::string, Contact>::iterator it = contacts.begin();
        for(; it != contacts.end(); it++) {
            if(it->first.find(re) != std::string::npos) {
                retorno.push_back(it->second);
            }
            else {
                for(auto fone : it->second.getFones()) {
                    if( (fone.getId().find(re)!= std::string::npos) || (fone.getNumber().find(re) != std::string::npos)) {
                        retorno.push_back(it->second);
                    }
                }
            }
        }
        return retorno;
    }

    friend std::ostream& operator<<(std::ostream& os, Agenda& agenda) {
        for(auto it : agenda.contacts) {
            os << "- " << it.first << it.second << '\n';
        }
        return os;
    }
    

};