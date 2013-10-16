#include "punto.h"
class lapiz
{
public:
	
	lapiz(){
	pos.x=0.0;
	pos.y=0.0;
	dir=0.0;
	}
	lapiz(punto p,GLdouble d): pos(p), dir(d) {}
	punto pos; 
	GLdouble dir;
	void moveTo(punto,bool);
	void turnTo(GLdouble);
	void forward(GLdouble,bool);

	




};

