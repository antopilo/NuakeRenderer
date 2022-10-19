// Nuake Renderer is a helper library that with everything related to OpenGL rendering.
// It is made to be low level and isn't trying to be a renderer that is already built for you.
#include <string>
#include "imgui.h"

namespace NuakeRenderer
{
	int Init();
	std::string GetVersion();

	// Enables debugging output
	void EnableGLDebug(bool value);

	void SetClearColor(float r, float g, float b, float a);
	void Clear();

	void SetMSAA(bool enable);
	void SetMSAASamples(uint32_t samples);

	void Begin();
	void End();

	// Poll window events
	void PollEvents();

	// ImGui stuff
	void ApplyNuakeImGuiTheme();
	void BeginImGuiFrame();
	void EndImGuiFrame();
}
