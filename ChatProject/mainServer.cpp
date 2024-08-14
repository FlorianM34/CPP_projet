#include <iostream>
#include <string>
#include "Room.hpp"
#include "User.hpp"
#include "Genre.hpp"
#include "Server.hpp"


using namespace std;

#define PORT 8080


int main() {
    
    Server server(8080);

    server.start();

}