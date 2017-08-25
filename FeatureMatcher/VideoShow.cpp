#include "opencv2/opencv.hpp"

using namespace cv;

int main(int, char**)
{
    VideoCapture cap; // open the default camera
    cap.open("../../Video1.mp4");
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    for(;;)
    {
        Mat frame;
	Mat resize_frame;
        cap >> frame; // get a new frame from camera
	if(frame.empty()) break;
	resize(frame,resize_frame,Size(),0.5,0.5);
        if(char(waitKey(1)) == 'q') break;
	imshow("Video",resize_frame);
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
