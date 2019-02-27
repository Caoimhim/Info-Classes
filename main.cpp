#include <iostream>
using namespace std;

#include "Materia.h"
#include "Tema.h"
#include "Autor.h"
#include "Fecha.h"
#include "EjemploVideo.h"

int main()
{ 
	Materia mTest;
	Tema tTest;
	Autor aTest;
	Fecha fTest;
	EjemploVideo eTest;

	cout << mTest.getID();
	cout << tTest.getIDTema();
	cout << aTest.getIDAutor();
	cout << fTest.getDD();
	cout << eTest.getIDVideo();

	return 0;
}
