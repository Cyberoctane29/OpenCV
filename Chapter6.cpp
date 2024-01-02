#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;

//for detecting colours

Mat imgHSV, mask;
int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;

int main() {
	string path = "Resources/lambo.png";
	Mat img = imread(path);

	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	namedWindow("Trackbars", (640, 200));  //to create a window to host the trackbar, can also host images
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Saturation Min", "Trackbars", &hmin, 254);
	createTrackbar("Saturation Max", "Trackbars", &hmax, 254);
	createTrackbar("Value Min", "Trackbars", &hmin, 254);
	createTrackbar("Value Max", "Trackbars", &hmax, 254);


	while (true) {
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);

		imshow("Image", img);
		imshow("HSV-Image", imgHSV);
		imshow("Masked Image", mask);

		waitKey(1);
	}
	return 0;
}
