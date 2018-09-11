#ifndef LINEA_H
#define LINEA_H


class Linea
{
    public:

        double calx=0.0,caly=0.0;
        int x1=0,x2=0,y_1=3,y2=3;

        void Algoritmo_incremental_basico(GLint x0,GLint y0, GLint xf, GLint yf);
        void Algoritmo_punto_medio(GLint x0,GLint y0, GLint xf, GLint yf);
        void linea();
        void dibujar_linea(GLint x0,GLint y0, GLint xf, GLint yf);
        void ponerPixel(GLint x,GLint y);
        Linea(){;}
};

void Linea::ponerPixel(GLint x,GLint y){
	glColor3f(0.0,1.0,0.0);
	glPointSize(6);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void Linea:: Algoritmo_incremental_basico(GLint x0,GLint y0, GLint xf, GLint yf){
	int x=0,y=0,valor;
	float m;
	m=(yf-y0)/(xf-x0);
	for(x=x0;x<=xf;x++){
		y=( y0 + m * ( x - x0) );
		ponerPixel(x,y);
	}
}
void Linea:: Algoritmo_punto_medio(GLint x0,GLint y0, GLint xf, GLint yf){
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

void Linea::dibujar_linea(GLint x0,GLint y0, GLint xf, GLint yf){
	glBegin(GL_LINES);
	glColor3f(1.0,0.0,0.0);
	glVertex2i(x0,y0);
	glVertex2i(xf,yf);
	glEnd();
}

void Linea::linea(){
	glClear(GL_COLOR_BUFFER_BIT);
	GLint x0=-5,y0=0,xf=10,yf=15;
	dibujar_linea(x0,y0,xf,yf);
	//Algoritmo_incremental_basico( x0, y0,  xf,  yf);
	Algoritmo_punto_medio( x0, y0,  xf,  yf);
	glFlush();
}


#endif // LINEA_H
