// http://stackoverflow.com/questions/15310846/creating-a-class-object-in-c // Constructeur
// http://stackoverflow.com/questions/10750057/c-printing-out-the-contents-of-a-vector Vector itération
// http://stackoverflow.com/questions/181693/what-are-the-complexity-guarantees-of-the-standard-containers complexité des containers
// https://en.wikipedia.org/wiki/Object_slicing
// http://stackoverflow.com/questions/8777724/store-two-classes-with-the-same-base-class-in-a-stdvector
#include <iostream>
#include <string>
#include <vector>
#include "class.h"

using namespace std;


int main(){
	pDoc = new struct base;

	typedef vector<DocumentPapier*> Path; // Initialisation du vector de class DocumentPapier

	Path myVec;


	pDoc->annee = 2015;
	pDoc->editeur = "UQAC";
	pDoc->titre = "8PROO";
	pDoc->nbPage = 1;

	/*DocumentPapier papier(pDoc);
	papier.parleDeToi();*/


	myVec.push_back(new Livre (pDoc, "Cours de Programmation Object", "Hamid Mcheick"));
	//livre.parleDeToi(livre);


	myVec.push_back(new Dictionnaire(pDoc, "Cours de Programmation Object", "Hamid Mcheick", 2000, "Anglais", "Francais"));
	//dico.parleDeToi(dico);

	myVec.push_back(new Revue(pDoc,10,"Les animaux de la Jungles"));
  //revueAnimal.parleDeToi(revueAnimal);


	myVec.push_back(new Acte(pDoc,10,"Les animaux de la jungle"," Sauvage","La Jungle "));

	myVec[3]->setPage(10000000);
  //ActeMinisterielle.parleDeToi(ActeMinisterielle);

	for (int i = 0; i < myVec.size();++i){
		myVec[i]->parleDeToi();
		delete myVec[i];
	}
	system("pause");

	delete pDoc;
  return 0;
}
