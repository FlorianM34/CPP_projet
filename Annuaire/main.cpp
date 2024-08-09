#include <iostream>
#include <string>

#include "Annuaire.cpp"
#include "Personne.cpp"

using namespace std;


int main() { 

    Personne sarah("Sarah", 20, "0648038058");
    Personne pio("Pio", 20, "0669696969");
    Personne mathis("Mathis", 20, "06481920");

    vector<Personne> listePersonne;
    listePersonne.push_back(sarah);
    listePersonne.push_back(pio);
    listePersonne.push_back(mathis);

    Annuaire annuaire(listePersonne);

    try {
        Personne personneSearch = annuaire.getPersonneByName("parads");
        cout << "Personne search : " << endl;
        personneSearch.afficherInfos();

        vector<Personne> personByNumber = annuaire.getPersonnesByNumber("08");

        cout << " There is : "<< personByNumber.size() << " people with this phone number " << endl;

    }

    catch (PeopleNotFoundException e) {
        std::cerr << "Erreur capturée : " << e.what() << std::endl;
        return 0;
    }

}
