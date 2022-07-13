#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <highgui/highgui_c.h>
#include <iostream>
#include "yolo5.h"

using namespace cv;
using namespace cv::dnn;
using namespace std;

int main()
{
    string img_path = "/home/liqianqi/SVM/armor/0013.png";
    string model_path = "/home/liqianqi/SVM/best.onnx";
    YOLO test;
    Net net;
    if (test.readModel(net, model_path, false))
    {
        cout << "read net ok!" << endl;
    }
    else
    {
        cout << "read net false!" << endl;
        return -1;
    }

    //生成随机颜色
    vector<Scalar> color;
    srand(time(0));
    for (int i = 0; i < 80; i++)
    {
        int b = rand() % 256;
        int g = rand() % 256;
        int r = rand() % 256;
        color.push_back(Scalar(b, g, r));
    }
    vector<Output> result;

    Mat src = imread(img_path);
    Mat img;
    resize(src.clone(),img,Size(640,640));
    imshow("resize",img);

    if (test.Detect(img, net, result))
    {
        test.drawPred(img, result, color);
    }
    else
    {
        cout << "Detect Failed!" << endl;
    }

    //system("pause");
    return 0;
}
