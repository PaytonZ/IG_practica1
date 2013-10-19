#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h> 

#include <GL/freeglut.h>


#include <iostream>

#include "escena.h"
#include "controlador.h"
#include "lapiz.h"
#include "cuadrado.h"



void  cuadrado::  pintarCuadrado() const
{
	//Sentido antihorario
	glBegin(GL_QUADS);

		glVertex2d(esquina_inferior_izquierda.x,esquina_inferior_izquierda.y);
		glVertex2d(esquina_inferior_derecha.x,esquina_inferior_derecha.y);
		glVertex2d(esquina_superior_derecha.x,esquina_superior_derecha.y);
		glVertex2d(esquina_superior_izquierda.x,esquina_superior_izquierda.y);

	glEnd();

}

void cuadrado::creaCuadrado(GLdouble dir)
{
	lapiz a;
	a.pos=esquina_inferior_izquierda;
	a.dir=dir;
	a.forward(distancia,false);
	esquina_inferior_derecha=a.pos; // ESTO NO SE SI ESTARA BIEN, SI LO QUE HACE ES QUE EL PUNTERO DE ESTO APUNTE A A.POS ESTA MAL.
	a.turnTo(90);
	a.forward(distancia,false);
	esquina_superior_derecha=a.pos;
	a.turnTo(90);
	direccion=a.dir;
	a.forward(distancia,false);
	esquina_superior_izquierda=a.pos;


}

void cuadrado:: crearCuadradoDerecha(GLdouble dir)
{
	lapiz a;
	a.pos=esquina_inferior_derecha;
	a.dir=dir;
	a.forward(distancia,false);
	esquina_superior_derecha=a.pos;
	a.turnTo(90);
	direccion=a.dir;
	a.forward(distancia,false);
	esquina_superior_izquierda=a.pos;
	a.turnTo(90);
	a.forward(distancia,false);
	esquina_inferior_izquierda=a.pos;

}

cuadrado cuadrado:: dameCuadradoDerecho()
{
	GLint h=sqrt((distancia/2)*(distancia/2)*2);
	cuadrado derecha(esquina_superior_derecha,h);
	derecha.setEsquinaInferiorDerecha(esquina_superior_derecha);
	derecha.crearCuadradoDerecha(direccion-135);
	return derecha;
}

cuadrado cuadrado:: dameCuadradoIzquierdo()
{
	GLint h=sqrt((distancia/2)*(distancia/2)*2);
	cuadrado izquierda(esquina_superior_izquierda,h);
	izquierda.creaCuadrado(direccion-135);
	return izquierda;
}

void cuadrado :: setEsquinaInferiorDerecha(punto a)
{
	esquina_inferior_derecha=a;
}