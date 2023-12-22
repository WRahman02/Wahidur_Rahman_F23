#include "pch.h"
#include "Unit.h"

namespace pl
{

	Unit::Unit(const std::string& image, int x, int y) : mImage(image), mXPosition(x), mYPosition(y), mDirection(Direction::forward)
	{
	}

	Unit::Unit(std::string&& image, int x, int y) : mImage(image), mXPosition(x), mYPosition(y), mDirection(Direction::forward)
	{
	}

	int Unit::GetWidth() const
	{
		return mImage.GetWidth();
	}

	int Unit::GetHeight() const
	{
		return mImage.GetHeight();
	}

	int Unit::GetXCoord() const
	{
		return mXPosition;
	}

	int Unit::GetYCoord() const
	{
		return mYPosition;
	}

	void Unit::SetCoords(int x, int y)
	{
		mXPosition = x;
		mYPosition = y;
	}

	void Unit::UpdateXCoord(int amount)
	{
		mXPosition += amount;		
	}

	void Unit::UpdateYCoord(int amount)
	{
		mYPosition += amount;
	}

	Unit::Direction Unit::GetDirection() const
	{
		return mDirection;
	}

	void Unit::SetDirection(Unit::Direction direction)
	{
		mDirection = direction;
	}
	
	bool UnitsOverlap(const Unit& a, const Unit& b)
	{
		int aLeft{ a.mXPosition };
		int aRight{ a.mXPosition + a.mImage.GetWidth() };
		int aBottom{ a.mYPosition };
		int aTop{ a.mYPosition + a.mImage.GetHeight() };

		int bLeft{ b.mXPosition };
		int bRight{ b.mXPosition + b.mImage.GetWidth() };
		int bBottom{ b.mXPosition };
		int bTop{ b.mYPosition + b.mImage.GetHeight() };

		bool xOverlap{ (aLeft <= bLeft and bLeft <= aRight) || (bLeft <= aLeft and aLeft <= bRight) };
		bool yOverlap{ (aBottom <= bBottom and bBottom <= aTop) || (bBottom <= aBottom and aBottom <= bTop) };

		return xOverlap and yOverlap;
	}	
}


