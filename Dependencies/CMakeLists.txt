project(glad)
include_directories(glad/include/)
add_library(glad glad/src/glad.c)

include_directories(glfw/include/)
add_subdirectory(glfw)

