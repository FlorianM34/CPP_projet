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
        

        std::string roomId_;


        void isPlayerAlreadyBanned(std::string ip);
        
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
        

        void banById(std::string id);
        void kickById(std::string id);

        

};


#endif