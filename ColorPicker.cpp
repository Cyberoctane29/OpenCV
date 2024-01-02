#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// For detecting colors

Mat imgHSV, mask, imgColor;
int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;

VideoCapture cap(0);
Mat img;

int main() {
    namedWindow("Trackbars", (100, 100));  //to create a window to host the trackbar, can also host images
    resizeWindow("Trackbars", 400, 200);
    createTrackbar("Hue Min", "Trackbars", &hmin, 179);
    createTrackbar("Hue Max", "Trackbars", &hmax, 179);
    createTrackbar("Saturation Min", "Trackbars", &hmin, 254);
    createTrackbar("Saturation Max", "Trackbars", &hmax, 254);
    createTrackbar("Value Min", "Trackbars", &hmin, 254);
    createTrackbar("Value Max", "Trackbars", &hmax, 254);

    while (true) {
        cap.read(img);

        cvtColor(img, imgHSV, COLOR_BGR2HSV);

        Scalar lower(hmin, smin, vmin); // Fix variable assignment
        Scalar upper(hmax, smax, vmax); // Fix variable assignment

        inRange(imgHSV, lower, upper, mask);

        cout << hmin << "," << smin << "," << vmin << "," << hmax << "," << smax << "," << vmax << endl;
        imshow("Image", img);
        imshow("Masked Image", mask);

        waitKey(1);
    }

    return 0;
}
