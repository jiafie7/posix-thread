cmake_minimum_required(VERSION 3.19)

project(posix-thread)

set(CMAKE_CXX_STANDARD 11)

add_compile_options(-g -O2 -Wall -Werror -Wno-unused)

include_directories(./)

file(GLOB_RECURSE SOURCES "utility/*.cpp" "thread/*.cpp" "task/*.cpp")

add_executable(thread_main_1 ${SOURCES} thread_main_1.cpp)
add_executable(thread_main_2 ${SOURCES} thread_main_2.cpp)

add_executable(mutex_main_1 ${SOURCES} mutex_main_1.cpp)
add_executable(mutex_main_2 ${SOURCES} mutex_main_2.cpp)

add_executable(cond_main_1 ${SOURCES} cond_main_1.cpp)
add_executable(cond_main_2 ${SOURCES} cond_main_2.cpp)

add_executable(main ${SOURCES} main.cpp)
