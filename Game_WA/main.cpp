#include "Platinum.h"
#include <iostream>

class MyGame : public pl::PlatinumApp<MyGame>
{
public:
	virtual void onUpdate() override
	{
		std::cout << "Platinum running" << std::endl;
	}
};


PLATINUM_APPLICATION_START(MyGame);
//int main()
//{
//	MyGame game;
//	game.Run();
//	return (0);
//}