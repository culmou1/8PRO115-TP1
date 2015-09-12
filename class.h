#include <iostream>
#include <string>
<<<<<<< HEAD
=======

struct base {
	std::string editeur;
	std::string titre;
	int nbPage;
	int annee;
} *pDoc;

>>>>>>> fe00131ff5050e6d6f80d197090d848e5642a222

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
<<<<<<< HEAD

  // Par default les variables sont privés (doit être appeler avec un méthode)

protected:

  std::string editeur;
  std::string titre;
  int nbPage;
  int annee;


=======
// Par default les variables sont privés (doit être appeler avec un méthode)
protected :
	std::string editeur;
	std::string titre;
	int nbPage;
	int annee;
>>>>>>> fe00131ff5050e6d6f80d197090d848e5642a222
public:
	DocumentPapier(base *Object) { // constructeur
		annee = Object->annee;
		titre = Object->titre;
		nbPage = Object->nbPage;
		editeur = Object->editeur;
	}

<<<<<<< HEAD
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
=======
	virtual ~DocumentPapier() {}

	std::string getTitre(){ return titre; }
	void setTitre (std::string papierTitre){ titre = papierTitre; }
>>>>>>> fe00131ff5050e6d6f80d197090d848e5642a222

	std::string getEditeur(){ return editeur; }
	void setEditeur (std::string papierEditeur){ editeur = papierEditeur; }

	int getNbPage(){ return nbPage; }
	void setPage (int papierNbPage){ nbPage = papierNbPage; }

	int getAnnee(){ return annee; }
	void setAnnee (int papierAnnee){ annee = papierAnnee; }

<<<<<<< HEAD
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

=======
	virtual void parleDeToi(){
		std::cout << ", mon titre est \"" << titre << "\", mon editeur est " << editeur << ", je suis compose de " <<
		nbPage << " pages et je suis ne en " << annee;
	}
>>>>>>> fe00131ff5050e6d6f80d197090d848e5642a222
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

<<<<<<< HEAD
private:
  std::string resumer;
  std::string auteur;
};

public:

  Livre(base DocumentPapier,std::string resumer, std::string auteur):
    DocumentPapier(DocumentPapier),resumer(resumer),auteur(auteur){}
=======
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
>>>>>>> fe00131ff5050e6d6f80d197090d848e5642a222

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
<<<<<<< HEAD
};
=======
};
>>>>>>> fe00131ff5050e6d6f80d197090d848e5642a222
