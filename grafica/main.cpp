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

int x1=0,x2=0,y_1=3,y2=3;

void Inicio()
{
	glMatrixMode(GL_PROJECTION);
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(-20,20,-20,20);
}
void setPixel(GLint x,GLint y){
	glColor3f(0.0,1.0,0.0);
	glPointSize(6);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
void incremental_basico(GLint x0,GLint y0, GLint xf, GLint yf){
	int x=0,y=0,valor;
	float a;
	a=(yf-y0)/(xf-x0);
	for(x=x0;x<=xf;x++){
		y=( y0 + a * ( x - x0) );
		setPixel(x,y);
	}
}
void punto_medio(GLint x0,GLint y0, GLint xf, GLint yf){
	int dx,dy,incE,incNE,d,x,y;

	dx=xf-x0;
	dy=yf-y0;
	d=2*dy-dx; /* Valor inicial de d*/
	incE=2*dy; /*Incremento de E*/
	incNE=2*(dy-dx);/* Incremento de NE*/
	x=x0;
	y=y0;
	setPixel(x,y);
	while (x < xf){
		if(d <=0){
			d=d+incE;
			x=x+1;
		}else{
		   d=d+incNE;
		   x=x+1;
		   y=y+1;
		}
		setPixel(x,y);
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
	GLint x0=-10,y0=-5,xf=10,yf=15;
	dibujar_linea(x0,y0,xf,yf);
	//incremental_basico( x0, y0,  xf,  yf);
	punto_medio( x0, y0,  xf,  yf);
	glFlush();
}


/**_________________________________**/

double calx=0.0,caly=0.0;
int radio=5,lados=3;

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


/**_________________________________**/

void Poligono_Regular(){
    int tam=lados+1;
	punto * pt =new punto[tam];
    vector<punto> vPunto;
	punto p;
	double i;
	int j;
    if (lados==3){
		for(i=90.0,j=0;i<360.0;i+=360/lados*1.0,j++){
			p.x=radio*cos((i*pi)/180);
			p.y=radio*sin((i*pi)/180);
			vPunto.push_back(p);
			pt[j]=p;
		}
		pt[j]=pt[0];
		for(int i=0;i<tam-1;i++){
            glColor3f(0.0,1.0,1.0);
			glBegin ( GL_LINES ) ;
            glVertex2f ( pt[i+1].x,pt[i+1].y) ;
            glVertex2f ( pt[i].x,pt[i].y) ;
			glEnd ( ) ;
		}
	}
	if(lados>3){
		for(i=0.0,j=0;i<360.0;i+=360/lados*1.0,j++){
			p.x=radio*cos((i*pi)/180);
			p.y=radio*sin((i*pi)/180);
			pt[j]=p;
		}
		pt[j]=pt[0];
		for(int i=0;i<tam-1;i++){
            glColor3f(0.0,1.0,1.0);
			glBegin ( GL_LINES ) ;
				glVertex2f ( pt[i].x,pt[i].y) ;
				glVertex2f ( pt[i+1].x,pt[i+1].y) ;

			glEnd ( ) ;
		}


	}
	glFlush();


}
int main ( int argc , char ** argv ){
    glutInit (&argc,argv ) ;
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB ) ;
    glutInitWindowPosition (200 , 100) ;
    glutInitWindowSize ( 600,600 ) ;
    glutCreateWindow ( " lineas " ) ;
    Inicio() ;
    //glutDisplayFunc (linea) ;
    //glutDisplayFunc (circunferencia) ;
    glutDisplayFunc (Poligono_Regular) ;
    glutMainLoop () ;
}

