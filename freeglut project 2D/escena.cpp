#include "escena.h"
#include <iostream>

extern int WIDTH, HEIGHT;


escena escena::AVE;

GLdouble escena::getxRight() const{
	return xRight;
}
void escena::setxRight(GLdouble new_xRight){
	xRight= new_xRight;
}

GLdouble escena::getyTop() const{
	return yTop;

}

void escena::setyTop(GLdouble new_ytop){
	yTop= new_ytop;
}


GLdouble escena::getxLeft() const{
	return xLeft;
}

void escena::setxLeft(GLdouble new_xleft){

	xLeft=new_xleft;

}

GLdouble escena::getyBot() const{
	return yBot;
}

void escena::setyBot(GLdouble new_ybot )
{
	yBot=new_ybot;
}

punto escena::getCentro()
{
	punto p= punto(GLdouble(1) , GLdouble (2));

	return p;
}


void __cdecl  escena::resize(int newWidth, int newHeight){

	//Resize Viewport
	WIDTH= newWidth;
	HEIGHT= newHeight;


	GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
	glViewport ( 0, 0, WIDTH, HEIGHT ) ;

	//Resize Scene Visible Area 
	//Se actualiza el área visible de la escena
	//para que su ratio coincida con ratioViewPort

	GLdouble SVAWidth= getAVEInstance().getxRight()- getAVEInstance().getxLeft();

	GLdouble SVAHeight= getAVEInstance().getyTop()-getAVEInstance().getyBot();
	GLdouble SVARatio= SVAWidth/SVAHeight;
	if (SVARatio >= RatioViewPort) {
		// Increase SVAHeight
		GLdouble newHeight= SVAWidth/RatioViewPort;
		GLdouble yMiddle= ( getAVEInstance().getyBot()+getAVEInstance().getyTop() )/2.0;
		getAVEInstance().setyTop(( yMiddle + newHeight)/2.0);
		getAVEInstance().setyBot ((yMiddle - newHeight)/2.0);
	}
	else {
		//Increase SVAWidth
		GLdouble newWidth= SVAHeight*RatioViewPort;
		GLdouble xMiddle= ((getAVEInstance().getxLeft()+getAVEInstance().getxRight() )/2.0);
		getAVEInstance().setxRight((xMiddle + newWidth)/2.0);
		getAVEInstance().setxLeft(( xMiddle - newWidth)/2.0);
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	getAVEInstance().setxRight(200.0);



	gluOrtho2D(getAVEInstance().getxLeft(),getAVEInstance().getxRight(), getAVEInstance().getyBot(), getAVEInstance().getyTop());



}


escena escena::getAVEInstance()
{       

	return AVE;
}

escena escena::getAVEInstance(GLdouble new_xleft, GLdouble new_yBot , GLdouble new_xright, GLdouble new_yTop)
{       

	return AVE=escena(new_xleft,new_yBot, new_xright, new_yTop);

}

