#include "kid.hpp"

class Trampoline {
private:
    std::list<Kid> playing;
    std::list<Kid> waiting;
    Kid *removeKid(std::string name, std::list<Kid>& list) {
        for(auto it = list.begin(); it != list.end(); it++) {
            if(it->getName() == name) {
                Kid *kid = &(*it);
                list.erase(it);
                return kid;
            }
        }
        return nullptr;
    }
public:
    Trampoline(){}

    void arrive(Kid kid) {
        waiting.push_front(kid);
    }

    void enter() {
        if(!waiting.empty()) {
            playing.push_front(waiting.back());
            waiting.erase(--waiting.end());
        }
    }

    void leave() {
        if(!playing.empty()) {
            waiting.push_front(playing.back());
            playing.erase(--playing.end());
        }
    }

    void remove(std::string name) {
        Kid *kid = removeKid(name, playing);
        if(kid == nullptr) {
            kid = removeKid(name, waiting);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Trampoline& trampoline) {
        os << "=> ";
        for(auto it = trampoline.waiting.begin(); it != trampoline.waiting.end(); it++) {
            os << *it << " ";
        }
        os << "=> " << "[ ";
        for(auto it = trampoline.playing.begin(); it != trampoline.playing.end(); it++) {
            os << *it << " ";
        }
        os << "]";
        return os;
    }
};
