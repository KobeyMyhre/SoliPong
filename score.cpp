#include "sfwdraw.h"
#include "Score.h"
#include <iostream>


void drawScore(unsigned font, int p1score, int p2score)
{
	char buffer[64] = { 0 };
	sprintf_s(buffer, "%d", p1score);
	sfw::drawString(font, buffer, 650, 600, 40, 40);

	sprintf_s(buffer, "%d", p2score);
	sfw::drawString(font, buffer, 500, 600, 40, 40);
	if (p1score >= 10 && p2score < p1score)
	{
		sprintf_s(buffer, "Stop Sucking");
		sfw::drawString(font, buffer, 50, 550, 40, 40);
	}
	if (p2score >= 10 && p2score > p1score)
	{
		sprintf_s(buffer, "Stop Sucking");
		sfw::drawString(font, buffer, 650, 550, 40, 40);
	}
}
//void drawWin(unsigned font)
//{
//	sfw::drawString(font, "Game Over Player 1 Wins!", 400, 500, 20, 20);
//}
//void drawWin2(unsigned font)
//{
//	sfw::drawString(font, " Game Over Player 2 Wins!", 400, 500, 20, 20);
//}

