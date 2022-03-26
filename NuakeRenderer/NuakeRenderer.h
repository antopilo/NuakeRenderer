#include <string>

namespace NuakeRenderer
{
	void SetClearColor(float r, float g, float b, float a);
	void Clear();

	void EnableGLDebug(bool value);

	int Init();
	void PollEvents();

	std::string GetVersion();
}
