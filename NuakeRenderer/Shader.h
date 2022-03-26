#include "Math.h"

#include <glad/glad.h>

#include <vector>
#include <string>
#include <map>

namespace NuakeRenderer
{
	struct ShaderSource
	{
		std::string vertex;
		std::string fragment;
		std::string compute;
	};

	enum class UniformTypes
	{
		Int, Float, Vec2, Vec3, Vec4, Mat3, Mat4, Sampler2D
	};

	union UniformValue {
		float valueFloat;
		int valueInt;
		Vector2 valueVec2;
		Vector3 valueVec3;
		Vector4 valueVec4;
		Matrix3 valueMat3;
		Matrix4 valueMat4;
	};

	struct UniformVariable
	{
		std::string name;
		UniformValue value;
		UniformTypes type;

		UniformVariable(const std::string& uniformName, float uniformValue)
		{
			name = name;
			value.valueFloat = uniformValue;
			type = UniformTypes::Float;
		}

		UniformVariable(const std::string& uniformName, int uniformValue)
		{
			name = name;
			value.valueInt = uniformValue;
			type = UniformTypes::Int;
		}

		UniformVariable(const std::string& uniformName, Vector2 uniformValue)
		{
			name = name;
			value.valueVec2 = uniformValue;
			type = UniformTypes::Vec2;
		}
	};

	class Shader
	{
	private:
		unsigned int mShaderID;
		std::map<std::string, UniformTypes> mUniformsType;
		std::map<std::string, unsigned int> mUniforms;

	public:
		Shader(const std::string& vertex, const std::string& frag);

		void Bind() const;
		void Unbind() const;

		std::map<std::string, UniformTypes> GetUniforms()
		{
			return mUniformsType;
		}

		void SetUniforms(std::vector<UniformVariable> uniforms);

		void Shader::SetUniform(const std::string& name, float v0)
		{
			int addr = FindUniformLocation(name);

			if (addr != -1)
				glUniform1f(addr, v0);
		}

		void Shader::SetUniform(const std::string& name, float v0, float v1)
		{
			int addr = FindUniformLocation(name);

			if (addr != -1)
				glUniform2f(addr, v0, v1);
		}

	private:
		unsigned int CreateProgram(const ShaderSource& source);
		unsigned int Compile(GLenum shaderType, const ShaderSource& source);
		int FindUniformLocation(const std::string);
	};
}