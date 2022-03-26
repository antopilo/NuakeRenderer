#include "VertexBuffer.h"

namespace NuakeRenderer
{
	VertexBuffer::VertexBuffer(const void* data, unsigned int size, GLenum bufferType, GLenum dataHint)
	{
		mBufferType = bufferType;
		glGenBuffers(1, &mBufferID);
		Bind();
		glBufferData(mBufferType, size, data, dataHint);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &mBufferID);
	}

	void VertexBuffer::SetSubData(const void* data, unsigned int size, unsigned int offset)
	{
		glBufferSubData(mBufferType, offset, size, data);
	}

	void VertexBuffer::Bind() const
	{
		glBindBuffer(mBufferType, mBufferID);
	}

	void VertexBuffer::Unbind() const
	{
		glBindBuffer(mBufferType, 0);
	}
}