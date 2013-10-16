
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
	
	cuadrado cuadradoprincipal;
	GLdouble tam=50.0;

	cuadradoprincipal.esquina_superior_izquierda.x=100.0;
	cuadradoprincipal.esquina_superior_izquierda.y=100.0;

	cuadradoprincipal.esquina_superior_derecha.x=cuadradoprincipal.esquina_superior_izquierda.x+tam;
	cuadradoprincipal.esquina_superior_derecha.y=cuadradoprincipal.esquina_superior_izquierda.y;

	cuadradoprincipal.esquina_inferior_izquierda.x=cuadradoprincipal.esquina_superior_izquierda.x;
	cuadradoprincipal.esquina_inferior_izquierda.y=cuadradoprincipal.esquina_inferior_izquierda.y+tam;

	cuadradoprincipal.esquina_inferior_derecha.x=cuadradoprincipal.esquina_superior_derecha.x;
	cuadradoprincipal.esquina_inferior_derecha.y=cuadradoprincipal.esquina_inferior_derecha.y+tam;

	cuadradoprincipal.pintarCuadrado();

	cuadradosFrontera.ponDr(cuadradoprincipal);


	}


	
	int nivel;

	void pintaSiguienteNivel();

	void addCuadradoFrontera(cuadrado);
	void addCuadradoArchivados(cuadrado);

};


#endif // !ARBOL_H
