#include "ShaderRegistry.h"

namespace NuakeRenderer
{
	std::map<std::string, Shader*> ShaderRegistry::mShaders = std::map<std::string, Shader*>();

	bool ShaderRegistry::IsShaderRegistered(const std::string& shaderName)
	{
		return mShaders.find(shaderName) != mShaders.end();
	}

	Shader* ShaderRegistry::Get(const std::string& shaderName)
	{
		if (IsShaderRegistered(shaderName))
		{
			return mShaders[shaderName];
		}

		// TODO: logger.
		return nullptr;
	}

	bool ShaderRegistry::Set(const std::string& shaderName, Shader* shader)
	{
		bool isOveriding = false;
		if (IsShaderRegistered(shaderName))
			isOveriding = true;

		mShaders[shaderName] = shader;

		return isOveriding;
	}
}