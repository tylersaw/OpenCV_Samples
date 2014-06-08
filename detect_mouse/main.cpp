#include <iostream>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

void callbackFunc(int event, int x, int y, int, void *)
{
    if(event == EVENT_LBUTTONDOWN)
    {
	cout<<x<<" "<<y<<endl;
    }
    else if(event == EVENT_MOUSEMOVE)
    {
	cout<<"moving.."<<endl;
    }
}

int main()
{
    Mat img = imread("lena.jpg");
    namedWindow("window");
    setMouseCallback("window1",callbackFunc);
    imshow("window",img);  
    waitKey(0);
}
