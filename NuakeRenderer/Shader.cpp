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
		printf("Active Uniforms: %d\n", uniformCount);

		for (int i = 0; i < uniformCount; i++)
		{
			glGetActiveUniform(program, (GLuint)i, bufSize, &length, &size, &type, name);

			printf("Uniform #%d Type: %u Name: %s\n", i, type, name);
		}

		glGetProgramiv(program, GL_ACTIVE_ATTRIBUTES, &uniformCount);
		printf("Active Attributes: %d\n", uniformCount);

		for (int i = 0; i < uniformCount; i++)
		{
			glGetActiveAttrib(program, (GLuint)i, bufSize, &length, &size, &type, name);

			printf("Attribute #%d Type: %u Name: %s\n", i, type, name);
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

	void Shader::SetUniforms(std::vector<UniformVariable> uniforms)
	{
		for (auto& u : uniforms)
		{
			std::string name = u.name;
			auto type = u.type;
			switch (type)
			{
			case UniformTypes::Float:
				{

					break;
				}
			}
		}
	}
}