#pragma once


#include "pch.h"
#include "Utilities.h"
#include"PictureImplementation.h"

namespace pl
{
	class PLATINUM_API Picture
	{
	public:
		Picture(const std::string& pathToPicture);

		int GetWidth() const;
		int GetHeight() const;

		void Bind();

	private:
		std::unique_ptr<pl::PictureImplementation> mImplementation;
	};
}