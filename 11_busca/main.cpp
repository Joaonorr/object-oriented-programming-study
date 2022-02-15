#include "agenda.hpp"

int main() {
    Agenda agenda;
    int cont{0};

    while(true) {
        std::cout << "$";
        std::string line{};
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string command{};
        ss >> command;

        

        if(command == "add") {
            for(char &caracter: line) {
                if(caracter == ':') {
                    caracter = ' ';
                }
            }
            std::stringstream ss2(line);
            std::string buffer{};
            ss2 >> buffer;
            std::string name{};
            ss2 >> name;
            std::list<Fone> fones;
            std::string id;
            std::string number;
            while(ss2 >> id >> number) {
                fones.push_back(Fone(id, number));
            };   

            agenda.addContact(name, fones);
        }
        else if(command == "rmFone") {
            std::string name{};
            std::string aux{};            
            ss >> name >> aux;
            int pos = std::stoi(aux);
            Contact *contact = agenda.findContact(name);
            if(contact != nullptr) {
                contact->rmFone(pos);
            }
        }
        else if(command == "rm") {
            std::string name{};
            ss >> name;
            agenda.rmContact(name);
        }
        else if(command == "search") {
            std::string regularExpression{};
            ss >> regularExpression;
            for(auto &contacts : agenda.search(regularExpression)) {
                std::cout << contacts << '\n';
            }


        }
        else if(command == "show") {
            std::cout << agenda;
        }
        else if(command == "end") {
            break;
        }
            
        
        if(cont == 100) {
            break;
        }
        cont++;
    }
}

// SHELL 

// #__case adicionando em lote
// $add eva oio:8585 cla:9999
// $add ana tim:3434 
// $add bia viv:5454

// # como ana já existe, não crie um novo contato
// # adicione os telefones ao contato existente
// $add ana cas:4567 oio:8754

// $show
// - ana [0:tim:3434] [1:cas:4567] [2:oio:8754]
// - bia [0:viv:5454]
// - eva [0:oio:8585] [1:cla:9999]


// #__case removendo telefone
// # remove o elemento indice 0 da ana
// $rmFone ana 0

// $show
// - ana [0:cas:4567] [1:oio:8754]
// - bia [0:viv:5454]
// - eva [0:oio:8585] [1:cla:9999]

// #__case removendo contato
// $rm bia

// $show
// - ana [0:cas:4567] [1:oio:8754]
// - eva [0:oio:8585] [1:cla:9999]

// $add ava tim:5454
// $add rui viv:2222 oio:9991
// $add zac rec:3131

// $show
// - ana [0:cas:4567] [1:oio:8754]
// - ava [0:tim:5454]
// - eva [0:oio:8585] [1:cla:9999]
// - rui [0:viv:2222] [1:oio:9991]
// - zac [0:rec:3131]

// #__case busca por padrao
// $search va
// - ava [0:tim:5454]
// - eva [0:oio:8585] [1:cla:9999]

// $search 999
// - eva [0:oio:8585] [1:cla:9999]
// - rui [0:viv:2222] [1:oio:9991]

// $end

// #__end__