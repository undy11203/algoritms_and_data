cmake_minimum_required(VERSION 3.5.1)
project(lab5 C)

set(SRC src/main.c "src/Decode.c" "src/Decode.h" "src/Encode.c" "src/Encode.h" "src/Free.c" "src/Free.h" "src/Read.c" "src/Read.h" "src/StructsAndTypes.c" "src/StructsAndTypes.h" "src/Write.c" "src/Write.h")

add_executable(${PROJECT_NAME} ${SRC} "src/Decode.c" "src/Decode.h" "src/Encode.c" "src/Encode.h" "src/Free.c" "src/Free.h" "src/Read.c" "src/Read.h" "src/StructsAndTypes.c" "src/StructsAndTypes.h" "src/Write.c" "src/Write.h")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../modules")
include(common_lab)
