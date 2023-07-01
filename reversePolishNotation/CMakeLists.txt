cmake_minimum_required(VERSION 3.5.1)
project(lab4 C)

set(SRC src/main.c "src/Stack.h" "src/Stack.c" "src/Eval.c" "src/Eval.h" "src/Input.c" "src/Input.h" "src/CalcWithRPN.c" "src/CalcWithRPN.h" "src/Priority.c" "src/Priority.h")

add_executable(${PROJECT_NAME} ${SRC} "src/Stack.c" "src/Stack.h"  "src/Eval.c" "src/Eval.h" "src/Input.c" "src/Input.h"   "src/CalcWithRPN.c" "src/CalcWithRPN.h" "src/Priority.c" "src/Priority.h")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../modules")
include(common_lab)
