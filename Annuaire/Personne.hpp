#ifndef DEF_PESRONNE
#define DEF_PESRONNE

#include <string>

class Personne {
    private :
        std::string nom;
        int age;
        std::string phoneNumber;
        int uid;
    
    public :
        Personne();

        Personne(std::string n, int a, std::string pn);

        std::string getNom();

        void setNom(std::string n);

        std::string getPhoneNumber();

        void setPhoneNumber(std::string pn);

        int getAge();

        void setAge(int a);

        void afficherInfos();

        int getUid();

};



#endif