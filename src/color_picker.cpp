#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace std;
using namespace cv;



int color_picker() {
    /*
    Shows a color detection and allows you to alter the thresholds
    */

    int hmin=0, smin = 0, vmin = 0;
    int hmax=179, smax = 255, vmax = 255;

    // Blank Image
    Mat img;
    VideoCapture cap(0);
    while (!cap.isOpened()) {
        // wait for authorization
        cap.open(0);
        waitKey(100);
    }
    Mat hsv_image;
    namedWindow("trackBars", (640, 200));
    createTrackbar("Hue Min", "trackBars", &hmin, 179);
    createTrackbar("Hue Max", "trackBars", &hmax, 179);
    createTrackbar("Sat Min", "trackBars", &smin, 255);
    createTrackbar("Sat Max", "trackBars", &smax, 255);
    createTrackbar("Val Min", "trackBars", &vmin, 255);
    createTrackbar("Val Max", "trackBars", &vmax, 255);
    while(true){
        cap.read(img);
        cvtColor(img, hsv_image, COLOR_BGR2HSV);
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        Mat mask;
        inRange(hsv_image, lower, upper, mask);
        imshow("HSVImage", hsv_image);
        imshow("Mask", mask);
        waitKey(200);

    }
    return 0;
}