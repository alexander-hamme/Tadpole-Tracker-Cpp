cmake_minimum_required(VERSION 3.12)
project(Sproj_Cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(/home/alex/Applications/googletest-master/googletest/include /home/alex/Applications/googletest-master/googletest)

add_executable(Sproj_Cpp main.cpp src/Animal.cpp src/Animal.h src/CircularPointsQueue.cpp
        src/CircularPointsQueue.h test/testCircularPointsQueue.cpp test/testCircularPointsQueue.h)

target_link_libraries(Sproj_Cpp gtest gtest_main)
