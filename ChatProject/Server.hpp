#include <iostream>
#include <string>
#include <vector>
#include "Room.hpp"


class Server {

    private :
        std::vector<Room> roomList;
    
    public :  

        void createRoom(std::string roomName, int maxPlayer);

};