
#ifndef ARBOL_H
#define ARBOL_H

#include "Lista.h"
class cuadrado;


class arbol
{
public:

	Lista<cuadrado> cuadradosArchivados;
	Lista<cuadrado> cuadradosFrontera;

	arbol(void):nivel(0) {
	
		cuadradosArchivados= Lista<cuadrado>();
		cuadradosArchivados= Lista<cuadrado>();
	
	}


	
	int nivel;

	void pintaSiguienteNivel();

	void addCuadradoFrontera(cuadrado);
	void addCuadradoArchivados(cuadrado);
	void draw();
	void pintaCuadrados();
<<<<<<< HEAD
	void addCuadradoInicial(punto,GLdouble);
=======
<<<<<<< HEAD
	void addCuadradoInicial(punto,GLdouble);
=======
>>>>>>> 5deea40d5f70b2a4e8c138d32bdf0b5006e81b70
>>>>>>> ded47e05e2e5d296f34ee78f56bf84a6ca2a21f2

};


#endif // !ARBOL_H
