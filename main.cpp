#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

#include "Materia.h"
#include "Tema.h"
#include "Autor.h"
#include "Fecha.h"
#include "EjemploVideo.h"

/* getMatoAut
 * Obtiene input the un archivo cuyo nombre es dado y lo lee en el formata ID Nombre
 * Inputs: El nombre del archivo
 * Outputs: Escribe a un arreglo de objetos (sobrecargada a para soportar los diferentes tipos), el arreglo donde se guardaran los datos, y una entero para guardar el numero de este.
 * Regresa verdadero si encuentra el archivo, falso si no
 */
bool getData(string fileName, Materia materias[5], short int &cant)
{ 
	cant = 0;
	ifstream inFile;
	inFile.open(fileName.c_str());
	if(!inFile.is_open())
	{ 
		return false;
	}
	
	string data;
	while(getline(inFile, data))
	{ 
		short int pos = data.find(" ");
		materias[cant].setID(strtol(data.substr(0,pos).c_str(), NULL, 10));
		materias[cant++].setNombre(data.substr(pos + 1));
	}

	return true;
}

bool getData(string fileName, Tema temas[5], short int &cant)
{ 
	cant = 0;
	ifstream inFile;
	inFile.open(fileName.c_str());
	if(!inFile.is_open())
	{ 
		return false;
	}
	string data;
	while(getline(inFile, data))
	{ 
		short int pos = data.find(" ");
		temas[cant].setIDTema(strtol(data.substr(0,pos).c_str(), NULL, 10));
		short int pos2 = data.find(" ", pos+1);
		temas[cant].setIDMateria(strtol(data.substr(pos+1,pos2).c_str(), NULL, 10));
		temas[cant++].setNombre(data.substr(pos2 + 1));
	}

	return true;
}

bool getData(string fileName, Autor autores[10], short int &cant)
{ 
	cant = 0;
	ifstream inFile;
	inFile.open(fileName.c_str());
	if(!inFile.is_open())
	{ 
		return false;
	}
	string data;
	while(getline(inFile, data))
	{ 
		short int pos = data.find(" ");
		autores[cant].setIDAutor(strtol(data.substr(0,pos).c_str(), NULL, 10));
		autores[cant++].setNombre(data.substr(pos + 1));
	}

	return true;
}

bool getData(string fileName, EjemploVideo videos[20], short int &cant)
{ 
	cant = 0;
	ifstream inFile;
	inFile.open(fileName.c_str());
	if(!inFile.is_open())
	{ 
		return false;
	}
	int data;
	while(inFile >>  data)
	{ 
		videos[cant].setIDVideo(data);

		string nombre;
		inFile >> nombre;
		videos[cant].setNombre(nombre);

		inFile >> data;
		videos[cant].setIDTema(data);

		int d, m, a;
		inFile >> d;
		inFile >> m;
		inFile >> a;

		Fecha fechaElab;
		fechaElab.setFecha(d, m, a);
		videos[cant].setfechaElaboracion(fechaElab);

		int autorCount;
		inFile >> autorCount;
		while (autorCount > 0)
		{ 
			inFile >> data;
			videos[cant].agregaAutor(data);
			autorCount--;
		}
		cant++;

	}
	return true;
}
/* main
 * Llama todas las otras funciones
 * Input: NONE
 * Output: 0
 */
int main()
{ 
	//Variables
	Materia materias[5];
	short int cantMaterias;
	Tema temas[10];
	short int cantTemas;
	Autor autores[10];
	short int cantAutores;
	EjemploVideo videos[20];
	short int cantVideos;

	//Input
	char i = 0;
	while (i < 4)
	{ 
		bool exists;
		string fileName;
		switch(i)
		{ 
			case 0:
				cout << "¿Cuál es el nombre del archivo de materias" << endl;
				cin >> fileName;
				exists = getData(fileName, materias, cantMaterias);
				break;
			case 1:
				cout << "¿Cuál es el nombre del archivo de temas?" << endl;
				cin >> fileName;
				exists = getData(fileName, temas, cantTemas);
				break;
			case 2:
				cout << "¿Cuál es el nombre del archivo de autores?" << endl;
				cin >> fileName;
				exists = getData(fileName, temas, cantTemas);
				break;
			case 3:
				cout << "¿Cuál es el nombre del archivo de videos?" << endl;
				cin >> fileName;
				exists = getData(fileName, temas, cantTemas);
				break;

		}
		if (!exists)
		{ 
			cout << "No se encontró el archivo" << endl;
			return 0;
		}
		i++;
	}
	
	//menu();
	return 0;
}
