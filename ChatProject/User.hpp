#ifndef DEF_USER
#define DEF_USER

#include "Genre.hpp"
#include "Room.hpp"

#include <iostream>
#include <string>


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
        std::string userId_;

        //custom
        Genre sexe_;
        Room currentRoom_;
        
    
    public : 

        User(std::string firstname, std::string lastname, std::string mail, Genre sexe, int age);

        std::string getFirstname();
        std::string getLastname();
        std::string getMail();
        std::string getIp();
        int getAge();
        std::string getUserId();
        Room getCurrentRoom();

        void joinRoom(std::string roomId);
        void leaveRoom();
        void sendMail(std::string playerName);



};

    



#endif