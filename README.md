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

<video src="./images/import_video.mp4" placeholder="./images/import_video.mp4" autoplay loop controls muted title="test-title">
Sorry, your browser doesn't support HTML 5 video.
</video>

**import_webcam**

Shows a webcam if you have one

<video src="./images/import_webcam.mp4" placeholder="./images/import_webcam.mp4" autoplay loop controls muted title="test-title">
Sorry, your browser doesn't support HTML 5 video.
</video>

**license_plate_detector**

Uses a cascade classifier to find russian license plates in images

<video src="./images/license_plate_detector.mp4" placeholder="./images/license_plate_detector.mp4" autoplay loop controls muted title="test-title">
Sorry, your browser doesn't support HTML 5 video.
</video>

**rescaling**

Resizing and cropping functionality in opencv

![Resizing and cropping functionality in opencv](./images/rescaling.png "Title")

**shape_detection**

Resizing and cropping functionality in opencv

![Resizing and cropping functionality in opencv](./images/shape_detection.png "Title")

**shapes**

Draws shapes on an image

![Draws shapes on an image](./images/shapes.png "Title")


**virtual_painter**

Opens a webcam where If I hold a red or blue marker/pencil correctly it draws on the image

<video src="./images/virtual_painter.mp4" placeholder="./images/virtual_painter.mp4" autoplay loop controls muted title="test-title">
Sorry, your browser doesn't support HTML 5 video.
</video>


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


