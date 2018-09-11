#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <unistd.h>

#include "PoligonoRegular.h"
#include "Elipse.h"
#include "Linea.h"
#include "Hiperbola.h"
#include "Tortuga.h"
#include "Circunferencia.h"
using namespace std;

void Inicio(){
	glMatrixMode(GL_PROJECTION);
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(-20,20,-20,20);
}

void Llamadas(){
    Tortuga t;
    t.dibujar_tortuga();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'h':
            cout<<"pres h "<<endl;
        break;
        case 'c':
        if (glIsEnabled(GL_CULL_FACE))
            glDisable(GL_CULL_FACE);
        else
            glEnable(GL_CULL_FACE);
        break;

        case 'q':
            glRotatef(1.0,0,0.,1.);
        break;
        case 'e':
            glRotatef(1.0,0.,0.,-1.);
        break;

        case 'w':
            glTranslatef(0.0f, 1.0f, 0.0f);
        break;

        case 's':
            glTranslatef(0.0f, -1.0f, 0.0f);
        break;

        case 'a':
            glTranslatef(-1.0f, 0.0f, 0.0f);
        break;

        case 'd':
            glTranslatef(1.0f, 0.0f, 0.0f);
        break;


        case '1':
        case 27:
            exit(0);
        break;
        }
    glutPostRedisplay();
}


int main ( int argc , char ** argv ){

    glutInit (&argc,argv ) ;
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB ) ;
    glutInitWindowPosition (200 , 100) ;
    glutInitWindowSize ( 600,600 ) ;
    glutCreateWindow ( "Computacion Grafica" ) ;
    Inicio() ;
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(Llamadas) ;
    glutMainLoop () ;


}
