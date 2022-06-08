#include "UniformBuffer.h"
#include <glad/glad.h>

namespace NuakeRenderer
{
	UniformBuffer::UniformBuffer()
	{
		glGenBuffers(1, &m_RendererID);
		glBufferData(GL_UNIFORM_BUFFER, 256, 0, GL_STATIC_DRAW);
	}

	UniformBuffer::~UniformBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}
	void UniformBuffer::SetData(void* data, unsigned size)
	{
		Bind();
		glBufferSubData(GL_UNIFORM_BUFFER, 0, size, data);
		Unbind();
	}
	
	void UniformBuffer::Bind(unsigned int slot) const
	{
		glBindBuffer(GL_UNIFORM_BUFFER, m_RendererID);
		glBindBufferBase(GL_UNIFORM_BUFFER, slot, m_RendererID);
	}

	void UniformBuffer::Unbind() const
	{
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
	}
}