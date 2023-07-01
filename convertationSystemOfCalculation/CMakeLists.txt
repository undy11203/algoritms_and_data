cmake_minimum_required(VERSION 3.5.1)
project(lab0 C)

set(SRC src/main.c "src/translateInSys.h" "src/translateInSys.c")

add_executable(${PROJECT_NAME} ${SRC}   "src/translateInSys.h" "src/translateInSys.c")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../modules")
include(common_lab)
