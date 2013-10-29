/********************************************************************************
*																				*
*		Practica 1 IG - Pythagoras tree											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/


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

	if(cuadrado_selecionado)
	{
		glColor3f(0,0,0);
	}
	else
	{
		glColor3f(red,green,blue);
	}
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

cuadrado cuadrado:: dameCuadradoDerecho(GLdouble angulo)
{
	//GLdouble h=sqrt(2)*distancia/2.0;
	GLdouble h= distancia*cos(3.1416*angulo/180.0);
	cuadrado derecha(esquina_superior_derecha,h);
	derecha.setEsquinaInferiorDerecha(esquina_superior_derecha);
	derecha.crearCuadradoDerecha(direccion-90-angulo);
	if (red!=0)
		derecha.setRed(red-0.005);
	else
		derecha.setRed(0);
	if (green!=1)
		derecha.setGreen(green+0.005);
	else 
		derecha.setGreen(1);
	if (blue!=0)
		derecha.setBlue(blue-0.005);
	else
		derecha.setBlue(0);
	return derecha;
}

cuadrado cuadrado:: dameCuadradoIzquierdo(GLdouble angulo)
{
	//GLdouble h=sqrt(2)*distancia/2.0;
	GLdouble h=distancia*sin(3.1416*angulo/180.0);
	cuadrado izquierda(esquina_superior_izquierda,h);
	izquierda.creaCuadrado(direccion-90-angulo);
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

bool cuadrado :: selecionado(punto a, GLdouble eps)
{
	bool seleccion=false;

	if (a.estaCerca(esquina_inferior_derecha,eps) || a.estaCerca(esquina_inferior_izquierda,eps) || a.estaCerca(esquina_superior_derecha,eps) || a.estaCerca(esquina_superior_izquierda,eps))
	{
		cuadrado_selecionado=true;
		seleccion=true;
	}
	return seleccion;

}