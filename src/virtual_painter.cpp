#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace std;
using namespace cv;


Mat img;
vector<vector<int>> points;
vector<vector<int>> my_colors {
    {75, 68, 0, 146, 233, 255}, // blue
    {0, 181, 0, 7, 255, 255}, // red
};
vector<Scalar> myColorValues {{255, 0, 0}, {0, 0, 255}};

Point get_contours(Mat image_dilation){


    vector<vector<Point>> contours;
    vector<Vec4i> hirearchy;
    string object_type;
    findContours(image_dilation, contours, hirearchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    // cout << contours.size() << endl;
    vector<vector<Point>> contourPoly(contours.size());
    vector<Rect> boundRect(contours.size());
    Point my_point(0, 0);
    for (int i = 0; i < contours.size(); i++)
    {
       int area = contourArea(contours[i]);
    //    cout << area << endl;
       if(area > 1000){
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], contourPoly[i], 0.02*peri, true);
            boundRect[i] = boundingRect(contourPoly[i]);
            float aspect_ratio = (float) boundRect[i].height / (float) boundRect[i].width;

            if (aspect_ratio > 2.05){
                cout << aspect_ratio << endl;
                drawContours(img, contourPoly, i, Scalar(255,0,255), 2);
                my_point.x = boundRect[i].x + boundRect[i].width/2;
                my_point.y = boundRect[i].y;
            }


       }
    }
    return my_point;
}
void find_color(Mat image){
    Mat image_hsv;
    cvtColor(image, image_hsv, COLOR_BGR2HSV);
    for (int i = 0; i < my_colors.size(); i++)
    {
        Scalar lower(my_colors[i][0], my_colors[i][1], my_colors[i][2]);
        Scalar upper(my_colors[i][3], my_colors[i][4], my_colors[i][5]);
        Mat mask;
        inRange(image_hsv, lower, upper, mask);
        Point my_point = get_contours(mask);
      
        if(my_point.x != 0 && my_point.y != 0){
            points.push_back({my_point.x, my_point.y, (int) myColorValues[i][0], (int) myColorValues[i][1], (int) myColorValues[i][2]});
        }
    }
    

}

void draw_on_canvas(){
    for (int i = 0; i < points.size(); i++)
    {
        circle(
            img, 
            Point(points[i][0], points[i][1]), 
            10, 
            Scalar(points[i][2], points[i][3], points[i][4]), -1);
    }

    
}


int virtual_painter() {
    int hmin=0, smin = 0, vmin = 0;
    int hmax=179, smax = 255, vmax = 255;

    // Blank Image
    VideoCapture cap(0);
    while (!cap.isOpened()) {
        // wait for authorization
        cap.open(0);
        waitKey(100);
    }
    while(true){
        cap.read(img);
        find_color(img);
        draw_on_canvas();
        imshow("VirtualPainter", img);
        waitKey(10);

    }
    return 0;
}