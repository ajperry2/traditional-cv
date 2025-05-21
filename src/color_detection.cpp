#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


int color_detection() {
    // Blank Image
    string img_path = "../Resources/lambo.png";
    Mat img = imread(img_path);
    Mat hsv_image;
    cvtColor(img, hsv_image, COLOR_BGR2HSV);
    int hmin=0, smin = 110, vmin = 153;
    int hmax=19, smax = 240, vmax = 255;
    namedWindow("trackBars", (640, 200));
    createTrackbar("Hue Min", "trackBars", &hmin, 179);
    createTrackbar("Hue Max", "trackBars", &hmax, 179);
    createTrackbar("Sat Min", "trackBars", &smin, 255);
    createTrackbar("Sat Max", "trackBars", &smax, 255);
    createTrackbar("Val Min", "trackBars", &vmin, 255);
    createTrackbar("Val Max", "trackBars", &vmax, 255);
    while(true){
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        Mat mask;
        inRange(hsv_image, lower, upper, mask);
        imshow("Image", img);
        imshow("HSVImage", hsv_image);
        imshow("Mask", mask);
        waitKey(1);

    }

    return 0;
}