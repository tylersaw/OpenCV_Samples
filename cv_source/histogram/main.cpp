#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
int main(int argc, char* argv[])
{
    Mat src, dst;
    src = imread(argv[1]);
    if(!src.data)
    {
	return -1;
    }

    vector<Mat> bgr_planes;
    split(src, bgr_planes);
    int histSize = 256;
    float range[]={0,256};
    const float* histRange = range;
    bool uniform = true; bool accumulate = false;
    Mat b_hist,r_hist,g_hist;
    calcHist
    return 0;
}
