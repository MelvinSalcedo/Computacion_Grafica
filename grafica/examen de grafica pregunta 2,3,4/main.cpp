#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <unistd.h>
#include "Linea3D.h"
#include "Parabola.h"
using namespace std;

double rotate_y=0;
double rotate_x=0;


void Inicio(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 4.0/3.0, 1, 40);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(4, 6, 5, 0, 0, 0, 0, 1, 0);

    /*glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-10,100,-10,40);*/

}

void Llamadas(){
  glClear(GL_COLOR_BUFFER_BIT);

    Linea3D a;
    a.linea3D_Bresenham(0,0,0,5,5,5);

    //Parabola a;
    //a.parabola_punto_medio();

  glBegin(GL_LINES);
    glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(100, 0, 0);
    glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 100, 0);
    glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 100);
  glEnd();

  glFlush();
}

void specialKeys( int key, int x, int y ) {
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;
  else if (key == GLUT_KEY_UP)
    rotate_x += 5;
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
  glutPostRedisplay();

}

int main ( int argc , char ** argv ){

    glutInit (&argc,argv ) ;
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB ) ;
    glutInitWindowPosition (200 , 100) ;
    glutInitWindowSize ( 600,600 ) ;
    glutCreateWindow ( "Computacion Grafica" ) ;
    Inicio() ;
    //glutKeyboardFunc(keyboard);
    glutDisplayFunc(Llamadas) ;
    glutSpecialFunc(specialKeys);
    glutMainLoop () ;


}
