#ifndef DEF_ROOM
#define DEF_ROOM

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "User.hpp"


class Room {
    private :
        std::string roomName_;
        int maxChaters_;
        std::string dateStr_;
        std::vector<User> userList_;
        std::vector<std::string> bannedIpList_;
        
        void isIpExist(std::string ip);
        void isNameExist(std::string name);

        std::string roomId_;

        
    public :

        Room(std::string roomName, int maxChaters);
        Room();

        int getMaxChaters();
        std::string getRoomName();
        std::string getDate();
        std::vector<User> getUserList();
        std::vector<std::string> getBannedUsersIp();

        void renameRoom(std::string roomName);
        void changeMaxChaters(int maxChaters);
        

        void banByIp(std::string ip);
        void banByName(std::string name);
        void kickByName(std::string name);
        void kickByIp(std::string ip);

        

};


#endif