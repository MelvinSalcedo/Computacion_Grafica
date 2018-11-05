#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include <Linea.h>
#include<MousePosition.h>
#include <PintarPoligono.h>
#include <Transformaciones.h>
using namespace std;

PintarPoligono Pp;
Linea L;
MousePosition MP;
Transformaciones T;


int tam=500;
vector<pair<int,int>>V;
bool disparador=true;

float h,k,r,x,y;
void display(void){

     glColor3f (1.0, 0.0, 0.0);
     if(disparador==false){
        glClear (GL_COLOR_BUFFER_BIT);
        MP.mostrar_puntos();
        Pp.display_(MP.pares);
        glEnd();

     }
     if(disparador==true){
         L.ponerPixel((int)x,(int)y);
     }

     glFlush();
}
 void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,tam,0.0,tam);

 }

void mouse(int button, int state, int mousex, int mousey){
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        x = mousex/1.0;
        y = (tam-mousey)/1.0;
        cout<<x<<" "<<y<<endl;

        MP.pares.push_back(make_pair((float)x,(float)y));
    }

    else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
        disparador=false;
    }
    glutPostRedisplay();
}


void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'c':
             T.scalamiento(MP.pares,0.9,0.9);
        break;
        case 'f':
            T.scalamiento(MP.pares,1.1,1.1);
        break;

        case 'q':
            T.rotacion(MP.pares,0.05);
        break;

        case 'e':
            T.rotacion(MP.pares,-0.05);
        break;

        case 'w':
            T.desplazamiento(MP.pares,0,2);
            //glTranslatef(0.0f, 1.0f, 0.0f);
        break;

        case 's':
            T.desplazamiento(MP.pares,0,-2);
        break;

        case 'a':
            T.desplazamiento(MP.pares,-2,0);
        break;

        case 'd':
            T.desplazamiento(MP.pares,2,0);
        break;

        case 27:
            exit(0);
        break;
        }
    glutPostRedisplay();
}


int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(tam,tam);
    glutInitWindowPosition (300, 100);
    glutCreateWindow ("Circle : Scanline Filling Method ");
    glutDisplayFunc(display);
    init ();
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
