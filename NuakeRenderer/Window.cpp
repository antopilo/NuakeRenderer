#include "Window.h"
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

namespace NuakeRenderer
{
	Window::Window(const std::string& windowTitle, Vector2 windowSize)
	{
		mWindowSize = windowSize;

		if (!glfwInit())
		{
			std::cout << "Failed to initialize GLFW" << std::endl;
			return;
		}

		mWindow = glfwCreateWindow(mWindowSize.x, mWindowSize.y, windowTitle.c_str(), NULL, NULL);

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

		glfwSetWindowUserPointer(mWindow, this);
		auto func = [](GLFWwindow* w, int width, int height)
		{
			static_cast<Window*>(glfwGetWindowUserPointer(w))->ResizeCallback(w, width, height);
		};

		glfwSetWindowSizeCallback(mWindow, func);
	}

	void Window::ResizeCallback(GLFWwindow* window, int width, int height)
	{
		SetWindowSize({ width, height });
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::MakeCurrent() const
	{
		glfwMakeContextCurrent(mWindow);
	}

	bool Window::ShouldClose() const
	{
		return glfwWindowShouldClose(mWindow);
	}

	void Window::SwapBuffers() const
	{
		glfwSwapBuffers(mWindow);
	}

	Vector2 Window::GetWindowSize() const
	{
		return mWindowSize;
	}

	void Window::SetWindowSize(Vector2 windowSize)
	{
		if (windowSize.x <= 0 && windowSize.y <= 0)
			return;

		mWindowSize = windowSize;
		glfwSetWindowSize(mWindow, mWindowSize.x, mWindowSize.y);
	}
}