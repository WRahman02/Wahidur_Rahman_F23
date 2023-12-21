#include "pch.h"
#include "Events.h"

namespace pl
{
	KeyPressed::KeyPressed(int kCode) : mKeyCode(kCode)
	{
	}
	int KeyPressed::getGetKeyCode() const
	{
		return mKeyCode;
	}
	KeyReleased::KeyReleased(int kCode): mKeyCode(kCode)
	{
	}

	int KeyReleased::getKeyCode() const
	{
		return mKeyCode;
	}

}