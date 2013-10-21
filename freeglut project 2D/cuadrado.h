#ifndef CUADRADO_H
#define CUADRADO_H
#include "punto.h"

class cuadrado
{
public:
	cuadrado(punto ini, GLdouble l):esquina_inferior_izquierda(ini), distancia(l){}

	void  pintarCuadrado() const;
	punto esquina_inferior_izquierda;
	punto esquina_inferior_derecha;
	punto esquina_superior_izquierda;
	punto esquina_superior_derecha;
	GLdouble distancia;
	GLdouble direccion;
<<<<<<< HEAD
	
=======
>>>>>>> 5deea40d5f70b2a4e8c138d32bdf0b5006e81b70
	GLdouble red;
	GLdouble green;
	GLdouble blue;

	void creaCuadrado(GLdouble dir);
	cuadrado dameCuadradoDerecho();
	cuadrado dameCuadradoIzquierdo();
	void setEsquinaInferiorDerecha(punto a);
	void crearCuadradoDerecha(GLdouble dir);
	void setRed(GLdouble);
	void setGreen(GLdouble);
	void setBlue(GLdouble);


};


#endif // CUADRADO_H
