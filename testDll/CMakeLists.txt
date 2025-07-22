cmake_minimum_required(VERSION 3.14)

project(testDll)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# OpenCV 路径
set(OpenCV_DIR "D:/lib/OpenCV/OpenCV4.8.0_CUDA/x64/vc17/lib")
# OpenVINO 路径
set(OpenVINO_DIR "D:/lib/openvino_toolkit")

include_directories(
    ${PROJECT_SOURCE_DIR}/../include
    ${OpenCV_DIR}/include
    ${OpenVINO_DIR}/runtime/include
)

find_package(OpenCV REQUIRED NO_DEFAULT_PATH PATHS ${OpenCV_DIR})
link_directories(
    ${OpenVINO_DIR}/runtime/lib/intel64/Debug
    ${OpenVINO_DIR}/runtime/lib/intel64/Release
    ${PROJECT_SOURCE_DIR}/../build/Release
    ${PROJECT_SOURCE_DIR}/../build/Debug
)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    set(OpenVINO_LIB "${OpenVINO_DIR}/runtime/lib/intel64/Debug/openvinod.lib")
    set(YOLOV5DLL_LIB "${PROJECT_SOURCE_DIR}/../build/Debug/yolov5.lib")
else()
    set(OpenVINO_LIB "${OpenVINO_DIR}/runtime/lib/intel64/Release/openvino.lib")
    set(YOLOV5DLL_LIB "${PROJECT_SOURCE_DIR}/../build/Release/yolov5.lib")
endif()

add_executable(testDll testDll.cpp)
target_include_directories(testDll PRIVATE ../include)
target_link_libraries(testDll PRIVATE ${YOLOV5DLL_LIB} ${OpenCV_LIBS} ${OpenVINO_LIB})
