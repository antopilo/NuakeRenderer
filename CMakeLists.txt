cmake_minimum_required(VERSION 3.6)

project(NuakeRenderer)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/../cmake/modules/" ${CMAKE_MODULE_PATH})
set(GLAD_LIB_DIR glad)

set(HEADERS src/NuakeRenderer.h src/Window.h)

set(SOURCES src/NuakeRenderer.cpp src/Window.cpp)
add_subdirectory(./Dependencies ${CMAKE_CURRET_BINARY_DIR}/Dependencies)

add_library(NuakeRenderer ${SOURCES} ${HEADERS})

include_directories(PUBLIC ./Dependencies/glad/include/ ./Dependencies/glfw/include/)
target_link_libraries(NuakeRenderer PUBLIC glad glfw)