#include "lapiz.h"
#include "punto.h"
#include <cmath>
#ifndef M_PI
#define M_PI (3.1415926535897932384626433832795)
#endif



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
		
		nuevo_punto.x= pos.x + dist*cos(M_PI*dir/180.0);
		nuevo_punto.y= pos.y + dist*sin(M_PI*dir/180.0);
		
		glClear( GL_COLOR_BUFFER_BIT );
		
		if(draw)
		{
			 glBegin(GL_LINES);
				glVertex2d(pos.x, pos.y);
				glVertex2d(nuevo_punto.x, nuevo_punto.y);
         glEnd();
		}
		pos=nuevo_punto;

	glFlush();
	glutSwapBuffers();

	}