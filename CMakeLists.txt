cmake_minimum_required(VERSION 3.6)

project(NuakeRenderer)

set(HEADERS src/NuakeRenderer.h )

set(SOURCES src/NuakeRenderer.cpp )

add_library(NuakeRenderer ${SOURCES} ${HEADERS})