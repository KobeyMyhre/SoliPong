#pragma once
#include "sfwdraw.h"
#include "Ball.h"
#include "Paddle.h"
#include <iostream>

void player::createPaddle(float a_Y, float a_X, float a_size, char a_up, char a_down, unsigned int a_color)
{
	
	a_up = up;
	a_down = down;
	a_Y = Y;
	a_X = X;
	a_color = color;

	
}
void player::updatPaddle()
{


	if (sfw::getKey(up))
		Y += 10;
	if (sfw::getKey(down))
		Y -= 10;
	if (Y > 600 - size) Y = 600 - size;
	if (Y < 0) Y = 0;
}


void player::drawPaddle()
{
	sfw::drawLine(X, size + Y, X, Y, color);
}
