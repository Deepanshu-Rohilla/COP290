#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(){
    string image_path = samples::findFile("empty.jpg");
    Mat img = imread(image_path, IMREAD_COLOR); // Reading the image
    imshow("Display window", img); // Displaying the image 
    int k = waitKey(0); 
}