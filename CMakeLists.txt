cmake_minimum_required(VERSION 3.20)
project(learn_cpp)

set(CMAKE_CXX_STANDARD 17)


file(GLOB CPP_CRASH_COURSE *.cpp crash-course/part-1/*.cpp crash-course/part-1/*.h)

add_executable(learn_cpp ${CPP_CRASH_COURSE})

add_executable(strlenTest external/strlenTest.cpp)

add_executable(strcmpTest external/strcmpTest.cpp)