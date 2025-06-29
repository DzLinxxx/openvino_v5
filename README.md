YOLOv5 + OpenVINO 推理系统（ONNX 类封装）

** 功能

- 支持 ONNX 模型直接加载
- OpenVINO 推理
- 类封装：`yolo.h` + `yolo.cpp`
- 主函数抽帧控制（降低资源占用）
- 参数集中管理（`config.h`）
- OpenCV 实时显示检测框

** 编译要求

- OpenCV >= 4.5
- OpenVINO Version: 2023.2.0
- C++14 

** 编译步骤（Linux）

```bash
unzip yolov5_openvino_onnx_async_class.zip
cd yolov5_openvino_onnx_async_class
mkdir build && cd build
cmake ..
make



** 编译步骤（windows）

```bash
unzip yolov5_openvino_onnx_async_class.zip
cd yolov5_openvino_onnx_async_class
mkdir build && cd build
cmake ..
cmake --build . --config Release

** 执行程序记得修改配置文件