#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
int main(int argc, char* argv[])
{
    Mat_<float> state(4,4,CV_32F);
    cout<<state<<endl;
    state = (Mat_<float>(4, 4) << 1,0,4,0,   0,1,0,4,  0,2,0,0,  0,0,0,0);
    cout<<state<<endl;
    Mat a= (Mat_<float>(1,4)<<1,2,4,5);
    cout<<a*state<<endl;
    cout<<state*state<<endl;
    return 0;
}
