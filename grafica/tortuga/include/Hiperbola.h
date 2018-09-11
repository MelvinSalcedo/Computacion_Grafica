#ifndef HIPERBOLA_H
#define HIPERBOLA_H


class Hiperbola
{
    public:
        int wide=300, high=300;
        int winX=40, winY=40;


        Hiperbola();
        void DrawMyStuff();
        void hiperbola(void);

};


void Hiperbola::DrawMyStuff()
{
    double x,y;
    glColor3f(1.0, 1.0, 0.0);
    glBegin( GL_POINTS );
        for (x = -1; x <= 1; x += .001)
          { y =  4* x -  4* x * x ;
            glVertex3f(x, y, 0.0);
          }
   glEnd();
}

void Hiperbola::hiperbola(void)
{

   glClear(GL_COLOR_BUFFER_BIT);
   DrawMyStuff();
   glFlush();
}

#endif // HIPERBOLA_H
