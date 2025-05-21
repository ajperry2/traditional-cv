#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


int import_video() {
    /*
    Load a video and display it
    */
    string vid_path = "../Resources/test_video.mp4";
    VideoCapture cap(vid_path);
    Mat img;
    while (true)
    {
        cap.read(img);
        imshow( "Image", img);
        waitKey(20);
    }
    

    return 0;
}