#ifndef TORTUGA_H
#define TORTUGA_H
#define WIDTH 1024
#define HEIGHT 800


class Tortuga{
    public:
        Tortuga(){;}
        void circulo(int r,int x,int y);
        void dibujar_tortuga();
        void mover_tortuga(int);
};

void Tortuga::circulo(int r,int x,int y){
    float x1=x,y1=y,x2,y2;
    float angulo;
    double radio=r;
    glColor3f(1.0,1.0,1.0);

    for (angulo=1.0f;angulo<361.0f;angulo+=0.1){
        x2 = x1+sin(angulo)*radio;
        y2 = y1+cos(angulo)*radio;
        glPointSize(5);
        glBegin(GL_POINTS);
        glVertex2f(x2,y2);

    }
    glEnd();
}

void Tortuga::mover_tortuga(int x){
}

void Tortuga::dibujar_tortuga(){
    glClear(GL_COLOR_BUFFER_BIT);

    circulo(2,0,4);
    circulo(2,-6,-0);
    circulo(2,6,-0);
    circulo(7,0,-5);
    circulo(2,-6,-10);
    circulo(2,6,-10);

    glEnd();
    glFlush();
}
#endif // TORTUGA_H
