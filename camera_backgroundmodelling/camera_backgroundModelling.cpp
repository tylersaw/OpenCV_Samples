#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/video/background_segm.hpp>
using namespace cv;
using namespace std;

int main(int, char**)
{
	Mat src_gray;
	VideoCapture cap(0); // open the default camera
	string fileName="c:/camera_bgm.avi";
	int width = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	int height = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	Mat MaskMog;

	BackgroundSubtractorMOG Mog;
	namedWindow("frame",WINDOW_AUTOSIZE);
	Size frameSize(width, height);
	
	//VideoWriter writer(fileName,CV_FOURCC('M', 'P', '4', '2'),20,frameSize);
	if(!cap.isOpened())  // check if we succeeded
		return -1;
	int key=0;
	Mat frame;
	while(1)
	{
		cap >> frame; // get a new frame from camera
		string FrameNumber= "sekunde.github.io";
		if(char(key)=='q') break;
		else if (char(key)=='b'){
			Mog.operator()(frame,MaskMog,0.1);
			imshow("frame", MaskMog);
		//	writer.write(MaskMog);
		//imwrite("c:/a.jpg",MaskMog);
		
			int tmp=waitKey(30);
			if(tmp!=-1)
				key=tmp;
		
			continue;
		}
		else if (char(key)=='t')
		{
			FrameNumber= "tracking-learning rate=0.1";
			Mog.operator()(frame,MaskMog,0.1);
			blur( MaskMog, src_gray, Size(3,3) );

			Mat threshold_output;
			vector<vector<Point> > contours;
			vector<Vec4i> hierarchy;
			/// Detect edges using Threshold

			threshold( src_gray, threshold_output, 230, 255, THRESH_BINARY );
			/// Find contours
			findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
			vector<RotatedRect> minEllipse( contours.size() );

			for( int i = 0; i < contours.size(); i++ )
			if( contours[i].size() > 5 )
			{ minEllipse[i] = fitEllipse( Mat(contours[i]) ); }

			int max=0;
			for( int i = 0; i<contours.size(); i++ ){
				if(contours[i].size()>max){
					max=contours[i].size();
					ellipse( frame, minEllipse[i], Scalar(200,49,6), 2, 8 );		
				}			
			}		
		}
		else if (char(key)=='v'){
			Mog.operator()(frame,MaskMog,0);
			imshow("frame", MaskMog);

		//	writer.write(MaskMog);
			//imwrite("c:/a.jpg",MaskMog);

			int tmp=waitKey(30);
			if(tmp!=-1)
				key=tmp;
			//cout<<"here"<<endl;
			//cout<<key<<endl;
			continue;
		}
		else if (char(key)=='r')
		{
			FrameNumber= "tracking-learning rate=0";
			Mog.operator()(frame,MaskMog,0);

			/// Convert image to gray and blur it
			//	cvtColor( MaskMog, src_gray, CV_BGR2GRAY );
			blur( MaskMog, src_gray, Size(3,3) );

			Mat threshold_output;
			vector<vector<Point> > contours;
			vector<Vec4i> hierarchy;
			/// Detect edges using Threshold

			threshold( src_gray, threshold_output, 230, 255, THRESH_BINARY );
			/// Find contours
			findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
			vector<RotatedRect> minEllipse( contours.size() );

			for( int i = 0; i < contours.size(); i++ )
				if( contours[i].size() > 5 )
				{ minEllipse[i] = fitEllipse( Mat(contours[i]) ); }
				int max=0;
				for( int i = 0; i<contours.size(); i++ ){
					if(contours[i].size()>max){
						max=contours[i].size();
					ellipse( frame, minEllipse[i], Scalar(200,49,6), 2, 8 );
					}
				}

		}

		putText(frame,FrameNumber.c_str(),Point(25,25),FONT_HERSHEY_SIMPLEX,1,Scalar(2,25,12));
		imshow("frame", frame);
		//writer.write(frame);
		
		int tmp=waitKey(30);
		if(tmp!=-1)
			key=tmp;

		cout<<key<<endl;
		
	}

	return 0;
}