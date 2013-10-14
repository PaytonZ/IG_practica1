#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "controlador.h"
#include <GL/freeglut.h>



void controlador::key(unsigned char key, int x, int y){
 
  bool need_redisplay = true;

  switch (key) {
  case 27:  // Escape key 
    //continue_in_main_loop = false; // 
	glutLeaveMainLoop (); //Freeglut's sentence for stopping glut's main loop (*)
    break;

  case '+' :
    
    break ;

  case '-' :
  
    break ;

  default:
    need_redisplay = false;
    break;
  }//switch

  if (need_redisplay)
    glutPostRedisplay();
}

