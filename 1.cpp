#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

void onMouse(int event, int x, int y, int flags, void* param) {

    cv::Mat *im = reinterpret_cast<cv::Mat*>(param);

    switch (event) {	// dispatch the event

    case cv::EVENT_LBUTTONDOWN: // 鼠标左键按下

        cout << "imagePoint2d   x: " << x << "   y: " << y << endl;

        break;
    }
}

int main() {

    cv::Mat image; // 新建一个空图

    cv::Mat image1;
    // 读取图像并转化为灰度图
    image = cv::imread("/home/liqianqi/BinocularWorld/test/7548.jpg");

    image1 = cv::imread("/home/liqianqi/SVM/5828124.jpg");
    //输出图像的长和宽
    cout << "This image is " << image.rows << " x "
        << image.cols << endl;
    //输出图像的通道数
    cout << "This image has "
        << image.channels() << " channel(s)" << endl;

    // 创建一个窗口，窗口名称为"Original Image"
    cv::namedWindow("Original Image"); // 命名
    cv::namedWindow("Original Image1"); // 命名

    cv::imshow("Original Image", image); // 显示原始图像

    cv::imshow("Original Image1",image1);

    // set the mouse callback for this image
    cv::setMouseCallback("Original Image", [](int event, int x, int y, int flags, void* param){
        cv::Mat *im = reinterpret_cast<cv::Mat*>(param);

        switch (event) {	// dispatch the event

        case cv::EVENT_LBUTTONDOWN: // 鼠标左键按下

            cout << "imagePoint2d_left   x: " << x << "   y: " << y << endl;

            break;
        }
    }, reinterpret_cast<void*>(&image));

    cv::setMouseCallback("Original Image1", [](int event, int x, int y, int flags, void* param){
        cv::Mat *im = reinterpret_cast<cv::Mat*>(param);

        switch (event) {	// dispatch the event

        case cv::EVENT_LBUTTONDOWN: // 鼠标左键按下

            cout << "imagePoint2d_right   x: " << x << "   y: " << y << endl;

            break;
        }
    }, reinterpret_cast<void*>(&image1));

    cv::waitKey(0); // 按任何键结束

    return 0;
}







