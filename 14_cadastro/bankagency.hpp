#include "client.hpp"

class BankAgency {
private:
    std::map<int, std::shared_ptr<Account>> accounts{};
    std::map<std::string, std::shared_ptr<Client>> clients{};
    int nextAccountId{0};

    std::shared_ptr<Account> getAccont(int id) {
        return accounts[id];
    }

public:
    BankAgency() {};

    void next() {
        nextAccountId++;
    }

    bool accountVerifty(int id) {
        if( (id < 0) || (id > this->nextAccountId) ){
            return true;
        }
        return false;
    }
    
    void addClient(std::string clientId) {
        this->clients[clientId] = std::make_shared<Client>(clientId);

        this->accounts[this->nextAccountId] = std::make_shared<CheckingAccount>(this->nextAccountId, clientId);
        this->clients[clientId].get()->addAccount(this->getAccont(this->nextAccountId));
        this->next();

        this->accounts[this->nextAccountId] = std::make_shared<SavingAccount>(this->nextAccountId, clientId);
        this->clients[clientId].get()->addAccount(this->getAccont(this->nextAccountId));
        this->next();
    }

    void deposit(int id, float value) {
        if(this->accountVerifty(id)) {
            std::cout << "fail: invalid account" << '\n';
        } 
        else {
            this->accounts[id].get()->deposit(value);
        }
    }

    void monthlyUpdate() {
        std::map<int, std::shared_ptr<Account>>::iterator it = this->accounts.begin();
        for(; it != this->accounts.end(); it++) {
            it->second.get()->monthlyUpdate();
        }
    }

    void transfer(int fromId, int toId, float value) {
        if(this->accountVerifty(fromId) || this->accountVerifty(toId)) {
            std::cout << "fail: invalid account" << '\n';
        }
        else if(this->accounts[fromId].get()->getBalance() < value) {
            std::cout << "fail: insufficient balance" << '\n';
        }
        else {
            this->accounts[fromId].get()->withdraw(value);
        }        
    }

    void withdraw(int id, float value) {
        if(this->accountVerifty(id)) {
            std::cout << "fail: invalid account" << '\n';
        }
        else if(this->accounts[id].get()->getBalance() < value) {
            std::cout << "fail: insufficient balance" << '\n';
        }
        else {
            this->accounts[id].get()->withdraw(value);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, BankAgency& bank) {
        os << "Clients:" << '\n';
        for(auto& client : bank.clients) {
            os << "- " << client.first << "[";
            int i{1};
            for(auto& clientAccount : client.second.get()->getAccounts()) {
                if(i < (int) client.second.get()->getAccounts().size()) {
                    os << clientAccount->getId() << ", ";
                    i++;
                }
                else {
                    os << clientAccount->getId() << "]";
                }
            }
            os << '\n';
        }
        os << "Accounts:" << '\n';
        for(auto& account : bank.accounts) {
            os << "- " << *account.second << '\n';
        }
        return os;
    }
};
