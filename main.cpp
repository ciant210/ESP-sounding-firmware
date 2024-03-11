/* face tracking PC application SDK */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include "detection/face_detector.h"
#include "face_tracker.h"

#include <string>
#include <sstream>

using std::vector;
using namespace cv;
using namespace std;

typedef struct {
	std::vector<int> id_vector;
	std::vector<cv::Mat> img_vector;
} TrackData;

void DrawDetection(cv::Mat& img, std::vector<FaceInfo> boxes){
	if (boxes.size() == 0) {
		//cv::imshow("image", img);
	}
	else {
		for (int i = 0; i < boxes.size(); i++) {
			cv::Point topleft;
			cv::Point bottomright;
			topleft.x = boxes[i].x1;
			topleft.y = boxes[i].y1;
			bottomright.x = boxes[i].x2;
			bottomright.y = boxes[i].y2;
			std::cout << topleft.x << std::endl;
			cv::rectangle(img, topleft, bottomright, cv::Scalar(255, 0, 0), 2, cv::LINE_8);
			cv::imshow("image", img);
		}
	}
}
