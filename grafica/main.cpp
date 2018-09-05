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

/**_________________________________**/


int x1=0,x2=0,y_1=3,y2=3;

void ponerPixel(GLint x,GLint y){
	glColor3f(0.0,1.0,0.0);
	glPointSize(6);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
void Algoritmo_incremental_basico(GLint x0,GLint y0, GLint xf, GLint yf){
	int x=0,y=0,valor;
	float m;
	m=(yf-y0)/(xf-x0);
	for(x=x0;x<=xf;x++){
		y=( y0 + m * ( x - x0) );
		ponerPixel(x,y);
	}
}
void Algoritmo_punto_medio(GLint x0,GLint y0, GLint xf, GLint yf){
	int dx,dy,incE,incNE,d,x,y;

	dx=xf-x0;
	dy=yf-y0;
	d=2*dy-dx; /* Valor inicial de d*/
	incE=2*dy; /*Incremento de E*/
	incNE=2*(dy-dx);/* Incremento de NE*/
	x=x0;
	y=y0;
	ponerPixel(x,y);
	while (x < xf){
		if(d <=0){
			d=d+incE;
			x=x+1;
		}else{
		   d=d+incNE;
		   x=x+1;
		   y=y+1;
		}
		ponerPixel(x,y);
	}
}

void dibujar_linea(GLint x0,GLint y0, GLint xf, GLint yf){
	glBegin(GL_LINES);
	glColor3f(1.0,0.0,0.0);
	glVertex2i(x0,y0);
	glVertex2i(xf,yf);
	glEnd();
}

void linea(){
	glClear(GL_COLOR_BUFFER_BIT);
	GLint x0=-5,y0=0,xf=10,yf=15;
	dibujar_linea(x0,y0,xf,yf);
	//Algoritmo_incremental_basico( x0, y0,  xf,  yf);
	Algoritmo_punto_medio( x0, y0,  xf,  yf);
	glFlush();
}

void Inicio(){
	glMatrixMode(GL_PROJECTION);
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(-20,20,-20,20);
}


/**_________________________________**/

int main ( int argc , char ** argv ){
    glutInit (&argc,argv ) ;
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB ) ;
    glutInitWindowPosition (200 , 100) ;
    glutInitWindowSize ( 600,600 ) ;
    glutCreateWindow ( "Computacion Grafica" ) ;
    Inicio() ;
    glutDisplayFunc (linea) ;
    //glutDisplayFunc (Poligono_Regular) ;

    glutMainLoop () ;


}

