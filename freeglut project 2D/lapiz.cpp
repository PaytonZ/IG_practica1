#include "lapiz.h"
#include <cmath>

#define M_PI (3.1415926535897932384626433832795)

	void lapiz::moveTo(punto p,bool draw)
	{
		if(draw)
		{
			 glBegin(GL_LINES);
				glVertex2d(pos.x, pos.y);
				glVertex2d(p.x, p.y);
	        glEnd();
		}
		pos=p;

	}
	void lapiz::turnTo(GLdouble a)
	{
		dir+=a;
	}
	void lapiz::forward(GLdouble dist,bool draw )
	{
		punto nuevo_punto ;
		nuevo_punto.x+=dist*cos(dir);
		nuevo_punto.y+=dist*cos(dir);

		if(draw)
		{
			 glBegin(GL_LINES);
				glVertex2d(pos.x, pos.y);
				glVertex2d(nuevo_punto.x, nuevo_punto.y);
         glEnd();
		}
		pos=nuevo_punto;


	}