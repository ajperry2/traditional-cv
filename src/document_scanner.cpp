#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Mat img_original, imgWarp, resized, grayImage, blurImage, cannyImage, dilateImage, erodeImage, cropped_image;
float w = 420, h = 596;
vector<Point> initial_points, document_points;

void preprocessing(){
    cvtColor(img_original, grayImage, COLOR_BGR2GRAY);

    GaussianBlur( grayImage, blurImage, Size(7,7), 5, 0);
    Canny(blurImage, cannyImage, 50, 150);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5));
    dilate(cannyImage, dilateImage, kernel);
    // erode(dilateImage, erodeImage, kernel);
}

void reorder(){
    vector<int> sum_points(4), sub_points(4);
    for (int i = 0; i < 4; i++)
    {
        sum_points[i] = initial_points[i].x + initial_points[i].y;
        sub_points[i] = initial_points[i].x - initial_points[i].y;
    }
    document_points.push_back(
        initial_points[min_element(sum_points.begin(), sum_points.end()) - sum_points.begin()]
    );
    document_points.push_back(
        initial_points[max_element(sub_points.begin(), sub_points.end()) - sub_points.begin()]
    );
    document_points.push_back(
        initial_points[min_element(sub_points.begin(), sub_points.end()) - sub_points.begin()]
    );
    document_points.push_back(
        initial_points[max_element(sum_points.begin(), sum_points.end()) - sum_points.begin()]
    );
    
}

vector<Point> get_contours(){


    vector<vector<Point>> contours;
    vector<Vec4i> hirearchy;
    string object_type;
    findContours(dilateImage, contours, hirearchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    // cout << contours.size() << endl;
    vector<vector<Point>> contourPoly(contours.size());
    vector<Rect> boundRect(contours.size());
    vector<Point> biggest;
    int max_area = 0;
    for (int i = 0; i < contours.size(); i++)
    {
       int area = contourArea(contours[i]);
       if(area > max_area){
            max_area = area;
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], contourPoly[i], 0.02*peri, true);
            if( contourPoly[i].size() == 4){
                // drawContours(img_original, contourPoly, i, Scalar(255,0,255), 2);
                biggest = {
                    contourPoly[i][0],
                    contourPoly[i][1],
                    contourPoly[i][2],
                    contourPoly[i][3]};
            }
            


       }
    }
    return biggest;
}


void draw_points(vector<Point> points, Scalar color){
    for (int i = 0; i < points.size(); i++)
    {
        circle(img_original, points[i], 10, color, FILLED);
        putText(img_original, to_string(i), points[i], FONT_HERSHEY_PLAIN, 4, color, 4);
    }
    
}

int document_scanner() {
    // Blank Image
    string img_path = "../Resources/paper.jpg";
    img_original = imread(img_path);
    

    // Preprocess
    preprocessing();
    imshow("Threshold", dilateImage);
    // Get Contours
    initial_points = get_contours();
    reorder();

    // Warp
    Point2f src[4] = {
        {(float) document_points[0].x, (float) document_points[0].y}, 
        {(float) document_points[1].x, (float) document_points[1].y}, 
        {(float) document_points[2].x, (float) document_points[2].y}, 
        {(float) document_points[3].x, (float) document_points[3].y}}; 
    Point2f dst[4] = {{0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h}};

    Mat matrix = getPerspectiveTransform(src, dst);
    warpPerspective(img_original, imgWarp, matrix, Point(w,h));
    

    // Crop
    int crop_value = 5;
    Rect roi(crop_value, crop_value, w - (2*crop_value), h  - (2*crop_value));
    cropped_image = imgWarp(roi);

    // draw_points(document_points, Scalar(255, 0, 0));
    imshow("Origunal", img_original);
    imshow("Warped", imgWarp);
    imshow("Cropped", cropped_image);
    waitKey(0);
    return 0;
}