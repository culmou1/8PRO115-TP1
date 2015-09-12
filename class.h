#include <iostream>

// J'ai pas trouver d'autre nom pour factoriser encore plus les classes
// Les autres classe vont érité de cette classe
class DocumentPapier{

  // Par default les variables sont privés (doit être appeler avec un méthode)

  std::string editeur;
  std::string titre;
  int nbPage;
  int annee#include <iostream>
#include <string>

struct base {
	std::string editeur;
	std::string titre;
	int nbPage;
	int annee;
} *pDoc;


// J'ai pas trouver d'autre nom pour factoriser encore plus les classes
// Les autres classe vont érité de cette classe
class DocumentPapier{
// Par default les variables sont privés (doit être appeler avec un méthode)
protected :
	std::string editeur;
	std::string titre;
	int nbPage;
	int annee;
public:
	DocumentPapier(base *Object) { // constructeur
		annee = Object->annee;
		titre = Object->titre;
		nbPage = Object->nbPage;
		editeur = Object->editeur;
	}

	virtual ~DocumentPapier() {}

	std::string getTitre(){ return titre; }
	void setTitre (std::string papierTitre){ titre = papierTitre; }

	std::string getEditeur(){ return editeur; }
	void setEditeur (std::string papierEditeur){ editeur = papierEditeur; }

	int getNbPage(){ return nbPage; }
	void setPage (int papierNbPage){ nbPage = papierNbPage; }

	int getAnnee(){ return annee; }
	void setAnnee (int papierAnnee){ annee = papierAnnee; }

	virtual void parleDeToi(){
		std::cout << ", mon titre est \"" << titre << "\", mon editeur est " << editeur << ", je suis compose de " <<
		nbPage << " pages et je suis ne en " << annee;
	}
};


// voici comment nous fesont de l'héritage
class Livre : public DocumentPapier{
protected:
	std::string resume;
	std::string auteur;

public :
	Livre (base *Object, std::string sum, std::string aut) : 
		DocumentPapier(Object), resume(sum), auteur(aut) {}

	~Livre() {}

	std::string getResume(){ return resume; }
	void setResume (std::string papierResume){ resume = papierResume; }

	std::string getAuteur(){ return auteur; }
	void setAuteur (std::string papierAuteur){ auteur = papierAuteur; }

	virtual void parleDeToi(DocumentPapier xyz) {
		std::cout << "Je suis un livre, mon auteur est " << auteur;
		xyz.parleDeToi();
		std::cout << ", et mon resume est \"" << resume << "\".\n";
	}
};

class Dictionnaire : public Livre{
protected:
    int nbMots;
    std::string langueSource; // Anglais
    std::string langueCible; // Francais
};

class Revue : public DocumentPapier{
protected:
    int nbArticle;
    std::string editorial; // Anglais
};

class Acte : public Revue{
protected:
    std::string nomConference;
    std::string addresseConference;
};


public:

  article(); // constructeur

  virtual ~article();

   virtual void getAuteur const (){
     std:: cout << auteur << "\n";
   }

   virtual void setAuteur (const std::string& papierAuteur){

     auteur = papierAuteur;

   }


   virtual void getEditeur const (){
     std::cout << editeur << "\n";
   }

   virtual void setEditeur (const std::string& papierEditeur){

      editeur = papierEditeur;
   }


   virtual void getTitre const (){
     std::cout << titre << "\n";
   }

   virtual void setTitre (const std::string& papierTitre){

     titre = papierTitre
   }

   virtual void getNbPage const (){
     std::cout << nbPage  << "\n";
   }

   virtual void setPage (int papierNbPage){

     nbPage = papierNbPage;
   }


   virtual void getAnnee const (){
     std::cout << nbPage  << "\n";
   }

   virtual void setAnnes (int papierAnnee){

     annee = papierAnnee;
   }

   virtual void parleDeToi const (){

     std::cout << "Je suis un livre, mon titre est " << titre << " , mon auteur " <<
     "est " << auteur << " , mon editeur est " << editeur << " , je suis compose de " <<
     nbPage << " pages et je suis né en " << annee << "\n";
   }

};



// voici comment nous fesont de l'héritage
class Livre : public DocumentPapier{


private:
  std::string resumer;


};

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
