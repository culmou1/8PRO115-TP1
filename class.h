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
} *pDoc;

class DocumentPapier{

  // Par default les variables sont privés (doit être appeler avec un méthode)

protected:
	std::string editeur;
	std::string titre;
	int nbPage;
	int annee;


public:
	DocumentPapier(base *Object){
		editeur = Object->editeur;
		titre = Object->titre;
		nbPage = Object->nbPage;
		annee = Object->annee;
	}; // constructeur

	virtual ~DocumentPapier() {};


	virtual std::string getEditeur  (){
		return editeur;
	}

	virtual void setEditeur (std::string papierEditeur){
		editeur = papierEditeur;
	}

	virtual std::string getTitre  (){
		return titre;
	}

	virtual void setTitre (std::string papierTitre){
		titre = papierTitre;
	}

	virtual int getNbPage  (){
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
		std::cout << ", mon titre est \"" << titre <<  "\", mon editeur est " 
		<< editeur << " , je suis compose de " << nbPage 
		<< " pages et je suis ne en " << annee;
	}

};



// voici comment nous fesont de l'héritage
class Livre : public DocumentPapier{
protected:
	std::string resume;
	std::string auteur;

public :
	
	// Declation constructeur Class(Super_classe param,string param, string param):
    // Declaration immédiate des variables de l'object
	Livre (base *Object, std::string sum, std::string aut) : 
		DocumentPapier(Object), resume(sum), auteur(aut) {}

	~Livre() {}

	std::string getResume() { 
		return resume; 
	}

	void setResume (std::string livreResume) {
		resume = livreResume; 
	}

	std::string getAuteur() { 
		return auteur; 
	}

	void setAuteur (std::string livreAuteur) { 
		auteur = livreAuteur; 
	}

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

public :
	Dictionnaire (base *Object, std::string sum, std::string aut, int nbWords, std::string lSource, std::string lCible) : 
		Livre (Object, sum, aut), nbMots(nbWords), langueSource(lSource), langueCible(lCible) {}

	~Dictionnaire() {};

	int getNbMots() { 
		return nbMots; 
	}

	void setNbMots (int dicNbMots) { 
		nbMots = dicNbMots; 
	}

	std::string getLangueSource() { 
		return langueSource; 
	}

	void setLangueSource (std::string dicLangueSource) { 
		langueSource = dicLangueSource; 
	}

	std::string getLangueCible(){ 
		return langueCible; 
	}

	void setLangueCible (std::string dicLangueCible) { 
		langueCible = dicLangueCible; 
	}

	void parleDeToi (DocumentPapier xyz) {
		std::cout << "Je suis un dictionnaire " << langueSource+ "-" +langueCible << " de " << nbMots << " mots, mon auteur est " << auteur;
		xyz.parleDeToi();
		std::cout << ", et mon resume est \"" << resume << "\".\n";
	}
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
