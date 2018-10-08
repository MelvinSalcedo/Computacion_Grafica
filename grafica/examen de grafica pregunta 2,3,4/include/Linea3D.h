#ifndef LINEA3D_H
#define LINEA3D_H
#include <windows.h>
#include <iostream>
#include <algorithm>
using namespace std;

class Linea3D
{
    public:
        Linea3D(){;}
        void linea3D_Bresenham(int x0, int y0, int z0, int x1, int y1, int z1);
        void dibujar_puntos(int x,int y,int z);
        int max(int,int,int);

};
 int Linea3D::max(int a,int b,int c){
    if(a>b && a> c){return a;}
    else if(b>a && b> c){return b;}
    else if(c>a && c> a){return c;}
    else{
        return a;
    }
 }
void Linea3D::linea3D_Bresenham(int x0, int y0, int z0, int x1, int y1, int z1){
    glClear(GL_COLOR_BUFFER_BIT);
    int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
    int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
    int dz = abs(z1-z0), sz = z0<z1 ? 1 : -1;
    int dm = max(dx,dy,dz), i = dm; /* maximum difference */
    x1 = y1 = z1 = dm/2; /* error offset */

    for(int c=0;c<100;c++) {  /* loop */
        dibujar_puntos(x0,y0,z0);
        if (i-- == 0) break;
        x1 -= dx; if (x1 < 0) { x1 += dm; x0 += sx; }
        y1 -= dy; if (y1 < 0) { y1 += dm; y0 += sy; }
        z1 -= dz; if (z1 < 0) { z1 += dm; z0 += sz; }
    }
    glEnd();
    glFlush();

}

void Linea3D::dibujar_puntos(int x,int y,int z){
    cout<<"x= "<<x<<" "<<"y= "<<y<<" "<<"z= "<<z<<endl;
    glColor3f(0.18,0.67,0.65);
	glPointSize(18);
    glBegin(GL_POINTS);        // Select points as the primitive
      glVertex3f(x, y, z);    // Specify a point
    //glEnd();
}
#endif // LINEA3D_H
