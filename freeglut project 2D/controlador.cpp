#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "controlador.h"
#include <GL/freeglut.h>
#include <iostream>
#include "escena.h"



void controlador::key(unsigned char key, int x, int y){

	bool need_redisplay = true;

	switch (key) {
	case 27:  // Escape key 
		//continue_in_main_loop = false; // 
		glutLeaveMainLoop (); //Freeglut's sentence for stopping glut's main loop (*)
		break;

	case '+' :
		escena::getAVEInstance()->escalacion(1.1);
		break ;

	case '-' :
		escena::getAVEInstance()->escalacion(0.9);
		break ;

	case 'g' : escena::getAVEInstance()->arbol_pitagoras.draw(); break;

	default:
		need_redisplay = false;
		break;
	}//switch

	if (need_redisplay)
		{
			glutPostRedisplay();
	}
}

void controlador::key(int key, int x, int y){

	bool need_redisplay = true;

	switch (key) {

	case GLUT_KEY_LEFT:
		escena::getAVEInstance()->translacionX(10.0);
		break;
	case GLUT_KEY_UP :
		escena::getAVEInstance()->translacionY(-10.0);

		break;
	case GLUT_KEY_RIGHT :
		escena::getAVEInstance()->translacionX(-10.0);

		break;
	case GLUT_KEY_DOWN :
		escena::getAVEInstance()->translacionY(10.0);
		break;		

	default:
		need_redisplay = false;
		break;
	}//switch

	if (need_redisplay)
		glutPostRedisplay();
}

void controlador:: key(int button, int state, int x, int y)
{

	if (button=0)
	{
		GLdouble escalaAncho;
	}
}