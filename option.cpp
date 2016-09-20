
#include "Splash.h"
#include "Option.h"
#include "sfwdraw.h"
#include <iostream>
void option::init(int a_font)
{
	d = a_font;
}

void option::play() { select = 0; timer = 3.f; }

void option::draw()
{

	sfw::drawString(d, "Press enter to Start a New Game", 100, 100, 20, 20, 0, 0, WHITE);

	/*sfw::drawString(d, "press 1 tGOTO DEPART", 100, 300, 20, 20, 0, 0,  WHITE);*/
}

void option::step()
{
	/*timer -= sfw::getDeltaTime();
	if (timer < 0)
	{
		timer = 1.f;
		select = 1 - select;
	}*/
}

menueState option::next()
{
	
	if (sfw::getKey(KEY_ENTER))
	{
		return Enter_Game;
	}
	///*if (sfw::getKey(KEY_ENTER))
	//{
	//	if (select == 0)
	//		return Enter_Depart;
	//	if (select == 1)
	//		ret*/urn Enter_Game;
	//}

	return Option;
}

