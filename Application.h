#ifndef APP_H
#define APP_H

#include <vector>


struct Data {
	std::string resume;
  	std::string auteur;
	int nbMots;
    std::string langueSource; // Anglais
    std::string langueCible; // Francais
	int nbArticle;
    std::string editorial; // Anglais
	std::string nomConference;
    std::string adresseConference;
};


class Application {

private:
	std::vector<DocumentPapier*> myVec;
	Data *construc;

public:
	Application() {
		construc = new Data;
		pDoc = new base;
	}

	~Application() {
		delete construc;
	}

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
			std::cout << "Sorry I don't understand" << std::endl;
			return true;
		}
	}

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
		std::cout<< std::endl << "Nombre Pages : "; std::cin >> pDoc->nbPage;
		std::cout << "\n";
		myVec.push_back(new Livre (pDoc, construc->resume, construc->auteur));
	}

	void CreerDictionnaire() {
		std::cin.ignore(1);
		std::cout<< "Auteur : "; getline (std::cin, construc->auteur);
		std::cin.clear();
		std::cout<< std::endl << "Editeur : "; getline (std::cin, pDoc->editeur);
		std::cin.clear();
		std::cout<< std::endl << "Titre : "; getline (std::cin, pDoc->titre);
		std::cin.clear();
		std::cout<< std::endl << "Resume : "; getline (std::cin, construc->resume);
		std::cin.clear();
		std::cout<< std::endl << "Annee : "; std::cin >> pDoc->annee;
		std::cout<< std::endl << "Nombre Pages : "; std::cin >> pDoc->nbPage;
		std::cout<< std::endl << "Langue Source : "; std::cin >> construc->langueSource;
		std::cout<< std::endl << "Langue Cible : "; std::cin >> construc->langueCible;
		std::cout<< std::endl << "Nombre Mots : "; std::cin >> construc->nbMots;
		std::cout << "\n";
		myVec.push_back(new Dictionnaire (pDoc, construc->resume, construc->auteur, construc->nbMots, construc->langueSource, construc->langueCible));
	}

	void CreerRevue() {
		std::cin.ignore(1);
		std::cout<< "Editorial : "; getline (std::cin, construc->editorial);
		std::cin.clear();
		std::cout<< std::endl << "Editeur : "; getline (std::cin, pDoc->editeur);
		std::cin.clear();
		std::cout<< std::endl << "Titre : "; getline (std::cin, pDoc->titre);
		std::cout<< std::endl << "Annee : "; std::cin >> pDoc->annee;
		std::cout<< std::endl << "Nombre Pages : "; std::cin >> pDoc->nbPage;
		std::cout<< std::endl << "Nombre Articles : "; std::cin >> construc->nbArticle;
		std::cout << "\n";
		myVec.push_back(new Revue (pDoc, construc->nbArticle, construc->editorial));
	}

	void CreerActe() {
		std::cin.ignore(1);
		std::cout<< "Editorial : "; getline (std::cin, construc->editorial);
		std::cin.clear();
		std::cout<< std::endl << "Editeur : "; getline (std::cin, pDoc->editeur);
		std::cin.clear();
		std::cout<< std::endl << "Nom de la Conférence : "; getline (std::cin, construc->nomConference);
		std::cin.clear();
		std::cout<< std::endl << "Adresse de la Conference : "; getline (std::cin, construc->adresseConference);
		std::cin.clear();
		std::cout<< std::endl << "Titre : "; getline (std::cin, pDoc->titre);
		std::cout<< std::endl << "Annee : "; std::cin >> pDoc->annee;
		std::cout<< std::endl << "Nombre Pages : "; std::cin >> pDoc->nbPage;
		std::cout<< std::endl << "Nombre Articles : "; std::cin >> construc->nbArticle;
		std::cout << "\n";
		myVec.push_back(new Acte (pDoc, construc->nbArticle, construc->editorial, construc->nomConference, construc->adresseConference));
	}

	void Afficher_Bibliotheque() {
		for (int i = 0; i < myVec.size();++i)
		{
			myVec[i]->parleDeToi();
			delete myVec[i];
		}
	}
};

#endif
