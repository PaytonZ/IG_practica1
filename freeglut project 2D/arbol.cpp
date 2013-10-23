#include "arbol.h"
#include "lapiz.h"
#include "Lista.h"
#include "cuadrado.h"
#include <iostream>


void arbol::pintaSiguienteNivel()
{



}


void arbol::addCuadradoFrontera(cuadrado c)
{
	cuadradosFrontera.ponDr(c);
	

}
	void arbol::addCuadradoArchivados(cuadrado c)
{

}

	void arbol:: draw()
	{
		if (cuadrados.esVacia())
		{
			cuadrado a (punto(100,20),50.00);
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
				nuevaLista->ponDr(frontera.dameCuadradoDerecho());
				nuevaLista->ponDr(frontera.dameCuadradoIzquierdo());
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

	 void arbol::addCuadradoInicial(punto p ,GLdouble tam)
	 {
		
		
		 if (cuadrados.esVacia())
		 {
				lapiz l;		
				l.dir=225;
		 		l.moveTo(p,false);
				l.forward((sqrt(2)*(tam/2.0))/2.0,false);
				//l.forward(tam/2.0,false);
				//l.dir=180;
				//l.forward(tam/2,false);
				cuadrado a(l.pos,tam);
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


	  