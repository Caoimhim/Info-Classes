#ifndef Materia_h
#define Materia_h

class Materia
{ 	
	public:
		Materia();

		int getID();
		string getNombre();

		void setID(int id);
		void setNombre(string nom);


	private:
		int idMateria;
		string nombre;
};

Materia::Materia()
{ 
	idMateria = 0;
	nombre = '\0';
}

int Materia::getID()
{ 
	return idMateria;
}

string Materia::getNombre()
{ 
	return nombre;
}

void Materia::setID(int id)
{ 
	idMateria = id;	
}

void Materia::setNombre(string nom)
{ 
	nombre = nom;
}

#endif
