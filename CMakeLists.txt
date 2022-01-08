cmake_minimum_required(VERSION 3.10)

project(Pac-man)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

file(GLOB SRC_FILES
    "${PROJECT_SOURCE_DIR}/include/*.h"
    "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE GLUT::GLUT)
target_link_libraries(${CMAKE_PROJECT_NAME} ${OpenGL_LIBRARY})