
#ifndef ARBOL_H
#define ARBOL_H

#include "Lista.h"
class cuadrado;


class arbol
{
public:

	Lista<cuadrado> cuadradosArchivados;
	Lista<cuadrado> cuadradosFrontera;
	Lista< Lista<cuadrado> *> cuadrados;

	arbol(void):nivel(0) {
	
		cuadradosArchivados= Lista<cuadrado>();
		cuadradosArchivados= Lista<cuadrado>();
		cuadrados = Lista< Lista<cuadrado> *>();
	
	}


	
	int nivel;

	void pintaSiguienteNivel();

	void addCuadradoFrontera(cuadrado);
	void addCuadradoArchivados(cuadrado);
	void draw();
	void pintaCuadrados();
	void addCuadradoInicial(punto,GLdouble);
	void quitaUnNivel();

		void  liberarArbol()
		 {
			 Lista<Lista <cuadrado> *> :: Iterador it = cuadrados.principio();
			 while(it!=cuadrados.final())
			 {
				 Lista<cuadrado>* l= it.elem();
				 it.avanza();
				 delete l;
			 }
		 }

};


#endif // !ARBOL_H
