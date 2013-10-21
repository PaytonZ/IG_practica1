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
	glColor3f(red,green,blue);
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
	esquina_inferior_derecha=a.pos; 
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
	GLdouble h=sqrt(2)*distancia/2.0;
	cuadrado derecha(esquina_superior_derecha,h);
	derecha.setEsquinaInferiorDerecha(esquina_superior_derecha);
	derecha.crearCuadradoDerecha(direccion-135);
	if (red!=0)
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> ded47e05e2e5d296f34ee78f56bf84a6ca2a21f2
>>>>>>> 9fd1f27fcf753cb90eb51381b14b69b5acebbe7a
		derecha.setRed(red-0.005);
	else
		derecha.setRed(0);
	if (green!=1)
		derecha.setGreen(green+0.005);
	else 
		derecha.setGreen(1);
	if (blue!=0)
		derecha.setBlue(blue-0.005);
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
=======
		derecha.setRed(red-0.1);
	else
		derecha.setRed(0);
	if (green!=1)
		derecha.setGreen(green+0.1);
	else 
		derecha.setGreen(1);
	if (blue!=0)
		derecha.setBlue(blue-0.01);
>>>>>>> 5deea40d5f70b2a4e8c138d32bdf0b5006e81b70
>>>>>>> ded47e05e2e5d296f34ee78f56bf84a6ca2a21f2
>>>>>>> 9fd1f27fcf753cb90eb51381b14b69b5acebbe7a
	else
		derecha.setBlue(0);
	return derecha;
}

cuadrado cuadrado:: dameCuadradoIzquierdo()
{
	GLdouble h=sqrt(2)*distancia/2.0;
	cuadrado izquierda(esquina_superior_izquierda,h);
	izquierda.creaCuadrado(direccion-135);
	if (red!=0)
		izquierda.setRed(red-0.1);
	else
		izquierda.setRed(0);
	if (green!=1)
		izquierda.setGreen(green+0.1);
	else 
		izquierda.setGreen(1);
	if (blue!=0)
		izquierda.setBlue(blue-0.01);
	else
		izquierda.setBlue(0);
	return izquierda;
}

void cuadrado :: setEsquinaInferiorDerecha(punto a)
{
	esquina_inferior_derecha=a;
}

void cuadrado :: setRed(GLdouble colorred)
{
	red=colorred;
}

void cuadrado :: setBlue (GLdouble colorblue)
{
	blue=colorblue;
}

void cuadrado :: setGreen (GLdouble colorgreen)
{
	green=colorgreen;
}