#include <iostream>
#include <string>
#include <cstdlib> 
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <unistd.h>

#include "PlayerNotFoundException.hpp"
#include "Room.hpp"
#include "User.hpp"

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

int Room::getMaxChaters() {
    return maxChaters_;
}

string Room::getRoomName(){
    return roomName_;
}
string Room::getDate(){
    return dateStr_;
}
vector<User*> Room::getUserList(){
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

void Room::isPlayerAlreadyBanned(std::string ip) {

}

void Room::banById(std::string id){

    try {

        for( const auto &user : userList_){
            if(user->getUserId() == id){
                // request server to kick this player
                bannedIpList_.push_back(user->getIp());
                return;

            }
        }

        throw PlayerNotFoundException("No player found with this name", 1);

        
    } catch(PlayerNotFoundException e){
        cout << "error number " << e.getCode() << "message  : \n" << e.what() << endl;
    }    

}

void Room::kickById(std::string id){
    try {

    for( const auto &user : userList_){
        if(user->getUserId() == id){
            // request server to kick this player
            return;

        }
    }

    throw PlayerNotFoundException("No player found with this name", 2);

    
} catch(PlayerNotFoundException e){
    cout << "error number " << e.getCode() << "message  : \n" << e.what() << endl;
}    
}


