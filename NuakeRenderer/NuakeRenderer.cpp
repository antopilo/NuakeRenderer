#include "NuakeRenderer.h"
#include "Window.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

namespace NuakeRenderer
{
	std::string GetVersion()
	{
		return "0.1";
	}

	int Init()
	{
		return glfwInit();
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
