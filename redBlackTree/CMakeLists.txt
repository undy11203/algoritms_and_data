cmake_minimum_required(VERSION 3.5.1)
project(lab6-1 C)

set(SRC src/main.c "src/Alloc.h" "src/Alloc.c" "src/Balanced.h" "src/Balanced.c" "src/CheckColor.h" "src/CheckColor.c" "src/Tree.h" "src/Tree.c" "src/Height.c" "src/Height.h" "src/Input.h" "src/Input.c")

add_executable(${PROJECT_NAME} ${SRC} "src/Alloc.h" "src/Alloc.c" "src/Balanced.h" "src/Balanced.c"  "src/CheckColor.h" "src/CheckColor.c" "src/Tree.h" "src/Tree.c" "src/Height.c" "src/Height.h" "src/Input.h" "src/Input.c")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../modules")
include(common_lab)
