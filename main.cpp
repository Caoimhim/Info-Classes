#include <iostream>
using namespace std;

#include "Materia.h"
#include "Tema.h"

int main()
{ 
	Materia mTest;
	Tema tTest;

	cout << mTest.getID();
	cout << tTest.getIDTema();

	return 0;
}
