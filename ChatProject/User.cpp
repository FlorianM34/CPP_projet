#include <iostream>
#include <string>

#include "Genre.hpp"
#include "User.hpp"
#include <cstdlib> 
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;


User::User(std::string serverAddress, int port) 
    : serverAddress_(serverAddress), port_(port) {


    string firstname;
    string lastname;
    string age;

    cout << "enter firstname : ";
    cin >> firstname;

    cout << "enter lastname : ";
    cin >> lastname;

    cout << "enter age : ";
    cin >> age;

    firstname_ = firstname;
    lastname_ = lastname;
    age_ = stoi(age);


    int userId = rand();
    userId_ = to_string(userId);
    // username_ = firstname + lastname;
    ip_ = "0.0.0.0"; // use function later to get ip adress

    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }


    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);


    // Convertir l'adresse IP en binaire et la stocker dans serv_addr.sin_addr
    if (inet_pton(AF_INET, serverAddress_.c_str(), &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    connectToServer();

}

void User::connectToServer() {
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "Connection failed" << std::endl;
        return ;
    }

    std::cout << "Connected to server " << serverAddress_ << " on port " << port_ << std::endl;
    return;
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

// Room User::getCurrentRoom() {
//     return currentRoom_;
// }


void User::sendMail(std::string playerName){

}