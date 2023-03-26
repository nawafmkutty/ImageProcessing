cmake_minimum_required(VERSION 3.24)
project(ImageProcessing C)

set(CMAKE_C_STANDARD 99)

add_executable(ImageProcessing main.c image.h BMPHandler.h image.c BMPHandler.c)
