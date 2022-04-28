#pragma once
#include "Math.h"

#include <string>

struct GLFWwindow;
namespace NuakeRenderer
{
	class Window
	{
	private:
		GLFWwindow* mWindow;
		std::string mWindowTitle;

		Vector2 mWindowSize;
	public:
		Window(const std::string& windowTitle, Vector2 windowSize = {800, 600});
		~Window();

		void MakeCurrent() const;
		bool ShouldClose() const;
		void SwapBuffers() const;

		void SetWindowSize(Vector2 windowSize);
		Vector2 GetWindowSize() const;

		GLFWwindow* GetHandle() const { return mWindow; }
	private:
		void ResizeCallback(GLFWwindow* window, int width, int height);
	};
}