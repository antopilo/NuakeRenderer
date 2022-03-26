#include "NuakeRenderer.h"
#include "Window.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

namespace NuakeRenderer
{
    void APIENTRY glDebugOutput(GLenum source,
        GLenum type,
        unsigned int id,
        GLenum severity,
        GLsizei length,
        const char* message,
        const void* userParam)
    {
        // ignore non-significant error/warning codes
        if (id == 131169 || id == 131185 || id == 131218 || id == 131204) return;

        std::cout << "---------------" << std::endl;
        std::cout << "Debug message (" << id << "): " << message << std::endl;

        
        std::cout << std::endl;
    }

	void EnableGLDebug(bool value)
	{
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, value ? GL_TRUE : GL_FALSE);

		GLint flags;
		glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
		if (value && flags)
		{
			glEnable(GL_DEBUG_OUTPUT);
			glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
			glDebugMessageCallback(glDebugOutput, nullptr);
			glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
		}
		else
		{
			glDisable(GL_DEBUG_OUTPUT);
			glDisable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		}
	}

	std::string GetVersion()
	{
		return "0.1";
	}

	int Init()
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		return 1;
	}

	void PollEvents()
	{
		glfwPollEvents();
	}

	void SetClearColor(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
	}

	void Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}
}
