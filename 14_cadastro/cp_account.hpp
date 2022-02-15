#include "cc_account.hpp"

class SavingAccount : public Account {
public:
    SavingAccount(int id, std::string clientId) : Account{id, clientId} {
        this->type = "CP";
    }

    void monthlyUpdate() {
        this->balance *= 1.1;
    }
};
