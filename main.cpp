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
bool checkExists(int tema, Tema temas[10], short int cant)
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

bool checkExists(int autor, Autor autores[10], short int cant)
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

bool checkExists(int video, EjemploVideo videos[20], short int cant)
{ 
	for(short int i = 0; i < cant; i++)
	{ 
		if(video == videos[i].getIDVideo())
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
		string nombre = (data.substr(pos + 1));
		if (nombre[nombre.length() - 1] == '\r')
		{ 
			nombre.pop_back();
		}
		materias[cant++].setNombre(nombre);
	}

	return true;
}

bool getData(string fileName, Tema temas[10], short int &cant)
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
		string nombre = (data.substr(pos2 + 1));
		if (nombre[nombre.length() - 1] == '\r')
		{ 
			nombre.pop_back();
		}
		temas[cant++].setNombre(nombre);
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
		string nombre = (data.substr(pos + 1));
		if (nombre[nombre.length() - 1] == '\r')
		{ 
			nombre.pop_back();
		}
		autores[cant++].setNombre(nombre);
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
	int idVideo, idTema, d, m, a, autoresLinea;
	string nombre;
	while(inFile >> idVideo >> nombre >> idTema >> d >> m >> a >> autoresLinea)
	{ 
		int inAutores[10];
		int idAutor;
		bool exists = true; 
			
		for (unsigned char i = 0; i < autoresLinea; i++)
		{ 
			inFile >> idAutor;
	
			if(!checkExists(idAutor, autores, autoresLinea))	
			{ 
				exists = false;	
			}
			inAutores[i] = idAutor;
		}
		if (checkExists(idTema, temas, cantTemas))
		{ 
			if (!exists)
			{ 
				cout << "¡Advertencia! No se encontró el autor con la ID " << idAutor << endl;
			}
			else
			{ 
				cout << "writing...\n";
				cout << idVideo << ' ' << nombre << ' ' << idTema << ' ' << d << '/' << m << '/' << a << ' ' << endl;
				videos[cant].setIDVideo(idVideo);
				videos[cant].setNombre(nombre);
				videos[cant].setIDTema(idTema);
				Fecha fechaElab;
				fechaElab.setFecha(d, m, a);
				videos[cant].setfechaElaboracion(fechaElab);

				for (unsigned char i = 0; i < autoresLinea; i++)
				{ 
					videos[cant].agregaAutor(inAutores[i]);
					cout << inAutores[i];
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

/* mostrarMaterias
 * Imprime a la pantalla toda la información acerca de las materias
 * Inputs: El arreglo de materias y su tamaño
 * Outputs: NONE
 */
void mostrarMaterias(Materia materias[5], short int cantMaterias)
{ 
	cout << "\tMaterias" << endl;
	cout << "ID\tNombre" << endl;
	for(unsigned char i = 0; i < cantMaterias; i++)
	{ 
		cout <<  materias[i].getID() << '\t' << materias[i].getNombre() << endl;
	}
	cout << endl;
	
}

/* mostrarTemas
 * Imprime a la pantalla toda la información acerca de los temas
 * Input: El arreglo de los temas y su tamaño
 * Output: NONE
 */
void mostrarTemas(Tema temas[10], short int cantTemas)
{ 
	cout << "\tTemas" << endl;
	cout << "ID\tID de materia\t\tNombre" << endl;
	for (unsigned char i = 0; i < cantTemas; i++)
	{ 
		cout << temas[i].getIDTema() << '\t' << temas[i].getIDMateria() << "\t\t" << temas[i].getNombre() << endl;
	}
	cout << endl;
}

/*mostrarAutores
 * Imprime a la pantalla toda la información acerca de los autores
 * Inputs: El arreglo de autores y su tamaño
 * Outputs: NONE
 */
void mostrarAutores(Autor autores[10], short int cantAutores)
{ 
	cout << "\tAutores" << endl;
	cout << "ID\tNombre" << endl;
	for(unsigned char i = 0; i < cantAutores; i++)
	{ 
		cout <<  autores[i].getIDAutor() << '\t' << autores[i].getNombre() << endl;
	}
	cout << endl;
}

void mostrarVideos(EjemploVideo videos[20], short int cantVideos, Materia materias[5], short int cantMaterias);

void mostrarVideos(EjemploVideo videos[20], short int cantVideos, Autor auotres[10], short int cantAutores);

void mostrarVideos(EjemploVideo videos[20], short int cantVideos, Tema temas[10], short int cantTemas);

/* agregarVideo
 * Pide al usario que entre la información acerca de un nuevo video a través de la consola.
 * Valida todos los datos y no sale hasta que toda la información sea valida
 * Inputs: El arreglo de videos, autores y temas
 * Outputs: Escribe al arreglo de videos y su tamaño
 */
void agregarVideo(EjemploVideo videos[20], short int &cantVideos, Tema temas[10], short int cantTemas, Autor autores[10], short int cantAutores)
{ 
	cantVideos++;
	int id;
	cout << "Porfavor, entre la ID del nuevo video: ";
	cin >> id;
	while(checkExists(id, videos, cantVideos))
	{ 
		cout << "Ya existe un video con esa ID, porfavor, entre un ID único: " << endl;
		cin >> id;
	}
	videos[cantVideos].setIDVideo(id);

	string nombre;
	cout << "¿Cuál es el nombre del nuevo video?" << endl;
	cin >> nombre;
	videos[cantVideos].setNombre(nombre);

	cout << "¿Cuál es el ID del tema del video?" << endl;
	cin >> id;
	while(!checkExists(id, temas, cantTemas))
	{ 
		cout << "No existe un tema con ese ID, porfavor, entre un ID válido: ";
		cin >> id;
	}

	int a, m, d;
	cout << "Año de elaboración: ";
	cin >> a;
	cout << "Mes: ";
	cin >> m;
	cout << "Día: ";
	cin >> d;
	Fecha fechaElab;
	fechaElab.setFecha(d, m, a);
	videos[cantVideos].setfechaElaboracion(fechaElab);

	int inAutores;
	cout << "¿Cuántos autores tiene este video?" << endl;
	cin >> inAutores;

	for (short int i = 0; i < inAutores; i++)
	{ 
		cout << "¿Cuál es la ID del autor " << i + 1 << "?" << endl;
		cin >> id;
		while(!checkExists(id, autores, cantAutores))
		{ 
			cout << "No existe un autor con esa ID, profavor, entre un ID válido: ";
			cin >> id;
		}
		videos[cantVideos].agregaAutor(id);
	}

	
}

void listarVideos(EjemploVideo videos[20], short int cantVideos);



/* menu
 * muesta el menú y llama las funciones requeridas para hacer las operaciones necesarias
 * Inputs: Los datos de materias, temas, autores, y videos
 * Outputs: Puede modificiar los arreglos de información
 */
void menu(Materia materias[5], short int cantMaterias, Tema temas[10], short int cantTemas, Autor autores[10], short int cantAutores, EjemploVideo videos[20], short int &cantVideos)
{ 
	cout << endl;
	bool running = true;
	while (running)
	{ 
		char option;
		cout << "Seleccione p para mostrar la información de autores, materias y temas" << endl;
		cout << "Seleccione s para sumar un video" << endl;
		cout << "Seleccione t para mostrar información sobre videos por tema" << endl;
		cout << "Seleccione m para mostrar información sobre videos por tema" << endl;
		cout << "Seleccione l para mostar la lista de los videos registrados" << endl;
		cout << "Seleccione a para mostrar información sobre videos por autor" << endl;
		cout << "Seleccione q para salir" << endl;
		cin >> option;
		int id;
		switch(tolower(option))
		{ 
			case 'p':
				mostrarMaterias(materias, cantMaterias);
				mostrarTemas(temas, cantTemas);
				mostrarAutores(autores, cantAutores);
				break;
			case 's':
				agregarVideo(videos, cantVideos, temas, cantTemas, autores, cantAutores);
				break;
			case 't':
				//cout << "¿Qué tema quisiera consultar?" << endl;
				cin >> id;
				//mostrarVideos(videos, cantVideos, temas, cantTemas);
				break;
			case 'm':
				cout << "¿Qué materia quisiera consultar?" << endl;
				cin >> id;
				//mostrarVideos(videos, cantVideos, materias, cantMaterias);
				break;
			case 'l':
				//listarVideos(videos, cantVideos);
				break;
			case 'a':
				cout << "¿Qué autor quisiera consultar?" << endl;
				cin >> id;
				//mostrarVideos(videos, cantVideos, autores, cantAutores);
				break;
			case 'q':
				cout << "terminado" << endl;
				running = false;
				break;
			default:
				cout << "Porfavor seleccionar una opcion apropiada" << endl;
		}
		cout << endl;
	}
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
	
	menu(materias, cantMaterias, temas, cantTemas, autores, cantAutores, videos, cantVideos);

	return 0;
}
