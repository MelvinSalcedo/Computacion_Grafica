//g++ -ggdb -std=c++11 Obtener_imagenes.cpp -o obtener_imagen `pkg-config --cflags --libs opencv` -lopencv_video -lpthread

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <sstream>
#include <unistd.h>
#include <thread>

using namespace std;
using namespace cv;


cv::VideoCapture TheVideoCapturer;
cv::Mat bgrMap;
cv::Mat contours;
int cont=0;

void tomar_foto(){

	int numSnapshot = 0;
	cv::Mat bgrMap1;
	std::string snapshotFilename = "0";

  	while(cont < 72){
	    usleep(45000000/300);
	    /*retruieve debueve el fotograma capturada 
	    y lo guarda en bgrmap1*/
	    TheVideoCapturer.retrieve(bgrMap1);
	    cv::cvtColor(bgrMap1, contours, CV_BGR2GRAY);
	    /*cvtcolor convierte la imagen almacenad en grpma11 en graay 
	    y lo guarda en contous*/
	    cv::imwrite("images/"+ snapshotFilename + ".png", contours);
	    /*imwrite guarda contours en una direccion*/
	    numSnapshot++;
	    snapshotFilename = static_cast<std::ostringstream*>(&(std::ostringstream() << numSnapshot))->str();
	    cont++;
  	}
}

int main(int argc, char *argv[]) {
	char key = 0;


    TheVideoCapturer.open("http://192.168.43.1:8080/video?x.mjpeg");
    //TheVideoCapturer.open("http://10.42.0.199:8080/video?x.mjpeg");

    if (!TheVideoCapturer.isOpened()) {
    	std::cerr<<"\n\nConexion no encontrada con el dispositivo\n\n"<<std::endl;
    	return -1;
    }
    //tomar_foto();
  	std::thread fotografo;
  	fotografo=std::thread(tomar_foto);
  	
  	while(TheVideoCapturer.grab() && cont<36){
    	TheVideoCapturer.retrieve(bgrMap);
    	cv::waitKey(20);
  	}

  	fotografo.join();

}