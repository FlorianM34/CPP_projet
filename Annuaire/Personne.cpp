#include <iostream>
#include <string>
#include "Personne.hpp"

using namespace std;

Personne::Personne() : nom("Inconnu"), age(0) {}

Personne::Personne(string n, int a, string pn) : nom(n), age(a), phoneNumber(pn) {}

void Personne::setNom(string n) {
    nom = n;
}

string Personne::getNom() {
    return nom;
}

void Personne::setPhoneNumber(std::string pn) {
    phoneNumber = pn;
}

string Personne::getPhoneNumber() {
    return phoneNumber;
}

void Personne::setAge(int a) {
    age = a;
}

int Personne::getAge() {
    return age;
}

int Personne::getUid(){
    return uid;
}

void Personne::afficherInfos(){
    cout << "Nom :" << nom << ", Age" << age << endl;
}

