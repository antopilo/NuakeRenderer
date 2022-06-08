#include "SSBO.h"
#include <glad/glad.h>

namespace NuakeRenderer
{
	SSBO::SSBO(unsigned int size)
	{
		glGenBuffers(1, &mRendererID);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, mRendererID);
		glBufferData(GL_SHADER_STORAGE_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
	}
	
	SSBO::~SSBO()
	{
		glDeleteBuffers(1, &mRendererID);
	}

	void SSBO::Bind(unsigned int slot) const
	{
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, mRendererID);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, slot, mRendererID);
	}

	void SSBO::Unbind() const
	{
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
	}

	void SSBO::SetData(void* data, unsigned int size) const
	{
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, mRendererID);
		glBufferSubData(GL_SHADER_STORAGE_BUFFER, 0, size, data);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
	}
}
