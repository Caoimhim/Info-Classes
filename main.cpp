/* Proyecto 2
 * Provee una interface con la cuál interactuar con información de videos acerca de diferentes temas.
 * Los videos se asocian con un tema y una lista de autores. Cada tema se asocia con diferentes materias.
 * Kevin Daniel Chinchilla Flores
 * A00825945
 * 2019/03/10
 */
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
//Revisa Temas
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

//Revisa Autores
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

//Revisa videos
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

/* buscarTema
 * busca el tema en el arreglo de temas y regresa su nombre
 * Input, la id a buscar, el arreglo de temas y su tamaño
 * Outputs: string con el nombre del tema
 */
string buscarTema(int id, Tema temas[10], short int cant)
{ 
	for (unsigned char i = 0; i < cant; i++)
	{ 
		if (id == temas[i].getIDTema())
		{ 
			return temas[i].getNombre();
		}
	}
	return "\0";
}

/* buscarAutor
 * busca el autor en el arreglo de autor y regresa su nombre
 * Input, la id a buscar, el arreglo de autor y su tamaño
 * Outputs: string con el nombre del autor
 */
string buscarAutor(int id, Autor autores[10], short int cant)
{ 
	for (unsigned char i = 0; i < cant; i++)
	{ 
		if (id == autores[i].getIDAutor())
		{ 
			return autores[i].getNombre();
		}
	}
	return "\0";
}
/* getData
 * Obtiene input the un archivo cuyo nombre es dado y lo lee en el formata ID Nombre
 * Inputs: El nombre del archivo
 * Outputs: Escribe a un arreglo de objetos (sobrecargada a para soportar los diferentes tipos), el arreglo donde se guardaran los datos, y una entero para guardar el numero de este.
 * Regresa verdadero si encuentra el archivo, falso si no
 */
//Lee materias
bool getData(string fileName, Materia materias[5], short int &cant)
{ 
	cant = 0;
	ifstream inFile;
	inFile.open(fileName.c_str());
	if(!inFile.is_open())
	{ 
		return false;
	}
	int id;
	while(inFile >> id)
	{ 
		materias[cant].setID(id);
		string nombre;
		getline(inFile, nombre);
		nombre.erase(0, 1);
		if (nombre[nombre.length() - 1] == '\r')
		{ 
			nombre.pop_back();
		}
		materias[cant++].setNombre(nombre);
	}
	inFile.close();
	return true;
}

//Lee temas
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

	inFile.close();
	return true;
}

//Lee autores
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
	inFile.close();
	return true;
}

//Lee videos
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
			int lineAutores = strtol(buffer.c_str(), NULL, 10);
	
			data = data.substr(pos+1);
			int inAutores[10];
			int countinAutores = 0;
			int idAutor;
			bool exists = true; 
			for (unsigned char i = 0; i < lineAutores && exists; i++)
			{ 
				pos = data.find(" ");
				idAutor = strtol(data.substr(0,pos).c_str(), NULL, 10);
				data = data.substr(pos+1);
	
				if(!checkExists(idAutor, autores, cantAutores))	
				{ 
					exists = false;	
				}
				inAutores[countinAutores++] = idAutor;
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

				for (unsigned char i = 0; i < countinAutores; i++)
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
	inFile.close();
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

/* mostrarVideos
 * imprime a la pantalla los detalles de un video, ua sea por clase, materia, o por autor
 * Inputs: El arreglo de videos, la cantidad de videos, y el arreglo y cantidad del objeto por el cual se quiere consultar
 * Outputs: NONE
 */
//Por tema
void mostrarVideos(int id, EjemploVideo videos[20], short int cantVideos, Autor autores[10], short int cantAutores)
{ 
	bool found = false;
	cout << "Videos con el tema " << id << endl;
	for (unsigned char j = 0; j < cantVideos; j++)
	{ 
		if (id == videos[j].getIDTema() )
		{ 
			found = true;
			cout << "ID: " << videos[j].getIDVideo() << endl;
			cout << "Nombre: " << videos[j].getNombre() << endl;
			
			videos[j].getFechasElaboracion().muestra();
			cout << endl;
			cout << "Autores: ";
			for ( unsigned char k = 0; k < videos[j].getCantidadAutores(); k++)
			{ 
				string autorNom = buscarAutor(videos[j].getlistaAutores(k), autores, cantAutores);
				if (autorNom != "\0")
				{ 
					cout << autorNom << endl;
				}
			}
			cout << endl;
		}
	}
	if (!found)
	{ 
		cout << "No se encontraron videos con esta información" << endl;
	}
}

//Por materia
void mostrarVideosPorMateria(int id, EjemploVideo videos[20], short int cantVideos, Tema temas[10], short int cantTemas, Autor autores[10], short int cantAutores)
{ 
	bool found = false;
	cout << "Videos con la materia " << id << endl;
	for (unsigned char i = 0; i < cantTemas; i++)
	{ 
		if (temas[i].getIDMateria() == id)	
		{ 
			for (unsigned char j = 0; j < cantVideos; j++)
			{ 
				if(videos[j].getIDTema() == temas[i].getIDTema()) 
				{ 
					found = true;
					cout << "ID: " << videos[j].getIDVideo() << endl;
					cout << "Nombre: " << videos[j].getNombre() << endl;
					cout << "Tema: " << buscarTema(videos[j].getIDTema(), temas, cantTemas) << endl;
			
					videos[j].getFechasElaboracion().muestra();
					cout << endl;
					cout << "Autores: ";
					for ( unsigned char k = 0; k < videos[j].getCantidadAutores(); k++)
					{ 
						string autorNom = buscarAutor(videos[j].getlistaAutores(k), autores, cantAutores);
						if (autorNom != "\0")
						{ 
							cout << autorNom << endl;
						}
					}
					cout << endl;
				}
			}
		}
	}
	if (!found)
	{ 
		cout << "No se encontraron videos con esta información" << endl;
	}
}

//Por autor
void mostrarVideosAutor(int id, EjemploVideo videos[20], short int cantVideos)
{ 
	bool found = false;
	cout << "Videos con el autor " << id << endl;
	for(unsigned char i = 0; i < cantVideos; i++)
	{ 
		for(unsigned char k =0; k < videos[i].getCantidadAutores(); k++)
		{ 
			if (videos[i].getlistaAutores(k) == id)
			{ 
				found = true;
				cout << "ID: " << videos[i].getIDVideo() << endl;
				cout << "Nombre: " << videos[i].getNombre() << endl;
				cout << endl;
			}
		}
	}
	if (!found)
	{ 
		cout << "No se encontraron videos con esta información" << endl;
	}
}

/* agregarVideo
 * Pide al usario que entre la información acerca de un nuevo video a través de la consola.
 * Valida todos los datos y no sale hasta que toda la información sea valida
 * Inputs: El arreglo de videos, autores y temas
 * Outputs: Escribe al arreglo de videos y su tamaño
 */
void agregarVideo(EjemploVideo videos[20], short int &cantVideos, Tema temas[10], short int cantTemas, Autor autores[10], short int cantAutores)
{ 
	int id;
	cout << "Porfavor, entre la ID del nuevo video: ";
	cin >> id;
	while(checkExists(id, videos, cantVideos))
	{ 
		cout << "Ya existe un video con esa ID, porfavor, entre un ID único: " << endl;
		cin >> id;
	}
	videos[cantVideos].setIDVideo(id);
	cin.ignore();

	string nombre;
	cout << "¿Cuál es el nombre del nuevo video?" << endl;
	getline(cin, nombre);
	videos[cantVideos].setNombre(nombre);

	cout << "¿Cuál es el ID del tema del video?" << endl;
	cin >> id;
	while(!checkExists(id, temas, cantTemas))
	{ 
		cout << "No existe un tema con ese ID, porfavor, entre un ID válido: ";
		cin >> id;
	}
	videos[cantVideos].setIDTema(id);

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
		while(!checkExists(id, autores, cantAutores) || !videos[cantVideos].agregaAutor(id))
		{ 
			cout << "ID no es valida, profavor, entre un ID válido: ";
			cin >> id;
		}
	}
	cantVideos++;
}

