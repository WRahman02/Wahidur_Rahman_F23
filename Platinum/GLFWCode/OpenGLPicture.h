#pragma once

#include "../pch.h"
#include "../PictureImplementation.h"

namespace pl
{
    class OpenGLPicture : public PictureImplementation
    {
    public:

        OpenGLPicture(const std::string& filePath);

        virtual int GetWidth() const override;
        virtual int GetHeight() const override;

        virtual void Bind() override;

        ~OpenGLPicture();

    private:
        int mWidth;
        int mHeight;

        unsigned int mPictureProgram;

    };
}