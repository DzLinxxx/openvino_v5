#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include"config.h"
#include<opencv2/dnn.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<openvino/openvino.hpp>


struct Resize
{
	cv::Mat resized_image;
	int dw;
	int dh;
};

struct Detection {
	int class_id;
	float confidence;
	cv::Rect box;
};

class YOLOV5 {
public:
	YOLOV5(Config config);
	~YOLOV5();
	void detect(cv::Mat& frame);

private:

    std::vector<std::string> classNames;
	float confThreshold;
	float nmsThreshold;
	float scoreThreshold;
	int inpWidth;
	int inpHeight;
	float rx;   // the width ratio of original image and resized image
	float ry;   // the height ratio of original image and resized image
	std::string onnx_path;
    std::string class_names_path;
	Resize resize;
	ov::Tensor input_tensor;
	ov::InferRequest infer_request;
	ov::CompiledModel compiled_model;
	void initialmodel();
	void preprocess_img(cv::Mat& frame);
	void postprocess_img(cv::Mat& frame, float* detections, ov::Shape & output_shape);
};