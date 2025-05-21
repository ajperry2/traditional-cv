#include <iostream>
#include <filesystem>
#include <string>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace std;
using namespace cv;
namespace fs = std::filesystem;


int license_plate_detector() {
    /*
    Detect russian license plates using a cascade classifier, in all images in
    the plates resource folder
    */
    string plate_path = "../Resources/Plates";
    // for OCR

    // For License place detection
    CascadeClassifier license_cascade;
    license_cascade.load("../Resources/haarcascade_russian_plate_number.xml");

    // License plate instances
    vector<Rect> faces;
    // Loop trhough file in plate images
    for (const auto& entry : fs::directory_iterator(plate_path)) {
        if (fs::is_regular_file(entry)) {
            std::cout << entry.path().string() << std::endl;
            Mat img = imread(entry.path().string());
            if (img.empty()) {
                std::cerr << "Could not open or find the image!" << std::endl;
                return -1;
            }
            license_cascade.detectMultiScale(img, faces, 1.1, 10);
            std::cout << faces.size() << std::endl;
            for (int i = 0; i < faces.size(); i++)
            {
                rectangle(img, faces[i].tl(), faces[i].br(), Scalar(69, 255, 0), 10);
            }
            imshow( "Image", img);
            waitKey(3000);
            destroyWindow("Image");
        }
    }


    return 0;
}