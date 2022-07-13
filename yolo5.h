#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <opencv4/opencv2/dnn.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include<time.h>
using namespace cv;
using namespace dnn;
using namespace std;
struct Output {
    int id;//结果类别id
    float confidence;//结果置信度
    cv::Rect box;//矩形框
};

class YOLO
{
public:
    YOLO() {};
    bool readModel(Net &net, string &netPath, bool isCuda = false);
    bool Detect(cv::Mat &SrcImg, cv::dnn::Net &net, std::vector<Output> &output);
    void drawPred(cv::Mat &img, std::vector<Output> result, std::vector<cv::Scalar> color);
private:
    //计算归一化函数
    float Sigmoid(float x) {
        return static_cast<float>(1.f / (1.f + exp(-x)));
    }
    const float netAnchors[3][6] = { { 10,13, 16,30, 33,23},{ 30,61, 62,45, 59,119 },{ 116,90, 156,198, 373,326} };
    const float netStride[3] = { 8.0, 16.0, 32.0 };
    const int netWidth = 640;
    const int netHeight = 640;
    float nmsThreshold = 0.2;
    float boxThreshold = 0.5;
    float classThreshold = 0.7;
    std::vector<std::string> className = {"blue", "red", "2", "4", "7", "8", "3", "1", "5"};
};
