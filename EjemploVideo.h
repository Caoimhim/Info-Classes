#ifndef EjemploVideo_h
#define EjemploVideo_h

class EjemploVideo
{ 
	public:
		EjemploVideo();

		int getIDVideo();
		string getNombre();
		int getIDTema();
		Fecha getFechasElaboracion();
		int getlistaAutores(int index);

		void setIDVideo(int id);
		void setNombre(string nom);
		void setIDTema(int id);
		void setfechaElaboracion(Fecha newFecha);

		bool agregaAutor(int newAutor);

	private:
		int idVideo;
		string nombre;
		int idTema;
		Fecha fechaElaboracion;
		int cantidadAutores;
		int listaAutores[10];

};

EjemploVideo::EjemploVideo()
{ 
	idVideo = 0;
	nombre = '\0';
	idTema = 0;
	cantidadAutores = 0;
}

int EjemploVideo::getIDVideo()
{ 
	return idVideo;
}

string EjemploVideo::getNombre()
{ 
	return nombre;
}

int EjemploVideo::getIDTema()
{ 
	return idTema;
}

Fecha EjemploVideo::getFechasElaboracion()
{ 
	return fechaElaboracion;
}

int EjemploVideo::getlistaAutores(int index)
{ 
	return listaAutores[index];
}

void EjemploVideo::setIDVideo(int id)
{ 
	idVideo = id;
}

void EjemploVideo::setNombre(string nom)
{ 
	nombre = nom;
}

void EjemploVideo::setIDTema(int id)
{ 
	idTema = id;
}

void EjemploVideo::setfechaElaboracion(Fecha newFecha)
{ 
	fechaElaboracion = newFecha;
}

bool EjemploVideo::agregaAutor(int newAutor)
{ 
	if (newAutor > 10 )
	{ 
		return false;
	}
	else
	{ 
		for (char i = 0; i < cantidadAutores; i++ )
		{ 
			if (newAutor == listaAutores[i])
			{ 
				return false;
			}
		}
		cantidadAutores++;
		listaAutores[cantidadAutores] = newAutor;
		return true;
	}
}
#endif
