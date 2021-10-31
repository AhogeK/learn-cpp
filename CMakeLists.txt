cmake_minimum_required(VERSION 3.20)
project(learn_cpp)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES *.cpp part_1/*.cpp part_1/*.h part_1/*.cuh)

add_executable(learn_cpp ${SOURCES})
