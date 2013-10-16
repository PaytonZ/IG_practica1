#include "Lista.h"
#include "cuadrado.h"
class arbol
{
public:
	arbol(void);
	~arbol(void);

	Lista<cuadrado> cuadradosArchivados;
	Lista<cuadrado> cuadradosFrontera;

	void pintaSiguienteNivel();

};

