#include <windows.h>
#include <GL/glut.h>
#ifndef ELIPSE_H
#define ELIPSE_H


class Elipse{
    float radio_a;
    float radio_b;
    public:
        Elipse();
        Elipse(float a,float b){
            radio_a=a;
            radio_b=b;
        }

        void punto_medio_elipse();
};


void Elipse::punto_medio_elipse(){
    glClear(GL_COLOR_BUFFER_BIT);

    float x, y, p;
    float d1, d2;
    // Valores iniciales
    p = 0.2;
    radio_a = radio_a/p;
    radio_b = radio_b/p;
    x = 0.0;
    y = radio_b;

    d1 = radio_b*radio_b - radio_a*radio_a*radio_b + radio_a*radio_a / 4.0;

    glColor3f(0.18,0.67,0.65);  //color RGB = X/255
    glBegin(GL_POINTS); // Simetria de orden 4
    glVertex2f(x, y*p*p);   glVertex2f(x, -y*p*p);
    glVertex2f(-x, y*p*p);  glVertex2f(-x, -y*p*p);

    while((radio_a*radio_a*(y - 0.5)) > (radio_b*radio_b*(x + 1)))
    {// Region 1
        if (d1 < 0.0)
        {
            d1 = d1 + radio_b*radio_b*(2*x + 3);
            x += 1.0;
        }
        else
        {
            d1 = d1 + radio_b*radio_b*(2*x + 3) + radio_a*radio_a*(-2*y + 2);
            x += 1.0;
            y -= 1.0;
        }// end if
        glBegin(GL_POINTS); // Simetria de orden 4
        glVertex2f(x*p*p, y*p*p);   glVertex2f(x*p*p, -y*p*p);
        glVertex2f(-x*p*p, y*p*p);  glVertex2f(-x*p*p, -y*p*p);
    }// end while
    d2 = radio_b*radio_b*(x + 0.5)*(x + 0.5) + radio_a*radio_a*(y - 1)*(y - 1) - radio_a*radio_a*radio_b*radio_b;
    while(y > 0)
    {
        // Region 2
        if (d2 < 0)
        {
            d2 = d2 + radio_b*radio_b*(2*x + 2) + radio_a*radio_a*(-2*y + 3);
            x += 1.0;
            y -= 1.0;
        }
        else
        {
            d2 = d2 + radio_a*radio_a*(-2*y + 3);
            y -= 1.0;
        }// end if
        glBegin(GL_POINTS); // Simetria de orden 4
        glVertex2f(x*p*p, y*p*p);   glVertex2f(x*p*p, -y*p*p);
        glVertex2f(-x*p*p, y*p*p);  glVertex2f(-x*p*p, -y*p*p);
    }// end while
    glEnd();
    glFlush();
}
#endif // ELIPSE_H
