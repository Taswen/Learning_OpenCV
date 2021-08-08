#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: opencv_test <image path>" << std::endl;
        return -1;
    }


    try {
        cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
        cv::VideoCapture cap;
        cap.open(std::string(argv[1]));
        cv::Mat frame;
        int x=0;
        while(true){
            std::cout<< ++x << " "<<std::endl;
            cap >> frame;
            if(frame.empty()) break;
            cv::imshow("Example1", frame);
            if(cv::waitKey(33)>=0) break;            
        }
        cv::destroyWindow("Example1");
        std::cout << "Suceess" << std::endl;
    } catch (...) {
        std::cout << "Error" << std::endl;
        return -1;
    }
    return 0;
}