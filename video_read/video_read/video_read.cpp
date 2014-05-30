#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void help()
{
	cout
		<< "--------------------------------------------------------------------------"   << endl
		<< "This program shows how to read video files and track it by using Kalman Filter. You can extract the R or G or B color channel "
		<< " of the input video. You can choose to use the source codec (Y) or select a custom one. (N)"<< endl
		<< "Usage:"                                                                       << endl
		<< "./video-write inputvideoName [ R | G | B] [Y | N]"                            << endl
		<< "--------------------------------------------------------------------------"   << endl
		<< endl;
}

int main()
{
	// here comes the actual source code
	//����Ƶ�ļ�����ʵ���ǽ���һ��VideoCapture�ṹ
	VideoCapture capture("C:/billiard-trickshot.mp4");
	//����Ƿ�������:�ɹ���ʱ��isOpened����ture
	if(!capture.isOpened())
	{
		
		cout<<"fail to open!"<<endl;
	}
	//��ȡ����֡��
	long totalFrameNumber = capture.get(CV_CAP_PROP_FRAME_COUNT);
	cout<<"������Ƶ��"<<totalFrameNumber<<"֡"<<endl;


	//���ÿ�ʼ֡()
	long frameToStart = 1;
	capture.set( CV_CAP_PROP_POS_FRAMES,frameToStart);
	cout<<"�ӵ�"<<frameToStart<<"֡��ʼ��"<<endl;


	//���ý���֡
	int frameToStop = 104;

	if(frameToStop < frameToStart)
	{
		cout<<"����֡С�ڿ�ʼ֡��������󣬼����˳���"<<endl;
		return -1;
	}
	else
	{
		cout<<"����֡Ϊ����"<<frameToStop<<"֡"<<endl;
	}


	//��ȡ֡��
	double rate = capture.get(CV_CAP_PROP_FPS);
	cout<<"֡��Ϊ:"<<rate<<endl;



	//����һ���������ƶ�ȡ��Ƶѭ�������ı���
	bool stop = false;
	//����ÿһ֡��ͼ��
	Mat frame;
	//��ʾÿһ֡�Ĵ���
	namedWindow("Extracted frame");
	//��֡��ļ��ʱ��:
	//int delay = 1000/rate;
	int delay = 1000/rate;


	//����whileѭ����ȡ֡
	//currentFrame����ѭ�����п��ƶ�ȡ��ָ����֡��ѭ�������ı���
	long currentFrame = frameToStart;


	//�˲����ĺ�
	int kernel_size = 3;
	Mat kernel = Mat::ones(kernel_size,kernel_size,CV_32F)/(float)(kernel_size*kernel_size);

	while(!stop)
	{
		//��ȡ��һ֡
		if(!capture.read(frame))
		{
			cout<<"��ȡ��Ƶʧ��"<<endl;
			return -1;	
		}

		//������˲�����
		imshow("Extracted frame",frame);
		filter2D(frame,frame,-1,kernel);

		imshow("after filter",frame);
		cout<<"���ڶ�ȡ��"<<currentFrame<<"֡"<<endl;
		//waitKey(int delay=0)��delay �� 0ʱ����Զ�ȴ�����delay>0ʱ��ȴ�delay����
		//��ʱ�����ǰû�а�������ʱ������ֵΪ-1�����򷵻ذ���


		int c = waitKey(delay);
		//����ESC���ߵ���ָ���Ľ���֡���˳���ȡ��Ƶ
		if((char) c == 27 || currentFrame > frameToStop)
		{
			stop = true;
		}
		//���°������ͣ���ڵ�ǰ֡���ȴ���һ�ΰ���
		if( c >= 0)
		{
			waitKey(0);
		}
		currentFrame++;

	}
	//�ر���Ƶ�ļ�
	capture.release();
	waitKey(0);
	return 0;
}

