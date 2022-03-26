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

	std::string GetVersion()
	{
		return "0.1";
	}

	int Init()
	{
		if(!glfwInit())
			return -1;

		
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
