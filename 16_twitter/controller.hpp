#include "user.hpp"

class Controller{
private:
    int nextTweetId{0};
    std::map<int, std::shared_ptr<Tweet>> tweets{};
    std::map<std::string, std::shared_ptr<User>> users{};

    Tweet* createTweet(std::string sender, std::string msg) {
        auto tweet = std::make_shared<Tweet>(nextTweetId++, sender, msg);
        this->tweets[tweet->getId()] = tweet;
        return tweet.get();
    }

public:
    Controller() {}
    

    void addUser(std::string username) {
        if(users.find(username) == users.end()) {
            users[username] = std::make_shared<User>(username);        
        }
        else {
            std::cout << "fail: usuario ja cadastrado";
        }
    }

    User* getUser(std::string username) {
        if(users.find(username) != users.end()) {
            return this->users[username].get();        
        }
        else {
            std::cout << "fail: usuario ja cadastrado";
        }
        return nullptr;
    }

    void sendTweet(std::string username, std::string msg) {
        getUser(username)->sendTweet(createTweet(username, msg));
    }

    void sendRt(std::string username, int twId, std::string msg) {
        Tweet* rt = getUser(username)->getInbox()->getTweet(twId);
        Tweet* tw = createTweet(username, msg);

        tw->setRt(rt);
        getUser(username)->sendTweet(tw);
    }

    void rmUser(std::string username) {
        User* user = this->getUser(username);
        user->unfollowAll();
        user->rejectAll();

        for(auto tweet : user->getInbox()->getMyTweets()){
            tweet->setDeleted();
        }
        this->users.erase(username);
    }

    friend std::ostream &operator<<(std::ostream& os, const Controller& controller) {
        for(auto user : controller.users){
            os << *user.second;
        }
        return os;
    }

};
