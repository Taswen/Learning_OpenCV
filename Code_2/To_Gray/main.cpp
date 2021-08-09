#include <opencv2/opencv.hpp>



int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: exe_name <image path>" << std::endl;
        return -1;
    }


    try {
        cv::Mat img_rgb, img_gry, img_cny;
        // 创建两个窗口
        cv::namedWindow("E2_7 Gray", cv::WINDOW_AUTOSIZE);
        cv::namedWindow("E2_7 Canny", cv::WINDOW_AUTOSIZE);

        img_rgb = cv::imread(argv[1]);
        if (img_rgb.empty()) {
            std::cout << "Need a Picture" << std::endl;
            return -1;
        }


        cv::cvtColor(img_rgb, img_gry,cv::COLOR_BGR2GRAY);
        cv::imshow("E2_7 Gray",img_gry);

        cv::Canny(img_gry, img_cny, 10, 100, 3,true);
        cv::imshow("E2_7 Canny",img_cny);
        cv::waitKey(0);
        std::cout << "Suceess" << std::endl;
    } catch (...) {
        std::cout << "Error" << std::endl;
        return -1;
    }
    return 0;
}