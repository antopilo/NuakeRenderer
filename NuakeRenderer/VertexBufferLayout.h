#pragma once
#include <vector>
#include <glad/glad.h>

namespace NuakeRenderer 
{
	struct VertexBufferElement
	{
		GLenum type;
		unsigned int count;
		bool normalized;

		static unsigned int GetSizeOfType(GLenum type)
		{
			switch (type)
			{
			case GL_FLOAT:  return 4;
			case GL_UNSIGNED_INT:   return 4;
			case GL_UNSIGNED_BYTE:  return 1;
			}
			return 0;
		}
	};

	class VertexBufferLayout
	{
	private:
		std::vector<VertexBufferElement> m_Elements;
		unsigned int m_Stride;

	public:
		VertexBufferLayout() : m_Stride(0) {};

		template<typename T>
		void Push(unsigned int count)
		{
			//static_assert(false);
		}

		template<>
		void Push<float>(unsigned int count)
		{
			m_Elements.push_back({ GL_FLOAT, count, false });
			m_Stride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * count;
		}

		template<>
		void Push<unsigned int>(unsigned int count)
		{
			m_Elements.push_back({ GL_UNSIGNED_INT, count, false });
			m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT) * count;
		}

		template<>
		void Push<unsigned char>(unsigned int count)
		{
			m_Elements.push_back({ GL_UNSIGNED_BYTE, count, true });
			m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE) * count;
		}

		inline const std::vector<VertexBufferElement>& GetElements() const { return m_Elements; }

		inline unsigned int GetStride() const { return m_Stride; }
	};
}