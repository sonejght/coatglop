cmake_minimum_required(VERSION 3.8)

project(glad LANGUAGES C CXX)

add_library(${PROJECT_NAME} src/gl.c)

target_include_directories(${PROJECT_NAME} PUBLIC include)
