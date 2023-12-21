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
		unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			GLenum error = glGetError();
			if (error != GL_NO_ERROR)
			{
				// Log or print the error
				PL_ERROR("OpenGL Error: {}", error);
			}
		}
		else
		{
			PL_ERROR("FAILED TO LOAD PICTURE");
			return;
		}
		
		
		stbi_image_free(data);
		std::cout << &data << std::endl;
		std::cout << height << std::endl;

	}
	int OpenGLPicture::GetWidth() const
	{
		return width;
	}
	int OpenGLPicture::GetHeight() const
	{
		return height;
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