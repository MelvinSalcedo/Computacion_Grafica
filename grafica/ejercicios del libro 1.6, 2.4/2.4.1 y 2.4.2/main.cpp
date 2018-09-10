#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <unistd.h>

#define pi 3.1416
#define fin 40
#include <vector>

using namespace std;


/**_________________________________**/

double calx=0.0,caly=0.0;
int radio=5,num_lados=100;

class punto{
public:
	double x;
	double y;
	punto(){};
	punto(double x_,double y_){
        x=x_;
        y=y_;
	}
};


void Poligono_Regular(){
    int tam=num_lados+1;
    vector<punto> vPunto;
	punto _p;
	double i;
    if (num_lados==3){
		for(i=90;i<360;i+=360/num_lados){
            //cout<<"i: "<<i<<endl;
			_p.x=radio*cos((i*pi)/180);
			_p.y=radio*sin((i*pi)/180);
			vPunto.push_back(_p);
		}
		vPunto.push_back(vPunto[0]);

		for(int i=0;i<tam-1;i++){
            glColor3f(0.0,1.0,1.0);
			glBegin ( GL_LINES ) ;
            glVertex2f ( vPunto[i+1].x,vPunto[i+1].y) ;
            glVertex2f ( vPunto[i].x,vPunto[i].y) ;
			glEnd ( ) ;
		}
	}
	if(num_lados>3){
		for(i=0; i<360; i+=360.0/num_lados){
            //cout<<"i: "<<i<<endl;
			_p.x=radio*cos((i*pi)/180);
			_p.y=radio*sin((i*pi)/180);
			vPunto.push_back(_p);
		}
		vPunto.push_back(vPunto[0]);
		for(int i=0;i<tam-1;i++){
            glColor3f(0.0,1.0,1.0);
			glBegin ( GL_LINES ) ;
            glVertex2f ( vPunto[i+1].x,vPunto[i+1].y) ;
            glVertex2f ( vPunto[i].x,vPunto[i].y) ;
			glEnd ( ) ;
		}
	}
	glFlush();

}


void Inicio(){
	glMatrixMode(GL_PROJECTION);
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(-20,20,-20,20);
}



int main ( int argc , char ** argv ){
    glutInit (&argc,argv ) ;
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB ) ;
    glutInitWindowPosition (200 , 100) ;
    glutInitWindowSize ( 600,600 ) ;
    glutCreateWindow ( "Computacion Grafica" ) ;
    Inicio() ;
    glutDisplayFunc (Poligono_Regular) ;

    glutMainLoop () ;


}
