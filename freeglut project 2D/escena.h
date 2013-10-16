#ifndef ESCENA_H
#define ESCENA_H

#include <Windows.h>
#include "punto.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "arbol.h"



extern int WIDTH, HEIGHT;

class escena
{

public:

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

	arbol getArbol();
	void setArbol(arbol);



private:

	escena() {}
	escena(GLdouble new_xleft, GLdouble new_yBot , GLdouble new_xright, GLdouble new_yTop):
		xLeft(new_xleft) , xRight(new_xright) ,  yBot(new_yBot) , yTop(new_yTop) {}

	static escena* AVE;
	static void _AVE_deleter() { delete AVE; }

	arbol arbol_pitagoras;

	GLdouble xLeft;
	GLdouble xRight;

	GLdouble yBot;
	GLdouble yTop;


};

#endif // !ESCENA_H

