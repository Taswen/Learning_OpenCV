#include <iostream>

#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: opencv_test <image path>" << std::endl;
        return -1;
    }

    try {
        // 载入影像，其会根据文件名来决定载入图像格式的处理，并申请内存。
        // 支持的格式：BMP, DIP, JPEG, JPE, PNG, PBM, PGM, PPM, SR, RAS 以及TIFF
        // 。 函数会返回一个cv::Mat
        // 结构，OpenCV使用这个结构来处理所有类型的图像：单通道、多通道、整型、浮点数以及各种类型。
        //
        Mat img = imread(argv[1], -1);
        // 检测图像有没有被真载入。
        if (img.empty()) {
            std::cout << "Need a Picture" << std::endl;
            return -1;
        }
        // 打开窗口以显示图像。
        // 参数：标题名，Flags
        // 标题名指定了窗口的标题，未来HighGUI的和这个窗口的交互函数将由这个名称来指定要与哪个窗口交互。
        // WINDOW_AUTOSIZE 表示窗口大小和图像大小一致。
        namedWindow("Example1", WINDOW_AUTOSIZE);
        // cv::imshow()
        // 将建一个窗口（如果这个窗口不存在，它会自动调用cv::namedWindow()
        // 新建一个窗口）。 在调用cv: :imshow()
        // 的时候，窗口将被重绘上要求的图片，并且窗口会按照要求自动调整大小（如果使用cv::WINDOW_AUTOSIZE参数）。
        imshow("Example1", img);
        // 系统暂停并且等待键盘事件。如果其传入了一个大于零的参数，
        // 它将会等待等同千该参数的毫秒时间，然后继续执行程序。
        // 如果参数被设置为0或者一个负数，程序将会无限等待直到有键被按下。
        waitKey(0);
        // 图像将会在生命周期结束的时候自动释放，其行为类似于标准模板库( STL) 中的容器类。这种自动的内存释放由内部的引用指针所控制
        // 可以让窗口自行销毁。也可以调用cv:: destroyWindow()关闭窗口并且释放掉相关联的内存空间。
        destroyWindow("Example1");
        std::cout << "Suceess" << std::endl;
    } catch (...) {
        std::cout << "Error" << std::endl;
        return -1;
    }
    return 0;
}