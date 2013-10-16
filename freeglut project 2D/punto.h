#ifndef PUNTO_H
#define PUNTO_H



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
	punto(): x(0),y(0){}
	/* Getter setter
	GLdouble x() const;
	GLdouble y() const;
	void x(GLdouble);
	void y(GLdouble);
	*/
	punto& operator = (const punto &p);
};

#endif // !PUNTO_H
