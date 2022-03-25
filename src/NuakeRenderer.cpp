#include "NuakeRenderer.h"
#include "../Dependencies/glad/include/glad/glad.h"
#include <iostream>

namespace NuakeRenderer
{
	std::string GetVersion()
	{
		return "0.1";
	}

	int Init(void* context)
	{
		if (!gladLoadGLLoader((GLADloadproc)context))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return -1;
		}
	}
}
