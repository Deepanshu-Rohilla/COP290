#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/persistence.hpp>
using namespace cv;
using namespace std;


Mat src,img,ROI;
Rect cropRect(0,0,0,0);
 Point P1(0,0);
 Point P2(0,0);

const char* winName="Crop Image";
bool clicked=false;
int i=0;
char imgName[15];


void checkBoundary(){
       //check croping rectangle exceed image boundary
       if(cropRect.width>img.cols-cropRect.x)
         cropRect.width=img.cols-cropRect.x;

       if(cropRect.height>img.rows-cropRect.y)
         cropRect.height=img.rows-cropRect.y;

        if(cropRect.x<0)
         cropRect.x=0;

       if(cropRect.y<0)
         cropRect.height=0;
}

void showImage(){
    img=src.clone();
    checkBoundary();
    if(cropRect.width>0&&cropRect.height>0){
        ROI=src(cropRect);
        imshow("cropped",ROI);
    }

    rectangle(img, cropRect, Scalar(0,255,0), 1, 8, 0 );
    imshow(winName,img);
}


void onMouse( int event, int x, int y, int f, void* ){
    switch(event){

        case  EVENT_LBUTTONDOWN  :
            clicked=true;
            P1.x=x;
            P1.y=y;
            P2.x=x;
            P2.y=y;
            break;

        case  EVENT_LBUTTONUP    :
            P2.x=x;
            P2.y=y;
            clicked=false;
            break;

        case  EVENT_MOUSEMOVE    :
            if(clicked){
            P2.x=x;
            P2.y=y;
            }
            break;

        default                     :   break;


    }
    if(clicked){
     if(P1.x>P2.x){ cropRect.x=P2.x;
                       cropRect.width=P1.x-P2.x; }
        else {         cropRect.x=P1.x;
                       cropRect.width=P2.x-P1.x; }

        if(P1.y>P2.y){ cropRect.y=P2.y;
                       cropRect.height=P1.y-P2.y; }
        else {         cropRect.y=P1.y;
                       cropRect.height=P2.y-P1.y; }

    }

showImage();
}
int main()
{
    src=imread("empty.jpg",1);

    namedWindow(winName,WINDOW_NORMAL);
    setMouseCallback(winName,onMouse,NULL );
    imshow(winName,src);

    while(1){
    char c=waitKey(0);
    if(c=='s'&&ROI.data){
     sprintf(imgName,"%d.jpg",i++);
     imwrite(imgName,ROI);
     cout<<"  Saved "<<imgName<<endl;
    }
    if(c=='6') cropRect.x++;
    if(c=='4') cropRect.x--;
    if(c=='8') cropRect.y--;
    if(c=='2') cropRect.y++;

    if(c=='w') { cropRect.y--; cropRect.height++;}
    if(c=='d') cropRect.width++;
    if(c=='x') cropRect.height++;
    if(c=='a') { cropRect.x--; cropRect.width++;}

    if(c=='t') { cropRect.y++; cropRect.height--;}
    if(c=='h') cropRect.width--;
    if(c=='b') cropRect.height--;
    if(c=='f') { cropRect.x++; cropRect.width--;}

    if(c==27) break;
    if(c=='r') {cropRect.x=0;cropRect.y=0;cropRect.width=0;cropRect.height=0;}
    showImage();

    }


    return 0;
}