#include <iostream>
#include <exception>
#include <string>

#include "customException.hpp"


const char * MyCustomException::what () { 
    return message_;
}