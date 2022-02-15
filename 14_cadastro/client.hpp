#include "cp_account.hpp"

class Client {
private:
    std::list<std::shared_ptr<Account>> accounts{};
    std::string clientId{};

public:
    Client(std::string clientId) : clientId{clientId} {}

    void addAccount(std::shared_ptr<Account> account) {
        this->accounts.push_back(account);
    }

    std::list<std::shared_ptr<Account>> getAccounts() {
        return this->accounts;
    }

    std::string getClientId() {
        return this->clientId;
    }

    void setAcconts(std::list<std::shared_ptr<Account>> accounts) {
        this->accounts = accounts;
    }

    void setClientId(std::string clientId) {
        this->clientId = clientId;
    }

    friend std::ostream &operator<<(std::ostream& os, const Client& client) {
        for(auto& account : client.accounts) {
            os << account << "\n";
        }
        return os;
    }
};
