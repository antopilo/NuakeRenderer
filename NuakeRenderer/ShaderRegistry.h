#pragma once
#include <string>
#include <map>

#include "Shader.h"

namespace NuakeRenderer
{
	class ShaderRegistry
	{
	public:
		static Shader* Get(const std::string& shaderName);
		static bool Set(const std::string& shaderName, Shader* shader);
		static bool IsShaderRegistered(const std::string& shaderName);
	private:
		static std::map<std::string, Shader*> mShaders;
	};
}