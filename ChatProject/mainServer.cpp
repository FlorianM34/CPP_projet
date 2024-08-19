#include <iostream>
#include <string>
#include "Server.hpp"


using namespace std;

#define S_PORT 8080


int main() {
    

    Server *server;

    server = new Server(S_PORT);

    server->start();


}