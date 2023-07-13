cmake_minimum_required(VERSION 3.5.1)
project(bubbleSort C)

set(SRC src/main.c "src/bubbleSort.c" "src/bubbleSort.h")

add_executable(${PROJECT_NAME} ${SRC} "src/bubbleSort.c" "src/bubbleSort.h")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../modules")