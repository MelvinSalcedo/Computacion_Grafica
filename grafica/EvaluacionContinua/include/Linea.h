#ifndef LINEA_H
#define LINEA_H


class Linea
{
    public:

        void Algoritmo_incremental_basico(GLint x0,GLint y0, GLint xf, GLint yf);
        void Algoritmo_punto_medio(GLint x0,GLint y0, GLint xf, GLint yf);
        void linea();
        void dibujar(GLint x0,GLint y0, GLint xf, GLint yf);
        void dibujar_linea(GLint x0,GLint y0, GLint xf, GLint yf);
        void ponerPixel(GLint x,GLint y);
        Linea(){;}
        void bresenham(float x1, float y1, float x2, float y2);
        void puntoMedio(int X1, int Y1, int X2, int Y2) ;
};

void Linea::puntoMedio(int x1, int y1, int x2, int y2){
    if (x1 > x2)
    {
        puntoMedio(x2, y2, x1, y1);
        return;
    }

    int slope;
    int dx, dy, d, x, y;

    dx = x2 - x1;
    dy = y2 - y1;
    d = dx - 2 * dy;
    y = y1;

    if (dy < 0) {
        slope = -1;
        dy = -dy;
    }
    else {
        slope = 1;
    }
    for (x = x1; x < x2; x++) {
         ponerPixel(x,y);
        if (d <= 0) {
            d += 2 * dx - 2 * dy;
            y += slope;
        }
        else {
            d += -2 * dy;
        }

    }

}


void Linea::bresenham(float x1, float y1, float x2, float y2)
{
    // Find Delta
    float dx = x2-x1;
    float dy = y2-y1;

    // Find Signs
    int sx = (dx>=0) ? 1 : (-1);
    int sy = (dy>=0) ? 1 : (-1);

    // Get Initial Points
    float x = x1;
    float y = y1;

    // Flag to check if swapping happens
    int isSwaped = 0;

    // Swap if needed
    if(abs(dy) > abs(dx))
    {
        // swap dx and dy
        float tdx = dx;
        dx =dy;
        dy = tdx;

        isSwaped = 1;
    }

    // Decision parameter
    float p = 2*(abs(dy)) - abs(dx);

    //Print Initial Point
    ponerPixel(x,y);

    // Loop for dx times
    for(int i = 0; i<= abs(dx);i++)
    {
        // Depending on decision parameter
        if(p < 0)
        {
            if(isSwaped == 0){
                x = x + sx;
                ponerPixel(x,y);
            }
            else{
                y = y+sy;
                ponerPixel(x,y);
            }
            p = p + 2*abs(dy);
        }
        else
        {
            x = x+sx;
            y = y+sy;
            ponerPixel(x,y);
            p = p + 2*abs(dy) - 2*abs(dx);
        }
    }
}



void Linea::ponerPixel(GLint x,GLint y){
	glColor3f(0.0,1.0,0.0);
	glPointSize(3);
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
	//glClear(GL_COLOR_BUFFER_BIT);
	GLint x0=-5,y0=-5,xf=150,yf=150;
	dibujar_linea(x0,y0,xf,yf);
	//Algoritmo_incremental_basico( x0, y0,  xf,  yf);
	puntoMedio(x0, y0,  xf,  yf);
	//bresenham(x0, y0,  xf,  yf);
	//Algoritmo_punto_medio( x0, y0,  xf,  yf);
	glFlush();
}

void Linea::dibujar(GLint x0,GLint y0, GLint xf, GLint yf){
	//glClear(GL_COLOR_BUFFER_BIT);
	dibujar_linea(x0,y0,xf,yf);
	//Algoritmo_incremental_basico( x0, y0,  xf,  yf);
	//puntoMedio(x0, y0,  xf,  yf);
	bresenham(x0, y0,  xf,  yf);
	//Algoritmo_punto_medio( x0, y0,  xf,  yf);
	glFlush();
}
#endif // LINEA_H
