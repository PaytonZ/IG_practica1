/********************************************************************************
*																				*
*		Practica 1 IG - Pythagoras tree											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/


#ifndef ESCENA_H
#define ESCENA_H

#include <Windows.h>
#include "punto.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "arbol.h"



extern int WIDTH, HEIGHT ;

class escena
{

public:


	bool baldosas;


	static escena* getAVEInstance();
	static escena* getAVEInstance(GLdouble new_xleft, GLdouble new_yBot , GLdouble new_xright, GLdouble new_yTop);
		
	GLdouble getxRight() const;
	void setxRight(GLdouble);

	GLdouble getxLeft() const;
	void setxLeft(GLdouble);

	GLdouble getyTop() const;
	void  setyTop(GLdouble);

	GLdouble getyBot() const;
	void setyBot(GLdouble);

	punto getCentro();

	static	void  __cdecl resize(int newWidth, int newHeight);

	void translacionX(GLdouble);
	void translacionY(GLdouble);
	void escalacion(GLdouble);

	arbol* getArbol();
	void setArbol(arbol*);

	void draw();

	arbol *arbol_pitagoras;

	punto dePuertodeVistaaAVE(int,int);

	void escalacionProgresivo(GLdouble);

	static void display();

	void embaldosar(int);

	void drawEscene();

	void activarDesActivarBaldosas();

private:

	escena() {}
	escena(GLdouble new_xleft, GLdouble new_yBot , GLdouble new_xright, GLdouble new_yTop):
		xLeft(new_xleft) , xRight(new_xright) ,  yBot(new_yBot) , yTop(new_yTop), baldosas(false) {
			arbol_pitagoras = new arbol();

	}

	static escena* AVE;
	static void _AVE_deleter() { delete AVE; }

	//arbol arbol_pitagoras;

	GLdouble xLeft;
	GLdouble xRight;

	GLdouble yBot;
	GLdouble yTop;


};

#endif // !ESCENA_H

