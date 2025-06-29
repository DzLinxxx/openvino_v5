#include "config.h"

Config loadConfig() {
    Config config;
    config.confThreshold = 0.4f;
    config.nmsThreshold = 0.4f;
    config.scoreThreshold = 0.25f;
    config.inpWidth = 640;
    config.inpHeight = 640;
    config.onnx_path = "../../models/yolov5n.onnx";
    config.class_names_path = "../../classes.txt";
    return config;
}