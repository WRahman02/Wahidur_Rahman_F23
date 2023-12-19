#include "pch.h"
#include "Picture.h"
#include "GLFWCode/OpenGLPicture.h"
#include "Utilities.h"


namespace pl
{
    Picture::Picture(const std::string& pic)
    {
#ifdef PLATINUM_MSCPP
        mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(pic) };
#elif PLATINUM_APPLE
        mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(pic) };
#elif PLATINUM_LINUX
        mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(pic) };
#endif
    }

    /*
    Picture::~Picture()
    {
        mImplementation->~PictureImplementation();
    }
    */
    int Picture::GetHeight() const
    {
        return mImplementation->GetHeight();
    }

    int Picture::GetWidth() const
    {
        return mImplementation->GetWidth();
    }

    void Picture::Bind()
    {
        mImplementation->Bind();
    }


}