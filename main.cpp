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

	while(biblio.LectureChoix()) {} // Tant qu'il est vrai il execute le Switch Case

	system("pause");

  return 0;
}
