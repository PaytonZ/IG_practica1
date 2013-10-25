#ifndef CUADRADO_H
#define CUADRADO_H
#include "punto.h"

class cuadrado
{
public:
	cuadrado(punto ini, GLdouble l):esquina_inferior_izquierda(ini), distancia(l),cuadrado_selecionado(false){}

	
	punto esquina_inferior_izquierda;
	punto esquina_inferior_derecha;
	punto esquina_superior_izquierda;
	punto esquina_superior_derecha;
	
	GLdouble distancia;
	GLdouble direccion;
	//Colores
	GLfloat red;
	GLfloat green;
	GLfloat blue;
	bool cuadrado_selecionado;

	void creaCuadrado(GLdouble dir);
	void  pintarCuadrado() const;
	cuadrado dameCuadradoDerecho(GLdouble angulo);
	cuadrado dameCuadradoIzquierdo(GLdouble angulo);
	void setEsquinaInferiorDerecha(punto a);
	void crearCuadradoDerecha(GLdouble dir);
	void setRed(GLdouble);
	void setGreen(GLdouble);
	void setBlue(GLdouble);
	bool selecionado(punto, GLdouble) ;


};


#endif // CUADRADO_H
