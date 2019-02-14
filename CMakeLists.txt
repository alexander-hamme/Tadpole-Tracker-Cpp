cmake_minimum_required(VERSION 3.12)
project(Sproj_Cpp)

set(CMAKE_CXX_STANDARD 11)

include_directories(/home/alex/Applications/googletest-master/googletest/include /home/alex/Applications/googletest-master/googletest)

#include_directories(/home/alex/Documents/coding/c/Sproj_Cpp/libs/darknet/include /home/alex/Documents/coding/c/Sproj_Cpp/libs/darknet/src)


add_executable(Sproj_Cpp src/animal.cpp src/animal.h src/util/circular_buffer.cpp
        src/util/circular_buffer.h test/test_circular_buffer.cpp test/test_circular_buffer.h src/util/bounding_box.h src/util/mini_cmath.h src/util/detections_parser.cpp src/util/detections_parser.h src/yolo/yolo_container.cpp src/yolo/yolo_container.h)

#SET(OpenCV_DIR /usr/local)

target_link_libraries(Sproj_Cpp gmock gtest gtest_main pthread)
