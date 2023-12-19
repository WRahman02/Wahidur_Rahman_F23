#pragma once

#include "../pch.h"
#include "Picture.h"
namespace pl
{
	class OpenGLPicture : public PictureImplementation
	{
	public: 
		OpenGLPicture(const std::string& path);

		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void Bind() override;
		~OpenGLPicture();

	private:
		int Width, Height;
		unsigned int mPictureProgram;
		
	};
}