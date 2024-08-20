#include <iostream>
#include <string>
// #include "Room.hpp"
#include "User.hpp"
// #include "Genre.hpp"
// #include "Server.hpp"


using namespace std;

#define C_PORT 8080


int main() {
    
    string address = "127.0.0.1";
    
    User *user;

    user = new User(address, C_PORT);

    user->connectToServer();


}