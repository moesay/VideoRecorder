/*
coded by : mohamed el sayed
13/4/2016
*/

#include <iostream>
#include <opencv\highgui.h>
#include <opencv\cv.h>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture c(0);
	VideoWriter write;
	
	if(!c.isOpened()){cout<<"Error while opening your webcam\n";cin.ignore();return -1;}
	char *winName = "Feed";

	string filename = "D:/vid.avi";
	int fcc = CV_FOURCC('D','I','V','3');
	int fps = 25;
	cv::Size fsize (c.get(CV_CAP_PROP_FRAME_WIDTH),c.get(CV_CAP_PROP_FRAME_HEIGHT));

	write = VideoWriter(filename,fcc,fps,fsize);

	if(!write.isOpened()){cout<<"Error while saving your video\n";cin.ignore();return -1;}

	Mat feed;
	for(;;)
	{
		bool success = c.read(feed);
		if(!success){cout<<"Error while processing your video\n";cin.ignore();return -1;}
		write.write(feed);
		imshow(winName,feed);

		switch(waitKey(10))
		{
		case 27:
			return 0;
		}
	}
}
