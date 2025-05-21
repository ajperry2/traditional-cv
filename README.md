# traditional-cv
Following along with the LEARN OPENCV tutorial on youtube

## Scripts



**basic_functions**

Shows basic functionality of opencv in different

![Shows basic functionality of opencv in different](./images/basic_functions.png "Title")

**color_detection**

Finds object by color in an image, displays it and a mask of the detection

![Finds object by color in an image, displays it and a mask of the detection](./images/color_detection.png "Title")

**color_picker**

A convenience script to find which hsv values are suitable to detect an object in the webcam 

![A convenience script to find which hsv values are suitable to detect an object in the webcam ](./images/color_picker.png "Title")

**document_scanner**

Finds a document an an image, warps it for presentation and displays

![Finds a document an an image, warps it for presentation and displays](./images/document_scanner.png "Title")

**face_detection**

Using a cascade classifier finds a face an an image

![Using a cascade classifier finds a face an an image](./images/face_detection.png "Title")

**import_image**

Imports an image from Resources and displays it

![Imports an image from Resources and displays it](./images/import_image.png "Title")

**import_video**

Imports a video from Resources and displays it


![Imports a video from Resources and displays it](./images/import_video.gif "Title")

**import_webcam**

Shows a webcam if you have one


![Shows a webcam if you have one](./images/import_webcam.gif "Title")

**license_plate_detector**

Uses a cascade classifier to find russian license plates in images


![Uses a cascade classifier to find russian license plates in images](./images/license_plate_detector.gif "Title")


**rescaling**

Resizing and cropping functionality in opencv

![Resizing and cropping functionality in opencv](./images/rescaling.png "Title")

**shape_detection**

Detecting shapes and classifying them using the number of corners in their contours

![Resizing and cropping functionality in opencv](./images/shape_detection.png "Title")

**shapes**

Draws shapes on an image

![Draws shapes on an image](./images/shapes.png "Title")


**virtual_painter**

Opens a webcam where If I hold a red or blue marker/pencil correctly it draws on the image

![Opens a webcam where If I hold a red or blue marker/pencil correctly it draws on the image](./images/virtual_painter.gif "Title")

**warp_perspectives**

Crops a section in an image and projects it to be forward facing

![Crops a section in an image and projects it to be forward facing](./images/warp_perspectives.png "Title")


## Setup

**Bare Metal (Unix)**

*Requirements*

- g++ compiler

*steps*

- Build with: `./build.sh`
- `cd src`
- Run scripts like this: `SCRIPT=import_image ./main`

**VS Code**

This code can be ran with vscode without docker.

*Requirements*

- visual studio code
- g++ compiler

*steps*

- open entrypoint at src/main.cpp
- hit play button to build the solution
- choose a scipt to run in `.vscode/tasks.json`
- go to debug tab on left and hit play


