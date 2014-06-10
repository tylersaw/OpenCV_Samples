#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
using namespace std;
using namespace cv;
int threshold_value = 0;
int threshold_type = 3;
int const max_value = 255;
int const max_type = 4;
int const max_BINARY_value = 255;
Mat dst;
Mat img;
Mat gray;
string window_name = "Thresholding demo";
string trackbar_value = "Value";
string trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
void Threshold_Demo(int, void*)
{
    threshold(gray, dst, threshold_value, max_BINARY_value, threshold_type);
    imshow(window_name, dst);
}
int main(int argc, char** argv )
{
    img = imread("./lena.jpg");
    cvtColor(img, gray, CV_RGB2GRAY);
    namedWindow(window_name,CV_WINDOW_AUTOSIZE);
    imshow(window_name,gray);
    createTrackbar(trackbar_type, window_name, &threshold_type, max_type, Threshold_Demo);
    createTrackbar(trackbar_value, window_name,&threshold_value,max_value, Threshold_Demo);
    waitKey(0);
    return 0;
}
