#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;

//for processing pics
//void main() {
//	string path = "Resources/test.png";
//	Mat img = imread(path);
//
//	imshow("Image", img);
//	waitKey(0);
//}


//for processing individual frames of a video
//void main() {
//	string path = "Resources/test_video.mp4";
//	VideoCapture cap(path);
//	Mat img;
//
//	while (true) {
//		cap.read(img);
//		imshow("Video", img);
//		waitKey(4);
//	}
//}

//for processing a webcam

void main() {
	VideoCapture cap(0);
	Mat img;

	while (true) {
		cap.read(img);
		imshow("Video", img);
		waitKey(10);
	}
}
