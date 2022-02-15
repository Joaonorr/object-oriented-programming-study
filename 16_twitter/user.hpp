#include "inbox.hpp"

class User {
private:
    std::string username{};
    Inbox inbox{};
    std::map<std::string, User*> followers{};
    std::map<std::string, User*> following{};

public:
    User(std::string username) : username{username} {}

    void follow(User *other) {
        this->following[other->username] = other;
        other->followers[this->username] = this;
    }

    Inbox* getInbox() {
        return &this->inbox;
    }

    void sendTweet(Tweet *tweet) {
        inbox.storeInMyTweets(tweet);
        inbox.storeInTimeline(tweet);
        for(auto pair : this->followers) {
            pair.second->getInbox()->storeInTimeline(tweet);
        }
    }

    void unfollow(User *other) {
        this->inbox.rmMsgsFrom(other->username);
        this->following.erase(other->username);
        other->followers.erase(this->username);
    }

    void like(int id) {
        inbox.getTweet(id)->like(this->username);
    }

    void unfollowAll(){
        for(auto user : this->following){
            user.second->followers.erase(this->username);
        }
        this->following.clear();
    }

    void rejectAll() {
        for(auto user : this->followers){
            user.second->following.erase(this->username);
        }
        this->followers.clear();
    }

    friend std::ostream &operator<<(std::ostream& os, const User& user){
        os << user.username << "\n";
        os << "  seguidos   [";
        int size = 1;

        for(auto followingSp : user.following){
            if(size < (int) user.following.size()){
                os << followingSp.first << ", ";
            }else{
                os << followingSp.first; 
            }

            size++;
        }

        os << "]\n";
        
        os << "  seguidores [";
        size = 1;

        for(auto followersSp : user.followers){
            if(size < (int) user.followers.size()){
                os << followersSp.first << ", ";
            }else{
                    os << followersSp.first; 
            }
            size++;
        }
        os << "]\n";
        return os;
    }
};
