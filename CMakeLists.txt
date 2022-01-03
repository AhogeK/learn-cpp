cmake_minimum_required(VERSION 3.20)
project(learn_cpp)

set(CMAKE_CXX_STANDARD 17)


file(GLOB CPP_CRASH_COURSE *.cpp crash-course/part-1/*.cpp crash-course/part-1/*.h)

add_executable(learn_cpp ${CPP_CRASH_COURSE})

add_executable(strlen_test external/strlen_test.cpp)
add_executable(strcmp_test external/strcmp_test.cpp)
add_executable(strcpy_test external/strcpy_test.cpp)
add_executable(string_test external/string_test.cpp)
add_executable(memory_cells_address_test external/memory_cells_address_test.cpp)
add_executable(pointer_array_test external/pointer_array_test.cpp)