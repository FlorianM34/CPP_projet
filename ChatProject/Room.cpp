#include <iostream>
#include <string>
#include "Room.hpp"

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
}

Room::Room() : roomName_("default"), maxChaters_(10) {}
