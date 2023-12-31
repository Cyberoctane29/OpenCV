#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;

//Basic functions for processing pics

void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDilate, imgErode;

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	//GaussianBlur(img, imgBlur, Size(7, 7),5,0);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	//Canny(imgBlur, imgCanny, 60, 150); //for normal edges 
	Canny(imgBlur, imgCanny, 25, 75); //for more edges

	Mat kernel1 = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDilate, kernel1);

	Mat kernel2 = getStructuringElement(MORPH_RECT, Size(3, 3));
	erode(imgDilate, imgErode, kernel2);

	//imshow("Image", img);
	/*imshow("Gray Image", imgGray);
	imshow("Blurred Image", imgBlur);*/
	//imshow("Canny Edge detected Image", imgCanny);
	imshow("Dialated Image", imgDilate);
	imshow("Eroded Image", imgErode);


	waitKey(0);
}


