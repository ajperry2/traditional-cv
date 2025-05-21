#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


int rescaling() {
    /*
    Rescale an image, crop it and show the results
    */
    string img_path = "../Resources/test.png";
    Mat img = imread(img_path);
    Mat resized, cropped;
    imshow("Image", img);
    // Resizing
    resize(img, resized, Size(), 0.5, 0.5);
    imshow("Resized", resized);
    // Cropping
    Rect roi(100, 100, 300, 250);
    cropped = img(roi);
    imshow("Cropped", cropped);
    waitKey(0);

    return 0;
}