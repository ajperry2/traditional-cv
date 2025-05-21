#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


int basic_functions() {
    string img_path = "../Resources/test.png";
    Mat img = imread(img_path);
    Mat grayImage, blurImage, cannyImage, dilateImage, erodeImage;
    cvtColor(img, grayImage, COLOR_BGR2GRAY);

    imshow( "Gray", grayImage);
    GaussianBlur( grayImage, blurImage, Size(7,7), 5, 0);
    imshow( "GaussianBlur", blurImage);
    Canny(img, cannyImage, 50, 150);
    imshow( "Canny", cannyImage);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5));
    dilate(cannyImage, dilateImage, kernel);
    imshow( "Dilate", dilateImage);
    erode(dilateImage, erodeImage, kernel);
    imshow("Erode", erodeImage);
    waitKey(0);

    return 0;
}