#include "tweet.hpp"

class Inbox {
private:
    std::map<int, Tweet*> timeline{};
    std::map<int, Tweet*> myTweets{};

public:
    Inbox() {}

    std::list<Tweet*> getTimeline() {
        std::list<Tweet*> timeline;
        for (auto const& pair : this->timeline) {
            timeline.push_back(pair.second);
        }
        return timeline;
    }

    Tweet* getTweet(int id) {
        auto it{this->timeline.find(id)};
        if(it == (this->timeline.end()) ) {
            std::cout << "fail: tweet nao existe";
            return nullptr;
        }
        else {
            return it->second;
        }
    }

    void rmMsgsFrom(std::string username) {
        for (auto const& pair : this->timeline) {
            if(pair.second->getSender() == username) {
                pair.second->setDeleted();
            }
        }
    }

    void storeInTimeline(Tweet *tweet) {
        this->timeline[tweet->getId()] = tweet;
    }

    void storeInMyTweets(Tweet *tweet) {
        this->myTweets[tweet->getId()] = tweet;
        this->timeline[tweet->getId()] = tweet;
    }

    std::list<Tweet*> getMyTweets() {
        std::list<Tweet*> myTweets;
        for (auto const& pair : this->myTweets) {
            myTweets.push_back(pair.second);
        }
        return myTweets;
    }

    friend std::ostream &operator<<(std::ostream& os, Inbox& inbox) {
        for(auto msg : inbox.getTimeline()) {
            os << *msg << "\n";
        }
        return os;
    }
};
