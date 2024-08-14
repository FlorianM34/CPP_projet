#ifndef DEF_SERVER
#define DEF_SERVER

#include <iostream>
#include <string>
#include <vector>
#include "Room.hpp"
#include <netinet/in.h>

#define PORT 8080;

class Server {

    private :
    
        int server_fd;
        int port;
        struct sockaddr_in address;
        int addrlen;

        void handleClient(int client_socket);

        void createRoom(std::string roomName, int maxPlayer);
    
    public :  
        std::vector<Room> roomList;
        Server(int port);  // Constructeur public
        ~Server();
        void start();

};

#endif