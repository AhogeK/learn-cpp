cmake_minimum_required(VERSION 3.20)
project(learn_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB CPP_CRASH_COURSE *.cpp crash-course/part-1/*.cpp crash-course/part-1/*.h)

add_executable(learn_cpp ${CPP_CRASH_COURSE})

# CRASH COURSE
add_executable(listing_1_1 crash-course/part-one/listing_1_1.cpp)
add_executable(listing_1_2 crash-course/part-one/listing_1_2.cpp)
add_executable(listing_1_4 crash-course/part-one/listing_1_4.cpp)
add_executable(listing_1_7 crash-course/part-one/listing_1_7.cpp)
add_executable(listing_1_8 crash-course/part-one/listing_1_8.cpp)
add_executable(exercise_1_1 crash-course/part-one/exercise_1_1.cpp)
add_executable(exercise_1_4 crash-course/part-one/exercise_1_4.cpp)

# External
add_executable(strlen_test external/imooc/414/string/strlen_test.cpp)
add_executable(strcmp_test external/imooc/414/string/strcmp_test.cpp)
add_executable(strcpy_test external/imooc/414/string/strcpy_test.cpp)
add_executable(string_test external/imooc/414/string/string_test.cpp)
add_executable(memory_cells_address_test external/imooc/414/memory_cells_address_test.cpp)
add_executable(pointer_array_test external/imooc/414/pointer_array_test.cpp)
add_executable(const_pointer_test external/imooc/414/const_pointer_test.cpp)
add_executable(double_pointer_test external/imooc/414/double_pointer_test.cpp)
add_executable(illegal_pointer_test external/imooc/414/illegal_pointer_test.cpp)
add_executable(pointer_increment_test external/imooc/414/pointer_increment_test.cpp)
add_executable(memory_layout_test external/imooc/414/memory_layout_test.cpp)
add_executable(raii_test external/imooc/414/raii_test.cpp)
add_executable(stack_heap_test external/imooc/414/stack_heap_test.cpp)
add_executable(autoptr_test external/imooc/414/autoptr_test.cpp)
add_executable(unique_ptr_test external/imooc/414/unique_ptr_test.cpp)
add_executable(shared_ptr_test external/imooc/414/shared_ptr_test.cpp)
add_executable(week_ptr_test external/imooc/414/week_ptr_test.cpp)
add_executable(circular_dependency_test external/imooc/414/circular_dependency_test.cpp)
add_executable(reference_test external/imooc/414/reference_test.cpp)
add_executable(enum_test external/imooc/414/enum_test.cpp)
add_executable(struct_union_test external/imooc/414/struct_union_test.cpp)
add_executable(data_alignment_test external/imooc/414/data_alignment_test.cpp)