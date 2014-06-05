#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	int keyboard='s';
    Mat frame;
    Mat MaskMog;

	BackgroundSubtractorMOG Mog;
	
    VideoCapture capture("c:/billiard-trickshot.mp4");
    if(!capture.isOpened())
    {
	cerr<<"error"<<endl;
	return -1;
    }
    int current=0;
    int total=capture.get(CV_CAP_PROP_FRAME_COUNT);
    while((char)keyboard!='q'&&total!=current+1)
    {
	if(!capture.read(frame))
	{
	    cout<<total<<" "<<current<<endl;
	    cerr<<"error"<<endl;
	    return -1;
	}
	rectangle(frame,Point(10,2),Point(100,2),Scalar(255,255,255),-1);

	Mog.operator()(frame,MaskMog,0.1);
	

	stringstream ss;
	ss << capture.get(CV_CAP_PROP_POS_FRAMES);
	string FrameNumber= ss.str();
	current=atoi(FrameNumber.c_str());
	putText(frame,FrameNumber.c_str(),Point(15,15),FONT_HERSHEY_SIMPLEX,0.5,Scalar(0,0,0));
	imshow("frame",frame);
	imshow("Mog",MaskMog);
	
	keyboard=waitKey(30);

    }

    return 0;
}
