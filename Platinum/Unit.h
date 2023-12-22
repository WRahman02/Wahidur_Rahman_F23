#pragma once
#include"Picture.h"
#include"Utilities.h"

namespace pl
{
	class PLATINUM_API Unit
	{
	public:
		Unit(const std::string& image, int x, int y);
		Unit(std::string&& image, int x, int y);

		int GetWidth() const;
		int GetHeight() const;

		int GetXCoord() const;
		int GetYCoord() const;

		void SetCoords(int x, int y);
		void UpdateXCoord(int amount);
		void UpdateYCoord(int amount);

		enum Direction{forward, backward};
		Unit::Direction GetDirection() const;
		void SetDirection(Unit::Direction direction);

		bool UnitsOverlap(const Unit& a, const Unit& b);

		bool InWindow();
	private:
		Picture mImage;
		int mXPosition;
		int mYPosition;
		Direction mDirection;

		template<typename T> friend class PlatinumApp;
		friend PLATINUM_API bool UnitsOverlap(const Unit& a, const Unit& b);

	};

	PLATINUM_API bool UnitsOverlap(const Unit& a, const Unit& b);

}