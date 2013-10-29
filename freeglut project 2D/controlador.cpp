
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "controlador.h"
#include <GL/freeglut.h>
#include <iostream>
#include "escena.h"


extern int WIDTH, HEIGHT;
extern GLdouble TAM_CUADRADO;
extern GLdouble EPSILON;
extern GLdouble ANGULO;

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

	case 'h' : escena::getAVEInstance()->arbol_pitagoras->quitaUnNivel(); break;

	case 'a' : std::cout << "Introduce el angulo de anidamiento : " << std::endl;

				std::cin >> ANGULO; break;
	case 'e': do{std::cout << "Introduce epsilon de busqueda deseado : " << std::endl;

				std::cin >> EPSILON;
				}
				while (EPSILON<=0); break;
	case 't': 
		do{

			std::cout << "Introduce tam del cuadrado inicial : " << std::endl;

			std::cin >> TAM_CUADRADO;
			}
			while (TAM_CUADRADO<=0);break;

	case 'o' :
		escena::getAVEInstance()->escalacionProgresivo(1.3);
		 break;

	case 'p' : 
		escena::getAVEInstance()->escalacionProgresivo(0.7);
		break;

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
		escena::getAVEInstance()->translacionX(+10.0);
		break;
	case GLUT_KEY_UP :
		escena::getAVEInstance()->translacionY(-10.0);

		break;
	case GLUT_KEY_RIGHT :
		escena::getAVEInstance()->translacionX(-10.0);

		break;
	case GLUT_KEY_DOWN :
		escena::getAVEInstance()->translacionY(+10.0);
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

	bool need_redisplay = true;

	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_UP)
		{
			if(escena::getAVEInstance()->arbol_pitagoras->cuadrados.esVacia())
				escena::getAVEInstance()->arbol_pitagoras->addCuadradoInicial(escena::getAVEInstance()->dePuertodeVistaaAVE(x,y));
			else
			{
				escena::getAVEInstance()->arbol_pitagoras->selecion(escena::getAVEInstance()->dePuertodeVistaaAVE(x,y));
			}
		
		}

		break;
	}
	if (need_redisplay)
		{
			glutPostRedisplay();
	}

}