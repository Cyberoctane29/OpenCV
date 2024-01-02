#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

//Draw shapes and texts

void main() {

	//Mat img(512, 512, CV_8UC3, Scalar(255, 0, 0)); //blue
	Mat img(512, 512, CV_8UC3, Scalar(191, 153, 116));

	//circle(img, Point(256, 256), 155, Scalar(191, 105, 19),10);//for unfilled circle
	circle(img, Point(256, 256), 156, Scalar(191, 105, 19), FILLED);

	//rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), 3);//for unfilled rectangle
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);

	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2); //horizontal line

	putText(img, "Saswat Seth", Point(137, 262), FONT_HERSHEY_DUPLEX, 1.2, Scalar(191, 105, 19), 2);

	imshow("Image", img);

	waitKey(0);
}


