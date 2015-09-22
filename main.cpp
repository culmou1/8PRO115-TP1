// http://stackoverflow.com/questions/15310846/creating-a-class-object-in-c // Constructeur
// http://stackoverflow.com/questions/10750057/c-printing-out-the-contents-of-a-vector Vector itération
// http://stackoverflow.com/questions/181693/what-are-the-complexity-guarantees-of-the-standard-containers complexité des containers
// https://en.wikipedia.org/wiki/Object_slicing
// http://stackoverflow.com/questions/8777724/store-two-classes-with-the-same-base-class-in-a-stdvector

#include <iostream>
#include <string>
#include "class.h"
#include "Application.h"

using namespace std;


int main(){
	Application biblio;

	while(biblio.LectureChoix()) {} // Tant qu'il est vrai

	typedef vector<DocumentPapier*> Path; // Initialisation du vector de class DocumentPapier

	Path myVec;


	pDoc->annee = 2100;
	pDoc->editeur = "Mars Et Pluton";
	pDoc->titre = "La vie sur terre";
	pDoc->nbPage = 5100;

	myVec.push_back(new Livre (pDoc, "Cours de Programmation Terre", "Hamid \"PLuton\" Mcheick"));



	myVec.push_back(new Dictionnaire(pDoc, "Les mots sur terre", "Djamd Rebei", 2000, "Anglais", "Francais"));


	myVec.push_back(new Revue(pDoc,420,"Les humains sur terre"));



	myVec.push_back(new Acte(pDoc,200,"Les humains de la terre"," L\'humain avant la programmation ","Pavillon des terriens "));


	for (int i = 0; i < myVec.size();++i){
		myVec[i]->parleDeToi();
		delete myVec[i];
	}

	system("pause");

  return 0;
}
