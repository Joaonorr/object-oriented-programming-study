#include "controller.hpp"

int main(){
    Controller controller;

    while(true){
        std::cout << "$";
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string command;
        ss >> command;

            if(command == "add") {
                std::string username;
                ss >> username;
                controller.addUser(username);
            }
            else if(command == "follow") {
                std::string user;
                std::string other;
                ss >> user >> other;
                controller.getUser(user)->follow(controller.getUser(other));
            
            }
            else if(command == "rm") {
                std::string username;
                ss >> username;
                controller.rmUser(username);
            }
            else if(command == "like") {
                std::string username;
                int idMsg;
                ss >> username >> idMsg;
                controller.getUser(username)->like(idMsg);            
            }
            else if(command == "twittar") {
                std::string username;
                std::string msg;
                ss >> username;
                getline(ss, msg);
                controller.sendTweet(username, msg.substr(1));
            
            }
            else if(command == "rt") {
                std::string username;
                int id;
                std::string msg;
                ss >> username >> id;
                getline(ss, msg);
                controller.sendRt(username, id, msg.substr(1));
            }
            else if(command == "timeline") {
                std::string username;
                ss >> username;
                std::cout << *controller.getUser(username)->getInbox() << '\n';            
            }
            else if(command == "unfollow") {
                std::string user;
                std::string other;
                ss >> user >> other;
                controller.getUser(user)->unfollow(controller.getUser(other));
            
            }
            else if(command == "show") {
                std::cout << controller;
            
            }
            else if(command == "end") {
                break;
            }       
    }
    return 0;
}    
