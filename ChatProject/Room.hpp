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
        
    public :

        Room(std::string roomName, int maxChaters);
        Room();

};


#endif