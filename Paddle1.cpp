#pragma once
#include "sfwdraw.h"
#include "Ball.h"
#include "Paddle.h"
#include <iostream>

void player::createPaddle(float a_Y, float a_X, float a_size, char a_up, char a_down, unsigned int a_color, int a_tricks,char a_shit)
{
	up = a_up;
	down = a_down;
	size = a_size;
	Y = a_Y;
	X = a_X;
	color = a_color;	
	score = 0;
	Shit = a_shit;
	Tricks = a_tricks;
}
void player::TricksAndShitBallOne(ball &b1)
{
	if (Tricks > 0)
	{
		if (sfw::getKey(Shit) && ShitTimer <= 0.0f)
		{
			b1.Vely *= 1.5;
			b1.Velx *= 1.5;
			Tricks -= 1;

			ShitTimer = 1.0f;
		}
	}
}
void player::TricksAndShitBallTwo(ball &b2)
{
	if (Tricks > 0)
	{
		if (sfw::getKey(Shit) && ShitTimer <= 0.0f)
		{
			b2.Vely *= 1.5;
			b2.Velx *= 1.5;
			Tricks -= 1;

			ShitTimer = 1.0f;
		}
	}
}
	
void player::updatePaddle()
{
	ShitTimer -= sfw::getDeltaTime();
	

	if (sfw::getKey(up))
		Y += 15;
	if (sfw::getKey(down))
		Y -= 15;
	if (Y > 600 - size) Y = 600 - size;
	if (Y < 0) Y = 0;
}
void player::updatePaddlecolor()
{
	if (color == GREEN)
		color = YELLOW;
	else if (color == YELLOW)
		color = BLUE;
	else if (color == BLUE)
		color = RED;
	else if (color == RED)
		color = MAGENTA;
	else if (color == MAGENTA)
		color = WHITE;
	else if (color == WHITE)
		color = CYAN;
	else
		color = GREEN;
}


void player::drawPaddle()
{
	sfw::drawLine(X, size + Y, X, Y, color);
}
