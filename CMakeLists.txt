cmake_minimum_required(VERSION 2.8.4)
project(Project02)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    dlist.cpp
    dlist.h
    listtester.cpp)

add_executable(Project02 ${SOURCE_FILES})