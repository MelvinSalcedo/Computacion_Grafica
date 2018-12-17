// g++ -ggdb -std=c++11 obtener_contornos.cpp -o o_c `pkg-config --cflags --libs opencv` -lopencv_video -lpthread
#include <iostream>
#include <bits/stdc++.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <sstream>
#include<vector>

using namespace std;
using namespace cv;

class Obtener_contornos{
private:
  
  
public:
  int alto;
  int ancho;

  Mat img_origen;
  Mat img_destino;

  Size tam_imagen;
  Vec3f intensity;

  int r,g,b,prom;
  string nombre_imagen;
  Obtener_contornos(string name_image){
    nombre_imagen=name_image;
    img_origen = cv::imread("Images2/"+nombre_imagen+".png");
    img_destino;
    cvtColor(img_origen, img_destino, CV_BGR2GRAY);
  }

  void obtener_dimesion_imagen();
  void transformar_imagen();

};

void Obtener_contornos::obtener_dimesion_imagen(){
  tam_imagen = img_destino.size();
}

void Obtener_contornos::transformar_imagen(){
  for(int i=0;i<tam_imagen.height;i++){
    std::vector<int> Temporal;
    for(int j=0;j<tam_imagen.width;j++){

      intensity = img_destino.at<cv::Vec3b>(i, j);
      r=intensity.val[0];
      g=intensity.val[1];
      b=intensity.val[2];
      prom=(r+g+b)/3;
      
      if(prom<60){
        intensity.val[0]=0;
        intensity.val[1]=0;
        intensity.val[2]=0;
        img_destino.at<cv::Vec3b>(i, j) = intensity;
      }
      else{
        intensity.val[0]=255;
        intensity.val[1]=255;
        intensity.val[2]=255;
        img_destino.at<cv::Vec3b>(i, j) = intensity;
        
        for(int jj=j+1;jj<tam_imagen.width;jj++){
          intensity = img_destino.at<cv::Vec3b>(i, jj);
          intensity.val[0]=0;
          intensity.val[1]=0;
          intensity.val[2]=0;
          img_destino.at<cv::Vec3b>(i, jj) = intensity;
        }
        break;
      }
    }
    //cout<<"\n"<<endl;
  }
  imwrite("contornos/"+nombre_imagen+".png",img_destino);
}


int main(int argc, char *argv[]) {
  string id_imagen;
  std::vector<Obtener_contornos*> v;
  for(int x=0;x<72;x++){
    id_imagen=to_string(x);
    Obtener_contornos *a=new Obtener_contornos(id_imagen);
    v.push_back(a);
    cout<<"-------------------------"<<endl;
    
  }
  for(int x=0;x<72;x++){ 
    cout<<"x= "<<v[x]->nombre_imagen<<endl;
    v[x]->obtener_dimesion_imagen();
    v[x]->transformar_imagen();
  }
}