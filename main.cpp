#include <iostream>
#include <string>
#include "class.h"

using namespace std;


int main(){
	pDoc = new struct base;


	pDoc->annee = 2015;
	pDoc->editeur = "UQAC";
	pDoc->titre = "8PROO";
	pDoc->nbPage = 1;

	/*DocumentPapier papier(pDoc);
	papier.parleDeToi();*/

	Livre livre (pDoc, "Cours de Programmation Object", "Hamid Mcheick");
	livre.parleDeToi(livre);
	
	Dictionnaire dico (pDoc, "Cours de Programmation Object", "Hamid Mcheick", 2000, "Anglais", "Francais");
	dico.parleDeToi(dico);

  Revue revueAnimal (pDoc,10,"Les animaux de la Jungles");
  revueAnimal.parleDeToi(revueAnimal);

	system("pause");

	delete pDoc;
  return 0;
}
