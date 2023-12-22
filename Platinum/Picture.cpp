#include "pch.h"
#include "Picture.h"
#include "GLFWCode/OpenGLPicture.h"

namespace pl
{
	Picture::Picture(const std::string& pathToPicture)
	{
#ifdef PLATINUM_MSCPP
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(pathToPicture) };
#elif PLATINUM_APPLE
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(pathToPicture) };
#elif PLATINUM_LINUX
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(pathToPicture) };
#endif
	}

	int Picture::GetWidth() const
	{
		return mImplementation->GetWidth();
	}

	int Picture::GetHeight() const
	{
		return mImplementation->GetHeight();
	}

	void Picture::Bind()
	{
		mImplementation->Bind();
	}

}