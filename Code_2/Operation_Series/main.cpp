#include <opencv2/opencv.hpp>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: exe_name <image path>" << std::endl;
        return -1;
    }

    try {
        cv::Mat img1, img2, img3, img4, img5;
        cv::namedWindow("E2_9 1", cv::WINDOW_AUTOSIZE);
        cv::namedWindow("E2_9 Canny", cv::WINDOW_AUTOSIZE);

        img1 = cv::imread(argv[1], -1);
        if (img1.empty()) {
            std::cout << "Need a Picture" << std::endl;
            return -1;
        }

        cv::imshow("E2_9 1", img1);

        // 高斯模糊以及降采样
        cv::cvtColor(img1, img2, cv::COLOR_BGR2GRAY);
        cv::pyrDown(img2, img3);
        cv::pyrDown(img3, img4);
        cv::Canny(img4, img5, 10, 100, 3, true);

        int x = 16, y = 32;
        cv::Vec3b intensity = img1.at<cv::Vec3b>(y, x);

        uchar blue = intensity[0];
        uchar green = intensity[1];
        uchar red = intensity[2];

        std::cout << "At (x,y) = (" << x << ", " << y
                  << "):(Blue, Green, Red) = (" << (unsigned int)blue << ", "
                  << (unsigned int)green << ", " << (unsigned int)red << ") "
                  << std::endl;

        std::cout << "Gray pixel there is: "
                  << (unsigned int)img2.at<uchar>(y, x) << std::endl;
        x /= 4;
        y /= 4;
        std::cout << "Pyramid2 pixel there is: "
                  << (unsigned int)img4.at<uchar>(y, x) << std::endl;
        img5.at<uchar>(x, y) = 128;
        cv::imshow("E2_9 Canny", img5);

        cv::waitKey(0);
        cv::destroyWindow("E2_9 1");
        cv::destroyWindow("E2_9 Canny");
        std::cout << "Suceess" << std::endl;
    } catch (...) {
        std::cout << "Error" << std::endl;
        return -1;
    }
    return 0;
}