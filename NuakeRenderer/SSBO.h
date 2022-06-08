#pragma once

namespace NuakeRenderer
{
	class SSBO
	{
	private:
		unsigned int mRendererID;
	public:
		SSBO(unsigned int size = 0);
		~SSBO();

		void Bind(unsigned int slot = 0) const;
		void Unbind() const;
		
		void SetData(void* data, unsigned int size) const;

		unsigned int GetID() const
		{
			return mRendererID;
		}
	};
}