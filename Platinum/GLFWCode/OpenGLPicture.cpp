#include "pch.h"
#include "OpenGLPicture.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "stb_image.h"

#include "../Utilities.h"

namespace pl
{
	OpenGLPicture::OpenGLPicture(const std::string& path)
	{
		glGenTextures(1, &mPictureProgram);
		glBindTexture(GL_TEXTURE_2D, mPictureProgram);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(path.c_str(), &Width, &Height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Width, Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			PL_ERROR("FAILED TO LOAD PICTURE");
		}
		stbi_image_free(data);
	}
	int OpenGLPicture::GetWidth() const
	{
		return Width;
	}
	int OpenGLPicture::GetHeight() const
	{
		return Height;
	}

	void OpenGLPicture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, mPictureProgram);
	}

	OpenGLPicture::~OpenGLPicture()
	{
		glDeleteTextures(1, &mPictureProgram);
	}


}