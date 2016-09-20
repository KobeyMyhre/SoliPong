
#include "Depart.h"
#include "menuestate.h"
#include "sfwdraw.h"
#include "GameState.h"
#include <iostream>

void depart::init(int a_font)
{
	d = a_font;
	
}

void depart::play(int a_winner)
{
	timer = 5.f;
	w = a_winner;
}

void depart::draw()
{
	char buffer[64];
	if (w = 0)
	{
		sprintf_s(buffer, "Player 1 Wins!");
		sfw::drawString(d, buffer, 100, 100, 20, 20);
	}
	if (w = 1)
	{
		sprintf_s(buffer, "Player 2 Wins!");
		sfw::drawString(d, buffer, 100, 100, 20, 20);
	}
		sfw::drawLine(100, 80, 100 + 500 * (timer / 5.f), 80);
		if (timer <= 4)
			sfw::drawString(d, "Insert 50 Credits to continue.", 300, 300, 20, 20);
	
}

void depart::step()
{
	timer -= sfw::getDeltaTime();
}

menueState depart::next()
{
	if (timer < 0)
		return Enter_Option;

	return Depart;
}