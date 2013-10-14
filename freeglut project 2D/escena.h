#include <Windows.h>
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

	GLdouble xRight() const;
	void xRight(GLdouble);

	GLdouble yRight() const;
	void yRight(GLdouble);

	GLdouble xLeft() const;
	void xLeft(GLdouble);

	GLdouble yLeft() const;
	void yLeft(GLdouble);
	
	GLdouble getCentro();



	

};

