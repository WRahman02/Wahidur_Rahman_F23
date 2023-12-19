#include "Platinum.h"
#include <iostream>

class MyGame : public pl::PlatinumApp<MyGame>
{
public:
	virtual void onUpdate() override
	{
		std::cout << "Platinum running" << std::endl;
		Draw(mUnit);
	}
private:
	pl::Picture mPic{ "../Assets/images/test.png" };
	pl::Unit mUnit{ "../Assets/images/test.png", 100, 200 };
};


PLATINUM_APPLICATION_START(MyGame);
//int main()
//{
//	MyGame game;
//	game.Run();
//	return (0);
//}