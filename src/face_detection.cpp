#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace std;
using namespace cv;



int face_detection() {
    /*
    Finds a face in an image using a cascade classifier
    */
    string img_path = "../Resources/test.png";
    Mat img = imread(img_path);

    CascadeClassifier face_cascade;
    face_cascade.load("../Resources/haarcascade_frontalface_default.xml");
    if(face_cascade.empty()){
        cout << "XML not loaded" << endl;
    }
    vector<Rect> faces;
    face_cascade.detectMultiScale(img, faces, 1.1, 10);
    for (int i = 0; i < faces.size(); i++)
    {
        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(69, 255, 0), 10);
    }
    imshow("Image", img);
    waitKey(0);
    return 0;
}