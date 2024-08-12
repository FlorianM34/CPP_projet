#include <iostream>
#include <string>
#include "PlayerNotFoundException.hpp"
#include "Room.hpp"
#include <cstdlib> 

using namespace std;

Room::Room(string roomName, int maxChaters) : roomName_(roomName), maxChaters_(maxChaters)
{

    time_t tempsActuel = time(nullptr);
    tm *date = localtime(&tempsActuel);

    string dateStr =
        std::to_string(date->tm_mday) + "/" +
        std::to_string(date->tm_mon + 1) + "/" +
        std::to_string(date->tm_year + 1900);

    dateStr_ = dateStr;

    int roomId = rand();
    roomId_ = to_string(roomId);

}

Room::Room() : roomName_("waitingRoom"), maxChaters_(100) {}


////////////////////////////////////////////////////////////////////////////

void Room::isIpExist(string ip){
    for( User user : userList_ ){
        if(user.getIp() == ip){
            return ;
        }
    }

    throw PlayerNotFoundException("This player ip do not exist", 1);
}

void Room::isNameExist(string name){ 
    for( User user : userList_ ){
        if(user.getFirstname() == name){
            return ;
        }
    }

    throw PlayerNotFoundException("This player ip do not exist", 2);
}


int Room::getMaxChaters() {
    return maxChaters_;
}

string Room::getRoomName(){
    return roomName_;
}
string Room::getDate(){
    return dateStr_;
}
vector<User> Room::getUserList(){
    return userList_;
}

vector<string> Room::getBannedUsersIp(){
    return bannedIpList_;
}

void Room::renameRoom(string roomName){
    roomName_ = roomName;
}
void Room::changeMaxChaters(int maxChaters){
    maxChaters_ = maxChaters;
}


void Room::banByIp(std::string ip){
    try {
        isIpExist(ip);

        for( User user : userList_){
            if(user.getIp() == ip){
                // bannedUsername = user.getUsername();
                bannedIpList_.push_back(user.getIp());
                return;

            }
        }

        
    } catch(PlayerNotFoundException e){
        cout << "error number " << e.getCode() << "message  : \n" << e.what() << endl;
    }

    
}

void Room::banByName(std::string name){

}

void Room::kickByName(std::string name){

}
void Room::kickByIp(std::string ip){

}

