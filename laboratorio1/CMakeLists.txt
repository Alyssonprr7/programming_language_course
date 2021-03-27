cmake_minimum_required(VERSION 3.17)
project(laboratorio1)

set(CMAKE_CXX_STANDARD 14)

include_directories(question3)

add_executable(laboratorio1
        question3/agenda.cpp
        question3/agenda.h
        question3/main.cpp)
