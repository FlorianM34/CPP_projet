#include <iostream>
#include <string>

#include "Annuaire.hpp"
#include "PeopleNotFoundException.hpp"
using namespace std;


Annuaire::Annuaire() : listePersonne() {}

Annuaire::Annuaire(vector<Personne> list) : listePersonne(list) {}

void Annuaire::addPersonne(Personne p) {
    listePersonne.push_back(p);
    return;
}


Personne Annuaire::getPersonneByName(string name) {
    for (size_t i = 0; i < listePersonne.size(); i++){
        if (listePersonne[i].getNom() ==  name){
            return listePersonne[i];
        }
    }
    throw PeopleNotFoundException("No peolpe find with this name", 1);
}

void Annuaire::removePersonneByName(std::string name) {
    for (auto it = listePersonne.begin(); it != listePersonne.end(); ++it) {
        if (it->getNom() == name) {
            listePersonne.erase(it);
            return;
        }
    }
    throw PeopleNotFoundException("No peolpe find with this name", 2);
}

vector<Personne> Annuaire::getPersonnesByNumber(string pn){

    vector<Personne> personnesFound;
    bool hasFound = false;
    for (Personne personne : listePersonne){
        if(personne.getPhoneNumber().rfind(pn, 0) == 0){ //search any number that starts as for suffix pn
            personnesFound.push_back(personne);
            hasFound = true;
        }
    }
    
    if(hasFound){
        return personnesFound;
    }
    
    throw PeopleNotFoundException("No peolpe find that start or with this number", 3);

}