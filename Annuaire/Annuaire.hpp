#ifndef DEF_ANNUAIRE
#define DEF_ANNUAIRE
#include "Personne.hpp"

#include <string>
#include <vector>


class Annuaire {
    private: 
        std::vector<Personne> listePersonne;

    public :

        Annuaire();

        Annuaire(std::vector<Personne> listePersonne);

        void addPersonne(Personne p);
        Personne getPersonneByName(std::string name);
        void removePersonneByName(std::string name);
};


#endif