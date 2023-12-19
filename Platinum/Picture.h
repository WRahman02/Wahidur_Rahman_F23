#pragma once

#include "pch.h"
#include "Utilities.h"
#include "PictureImplementation.h"


namespace pl
{
    class PLATINUM_API Picture
    {
    public:
        Picture(const std::string& pic);
        int GetHeight() const;
        int GetWidth() const;
        void Bind();
        //~Picture();

    private:
        std::unique_ptr<PictureImplementation> mImplementation;
    };
}