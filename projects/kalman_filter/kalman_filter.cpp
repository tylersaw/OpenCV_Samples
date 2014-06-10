#include <iostream>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
using namespace cv;
using namespace std;
int initialX= 175;
int initialY=87;

int main (int argc, char * const argv[])
{
    VideoCapture cap(argv[1]);
    int currentFrame = 11;
    int totalFrame = cap.get(CV_CAP_PROP_FRAME_COUNT);
    double rate = cap.get(CV_CAP_PROP_FPS);
    int delay = 1000/rate;
    char code;    

    vector<Vec3f> circles;
    Mat src, src_gray;
    namedWindow("kalman");
    cap.set(CV_CAP_PROP_POS_FRAMES, currentFrame);
    
    KalmanFilter KF(4, 2, 0);
    KF.statePost = (Mat_<float>(4,1)<< initialX, initialY, 0, 0);
    Mat_<float> measurement(2,1);  
    KF.transitionMatrix = *(Mat_<float>(4, 4) << 1,0,0,0,   0,1,0,0,  0,0,0,0,  0,0,0,0);
    setIdentity(KF.measurementMatrix);
    setIdentity(KF.processNoiseCov, Scalar::all(1.77));
    setIdentity(KF.measurementNoiseCov, Scalar::all(1e-1));
    setIdentity(KF.errorCovPost, Scalar::all(1.77));
  
    while(currentFrame < totalFrame-80)
    {
	Mat predictedState = KF.predict();
	cout<<predictedState<<endl;
	Mat predictedPosition = KF.measurementMatrix*predictedState;
	Point predictPt(predictedState.at<float>(0),predictedState.at<float>(1));
	cout<<predictPt.x<<" "<<predictPt.y<<endl;

	cap.read(src);
/*
	cvtColor(src, src_gray, CV_BGR2GRAY);
	double mininum= 1.0/0.0; //inf
	int finalX, finalY;
*/
	measurement(0) = finalX;
	measurement(1) = finalY;
	KF.correct(measurement);

	Point statePt(predictPt.x,predictPt.y);
	Point measPt(measurement(0),measurement(1));
	circle(src, statePt, 5, Scalar(0,0,255), 3, 8, 0);
	circle(src, measPt, 5, Scalar(255,0,0), 3, 8, 0);

	currentFrame++;
	imshow( "kalman", src );
	code = (char)waitKey(delay);
    }
	return 0;
}
