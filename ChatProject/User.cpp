#include <iostream>
#include <string>

#include "Genre.hpp"
#include "User.hpp"

using namespace std;

User::User(std::string firstname, std::string lastname, std::string mail, Genre sexe, int age) : firstname_(firstname), lastname_(lastname), mail_(mail), sexe_(sexe), age_(age) {}