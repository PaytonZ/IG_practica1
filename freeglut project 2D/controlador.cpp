#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "controlador.h"
#include <GL/freeglut.h>
#include <iostream>
#include "escena.h"


extern int WIDTH, HEIGHT;


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

	case 'g' : escena::getAVEInstance()->arbol_pitagoras->draw(); break;

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

<<<<<<< HEAD
	bool need_redisplay = true;

	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_UP)
		{
			escena *escena = escena::getAVEInstance();
		
			GLdouble escalaAncho= WIDTH / ( escena->getxRight() -escena->getxLeft() );

			GLdouble escalaAlto = HEIGHT / (escena->getyTop() - escena->getyBot()); 

			punto nuevo;
			nuevo.x=(x/escalaAncho) + escena->getxLeft();
			nuevo.y=(y/escalaAlto) + escena->getyBot();

			escena->arbol_pitagoras->addCuadradoInicial(nuevo,100);
			std::cout << escena->arbol_pitagoras->cuadradosFrontera.numElems();

		}

		break;
	}
	if (need_redisplay)
		{
			glutPostRedisplay();
	}

=======
	if (button=0)
	{
		GLdouble escalaAncho;
	}
>>>>>>> 5deea40d5f70b2a4e8c138d32bdf0b5006e81b70
}