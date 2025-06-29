cmake_minimum_required(VERSION 3.14)
project(yolov5_async_onnx)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==============================
# 设置 OpenCV 和 OpenVINO 路径
# ==============================
set(OpenCV_DIR "D:/lib/OpenCV/OpenCV4.8.0_CUDA")
set(OpenVINO_DIR "D:/lib/openvino_toolkit")

# ==============================
# 包含目录
# ==============================
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${OpenCV_DIR}/include)
include_directories(${OpenVINO_DIR}/runtime/include)

# ==============================
# 查找 OpenCV
# ==============================
find_package(OpenCV REQUIRED NO_DEFAULT_PATH PATHS ${OpenCV_DIR})
message(STATUS "Using OpenCV: ${OpenCV_INCLUDE_DIRS}")

# ==============================
# 设置 OpenVINO 库路径
# ==============================
link_directories(
    ${OpenVINO_DIR}/runtime/lib/intel64/Debug
    ${OpenVINO_DIR}/runtime/lib/intel64/Release
)

# ==============================
# 根据构建类型选择正确的 OpenVINO lib
# ==============================
if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    set(OpenVINO_LIB "${OpenVINO_DIR}/runtime/lib/intel64/Debug/openvinod.lib")
else()
    set(OpenVINO_LIB "${OpenVINO_DIR}/runtime/lib/intel64/Release/openvino.lib")
endif()

# ==============================
# 添加可执行文件
# ==============================
add_executable(yolov5_async_onnx main.cpp src/yolo.cpp src/config.cpp)

# ==============================
# 链接库
# ==============================
target_link_libraries(yolov5_async_onnx PRIVATE ${OpenCV_LIBS} ${OpenVINO_LIB})

# 静态库
add_library(yolov5_static STATIC src/yolo.cpp src/config.cpp)
set_target_properties(yolov5_static PROPERTIES OUTPUT_NAME "yolov5")
target_link_libraries(yolov5_static PRIVATE ${OpenCV_LIBS} ${OpenVINO_LIB})

# 动态库
add_library(yolov5_shared SHARED src/yolo.cpp src/config.cpp)
set_target_properties(yolov5_shared PROPERTIES OUTPUT_NAME "yolov5")
target_link_libraries(yolov5_shared PRIVATE ${OpenCV_LIBS} ${OpenVINO_LIB})
