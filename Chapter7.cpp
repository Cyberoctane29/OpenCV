#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;

//for detecting shapes and contours

void getContour(Mat imgDil, Mat img) {
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	vector<vector<Point>> conPoly(contours.size());
	vector<Rect>boundRect(contours.size());;

	for (int i = 0; i < contours.size(); i++) {

		int area = contourArea(contours[i]);
		string objText;
		cout << "Area of " << i << " contour is: " << area << endl;

		if (area > 1000) {
			/*float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);*/
			approxPolyDP(contours[i], conPoly[i], 5, true);  //more accurate

			drawContours(img, conPoly, i, Scalar(0, 0, 0), 2);
			//drawContours(img, contours, i, Scalar(0, 0, 0), 2);

			cout << "Contour points: "<<conPoly[i].size() << endl;

			boundRect[i] = boundingRect(conPoly[i]);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 0, 0), 5);
			
			int  objCor = (int)conPoly[i].size();
			if (objCor == 3) {
				objText = "Triangle";
			}
			else if (objCor == 4) {
				float aspRatio = (float)boundRect[i].width/(float)boundRect[i].height;
				if(aspRatio>0.95&&aspRatio<1.05){
					objText = "Square";
				}
				else {
					objText = "Rectangle";
				}
			}
			else {
				objText = "Circle";
			}
			putText(img,objText,{boundRect[i].x,boundRect[i].y-5}, FONT_HERSHEY_PLAIN, 1, Scalar(191, 105, 19), 1);
		}
	}
}

int main() {
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;

	//preprocessing before getting the contours
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 20, 75);
	 
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	getContour(imgDil, img);

	imshow("Image", img);
	//imshow("Canny Image", imgCanny);
	//imshow("Blurred Image", imgBlur);
	//imshow("Dilated Image", imgDil);
	waitKey(0);

	return 0;
}
