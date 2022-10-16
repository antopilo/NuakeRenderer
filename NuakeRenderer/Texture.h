#pragma once
#include "Math.h"

#include <string>
#include <glad/glad.h>

namespace NuakeRenderer
{
	enum class PixelFormat
	{	// TODO: ADD MORE FORMATS
		RGB8 = GL_RGB,
		RGBA8 = GL_RGBA,
		RGBA32F = GL_RGBA32F
	};

	enum class PixelDataType
	{	// TODO: ADD MORE FORMATS
		UBYTE = GL_UNSIGNED_BYTE,
		FLOAT = GL_FLOAT
	};

	enum class SamplerFilter
	{	// TODO: ADD MORE FILTERS
		LINEAR = GL_LINEAR,
		NEAREST = GL_NEAREST
	};

	enum class SamplerWrapping
	{	// TODO: ADD MORE WRAPPING
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
		bool flipVertical = false;
	};

	class Texture
	{
	private:
		uint32_t mTextureID;
		Vector2 mSize;
		TextureFlags mFlags;
		void* mData;

		void FlipOnLoad();
	public:
		Texture(const TextureFlags& flags, const std::string& path);
		Texture(const TextureFlags& flags, Vector2 size, void* data);
		Texture(const TextureFlags& flags, Vector2 size);
		~Texture();

		Vector2 GetSize() const { return mSize; }
		void Resize(const Vector2& size);

		unsigned int GetTextureID() const { return mTextureID; }

		void Bind(uint32_t slot = 0 ) const;
		void Unbind() const;

		void SetMagnificationFilter(const SamplerFilter& filter);
		void SetMinificationFilter(const SamplerFilter& filter);
		void SetWrapping(const SamplerWrapping& wrapping);
		void SetMaxAnisotropy();
		void GenerateMipmap();
	};
}