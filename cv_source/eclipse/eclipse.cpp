#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

Mat src;
Mat src_gray;

int main( int argc, char** argv )
{
	/// Load source image and convert it to gray
	src = imread("c:/a.jpg");
	/// Convert image to gray and blur it
	cvtColor( src, src_gray, CV_BGR2GRAY );
	blur( src_gray, src_gray, Size(3,3) );
	/// Create Window

	Mat threshold_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	/// Detect edges using Threshold

	threshold( src_gray, threshold_output, 200, 1, THRESH_BINARY );
	/// Find contours
	findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

	/// Find the rotated rectangles and ellipses for each contour
	int s=contours.size();
	RotatedRect minEllipse;
	Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
	if (contours[s-1].size()>5)
	{

		minEllipse= fitEllipse( Mat(contours[s-1]) );
		cout<<"im in"<<endl;
		
		ellipse( drawing, minEllipse, Scalar(234,34,2), 2, 8 );

	}


	/// Show in a window
	namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
	imshow( "Contours", drawing );

	waitKey(0);
	return(0);
}

