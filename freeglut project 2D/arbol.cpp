/********************************************************************************
*																				*
*		Practica 1 IG - Pythagoras tree											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#include "arbol.h"
#include "lapiz.h"
#include "Lista.h"
#include "cuadrado.h"
#include <iostream>
#include "escena.h"

extern GLdouble TAM_CUADRADO;
extern GLdouble EPSILON;
extern GLdouble ANGULO;


void arbol:: draw()
{
	if (cuadrados.esVacia())
	{

		cuadrado a (punto(100,20),TAM_CUADRADO);
		a.creaCuadrado(0);
		a.setRed(0.5);
		a.setBlue(0.05);
		a.setGreen(0.35);
		Lista<cuadrado> * lista = new Lista<cuadrado>();
		lista->ponDr(a);
		cuadrados.ponDr(lista);
		nivel=1;
	}
	else
	{

		Lista<cuadrado> * nuevaLista = new Lista<cuadrado>();
		Lista<Lista<cuadrado>*> :: Iterador it= cuadrados.principio();
		for (int i=0; i<cuadrados.numElems()-1;i++)
			it.avanza();
		Lista<cuadrado> asd = *it.elem();
		Lista<cuadrado> :: Iterador at= asd.principio();
		while(at!=asd.final())
		{
			cuadrado frontera= at.elem();
			nuevaLista->ponDr(frontera.dameCuadradoDerecho(ANGULO));
			nuevaLista->ponDr(frontera.dameCuadradoIzquierdo(ANGULO));
			at.avanza();
		}
		nivel++;
		cuadrados.ponDr(nuevaLista);
	}



}

void arbol:: quitaUnNivel()
{
	if (!cuadrados.esVacia())
	{
		cuadrados.inicio();
		nivel--;
	}

}

void arbol:: pintaCuadrados()
{

	Lista<Lista<cuadrado>*> :: Iterador it= cuadrados.principio();
	while(it!=cuadrados.final())
	{
		Lista<cuadrado> asd = *it.elem();
		Lista<cuadrado> :: Iterador at = asd.principio();
		while(at!=asd.final())
		{
			at.elem().pintarCuadrado();
			at.avanza();
		}
		it.avanza();
	}

}

void arbol::addCuadradoInicial(punto p )
{


	if (cuadrados.esVacia())
	{
		//GLdouble tam;
		//std::cout<< "Introduce el tamaño que quieres para el primer cuadrado: ";
		//std::cin>>tam;
		lapiz l;		
		l.dir=270;
		l.moveTo(p,false);

		l.forward(TAM_CUADRADO/2.0,false);
		l.dir=180;
		l.forward(TAM_CUADRADO/2.0,false);
		cuadrado a(l.pos,TAM_CUADRADO);
		a.creaCuadrado(0);
		a.setRed(0.5);
		a.setBlue(0.05);
		a.setGreen(0.35);
		Lista<cuadrado> *abc=new Lista<cuadrado>();
		abc->ponDr(a);
		cuadrados.ponDr(abc);
		a.pintarCuadrado();

	}

}

void arbol :: selecion(punto a)
{
	bool esta=false;
	Lista<Lista<cuadrado>*>:: Iterador it=cuadrados.principio();

	while (it!=cuadrados.final() && !esta)
	{
		Lista<cuadrado>* asd= it.elem();
		Lista<cuadrado> :: Iterador at=(*asd).principio();
		while (at!=(*asd).final() && !esta)
		{
			cuadrado abc=at.elem();
			GLdouble epsilon = abs(escena::getAVEInstance()->getxRight() - escena::getAVEInstance()->getxLeft())*0.02;

			if(abc.selecionado(a,epsilon))
			{
				std::cout << "Encontrado cuadrado! " << std::endl;
				esta=true;
				(*asd).borra(at);
				(*asd).ponDr(abc);
			}
			at.avanza();
		}
		it.avanza();
	}
	if (!esta)
		std::cout << "No se encontro nada con ese epsion" << std::endl;

}


