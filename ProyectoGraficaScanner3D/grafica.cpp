//g++ -std=c++11 grafica.cpp -o grafica -lGL -lGLU -lglut

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define GL_PI 3.1415f
static float orbitDegreeZ = 0.0f;
static float orbitDegreeX = 0.0f;
static float zoom = 1.0f;
static float alfa = 0.0f;
GLint i = 0;


struct punto_3d{
    float x;
    float y;
    float z;
};

int num_points;
float x, y, z;
std::vector<punto_3d> cloud_points;
//std::string filename = "points.dat";
std::string filename = "nube_puntos.txt";

void parsePoints(){
    std::ifstream ifile(filename);
    ifile >> num_points;

    cloud_points.resize(num_points);
    for(int i=0; i < num_points; i++){
        ifile >> x >> y >> z;
        punto_3d p;
        p.x = x;
        p.y = y;
        p.z = z;

        //std::cout <<"p = "<<num_points<<" "<<"x: "<< x<<" , "<<" y: "<<y<<" , "<<" z: "<<z<< std::endl;
        cloud_points[i] = p;
    }
    std::cout << "numero de puntos = " << cloud_points.size()<<endl;
}

void dibujar_punto(float a, float b, float c){
    glPointSize(1);
    glColor3f(0.6f,1,1);
    glBegin(GL_POINTS); 
        //glVertex3f(20,1,29);
        glVertex3f(a,b,c);
    glEnd();
}

void cloudPoints(){
    int tam_radio=1;
    for(int i = 0; i < cloud_points.size(); i++){
        dibujar_punto(cloud_points[i].x*tam_radio,
            cloud_points[i].y*tam_radio,cloud_points[i].z);
    }
}

/*_______________________________________________*/


void RenderScene(void){
    int j = 0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(-50.0 + orbitDegreeX, 1.0f, 0.0f, 0.0f);
    glRotatef(orbitDegreeZ, 0.0f,0.0f,1.0f);

    cloudPoints();
    glPopMatrix();
    glutSwapBuffers();
}


void ChangeSizeOrtho(int w, int h){
    //GLfloat nRange = 25.0f;
    //GLfloat nRange = 30.0f;
    GLfloat nRange = 300.0f ;
    // Prevent a divide by zero
    if(h == 0)
        h = 1;
    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);
    // Reset projection matrix stack
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Establish clipping volume (left, right, bottom, top, near, far)
    if (w <= h) 
        glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
    else 
        glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange);
  
    // Reset Model view matrix stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void SpecialKeys(int key, int x, int y) {
        if (key == GLUT_KEY_UP   ) {
            orbitDegreeX += 4.0f;
        }
        if (key == GLUT_KEY_DOWN ) {
            orbitDegreeX -= 4.0f;
        }
        
        if (key == GLUT_KEY_LEFT ) {
            orbitDegreeZ -= 4.0f;
        }
        if (key == GLUT_KEY_RIGHT) {
            orbitDegreeZ += 4.0f;
        }
        glutPostRedisplay();

}


/*_______________________________________________*/

int main(int argc, char **argv){
    glutInit(&argc, argv);
    //glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(640, 640);
    glutCreateWindow("GLUT Cube");
    glutReshapeFunc(ChangeSizeOrtho); // Parhuzamos vetites

    parsePoints();
    //glutDisplayFunc(display);
    glutSpecialFunc(SpecialKeys);
    //glutSpecialFunc(specialKeys);
    glutDisplayFunc(RenderScene);
    //glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}