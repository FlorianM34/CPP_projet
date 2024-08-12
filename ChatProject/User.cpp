#include <iostream>
#include <string>

#include "Genre.hpp"
#include "User.hpp"
#include <cstdlib> 

using namespace std;


User::User(std::string firstname, std::string lastname, std::string mail, Genre sexe, int age) : firstname_(firstname), lastname_(lastname), mail_(mail), sexe_(sexe), age_(age) {
    int userId = rand();
    userId_ = to_string(userId);
    username_ = firstname + lastname;
    //logique pour initialiser l'adresse ip du joueurx

}



string User::getFirstname(){
    return firstname_;
}
string User::getLastname(){
    return lastname_;
}
string User::getMail(){
    return mail_;
}
string User::getIp(){
    return ip_;
}

int User::getAge() {
    return age_;
}

string User::getUserId() {
    return userId_;
}

Room User::getCurrentRoom() {
    return currentRoom_;
}






void User::sendMail(std::string playerName){

}