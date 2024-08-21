#include "Message.hpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>


using namespace std;


Message::Message(string senderName, string message) : senderName_(senderName), content_(message) {}

char* Message::serialize() {




    ssize_t senderNameSize = senderName_.length() + 1;
    ssize_t contentSize = content_.length() + 1;

    //SENDER NAME SERIALIZATION

    char *buffer;
    ssize_t messageSize = sizeof(ssize_t) * 2 + senderNameSize + contentSize;
    messageSize_ = messageSize;
    buffer = (char *) malloc(messageSize);
    int pos=0;
    
    memcpy(buffer+pos, (void *)&senderNameSize, sizeof(ssize_t));
    pos += sizeof(ssize_t);
    cout << "After senderNameSize Pos=" << pos << endl;

    memcpy(buffer+pos, (void *)senderName_.c_str(), senderNameSize);
    pos += senderNameSize;

    cout << "After senderName Pos=" << pos << endl;

    // CONTENT SERIALIZATION

    memcpy(buffer+pos, (void *)&contentSize, sizeof(ssize_t));
    pos += sizeof(ssize_t);
    cout << "After contentSize Pos=" << pos << endl;

    memcpy(buffer+pos, (void *)content_.c_str(), contentSize);
    pos += contentSize;
    cout << "After content_ Pos=" << pos << endl;

    return buffer;
}

Message Message::deserialize(char* data) {

    char * sender;
    char * content;

    ssize_t senderNameSize;
    ssize_t contentSize;

    char * pos = data;

    memcpy( (void *)&senderNameSize, pos, sizeof(ssize_t));
    sender = (char *)malloc(senderNameSize);
    pos += sizeof(ssize_t);

    memcpy(sender, pos, senderNameSize);
    pos += senderNameSize;

    memcpy( (void *)&contentSize, pos, sizeof(ssize_t));
    content = (char *)malloc(contentSize);
    pos += sizeof(ssize_t);

    memcpy(content, pos, contentSize);

    string senderString = sender;
    string contentString = content;

    Message message(senderString, contentString);

    return message;

}


std::string Message::getContent() {
    return content_;
}


std::string Message::getSender() {
    return senderName_;
}

ssize_t Message::getMessageSize() {
    return messageSize_;
}