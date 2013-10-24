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
		/*if (cuadradosFrontera.esVacia()) // crea el primer cuadrado.
		{
			cuadrado a (punto(100,20),50.00);
			a.creaCuadrado(0);
			a.setRed(0.5);
			a.setBlue(0.05);
			a.setGreen(0.35);
			cuadradosFrontera.ponDr(a);
			nivel=1;
		}
		else 
		{
			Lista<cuadrado>::Iterador it = cuadradosFrontera.principio();
			int i= 0;
			int numcuadrados= pow(2,nivel-1);
			while(i!=numcuadrados)
			{
				cuadrado frontera= it.elem();
				cuadradosFrontera.ponDr(frontera.dameCuadradoDerecho());
				cuadradosFrontera.ponDr(frontera.dameCuadradoIzquierdo());
				cuadradosArchivados.ponDr(cuadradosFrontera.primero());
				it.avanza();
				cuadradosFrontera.resto();
				i++;
			}
			nivel++;
		}*/
		if (cuadrados.esVacia())
		{
			cuadrado a (punto(100,20),50.00);
			a.creaCuadrado(0);
			a.setRed(0.5);
			a.setBlue(0.05);
			a.setGreen(0.35);
			Lista<cuadrado> lista = Lista<cuadrado>();
			lista.ponDr(a);
			cuadrados.ponDr(lista);
			nivel=1;
		}
		else
		{
			Lista<cuadrado> nuevaLista = Lista<cuadrado>();
			Lista<Lista<cuadrado>> :: Iterador it= cuadrados.principio();
			for (int i=0; i<cuadrados.numElems()-1;i++)
				it.avanza();
			Lista<cuadrado> asd = it.elem();
			Lista<cuadrado> :: Iterador at= asd.principio();
			while(at!=asd.final())
			{
				cuadrado frontera= at.elem();
				nuevaLista.ponDr(frontera.dameCuadradoDerecho());
				nuevaLista.ponDr(frontera.dameCuadradoIzquierdo());
				at.avanza();
			}
			nivel++;
			cuadrados.ponDr(nuevaLista);
		}


		
	}

	void arbol:: pintaCuadrados()
	{
		/*Lista<cuadrado>:: Iterador iter = cuadradosFrontera.principio();
		Lista<cuadrado>:: Iterador iter2= cuadradosArchivados.principio();
		while (iter!=cuadradosFrontera.final() || iter2!=cuadradosArchivados.final())
		{
			if (iter!=cuadradosFrontera.final() && iter2!=cuadradosArchivados.final())
			{
				iter.elem().pintarCuadrado();
				iter.avanza();
				iter2.elem().pintarCuadrado();
				iter2.avanza();
			}
			else if (iter!=cuadradosFrontera.final())
			{
				iter.elem().pintarCuadrado();
				iter.avanza();
			}
			else if (iter2!=cuadradosArchivados.final())
			{
				iter2.elem().pintarCuadrado();
				iter2.avanza();
			}
		}*/

		Lista<Lista<cuadrado>> :: Iterador it= cuadrados.principio();
		while(it!=cuadrados.final())
		{
			Lista<cuadrado> asd = it.elem();
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
		
		/* if(cuadradosFrontera.esVacia())
		{ lapiz l;
		
		 l.dir=225;
		 
		 l.moveTo(p,false);
		 l.forward((sqrt(2)*(tam/2.0))/2.0,false);
		 cuadrado a(l.pos,50.0);
		 a.creaCuadrado(0);
		 a.setRed(0.5);
		a.setBlue(0.05);
		a.setGreen(0.35);

		 cuadradosFrontera.ponDr(a);
		 nivel=1;
		 a.pintarCuadrado();

		 std::cout << cuadradosFrontera.numElems() << std::endl;
		  
		 }*/

		 if (cuadrados.esVacia())
		 {
			  lapiz l;
		
		 l.dir=225;
		 
		 l.moveTo(p,false);
		 l.forward((sqrt(2)*(tam/2.0))/2.0,false);
		 cuadrado a(l.pos,50.0);
		 a.creaCuadrado(0);
		 a.setRed(0.5);
		a.setBlue(0.05);
		a.setGreen(0.35);
		Lista<cuadrado> abc=Lista<cuadrado>();
		abc.ponDr(a);
		cuadrados.ponDr(abc);
		a.pintarCuadrado();

		 }



	 }