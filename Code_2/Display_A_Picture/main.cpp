#include <iostream>

#include <opencv2/opencv.hpp>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: opencv_test <image path>" << std::endl;
        return -1;
    }


    try {
        cv::Mat img = cv::imread(argv[1], -1);

        if (img.empty()) {
            std::cout << "Need a Picture" << std::endl;
            return -1;
        }
        cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
        cv::imshow("Example1", img);
        cv::waitKey(0);
        cv::destroyWindow("Example1");
        std::cout << "Suceess" << std::endl;
    } catch (...) {
        std::cout << "Error" << std::endl;
        return -1;
    }
    return 0;
}