#include <iostream>
#include <string>
#include <vector>

//DECLARATION DE LA CLASSE
class Etudiant
{
//DECLARATION DES ATTRIBUTS
public:
    std::string codePerm; // exemple "TREJ15028009"
    int nbCafe; // nombre de tasses de café consommées par jour
    char genre;
//ATTRIBUT AGE POUR CONVERTIR PLUS TARD
    int age;
//GETTERS AND SETTERS
public :
    std::string getcodePerm()
    {
        return codePerm;
    }
    void setSexe(char genre)
    {
        this->genre = genre;
    }
    char getSexe()
    {
        return genre;
    }
    int getAge()
    {
        return 105 - atoi(codePerm.substr(8, 2).c_str());
    }
    void setCoffee(int c)
    {
        this->nbCafe = c;
    }
    int getCoffee()
    {
        return nbCafe;
    }
//CONSTRUCTEURS
//ON APPELLE LA MÉTHODE POUR CONVERTIR
    Etudiant(std::string codePerm_, int nbCafe_, char genre_)
    {
        codePerm = codePerm_;
        nbCafe = nbCafe_;
        genre = genre_;
        age = calculateage(codePerm_);
    };
//ON APPELLE LA MÉTHODE POUR CONVERTIR
    Etudiant(std::string codePerm_, int nbCafe_ = 1)
    {
        codePerm = codePerm_;
        nbCafe = nbCafe_;
        age = calculateage(codePerm_);
    }
//METHODES DE LA CLASSE
    void print()
    {
        std::cout << "Code permanent : " << codePerm;
        std::cout << " Age : " << getAge();
        std::cout << " Nombre de cafe : " << nbCafe << std::endl;
    }
//MÉTHODE POUR CONVERTIR LE CODE PERMANENT
    int calculateage(std::string codepermanent)
    {
        return 105 - atoi(codepermanent.substr(8, 2).c_str());
    };
};


//FONCTIONS/METHODES
void calculatecoffee(Etudiant etudiant1, Etudiant etudiant2)
{
    if (etudiant1.nbCafe > etudiant2.nbCafe)
    {
        std::cout << "L'etudiant " << etudiant1.codePerm << " Consomme le plus de caffe" << "\n";
        std::cout << "Cet etudiant consomme " << etudiant1.nbCafe << " Tasses de caffe" << "\n";
    }
    else
    {
        std::cout << "L'etudiant " << etudiant2.codePerm << " Consomme le plus de caffe " << "\n";
        std::cout << "Cet etudiant consomme " << etudiant2.nbCafe << " Tasses de caffe" << "\n";
    }
}
void demo1()
{
    Etudiant etudiant1("TREJ15028009", 3, 'm');
    Etudiant etudiant2("CHAN27568503", 1, 'f');
    std::cout << "Informations de " << etudiant1.codePerm << "\n" << "- sexe : " << etudiant1.getSexe() << "\n" <<
    "- age a 2005 : " << etudiant1.getAge() << "\n" << "- cafe consomme : " << etudiant1.getCoffee() << "\n";
    std::cout << "Informations de " << etudiant2.codePerm << "\n" << "- sexe : " << etudiant2.getSexe() << "\n" <<
              "- age a 2005 : " << etudiant2.getAge() << "\n" << "- cafe consomme : " << etudiant2.getCoffee() << "\n";
    calculatecoffee(etudiant1,etudiant2);
    etudiant1.setCoffee(etudiant1.getCoffee() -3);
    calculatecoffee(etudiant1,etudiant2);
}
void demo2()
{
    //j'ai eu plus de faciilité un vecteur alors j'ai remplacé la structure par un vecteur vu que c'est plus facile à manipuler pour moi.
    std::vector<Etudiant> etudiant;
    etudiant.push_back({"TREJ15028009", 2});
    etudiant.push_back({"CHAN27568503"});
    etudiant.push_back({"ARCP02067001", 5});
    etudiant.push_back({"LAFJ31628104", 0});
    etudiant.push_back({"TREM01128607"});
    //simple affichage
    for (size_t i = 0; i< etudiant.size(); i++)
    {
        etudiant[i].print();
    }
    // les éléments se tassent, voila la raison de +1 2 fois
    etudiant.erase(etudiant.begin()+1);
    etudiant.erase(etudiant.begin()+1);
    //affichage apres efface
    for (size_t i = 0; i< etudiant.size(); i++)
    {
        etudiant[i].print();
    }
    //Trouver eleve le plus vieux
    Etudiant oldest = etudiant[1];
    for (size_t i = 0; i< etudiant.size(); i++) {
        if (etudiant[i].age >= 0)
        {
            if (etudiant[i].age > oldest.age)
            {
                oldest = etudiant[i];
            }
        }
    }
        oldest.print();
}


int main() {
    demo1();
    demo2();
    return 0;
}
