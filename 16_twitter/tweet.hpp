#include "libraries.hpp"

class Tweet {
private:
    int id{};
    std::string username{};
    std::string msg{};
    std::set<std::string> likes{};
    Tweet *rt{nullptr};
    bool delered{false};

public:
    Tweet(int id, std::string username, std::string msg) : 
        id{id}, 
        username{username}, 
        msg{msg} 
    {}

    int getId() {
        return this->id;
    }

    std::string getSender() {
        return this->username;
    }

    std::string getMsg() {
        return this->msg;
    }

    void like(std::string username) {
        this->likes.insert(username);
    }

    std::set<std::string> getLikes() {
        return this->likes;
    }

    void setRt(Tweet *rt) {
        this->rt = rt;
    }

    void setDeleted() {
        this->delered = true;
        this->username = "";
        this->msg = "tweet deletado";
        this->likes.clear();
    }

    bool isDelered() {
        return this->delered;
    }

    friend std::ostream &operator<<(std::ostream& os, Tweet& tweet){
        os << tweet.getId() << ":" << tweet.username << " (" << tweet.msg << ")";
        if((int) tweet.likes.size() > 0){
            os << "  " << "[";

            int size = 1;
            for(auto user : tweet.likes){
                if(size < (int) tweet.likes.size()){
                    os << user << ", ";

                }else{
                    os << user;
                }

                size++;
            }

            os << "]";
        }

        if(tweet.rt != nullptr){
            os << "\n\t" << *tweet.rt;
        }

        return os; 
    }
};
