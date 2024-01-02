#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

//Basic functions for resizing and cropping

void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat resizedImage, croppedImage;

	//resize(img, resizedImage, Size(640,480));  
	resize(img, resizedImage, Size(), 0.5, 0.5);  //if you dont know the perfect pixel value then you can just use fx and fy

	Rect roi(200, 60, 340, 430);
	croppedImage = img(roi);


	imshow("Image", img);
	imshow("Resized Image", resizedImage);
	imshow("Cropped Image", croppedImage);

	waitKey(0);
}


