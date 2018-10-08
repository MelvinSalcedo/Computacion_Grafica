#ifndef EJERCICIO2_H
#define EJERCICIO2_H
#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

class Ejercicio2
{
    public:
        Ejercicio2(){;}
        GLdouble mModel[16];
        float rotar_x=0.0;
        float rotar_y=0.0;
        float rotar_z=0.0;

        double *A=new double[4];
        double *B=new double[4];
        double *C=new double[4];

        double **transformacion=new double*[4];
        double **Desplazamiento=new double*[4];


        void iniciar();
        double * mvmult(double **mat,int sizeMat ,double *vec,int sizeVec);
        void dibujar_Figura(double *_A,double *_B, double *_C,int color);
        void dibujar_puntos(double *array);
        void llamada();
};

void Ejercicio2::llamada(){
    glPushMatrix();
		glRotatef( rotar_x, 1.0, 0.0, 0.0 );
		glRotatef( rotar_y, 0.0, 1.0, 0.0 );
		glRotatef( rotar_z, 0.0, 0.0, 1.0 );


		glClear(GL_COLOR_BUFFER_BIT);

	 	//Graficamos los puntos A,B y C originales
		dibujar_Figura(A,B,C,5);

		//Movemos los puntos al origen, para eso multiplicamos los puntos por la matriz de traslación
		double *despA = mvmult(Desplazamiento,4,A,4);
		double *despB = mvmult(Desplazamiento,4,B,4);
		double *despC = mvmult(Desplazamiento,4,C,4);

		//Hacemos las rotaciones multiplicando a nuestros puntos con la mtriz obtenida a partir de los vectores unitarios
		double *tranA = mvmult(transformacion,4,despA,4);
		double *tranB = mvmult(transformacion,4,despB,4);
		double *tranC =	mvmult(transformacion,4,despC,4);

		//Graficamos los nuevos puntos A' B' C'
		dibujar_Figura( tranA,tranB,tranC,0);

    glPopMatrix();
    glFlush();
}

void Ejercicio2::iniciar(){
    A[0]=-1.;
    A[1]=2.;
    A[2]=3.;
    A[3]=1.;
	B[0]=1.;
	B[1]=1.;
	B[2]=1.;
	B[3]=1.;
	C[0]=3.;
	C[1]=2.;
	C[2]=1.;
	C[3]=1.;

	for(int i=0;i<4;i++){
		transformacion[i] = new double[4];
		Desplazamiento[i] = new double[4];
	}

	//Matriz de transformacionformación
	transformacion[0][0]=-2./3.;
	transformacion[0][1]=1./3.;
	transformacion[0][2]=2./3.;
	transformacion[0][3]=0.;
	transformacion[1][0]=2./3.;
	transformacion[1][1]=2./3.;
	transformacion[1][2]=1./3.;
	transformacion[1][3]=0.;
	transformacion[2][0]=-1./3.;
	transformacion[2][1]=2./3.;
	transformacion[2][2]=-2./3.;
	transformacion[2][3]=0.;
	transformacion[3][0]=0.;
	transformacion[3][1]=0.;
	transformacion[3][2]=0.;
	transformacion[3][3]=1.;

	//Matriz de desplazamiento o traslación
	Desplazamiento[0][0]=1.;
	Desplazamiento[0][1]=0.;
	Desplazamiento[0][2]=0.;
	Desplazamiento[0][3]=-1.;
	Desplazamiento[1][0]=0.;
	Desplazamiento[1][1]=1.;
	Desplazamiento[1][2]=0.;
	Desplazamiento[1][3]=-1.;
	Desplazamiento[2][0]=0.;
	Desplazamiento[2][1]=0.;
	Desplazamiento[2][2]=1.;
	Desplazamiento[2][3]=-1.;
	Desplazamiento[3][0]=0.;
	Desplazamiento[3][1]=0.;
	Desplazamiento[3][2]=0.;
	Desplazamiento[3][3]=1.;
}

double *Ejercicio2::mvmult(double **mat,int sizeMat ,double *vec,int sizeVec)
{
	double *res=new double[sizeVec];

	for(int i=0; i< sizeMat ;i++)
		for(int j=0;j< sizeMat ;j++)
			res[i]+= mat[i][j]*vec[j];
	return res;
}


void Ejercicio2::dibujar_puntos(double *array)
{
    glColor3f(0.18,0.67,0.65);

	glPointSize(6);
	glColor3f (1,1,1); // X axis is red.
    glBegin(GL_POINTS);
    	glVertex3dv(array);
	glEnd();
}


void Ejercicio2::dibujar_Figura(double *_A,double *_B, double *_C,int color)
{
	glLineWidth(1);
	glColor3f (5,color,1); // X axis is red.
	glBegin (GL_LINES);
		glVertex3dv(_A);
		glVertex3dv(_B);

		glVertex3dv(_B);
		glVertex3dv(_C);
	glEnd();

	dibujar_puntos(_A);
	dibujar_puntos(_B);
 	dibujar_puntos(_C);
}

#endif // EJERCICIO2_H
