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
#include "Circunferencia.h"
using namespace std;

void Inicio(){
	glMatrixMode(GL_PROJECTION);
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(-20,20,-20,20);
}
void Llamadas(){
    //PoligonoRegular pr(4,5);
    //pr.Poligono_Regular();

    //Linea l;
    //l.linea();

    //Hiperbola h;
    //h.hiperbola();

    //Elipse e(50,40);
    //e.punto_medio_elipse();

    Circunferencia c(2);
    c.cicunferencia();
    //c.circunferencia_incremental();
}

int main ( int argc , char ** argv ){

    glutInit (&argc,argv ) ;
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB ) ;
    glutInitWindowPosition (200 , 100) ;
    glutInitWindowSize ( 600,600 ) ;
    glutCreateWindow ( "Computacion Grafica" ) ;
    Inicio() ;
    glutDisplayFunc(Llamadas) ;
    glutMainLoop () ;


}
