#pragma once

#include <string>

struct Config {
	float confThreshold;
	float nmsThreshold;
	float scoreThreshold;
	int inpWidth;
	int inpHeight;
	std::string onnx_path;
    std::string class_names_path;
};

// 加载默认配置（或从文件读取）
Config loadConfig();