cmake_minimum_required(VERSION 3.19)

project(posix-thread)

set(CMAKE_CXX_STANDARD 11)

add_compile_options(-g -O2 -Wall -Werror -Wno-unused)

include_directories(./)

file(GLOB_RECURSE SOURCES "utility/*.cpp" "thread/*.cpp")

add_executable(thread_main_1 ${SOURCES} thread_main_1.cpp)
add_executable(thread_main_2 ${SOURCES} thread_main_2.cpp)
