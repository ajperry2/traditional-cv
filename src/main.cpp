
#include <import_image.h>
#include <import_video.h>
#include <import_webcam.h>
#include <basic_functions.h>
#include <rescaling.h>
#include <shapes.h>
#include <warp_perspectives.h>
#include <color_detection.h>
#include <shape_detection.h>
#include <face_detection.h>
#include <color_picker.h>
#include <virtual_painter.h>
#include <document_scanner.h>
#include <license_plate_detector.h>

#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <functional>

using namespace std;


int main(int num_args, char* args[]) {
    
    std::unordered_map<string, std::function<int()>> chapters;
    const char* variable_name = "SCRIPT";
    const char* env_variable_value = std::getenv(variable_name);

    chapters["import_image"] = import_image;
    chapters["import_video"] = import_video;
    chapters["import_webcam"] = import_webcam;
    chapters["basic_functions"] = basic_functions;
    chapters["rescaling"] = rescaling;
    chapters["shapes"] = shapes;
    chapters["warp_perspectives"] = warp_perspectives;
    chapters["color_detection"] = color_detection;
    chapters["shape_detection"] = shape_detection;
    chapters["face_detection"] = face_detection;
    chapters["color_picker"] = color_picker;
    chapters["virtual_painter"] = virtual_painter;
    chapters["document_scanner"] = document_scanner;
    chapters["license_plate_detector"] = license_plate_detector;
    cout << env_variable_value << endl;
    chapters[env_variable_value]();
    return 0;
}