#pragma once
#include "Math.h"

#include <glad/glad.h>

namespace NuakeRenderer
{
	enum class PixelFormat
	{
		RGB8 = GL_RGB,
		RGBA8 = GL_RGBA
	};

	enum class PixelDataType
	{
		UBYTE = GL_UNSIGNED_BYTE,
		FLOAT = GL_FLOAT
	};

	enum class SamplerFilter
	{
		LINEAR = GL_LINEAR,
		NEAREST = GL_NEAREST
	};

	enum class SamplerWrapping
	{
		CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
		REPEAT = GL_REPEAT
	};

	struct TextureFlags
	{
		PixelFormat pixelFormat = PixelFormat::RGBA8;
		PixelDataType pixelDataType = PixelDataType::UBYTE;

		SamplerFilter minFilter = SamplerFilter::LINEAR;
		SamplerFilter magFilter = SamplerFilter::LINEAR;
		SamplerWrapping wrapping = SamplerWrapping::REPEAT;
	};

	class Texture
	{
	private:
		unsigned int mTextureID;
		Vector2 mSize;
		TextureFlags mFlags;

	public:
		Texture(const TextureFlags& flags, Vector2 size, void* data);
		Texture(const TextureFlags& flags, Vector2 size);

		Vector2 GetSize() const { return mSize; }
		void Resize(const Vector2& size);

		unsigned int GetTextureID() const { return mTextureID; }

		void Bind(unsigned int slot = 0 ) const;
		void Unbind() const;

		void SetMagnificationFilter(const SamplerFilter& filter);
		void SetMinificationFilter(const SamplerFilter& filter);
		void SetWrapping(const SamplerWrapping& wrapping);
		void SetMaxAnisotropy();
		void GenerateMipmap();
	};
}