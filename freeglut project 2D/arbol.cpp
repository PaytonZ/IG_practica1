#include "arbol.h"
#include "lapiz.h"
#include "Lista.h"
#include "cuadrado.h"
#include <iostream>


void arbol::pintaSiguienteNivel()
{

	glClear( GL_COLOR_BUFFER_BIT );


	Lista<cuadrado> fronteraAux;
	

	Lista<cuadrado>::Iterador it = cuadradosFrontera.principio();
	lapiz l;
	
	while(it != cuadradosFrontera.final())
	{
		std::cout << "Entrando Bucle pintado cuadrados!" << std::endl;
		cuadrado frontera= it.elem();

		
			
		cuadrado izq, der;
		
		GLdouble tam_cuadrado = sqrt(pow((frontera.esquina_inferior_izquierda.x - frontera.esquina_inferior_derecha.x),2.0)+
			pow((frontera.esquina_inferior_izquierda.y - frontera.esquina_inferior_derecha.y),2.0));
		tam_cuadrado=tam_cuadrado*1/2*sqrt(2);

		
		izq.esquina_inferior_derecha=frontera.esquina_superior_izquierda;

		l.moveTo(frontera.esquina_superior_izquierda,false);

		l.turnTo(135);
		l.forward(tam_cuadrado,false);

		izq.esquina_inferior_izquierda=l.pos;

		l.turnTo(-90);
		l.forward(tam_cuadrado,false);

		izq.esquina_superior_izquierda=l.pos;

		l.turnTo(-90);
		l.forward(tam_cuadrado,false);
		
		izq.esquina_superior_derecha=l.pos;

		l.dir=0.0;
		
		der.esquina_inferior_derecha=frontera.esquina_superior_derecha;

		l.moveTo(frontera.esquina_superior_derecha,false);

		l.turnTo(135);
		l.forward(tam_cuadrado,false);

		der.esquina_inferior_izquierda=l.pos;

		l.turnTo(-90);
		l.forward(tam_cuadrado,false);

		der.esquina_superior_izquierda=l.pos;

		l.turnTo(-90);
		l.forward(tam_cuadrado,false);
		
		der.esquina_superior_derecha=l.pos;

		izq.pintarCuadrado();
		der.pintarCuadrado();

		fronteraAux.ponDr(izq);
		fronteraAux.ponDr(der);

		cuadradosArchivados.ponDr(frontera);
		
		it=cuadradosFrontera.borra(it);
		it.avanza();
	}
	cuadradosFrontera=fronteraAux;
	std::cout << "asddfffff!";
	std::cout << cuadradosFrontera.numElems();

	glFlush();
	glutSwapBuffers();



}
void arbol::addCuadradoFrontera(cuadrado c)
{
	cuadradosFrontera.ponDr(c);
	

}
	void arbol::addCuadradoArchivados(cuadrado c)
{

}