/* listarVideos
 * Mustra todos los videos con sus datos
 * Input: Arreglo de videos, temas, autores y materias con sus tamaños
 * Output: NONE
 */
void listarVideos(EjemploVideo videos[20], short int cantVideos, Tema temas[10], short int cantTemas, Autor autores[10], short int cantAutores)
{
	for(unsigned char j = 0; j < cantVideos; j++)
	{ 
		cout << "ID: " << videos[j].getIDVideo() << endl;
		cout << "Nombre: " << videos[j].getNombre() << endl;
		cout << "Tema: " << buscarTema(videos[j].getIDTema(), temas, cantTemas) << endl;
			
		videos[j].getFechasElaboracion().muestra();
		cout << endl;
		cout << "Autores: ";
		for ( unsigned char k = 0; k < videos[j].getCantidadAutores(); k++)
		{ 
			string autorNom = buscarAutor(videos[j].getlistaAutores(k), autores, cantAutores);
			if (autorNom != "\0")
			{ 
				cout << autorNom << endl;
			}
		}
		cout << endl;
	}
}

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
		cout << "Seleccione m para mostrar información sobre videos por materia" << endl;
		cout << "Seleccione l para mostrar la lista de los videos registrados" << endl;
		cout << "Seleccione a para mostrar información sobre videos por autor" << endl;
		cout << "Seleccione q para salir" << endl;
		cin >> option;
		int id;
		//Processing
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
				cout << "¿Qué tema quisiera consultar?" << endl;
				cin >> id;
				mostrarVideos(id, videos, cantVideos, autores, cantAutores);
				break;
			case 'm':
				cout << "¿Qué materia quisiera consultar?" << endl;
				cin >> id;
				mostrarVideosPorMateria(id,videos, cantVideos, temas, cantTemas, autores, cantAutores);
				break;
			case 'l':
				listarVideos(videos, cantVideos, temas, cantTemas, autores, cantAutores);
				break;
			case 'a':
				cout << "¿Qué autor quisiera consultar?" << endl;
				cin >> id;
				mostrarVideosAutor(id, videos, cantVideos);
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
				if (fileName.find(".txt") == fileName.npos)
				{ 
					fileName.append(".txt");
				}
				exists = getData(fileName, materias, cantMaterias);
				break;
			case 1:
				cout << "¿Cuál es el nombre del archivo de temas?" << endl;
				cin >> fileName;
				if (fileName.find(".txt") == fileName.npos)
				{ 
					fileName.append(".txt");
				}
				exists = getData(fileName, temas, cantTemas);
				break;
			case 2:
				cout << "¿Cuál es el nombre del archivo de autores?" << endl;
				cin >> fileName;
				if (fileName.find(".txt") == fileName.npos)
				{ 
					fileName.append(".txt");
				}
				exists = getData(fileName, autores, cantAutores);
				break;
			case 3:
				cout << "¿Cuál es el nombre del archivo de videos?" << endl;
				cin >> fileName;
				if (fileName.find(".txt") == fileName.npos)
				{ 
					fileName.append(".txt");
				}
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
	
	//Output
	menu(materias, cantMaterias, temas, cantTemas, autores, cantAutores, videos, cantVideos);

	return 0;
}
