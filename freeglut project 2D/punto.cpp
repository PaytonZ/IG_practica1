

#include "punto.h"

punto& punto::operator = (const punto &p)
{
    if(this!=&p){ 
        this->x = p.x;
        this->y = p.y;
    }
    return *this;
}

