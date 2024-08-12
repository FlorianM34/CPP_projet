#include <iostream>
#include <string>

#include "Personne.cpp"

using namespace std;

int main() {
	
	Personne flo("Flo", 14, "1342");

	int age = flo.getAge();

	flo.afficherInfos();

	cout << age << endl;


	std::cout << "Hello World" << std::endl;	
	std::cout << "Hello World" << std::endl;	


}
