#include "yolo.h"
#include <string>
#include <opencv2/opencv.hpp>

int main(int argc, char const *argv[]) {
    try {
        // 视频路径
        std::string video_path = "C:\\Users\\24351\\Videos\\2.mp4";
        cv::VideoCapture cap(video_path);
        if (!cap.isOpened()) {
            std::cerr << "Failed to open video file: " << video_path << std::endl;
            return EXIT_FAILURE;
        }

        // 加载模型配置
        Config config = loadConfig();
        YOLOV5 yolomodel(config);

        cv::Mat frame;
        int frame_id = 0;
        int skip_frame_interval = 8;  // 每隔 N 帧进行一次检测
        int detect_id = 0;

        while (cap.read(frame)) {
            if (frame.empty()) break;

            if (frame_id % skip_frame_interval == 0) {
                yolomodel.detect(frame);

                // 可视化结果
                std::string window_name = "Detection: " + std::to_string(detect_id++);
                cv::imshow("Detection", frame);
                // cv::imwrite("output/frame_" + std::to_string(detect_id) + ".jpg", frame); // 可选保存结果
            }

            frame_id++;

            if (cv::waitKey(1) == 27) break;  // 按 ESC 退出
        }

        cap.release();
        cv::destroyAllWindows();
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
