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
string image_path;

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
    Mat im_dst = imread(image_path);
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
    Mat im_out_gray;
    //Warp source image to destination based on homography
    warpPerspective(img, im_out, h, im_dst.size());
    cvtColor(im_out, im_out_gray, COLOR_BGR2GRAY);

    imwrite("outImg.jpg",im_out_gray);

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
    cout<<"Please enter the name of the image. Follow these instructions for more detail:\n";
    cout<<"1. Open the terminal and give the command: make run.\n";
    cout<<"2. An executable named video will be created.\n";
    cout<<"3. Run the executable with the command: ./video image_name where image_name is the name of the image that you wish to open.\n";
    cout<<"4. Enter the name along with the extension like .jpg, .jpeg, .png etc.\n";
    cout<<"5. All the arguments given (if any) after ./video image_name will be ignored.\n";
  }
  else{
    try
    {
      image_path = samples::findFile(argv[1]);
      img = imread(image_path, IMREAD_COLOR);  
      Mat img_gray;
      cvtColor(img, img_gray, COLOR_BGR2GRAY);

      imshow("Image" , img_gray);
      setMouseCallback("Image",MouseCallFun,NULL);
      waitKey();
    }
    catch(const std::exception& e)
    {
      cout<<"\nERROR!\n";
      cout<<"Please enter correct file name.\n";
      cout<<"Make sure that the image that you wish to open is present in the same directory of the code.\n";
    }
    
    
  }
      
      
    
       
}
