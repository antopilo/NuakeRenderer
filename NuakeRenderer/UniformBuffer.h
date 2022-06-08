#pragma once


namespace NuakeRenderer
{
	class UniformBuffer
	{
	private:
		unsigned int m_RendererID;
	public:
		UniformBuffer();
		~UniformBuffer();
		
		void SetData(void* data, unsigned size);

		void Bind(unsigned int slot = 0) const;
		void Unbind() const;
		
	};
}