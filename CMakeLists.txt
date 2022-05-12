cmake_minimum_required(VERSION 3.6)

project(NuakeRenderer)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/../cmake/modules/" ${CMAKE_MODULE_PATH})
set(GLAD_LIB_DIR glad)

set(HEADERS 
	NuakeRenderer/NuakeRenderer.h NuakeRenderer/Window.h 
	NuakeRenderer/Math.h 
	NuakeRenderer/VertexBuffer.h
	NuakeRenderer/VertexArray.h
	NuakeRenderer/VertexBufferLayout.h
	NuakeRenderer/Shader.h
	NuakeRenderer/ShaderRegistry.h
	NuakeRenderer/Texture.h
	NuakeRenderer/Framebuffer.h
)

set(SOURCES 
	NuakeRenderer/NuakeRenderer.cpp NuakeRenderer/Window.cpp 
	NuakeRenderer/Vendors/glm/glm/glm.hpp 
	NuakeRenderer/VertexBuffer.cpp NuakeRenderer/VertexArray.cpp
	NuakeRenderer/ShaderRegistry.cpp
	NuakeRenderer/Shader.cpp
	NuakeRenderer/Texture.cpp
	NuakeRenderer/Framebuffer.cpp
)

add_subdirectory(./Dependencies ${CMAKE_CURRET_BINARY_DIR}/Dependencies)
add_library(NuakeRenderer STATIC ${SOURCES} ${HEADERS})

target_include_directories(NuakeRenderer PUBLIC Dependencies/glad/include)
target_link_libraries(NuakeRenderer PUBLIC glad glfw imgui)