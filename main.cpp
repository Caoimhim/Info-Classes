#include <iostream>
using namespace std;

#include "Materia.h"
#include "Tema.h"
#include "Autor.h"

int main()
{ 
	Materia mTest;
	Tema tTest;
	Autor aTest;

	cout << mTest.getID();
	cout << tTest.getIDTema();
	cout << aTest.getIDAutor();

	return 0;
}
