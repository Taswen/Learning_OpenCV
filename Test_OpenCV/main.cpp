#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char *argv[]) {
    Mat img = imread("assets/img/woman.jpg");
    imshow("image", img);
    waitKey(0);
    return 0;
}