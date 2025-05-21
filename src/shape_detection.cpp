#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void get_contours(Mat image_dilation, Mat image_draw){
    /*
    Find shapes in image, classify them by the number of corners on them
    */


    vector<vector<Point>> contours;
    vector<Vec4i> hirearchy;
    string object_type;
    findContours(image_dilation, contours, hirearchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    cout << contours.size() << endl;
    for (int i = 0; i < contours.size(); i++)
    {
       int area = contourArea(contours[i]);
       cout << area << endl;
       vector<vector<Point>> contourPoly(contours.size());
       vector<Rect> boundRect(contours.size());
       if(area > 1000){
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], contourPoly[i], 0.02*peri, true);
            drawContours(image_draw, contourPoly, i, Scalar(255,0,255), 2);
            boundRect[i] = boundingRect(contourPoly[i]);
            rectangle(image_draw, boundRect[i].tl(), boundRect[i].br(), Scalar(69, 255, 0), 10);

            int objCorner = contourPoly[i].size();

            if(objCorner == 3){
                object_type = "triangle";
            } else if(objCorner == 4){
                float aspect_ratio = (float) boundRect[i].height / (float) boundRect[i].width;
                cout << aspect_ratio << endl;
                if (aspect_ratio > 0.95 && aspect_ratio < 1.05){

                    object_type = "square";
                } else {
                    object_type = "rectangle";
                }
            } else {
                object_type = "circle";
            }
            putText(image_draw, object_type, {boundRect[i].x+10, boundRect[i].y+25}, FONT_HERSHEY_DUPLEX, .6, Scalar(50, 50, 50), 2);



       }
    }
    
}

int shape_detection() {
    /*
    Detect shapes and display the detections
    */
    string img_path = "../Resources/shapes.png";
    Mat img = imread(img_path);
    // Preprocessing
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

    get_contours(dilateImage, img);
    imshow( "Contours",img);
    waitKey(0);

    

    return 0;
}