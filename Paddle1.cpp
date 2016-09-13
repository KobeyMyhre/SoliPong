#pragma once
#include "sfwdraw.h"
#include "Ball.h"
#include "Paddle.h"
#include <iostream>

void player::createPaddle(float a_Y, float a_X, float a_size, char a_up, char a_down, unsigned int a_color)
{
	up = a_up;
	down = a_down;
	size = a_size;
	Y = a_Y;
	X = a_X;
	color = a_color;	
}

void player::updatPaddle()
{


	if (sfw::getKey(up))
		Y += 15;
	if (sfw::getKey(down))
		Y -= 15;
	if (Y > 600 - size) Y = 600 - size;
	if (Y < 0) Y = 0;
}


void player::drawPaddle()
{
	sfw::drawLine(X, size + Y, X, Y, color);
}
