#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#define MESSAGE_SIZE 4096


class Message {

    public: 

        Message(std::string sendName, std::string content);

        char* serialize();
        static Message deserialize(char* data);

        std::string getSender();
        std::string getContent();
        ssize_t getMessageSize();

    private:

        std::string senderName_;
        std::string content_;
        ssize_t messageSize_;
};