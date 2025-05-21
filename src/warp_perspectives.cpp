#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


int warp_perspectives() {
    /*
    Extract a card from an image and project it so it looks
    right at us
    */
    string img_path = "../Resources/cards.jpg";
    Mat img = imread(img_path);
    Mat imgWarp;
    Point2f src[4] = {{529, 142}, {771, 190}, {405, 395}, {674, 457}};
    float w = 250.0f;
    float h = 350.0f;
    Point2f dst[4] = {{0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h}};

    Mat matrix = getPerspectiveTransform(src, dst);
    warpPerspective(img, imgWarp, matrix, Point(w,h));
    
    for (size_t i = 0; i < 4; i++)
    {
        circle(img, src[i], 155, Scalar(0,69,255), 10);
    }
    
    imshow("Image", img);
    imshow("ImageWarp", imgWarp);
    waitKey(0);
    return 0;
}