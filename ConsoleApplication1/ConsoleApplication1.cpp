// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <opencv2/opencv.hpp>   

#include<iostream>    
#define PI 3.1415926    
#define R 150    
using namespace cv;
using namespace std;

int main() {
	Point center = Point(250, 250);
	Mat img = imread("D:/1.jpg");
	if (!img.data)
	{
		cout << "no image!!" << endl;
	}
	else
		imshow("readphoto",img);

	int temp = 0;
	while (waitKey(60) != 27) {
		temp++;
		temp = temp % 72;
		float �Ƕ� = temp / 18.0 * PI;
		Mat picture(500, 500, CV_8UC3, Scalar(255, 255, 255));
		//  center = Point(palm[0] + 320, palm[2] + 240);    
		//  r = palm[1] / 2;    
		center.x = 250 + R*sin(�Ƕ�);
		center.y = 250 - R*cos(�Ƕ�);
		int r = 20;
		circle(picture, center, r, Scalar(255, 0, 0), -1);

		for (int i = 1; i < 7; i++) {
			�Ƕ� = (temp - 3 * i) / 18.0 * PI;
			r = 20 - i * 2;
			center.x = 250 + R*sin(�Ƕ�);
			center.y = 250 - R*cos(�Ƕ�);
			circle(picture, center, r, Scalar(255, 0, 0), -1);
		}
		string ���� = "Loading...";
		switch ((temp % 36) / 12) {
		case 0:���� = "Opencv3"; break;
		case 1:���� = "Opencv3."; break;
		case 2:���� = "Opencv3.2"; break;
		}
		cv::putText(picture, ����, cv::Point(180, 250), 3, 1, cvScalar(0, 0, 255));

		imshow("Loading...", picture);

	}
}
