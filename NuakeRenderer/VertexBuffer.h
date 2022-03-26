#pragma once
#include <glad/glad.h>

namespace NuakeRenderer
{
	class VertexBuffer
	{
	private:
		unsigned int mBufferID;
		GLenum mBufferType;
	public:
		VertexBuffer(const void* data, unsigned int size, GLenum bufferType = GL_ARRAY_BUFFER, GLenum dataHint = GL_STATIC_DRAW);
		~VertexBuffer();

		void SetSubData(const void* data, unsigned int size, unsigned int offset = 0);

		void Bind() const;
		void Unbind() const;
	};
}