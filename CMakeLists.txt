cmake_minimum_required(VERSION 3.20)
project(learn_cpp)

set(CMAKE_CXX_STANDARD 20)


file(GLOB CPP_CRASH_COURSE *.cpp crash-course/part-1/*.cpp crash-course/part-1/*.h)

add_executable(learn_cpp ${CPP_CRASH_COURSE})

# CRASH COURSE
add_executable(gdb_test crash-course/personal/gdb_test.cpp)

# External
add_executable(strlen_test external/strlen_test.cpp)
add_executable(strcmp_test external/strcmp_test.cpp)
add_executable(strcpy_test external/strcpy_test.cpp)
add_executable(string_test external/string_test.cpp)
add_executable(memory_cells_address_test external/memory_cells_address_test.cpp)
add_executable(pointer_array_test external/pointer_array_test.cpp)
add_executable(const_pointer_test external/const_pointer_test.cpp)
add_executable(double_pointer_test external/double_pointer_test.cpp)
add_executable(illegal_pointer_test external/illegal_pointer_test.cpp)
add_executable(pointer_increment_test external/pointer_increment_test.cpp)
add_executable(memory_layout_test external/memory_layout_test.cpp)
add_executable(raii_test external/raii_test.cpp)
add_executable(stack_heap_test external/stack_heap_test.cpp)
add_executable(autoptr_test external/autoptr_test.cpp)
add_executable(unique_ptr_test external/unique_ptr_test.cpp)
add_executable(shared_ptr_test external/shared_ptr_test.cpp)
add_executable(week_ptr_test external/week_ptr_test.cpp)
add_executable(circular_dependency_test external/circular_dependency_test.cpp)
add_executable(reference_test external/reference_test.cpp)
add_executable(enum_test external/enum_test.cpp)
add_executable(struct_union_test external/struct_union_test.cpp)