#include "FrameBuffer.h"
#include <vector>

namespace NuakeRenderer
{
	Framebuffer::Framebuffer(const Vector2& size)
	{
		if (size.x < 0 && size.y < 0)
			return;

		glGenFramebuffers(1, &mFramebufferID);
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, mFramebufferID);
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
	}

	Framebuffer::~Framebuffer()
	{
		glDeleteFramebuffers(1, &mFramebufferID);
	}

	bool Framebuffer::HasTextureAttachment(const TextureAttachment& attachment)
	{
		return mTextureAttachments.find(attachment) != mTextureAttachments.end();
	}

	Texture* Framebuffer::GetTextureAttachment(const TextureAttachment& attachment)
	{
		if (HasTextureAttachment(attachment))
			return mTextureAttachments[attachment];

		return nullptr;
	}

	void Framebuffer::Bind()
	{
		if (mResizeQueued)
			Resize(mSize);

		glBindFramebuffer(GL_FRAMEBUFFER, mFramebufferID);
		glViewport(0, 0, mSize.x, mSize.y);
	}

	void Framebuffer::Unbind() const
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void Framebuffer::QueueResize(const Vector2& size)
	{
		if (mSize == size)
			return;

		mResizeQueued = true;
		mSize = size;
	}

	void Framebuffer::Resize(const Vector2& size)
	{
		mResizeQueued = false;
		mSize = size;

		glDeleteFramebuffers(1, &mFramebufferID);
		glGenFramebuffers(1, &mFramebufferID);
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, mFramebufferID);

		// Recreate resized texture.
		for (auto const& t : mTextureAttachments)
		{
			t.second->Resize(mSize);
			SetTextureAttachment(t.first, t.second);
		}

		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
	}

	void Framebuffer::SetTextureAttachment(Texture* texture, const TextureAttachment& attachment)
	{
		mTextureAttachments[attachment] = texture;

		Bind();
		glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, (GLenum)attachment, GL_TEXTURE_2D, texture->GetTextureID(), 0);

		// Set Draw buffer with dynamic amount of render targets.
		// We dont need to set the draw buffer with a depth target
		int size = 0;
		auto keys = std::vector<TextureAttachment>();
		for (auto const& s : mTextureAttachments)
		{
			if (s.first == TextureAttachment::DEPTH) // Ignore depth attachment.
				continue;

			keys.push_back(s.first);
			size++;
		}

		if (size > 0)
			glDrawBuffers(size, (GLenum*)&keys[0]);

		Unbind();
	}
}