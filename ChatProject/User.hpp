#ifndef DEF_USER
#define DEF_USER

#include "Genre.hpp"
// #include "Room.hpp"

#include <iostream>
#include <string>
#include <netinet/in.h>


class User {
    private :   

        //Strings
        std::string firstname_;
        std::string lastname_;
        std::string username_;
        std::string mail_;
        std::string ip_;

        //int
        int age_;

        struct sockaddr_in serv_addr;
        int port_;
        int sock;
        int addrlen;
        char buffer[1024] = {0};
        std::string serverAddress_;
        std::string userId_;

        //custom
        Genre sexe_;
        // Room currentRoom_;
        
    
    public : 



        User(std::string serverAddress, int port);

        std::string getFirstname();
        std::string getLastname();
        std::string getMail();
        std::string getIp();
        int getAge();
        std::string getUserId();
        // Room getCurrentRoom();

        // void joinRoom(std::string roomId);
        // void leaveRoom();
        void sendMail(std::string playerName);

        void connectToServer();
        



};

    



#endif