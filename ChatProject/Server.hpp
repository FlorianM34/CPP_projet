#ifndef DEF_SERVER
#define DEF_SERVER

#include <iostream>
#include <string>
#include <vector>
#include <netinet/in.h>


class Message ;

#define PORT 8080;

class Room;

class Server {

    private :
    
        int server_fd;
        int port;
        struct sockaddr_in address;
        int addrlen;

        void handleClient(int client_socket);

        void createRoom(std::string roomName, int maxPlayer);

        Room *room;

        void handleCommand(std::string contentBuffer, ssize_t contentSize);
    
    public :  
        std::vector<Room*> roomList;
        Server(int port);  
        ~Server();
        void start();

};

#endif