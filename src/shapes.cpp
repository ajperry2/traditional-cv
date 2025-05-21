#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


int shapes() {
    /*
    Draw shapes on a blank image
    */
    Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));
    circle(img, Point(256, 256), 155, Scalar(0,69,255), 10);
    
    rectangle(img, Point(100, 100), Point(400, 400), Scalar(69, 255, 0), 10);
    line(img, Point(200, 100), Point(400, 100), Scalar(50, 50, 50), 12);
    putText(img, "My Text Here", Point(137, 262), FONT_HERSHEY_DUPLEX, 2, Scalar(50, 50, 50));
    imshow("Image", img);
    waitKey(0);

    return 0;
}