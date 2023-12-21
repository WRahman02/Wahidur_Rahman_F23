#include "Platinum.h"
#include "../Keys.h"
#include <iostream>

class MyGame : public pl::PlatinumApp<MyGame>
{
public:
	MyGame()
	{
		SetKeyPressedCallback([this](const pl::KeyPressed& e) {OnKeyPress(e); });
	}
	virtual void onUpdate() override
	{
		//std::cout << "Platinum running" << std::endl;
		Draw(mUnit);
	}
	void OnKeyPress(const pl::KeyPressed& e)
	{
		if (e.getGetKeyCode() == PLATINUM_KEY_RIGHT)
			x += 50;
		else if (e.getGetKeyCode() == PLATINUM_KEY_LEFT)
			x -= 50;
	}
private:
	pl::Picture mPic{ "../Assets/images/test.png" };
	pl::Unit mUnit{ "../Assets/images/test.png", 100, 500 };
	int x{ 100 };
	int y{ 500 };
};


PLATINUM_APPLICATION_START(MyGame);
//int main()
//{
//	MyGame game;
//	game.Run();
//	return (0);
//}