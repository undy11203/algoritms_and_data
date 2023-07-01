cmake_minimum_required(VERSION 3.5.1)
project(lab7 C)

set(SRC src/main.c "src/Input.c" "src/Input.h" "src/Graph.c" "src/Graph.h" "src/Output.c" "src/Output.h")

add_executable(${PROJECT_NAME} ${SRC}  "src/Input.c"  "src/Graph.c" "src/Graph.h" "src/Output.c" "src/Output.h")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../modules")
include(common_lab)
