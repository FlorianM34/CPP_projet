#include <iostream>
#include <string>
#include <cstdlib> 
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <unordered_map>
#include <sstream>

#include "Genre.hpp"
#include "User.hpp"
#include "MessageError.hpp"
#include "Message.hpp"

using namespace std;

#define TEST false


User::User(std::string serverAddress, int port) 
    :  port_(port), serverAddress_(serverAddress) {


    string firstname;
    string lastname;
    string age;

    if(!TEST){
        cout << "enter firstname : ";
        cin >> firstname;

        cout << "enter lastname : ";
        cin >> lastname;

        cout << "enter age : ";
        cin >> age;

        firstname_ = firstname;
        lastname_ = lastname;
        age_ = stoi(age);
    }

    else {
        firstname_ = "testname";
        lastname_ = "testname";
        age_ = 19;
    }
        


    int userId = rand();
    userId_ = to_string(userId);
    username_ = firstname + lastname;
    ip_ = "0.0.0.0"; // use function later to get ip adress

    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }


    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_);

    if (inet_pton(AF_INET, serverAddress_.c_str(), &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

}




void User::connectToServer() {

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "Connection failed" << std::endl;
        return ;
    }

    std::cout << "Connected to server " << serverAddress_ << " on port " << port_ << std::endl;


    while(true) {

        try {

            sendMessage();

            memset(buffer, 0, sizeof(buffer));
            ssize_t bytesReceived = read(sock, buffer, sizeof(buffer) -1);

            if (bytesReceived < 0) {
                cerr << "Read failed" << endl;
                break;
            }

            else if (bytesReceived == 0) {
                cout << "Server closed connection" << endl;
                break;
            }

            buffer[bytesReceived] = '\0';
            cout << "Server : " << buffer << endl;
        }

        catch(MessageErrorException e){
            cout << "Error in connect to server => " << e.what() << "Error number => " << e.getCode() << endl;
        }
        
    }

    close(sock);
}

void User::sendMessage() {

    string message;
    cout << ">>> ";
    cin >> message;


    Message dataMessage(username_, message);

    char* dataMessageSerialized = dataMessage.serialize(); //serializer

    if (send(sock, dataMessageSerialized, MESSAGE_SIZE , 0 ) < 0) {
        cerr << "Send failed" << endl;
        throw MessageErrorException("Failed to send the message", 1);
    }

    free(dataMessageSerialized);
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

Room* User::getCurrentRoom() {
    return currentRoom_;
}


void User::sendMail(std::string playerName){

}