/*#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
//#include <GL/glut.h>

#include <iostream>

#include "escena.h"

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH= 1000, HEIGHT= 500;

// Scene visible area size
GLdouble xLeft= 0.0, xRight= 500.0, yBot= 0.0, yTop= 250.0;

escena escena_principal = escena::getAVEInstance(xLeft,yBot,xRight,yTop);



//GLdouble xLeft= 0.0, xRight= 1280.0, yBot= 0.0, yTop= 1024.0;

// Scene variables
GLdouble xTriangle= 100.0, yTriangle= 100.0;
GLdouble triangleWidth= 100.0, triangleHeight= 50.0;


void intitGL(){

	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,1.0,0.0); 

	glPointSize(4.0);
	glLineWidth(2.0);

	// Viewport
    glViewport(0, 0, WIDTH, HEIGHT);
    
	// Model transformation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Scene Visible Area
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D(xLeft, xRight, yBot, yTop);

	
  std::cout << "xright:" <<  escena_principal.getxRight() << std::endl;
  std::cout <<  "xleft:" <<  escena_principal.getxLeft() << std::endl;
  std::cout << "ytop:" <<  escena_principal.getyTop() << std::endl;
  std::cout << "ybot:" <<  escena_principal.getyBot()<< std::endl;

	gluOrtho2D(escena_principal.getxLeft(), escena_principal.getxRight(), escena_principal.getyBot(), escena_principal.getyTop()); 
 }


void display(){

         
glClear( GL_COLOR_BUFFER_BIT );

  // Scene rendering
  glBegin ( GL_TRIANGLES ) ;
       glVertex2d( xTriangle, yTriangle );
       glVertex2d( xTriangle + triangleWidth, yTriangle );
       glVertex2d( xTriangle + triangleWidth, yTriangle + triangleHeight );
  glEnd () ;

  glFlush();
  glutSwapBuffers();

   
    
}







void key(unsigned char key, int x, int y){
 
  bool need_redisplay = true;

  switch (key) {
  case 27:  // Escape key 
    //continue_in_main_loop = false; // 
	glutLeaveMainLoop (); //Freeglut's sentence for stopping glut's main loop (*)
    break;

  case '+' :
    xTriangle += 10.0;
    break ;

  case '-' :
    xTriangle -= 10.0;
    break ;

  default:
    need_redisplay = false;
    break;
  }//switch

  if (need_redisplay)
    glutPostRedisplay();
}



int main(int argc, char *argv[]){

  std::cout<< "Starting ..." << std::endl;

  std::cout << "xright:" <<  escena_principal.getxRight() << std::endl;
  std::cout <<  "xleft:" <<  escena_principal.getxLeft() << std::endl;
  std::cout << "ytop:" <<  escena_principal.getyTop() << std::endl;
  std::cout << "ybot:" <<  escena_principal.getyBot()<< std::endl;

  int my_window; //my window's identifier

  //Initialization
  glutInitWindowSize(WIDTH, HEIGHT);
  glutInitWindowPosition (140, 140);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE );
  glutInit(&argc, argv);

  //Window construction
  my_window = glutCreateWindow( "IG Practica 1 - Pythagoras tree" );
    
  //Callback registration
  glutReshapeFunc(escena::resize);
  glutKeyboardFunc(key);
  glutDisplayFunc(display);

  //OpenGL basic setting
  intitGL();

  

  // Freeglut's main loop can be stopped executing (**)
  //while ( continue_in_main_loop )
  //  glutMainLoopEvent();

  // Classic glut's main loop can be stopped after X-closing the window,
  // using the following freeglut's setting (*)
  glutSetOption ( GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION ) ;
    
  // Classic glut's main loop can be stopped in freeglut using (*)
  glutMainLoop(); 
  
  // We would never reach this point using classic glut
  system("PAUSE"); 
   
  return 0;
}
*/