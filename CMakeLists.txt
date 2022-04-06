cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)
project(FemWorker)

add_subdirectory(worker-src)
add_subdirectory(demo)