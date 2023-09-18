cmake_minimum_required(VERSION 3.24)
project(Code)

set(CMAKE_CXX_STANDARD 17)

add_executable(Code main.cpp generator.cpp struct.h generator.h algorithm.cpp algorithm.h grafics.cpp grafics.h)
