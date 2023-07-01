cmake_minimum_required(VERSION 3.5.1)
project(lab3-1 C)

set(SRC src/main.c "src/quickSort.h" "src/quickSort.c")

add_executable(${PROJECT_NAME} ${SRC} "src/quickSort.h" "src/quickSort.c")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../modules")
include(common_lab)
