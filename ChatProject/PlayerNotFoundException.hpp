#include <iostream>
#include <exception>
#include <string>

#ifndef DEF_EXCEPTION
#define DEF_EXCEPTION

class PlayerNotFoundException : public std::exception {
    private :
        const char* message_;
        const int code_;

    public:

        PlayerNotFoundException(const char* message, const int code) : message_(message), code_(code) { }

        const char * what () {
            return message_;
        }

        const int getCode (){
            return code_;
        }
};


#endif