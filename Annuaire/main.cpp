#include <iostream>
#include <string>

#include "Annuaire.cpp"
#include "Personne.cpp"

using namespace std;


int main() { 

    Personne sarah("Sarah", 20, "0648038058");
    Personne pio("Pio", 20, "37738353");
    Personne mathis("Mathis", 20, "BANANE");

    vector<Personne> listePersonne;
    listePersonne.push_back(sarah);
    listePersonne.push_back(pio);
    listePersonne.push_back(mathis);

    Annuaire annuaire(listePersonne);

    Personne personneSearch = annuaire.getPersonneByName("Pio");

    cout << "Personne search : " << endl;
    personneSearch.afficherInfos();

    return 0;

}
