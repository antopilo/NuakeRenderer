#pragma once
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
		Int, Uint, Float, Vec2, Vec3, Vec4, Mat3, Mat4, Sampler2D
	};

	union UniformValue {
		float valueFloat;
		int valueInt;
		unsigned int valueUInt;
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
			name = uniformName;
			value.valueFloat = uniformValue;
			type = UniformTypes::Float;
		}

		UniformVariable(const std::string& uniformName, int uniformValue)
		{
			name = uniformName;
			value.valueInt = uniformValue;
			type = UniformTypes::Int;
		}

		UniformVariable(const std::string& uniformName, Vector2 uniformValue)
		{
			name = uniformName;
			value.valueVec2 = uniformValue;
			type = UniformTypes::Vec2;
		}

		UniformVariable(const std::string& uniformName, Vector3 uniformValue)
		{
			name = uniformName;
			value.valueVec3 = uniformValue;
			type = UniformTypes::Vec3;
		}

		UniformVariable(const std::string& uniformName, Vector4 uniformValue)
		{
			name = uniformName;
			value.valueVec4 = uniformValue;
			type = UniformTypes::Vec4;
		}

		UniformVariable(const std::string& uniformName, Matrix3 uniformValue)
		{
			name = uniformName;
			value.valueMat3 = uniformValue;
			type = UniformTypes::Mat3;
		}

		UniformVariable(const std::string& uniformName, Matrix4 uniformValue)
		{
			name = uniformName;
			value.valueMat4 = uniformValue;
			type = UniformTypes::Mat4;
		}
	};

	class Shader
	{
	private:
		uint32_t mShaderID;
		std::map<std::string, UniformTypes> mUniformsType;
		std::map<std::string, unsigned int> mUniforms;
		std::string mError = "";

	public:
		Shader(const std::string& vertex, const std::string& frag);
		Shader(const std::string& compute);

		void Bind() const;
		void Unbind() const;

		std::map<std::string, UniformTypes> GetUniforms()
		{
			return mUniformsType;
		}

		std::string GetError() const { return mError; }

		void SetUniforms(const std::vector<UniformVariable>& uniforms);

		void SetUniform(const std::string& name, float v0);
		void SetUniform(const std::string& name, int v0);
		void SetUniform(const std::string& name, unsigned int v0);
		void SetUniform(const std::string& name, float v0, float v1);
		void SetUniform(const std::string& name, Vector2 v0);
		void SetUniform(const std::string& name, float v0, float v1, float v3);
		void SetUniform(const std::string& name, Vector3 v0);
		void SetUniform(const std::string& name, float v0, float v1, float v3, float v4);
		void SetUniform(const std::string& name, Vector4 v0);
		void SetUniform(const std::string& name, Matrix3 v0);
		void SetUniform(const std::string& name, Matrix4 v0);

	private:
		unsigned int CreateProgram(const ShaderSource& source);
		unsigned int Compile(GLenum shaderType, const ShaderSource& source);
		int FindUniformLocation(const std::string& uniform);
	};
}