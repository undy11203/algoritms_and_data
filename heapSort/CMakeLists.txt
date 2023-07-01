cmake_minimum_required(VERSION 3.5.1)
project(lab3-0 C)

set(SRC src/main.c "src/heapSort.h" "src/heapSort.c")

add_executable(${PROJECT_NAME} ${SRC} "src/heapSort.h" "src/heapSort.c")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../modules")
include(common_lab)
