#include <iostream>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>

using namespace cv;
using namespace std;
int initialX= 175;
int initialY=87;

void on_mouse(int event, int x, int y, int flags, void* param) {
	if (event == CV_EVENT_LBUTTONDOWN) 
	{
		initialX = x;
		initialY = y;
		cout << "got mouse " << x <<","<< y <<endl;
	}
}

int main (int argc, char * const argv[])
{
    VideoCapture cap(argv[1]);
    int currentFrame = 11;
    int totalFrame = cap.get(CV_CAP_PROP_FRAME_COUNT);
    double rate = cap.get(CV_CAP_PROP_FPS);
    int delay = 1000/rate;
    
    KalmanFilter KF(4, 2, 0);
    Mat_<float> state(4, 1); /* (x, y, Vx, Vy) */
    Mat processNoise(4, 1, CV_32F);
    Mat_<float> measurement(2,1);
    measurement.setTo(Scalar(0));
    char code = (char)1;
    
    vector<Vec3f> circles;
    Mat src, src_gray;

    namedWindow("kalman");
    
    cap.set(CV_CAP_PROP_POS_FRAMES, 11);
  /*  setMouseCallback("kalman", on_mouse, 0);
    cap.set(CV_CAP_PROP_POS_FRAMES, 10);
    cap.read(src);
    imshow("kalman",src);
    while(code = waitKey(1000)) 
    {
	if(code=='q')  break;
	cout<<"wait for initial..."<<endl;
    }
  */	

    KF.statePre.at<float>(0) = initialX;
    KF.statePre.at<float>(1) = initialY;
    KF.statePre.at<float>(2) = 0;
    KF.statePre.at<float>(3) = 0;
    KF.transitionMatrix = *(Mat_<float>(4, 4) << 1,0,0.4,0,   0,1,0,0.4,  0,0,0,0,  0,0,0,0);
    
    setIdentity(KF.measurementMatrix);
    setIdentity(KF.processNoiseCov, Scalar::all(1e-4));
    setIdentity(KF.measurementNoiseCov, Scalar::all(1e-1));
    setIdentity(KF.errorCovPost, Scalar::all(.1));
    
    while(currentFrame < totalFrame-50)
    {
	Mat prediction = KF.predict();
	Point predictPt(prediction.at<float>(0),prediction.at<float>(1));
	if(currentFrame == 11) {

	predictPt.x = initialX;
	predictPt.y = initialY;
	}


	cout<<predictPt.x<<" "<<predictPt.y<<endl;

	waitKey(10000);
	cap.read(src);
	cvtColor(src, src_gray, CV_BGR2GRAY);
	GaussianBlur(src_gray, src_gray, Size(9,9),2,2);
	HoughCircles(src_gray, circles, CV_HOUGH_GRADIENT, 1, src_gray.rows/8, 100, 5, 0, 10);
	double mininum= 1.0/0.0; //inf
	int finalX, finalY;
	for(size_t i=0;i<circles.size();i++)
	{
	   
	    Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
	    circle(src, center, 5, Scalar(0,255,0), 3, 8, 0);
	    if(sqrt(pow(center.x-predictPt.x,2)+pow(center.y-predictPt.y,2))<mininum)
	    {
		mininum=sqrt(pow(center.x-predictPt.x,2)+pow(center.y-predictPt.y,2));
		finalX=center.x;
		finalY=center.y;
	    }	
	}
	measurement(0) = finalX;
	measurement(1) = finalY;

	Point measPt(measurement(0),measurement(1));
	Mat estimated = KF.correct(measurement);
	Point statePt(estimated.at<float>(0),estimated.at<float>(1));
	circle(src, statePt, 5, Scalar(0,0,255), 3, 8, 0);
	circle(src, measPt, 5, Scalar(255,0,0), 3, 8, 0);

	currentFrame++;
	imshow( "kalman", src );
	code = (char)waitKey(delay);
	if( code > 0 ) break;
    }
	return 0;
}
