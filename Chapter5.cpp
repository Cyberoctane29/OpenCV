#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;

//warping a pic

float w = 250, h = 350;
Mat matrix, matrix1, matrix2, matrix3, matrix4, imgWrap, imgWrap1, imgWrap2, imgWrap3, imgWrap4;

void main() {

	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	//K card
	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} }; //source object in the image
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };    //destination points of the image(top-view image) 

	//J card
	Point2f src1[4] = { {778,106},{1021,85},{840,350},{1114,330} }; //source object in the image
	Point2f dst1[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };    //destination points of the image(top-view image) 

	//Q card
	Point2f src2[4] = { {65,324},{340,280},{94,633},{400,573} };
	Point2f dst2[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	//9D
	Point2f src3[4] = { {742,385},{1021,438},{647,708},{967,781} };
	Point2f dst3[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix = getPerspectiveTransform(src, dst);  //will give us a matrix where if input values are given,returns the transformed values
	matrix1 = getPerspectiveTransform(src1, dst1);
	matrix2 = getPerspectiveTransform(src2, dst2);
	matrix3 = getPerspectiveTransform(src3, dst3);

	warpPerspective(img, imgWrap, matrix, Point(w, h)); //to create the image
	warpPerspective(img, imgWrap1, matrix1, Point(w, h));
	warpPerspective(img, imgWrap2, matrix2, Point(w, h));
	warpPerspective(img, imgWrap3, matrix3, Point(w, h));

	//for adding circles to the points we mentioned in src arrays
	for (int i = 0; i < 4; i++) {
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
		circle(img, src1[i], 10, Scalar(0, 0, 255), FILLED);
		circle(img, src2[i], 10, Scalar(0, 0, 255), FILLED);
		circle(img, src3[i], 10, Scalar(0, 0, 255), FILLED);

	}

	imshow("Image", img);
	imshow("Wrapped Image", imgWrap);
	imshow("Wrapped Image1", imgWrap1);
	imshow("Wrapped Image2", imgWrap2);
	imshow("Wrapped Image3", imgWrap3);

	waitKey(0);

}