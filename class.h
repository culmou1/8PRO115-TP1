#include <iostream>
#include <string>

// J'ai pas trouver d'autre nom pour factoriser encore plus les classes
// Les autres classe vont érité de cette classe

// Declaration de notre object au début

struct base {
    std::string editeur;
    std::string titre;
    int nbPage;
    int annee;
} Object;

class DocumentPapier{

  // Par default les variables sont privés (doit être appeler avec un méthode)

protected:

  std::string editeur;
  std::string titre;
  int nbPage;
  int annee;


public:

  DocumentPapier(base Object){
    editeur = Object.editeur;
    titre = Object.titre;
    nbPage = Object.nbPage;
    annee = Object.annee;
  }; // constructeur

  virtual ~DocumentPapier() {};


   virtual std::string getEditeur  (){
     return editeur;
   }

   virtual void setEditeur (const std::string& papierEditeur){

      editeur = papierEditeur;
   }


   virtual std::string getTitre  (){
     return titre;
   }

   virtual void setTitre (const std::string& papierTitre){

     titre = papierTitre;
   }

   virtual int getNbPage  (){

     std::cout << nbPage << "\n";
     return nbPage;
   }

   virtual void setPage (int papierNbPage){

     nbPage = papierNbPage;
   }


   virtual int getAnnee (){
     return annee;
   }

   virtual void setAnnes (int papierAnnee){

     annee = papierAnnee;
   }

   virtual void parleDeToi  (){

     std::cout << "Je suis un livre, mon titre est " << titre << " , mon auteur " <<
     "est " <<  " , mon editeur est " << editeur << " , je suis compose de " <<
     nbPage << " pages et je suis né en " << annee << "\n";
   }

};



// voici comment nous fesont de l'héritage
class Livre : public DocumentPapier{


private:
  std::string resumer;
  std::string auteur;
};

public:

  // Declation constructeur Class(Super_classe param,string param, string param):
    // Declaration immédiate des variables de l'object
  Livre(base DocumentPapier,std::string resumer, std::string auteur):
    DocumentPapier(DocumentPapier),resumer(resumer),auteur(auteur){}

  virtual ~Livre(){}

class Dictionnaire : public Livre{


private:
    int nbMots;
    std::string langueSource; // Anglais
    std::string langueCible; // Francais

};
class Revue : public DocumentPapier{


private:
    int nbArticle;
    std::string editorial; // Anglais

};

class Acte : public Revue{


private:
    std::string nomConference;
    std::string addresseConference;
};
