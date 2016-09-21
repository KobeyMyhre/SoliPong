#include "Instruct.h"
#include "menuestate.h"
#include "sfwdraw.h"
#include <iostream>


void instruct::init(int a_font)
{
	d = a_font;
}

void instruct::play()
{ 

}

void instruct::draw()
{
	char buffer[64];
	sprintf_s(buffer, "Controls");
	sfw::drawString(d, buffer, 450, 590, 25, 25);
	sprintf_s(buffer, "Player 1");
	sfw::drawString(d, buffer, 100, 550, 25, 25);
	sprintf_s(buffer, "Player 2");
	sfw::drawString(d, buffer, 700, 550, 25, 25);
	sprintf_s(buffer, "W - To Go Up");
	sfw::drawString(d, buffer, 110, 400, 20, 20);
	sprintf_s(buffer, "S - To Go Down");
	sfw::drawString(d, buffer, 110, 350, 20, 20);
	sprintf_s(buffer, "x - To Use Tricks");
	sfw::drawString(d, buffer, 110, 300, 20, 20);
	sprintf_s(buffer, "SpaceBar - To Reverse The Direction of Both Players Balls");
	sfw::drawString(d, buffer, 200, 200, 15, 15);
	sprintf_s(buffer, "I - To Go Up");
	sfw::drawString(d, buffer, 710, 400, 20, 20);
	sprintf_s(buffer, "K - To Go Down");
	sfw::drawString(d, buffer, 710, 350, 20, 20);
	sprintf_s(buffer, "M - To Use Tricks");
	sfw::drawString(d, buffer, 710, 300, 20, 20);
	sprintf_s(buffer, "[Space]");
	sfw::drawString(d, buffer, 1010, 100, 20, 20);

	/*if (timer <= 1)
		sfw::drawString(d, "Almost Done.", 300, 300, 20, 20);*/
}

void instruct::step()
{
	/*timer -= sfw::getDeltaTime();*/
}

menueState instruct::next()
{
	if (sfw::getKey(' '))
	{
		return Enter_Option;
	}
	return Instruct;
}