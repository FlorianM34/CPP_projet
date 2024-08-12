#include <iostream>
using namespace std;
#include "customException.hpp"



int main() {
    try {
        throw MyCustomException("ablablabla");
    } catch (MyCustomException mce) {
        cout << "Caught MyCustomException" << endl;
        cout << mce.what();
    }
}