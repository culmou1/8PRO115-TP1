#ifndef BASE_H
#define BASE_H


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


	std::string getEditeur  (){
		return editeur;
	}

	void setEditeur (std::string papierEditeur){
		editeur = papierEditeur;
	}

	std::string getTitre  (){
		return titre;
	}

	void setTitre (std::string papierTitre){
		titre = papierTitre;
	}

	int getNbPage  (){
		return nbPage;
	}

	void setPage (int papierNbPage){
		nbPage = papierNbPage;
	}

	int getAnnee (){
		return annee;
	}

	void setAnnes (int papierAnnee){
		annee = papierAnnee;
	}

	virtual void parleDeToi () const{
		std::cout << ", mon titre est \"" << titre <<  "\", mon editeur est "
		<< editeur << " , je suis composé de " << nbPage
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
  	void parleDeToi() const  {
  		std::cout << "Je suis un livre, mon auteur est " << auteur;
      DocumentPapier::parleDeToi();
  		std::cout << ", et mon resume est \"" << resume << "\".\n";
		std::cout << " -----------------------------------------------------------------------------------" << std::endl;
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

	void parleDeToi () const {
		std::cout << "Je suis un dictionnaire " << langueSource+ "-" +langueCible << " de " << nbMots << " mots, mon auteur est " << auteur;
		DocumentPapier::parleDeToi();
		std::cout << ", et mon resume est \"" << resume << "\".\n";
		std::cout << " -----------------------------------------------------------------------------------" << std::endl;
	}
};

class Revue : public DocumentPapier{

  protected:
      int nbArticle;
      std::string editorial; // Anglais

  public:

  Revue (base *Object,int revueNbArticle,std::string revueEditorial) :
    DocumentPapier(Object), nbArticle(revueNbArticle), editorial(revueEditorial) {}

  ~Revue(){}

  int getNbArticle (){

   return nbArticle;

  }

  void setNbArticle (int revueNbArticle){

   nbArticle = revueNbArticle;

  }

  std::string getEditorial (){

   return editorial;

  }

  void setEditorial (int revueEditorial){

   nbArticle = revueEditorial;

  }

   void parleDeToi() const {
    std::cout << "Je suis une revue, mon editorial est " << editorial;
    DocumentPapier::parleDeToi();
    std::cout << ", et je suis composé de \"" << nbArticle << "\" article .\n";
	std::cout << " -----------------------------------------------------------------------------------" << std::endl;
  }

};

class Acte : public Revue{


  protected:
    std::string nomConference;
    std::string adresseConference;

  public:

    Acte (base *Object,int revueNbArticle,std::string revueEditorial,std::string acteNomConf,
    std::string acteAddConf) :
      Revue(Object,revueNbArticle,revueEditorial),nomConference(acteNomConf),adresseConference(acteAddConf) {}

    ~Acte(){}


    std::string getNomConf (){
		
		return nomConference;

    }

    void setNomConf(std::string acteNomConf){

       nomConference = acteNomConf;

    }

    std::string getAddrConf (){

       return adresseConference;

    }

    void setEditorial (std::string acteAdrConf){

       adresseConference = acteAdrConf;

    }

    void parleDeToi() const {
        std::cout << "Je suis un acte, mon editorial est " << editorial;
        DocumentPapier::parleDeToi();
        std::cout << ", et je suis composé de \"" << nbArticle << "\" article ." <<
        "la conférence a été présenté au \"" << adresseConference << "\" et le nom est \"" << nomConference << "\" . \n" ;
		std::cout << " -----------------------------------------------------------------------------------" << std::endl;
    }
};


#endif