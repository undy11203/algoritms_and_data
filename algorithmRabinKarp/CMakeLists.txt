cmake_minimum_required(VERSION 3.5.1)
project(lab1-1 C)

set(SRC src/main.c "src/algoritmRobinKarp.h" "src/algoritmRobinKarp.c")

add_executable(${PROJECT_NAME} ${SRC} "src/algoritmRobinKarp.h" "src/algoritmRobinKarp.c")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../modules")
include(common_lab)
