#include "yolo.h"
#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 配置参数
    Config config;
    config.onnx_path = "D:/OpenvinoPro/v5_async/models/yolov5n.onnx";
    config.class_names_path = "D:/OpenvinoPro/v5_async/classes.txt";
    config.confThreshold = 0.25f;
    config.nmsThreshold = 0.45f;
    config.scoreThreshold = 0.25f;
    config.inpWidth = 640;
    config.inpHeight = 640;

    YOLOV5 detector(config);

    cv::Mat image = cv::imread("test.jpg"); // 替换为你的测试图片路径
    if (image.empty()) {
        std::cerr << "Failed to load image!" << std::endl;
        return -1;
    }

    detector.detect(image);

    cv::imshow("YOLOv5 Test", image);
    cv::waitKey(0);
    return 0;
}
