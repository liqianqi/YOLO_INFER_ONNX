#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;


int main()
{
    Mat img = imread("/home/liqianqi/SVM/5828124.jpg");

    if(img.empty())
    {
        cout << "the image is empty !" << endl;
        return -1;
    }


    // waitKey(0);

    Mat gray;
    Mat gray1;
    Mat vector_mat[3];
    cv::split(img,vector_mat);

    gray1 = vector_mat[0] - 1*vector_mat[2];

    cvtColor(img,gray,COLOR_BGR2GRAY);

    threshold(gray,gray,130,255,THRESH_BINARY_INV);

    threshold(gray1,gray1,127,255,THRESH_BINARY);

    gray = gray & gray1;

//    Mat element = getStructuringElement(cv::MORPH_RECT, cv::Size(7, 7));
//    dilate(gray,gray,element);

    vector<std::vector<cv::Point>> contours;
    vector<cv::Vec4i> hierarchy;

    findContours(gray,contours,hierarchy,RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);

    cout << contours.size() << endl;
    drawContours(img,contours,-1,Scalar(0,0,255),1);

    RotatedRect rect;

    for(unsigned long i = 0; i < contours.size();i++)
    {
        double area = contourArea(contours[i]);

        if(area < 200)
        {
            continue ;
        }

        cout << area << endl;

        rect = minAreaRect(contours[i]);

        float width = rect.size.width;
        float height = rect.size.height;

        Point2f left_up_conor = Point2f(rect.center.x - height/2,rect.center.y - width/2);

        rectangle(img,left_up_conor,Point(left_up_conor.x + height,left_up_conor.y+width),Scalar(0,255,0));
    }


    imshow("gray",gray);
    imshow("color",img);
    waitKey(0);

    //cv::VideoWriter writer;




}
