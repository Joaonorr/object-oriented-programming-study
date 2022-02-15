#include "account.hpp"

class CheckingAccount : public Account {
public:
    CheckingAccount(int id, std::string clientId) : Account{id, clientId} {
        this->type = "CC";
    }

    void monthlyUpdate() {
        this->balance -= 20;
    }
};
