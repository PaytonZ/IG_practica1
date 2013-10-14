#include <Windows.h>
#include "punto.h"
#include <gl/GL.h>
#include <gl/GLU.h>

class escena
{

	private:
		
	
	GLdouble xRight;
	GLdouble xLeft;

	GLdouble yRight;
	GLdouble yLeft;


public:
	escena() {}
	escena(GLdouble new_xleft, GLdouble new_yleft , GLdouble new_xright, GLdouble new_yright ):
		xLeft(new_xleft) , xRight(new_xright) ,  yLeft(new_yleft) , yRight(new_yright) {}
		

	/*
	getter setter para 4
	centro de la escena


	*/

	GLdouble getxRight();
	void setxRight(GLdouble);

	GLdouble getyRight() const;
	void setyRight(GLdouble);

	GLdouble getxLeft() const;
	void setxLeft(GLdouble);

	GLdouble getyLeft() const;
	void  setyLeft(GLdouble);
	
	punto getCentro();

	void resize(int, int);




	

};

