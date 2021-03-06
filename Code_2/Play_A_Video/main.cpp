#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: opencv_test <image path>" << std::endl;
        return -1;
    }

    try {
        cv::namedWindow("Example2_3", cv::WINDOW_AUTOSIZE);
        // 视频读取结构
        cv::VideoCapture cap;
        // 打开视频文件的路径，读取包含所有的关千这个视频文件可以读取的属性，包括状态信息。
        // 以这样的方式创建以后， cv::VideoCapture结构将会在视频的开头被初始化。
        cap.open(std::string(argv[1]));
        // 视频帧
        cv::Mat frame;
        while(true){
            // 视频文件会按照帧从视频流中被读取。
            cap >> frame;
            // 检查数据是不是真的从视频中读了出来，如果没有，程序将会退出。
            if(frame.empty()) break;
            // 显示视频帧
            cv::imshow("Example2_3", frame);
            // 等待30毫秒，能让视频以30FPS 的速率播放
            // 一般情况下需要检查cv::VideoCapture结构来确定视频真正的帧率
            if(cv::waitKey(33)>=0) break;            
        }

        cv::destroyWindow("Example2_3");
        std::cout << "Suceess" << std::endl;
    } catch (...) {
        std::cout << "Error" << std::endl;
        return -1;
    }
    return 0;
}