#include <iostream>
#include <string>

#include "Annuaire.hpp"
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
    throw runtime_error("No one was found with this name");
}

void Annuaire::removePersonneByName(std::string name) {
    for (auto it = listePersonne.begin(); it != listePersonne.end(); ++it) {
        if (it->getNom() == name) {
            listePersonne.erase(it);
            return;
        }
    }
    throw std::runtime_error("Personne non trouvée");
}

