#include <iostream>
#include <exception>
#include <string>

#ifndef DEF_EXCEPTION
#define DEF_EXCEPTION

class MyCustomException : public std::exception {
    private :
        const char* message_;

    public:

        MyCustomException(const char* message) : message_(message) { }

        const char * what ();
};


#endif