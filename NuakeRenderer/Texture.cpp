#include "Texture.h"

#include "stb_image.h"

namespace NuakeRenderer
{
	Texture::Texture(const TextureFlags& flags, const std::string& path)
	{
		stbi_set_flip_vertically_on_load(1);

		int width, height, channels;
		stbi_load(path.c_str(), &width, &height, &channels, 4);

		glGenTextures(1, &mTextureID);
		glBindTexture(GL_TEXTURE_2D, mTextureID);
		glTexImage2D(GL_TEXTURE_2D, 0, (GLenum)flags.pixelFormat, mSize.x, mSize.y, 0, (GLenum)flags.pixelFormat, (GLenum)flags.pixelDataType, mData);
		SetMagnificationFilter(mFlags.magFilter);
		SetMinificationFilter(mFlags.minFilter);
		SetWrapping(mFlags.wrapping);

		stbi_image_free(mData);
	}

	Texture::Texture(const TextureFlags& flags, Vector2 size, void* data) : mFlags(flags), mSize(size)
	{
		glGenTextures(1, &mTextureID);
		glBindTexture(GL_TEXTURE_2D, mTextureID);
		glTexImage2D(GL_TEXTURE_2D, 0, (GLenum)flags.pixelFormat, mSize.x, mSize.y, 0, (GLenum)flags.pixelFormat, (GLenum)flags.pixelDataType, data);
		SetMagnificationFilter(mFlags.magFilter);
		SetMinificationFilter(mFlags.minFilter);
		SetWrapping(mFlags.wrapping);
	}

	Texture::Texture(const TextureFlags& flags, Vector2 size) : mFlags(flags), mSize(size)
	{
		glGenTextures(1, &mTextureID);
		glBindTexture(GL_TEXTURE_2D, mTextureID);
		
		GLenum interlan = (GLenum)mFlags.pixelFormat;
		if (mFlags.pixelFormat == PixelFormat::RGBA32F)
			interlan = GL_RGBA;
		
		glTexImage2D(GL_TEXTURE_2D, 0, (GLenum)flags.pixelFormat, mSize.x, mSize.y, 0, interlan, (GLenum)flags.pixelDataType, 0);
		SetMagnificationFilter(mFlags.magFilter);
		SetMinificationFilter(mFlags.minFilter);
		SetWrapping(mFlags.wrapping);
	}
	
	Texture::~Texture()
	{
		glDeleteTextures(1, &mTextureID);
	}

	void Texture::Resize(const Vector2& size)
	{
		glDeleteTextures(1, &mTextureID);
		mSize = size;
		glGenTextures(1, &mTextureID);
		glBindTexture(GL_TEXTURE_2D, mTextureID);
		GLenum interlan = (GLenum)mFlags.pixelFormat;
		if (mFlags.pixelFormat == PixelFormat::RGBA32F)
			interlan = GL_RGBA;

		glTexImage2D(GL_TEXTURE_2D, 0, (GLenum)mFlags.pixelFormat, mSize.x, mSize.y, 0, interlan, (GLenum)mFlags.pixelDataType, 0);
		SetMagnificationFilter(mFlags.magFilter);
		SetMinificationFilter(mFlags.minFilter);
		SetWrapping(mFlags.wrapping);
	}

	void Texture::Bind(uint32_t slot) const
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, mTextureID);
	}

	void Texture::Unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::SetMagnificationFilter(const SamplerFilter& filter)
	{
		mFlags.magFilter = filter;
		glBindTexture(GL_TEXTURE_2D, mTextureID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, (GLint)mFlags.magFilter);
	}

	void Texture::SetMinificationFilter(const SamplerFilter& filter)
	{
		mFlags.minFilter = filter;
		glBindTexture(GL_TEXTURE_2D, mTextureID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, (GLint)mFlags.minFilter);
	}

	void Texture::SetWrapping(const SamplerWrapping& wrapping)
	{
		mFlags.wrapping = wrapping;
		glBindTexture(GL_TEXTURE_2D, mTextureID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, (GLint)mFlags.wrapping);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, (GLint)mFlags.wrapping);
	}

	void Texture::SetMaxAnisotropy()
	{

	}

	void Texture::GenerateMipmap()
	{

	}
}