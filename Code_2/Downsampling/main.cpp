#include <opencv2/opencv.hpp>



void smooth(const cv::Mat & img){
    // 创建两个窗口
    cv::namedWindow("E2_5 Input", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("E2_5 Output", cv::WINDOW_AUTOSIZE);

    // 展示输入图片
    cv::imshow("E2_5 Input", img);

    // 平滑后的数据
    cv::Mat out;

    // 平滑处理
    // 高斯滤波 2次
    cv::GaussianBlur(img, out, cv::Size(5,5), 3,3);
    cv::GaussianBlur(out, out, cv::Size(5,5), 3,3);

    // 展示输出图片
    cv::imshow("E2_5 Output", out);

    // 等待按键按下
    cv::waitKey(0);

    // 在对象生命周期结束的时候清理申请的内存。
    cv::destroyWindow("E2_5 Input");
    cv::destroyWindow("E2_5 Output");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: exe_name <image path>" << std::endl;
        return -1;
    }

    try {
        cv::Mat img1, img2;
        cv::namedWindow("E2_6 1", cv::WINDOW_AUTOSIZE);
        cv::namedWindow("E2_6 2", cv::WINDOW_AUTOSIZE);


        img1 = cv::imread(argv[1], -1);
        if (img1.empty()) {
            std::cout << "Need a Picture" << std::endl;
            return -1;
        }

        cv::imshow("E2_6 1", img1);

        // 高斯模糊以及降采样
        cv::pyrDown(img1, img2);
        cv::imshow("E2_6 2", img2);

        cv::waitKey(0);
        cv::destroyWindow("E2_6 1");
        cv::destroyWindow("E2_6 2");
        std::cout << "Suceess" << std::endl;
    } catch (...) {
        std::cout << "Error" << std::endl;
        return -1;
    }
    return 0;
}