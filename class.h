#include <iostream>
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