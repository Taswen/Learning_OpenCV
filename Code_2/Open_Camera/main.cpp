#include <iostream>

#include <opencv2/opencv.hpp>

int main(int argc, char *argv[]) {
    try {
        cv::namedWindow("Example2_10", cv::WINDOW_AUTOSIZE);
        cv::VideoCapture cap;
        if(argc == 1 ){
            cap.open(0);
        }else{
            cap.open(argv[1]);
        }
        if(!cap.isOpened()){
            std::cerr << "Could't open capture." << std::endl;
            return -1;
        }
        // 视频帧
        cv::Mat frame;
        while(true){
            // 视频文件会按照帧从视频流中被读取。
            cap >> frame;
            // 检查数据是不是真的从视频中读了出来，如果没有，程序将会退出。
            if(frame.empty()) break;
            // 显示视频帧
            cv::imshow("Example2_10", frame);
            // 等待30毫秒，能让视频以30FPS 的速率播放
            // 一般情况下需要检查cv::VideoCapture结构来确定视频真正的帧率
            if(cv::waitKey(33)>=0) break;            
        }

        cv::destroyWindow("Example2_10");
        std::cout << "Suceess" << std::endl;
    } catch (...) {
        std::cout << "Error" << std::endl;
        return -1;
    }
    return 0;
}