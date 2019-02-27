#ifndef Fecha_h
#define Fecha_h

class Fecha
{ 
	public:
		Fecha();

		int getDD();
		int getMM();
		int getAA();

		void setFecha(int d, int m, int a);
		
	private:
		int dd, mm, aa;	
};
#endif

Fecha::Fecha()
{ 
	dd = 1;
	mm = 1;
	aa = 2000;

}

int Fecha::getDD()
{ 
	return dd;
}

int Fecha::getMM()
{ 
	return mm;
}

int Fecha::getAA()
{ 
	return aa;
}

void Fecha::setFecha(int d, int m, int a)
{ 
	dd = d;
	mm = m;
	aa = a;
}
