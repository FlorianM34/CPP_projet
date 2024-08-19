#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "Room.hpp"
#include "Server.hpp"

using namespace std;

void Server::createRoom(string roomName, int maxPlayer) {
    

    room = new Room(roomName, maxPlayer);

    roomList.push_back(room);
}

Server::Server(int port) : port(port), addrlen(sizeof(address)) {
    int opt = 1;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    cout << "socket created" << endl;

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    
    cout << "socket linked" << endl;

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);


    if (::bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    cout << "server binded" << endl;


    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    std::cout << "Server started on port " << port << std::endl;
}

Server::~Server() {
    close(server_fd);
}

void Server::start() {
    while (true) {
        int client_socket;


        if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }


        handleClient(client_socket);

        close(client_socket);
    }
}

void Server::handleClient(int client_socket) {
    char buffer[1024] = {0};
    const char *hello = "Hello from server";

    read(client_socket, buffer, 1024);
    std::cout << "Message from client: " << buffer << std::endl;

    send(client_socket, hello, strlen(hello), 0);
    std::cout << "Hello message sent to client" << std::endl;
}