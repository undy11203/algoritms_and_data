cmake_minimum_required(VERSION 3.5.1)
project(lab6-0 C)

set(SRC src/main.c "src/Balanced.c" "src/Balanced.h" "src/Tree.h" "src/AddValue.c" "src/AddValue.h" "src/Height.c" "src/Height.h" "src/Alloc.c" "src/Alloc.h" "src/Input.c" "src/Input.h")

add_executable(${PROJECT_NAME} ${SRC} "src/Balanced.c" "src/Balanced.h" "src/Tree.h" "src/AddValue.c" "src/AddValue.h" "src/Height.c" "src/Height.h" "src/Alloc.c" "src/Alloc.h" "src/Input.c" "src/Input.h")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../modules")
include(common_lab)
