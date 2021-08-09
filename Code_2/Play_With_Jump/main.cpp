#include <fstream>
#include <iostream>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;

// 储存滑动条滑块的位置
int g_slider_position = 0;
// 指示变量，在新的跳转触发之后置0。
// 当它为正的时候，指示在停止之前程序要播放多少张图片；
// 当它为负的时候，表示系统处千连续视频播放模式。
int g_run = 1;
// 避免在调整进度条位置的时候触发单步模式。
int g_dontset = 0;

cv::VideoCapture g_cap;

// 用户调整滑动条的时候执行的回调程序。
// pos 表示当前位置，这将会是进度条存在的新的位置。
void onTrackbarSlide(int pos, void *) {
    // cv::CAP_PROP_POS_FRAMES参数指示我们想要帧集合的读取位置。
    // HighGUI 的代码是高度自动化的，所以当一个新的视频位置被请求的时候，
    // 将自动处理一些（诸如请求的帧并非是一个关键帧等）问题。
    // 如果遇到这种情况、它会从请求位置之前的一个关键帧开始播放并且快进到诗求的位置，免得我们考虑这些繁琐的问题。
    g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
    if (!g_dontset)
        g_run = 1;
    g_dontset = 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: exe_name <video path>" << std::endl;
        return -1;
    }

    try {
        cv::namedWindow("Example2_4", cv::WINDOW_AUTOSIZE);
        g_cap.open(string(argv[1]));
        // 使用get来确定总帧数以及视频的高和宽。
        int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT);
        int tmpw = (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
        int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);

        cout << "Video has " << frames << " frames of dimensioms(" << tmpw
             << ", " << tmph << ")." << endl;
        // 创建一个滑动条
        // 第一个参数是名字，第二个参数指定放置滑动条的窗口，
        // 第三个参数绑定一个变量用来指示滑动条滑块的位置数值。
        // 第四个参数指示滑动条的最大值（视频的总帧数）
        // 第五个参数是滑动条移动时候的回调函数（不需要的时候也可以输入NULL) 。
        cv::createTrackbar("Position", "Example2_4", &g_slider_position, frames,
                           onTrackbarSlide);

        cv::Mat frame;
        while (true) {
            if (g_run != 0) {
                g_cap >> frame;
                // 检查有没有数据的另一种方式
                if (!frame.data)
                    break;
                int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
                // 使下一个滑动条的回调函数不会让我们进入单步模式
                g_dontset = 1;
                // 委托滑动条的回调函数来更新滑动块在滑动条上的位置以便显示给用户。
                cv::setTrackbarPos("Position", "Example2_4", current_pos);
                cv::imshow("Example2_4", frame);
                // 让我们保持单步模式或者依据用户的设置让视频正常播放。
                g_run -= 1;
            }
            char c = (char)cv::waitKey(10);
            // 单帧模式
            if (c == 's') {
                g_run = 1;
                cout << "Single step, run = " << g_run << endl;
            }
            // 播放模式
            else if (c == 'r') {
                g_run = -1;
                cout << "Run mode, run = " << g_run << endl;
            } 
            //  Esc被按下，提前终止
            else if (c == 27)
                break;
        }

        cv::destroyWindow("Example2_4");
        std::cout << "Suceess" << std::endl;
    } catch (...) {
        std::cout << "Error" << std::endl;
        return -1;
    }
    return 0;
}