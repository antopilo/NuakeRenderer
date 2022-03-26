#include "Shader.h"
#include <iostream>


namespace NuakeRenderer
{
	Shader::Shader(const std::string& vertex, const std::string& frag)
	{
		mShaderID = CreateProgram({vertex, frag, ""});
	}

	void Shader::Bind() const
	{
		glUseProgram(mShaderID);
	}
	void Shader::Unbind() const
	{
		glUseProgram(0);
	}

	unsigned int Shader::CreateProgram(const ShaderSource& source)
	{
		unsigned int program = glCreateProgram();

		unsigned int vs = Compile(GL_VERTEX_SHADER, source);
		unsigned int fs = Compile(GL_FRAGMENT_SHADER, source);

		glAttachShader(program, vs);
		glAttachShader(program, fs);
		glLinkProgram(program);
		glValidateProgram(program);

		// Get Uniforms.
		GLint size; // size of the variable
		GLenum type; // type of the variable (float, vec3 or mat4, etc)

		const GLsizei bufSize = 16; // maximum name length
		GLchar name[bufSize]; // variable name in GLSL
		GLsizei length; // name length

		int uniformCount = 0;
		glGetProgramiv(program, GL_ACTIVE_UNIFORMS, &uniformCount);
		for (int i = 0; i < uniformCount; i++)
		{
			glGetActiveUniform(program, (GLuint)i, bufSize, &length, &size, &type, name);

			int addr = glGetUniformLocation(program, name);
			mUniforms[name] = addr;
			switch (type)
			{
				case(GL_FLOAT):
					mUniformsType[name] = UniformTypes::Float;
				break;
				case(GL_INT):
					mUniformsType[name] = UniformTypes::Int;
					break;
				case(GL_FLOAT_VEC2):
					mUniformsType[name] = UniformTypes::Vec2;
					break;
				case(GL_FLOAT_VEC3):
					mUniformsType[name] = UniformTypes::Vec3;
					break;
				case(GL_FLOAT_VEC4):
					mUniformsType[name] = UniformTypes::Vec4;
					break;
				case(GL_FLOAT_MAT4):
					mUniformsType[name] = UniformTypes::Mat4;
					break;
				case(GL_FLOAT_MAT3):
					mUniformsType[name] = UniformTypes::Mat3;
					break;
				case(GL_SAMPLER_2D):
					mUniformsType[name] = UniformTypes::Sampler2D;
					break;
			}
			printf("Uniform #%d Type: %u Name: %s\n", i, type, name);
		}
		glDeleteShader(vs);
		glDeleteShader(fs);

		return program;
	}

	unsigned int Shader::Compile(GLenum shaderType, const ShaderSource& source)
	{
		unsigned int id = glCreateShader(shaderType);
		const char* src;
		if (shaderType == GL_FRAGMENT_SHADER) src = source.fragment.c_str();
		if (shaderType == GL_VERTEX_SHADER)   src = source.vertex.c_str();

		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);

		// Shader error.
		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

			// We allocate the size of the array using 
			// m alloc. casted as a pointer.
			char* message = (char*)malloc(length * sizeof(char));

			glGetShaderInfoLog(id, length, &length, message);

			std::string stype;
			if (shaderType == GL_FRAGMENT_SHADER) stype = "Fragment";
			if (shaderType == GL_VERTEX_SHADER)  stype = "Vertex";

			std::cout << "Failed to compile " <<
				(shaderType == GL_VERTEX_SHADER ? "vertex" : "Fragment") << " shader!" << std::endl;

			std::cout << message << std::endl;
			// Delete invalid shader
			glDeleteShader(id);
			return 0;
		}

		return id;
	}

	int Shader::FindUniformLocation(const std::string uniform)
	{
		if (mUniforms.find(uniform) != mUniforms.end())
			return mUniforms[uniform];
		return -1;
	}

	void Shader::SetUniforms(std::vector<UniformVariable> uniforms)
	{
		for (auto& u : uniforms)
		{
			std::string name = u.name;
			auto type = u.type;
			switch (type)
			{
			case UniformTypes::Float:
				SetUniform(name, u.value.valueFloat);
				break;
			case UniformTypes::Int:
				SetUniform(name, u.value.valueInt);
				break;
			case UniformTypes::Vec2:
				SetUniform(name, u.value.valueVec2);
				break;
			case UniformTypes::Vec3:
				SetUniform(name, u.value.valueVec3);
				break;
			case UniformTypes::Vec4:
				SetUniform(name, u.value.valueVec4);
				break;
			case UniformTypes::Mat3:
				SetUniform(name, u.value.valueMat3);
				break;
			case UniformTypes::Mat4:
				SetUniform(name, u.value.valueMat4);
				break;
			case UniformTypes::Sampler2D:
				SetUniform(name, u.value.valueInt);
				break;
			}
		}
	}

	void Shader::SetUniform(const std::string& name, float v0)
	{
		int addr = FindUniformLocation(name);

		if (addr != -1)
			glUniform1f(addr, v0);
	}

	void Shader::SetUniform(const std::string& name, Vector2 v0)
	{
		SetUniform(name, v0.x, v0.y);
	}

	void Shader::SetUniform(const std::string& name, float v0, float v1)
	{
		int addr = FindUniformLocation(name);

		if (addr != -1)
			glUniform2f(addr, v0, v1);
	}


	void Shader::SetUniform(const std::string& name, float v0, float v1, float v2)
	{
		int addr = FindUniformLocation(name);

		if (addr != -1)
			glUniform3f(addr, v0, v1, v2);
	}

	void Shader::SetUniform(const std::string& name, Vector3 v0)
	{
		SetUniform(name, v0.x, v0.y, v0.z);
	}

	void Shader::SetUniform(const std::string& name, float v0, float v1, float v2, float v3)
	{
		int addr = FindUniformLocation(name);

		if (addr != -1)
			glUniform4f(addr, v0, v1, v2, v3);
	}

	void Shader::SetUniform(const std::string& name, Vector4 v0)
	{
		SetUniform(name, v0.x, v0.y, v0.z, v0.w);
	}

	void Shader::SetUniform(const std::string& name, Matrix3 v0)
	{
		int addr = FindUniformLocation(name);

		if (addr != -1)
			glUniformMatrix3fv(addr, 1, GL_FALSE, &v0[0][0]);
	}

	void Shader::SetUniform(const std::string& name, Matrix4 v0)
	{
		int addr = FindUniformLocation(name);

		if (addr != -1)
			glUniformMatrix4fv(addr, 1, GL_FALSE, &v0[0][0]);
	}
}