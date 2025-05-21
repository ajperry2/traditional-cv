#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


int import_image() {
    /*
    Load an image and display it
    */
    string img_path = "../Resources/test.png";
    Mat img = imread(img_path);
    imshow( "Image", img);
    waitKey(0);
    return 0;
}