
#include <math.h>

#include "punto.h"

punto& punto::operator = (const punto &p)
{
    if(this!=&p){ 
        this->x = p.x;
        this->y = p.y;
    }
    return *this;
}

GLdouble punto::distancia(punto p)
{
	return sqrt(pow((x - p.x),2.0)+
			pow((y - p.y),2.0));
}





bool punto ::estaCerca(punto p, GLdouble e)
{
    GLdouble a= pow(x-p.x,2);
    GLdouble b= pow(y-p.y,2);
    GLdouble c= sqrt(a+b);
    return (c<e);


}