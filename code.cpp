#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/persistence.hpp>

using namespace cv;
using namespace std;

vector<Point2f> pts_src;
int cnt = 0;
bool flag=true;
Mat src,img,ROI;
Rect cropRect(0,0,0,0);
Point P1(0,0);
Point P2(0,0);

const char* winName="Top-View Image";
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
        namedWindow("cropped",WINDOW_FREERATIO);
        imshow("cropped",ROI);
        imwrite("croppedImage.jpg",ROI);
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
            flag=false;
            }
            break;
        default :
          break;

    }
    if(clicked){
     if(P1.x>P2.x){ cropRect.x=P2.x;
            cropRect.width=P1.x-P2.x; }
        else{ cropRect.x=P1.x;
              cropRect.width=P2.x-P1.x; }

        if(P1.y>P2.y){ cropRect.y=P2.y;
                cropRect.height=P1.y-P2.y; }
        else {  cropRect.y=P1.y;
                cropRect.height=P2.y-P1.y; }
                showImage();
    }

}

void MouseCallFun(int event, int x, int y, int flags, void* userdata){

    if(event == EVENT_LBUTTONDOWN){
        pts_src.push_back(Point2f(x,y));
        cnt++;
    }


  if(cnt == 4){
    // Read destination image.
    Mat im_dst = imread("traffic.jpg");
    // Four corners of the book in destination image.
    vector<Point2f> pts_dst;
    pts_dst.push_back(Point2f(472,52));
    pts_dst.push_back(Point2f(800,52));
    pts_dst.push_back(Point2f(472,830));
    pts_dst.push_back(Point2f(800, 830));

    // Calculate Homography
    Mat h = findHomography(pts_src, pts_dst);

    //Output image
    Mat im_out;
    //Warp source image to destination based on homography
    warpPerspective(img, im_out, h, im_dst.size());

    imwrite("outImg.jpg",im_out);

    src=imread("outImg.jpg",1);
    namedWindow(winName,WINDOW_NORMAL);
    setMouseCallback(winName,onMouse,NULL );
    imshow(winName,src);
    cnt++;
    
  }
    waitKey(0); 
}
int main(int argc, char** argv){
  if(argc<2){
    cout<<"yahaan pe samjhaana hai";
  }
  else{
    try
    {
      string image_path = samples::findFile(argv[1]);
      // string image_path = samples::findFile("traffic.jpg");
      img = imread(image_path, IMREAD_COLOR);  
      imshow("Traffic" , img);
      setMouseCallback("Traffic",MouseCallFun,NULL);
      waitKey();
    }
    catch(const std::exception& e)
    {
      cout<<"\nERROR!\n Please enter correct file name\n";
    }
    
    
  }
      
      
    
       
}
