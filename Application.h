#ifndef APP_H
#define APP_H

#include "class.h"
#include <vector>

// Structure de données contenant toutes les variables des classes aidant à la création d'instances
struct Data {
	std::string resume;
  	std::string auteur;
	int nbMots;
    std::string langueSource;
    std::string langueCible;
	int nbArticle;
    std::string editorial;
	std::string nomConference;
    std::string adresseConference;
} *construc;

// Classe contenant une structure de données (vector myVec) pour collecter des objets (instances) des classes Livre, Dictionaire, 
// Revue, Acte. Cette structure nous permet d’appeler la méthode parleDeToi(…) sur toutes les instances de classes.
class Application {

private:
	std::vector<DocumentPapier*> myVec;

public:
	// Constructeur
	Application() { 
		construc = new Data;
		pDoc = new base;
	}

	// Destructeur
	~Application() {
		delete construc;
		delete pDoc;
	}

	// Méthodes traitant le choix de l'utilisateur à l'aide d'un switch-case. Elle appelle les méthodes respectives pour créer des instances 
	// des classes Livre, Dictionaire, Revue, Acte ou pour appeler la méthode parleDeToi(…) sur toutes les instances de classes.
	bool LectureChoix() {
		int choix;
		
		std::cout << std::endl << " -----------------------------------------------------------------------------------" << std::endl;
        std::cout << "INVENTAIRE DE LA BIBLIOTHEQUE " << std::endl;
        std::cout << "Veuillez choisir parmi les operations suivantes :" << std::endl;
        std::cout << "1- Ajouter un Livre " << std::endl;
        std::cout << "2- Ajouter un Dictionnaire " << std::endl;
        std::cout << "3- Ajouter une Revue " << std::endl;
        std::cout << "4- Ajouter un Acte " << std::endl;
        std::cout << "5- Afficher les documents de l'inventaire " << std::endl;
        std::cout << "6- Quitter " << std::endl;
        std::cout << " -----------------------------------------------------------------------------------" << std::endl;
        std::cout << "Quel est votre choix ? ";
        std::cin >> choix;

		// Execute selon le choix d'utilisateur une méthode
		switch (choix) {
		case 1 : 
			CreerLivre();
			return true;
			
		case 2 : 
			CreerDictionnaire();
			return true;
			
		case 3 :
			CreerRevue();
			return true;

		case 4 :
			CreerActe();
			return true;

		case 5 :
			Afficher_Bibliotheque();
			return true;

		case 6 :
			std::cout << "******FERMETURE DE L'INVENTAIRE******" << std::endl;
			return false;

		default : 
			std::cout << "******COMMANDE INCONNUE******" << std::endl;
			return true;
		}
	}

	// Méthode qui permet de créer une instance de la classe Livre à l'aide cout-cin/getline
	// puis l'ajoute au vecteur de la classe Application
	void CreerLivre() {
		std::cin.ignore(1);
		std::cout << "Auteur : "; getline (std::cin, construc->auteur);
		std::cin.clear();
		std::cout<< std::endl << "Editeur : "; getline (std::cin, pDoc->editeur);
		std::cin.clear();
		std::cout<< std::endl << "Titre : "; getline (std::cin, pDoc->titre);
		std::cin.clear();
		std::cout<< std::endl << "Resume : "; getline (std::cin, construc->resume);
		std::cout<< std::endl << "Annee : "; std::cin >> pDoc->annee;
		std::cout<< std::endl << "nombrePages : "; std::cin >> pDoc->nbPage;

		// Ajoute l'instance au vecteur de la classe
		myVec.push_back(new Livre (pDoc, construc->resume, construc->auteur));
	}

	// Méthode qui permet de créer une instance de la classe Dictionnaire à l'aide cout-cin/getline
	// puis l'ajoute au vecteur de la classe Application
	void CreerDictionnaire() {
		std::cin.ignore(1);
		std::cout<< "Auteur : "; getline (std::cin, construc->auteur);
		std::cin.clear();
		std::cout<< std::endl << "Editeur : "; getline (std::cin, pDoc->editeur);
		std::cin.clear();
		std::cout<< std::endl << "Titre : "; getline (std::cin, pDoc->titre);
		std::cin.clear();
		std::cout<< std::endl << "Resume : "; getline (std::cin, construc->resume);
		std::cout<< std::endl << "Annee : "; std::cin >> pDoc->annee;
		std::cout<< std::endl << "nombrePages : "; std::cin >> pDoc->nbPage;
		std::cout<< std::endl << "langueSource : "; std::cin >> construc->langueSource;
		std::cout<< std::endl << "langueCible : "; std::cin >> construc->langueCible;
		std::cout<< std::endl << "nombreMots : "; std::cin >> construc->nbMots;

		// Ajoute l'instance au vecteur de la classe
		myVec.push_back(new Dictionnaire (pDoc, construc->resume, construc->auteur, construc->nbMots, construc->langueSource, construc->langueCible));
	}

	// Méthode qui permet de créer une instance de la classe Revue à l'aide cout-cin/getline
	// puis l'ajoute au vecteur de la classe Application
	void CreerRevue() {
		std::cin.ignore(1);
		std::cout<< "Editorial : "; getline (std::cin, construc->editorial);
		std::cin.clear();
		std::cout<< std::endl << "Editeur : "; getline (std::cin, pDoc->editeur);
		std::cin.clear();
		std::cout<< std::endl << "Titre : "; getline (std::cin, pDoc->titre);
		std::cout<< std::endl << "Annee : "; std::cin >> pDoc->annee;
		std::cout<< std::endl << "nombrePages : "; std::cin >> pDoc->nbPage;
		std::cout<< std::endl << "nombreArticles : "; std::cin >> construc->nbArticle;

		// Ajoute l'instance au vecteur de la classe
		myVec.push_back(new Revue (pDoc, construc->nbArticle, construc->editorial));
	}

	// Méthode qui permet de créer une instance de la classe Acte à l'aide cout-cin/getline
	// puis l'ajoute au vecteur de la classe Application
	void CreerActe() {
		std::cin.ignore(1);
		std::cout<< "Editorial : "; getline (std::cin, construc->editorial);
		std::cin.clear();
		std::cout<< std::endl << "Editeur : "; getline (std::cin, pDoc->editeur);
		std::cin.clear();
		std::cout<< std::endl << "nomConference : "; getline (std::cin, construc->nomConference);
		std::cin.clear();
		std::cout<< std::endl << "adresseConference : "; getline (std::cin, construc->adresseConference);
		std::cin.clear();
		std::cout<< std::endl << "Titre : "; getline (std::cin, pDoc->titre);
		std::cout<< std::endl << "Annee : "; std::cin >> pDoc->annee;
		std::cout<< std::endl << "nombrePages : "; std::cin >> pDoc->nbPage;
		std::cout<< std::endl << "nombreArticles : "; std::cin >> construc->nbArticle;

		// Ajoute l'instance au vecteur de la classe
		myVec.push_back(new Acte (pDoc, construc->nbArticle, construc->editorial, construc->nomConference, construc->adresseConference));
	}

	// Méthode éxécutant la parleDeToi() de chaque instance contenue dans le vecteur de la classe Application
	void Afficher_Bibliotheque() {
		if (!myVec.empty()) // Vérifie si le vecteur est vide
		{
			for (int i = 0; i < myVec.size();++i)
			{
				myVec[i]->parleDeToi();
				delete myVec[i];
			}
		}
		else
			std::cout << std::endl << "******L'INVENTAIRE EST VIDE******";
	}
};

#endif
