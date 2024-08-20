#include <iostream>
#include <exception>
#include <string>

#ifndef DEF_EXCEPTION_MSG
#define DEF_EXCEPTION_MSG

class MessageErrorException : public std::exception {
    private :
        const char* message_;
        const int code_;

    public:

        MessageErrorException(const char* message, const int code) : message_(message), code_(code) { }

        const char * what () {
            return message_;
        }

        const int getCode (){
            return code_;
        }
};


#endif