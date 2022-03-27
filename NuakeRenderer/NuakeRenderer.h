#include <string>
#include "imgui.h"

namespace NuakeRenderer
{
	void SetClearColor(float r, float g, float b, float a);
	void Clear();
	void DrawElements();
	void EnableGLDebug(bool value);

	int Init();
	void PollEvents();

	std::string GetVersion();

	void ApplyNuakeImGuiTheme();
	void BeginImGuiFrame();
	void EndImGuiFrame();
}
