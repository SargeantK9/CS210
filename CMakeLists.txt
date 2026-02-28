cmake_minimum_required(VERSION 4.1)
project(clock_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(clock_project main.cpp
        functions.h
        functions.cpp)
