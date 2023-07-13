cmake_minimum_required(VERSION 3.5.1)
project(bubbleSort C)

set(SRC src/main.c "src/BFS.c" "src/BFS.h")

add_executable(${PROJECT_NAME} ${SRC} "src/BFS.c" "src/BFS.h")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../modules")