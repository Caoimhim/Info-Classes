#ifndef Tema_h
#define Tema_h

class Tema
{ 
	public:
		Tema();

		int getIDTema();
		string getNombre();
		int getIDMateria();

		void setIDTema(int id);
		void setNombre(string nom);
		void setIDMateria(int id);

	private:
		int idTema;
		string nombre;
		int idMateria;

};

Tema::Tema()
{ 
	idTema = 0;
	nombre = '\0';
	idMateria = 0;
}

int Tema::getIDTema()
{ 
	return idTema;
}

string Tema::getNombre()
{ 
	return nombre;
}

int Tema::getIDMateria()
{ 
	return idMateria;
}

void Tema::setIDTema(int id)
{ 
	idTema = id;
}

void Tema::setNombre(string nom)
{ 
	nombre = nom;
}

void Tema::setIDMateria(int id)
{ 
	idMateria = id;
}
#endif
