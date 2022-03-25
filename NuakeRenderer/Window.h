#pragma once
#include <string>

class GLFWwindow;
namespace NuakeRenderer
{
	class Window
	{
	private:
		GLFWwindow* mWindow;
		std::string mWindowTitle;

	public:
		Window(const std::string& windowTitle);
		~Window();

		void MakeCurrent();
		bool ShouldClose();
		void SwapBuffers();
	};
}