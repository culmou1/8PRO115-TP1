#include <iostream>
#include "class.h"

using namespace std;


int main(){

  Object; // Struc declaration
  Object.titre = "8PRO115";
  Object.editeur = "Hamid Mcheick";
  Object.nbPage = 1;
  Object.annee = 2015;


  DocumentPapier papier(Object);

  papier.getNbPage();





  return 0;
}
