
include_directories(glad/include/)
add_library(glad STATIC glad/src/glad.c)

include_directories(glfw/include/)
add_subdirectory(glfw)

add_library(imgui STATIC)

target_sources(imgui
               PRIVATE
               imgui/imgui_demo.cpp
               imgui/imgui_draw.cpp
               imgui/imgui_tables.cpp
               imgui/imgui_widgets.cpp
               imgui/imgui.cpp

               PRIVATE
               imgui/backends/imgui_impl_opengl3.cpp
               imgui/backends/imgui_impl_glfw.cpp
)

target_include_directories(imgui
    PUBLIC imgui
    PUBLIC imgui/backends
    )

if(RASPBIAN)
    target_compile_definitions(imgui PUBLIC -D__RASPBIAN__)

    # Do not search for OpenGL on raspbian. Use GLES instead.
    set(USE_GLES ON)
endif()

if(USE_GLES)
    target_compile_definitions(imgui PUBLIC -DIMGUI_IMPL_OPENGL_ES2)

    if(RASPBIAN AND USE_BROADCOM_DRIVER)
        target_link_directories(imgui PUBLIC /opt/vc/lib)
        target_link_libraries(imgui PUBLIC brcmGLESv2 brcmEGL)
    else()
        target_link_libraries(imgui PUBLIC GLESv2)
    endif()
else()
    find_package(OpenGL REQUIRED)
    target_link_libraries(imgui PUBLIC ${OPENGL_LIBRARIES})
endif()

target_link_libraries(imgui PUBLIC glfw ${CMAKE_DL_LIBS})

