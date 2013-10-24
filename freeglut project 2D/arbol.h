
#ifndef ARBOL_H
#define ARBOL_H

#include "Lista.h"
class cuadrado;


class arbol
{
public:

	
	Lista< Lista<cuadrado >*> cuadrados;

	arbol(void):nivel(0) {
	
		
		cuadrados = Lista< Lista<cuadrado > *>();
	
	}


	
	int nivel;

	

	
	void draw();
	void pintaCuadrados();
	void addCuadradoInicial(punto);
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
	void selecion(punto);

};


#endif // !ARBOL_H
