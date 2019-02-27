#ifndef Autor_h
#define Autor_h

class Autor
{ 
	public:
		Autor();

		int getIDAutor();
		string getNombre();

		void setIDAutor(int id);
		void setNombre(string nom);
	private:
		int idAutor;
		string nombre;
	
};

Autor::Autor()
{ 
	idAutor = 0;
	nombre = '\0';
}

int Autor::getIDAutor()
{ 
	return idAutor;
}

string Autor::getNombre()
{ 
	return nombre;
}

void Autor::setIDAutor(int id)
{ 
	idAutor = id;
}

void Autor::setNombre(string nom)
{ 
	nombre = nom;
}

#endif
