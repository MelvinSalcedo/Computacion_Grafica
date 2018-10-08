#include <windows.h>
#include <GL/glut.h>
#ifndef CIRCUNFERENCIA_H
#define CIRCUNFERENCIA_H


class Circunferencia
{
    public:
        float xc, yc, r;
        Circunferencia(int _r){
            r=_r;
        }
        void cicunferencia();
        void C();
        void ponerPixel(int,int);

};

void Circunferencia::cicunferencia(){

   glClear(GL_COLOR_BUFFER_BIT);

    float x, y, p;
    float d;
    p = 0.01;
    // Valores iniciales
    x = 0.0;
    y = r/p;
    d = 5.0/4.0 - r;
    //d = 1.0 - r;    //usando aritmetica entera

    glColor3f(0.18,0.67,0.65);  //color RGB = X/255
    glBegin(GL_POINTS);
    glVertex2f(x, y*p);   glVertex2f(x, -y*p);
    glVertex2f(-x, y*p);  glVertex2f(-x, -y*p);
    glVertex2f(y*p, x);   glVertex2f(y, -x*p);
    glVertex2f(-y*p, x);  glVertex2f(-y, -x*p);
    while (y > x)
    {
        if (d < 0.0)
        {// Selecione E
            d = d + 2 * x + 3;
        }
        else
        {// Selecione SE
            d = d + 2 * (x - y) + 5;
            y -= 1.0;
        }/*end if*/
        x += 1.0;

        glColor3f(0.18,0.67,0.65);  //color RGB = X/255
        glBegin(GL_POINTS);
        glVertex2f(x*p, y*p);   glVertex2f(x*p, -y*p);

        glVertex2f(-x*p, y*p);  glVertex2f(-x*p, -y*p);
        glVertex2f(y*p, x*p);   glVertex2f(y*p, -x*p);
        glVertex2f(-y*p, x*p);  glVertex2f(-y*p, -x*p);
    }/* end while */
    glEnd();
    glFlush();
}

void Circunferencia::ponerPixel(int x,int y){
	glColor3f(0.0,1.0,0.0);
	glPointSize(6);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void Circunferencia::C(){
	glClear(GL_COLOR_BUFFER_BIT);
	cicunferencia();
	glFlush();
}

#endif // CIRCUNFERENCIA_H
