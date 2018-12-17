//g++ -ggdb -std=c++11 obtener_puntos.cpp -o o_p `pkg-config --cflags --libs opencv` -lopencv_video
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>

#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;
using namespace cv;

class obtener_puntos{
private:
  int angle = 0;
  int cont = 0;
public:
  obtener_puntos(){;}
  void obtener_xyz(int,int,int);
  void ejecutar();
};


void obtener_puntos::obtener_xyz(int i, int j,int e){

    e*=0.4;
    float x = i;
    float y = j;
    float z = x;

    float d = (e-j);

    x = d * cos (angle);
    y = d * sin (angle);
    cont++;
    std::ofstream archivo ("nube_puntos.txt" , std::fstream::app);
    //std::ofstream archivo_opengl ("nube_puntos.txt" , std::fstream::app);
    int contador_lineas=0;
    if (archivo.is_open()){
      //cout<<x<< " " <<y<< " " <<z<<endl;
      archivo<<x<<";"<<y<<";"<<z<<endl;
      archivo.close();
    }
}
void obtener_puntos::ejecutar(){
  for(int id = 0 ;id<72 ; id++){

      //Mat img_origen = imread ("contornos2/"+std::to_string(id)+".png");
      Mat img_origen = imread ("contornos/0.png");
      Mat img_destino;

      //convertir la imagen que cargamos en blanco y negro 
      // y lo guardamos en img_destino
      cvtColor(img_origen, img_destino, CV_BGR2GRAY);
      Size tam_imagen = img_destino.size();
      int ejeZ=(tam_imagen.width)/2;
      //cout<<"tam_imagen.height = "<<tam_imagen.height<<" "<<tam_imagen.width<<endl;
      Vec3f intensity;
      float r,g,b,prom;

      for(int i=0;i<tam_imagen.height;i++){
        for(int j=0;j<tam_imagen.width;j++){

          intensity = img_destino.at<cv::Vec3b>(i, j);
          r=intensity.val[0];
          g=intensity.val[1];
          b=intensity.val[2];

          prom=(r+g+b)/3;

          if(prom==255){

            //cout<<"x "<<i<<" "<<j<<" r = "<<r<<" "<<"g = "<<g<<" "<<"b = "<<b<<endl;  
            //cout<<"axis "<<i<<" "<<j;

            obtener_xyz(i,j,ejeZ);
            break;
          }
        }
        //cout<<"\n"<<endl;
      }
    //cout<<"angulo "<<angle<<endl;
    angle+=5;
  }
  std::cerr<< cont << std::endl; 
}

int main(int argc, char *argv[]) {
  ofstream archivo ("nube_puntos.txt");
  //const int result = remove("nube_puntos");
  obtener_puntos ob;
  ob.ejecutar();
}
