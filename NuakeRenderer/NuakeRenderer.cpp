#include "NuakeRenderer.h"
#include "Window.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

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
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
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

	void ApplyNuakeImGuiTheme()
	{
		ImGuiStyle& s = ImGui::GetStyle();
		s.FrameRounding = 2.0f;
		s.GrabRounding = 2.0f;
		s.CellPadding = ImVec2(8, 8);
		s.WindowPadding = ImVec2(8, 8);
		s.ScrollbarRounding = 9.0f;
		s.TabRounding = 0;
		s.WindowRounding = 0;
		s.ChildRounding = 0;
		s.FrameRounding = 0;
		s.GrabRounding = 0;
		s.FramePadding = ImVec2(8, 4);
		s.ItemSpacing = ImVec2(8, 4);
		s.ItemInnerSpacing = ImVec2(4, 4);

		ImVec4* colors = ImGui::GetStyle().Colors;
		colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
		colors[ImGuiCol_WindowBg] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
		colors[ImGuiCol_ChildBg] = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);
		colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
		colors[ImGuiCol_Border] = ImVec4(0.08f, 0.10f, 0.12f, 0.00f);
		colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_FrameBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.09f, 0.09f, 0.09f, 1.00f);
		colors[ImGuiCol_FrameBgActive] = ImVec4(0.13f, 0.13f, 0.13f, 1.00f);
		colors[ImGuiCol_TitleBg] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
		colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
		colors[ImGuiCol_ScrollbarBg] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
		colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.34f, 0.34f, 0.34f, 1.00f);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.29f, 0.29f, 0.29f, 1.00f);
		colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.16f, 0.16f, 0.16f, 1.00f);
		colors[ImGuiCol_CheckMark] = ImVec4(0.55f, 0.76f, 0.29f, 1.00f);
		colors[ImGuiCol_SliderGrab] = ImVec4(0.55f, 0.76f, 0.29f, 1.00f);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(0.55f, 0.76f, 0.29f, 1.00f);
		colors[ImGuiCol_Button] = ImVec4(0.22f, 0.22f, 0.22f, 1.00f);
		colors[ImGuiCol_ButtonHovered] = ImVec4(0.19f, 0.19f, 0.19f, 1.00f);
		colors[ImGuiCol_ButtonActive] = ImVec4(0.16f, 0.16f, 0.16f, 1.00f);
		colors[ImGuiCol_Header] = ImVec4(0.18f, 0.18f, 0.18f, 1.00f);
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.16f, 0.16f, 0.16f, 1.00f);
		colors[ImGuiCol_HeaderActive] = ImVec4(0.12f, 0.12f, 0.12f, 1.00f);
		colors[ImGuiCol_Separator] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
		colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.10f, 0.10f, 0.78f);
		colors[ImGuiCol_SeparatorActive] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.00f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.00f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.00f);
		colors[ImGuiCol_Tab] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
		colors[ImGuiCol_TabHovered] = ImVec4(0.19f, 0.19f, 0.19f, 1.00f);
		colors[ImGuiCol_TabActive] = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);
		colors[ImGuiCol_TabUnfocused] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
		colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);
		colors[ImGuiCol_DockingPreview] = ImVec4(0.55f, 0.76f, 0.29f, 1.00f);
		colors[ImGuiCol_DockingEmptyBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
		colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
		colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
		colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
		colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.19f, 1.00f);
		colors[ImGuiCol_TableBorderStrong] = ImVec4(0.11f, 0.11f, 0.11f, 1.00f);
		colors[ImGuiCol_TableBorderLight] = ImVec4(0.11f, 0.11f, 0.11f, 1.00f);
		colors[ImGuiCol_TableRowBg] = ImVec4(0.11f, 0.11f, 0.11f, 1.00f);
		colors[ImGuiCol_TableRowBgAlt] = ImVec4(0.93f, 0.27f, 0.27f, 0.00f);
		colors[ImGuiCol_TextSelectedBg] = ImVec4(0.08f, 0.49f, 0.97f, 0.28f);
		colors[ImGuiCol_DragDropTarget] = ImVec4(0.55f, 0.76f, 0.29f, 1.00f);
		colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
		colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);

	}

	void BeginImGuiFrame()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();

		// ImGui Calls here
		ImGui::NewFrame();
	}

	void EndImGuiFrame()
	{
		ImGui::EndFrame();
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
	}
}
