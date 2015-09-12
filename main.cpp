#include <iostream>
#include <string>
#include "BAse.h"

using namespace std;

int main(){
	pDoc = new base; 

	pDoc->annee = 2015;
	pDoc->editeur = "UQAC";
	pDoc->titre = "8PROO";
	pDoc->nbPage = 1;

	/*DocumentPapier papier(pDoc);
	papier.parleDeToi();*/

	Livre livre (pDoc, "Cours de Programmation Object", "Hamid Mcheick"); 
	livre.parleDeToi(livre);

	system("pause");

	delete pDoc;
  return 0;
}