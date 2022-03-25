#include "Window.h"
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

namespace NuakeRenderer
{
	Window::Window(const std::string& windowTitle)
	{
		mWindow = glfwCreateWindow(640, 480, windowTitle.c_str(), NULL, NULL);

		if (mWindow == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}

		MakeCurrent();

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
		}
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::MakeCurrent()
	{
		glfwMakeContextCurrent(mWindow);
	}

	bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(mWindow);
	}

	void Window::SwapBuffers()
	{
		glfwSwapBuffers(mWindow);
	}
}