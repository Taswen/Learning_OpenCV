#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "Usage: exe_name <video file> <output file>" << std::endl 
         << "Or: " << "exe_name <output file>";
        return -1;
    }

    try {
        cv::namedWindow("Example2_11", cv::WINDOW_AUTOSIZE);
        cv::namedWindow("Example2_11 Log_Polar", cv::WINDOW_AUTOSIZE);
        // 打开视频文件或是摄像头进行读取
        cv::VideoCapture cap;
        if(argc ==2){
            cap.open(0);
        }
        else if (argc==3){
            cap.open(argv[1]);
        }
        if(!cap.isOpened()){
            std::cerr << "Could't open anyfile or capture for input." << std::endl;
            return -1;
        }
        double fps = cap.get(cv::CAP_PROP_FPS);

        cv::Size size((int)cap.get(cv::CAP_PROP_FRAME_WIDTH),
                      (int)cap.get(cv::CAP_PROP_FRAME_HEIGHT));

        cv::VideoWriter writer;
        // 第一个参数是新建视频文件的文件名
        // 第二个参数是视频编码方式，指明视频将以何种方式进行压缩。
        writer.open((argc==2)?argv[1] :argv[2] , cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size);
        cv::Mat logpolar_frame, bgr_frame;
        while (true) {
            // 逐帧读取
            cap >> bgr_frame;
            if (bgr_frame.empty())
                break;

            cv::imshow("Example2_11", bgr_frame);
            // 每一帧转换为对数极坐标形式
            cv::logPolar(bgr_frame,      // 输入图像
                         logpolar_frame, // 输出图像
                         cv::Point2f(    // 对数极坐标轴的中心点
                             (float)bgr_frame.cols / 2,  // x
                             (float)bgr_frame.rows / 2), // y
                         40,                      //幅度(比例参数)
                         cv::WARP_FILL_OUTLIERS //对于图像外的区域填充0
            );
            cv::imshow("Example2_11 Log_Polar", logpolar_frame);
            // 将转换的对数极坐标图像写入新的视频文件
            writer << logpolar_frame;
            char c = cv::waitKey(10);
            if (c == 27)
                break;
        }

        writer.release();
        cv::destroyWindow("Example2_11");
        cv::destroyWindow("Example2_11 Log_Polar");
        std::cout << "Suceess" << std::endl;
    } catch (...) {
        std::cout << "Error" << std::endl;
        return -1;
    }
    return 0;
}