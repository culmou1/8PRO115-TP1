#ifndef HEADER_FILE
#define HEADER_FILE

#include <iostream>
#include <string>

// J'ai pas trouver d'autre nom pour factoriser encore plus les classes
// Les autres classe vont érité de cette classe

/* La structute Base contient tout les éléments de base dans chaque Classe   */

struct base {
    std::string editeur;
    std::string titre;
    int nbPage;
    int annee;
} *pDoc;


/* Voici nôtre classe abstraite qui donne aux autres classes (méthodes et attributs) */
class DocumentPapier{


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

    // Destructeur
	virtual ~DocumentPapier() {};

    // Obtenir l'éditeur
	virtual std::string getEditeur  (){
		return editeur;
	}
    // Change la Valeur d'éditeur
	virtual void setEditeur (std::string papierEditeur){
		editeur = papierEditeur;
	}
    // Obtenir le titre
	virtual std::string getTitre  (){
		return titre;
	}
        // Change la Valeur de Titre
	virtual void setTitre (std::string papierTitre){
		titre = papierTitre;
	}
    // Obtenir le nombre de Page
	virtual int getNbPage  (){
		return nbPage;
	}
        // Change la Valeur de nommre de page
	virtual void setPage (int papierNbPage){
		nbPage = papierNbPage;
	}
    // Obtenir l'année
	virtual int getAnnee (){
		return annee;
	}
        // Change la Valeur de l'année
	virtual void setAnnes (int papierAnnee){
		annee = papierAnnee;
	}

    //Fonction qui Décrit le contenu de Document Papier
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

    // Obtenir le Résumé

	std::string getResume() {
		return resume;
	}
        // Change la Valeur du résumé
	void setResume (std::string livreResume) {
		resume = livreResume;
	}
    // Obtenir l'auteur
	std::string getAuteur() {
		return auteur;
	}
    // Changer la valeur de l'auteur
	void setAuteur (std::string livreAuteur) {
		auteur = livreAuteur;
	}
    //Fonction qui Décrit le contenu de Livre
  	void parleDeToi() const  {
  		std::cout << "Je suis un livre, mon auteur est " << auteur;
      DocumentPapier::parleDeToi();
  		std::cout << ", et mon resume est \"" << resume << "\".\n";
  	}
  };




class Dictionnaire : public Livre{

protected:
    int nbMots;
    std::string langueSource; // Anglais
    std::string langueCible; // Francais

public :
    // Constructeur
	Dictionnaire (base *Object, std::string sum, std::string aut, int nbWords, std::string lSource, std::string lCible) :
		Livre (Object, sum, aut), nbMots(nbWords), langueSource(lSource), langueCible(lCible) {}

    // Destructeur
	~Dictionnaire() {};

    // Obtenir le nombre de mots
	int getNbMots() {
		return nbMots;
	}
    // Change la Valeur  du nombre de mots
	void setNbMots (int dicNbMots) {
		nbMots = dicNbMots;
	}

    // Obtenir le language Source
	std::string getLangueSource() {
		return langueSource;
	}
    // Change la Valeur du language Source
	void setLangueSource (std::string dicLangueSource) {
		langueSource = dicLangueSource;
	}
    // Obtenir le language Cible
	std::string getLangueCible(){
		return langueCible;
	}
    // Change la Valeur du language Cible
	void setLangueCible (std::string dicLangueCible) {
		langueCible = dicLangueCible;
	}
    //Fonction qui Décrit le contenu de Dictionnaire
	void parleDeToi () const {
		std::cout << "Je suis un dictionnaire " << langueSource+ "-" +langueCible << " de " << nbMots << " mots, mon auteur est " << auteur;
		DocumentPapier::parleDeToi();
		std::cout << ", et mon resume est \"" << resume << "\".\n";
	}
};

class Revue : public DocumentPapier{

  protected:
      int nbArticle;
      std::string editorial; // Anglais

  public:
      // Constructeur
  Revue (base *Object,int revueNbArticle,std::string revueEditorial) :
    DocumentPapier(Object), nbArticle(revueNbArticle), editorial(revueEditorial) {}
    //Destructeur
  ~Revue(){}

  // Obtenir le Nombre d'article
  virtual int getNbArticle (){
   return nbArticle;
  }
  // Change la Valeur du nombre d'article
  virtual void setNbArticle (int revueNbArticle){

   nbArticle = revueNbArticle;

  }
  // Obtenir l'éditorial

  virtual std::string getEditorial (){

   return editorial;

  }
    // Change la Valeur de l'editorial
  virtual void setEditorial (int revueEditorial){

   nbArticle = revueEditorial;

  }
//Fonction qui Décrit le contenu de Revue
   void parleDeToi() const {
    std::cout << "Je suis une revue, mon editorial est " << editorial;
    DocumentPapier::parleDeToi();
    std::cout << ", et je suis composé de \"" << nbArticle << "\" article .\n";
  }

};

class Acte : public Revue{


  protected:
    std::string nomConference;
    std::string adresseConference;

  public:
      // Constructeur
    Acte (base *Object,int revueNbArticle,std::string revueEditorial,std::string acteNomConf,
    std::string acteAddConf) :
      Revue(Object,revueNbArticle,revueEditorial),nomConference(acteNomConf),adresseConference(acteAddConf) {}
      // Destructeur
    ~Acte(){}

    // Obtenir le Nom de la conférence
      std::string getNomConf (){
       return nomConference;
      }
    // Change la Valeur du nom de la conférence
      void setNomConf(std::string acteNomConf){

       nomConference = acteNomConf;

      }

      // Obtenir l'addresse de la conférence
      std::string getAddrConf (){
       return adresseConference;

      }
    // Change la Valeur de l'addresse de la conférence
      void setAddrConf (std::string acteAdrConf){

       adresseConference = acteAdrConf;

      }
      //Fonction qui Décrit le contenu de Acte
       void parleDeToi() const {
        std::cout << "Je suis un acte, mon editorial est " << editorial;
        DocumentPapier::parleDeToi();
        std::cout << ", et je suis composé de \"" << nbArticle << "\" article .\n" <<
        "La conférence à été présenté au \"" << adresseConference << "\" et le nom est \"" << nomConference << "\" . \n" ;
      }
};
#endif
