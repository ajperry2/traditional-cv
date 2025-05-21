#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


int import_webcam() {
    /*
    Load a webcam and display it
    */
    VideoCapture cap(0);
    while (!cap.isOpened()) {
        // wait for authorization
        cap.open(0);
        waitKey(100);
    }
    Mat img;

    while (true)
    {
        cap.read(img);
        imshow( "Image", img);
        waitKey(1);
    }
    

    return 0;
}