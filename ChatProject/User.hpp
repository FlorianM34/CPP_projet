#ifndef DEF_USER
#define DEF_USER

#include "Genre.hpp"
#include "Room.hpp"

#include <iostream>
#include <string>


class User {
    private :   
        std::string firstname_;
        std::string lastname_;
        std::string mail_;
        Genre sexe_;
        int age_;
        Room currentRoom_;
        
    
    public : 

        User(std::string firstname, std::string lastname, std::string mail, Genre sexe, int age_);

};

    



#endif