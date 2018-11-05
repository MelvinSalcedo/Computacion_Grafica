#include <vector>
#include <iostream>
using namespace std;
#ifndef POLIGONOREGULAR_H
#define POLIGONOREGULAR_H
#define pi 3.1416
#define fin 40
#include <vector>

class punto{
public:
	double x;
	double y;
	punto(){};
	punto(double x_,double y_){
        x=x_;
        y=y_;
	}
};


class PoligonoRegular
{
    public:
        int radio=5,num_lados=100;
        PoligonoRegular(int l,int r){
            radio=r;
            num_lados=l;
        }

    void Poligono_Regular();

};



void PoligonoRegular::Poligono_Regular(){
     int tam=num_lados+1;
    vector<punto> vPunto;
	punto _p;
	double i;
    if (num_lados==3){
		for(i=90;i<360;i+=360/num_lados){
            //cout<<"i: "<<i<<endl;
			_p.x=radio*cos((i*pi)/180);
			_p.y=radio*sin((i*pi)/180);
			vPunto.push_back(_p);
		}
		vPunto.push_back(vPunto[0]);

		for(int i=0;i<tam-1;i++){
            glColor3f(0.0,1.0,1.0);
			glBegin ( GL_LINES ) ;
            glVertex2f ( vPunto[i+1].x,vPunto[i+1].y) ;
            glVertex2f ( vPunto[i].x,vPunto[i].y) ;
			glEnd ( ) ;
		}
	}
	if(num_lados>3){
		for(i=0; i<360; i+=360.0/num_lados){
            //cout<<"i: "<<i<<endl;
			_p.x=radio*cos((i*pi)/180);
			_p.y=radio*sin((i*pi)/180);
			vPunto.push_back(_p);
		}
		vPunto.push_back(vPunto[0]);
		for(int i=0;i<tam-1;i++){
            glColor3f(0.0,1.0,1.0);
			glBegin ( GL_LINES ) ;
            glVertex2f ( vPunto[i+1].x,vPunto[i+1].y) ;
            glVertex2f ( vPunto[i].x,vPunto[i].y) ;
			glEnd ( ) ;
		}
	}
	glFlush();

}

#endif // POLIGONOREGULAR_H
