#ifndef CUADRADO_H
#define CUADRADO_H
#include "punto.h"

class cuadrado
{
public:
	cuadrado(punto ini, GLint l):esquina_inferior_izquierda(ini), distancia(l){}

	void  pintarCuadrado() const;
	punto esquina_inferior_izquierda;
	punto esquina_inferior_derecha;
	punto esquina_superior_izquierda;
	punto esquina_superior_derecha;
	GLdouble distancia;
	GLdouble direccion;

	void creaCuadrado(GLdouble dir);
	cuadrado dameCuadradoDerecho();
	cuadrado dameCuadradoIzquierdo();
	void setEsquinaInferiorDerecha(punto a);
	void crearCuadradoDerecha(GLdouble dir);


};


#endif // CUADRADO_H
