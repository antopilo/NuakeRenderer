#pragma once
class GLFWwindow;
namespace NuakeRenderer
{
	class Window
	{
	public:
		Window(const std::string windowTitle = DEFAULT_WINDOW_TITLE);
		~Window();

		void MakeCurrent();
		bool ShouldClose();
		void PollEvents();
		void SwapBuffers();
	private:
		const static std::string DEFAULT_WINDOW_TITLE = "Nuake Renderer Window";
		GLFWwindow* mWindow;
		std::string mWindowTitle;
	};
}