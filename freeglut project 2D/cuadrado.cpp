#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>


#include <iostream>

#include "escena.h"
#include "controlador.h"
#include "lapiz.h"
#include "cuadrado.h"



void cuadrado::pintarCuadrado()
{
	//Sentido antihorario
	glBegin(GL_QUADS);

		glVertex2d(esquina_inferior_izquierda.x,esquina_inferior_izquierda.y);
		glVertex2d(esquina_inferior_derecha.x,esquina_inferior_derecha.y);
		glVertex2d(esquina_superior_derecha.x,esquina_superior_derecha.y);
		glVertex2d(esquina_superior_izquierda.x,esquina_superior_izquierda.y);

	glEnd();

}