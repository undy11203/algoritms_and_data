cmake_minimum_required(VERSION 3.5.1)
project(lab2 C)

set(SRC src/main.c "src/swapperNair.h" "src/swapperNair.c" "src/outputResult.h" "src/outputResult.c")

add_executable(${PROJECT_NAME} ${SRC} "src/swapperNair.h" "src/swapperNair.c" "src/outputResult.h" "src/outputResult.c")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../modules")
include(common_lab)
