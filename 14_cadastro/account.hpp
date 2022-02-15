#include "libraries.hpp"

class Account {
protected:
    float balance{};
    std::string clientId{};
    int id{};
    std::string type{};
public:
    Account(int id, std::string clientId) : id{id}, clientId{clientId} {}

    virtual ~Account() {}

    // Deposita o valor na conta
    void deposit(float value) {
        this->balance += value;
    }

    // Método abstrato 
    virtual void monthlyUpdate() = 0;

    // Transfere o valor (value) da conta para a outra conta
    void transfer(Account &other, float value) {
        this->balance -= value;
        other.balance += value;
    }

    // saca o valor (value) da conta
    void withdraw(float value) {
        this->balance -= value;
    }

    float getBalance() const {
        return this->balance;
    }

    std::string getClientId() const {
        return this->clientId;
    }

    int getId() const {
        return this->id;
    }

    std::string getType() const {
        return this->type;
    }

    friend std::ostream &operator<<(std::ostream& os, const Account& account) {        
        os << account.getId() << ":" << account.getClientId() << ":" << account.getBalance() << ":" << account.getType();
        return os;
    }
};
