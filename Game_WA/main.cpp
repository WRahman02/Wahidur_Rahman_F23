#include "Platinum.h"
#include <iostream>

class MyGame : public pl::PlatinumApp<MyGame>
{
public:
	MyGame()
	{
		SetKeyPressedCallback([this] (const pl::KeyPressed& e) {OnKeyPress(e);});
	}
	virtual void onUpdate() override
	{
		Draw(0, 0, mBackground);
		if (mCharacterForward.GetDirection() == pl::Unit::forward && holding == false)
		{
			Draw(mCake);
			Draw(mCharacterForward);
		}
		else if (mCharacterForward.GetDirection() == pl::Unit::backward && holding == false)
		{
			Draw(mCake);
			Draw(mCharacterBack);
		}
		else if (mCharacterForward.GetDirection() == pl::Unit::forward && holding == true)
			Draw(mKCF);
		else if (mCharacterForward.GetDirection() == pl::Unit::backward && holding == true)
			Draw(mKCB);

	}
	void OnKeyPress(const pl::KeyPressed& e)
	{
		if (e.GetKeyCode() == PLATINUM_KEY_RIGHT)
		{
			if (mCharacterForward.GetDirection() == pl::Unit::backward && holding == false)
			{
				mCharacterForward.SetDirection(pl::Unit::Direction::forward);
				mCharacterForward.SetCoords(mCharacterBack.GetXCoord(), mCharacterBack.GetYCoord());
				
				mCharacterForward.UpdateXCoord(speed);
			}
			else if (mCharacterForward.GetDirection() == pl::Unit::backward && holding == true)
			{
				mCharacterForward.SetDirection(pl::Unit::Direction::forward);
				mKCF.SetCoords(mKCB.GetXCoord(), mKCB.GetYCoord());
				mKCF.UpdateXCoord(speed);
			}
			else if (mCharacterForward.GetDirection() == pl::Unit::forward && holding == true)
				mKCF.UpdateXCoord(speed);
			else
				mCharacterForward.UpdateXCoord(speed);
		}
		else if (e.GetKeyCode() == PLATINUM_KEY_LEFT)
		{
			if (mCharacterForward.GetDirection() == pl::Unit::forward && holding == false)
			{
				mCharacterForward.SetDirection(pl::Unit::Direction::backward);
				mCharacterBack.SetCoords(mCharacterForward.GetXCoord(), mCharacterForward.GetYCoord());
				mCharacterBack.UpdateXCoord(-speed);
			}
			else if (mCharacterForward.GetDirection() == pl::Unit::forward && holding == true)
			{
				mCharacterForward.SetDirection(pl::Unit::Direction::backward);
				mKCB.SetCoords(mKCF.GetXCoord(), mKCF.GetYCoord());
				mKCB.UpdateXCoord(-speed);
			}
			else if (mCharacterForward.GetDirection() == pl::Unit::backward && holding == true)
				mKCB.UpdateXCoord(-speed);
			else
				mCharacterBack.UpdateXCoord(-speed);
		}
		else if (e.GetKeyCode() == PLATINUM_KEY_UP)
			if (mCharacterForward.GetDirection() == pl::Unit::forward && holding == false)
				mCharacterForward.UpdateYCoord(speed);
			else if (mCharacterForward.GetDirection() == pl::Unit::forward && holding == true)
			{
				mKCF.UpdateYCoord(speed);
			}
			else if (mCharacterForward.GetDirection() == pl::Unit::backward && holding == true)
				mKCB.UpdateYCoord(speed);
			else
				mCharacterBack.UpdateYCoord(speed);
			
		else if (e.GetKeyCode() == PLATINUM_KEY_DOWN)
			if (mCharacterForward.GetDirection() == pl::Unit::forward && holding == false)
				mCharacterForward.UpdateYCoord(-speed);
			else if (mCharacterForward.GetDirection() == pl::Unit::forward && holding == true)
				mKCF.UpdateYCoord(-speed);
			else if (mCharacterForward.GetDirection() == pl::Unit::backward && holding == true)
				mKCB.UpdateYCoord(-speed);
			else
				mCharacterBack.UpdateYCoord(-speed);
		
		else if (e.GetKeyCode() == PLATINUM_KEY_SPACE)
			if ((pl::UnitsOverlap(mCharacterForward, mCake) == true) && holding == false)
			{
				mKCF.SetCoords(mCharacterForward.GetXCoord(), mCharacterForward.GetYCoord());
				mCharacterForward.SetDirection(pl::Unit::Direction::forward);
				holding = true;
			}
			else if ((pl::UnitsOverlap(mCharacterBack, mCake) == true) && holding == false)
			{
				mKCB.SetCoords(mCharacterBack.GetXCoord(), mCharacterBack.GetYCoord());
				mCharacterForward.SetDirection(pl::Unit::Direction::backward);
				holding = true;
			}
			else if ((holding == true) && (mCharacterForward.GetDirection() == pl::Unit::forward))
			{
				mCake.SetCoords((mKCF.GetXCoord() + mCake.GetWidth()), (mKCF.GetYCoord() - 40));
				mCharacterForward.SetCoords(mKCF.GetXCoord(), mKCF.GetYCoord());
				holding = false;
			}
			else if ((holding == true) && (mCharacterForward.GetDirection() == pl::Unit::backward))
			{
				mCake.SetCoords((mKCB.GetXCoord() + mCake.GetWidth()), (mKCB.GetYCoord() - 40));
				mCharacterBack.SetCoords(mKCB.GetXCoord(), mKCB.GetYCoord());
				holding = false;
			}
	}
private:
	pl::Picture mBackground{ "../Assets/images/background.png"};
	pl::Unit mCake{ "../Assets/images/cake.png", 50, 400 };
	pl::Unit mCharacterForward{ "../Assets/images/kirby_forward.png", 0, 10 };
	pl::Unit mCharacterBack{ "../Assets/images/kirby_backward.png", 0, 0 };
	pl::Unit mKCF{ "../Assets/images/kirby_cakef.png", 0, 0 };
	pl::Unit mKCB{ "../Assets/images/kirby_cakeb.png", 0, 0 };
	int x{ 100 }, y{ 500 };
	const int speed{ 50 };
	bool holding = false;
};

PLATINUM_APPLICATION_START(MyGame);