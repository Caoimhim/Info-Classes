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

/* checkExists
 * Revisa si existe el id de una objeto en un arreglo dado
 * Inputs: El arreglo de temas a revisar
 * Outputs: Verdadero o Falso
 */
bool checkExists(int tema, Tema temas[30], short int cant)
{ 
	for(short int i = 0; i < cant; i++)
	{ 
		if(tema == temas[i].getIDTema())
		{ 
			return true;
		}
	}
	return false;
}

bool checkExists(int autor, Autor autores[30], short int cant)
{ 
	for(short int i = 0; i < cant; i++)
	{ 
		if(autor == autores[i].getIDAutor())
		{ 
			return true;
		}
	}
	return false;
}


/* getData
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

bool getData(string fileName, EjemploVideo videos[20], short int &cant, Tema temas[30], short int cantTemas, Autor autores[30], short int cantAutores)
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
		string buffer;

		short int pos = data.find(" ");
		int idVideo = strtol(data.substr(0,pos).c_str(), NULL, 10);

		short int pos2 = data.find(" ", pos+1);
		string nombre = data.substr(pos+1, pos2 - pos -1);

		pos = data.find(" ", pos2+1);
		buffer = data.substr(pos2+1, pos);
		int idTema = strtol(buffer.c_str(), NULL, 10);
		if (checkExists(idTema, temas, cantTemas))
		{ 
	
			pos2 = data.find(" ", pos+1);
			buffer = data.substr(pos+1, pos2);
			int d = strtol(buffer.c_str(), NULL, 10);
	
			pos = data.find(" ", pos2+1);
			buffer = data.substr(pos2+1, pos);
			int m = strtol(buffer.c_str(), NULL, 10);
	
			pos2 = data.find(" ", pos+1);
			buffer = data.substr(pos+1, pos2);
			int a = strtol(buffer.c_str(), NULL, 10);
	
			pos = data.find(" ", pos2+1);
			buffer = data.substr(pos2+1, pos);
			int cantAutores = strtol(buffer.c_str(), NULL, 10);
	
			data = data.substr(pos+1);
			int inAutores[10];
			int idAutor;
			bool exists = true; 
			for (unsigned char i = 0; i < cantAutores && exists; i++)
			{ 
				pos = data.find(" ");
				idAutor = strtol(data.substr(0,pos).c_str(), NULL, 10);
	
				if(!checkExists(idAutor, autores, cantAutores))	
				{ 
					exists = false;	
				}
				inAutores[i] = idAutor;
			}
			if (!exists)
			{ 
				cout << "¡Advertencia! No se encontró el autor con la ID " << idAutor << endl;
			}
			else
			{ 
				videos[cant].setIDVideo(idVideo);
				videos[cant].setNombre(nombre);
				videos[cant].setIDTema(idTema);
				Fecha fechaElab;
				fechaElab.setFecha(d, m, a);
				videos[cant].setfechaElaboracion(fechaElab);

				for (unsigned char i = 0; i < cantAutores; i++)
				{ 
					videos[cant].agregaAutor(inAutores[i]);
				}
				cant++;
			}
		}
		else
		{ 
			cout << "¡Advertencia! No se encontró el tema con la ID " << idTema << endl;
		}
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
				exists = getData(fileName, autores, cantAutores);
				break;
			case 3:
				cout << "¿Cuál es el nombre del archivo de videos?" << endl;
				cin >> fileName;
				exists = getData(fileName, videos, cantVideos, temas, cantTemas, autores, cantAutores);
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
