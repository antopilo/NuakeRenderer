#pragma once
#include "Math.h"
#include "Texture.h"

#include <map>

namespace NuakeRenderer
{
	enum class TextureAttachment
	{
		DEPTH = GL_DEPTH_ATTACHMENT,
		COLOR0 = GL_COLOR_ATTACHMENT0,
		COLOR1 = GL_COLOR_ATTACHMENT1,
		COLOR2 = GL_COLOR_ATTACHMENT2,
		COLOR3 = GL_COLOR_ATTACHMENT3,
		COLOR4 = GL_COLOR_ATTACHMENT4,
		COLOR5 = GL_COLOR_ATTACHMENT5,
		COLOR6 = GL_COLOR_ATTACHMENT6,
		COLOR7 = GL_COLOR_ATTACHMENT7,
		COLOR8 = GL_COLOR_ATTACHMENT8,
		COLOR9 = GL_COLOR_ATTACHMENT9,
		COLOR10 = GL_COLOR_ATTACHMENT10,
		COLOR11 = GL_COLOR_ATTACHMENT11,
		COLOR12 = GL_COLOR_ATTACHMENT12,
		COLOR13 = GL_COLOR_ATTACHMENT13,
		COLOR14 = GL_COLOR_ATTACHMENT14,
		COLOR15 = GL_COLOR_ATTACHMENT15,
		COLOR16 = GL_COLOR_ATTACHMENT16,
		COLOR17 = GL_COLOR_ATTACHMENT17,
		COLOR18 = GL_COLOR_ATTACHMENT18,
		COLOR19 = GL_COLOR_ATTACHMENT19,
		COLOR20 = GL_COLOR_ATTACHMENT20,
		COLOR21 = GL_COLOR_ATTACHMENT21,
		COLOR22 = GL_COLOR_ATTACHMENT22,
		COLOR23 = GL_COLOR_ATTACHMENT23,
		COLOR24 = GL_COLOR_ATTACHMENT24,
		COLOR25 = GL_COLOR_ATTACHMENT25,
		COLOR26 = GL_COLOR_ATTACHMENT26,
		COLOR27 = GL_COLOR_ATTACHMENT27,
		COLOR28 = GL_COLOR_ATTACHMENT28,
		COLOR29 = GL_COLOR_ATTACHMENT29,
		COLOR30 = GL_COLOR_ATTACHMENT30,
		COLOR31 = GL_COLOR_ATTACHMENT31,
	};

	class Framebuffer
	{
	private:
		unsigned int mFramebufferID;
		Vector2 mSize;
		std::map<TextureAttachment, Texture*> mTextureAttachments;

		bool mResizeQueued = false;

	public:
		Framebuffer(const Vector2& size);
		~Framebuffer();

		bool HasTextureAttachment(const TextureAttachment& attachment);
		Texture* GetTextureAttachment(const TextureAttachment& attachment);
		void SetTextureAttachment(const TextureAttachment& attachment, Texture* texture);

		void Bind();
		void Unbind() const;

		void QueueResize(const Vector2& size);
		void Resize(const Vector2& size);
	};
}