// http://stackoverflow.com/questions/15310846/creating-a-class-object-in-c // Constructeur
// http://stackoverflow.com/questions/10750057/c-printing-out-the-contents-of-a-vector Vector itération
// http://stackoverflow.com/questions/181693/what-are-the-complexity-guarantees-of-the-standard-containers complexité des containers
// https://en.wikipedia.org/wiki/Object_slicing
// http://stackoverflow.com/questions/8777724/store-two-classes-with-the-same-base-class-in-a-stdvector
#include <iostream>
#include <string>
#include <list>
#include "class.h"

using namespace std;


int main(){
	pDoc = new struct base;

	typedef list<DocumentPapier*> Path; // Initialisation du vector de class DocumentPapier

	Path myVec;


	pDoc->annee = 2015;
	pDoc->editeur = "UQAC";
	pDoc->titre = "8PROO";
	pDoc->nbPage = 1;

	/*DocumentPapier papier(pDoc);
	papier.parleDeToi();*/

	Livre* livre = new Livre(pDoc, "Cours de Programmation Object", "Hamid Mcheick");
	myVec.push_back(livre);
	//livre.parleDeToi(livre);

	Dictionnaire* dico= new Dictionnaire(pDoc, "Cours de Programmation Object", "Hamid Mcheick", 2000, "Anglais", "Francais");
	myVec.push_back(dico);
	//dico.parleDeToi(dico);

  Revue* revueAnimal = new Revue(pDoc,10,"Les animaux de la Jungles");
	myVec.push_back(revueAnimal);
  //revueAnimal.parleDeToi(revueAnimal);

  Acte* ActeMinisterielle = new Acte(pDoc,10,"Les animaux de la jungle"," Sauvage","La Jungle ");
	myVec.push_back(ActeMinisterielle);
  //ActeMinisterielle.parleDeToi(ActeMinisterielle);

	for (Path::size_type i = 0; i < myVec.size();++i){
		(myVec[i]).parleDeToi(*myVec[i]);
	}
	system("pause");

	delete pDoc;
  return 0;
}
