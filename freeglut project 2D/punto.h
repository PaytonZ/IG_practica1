#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

class punto
{
public:

	GLdouble x;
	GLdouble y;
	//Constuctor - destructor
	punto(GLdouble newx , GLdouble newy): x(newx), y(newy){}
	
	/* Getter setter
	GLdouble x() const;
	GLdouble y() const;
	void x(GLdouble);
	void y(GLdouble);
	*/
};


