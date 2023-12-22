#pragma once

namespace pl
{
    class PictureImplementation
    {
    public:

        virtual int GetWidth() const = 0;

        virtual int GetHeight() const = 0;

        virtual void Bind() = 0;

        virtual ~PictureImplementation() {};

    };
}