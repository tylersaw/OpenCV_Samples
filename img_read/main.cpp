#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv )
{
    Mat image;
    image = imread( argv[1], 1 );
    Mat img = imread(argv[1],0);
 //   for(int i=1;i<=200;i++)
	//    image.row(i)=255;
   // cout<<image<<endl;
   Point start;
   start.x=10;
   start.y=8;
   Point end=Point(60,100);
   int thickness = 20;
   int lineType = 6;
   line(image,start,end,Scalar( 255, 0, 0 ),thickness,lineType );
   rectangle(image,  Point( 100, 100 ), Point(200,200 ), Scalar( 20, 255, 255), 10, 8 );
//    namedWindow("Display Image", CV_WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    imshow("Display Image", img);
    
    waitKey(0);

    return 0;
}
