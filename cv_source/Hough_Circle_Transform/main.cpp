#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
int main(int argc, char* argv[])
{
	
    namedWindow( "Hough Circle Transform Demo", CV_WINDOW_AUTOSIZE );
    Mat src, src_gray;
    VideoCapture cap(argv[1]);
    double rate = cap.get(CV_CAP_PROP_FPS);
    int delay = 1000/rate;
    int currentFrame = 1;
    int totalFrame = cap.get(CV_CAP_PROP_FRAME_COUNT);
    while(currentFrame < totalFrame){
	cap.read(src);
	currentFrame++;
    cvtColor(src, src_gray, CV_BGR2GRAY);
    GaussianBlur(src_gray, src_gray, Size(9,9),2,2);
    vector<Vec3f> circles;
    HoughCircles(src_gray, circles, CV_HOUGH_GRADIENT, 1, src_gray.rows/8, 10, 5, 0, 3);
    for(size_t i=0;i<circles.size();i++)
    {
	 Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
	 int radius = cvRound(circles[i][2]);
	  // circle center
	 circle( src, center, 3, Scalar(0,255,0), -1, 8, 0 );
	  // circle outline
//	 circle( src, center, radius, Scalar(0,0,255), 3, 8, 0 );
    }
    imshow( "Hough Circle Transform Demo", src );
    waitKey(delay);
    }
    waitKey(0);    
    return 0;
}
