#pragma once

#include "Utilities.h"

namespace pl
{
	class PLATINUM_API KeyPressed
	{
	public:
		KeyPressed(int kCode);

		int getGetKeyCode() const;

	private:
		int mKeyCode;
	};

	class PLATINUM_API KeyReleased
	{
	public:
		KeyReleased(int kCode);
		int getKeyCode() const;
	private:
		int mKeyCode;
	};
	class PLATINUM_API WindowClosed
	{

	};
}