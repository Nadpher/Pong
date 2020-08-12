cmake_minimum_required (VERSION 3.17)

project ("Pong")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/build")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

add_subdirectory ("src")
