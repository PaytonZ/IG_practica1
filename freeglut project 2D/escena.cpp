#include "escena.h"



GLdouble escena::xRight() const{
	return xRight;
}
	void escena::xRight(GLdouble new_xRight){
		xRight= new_xRight;
	}

	GLdouble escena::getyRight() const{}
	void escena::setyRight(GLdouble){}

	GLdouble escena::getxLeft() const{
	
	}
	void escena::getxLeft(GLdouble new_xleft){
	
		new_xleft
	
	}

	GLdouble escena::getyLeft() const{}

	escena::setyLeft(GLdouble )
	{

	}
	
	 punto escena::getCentro()
	 {

	 }

/*
void escena::resize(int newWidth, int newHeight){
  //Resize Viewport
  WIDTH= newWidth;
  HEIGHT= newHeight;
  GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
  glViewport ( 0, 0, WIDTH, HEIGHT ) ;
  
  //Resize Scene Visible Area 
  //Se actualiza el área visible de la escena
  //para que su ratio coincida con ratioViewPort
  GLdouble SVAWidth= xRight-xLeft;
  GLdouble SVAHeight= yTop-yBot;
  GLdouble SVARatio= SVAWidth/SVAHeight;
  if (SVARatio >= RatioViewPort) {
	 // Increase SVAHeight
     GLdouble newHeight= SVAWidth/RatioViewPort;
	 GLdouble yMiddle= ( yBot+yTop )/2.0;
     yTop= yMiddle + newHeight/2.0;
     yBot= yMiddle - newHeight/2.0;
     }
  else {
     //Increase SVAWidth
     GLdouble newWidth= SVAHeight*RatioViewPort;
     GLdouble xMiddle= ( xLeft+xRight )/2.0;
	 xRight= xMiddle + newWidth/2.0;
     xLeft=  xMiddle - newWidth/2.0;
  }

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(xLeft, xRight, yBot, yTop);
}
*/