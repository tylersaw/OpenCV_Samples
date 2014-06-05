#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argv, char **argc)
{
    	
	VideoCapture capture(argc[1]);
	if(!capture.isOpened())
	{
		cout<<"fail to open!"<<endl;
	}
	long totalFrameNumber = capture.get(CV_CAP_PROP_FRAME_COUNT);

	long frameToStart = 1;
	int frameToStop = totalFrameNumber;
	
	capture.set( CV_CAP_PROP_POS_FRAMES,frameToStart);
	
	double rate = capture.get(CV_CAP_PROP_FPS);
	int delay = 1000/rate;
	
	bool stop = false;
	Mat frame;
	namedWindow("frame");
	long currentFrame = frameToStart;
	
	Point start=Point(40,90);
	Point end = Point(200,300);
	while(!stop)
	{
	    cerr<<"show"<<endl;
	    	capture.read(frame);
		line(frame,start,end, 2,8);
		imshow("frame",frame);
		cout<<"currentFrame:"<<currentFrame<<endl;
		int c = waitKey(delay);
		if((char) c == 27 || currentFrame == frameToStop-2)
		{
			stop = true;
		}
		if( c >= 0)
		{
			waitKey(0);
		}
		currentFrame++;

	}
	capture.release();
	waitKey(0);
	return 0;
}

