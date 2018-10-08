#ifndef PARABOLA_H
#define PARABOLA_H
#include <iostream>
using namespace std;

class Parabola
{
    public:
        Parabola(){;}
        void parabola_punto_medio();
        void ponerPixel_simetria(int,int);
};


void Parabola::parabola_punto_medio(){
    glClear(GL_COLOR_BUFFER_BIT);

    int x,y,p,gc;
    x=0;
    y=0;
    p=1;
    ponerPixel_simetria(x,y);
    while(x<=100){
        x=x+1;
        if(p>0){
            y=y+1;
            p=p-2*y-1;
        }
        else{
            p=p+1;
        }
        ponerPixel_simetria(x,y);
    }
    glEnd();
    glFlush();


}
void Parabola::ponerPixel_simetria(int x,int y){
    cout<<x<<" , "<<y<<endl;
	glColor3f(0.18,0.67,0.65);
	glPointSize(6);
	glBegin(GL_POINTS);
    glVertex2f(x, y);
    glVertex2f(x, -y);

}

#endif // PARABOLA_H
